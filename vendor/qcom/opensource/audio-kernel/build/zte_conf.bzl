load("//soc-repo:configs/oemspec.bzl", "get_zte_board_name")

def zte_audio_config(c):
    ret = []

    # 根据输入参数c添加配置
    if c == "awinic":
        ret = ["CONFIG_SND_SMARTPA_AW882XX"]

    # 获取板级名
    board_name = get_zte_board_name()

    # 根据板级名添加配置
    if board_name == "qwbarley":
        ret += ["CONFIG_SOC_PA_SWITCH"]
    if board_name == "qwjujube":
        pass # 不做任何设置
    else:
        pass # 不做任何设置
    return ret