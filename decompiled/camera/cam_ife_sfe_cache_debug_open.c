__int64 __fastcall cam_ife_sfe_cache_debug_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, cam_ife_get_sfe_cache_debug, cam_ife_set_sfe_cache_debug, "%16llu", a6);
}
