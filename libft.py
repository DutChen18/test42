#!/usr/bin/env python3
import test
import os
import asyncio

groups = []

ft_isalpha_args = [test.join_proj("libft.a"), test.join_test("ft_isalpha/ft_isalpha.c")]
ft_isalpha_args += ["-Dft_isalpha=isalpha"] if test.test_mode == "record" else []
ft_isalpha = test.Group("ft_isalpha")
ft_isalpha.add(test.CTest("ascii", ft_isalpha_args + ["-DTEST_ASCII"]))
ft_isalpha.add(test.CTest("unsigned_char", ft_isalpha_args + ["-DTEST_UNSIGNED_CHAR"]))
ft_isalpha.add(test.CTest("signed_char", ft_isalpha_args + ["-DTEST_SIGNED_CHAR"]))
ft_isalpha.add(test.CTest("random", ft_isalpha_args + ["-DTEST_RANDOM"]))
groups.append(ft_isalpha)

ft_isdigit_args = [test.join_proj("libft.a"), test.join_test("ft_isdigit/ft_isdigit.c")]
ft_isdigit_args += ["-Dft_isdigit=isdigit"] if test.test_mode == "record" else []
ft_isdigit = test.Group("ft_isdigit")
ft_isdigit.add(test.CTest("ascii", ft_isdigit_args + ["-DTEST_ASCII"]))
ft_isdigit.add(test.CTest("unsigned_char", ft_isdigit_args + ["-DTEST_UNSIGNED_CHAR"]))
ft_isdigit.add(test.CTest("signed_char", ft_isdigit_args + ["-DTEST_SIGNED_CHAR"]))
ft_isdigit.add(test.CTest("random", ft_isdigit_args + ["-DTEST_RANDOM"]))
groups.append(ft_isdigit)

ft_isalnum_args = [test.join_proj("libft.a"), test.join_test("ft_isalnum/ft_isalnum.c")]
ft_isalnum_args += ["-Dft_isalnum=isalnum"] if test.test_mode == "record" else []
ft_isalnum = test.Group("ft_isalnum")
ft_isalnum.add(test.CTest("ascii", ft_isalnum_args + ["-DTEST_ASCII"]))
ft_isalnum.add(test.CTest("unsigned_char", ft_isalnum_args + ["-DTEST_UNSIGNED_CHAR"]))
ft_isalnum.add(test.CTest("signed_char", ft_isalnum_args + ["-DTEST_SIGNED_CHAR"]))
ft_isalnum.add(test.CTest("random", ft_isalnum_args + ["-DTEST_RANDOM"]))
groups.append(ft_isalnum)

ft_isascii_args = [test.join_proj("libft.a"), test.join_test("ft_isascii/ft_isascii.c")]
ft_isascii_args += ["-Dft_isascii=isascii"] if test.test_mode == "record" else []
ft_isascii = test.Group("ft_isascii")
ft_isascii.add(test.CTest("ascii", ft_isascii_args + ["-DTEST_ASCII"]))
ft_isascii.add(test.CTest("unsigned_char", ft_isascii_args + ["-DTEST_UNSIGNED_CHAR"]))
ft_isascii.add(test.CTest("signed_char", ft_isascii_args + ["-DTEST_SIGNED_CHAR"]))
ft_isascii.add(test.CTest("random", ft_isascii_args + ["-DTEST_RANDOM"]))
groups.append(ft_isascii)

ft_isprint_args = [test.join_proj("libft.a"), test.join_test("ft_isprint/ft_isprint.c")]
ft_isprint_args += ["-Dft_isprint=isprint"] if test.test_mode == "record" else []
ft_isprint = test.Group("ft_isprint")
ft_isprint.add(test.CTest("ascii", ft_isprint_args + ["-DTEST_ASCII"]))
ft_isprint.add(test.CTest("unsigned_char", ft_isprint_args + ["-DTEST_UNSIGNED_CHAR"]))
ft_isprint.add(test.CTest("signed_char", ft_isprint_args + ["-DTEST_SIGNED_CHAR"]))
ft_isprint.add(test.CTest("random", ft_isprint_args + ["-DTEST_RANDOM"]))
groups.append(ft_isprint)

