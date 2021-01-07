#include <pthread.h>
#include <stdio.h>

pthread_mutex_t	mutex;

void	*calculate(void		*count)
{
	int		*ref = (int *)count;

	while (1)
	{
		pthread_mutex_lock(&mutex);
		if (*ref >= 2000)
		{
			pthread_mutex_unlock(&mutex);
			return NULL;
		}
		(*ref)++;
		pthread_mutex_unlock(&mutex);
		printf("%d\n", *ref);
	}
}

int		main()
{
	int			count = 0;
	pthread_t	t1;
	pthread_t	t2;

	pthread_mutex_init(&mutex, NULL);
	pthread_create(&t1, NULL, calculate, (void *)&count);
	pthread_create(&t1, NULL, calculate, (void *)&count);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}
