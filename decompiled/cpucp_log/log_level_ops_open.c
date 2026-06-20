__int64 __fastcall log_level_ops_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, get_log_level, set_log_level, "%llu\n", a6);
}
