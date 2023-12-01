#!/bin/bash


# Verificar se um ID de job foi fornecido
if [ $# -eq 0 ]; then
    echo "Por favor, forneça um ID de Job SLURM."
    exit 1
fi

JOB_ID=$1
EVIDENCE_DIR="evidencias_job_$JOB_ID"

# Criar pasta de evidências
mkdir -p "$EVIDENCE_DIR"

# Coletar informações do job
scontrol show job $JOB_ID > "$EVIDENCE_DIR/detalhes_job.txt"

# Extrair o diretório de trabalho
WORK_DIR=$(grep "WorkDir" "$EVIDENCE_DIR/detalhes_job.txt" | cut -d'=' -f2)
echo "Diretório de trabalho: $WORK_DIR" >> "$EVIDENCE_DIR/detalhes_job.txt"

# Coletar mais informações do job
sacct -j $JOB_ID --format=User,JobName,Partition,State,Time,NodeList,ReqMem > "$EVIDENCE_DIR/sumario_job.txt"
sacct -j $JOB_ID --format=JobID,Start,End,Elapsed,AllocCPUS,ReqMem,MaxRSS,MaxVMSize > "$EVIDENCE_DIR/memoria_cpu_job.txt"
sacct -j $JOB_ID --format=JobID,Account,User > "$EVIDENCE_DIR/usuario_job.txt"

# Incluir arquivos de entrada e saída, se disponíveis
echo "ATENÇÃO: INCLUIA NA PASTA A SEGUIR O ARQUIVO DE INPUT, O ARQUIVO CPP, E SEU EXECUTAVEL: $EVIDENCE_DIR"

echo "Evidências coletadas na pasta: $EVIDENCE_DIR"

echo "Para compactar a pasta de evidências, execute: tar -czvf ${EVIDENCE_DIR}.tar.gz $EVIDENCE_DIR"