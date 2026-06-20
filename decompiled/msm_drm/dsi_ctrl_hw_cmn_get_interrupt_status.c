__int64 __fastcall dsi_ctrl_hw_cmn_get_interrupt_status(_DWORD *a1)
{
  unsigned int v2; // w0
  int v3; // w4
  int v4; // w19
  int v5; // w20

  v2 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 272LL));
  if ( a1 )
    v3 = a1[14];
  else
    v3 = -1;
  v4 = v2 & 1
     | (((v2 >> 8) & 1) << 6)
     | (v2 >> 9) & 2
     | (v2 >> 10) & 4
     | (v2 >> 11) & 8
     | (v2 >> 12) & 0x10
     | (v2 >> 15) & 0x20;
  v5 = (v2 >> 21) & 0x80 | (v2 >> 22) & 0x100 | (v2 >> 14) & 0x400;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: Interrupt status = 0x%x, INT_CTRL=0x%x\n", v3, v4 | v5, v2);
  return v4 | (unsigned int)v5;
}