ft_strlen_args = [test.join_proj("libft.a"), test.join_test("ft_strlen/ft_strlen.c")]
ft_strlen_args += ["-Dft_strlen=strlen"] if test.test_mode == "record" else []
ft_strlen = test.Group("ft_strlen")
ft_strlen.add(test.CTest("empty", ft_strlen_args + ["-DTEST_EMPTY"]))
ft_strlen.add(test.CTest("null", ft_strlen_args + ["-DTEST_NULL"], asan=False))
ft_strlen.add(test.CTest("basic", ft_strlen_args + ["-DTEST_BASIC"]))
ft_strlen.add(test.CTest("random", ft_strlen_args + ["-DTEST_RANDOM"]))
groups.append(ft_strlen)

ft_memset_args = [test.join_proj("libft.a"), test.join_test("ft_memset/ft_memset.c")]
ft_memset_args += ["-Dft_memset=memset"] if test.test_mode == "record" else []
ft_memset = test.Group("ft_memset")
ft_memset.add(test.CTest("empty", ft_memset_args + ["-DTEST_EMPTY"]))
ft_memset.add(test.CTest("null", ft_memset_args + ["-DTEST_NULL"], asan=False))
ft_memset.add(test.CTest("random", ft_memset_args + ["-DTEST_RANDOM"]))
groups.append(ft_memset)

ft_bzero_args = [test.join_proj("libft.a"), test.join_test("ft_bzero/ft_bzero.c")]
ft_bzero_args += ["-Dft_bzero=bzero"] if test.test_mode == "record" else []
ft_bzero = test.Group("ft_bzero")
ft_bzero.add(test.CTest("empty", ft_bzero_args + ["-DTEST_EMPTY"]))
ft_bzero.add(test.CTest("null", ft_bzero_args + ["-DTEST_NULL"], asan=False))
ft_bzero.add(test.CTest("random", ft_bzero_args + ["-DTEST_RANDOM"]))
groups.append(ft_bzero)

ft_memcpy_args = [test.join_proj("libft.a"), test.join_test("ft_memcpy/ft_memcpy.c")]
ft_memcpy_args += ["-Dft_memcpy=memcpy2"] if test.test_mode == "record" else []
ft_memcpy = test.Group("ft_memcpy")
ft_memcpy.add(test.CTest("empty", ft_memcpy_args + ["-DTEST_EMPTY"]))
ft_memcpy.add(test.CTest("null1", ft_memcpy_args + ["-DTEST_NULL1"], asan=False))
ft_memcpy.add(test.CTest("null2", ft_memcpy_args + ["-DTEST_NULL2"], asan=False))
ft_memcpy.add(test.CTest("null3", ft_memcpy_args + ["-DTEST_NULL3"], asan=False))
ft_memcpy.add(test.CTest("random", ft_memcpy_args + ["-DTEST_RANDOM"]))
groups.append(ft_memcpy)

ft_memmove_args = [test.join_proj("libft.a"), test.join_test("ft_memmove/ft_memmove.c")]
ft_memmove_args += ["-Dft_memmove=memmove2"] if test.test_mode == "record" else []
ft_memmove = test.Group("ft_memmove")
ft_memmove.add(test.CTest("empty", ft_memmove_args + ["-DTEST_EMPTY"]))
ft_memmove.add(test.CTest("null1", ft_memmove_args + ["-DTEST_NULL1"], asan=False))
ft_memmove.add(test.CTest("null2", ft_memmove_args + ["-DTEST_NULL2"], asan=False))
ft_memmove.add(test.CTest("null3", ft_memmove_args + ["-DTEST_NULL3"], asan=False))
ft_memmove.add(test.CTest("random", ft_memmove_args + ["-DTEST_RANDOM"]))
groups.append(ft_memmove)

ft_strlcpy_args = [test.join_proj("libft.a"), test.join_test("ft_strlcpy/ft_strlcpy.c")]
ft_strlcpy_args += ["-Dft_strlcpy=strlcpy2"] if test.test_mode == "record" else []
ft_strlcpy = test.Group("ft_strlcpy")
ft_strlcpy.add(test.CTest("empty", ft_strlcpy_args + ["-DTEST_EMPTY"]))
ft_strlcpy.add(test.CTest("null1", ft_strlcpy_args + ["-DTEST_NULL1"], asan=False))
ft_strlcpy.add(test.CTest("null2", ft_strlcpy_args + ["-DTEST_NULL2"], asan=False))
ft_strlcpy.add(test.CTest("null3", ft_strlcpy_args + ["-DTEST_NULL3"], asan=False))
ft_strlcpy.add(test.CTest("random", ft_strlcpy_args + ["-DTEST_RANDOM"]))
groups.append(ft_strlcpy)

