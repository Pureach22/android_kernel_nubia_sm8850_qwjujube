double __fastcall dsi_phy_hw_v3_0_disable(unsigned int *a1, __int64 a2)
{
  char v4; // w0
  int v5; // w0
  int v6; // w0
  int v7; // w4
  __int64 v9; // x1

  v4 = readl_relaxed_12((unsigned int *)(*(_QWORD *)a1 + 56LL));
  __dsb(0xFu);
  if ( (v4 & 1) != 0 )
  {
    if ( a1 )
      v9 = a1[7];
    else
      v9 = 0xFFFFFFFFLL;
    printk(&unk_25FC9D, v9);
  }
  v5 = dsi_phy_conv_logical_to_phy_lane(a2 + 296, 0);
  writel_relaxed_9(0, (unsigned int *)(*(_QWORD *)a1 + (v5 << 7) + 552));
  v6 = readl_relaxed_12((unsigned int *)(*(_QWORD *)a1 + 36LL));
  writel_relaxed_9(v6 & 0xFFFFFFE0, (unsigned int *)(*(_QWORD *)a1 + 36LL));
  writel_relaxed_9(0, (unsigned int *)(*(_QWORD *)a1 + 152LL));
  writel_relaxed_9(0, (unsigned int *)(*(_QWORD *)a1 + 36LL));
  __dsb(0xEu);
  if ( a1 )
    v7 = a1[7];
  else
    v7 = -1;
  return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: Phy disabled\n", v7);
}
