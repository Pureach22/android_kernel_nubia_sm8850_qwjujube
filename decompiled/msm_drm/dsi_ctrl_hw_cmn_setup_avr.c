double __fastcall dsi_ctrl_hw_cmn_setup_avr(unsigned int *a1, char a2)
{
  int v4; // w10
  int v5; // w8
  __int64 v6; // x4
  const char *v7; // x5

  v4 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 16LL)) & 0xDFFFFFFF;
  if ( (a2 & 1) != 0 )
    v5 = 0x20000000;
  else
    v5 = 0;
  writel_relaxed_16(v4 | v5, (unsigned int *)(*(_QWORD *)a1 + 16LL));
  if ( a1 )
    v6 = a1[14];
  else
    v6 = 0xFFFFFFFFLL;
  if ( (a2 & 1) != 0 )
    v7 = "enabled";
  else
    v7 = "disabled";
  return _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: AVR %s\n", v6, v7);
}
