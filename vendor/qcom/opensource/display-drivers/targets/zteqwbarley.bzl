load("//build/kernel/kleaf:kernel.bzl", "ddk_headers")

# 0 means hdrs
# 1 means ex-flags
# 2 means srcs

def zteqwbarley_disp_fun(p):
    if p == 0:
        ddk_headers(
            name = "zte_disp",
            hdrs = native.glob([
            "msm/zte_disp/*.h",
            ]),
            includes = ["msm/zte_disp"]
        )
        return [":zte_disp"]
    elif p == 1:
        return ["CONFIG_DRM_ZTE_DISP",
            "CONFIG_DRM_ZTE_DISP_LTM"]
    elif p == 2:
        return [
            "msm/zte_disp/zte_disp_backlight.c",
            "msm/zte_disp/zte_disp_feature.c",
            "msm/zte_disp/zte_disp_panel.c",
            "msm/zte_disp/zte_disp_panel_info.c",
            "msm/zte_disp/zte_lcd_reg_debug.c",
            "msm/zte_disp/zte_disp_sde.c",
            "msm/zte_disp/zte_disp_work.c",
        ]