ft_strlcat_args = [test.join_proj("libft.a"), test.join_test("ft_strlcat/ft_strlcat.c")]
ft_strlcat_args += ["-Dft_strlcat=strlcat2"] if test.test_mode == "record" else []
ft_strlcat = test.Group("ft_strlcat")
ft_strlcat.add(test.CTest("empty", ft_strlcat_args + ["-DTEST_EMPTY"]))
ft_strlcat.add(test.CTest("null1", ft_strlcat_args + ["-DTEST_NULL1"], asan=False))
ft_strlcat.add(test.CTest("null2", ft_strlcat_args + ["-DTEST_NULL2"], asan=False))
ft_strlcat.add(test.CTest("null3", ft_strlcat_args + ["-DTEST_NULL3"], asan=False))
ft_strlcat.add(test.CTest("random", ft_strlcat_args + ["-DTEST_RANDOM"]))
groups.append(ft_strlcat)

ft_toupper_args = [test.join_proj("libft.a"), test.join_test("ft_toupper/ft_toupper.c")]
ft_toupper_args += ["-Dft_toupper=toupper"] if test.test_mode == "record" else []
ft_toupper = test.Group("ft_toupper")
ft_toupper.add(test.CTest("ascii", ft_toupper_args + ["-DTEST_ASCII"]))
ft_toupper.add(test.CTest("unsigned_char", ft_toupper_args + ["-DTEST_UNSIGNED_CHAR"]))
ft_toupper.add(test.CTest("signed_char", ft_toupper_args + ["-DTEST_SIGNED_CHAR"]))
ft_toupper.add(test.CTest("random", ft_toupper_args + ["-DTEST_RANDOM"]))
groups.append(ft_toupper)

ft_tolower_args = [test.join_proj("libft.a"), test.join_test("ft_tolower/ft_tolower.c")]
ft_tolower_args += ["-Dft_tolower=tolower"] if test.test_mode == "record" else []
ft_tolower = test.Group("ft_tolower")
ft_tolower.add(test.CTest("ascii", ft_tolower_args + ["-DTEST_ASCII"]))
ft_tolower.add(test.CTest("unsigned_char", ft_tolower_args + ["-DTEST_UNSIGNED_CHAR"]))
ft_tolower.add(test.CTest("signed_char", ft_tolower_args + ["-DTEST_SIGNED_CHAR"]))
ft_tolower.add(test.CTest("random", ft_tolower_args + ["-DTEST_RANDOM"]))
groups.append(ft_tolower)

ft_strchr_args = [test.join_proj("libft.a"), test.join_test("ft_strchr/ft_strchr.c")]
ft_strchr_args += ["-Dft_strchr=strchr"] if test.test_mode == "record" else []
ft_strchr = test.Group("ft_strchr")
ft_strchr.add(test.CTest("empty", ft_strchr_args + ["-DTEST_EMPTY"]))
ft_strchr.add(test.CTest("null", ft_strchr_args + ["-DTEST_NULL"], asan=False))
ft_strchr.add(test.CTest("basic", ft_strchr_args + ["-DTEST_BASIC"]))
ft_strchr.add(test.CTest("random", ft_strchr_args + ["-DTEST_RANDOM"]))
groups.append(ft_strchr)

ft_strrchr_args = [test.join_proj("libft.a"), test.join_test("ft_strrchr/ft_strrchr.c")]
ft_strrchr_args += ["-Dft_strrchr=strrchr"] if test.test_mode == "record" else []
ft_strrchr = test.Group("ft_strrchr")
ft_strrchr.add(test.CTest("empty", ft_strrchr_args + ["-DTEST_EMPTY"]))
ft_strrchr.add(test.CTest("null", ft_strrchr_args + ["-DTEST_NULL"], asan=False))
ft_strrchr.add(test.CTest("basic", ft_strrchr_args + ["-DTEST_BASIC"]))
ft_strrchr.add(test.CTest("random", ft_strrchr_args + ["-DTEST_RANDOM"]))
groups.append(ft_strrchr)

