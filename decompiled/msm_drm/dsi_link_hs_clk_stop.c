double __fastcall dsi_link_hs_clk_stop(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x0

  v2 = a1[2];
  if ( v2 )
    clk_disable(v2);
  clk_disable(a1[1]);
  clk_disable(*a1);
  v3 = a1[2];
  if ( v3 )
    clk_unprepare(v3);
  clk_unprepare(a1[1]);
  clk_unprepare(*a1);
  return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: HS Link clocks disabled\n");
}
