load("//soc-repo:configs/oemspec.bzl", "get_zte_board_name")
#Need add board bzl begin
load(":targets/ztenull.bzl", "ztenull_disp_fun")
load(":targets/zteqwbarley.bzl", "zteqwbarley_disp_fun")
load(":targets/zteqwjujube.bzl", "zteqwjujube_disp_fun")

def get_inf_fun(p, board):
    if board == "qwbarley":
        return zteqwbarley_disp_fun
    elif board == "qwjujube":
        return zteqwjujube_disp_fun
    else:
        return ztenull_disp_fun
#Need add board bzl end

def zte_fun_init(p):
    fun = get_inf_fun(p, get_zte_board_name())
    return fun(p)