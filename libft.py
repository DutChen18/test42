#!/usr/bin/env python3
import test
import os

ft_isalpha_args = [test.join_proj("libft.a"), test.join_test("ft_isalpha/ft_isalpha.c")]
ft_isalpha_args += ["-Dft_isalpha=isalpha"] if test.test_mode == "record" else []
ft_isalpha = test.Group("ft_isalpha")
ft_isalpha.add(test.CTest("ascii", ft_isalpha_args + ["-DTEST_ASCII"]))
ft_isalpha.add(test.CTest("unsigned_char", ft_isalpha_args + ["-DTEST_UNSIGNED_CHAR"]))
ft_isalpha.add(test.CTest("signed_char", ft_isalpha_args + ["-DTEST_SIGNED_CHAR"]))
ft_isalpha.add(test.CTest("random", ft_isalpha_args + ["-DTEST_RANDOM"]))
ft_isalpha.start()

ft_isdigit_args = [test.join_proj("libft.a"), test.join_test("ft_isdigit/ft_isdigit.c")]
ft_isdigit_args += ["-Dft_isdigit=isdigit"] if test.test_mode == "record" else []
ft_isdigit = test.Group("ft_isdigit")
ft_isdigit.add(test.CTest("ascii", ft_isdigit_args + ["-DTEST_ASCII"]))
ft_isdigit.add(test.CTest("unsigned_char", ft_isdigit_args + ["-DTEST_UNSIGNED_CHAR"]))
ft_isdigit.add(test.CTest("signed_char", ft_isdigit_args + ["-DTEST_SIGNED_CHAR"]))
ft_isdigit.add(test.CTest("random", ft_isdigit_args + ["-DTEST_RANDOM"]))
ft_isdigit.start()

ft_isalnum_args = [test.join_proj("libft.a"), test.join_test("ft_isalnum/ft_isalnum.c")]
ft_isalnum_args += ["-Dft_isalnum=isalnum"] if test.test_mode == "record" else []
ft_isalnum = test.Group("ft_isalnum")
ft_isalnum.add(test.CTest("ascii", ft_isalnum_args + ["-DTEST_ASCII"]))
ft_isalnum.add(test.CTest("unsigned_char", ft_isalnum_args + ["-DTEST_UNSIGNED_CHAR"]))
ft_isalnum.add(test.CTest("signed_char", ft_isalnum_args + ["-DTEST_SIGNED_CHAR"]))
ft_isalnum.add(test.CTest("random", ft_isalnum_args + ["-DTEST_RANDOM"]))
ft_isalnum.start()

ft_isascii_args = [test.join_proj("libft.a"), test.join_test("ft_isascii/ft_isascii.c")]
ft_isascii_args += ["-Dft_isascii=isascii"] if test.test_mode == "record" else []
ft_isascii = test.Group("ft_isascii")
ft_isascii.add(test.CTest("ascii", ft_isascii_args + ["-DTEST_ASCII"]))
ft_isascii.add(test.CTest("unsigned_char", ft_isascii_args + ["-DTEST_UNSIGNED_CHAR"]))
ft_isascii.add(test.CTest("signed_char", ft_isascii_args + ["-DTEST_SIGNED_CHAR"]))
ft_isascii.add(test.CTest("random", ft_isascii_args + ["-DTEST_RANDOM"]))
ft_isascii.start()

ft_isprint_args = [test.join_proj("libft.a"), test.join_test("ft_isprint/ft_isprint.c")]
ft_isprint_args += ["-Dft_isprint=isprint"] if test.test_mode == "record" else []
ft_isprint = test.Group("ft_isprint")
ft_isprint.add(test.CTest("ascii", ft_isprint_args + ["-DTEST_ASCII"]))
ft_isprint.add(test.CTest("unsigned_char", ft_isprint_args + ["-DTEST_UNSIGNED_CHAR"]))
ft_isprint.add(test.CTest("signed_char", ft_isprint_args + ["-DTEST_SIGNED_CHAR"]))
ft_isprint.add(test.CTest("random", ft_isprint_args + ["-DTEST_RANDOM"]))
ft_isprint.start()

ft_strlen_args = [test.join_proj("libft.a"), test.join_test("ft_strlen/ft_strlen.c")]
ft_strlen_args += ["-Dft_strlen=strlen"] if test.test_mode == "record" else []
ft_strlen = test.Group("ft_strlen")
ft_strlen.add(test.CTest("empty", ft_strlen_args + ["-DTEST_EMPTY"]))
ft_strlen.add(test.CTest("null", ft_strlen_args + ["-DTEST_NULL"]))
ft_strlen.add(test.CTest("basic", ft_strlen_args + ["-DTEST_BASIC"]))
ft_strlen.add(test.CTest("random", ft_strlen_args + ["-DTEST_RANDOM"]))
ft_strlen.start()

