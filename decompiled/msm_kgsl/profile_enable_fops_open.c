__int64 __fastcall profile_enable_fops_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, profile_enable_get, profile_enable_set, "%llu\n", a6);
}