ft_strncmp_args = [test.join_proj("libft.a"), test.join_test("ft_strncmp/ft_strncmp.c")]
ft_strncmp_args += ["-Dft_strncmp=strncmp"] if test.test_mode == "record" else []
ft_strncmp = test.Group("ft_strncmp")
ft_strncmp.add(test.CTest("empty", ft_strncmp_args + ["-DTEST_EMPTY"]))
ft_strncmp.add(test.CTest("null1", ft_strncmp_args + ["-DTEST_NULL1"], asan=False))
ft_strncmp.add(test.CTest("null2", ft_strncmp_args + ["-DTEST_NULL2"], asan=False))
ft_strncmp.add(test.CTest("basic", ft_strncmp_args + ["-DTEST_BASIC"]))
ft_strncmp.add(test.CTest("random", ft_strncmp_args + ["-DTEST_RANDOM"]))
groups.append(ft_strncmp)

ft_memchr_args = [test.join_proj("libft.a"), test.join_test("ft_memchr/ft_memchr.c")]
ft_memchr_args += ["-Dft_memchr=memchr"] if test.test_mode == "record" else []
ft_memchr = test.Group("ft_memchr")
ft_memchr.add(test.CTest("empty", ft_memchr_args + ["-DTEST_EMPTY"]))
ft_memchr.add(test.CTest("null", ft_memchr_args + ["-DTEST_NULL"], asan=False))
ft_memchr.add(test.CTest("basic", ft_memchr_args + ["-DTEST_BASIC"]))
ft_memchr.add(test.CTest("random", ft_memchr_args + ["-DTEST_RANDOM"]))
groups.append(ft_memchr)

ft_memcmp_args = [test.join_proj("libft.a"), test.join_test("ft_memcmp/ft_memcmp.c")]
ft_memcmp_args += ["-Dft_memcmp=memcmp"] if test.test_mode == "record" else []
ft_memcmp = test.Group("ft_memcmp")
ft_memcmp.add(test.CTest("empty", ft_memcmp_args + ["-DTEST_EMPTY"]))
ft_memcmp.add(test.CTest("null1", ft_memcmp_args + ["-DTEST_NULL1"], asan=False))
ft_memcmp.add(test.CTest("null2", ft_memcmp_args + ["-DTEST_NULL2"], asan=False))
ft_memcmp.add(test.CTest("basic", ft_memcmp_args + ["-DTEST_BASIC"]))
ft_memcmp.add(test.CTest("random", ft_memcmp_args + ["-DTEST_RANDOM"]))
groups.append(ft_memcmp)

ft_strnstr_args = [test.join_proj("libft.a"), test.join_test("ft_strnstr/ft_strnstr.c")]
ft_strnstr_args += ["-Dft_strnstr=strnstr"] if test.test_mode == "record" else []
ft_strnstr = test.Group("ft_strnstr")
ft_strnstr.add(test.CTest("empty", ft_strnstr_args + ["-DTEST_EMPTY"]))
ft_strnstr.add(test.CTest("null1", ft_strnstr_args + ["-DTEST_NULL1"], asan=False))
ft_strnstr.add(test.CTest("null2", ft_strnstr_args + ["-DTEST_NULL2"], asan=False))
ft_strnstr.add(test.CTest("basic", ft_strnstr_args + ["-DTEST_BASIC"]))
ft_strnstr.add(test.CTest("random", ft_strnstr_args + ["-DTEST_RANDOM"]))
groups.append(ft_strnstr)

ft_atoi_args = [test.join_proj("libft.a"), test.join_test("ft_atoi/ft_atoi.c")]
ft_atoi_args += ["-Dft_atoi=atoi"] if test.test_mode == "record" else []
ft_atoi = test.Group("ft_atoi")
ft_atoi.add(test.CTest("null", ft_atoi_args + ["-DTEST_NULL"], asan=False))
ft_atoi.add(test.CTest("basic", ft_atoi_args + ["-DTEST_BASIC"]))
ft_atoi.add(test.CTest("intmax", ft_atoi_args + ["-DTEST_INTMAX"]))
ft_atoi.add(test.CTest("long", ft_atoi_args + ["-DTEST_LONGMAX"]))
ft_atoi.add(test.CTest("weird", ft_atoi_args + ["-DTEST_WEIRD"]))
ft_atoi.add(test.CTest("random", ft_atoi_args + ["-DTEST_RANDOM"]))
groups.append(ft_atoi)

