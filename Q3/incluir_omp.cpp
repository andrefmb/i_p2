#pragma omp parallel
 {
   tid = omp_get_thread_num(); 
    if (tid == 0) {
        printf("Thread %d getting environment info...\n",
                tid);
        procs = omp_get_num_procs();
        nthreads = omp_get_num_threads();
        maxt = omp_get_max_threads();
        inpar = omp_in_parallel();


        cout << "Number of processors "  <<  procs << endl;
        cout << "Number of threads = " <<  nthreads << endl;
        cout << "Max threads = " << maxt << endl;
        cout << "In parallel? = " <<  inpar << endl;


    }
 }
