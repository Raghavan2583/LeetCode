static int cmp_int_asc(const int * const pThis, const int * const pBase){
	return *pThis - *pBase;
}

static int cmp_int_desc(const int * const pThis, const int * const pBase){
	return -(*pThis - *pBase);
}

int minProcessingTime(
	int * const processorTime,
	const int processorTimeLen,
	int * const tasks,
	const int tasksLen
){
	qsort(processorTime, processorTimeLen, sizeof (int), &cmp_int_asc);
	qsort(tasks, tasksLen, sizeof (int), &cmp_int_desc);

	int finishedTime = 0;
	for (int i = 0; i < processorTimeLen; i += 1){
		const int curFinishedTime = processorTime[i] + tasks[4 * i];
		if (curFinishedTime > finishedTime){
			finishedTime = curFinishedTime;
		}
	}
	return finishedTime;
}