ft_calloc_args = [test.join_proj("libft.a"), test.join_test("ft_calloc/ft_calloc.c")]
ft_calloc = test.Group("ft_calloc")
ft_calloc.add(test.CTest("zero", ft_calloc_args + ["-DTEST_ZERO"]))
ft_calloc.add(test.CTest("basic", ft_calloc_args + ["-DTEST_BASIC"]))
ft_calloc.add(test.CTest("null", ft_calloc_args + ["-DTEST_NULL"], asan=False))
ft_calloc.add(test.CTest("zero_mem", ft_calloc_args + ["-DTEST_ZERO", "-DTEST_MEM"]))
ft_calloc.add(test.CTest("basic_mem", ft_calloc_args + ["-DTEST_BASIC", "-DTEST_MEM"]))
ft_calloc.add(test.CTest("null_mem", ft_calloc_args + ["-DTEST_NULL", "-DTEST_MEM"], asan=False))
groups.append(ft_calloc)

ft_strdup_args = [test.join_proj("libft.a"), test.join_test("ft_strdup/ft_strdup.c")]
ft_strdup = test.Group("ft_strdup")
ft_strdup.add(test.CTest("empty", ft_strdup_args + ["-DTEST_EMPTY"]))
ft_strdup.add(test.CTest("basic", ft_strdup_args + ["-DTEST_BASIC"]))
ft_strdup.add(test.CTest("random", ft_strdup_args + ["-DTEST_RANDOM"]))
ft_strdup.add(test.CTest("null", ft_strdup_args + ["-DTEST_NULL"], asan=False))
ft_strdup.add(test.CTest("empty_mem", ft_strdup_args + ["-DTEST_EMPTY", "-DTEST_MEM"]))
ft_strdup.add(test.CTest("basic_mem", ft_strdup_args + ["-DTEST_BASIC", "-DTEST_MEM"]))
ft_strdup.add(test.CTest("random_mem", ft_strdup_args + ["-DTEST_RANDOM", "-DTEST_MEM"]))
ft_strdup.add(test.CTest("null_mem", ft_strdup_args + ["-DTEST_NULL", "-DTEST_MEM"], asan=False))
groups.append(ft_strdup)

ft_substr_args = [test.join_proj("libft.a"), test.join_test("ft_substr/ft_substr.c")]
ft_substr = test.Group("ft_substr")
ft_substr.add(test.CTest("empty", ft_substr_args + ["-DTEST_EMPTY"]))
ft_substr.add(test.CTest("basic", ft_substr_args + ["-DTEST_BASIC"]))
ft_substr.add(test.CTest("random", ft_substr_args + ["-DTEST_RANDOM"]))
ft_substr.add(test.CTest("null", ft_substr_args + ["-DTEST_NULL"], opt=True))
ft_substr.add(test.CTest("empty_mem", ft_substr_args + ["-DTEST_EMPTY", "-DTEST_MEM"], opt=True))
ft_substr.add(test.CTest("basic_mem", ft_substr_args + ["-DTEST_BASIC", "-DTEST_MEM"], opt=True))
ft_substr.add(test.CTest("random_mem", ft_substr_args + ["-DTEST_RANDOM", "-DTEST_MEM"], opt=True))
ft_substr.add(test.CTest("null_mem", ft_substr_args + ["-DTEST_NULL", "-DTEST_MEM"], opt=True))
groups.append(ft_substr)

