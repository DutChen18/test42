import os.path

def cflags(**kwargs):
	return [os.path.join(kwargs["path"], "libft.a")]
