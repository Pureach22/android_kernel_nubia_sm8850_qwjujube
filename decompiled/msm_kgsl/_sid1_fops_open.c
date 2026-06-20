__int64 __fastcall sid1_fops_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, bcl_sid1_get, bcl_sid1_set, "%llu\n", a6);
}