ft_memset_args = [test.join_proj("libft.a"), test.join_test("ft_memset/ft_memset.c")]
ft_memset_args += ["-Dft_memset=memset"] if test.test_mode == "record" else []
ft_memset = test.Group("ft_memset")
ft_memset.add(test.CTest("empty", ft_memset_args + ["-DTEST_EMPTY"]))
ft_memset.add(test.CTest("null", ft_memset_args + ["-DTEST_NULL"]))
ft_memset.add(test.CTest("random", ft_memset_args + ["-DTEST_RANDOM"]))
ft_memset.start()

ft_bzero_args = [test.join_proj("libft.a"), test.join_test("ft_bzero/ft_bzero.c")]
ft_bzero_args += ["-Dft_bzero=bzero"] if test.test_mode == "record" else []
ft_bzero = test.Group("ft_bzero")
ft_bzero.add(test.CTest("empty", ft_bzero_args + ["-DTEST_EMPTY"]))
ft_bzero.add(test.CTest("null", ft_bzero_args + ["-DTEST_NULL"]))
ft_bzero.add(test.CTest("random", ft_bzero_args + ["-DTEST_RANDOM"]))
ft_bzero.start()

ft_memcpy_args = [test.join_proj("libft.a"), test.join_test("ft_memcpy/ft_memcpy.c")]
ft_memcpy_args += ["-Dft_memcpy=memcpy2"] if test.test_mode == "record" else []
ft_memcpy = test.Group("ft_memcpy")
ft_memcpy.add(test.CTest("empty", ft_memcpy_args + ["-DTEST_EMPTY"]))
ft_memcpy.add(test.CTest("null1", ft_memcpy_args + ["-DTEST_NULL1"]))
ft_memcpy.add(test.CTest("null2", ft_memcpy_args + ["-DTEST_NULL2"]))
ft_memcpy.add(test.CTest("null3", ft_memcpy_args + ["-DTEST_NULL3"]))
ft_memcpy.add(test.CTest("random", ft_memcpy_args + ["-DTEST_RANDOM"]))
ft_memcpy.start()

ft_memmove_args = [test.join_proj("libft.a"), test.join_test("ft_memmove/ft_memmove.c")]
ft_memmove_args += ["-Dft_memmove=memmove2"] if test.test_mode == "record" else []
ft_memmove = test.Group("ft_memmove")
ft_memmove.add(test.CTest("empty", ft_memmove_args + ["-DTEST_EMPTY"]))
ft_memmove.add(test.CTest("null1", ft_memmove_args + ["-DTEST_NULL1"]))
ft_memmove.add(test.CTest("null2", ft_memmove_args + ["-DTEST_NULL2"]))
ft_memmove.add(test.CTest("null3", ft_memmove_args + ["-DTEST_NULL3"]))
ft_memmove.add(test.CTest("random", ft_memmove_args + ["-DTEST_RANDOM"]))
ft_memmove.start()

ft_strlcpy_args = [test.join_proj("libft.a"), test.join_test("ft_strlcpy/ft_strlcpy.c")]
ft_strlcpy_args += ["-Dft_strlcpy=strlcpy2"] if test.test_mode == "record" else []
ft_strlcpy = test.Group("ft_strlcpy")
ft_strlcpy.add(test.CTest("empty", ft_strlcpy_args + ["-DTEST_EMPTY"]))
ft_strlcpy.add(test.CTest("null1", ft_strlcpy_args + ["-DTEST_NULL1"]))
ft_strlcpy.add(test.CTest("null2", ft_strlcpy_args + ["-DTEST_NULL2"]))
ft_strlcpy.add(test.CTest("null3", ft_strlcpy_args + ["-DTEST_NULL3"]))
ft_strlcpy.add(test.CTest("random", ft_strlcpy_args + ["-DTEST_RANDOM"]))
ft_strlcpy.start()

ft_strlcat_args = [test.join_proj("libft.a"), test.join_test("ft_strlcat/ft_strlcat.c")]
ft_strlcat_args += ["-Dft_strlcat=strlcat2"] if test.test_mode == "record" else []
ft_strlcat = test.Group("ft_strlcat")
ft_strlcat.add(test.CTest("empty", ft_strlcat_args + ["-DTEST_EMPTY"]))
ft_strlcat.add(test.CTest("null1", ft_strlcat_args + ["-DTEST_NULL1"]))
ft_strlcat.add(test.CTest("null2", ft_strlcat_args + ["-DTEST_NULL2"]))
ft_strlcat.add(test.CTest("null3", ft_strlcat_args + ["-DTEST_NULL3"]))
ft_strlcat.add(test.CTest("random", ft_strlcat_args + ["-DTEST_RANDOM"]))
ft_strlcat.start()
