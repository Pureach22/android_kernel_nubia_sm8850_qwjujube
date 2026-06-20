__int64 __fastcall cam_icp_debug_default_clk_open(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  return simple_attr_open(a1, a2, cam_icp_get_dbg_default_clk, cam_icp_set_dbg_default_clk, "%16llu", a6);
}
