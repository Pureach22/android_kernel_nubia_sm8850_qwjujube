double __fastcall dsi_link_lp_clk_stop(_QWORD *a1)
{
  __int64 v1; // x19

  v1 = *a1;
  clk_disable(*a1);
  clk_unprepare(v1);
  return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: LP Link clocks are disabled\n");
}
