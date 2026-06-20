double __fastcall dsi_phy_hw_v3_0_ulps_request(_DWORD *a1, __int64 a2, int a3)
{
  int v6; // w0
  int v7; // w4

  writel_relaxed_9(a3 & 0x1F, (unsigned int *)(*(_QWORD *)a1 + 156LL));
  usleep_range_state(100, 110, 2);
  v6 = dsi_phy_conv_logical_to_phy_lane(a2 + 296, 0);
  writel_relaxed_9(0, (unsigned int *)(*(_QWORD *)a1 + (v6 << 7) + 552));
  writel_relaxed_9(0x19u, (unsigned int *)(*(_QWORD *)a1 + 32LL));
  if ( a1 )
    v7 = a1[7];
  else
    v7 = -1;
  return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: ULPS requested for lanes 0x%x\n", v7, a3);
}
