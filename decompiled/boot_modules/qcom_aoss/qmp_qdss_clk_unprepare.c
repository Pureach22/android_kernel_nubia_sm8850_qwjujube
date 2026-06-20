__int64 __fastcall qmp_qdss_clk_unprepare(__int64 a1, __int64 a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  char vars0; // [xsp+0h] [xbp+0h]

  return qmp_send(a1 - 168, "{class: clock, res: qdss, val: 0}", a3, a4, a5, a6, a7, a8, vars0);
}
