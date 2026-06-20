__int64 __fastcall geni_se_common_clks_off(__int64 a1, __int64 a2, __int64 a3)
{
  clk_disable(a1);
  clk_unprepare(a1);
  clk_disable(a2);
  clk_unprepare(a2);
  clk_disable(a3);
  return clk_unprepare(a3);
}
