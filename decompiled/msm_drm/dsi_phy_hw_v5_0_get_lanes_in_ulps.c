__int64 __fastcall dsi_phy_hw_v5_0_get_lanes_in_ulps(_DWORD *a1)
{
  unsigned int v2; // w19
  int v3; // w4

  v2 = readl_relaxed_14((unsigned int *)(*(_QWORD *)a1 + 328LL));
  if ( a1 )
    v3 = a1[7];
  else
    v3 = -1;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: lanes in ulps = 0x%x\n", v3, v2);
  return v2;
}