ft_strjoin_args = [test.join_proj("libft.a"), test.join_test("ft_strjoin/ft_strjoin.c")]
ft_strjoin = test.Group("ft_strjoin")
ft_strjoin.add(test.CTest("empty", ft_strjoin_args + ["-DTEST_EMPTY"]))
ft_strjoin.add(test.CTest("basic", ft_strjoin_args + ["-DTEST_BASIC"]))
ft_strjoin.add(test.CTest("random", ft_strjoin_args + ["-DTEST_RANDOM"]))
ft_strjoin.add(test.CTest("null", ft_strjoin_args + ["-DTEST_NULL"], opt=True))
ft_strjoin.add(test.CTest("empty_mem", ft_strjoin_args + ["-DTEST_EMPTY", "-DTEST_MEM"], opt=True))
ft_strjoin.add(test.CTest("basic_mem", ft_strjoin_args + ["-DTEST_BASIC", "-DTEST_MEM"], opt=True))
ft_strjoin.add(test.CTest("random_mem", ft_strjoin_args + ["-DTEST_RANDOM", "-DTEST_MEM"], opt=True))
ft_strjoin.add(test.CTest("null_mem", ft_strjoin_args + ["-DTEST_NULL", "-DTEST_MEM"], opt=True))
groups.append(ft_strjoin)

ft_strtrim_args = [test.join_proj("libft.a"), test.join_test("ft_strtrim/ft_strtrim.c")]
ft_strtrim = test.Group("ft_strtrim")
ft_strtrim.add(test.CTest("empty", ft_strtrim_args + ["-DTEST_EMPTY"]))
ft_strtrim.add(test.CTest("basic", ft_strtrim_args + ["-DTEST_BASIC"]))
ft_strtrim.add(test.CTest("random", ft_strtrim_args + ["-DTEST_RANDOM"]))
ft_strtrim.add(test.CTest("null", ft_strtrim_args + ["-DTEST_NULL"], opt=True))
ft_strtrim.add(test.CTest("empty_mem", ft_strtrim_args + ["-DTEST_EMPTY", "-DTEST_MEM"], opt=True))
ft_strtrim.add(test.CTest("basic_mem", ft_strtrim_args + ["-DTEST_BASIC", "-DTEST_MEM"], opt=True))
ft_strtrim.add(test.CTest("random_mem", ft_strtrim_args + ["-DTEST_RANDOM", "-DTEST_MEM"], opt=True))
ft_strtrim.add(test.CTest("null_mem", ft_strtrim_args + ["-DTEST_NULL", "-DTEST_MEM"], opt=True))
groups.append(ft_strtrim)

ft_split_args = [test.join_proj("libft.a"), test.join_test("ft_split/ft_split.c")]
ft_split = test.Group("ft_split")
ft_split.add(test.CTest("empty", ft_split_args + ["-DTEST_EMPTY"]))
ft_split.add(test.CTest("basic", ft_split_args + ["-DTEST_BASIC"]))
ft_split.add(test.CTest("random", ft_split_args + ["-DTEST_RANDOM"]))
ft_split.add(test.CTest("null", ft_split_args + ["-DTEST_NULL"], opt=True))
ft_split.add(test.CTest("empty_mem", ft_split_args + ["-DTEST_EMPTY", "-DTEST_MEM"], opt=True))
ft_split.add(test.CTest("basic_mem", ft_split_args + ["-DTEST_BASIC", "-DTEST_MEM"], opt=True))
ft_split.add(test.CTest("random_mem", ft_split_args + ["-DTEST_RANDOM", "-DTEST_MEM"], opt=True))
ft_split.add(test.CTest("null_mem", ft_split_args + ["-DTEST_NULL", "-DTEST_MEM"], opt=True))
groups.append(ft_split)

ft_itoa_args = [test.join_proj("libft.a"), test.join_test("ft_itoa/ft_itoa.c")]
ft_itoa = test.Group("ft_itoa")
ft_itoa.add(test.CTest("basic", ft_itoa_args + ["-DTEST_BASIC"]))
ft_itoa.add(test.CTest("random", ft_itoa_args + ["-DTEST_RANDOM"]))
ft_itoa.add(test.CTest("intmax", ft_itoa_args + ["-DTEST_INTMAX"]))
ft_itoa.add(test.CTest("basic_mem", ft_itoa_args + ["-DTEST_BASIC", "-DTEST_MEM"], opt=True))
ft_itoa.add(test.CTest("random_mem", ft_itoa_args + ["-DTEST_RANDOM", "-DTEST_MEM"], opt=True))
ft_itoa.add(test.CTest("intmax_mem", ft_itoa_args + ["-DTEST_INTMAX", "-DTEST_MEM"], opt=True))
groups.append(ft_itoa)

