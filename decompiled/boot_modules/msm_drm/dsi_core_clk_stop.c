__int64 __fastcall dsi_core_clk_stop(__int64 *a1)
{
  __int64 v1; // x20
  __int64 v3; // x20
  __int64 v4; // x20
  __int64 v5; // x20
  __int64 v6; // x20
  __int64 v7; // x19

  v1 = a1[3];
  if ( v1 )
  {
    clk_disable(a1[3]);
    clk_unprepare(v1);
  }
  v3 = a1[4];
  if ( v3 )
  {
    clk_disable(a1[4]);
    clk_unprepare(v3);
  }
  v4 = a1[2];
  if ( v4 )
  {
    clk_disable(a1[2]);
    clk_unprepare(v4);
  }
  v5 = a1[1];
  if ( v5 )
  {
    clk_disable(a1[1]);
    clk_unprepare(v5);
  }
  v6 = a1[5];
  if ( v6 )
  {
    clk_disable(a1[5]);
    clk_unprepare(v6);
  }
  v7 = *a1;
  if ( v7 )
  {
    clk_disable(v7);
    clk_unprepare(v7);
  }
  return 0;
}
