__int64 __fastcall icc_debug_suspend_fops_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, icc_debug_suspend_get, icc_debug_suspend_set, "%llu\n", a6);
}
