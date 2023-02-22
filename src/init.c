#include <pong.h>

static void	ball_init(void)
{
	int	res = BALL_RES;
	data()->ball = malloc(sizeof(t_ball));
	if (!data()->ball)
		return ;
	data()->ball->img = mlx_xpm_file_to_image(data()->mlx, "images/ball.xpm", &res, &res);
	data()->ball->x_vector = 0;
	data()->ball->y_vector = 1;
	data()->ball->x = (WINDOW_RES / 2);
	data()->ball->y = WINDOW_RES / 2;
}

static void	bar_init(void)
{
	data()->bar = malloc(sizeof(t_bar));
	if (!data()->bar)
		return ;
	data()->bar->x = (WINDOW_RES / 2);
	data()->bar->y = WINDOW_RES - (WINDOW_RES / 10);
	data()->bar->width = BAR_WIDTH;
}

void	init(void)
{
	ball_init();
	bar_init();
}