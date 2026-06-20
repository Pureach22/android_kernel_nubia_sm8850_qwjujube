__int64 __fastcall dsi_ctrl_hw_cmn_ctrl_reset(_DWORD *a1, int a2)
{
  int v3; // w4
  int v4; // w20

  if ( a1 )
    v3 = a1[14];
  else
    v3 = -1;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: DSI CTRL and PHY reset, mask=%d\n", v3, a2);
  v4 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 4LL));
  writel_relaxed_16(v4 & 0xFFFFFFFD, (unsigned int *)(*(_QWORD *)a1 + 4LL));
  __dsb(0xEu);
  writel_relaxed_16(v4 & 0xFFFFFFFC, (unsigned int *)(*(_QWORD *)a1 + 4LL));
  __dsb(0xEu);
  writel_relaxed_16(0x100A00u, (unsigned int *)(*(_QWORD *)a1 + 284LL));
  writel_relaxed_16(1u, (unsigned int *)(*(_QWORD *)a1 + 280LL));
  __dsb(0xEu);
  writel_relaxed_16(0, (unsigned int *)(*(_QWORD *)a1 + 280LL));
  __dsb(0xEu);
  writel_relaxed_16(0, (unsigned int *)(*(_QWORD *)a1 + 284LL));
  writel_relaxed_16(v4 & 0xFFFFFFFD, (unsigned int *)(*(_QWORD *)a1 + 4LL));
  __dsb(0xEu);
  return 0;
}
