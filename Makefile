CC	= cc
CCFLAGS = -Wall -Wextra -Werror -g
LIBXFLAGS = -lX11 -lXext

FT_PRINTF = ft_printf/ft_printf.a
MINILIBX = minilibx-linux/libmlx.a
FRACTOL = fractol

SRCS_FRACTOL = main.c check_the_input.c collect_args.c\
				utils/ft_strcpy.c utils/ft_strlen.c utils/ft_strcmp.c utils/pixel_put.c\
				utils/ft_atoi.c utils/ft_atod.c\
				Mandelbrot/mandelbrot.c Mandelbrot/mandelbrot_set_values.c Mandelbrot/make_mandelbrot.c Mandelbrot/colorize.c\
				grafico/inicializacao.c grafico/events.c\
				Julia/make_julia.c Julia/julia_set_values.c Julia/draw_julia.c Julia/colorize_ju.c

OBJS_FRACTOL = $(SRCS_FRACTOL:.c=.o)

all: $(FT_PRINTF) $(MINILIBX) $(FRACTOL)

$(FT_PRINTF):
				$(MAKE) -C ./ft_printf

$(MINILIBX):
				$(MAKE) -C ./minilibx-linux

$(FRACTOL):		$(OBJS_FRACTOL)
									$(CC) $(CCFLAGS) $(OBJS_FRACTOL) ft_printf/libftprintf.a minilibx-linux/libmlx.a -o $(FRACTOL) $(LIBXFLAGS)

%.o: %.c
				$(CC) $(CCFLAGS) -c $< -o $@

clean:
				rm -rf $(OBJS_FRACTOL)
				$(MAKE) clean -C ./ft_printf
fclean: clean
				$(MAKE) fclean -C ./ft_printf
				rm -rf $(FRACTOL)
re: fclean all
