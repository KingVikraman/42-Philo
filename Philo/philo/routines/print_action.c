#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "limit.h"
#include "pthread.h"

void	print_action(t_data *data, int id, char *str)
{
	pthread_mutex_lock(&(data->writing_lock));
	printf("%lld ", gettime() - data->start_time);
	printf("%d ", id + 1);
	printf("%s\n", str);
	pthread_mutex_unlock(&(data->writing_lock));
}