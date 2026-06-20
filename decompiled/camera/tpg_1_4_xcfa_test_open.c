__int64 __fastcall tpg_1_4_xcfa_test_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, tpg_1_4_get_xcfa_test, tpg_1_4_set_xcfa_test, "%16lld", a6);
}
