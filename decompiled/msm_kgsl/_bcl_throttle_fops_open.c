__int64 __fastcall bcl_throttle_fops_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, bcl_throttle_time_us_get, 0, "%llu\n", a6);
}
