import ctypes
import os

ROUGE = "\033[91m"
VERT  = "\033[92m"
RESET = "\033[0m"

lib_way = os.path.abspath("ft_lib.so")
lib = ctypes.CDLL(lib_way)

#lib.ft_strlen.restype = ctypes.c_int
#lib.ft_strlen.argtypes = [ctypes.c_char_p]

#lib.ft_strcmp.restype = ctypes.c_int
#lib.ft_strcmp.argtypes = [ctypes.c_char_p]

def display_message(function_name, output, expected):
    if (output == expected):
        print(f"{VERT}{function_name}: {expected} == {output}{RESET}")
    else:
        print(f"{ROUGE}{function_name}: expected: {expected} got: {output}{RESET}")

def core_int(fonction_name, args = 0, f = None, ex = 0, one = None, two = None,  three = None, four = None):
    if (f == None):
        print("error not enogth arguments")
        return
    if (args == 0):
        ret = f()
    elif (args == 1):
        ret = f(one)
    elif (args == 2):
        ret = f(one, two)
    elif (args == 3):
        ret = f(one, two, tree)
    elif (args == 4):
        ret = f(one, two, tree, fout)
    else:
        print("Error norminette")
    display_message(fonction_name, ret, ex)

core_int("ft_strlen", 1, lib.ft_strlen, 3, b"aze")
core_int("ft_strlen", 1, lib.ft_strlen, 3, b"azee")
core_int("ft_strcmp", 2, lib.ft_strcmp, 0, b"aze", b"aze")
core_int("ft_strcmp", 2, lib.ft_strcmp, 0, b"aze", b"azee")
