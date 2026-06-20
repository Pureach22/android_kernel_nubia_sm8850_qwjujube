__int64 __fastcall dsi_clk_disable_unprepare(__int64 *a1)
{
  __int64 v1; // x20
  __int64 v3; // x19

  v1 = a1[1];
  clk_disable(v1);
  clk_unprepare(v1);
  v3 = *a1;
  clk_disable(v3);
  return clk_unprepare(v3);
}
