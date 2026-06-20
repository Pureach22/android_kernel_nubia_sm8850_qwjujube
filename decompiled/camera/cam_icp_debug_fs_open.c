__int64 __fastcall cam_icp_debug_fs_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, cam_icp_get_icp_dbg_lvl, cam_icp_set_icp_dbg_lvl, "%08llu", a6);
}
