#ifndef PONG_H
# define PONG_H

# include <mlx.h>
# include <mlx_int.h>
# include <stdio.h>

# define WINDOW_RES 800
# define BAR_WIDTH 50
# define BALL_RES 15

typedef struct s_ball
{
	int	x_vector;
	int	y_vector;
	int		x;
	int		y;
	t_img	*img;
}t_ball;

typedef struct s_bar
{
	int	x;
	int	y;
	int	width;
}t_bar;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	*mlx_img;
	t_ball	*ball;
	t_bar	*bar;
}t_data;

t_data *data(void);
void	init(void);
void	render(void);
void	ball_move(void);
int		exit_game(void *param);

#endif