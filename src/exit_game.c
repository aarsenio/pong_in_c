#include <pong.h>

int	exit_game(void *param)
{
	(void)param;
	if (data()->mlx_img)
		mlx_destroy_image(data()->mlx, data()->mlx_img);
	if (data()->ball)
	{
		mlx_destroy_image(data()->mlx, data()->ball->img);
		free(data()->ball);
	}
	if (data()->bar)
		free(data()->bar);
	if (data()->win)
		mlx_destroy_window(data()->mlx, data()->win);
	if (data()->mlx)
	{
		mlx_destroy_display(data()->mlx);
		free(data()->mlx);
	}
	exit (0);
	return (0);
}