ft_strmapi_args = [test.join_proj("libft.a"), test.join_test("ft_strmapi/ft_strmapi.c")]
ft_strmapi = test.Group("ft_strmapi")
ft_strmapi.add(test.CTest("empty", ft_strmapi_args + ["-DTEST_EMPTY"]))
ft_strmapi.add(test.CTest("basic", ft_strmapi_args + ["-DTEST_BASIC"]))
ft_strmapi.add(test.CTest("random", ft_strmapi_args + ["-DTEST_RANDOM"]))
ft_strmapi.add(test.CTest("null", ft_strmapi_args + ["-DTEST_NULL"], opt=True))
ft_strmapi.add(test.CTest("empty_mem", ft_strmapi_args + ["-DTEST_EMPTY", "-DTEST_MEM"], opt=True))
ft_strmapi.add(test.CTest("basic_mem", ft_strmapi_args + ["-DTEST_BASIC", "-DTEST_MEM"], opt=True))
ft_strmapi.add(test.CTest("random_mem", ft_strmapi_args + ["-DTEST_RANDOM", "-DTEST_MEM"], opt=True))
ft_strmapi.add(test.CTest("null_mem", ft_strmapi_args + ["-DTEST_NULL", "-DTEST_MEM"], opt=True))
groups.append(ft_strmapi)

ft_striteri_args = [test.join_proj("libft.a"), test.join_test("ft_striteri/ft_striteri.c")]
ft_striteri = test.Group("ft_striteri")
ft_striteri.add(test.CTest("empty", ft_striteri_args + ["-DTEST_EMPTY"]))
ft_striteri.add(test.CTest("basic", ft_striteri_args + ["-DTEST_BASIC"]))
ft_striteri.add(test.CTest("random", ft_striteri_args + ["-DTEST_RANDOM"]))
ft_striteri.add(test.CTest("null", ft_striteri_args + ["-DTEST_NULL"], opt=True))
groups.append(ft_striteri)

ft_putstr_fd_args = [test.join_proj("libft.a"), test.join_test("ft_putstr_fd/ft_putstr_fd.c")]
ft_putstr_fd = test.Group("ft_putstr_fd")
ft_putstr_fd.add(test.CTest("empty", ft_putstr_fd_args + ["-DTEST_EMPTY"]))
ft_putstr_fd.add(test.CTest("null", ft_putstr_fd_args + ["-DTEST_NULL"], opt=True))
ft_putstr_fd.add(test.CTest("basic", ft_putstr_fd_args + ["-DTEST_BASIC"]))
ft_putstr_fd.add(test.CTest("random", ft_putstr_fd_args + ["-DTEST_RANDOM"]))
groups.append(ft_putstr_fd)

ft_putchar_fd_args = [test.join_proj("libft.a"), test.join_test("ft_putchar_fd/ft_putchar_fd.c")]
ft_putchar_fd = test.Group("ft_putchar_fd")
ft_putchar_fd.add(test.CTest("basic", ft_putchar_fd_args + ["-DTEST_BASIC"]))
ft_putchar_fd.add(test.CTest("random", ft_putchar_fd_args + ["-DTEST_RANDOM"]))
groups.append(ft_putchar_fd)

ft_putendl_fd_args = [test.join_proj("libft.a"), test.join_test("ft_putendl_fd/ft_putendl_fd.c")]
ft_putendl_fd = test.Group("ft_putendl_fd")
ft_putendl_fd.add(test.CTest("empty", ft_putendl_fd_args + ["-DTEST_EMPTY"]))
ft_putendl_fd.add(test.CTest("null", ft_putendl_fd_args + ["-DTEST_NULL"], opt=True))
ft_putendl_fd.add(test.CTest("basic", ft_putendl_fd_args + ["-DTEST_BASIC"]))
ft_putendl_fd.add(test.CTest("random", ft_putendl_fd_args + ["-DTEST_RANDOM"]))
groups.append(ft_putendl_fd)

