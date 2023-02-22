#include <pong.h>

unsigned int	mlx_get_pixel(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

void	mlx_draw_pixel(t_img *mlx_img, int x, int y, int color)
{
	char			*target;

	target = mlx_img->data + (x * mlx_img->bpp / 8 + y * mlx_img->size_line);
	*(unsigned int *)target = color;
}

unsigned int	mlx_rgb_to_int(int o, int r, int g, int b)
{
	return (o << 24 | r << 16 | g << 8 | b);
}

void	draw_black(void)
{
	int	i = -1;
	int	j = -1;

	while (++j < WINDOW_RES)
	{
		i = -1;
		while (++i < WINDOW_RES)
			mlx_draw_pixel(data()->mlx_img, i, j, 0x00000000);
	}
}

void	draw_bar(void)
{
	int	start = data()->bar->x - data()->bar->width;

	while (start <= data()->bar->x + data()->bar->width)
		mlx_draw_pixel(data()->mlx_img, start++, WINDOW_RES - (WINDOW_RES / 10), 0xFFFFFF);
}

void	draw_ball(void)
{
	int				i = -1, j = -1;
	unsigned int	color;

	while (++j < BALL_RES)
	{
		i = -1;
		while (++i < BALL_RES)
		{
			color = mlx_get_pixel(data()->ball->img, i, j);
			if (color != mlx_rgb_to_int(0, 0, 0, 0))
				mlx_draw_pixel(data()->mlx_img, data()->ball->x - (BALL_RES / 2) + i, data()->ball->y - (BALL_RES / 2) + j, color);
		}
	}
}


void	render(void)
{
	draw_black();
	draw_bar();
	draw_ball();
	mlx_put_image_to_window(data()->mlx, data()->win, data()->mlx_img, 0, 0);
}