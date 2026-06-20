double __fastcall dsi_phy_hw_v7_2_ulps_request(_DWORD *a1, __int64 a2, int a3)
{
  unsigned int v6; // w22
  int v7; // w0
  int v8; // w0
  int v9; // w4

  if ( *(_BYTE *)(a2 + 320) )
    v6 = a3 & 0x1F | 0x80;
  else
    v6 = a3 & 0x1F;
  if ( *(_BYTE *)(a2 + 304) == 1 )
  {
    v6 |= 0x60u;
    if ( *(_BYTE *)(a2 + 320) )
    {
      v7 = readl_relaxed_15((unsigned int *)(*(_QWORD *)a1 + 436LL));
      writel_relaxed_12(v7 | 4, (unsigned int *)(*(_QWORD *)a1 + 436LL));
    }
  }
  writel_relaxed_12(v6, (unsigned int *)(*(_QWORD *)a1 + 164LL));
  usleep_range_state(100, 110, 2);
  v8 = dsi_phy_conv_logical_to_phy_lane(a2 + 296, 0);
  writel_relaxed_12(0, (unsigned int *)(*(_QWORD *)a1 + (v8 << 7) + 532));
  if ( a1 )
    v9 = a1[7];
  else
    v9 = -1;
  return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: ULPS requested for lanes 0x%x\n", v9, a3);
}
