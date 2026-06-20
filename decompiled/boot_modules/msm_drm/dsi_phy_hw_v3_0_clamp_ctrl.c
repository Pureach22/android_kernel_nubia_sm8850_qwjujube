void __fastcall dsi_phy_hw_v3_0_clamp_ctrl(unsigned int *a1, char a2)
{
  __int64 v3; // x4
  int v4; // w20
  const char *v5; // x5
  double v6; // d0
  int v7; // w20

  if ( a1 )
    v3 = a1[7];
  else
    v3 = 0xFFFFFFFFLL;
  v4 = a2 & 1;
  if ( (a2 & 1) != 0 )
    v5 = "true";
  else
    v5 = "false";
  v6 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: enable=%s\n", v3, v5);
  if ( !v4 )
  {
    v7 = readl_relaxed_12(*(_QWORD *)a1 + 940LL, v6);
    writel_relaxed_9(v7 | 1, (unsigned int *)(*(_QWORD *)a1 + 940LL));
    __dsb(0xEu);
    writel_relaxed_9(v7 & 0xFFFFFFFE, (unsigned int *)(*(_QWORD *)a1 + 940LL));
    __dsb(0xEu);
  }
}
