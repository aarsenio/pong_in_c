#include <pong.h>

int	animation(void *param)
{
	int x, y;

	(void) param;
	mlx_mouse_get_pos(data()->mlx, data()->win, &x, &y);
	if (x > data()->bar->width && x < WINDOW_RES - data()->bar->width)
		data()->bar->x = x;
	ball_move();
	render();
	return (1);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	data()->mlx = mlx_init();
	data()->win = mlx_new_window(data()->mlx, WINDOW_RES, WINDOW_RES, "P O N G");
	data()->mlx_img = mlx_new_image(data()->mlx, WINDOW_RES, WINDOW_RES);
	init();
	mlx_hook(data()->win, 17, (1L << 2), exit_game, &data);
	mlx_loop_hook(data()->mlx, animation, &data);
	mlx_loop(data()->mlx);
}