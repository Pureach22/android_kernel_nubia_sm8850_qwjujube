double __fastcall dsi_ctrl_hw_cmn_clear_interrupt_status(_DWORD *a1, unsigned int a2)
{
  unsigned int v4; // w21
  int v5; // w22
  int v6; // w4

  v4 = a2 & 1
     | (((a2 >> 6) & 1) << 8) & 0xFFEEABFF
     | (((a2 >> 1) & 1) << 10) & 0xFFEEAFFF
     | (((a2 >> 2) & 1) << 12) & 0xFFEEBFFF
     | (((a2 >> 3) & 1) << 14) & 0xFFEEFFFF
     | (((a2 >> 4) & 1) << 16) & 0xFFEFFFFF
     | (((a2 >> 5) & 1) << 20);
  v5 = (a2 << 22) & 0x40000000 | readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 272LL)) & 0xEEFFFFFF;
  writel_relaxed_16(v4 | v5, (unsigned int *)(*(_QWORD *)a1 + 272LL));
  if ( a1 )
    v6 = a1[14];
  else
    v6 = -1;
  return _drm_dev_dbg(
           0,
           0,
           0,
           "[msm-dsi-debug]: DSI_%d: Clear interrupts, ints = 0x%x, INT_CTRL=0x%x\n",
           v6,
           a2,
           v4 | v5);
}
