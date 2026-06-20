__int64 __fastcall cam_soc_util_clk_lvl_control_open(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  return simple_attr_open(a1, a2, cam_soc_util_get_clk_lvl_override, cam_soc_util_set_clk_lvl_override, "%08llu", a6);
}
