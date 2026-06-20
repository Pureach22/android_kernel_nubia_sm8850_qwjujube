double __fastcall dsi_ctrl_hw_cmn_ctrl_en(_DWORD *a1, char a2)
{
  unsigned int v4; // w21
  int v5; // w0
  int v6; // w4

  v4 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 284LL));
  writel_relaxed_16(v4 | 0x200B3F, (unsigned int *)(*(_QWORD *)a1 + 284LL));
  __dsb(0xEu);
  v5 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 4LL));
  writel_relaxed_16(v5 & 0xFFFFFFFE | a2 & 1, (unsigned int *)(*(_QWORD *)a1 + 4LL));
  __dsb(0xEu);
  writel_relaxed_16(v4, (unsigned int *)(*(_QWORD *)a1 + 284LL));
  __dsb(0xEu);
  if ( a1 )
    v6 = a1[14];
  else
    v6 = -1;
  return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: Controller engine = %d\n", v6, a2 & 1);
}
