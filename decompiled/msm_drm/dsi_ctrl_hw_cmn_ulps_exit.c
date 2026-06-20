double __fastcall dsi_ctrl_hw_cmn_ulps_exit(_DWORD *a1, int a2)
{
  unsigned int v4; // w21
  int v5; // w4

  v4 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 172LL)) & 0x1000000;
  writel_relaxed_16(v4 | ((a2 & 0x1F) << 8), (unsigned int *)(*(_QWORD *)a1 + 172LL));
  usleep_range_state(1000, 1010, 2);
  writel_relaxed_16(v4 & 0xFFE0FFFF | ((a2 & 0x1F) << 16), (unsigned int *)(*(_QWORD *)a1 + 172LL));
  __dsb(0xEu);
  writel_relaxed_16(v4, (unsigned int *)(*(_QWORD *)a1 + 172LL));
  __dsb(0xEu);
  if ( a1 )
    v5 = a1[14];
  else
    v5 = -1;
  return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: ULPS exit request for lanes=0x%x\n", v5, a2);
}
