__int64 __fastcall cam_cci_debug_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, cam_cci_get_debug, cam_cci_set_debug, "%16llu\n", a6);
}