ft_putnbr_fd_args = [test.join_proj("libft.a"), test.join_test("ft_putnbr_fd/ft_putnbr_fd.c")]
ft_putnbr_fd = test.Group("ft_putnbr_fd")
ft_putnbr_fd.add(test.CTest("basic", ft_putnbr_fd_args + ["-DTEST_BASIC"]))
ft_putnbr_fd.add(test.CTest("random", ft_putnbr_fd_args + ["-DTEST_RANDOM"]))
ft_putnbr_fd.add(test.CTest("intmax", ft_putnbr_fd_args + ["-DTEST_INTMAX"]))
groups.append(ft_putnbr_fd)

ft_lstnew_args = [test.join_proj("libft.a"), test.join_test("ft_lstnew/ft_lstnew.c")]
ft_lstnew = test.Group("ft_lstnew")
ft_lstnew.add(test.CTest("main", ft_lstnew_args + []))
ft_lstnew.add(test.CTest("main_mem", ft_lstnew_args + ["-DTEST_MEM"]))
groups.append(ft_lstnew)

ft_lstadd_front_args = [test.join_proj("libft.a"), test.join_test("ft_lstadd_front/ft_lstadd_front.c")]
ft_lstadd_front = test.Group("ft_lstadd_front")
ft_lstadd_front.add(test.CTest("main", ft_lstadd_front_args + []))
ft_lstadd_front.add(test.CTest("main_mem", ft_lstadd_front_args + ["-DTEST_MEM"]))
groups.append(ft_lstadd_front)

ft_lstsize_args = [test.join_proj("libft.a"), test.join_test("ft_lstsize/ft_lstsize.c")]
ft_lstsize = test.Group("ft_lstsize")
ft_lstsize.add(test.CTest("main", ft_lstsize_args + []))
ft_lstsize.add(test.CTest("main_mem", ft_lstsize_args + ["-DTEST_MEM"]))
groups.append(ft_lstsize)

ft_lstlast_args = [test.join_proj("libft.a"), test.join_test("ft_lstlast/ft_lstlast.c")]
ft_lstlast = test.Group("ft_lstlast")
ft_lstlast.add(test.CTest("main", ft_lstlast_args + []))
ft_lstlast.add(test.CTest("main_mem", ft_lstlast_args + ["-DTEST_MEM"]))
groups.append(ft_lstlast)

ft_lstadd_back_args = [test.join_proj("libft.a"), test.join_test("ft_lstadd_back/ft_lstadd_back.c")]
ft_lstadd_back = test.Group("ft_lstadd_back")
ft_lstadd_back.add(test.CTest("main", ft_lstadd_back_args + []))
ft_lstadd_back.add(test.CTest("main_mem", ft_lstadd_back_args + ["-DTEST_MEM"]))
groups.append(ft_lstadd_back)

ft_lstdelone_args = [test.join_proj("libft.a"), test.join_test("ft_lstdelone/ft_lstdelone.c")]
ft_lstdelone = test.Group("ft_lstdelone")
ft_lstdelone.add(test.CTest("main", ft_lstdelone_args + []))
ft_lstdelone.add(test.CTest("main_mem", ft_lstdelone_args + ["-DTEST_MEM"]))
groups.append(ft_lstdelone)

ft_lstclear_args = [test.join_proj("libft.a"), test.join_test("ft_lstclear/ft_lstclear.c")]
ft_lstclear = test.Group("ft_lstclear")
ft_lstclear.add(test.CTest("main", ft_lstclear_args + []))
ft_lstclear.add(test.CTest("main_mem", ft_lstclear_args + ["-DTEST_MEM"]))
groups.append(ft_lstclear)

ft_lstiter_args = [test.join_proj("libft.a"), test.join_test("ft_lstiter/ft_lstiter.c")]
ft_lstiter = test.Group("ft_lstiter")
ft_lstiter.add(test.CTest("main", ft_lstiter_args + []))
ft_lstiter.add(test.CTest("main_mem", ft_lstiter_args + ["-DTEST_MEM"]))
groups.append(ft_lstiter)

ft_lstmap_args = [test.join_proj("libft.a"), test.join_test("ft_lstmap/ft_lstmap.c")]
ft_lstmap = test.Group("ft_lstmap")
ft_lstmap.add(test.CTest("main", ft_lstmap_args + []))
ft_lstmap.add(test.CTest("main_mem", ft_lstmap_args + ["-DTEST_MEM"]))
groups.append(ft_lstmap)

async def main():
	for group in groups:
		await group.start_async()

asyncio.run(main())

