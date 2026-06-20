__int64 __fastcall clk_rate_fops_open(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  return simple_attr_open(a1, a2, clk_rate_get, clk_rate_set, "%llu\n", a6);
}
