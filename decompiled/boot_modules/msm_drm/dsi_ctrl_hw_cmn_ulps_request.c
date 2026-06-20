double __fastcall dsi_ctrl_hw_cmn_ulps_request(_DWORD *a1, int a2)
{
  int v4; // w0
  int v5; // w4

  v4 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 172LL));
  writel_relaxed_16(v4 | a2 & 0x1F, (unsigned int *)(*(_QWORD *)a1 + 172LL));
  usleep_range_state(100, 110, 2);
  if ( a1 )
    v5 = a1[14];
  else
    v5 = -1;
  return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: ULPS requested for lanes 0x%x\n", v5, a2);
}
