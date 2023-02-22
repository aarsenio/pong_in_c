#include <pong.h>

static void	direction_changer(void)
{
	data()->ball->x_vector += (data()->ball->x - data()->bar->x) / 20;
	if (data()->ball->x_vector >= 2)
		data()->ball->x_vector = 2;
	if (data()->ball->x_vector <= -2)
		data()->ball->x_vector = -2;
}

void	ball_move(void)
{
	if (data()->ball->y >= WINDOW_RES)
		exit_game(&data);
	if (data()->ball->y + (BALL_RES / 2) == data()->bar->y && \
	data()->ball->x >= (data()->bar->x - data()->bar->width) && \
	data()->ball->x <= (data()->bar->x + data()->bar->width))
	{
		data()->ball->y_vector *= -1;
		direction_changer();
	}
	if (data()->ball->y - (BALL_RES / 2) <= 0)
		data()->ball->y_vector *= -1;
	if (data()->ball->x - (BALL_RES / 2) <= 0 || data()->ball->x + (BALL_RES / 2) >= WINDOW_RES)
		data()->ball->x_vector *= -1;
	data()->ball->y += data()->ball->y_vector;
	data()->ball->x += data()->ball->x_vector;
}
