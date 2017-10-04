//Step8.1.2

#pragma omp parallel //Option 1.

#pragma omp parallel num_threads(4) //Option 2.

opm_set_num_threads(4) //Option 3.
#pragma omp parallel

export OMP_NUM_THREADS = 4; //Option 4.
#pragma omp parallel


//Step8.1.3
#pragma omp parallel shared(A, B, C) private(i, n)


//Step8.1.4

#pragma omp parallel for //Option 1.1

#pragma omp parallel for reduction(+:variable) //Option 1.2

#pragma omp parallel //Option 2.
{
	#pragma omp for
	
}

//Step8.1.5
#pragma omp parallel
{
	#pragma omp barrier
}


//Step8.1.6

#pragma omp parallel num_threads(4) //Option 1.1
{
	#pragma omp single
	{
		
	}
}

#pragma omp parallel num_threads(4) //Option 1.2
{
	#pragma omp single nowait
	{
		
	}
}

#pragma omp parallel num_threads(4) //Option 2.
{
	#pragma omp master nowait
	{
		
	}
}


//Step8.1.7
#pragma omp parallel for ordered
{
	#pragma omp ordered
	{
		
	}
}

//Step8.1.8
#pragma omp parallel
{
	#pragma omp critical
	{
		
	}
}

//Step8.1.9
#pragma omp parallel
{
	#pragma omp atomic
}

//Step8.1.10
#pragma omp sections
{
	#pragma omp section
	{
		
	}
	
	#pragma omp section
	{
		
	}
}


//Step8.1.11

#pragma omp task //Option 1.
{
	
}

#pragma omp task //Option 2.
{
	
}
#pragma omp taskwait