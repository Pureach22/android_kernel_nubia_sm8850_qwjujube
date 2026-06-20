__int64 __fastcall dsi_ctrl_hw_22_setup_misr(unsigned int *a1, __int64 a2, char a3, unsigned int a4)
{
  __int64 v7; // x4
  __int64 v8; // x5
  unsigned int v9; // w21
  __int64 result; // x0

  writel_relaxed_17(0, (unsigned int *)(*(_QWORD *)a1 + 868LL));
  __dsb(0xEu);
  if ( a1 )
    v7 = a1[14];
  else
    v7 = 0xFFFFFFFFLL;
  v8 = a3 & 1;
  if ( (a3 & 1) != 0 )
    v9 = (unsigned __int16)a4 | 0x81000100;
  else
    v9 = 0;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: MISR enable:%d, frame_count:%d, config:0x%x\n", v7, v8, a4, v9);
  result = writel_relaxed_17(v9, (unsigned int *)(*(_QWORD *)a1 + 868LL));
  __dsb(0xEu);
  return result;
}
