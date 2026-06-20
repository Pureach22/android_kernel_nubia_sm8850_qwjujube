__int64 __fastcall dsi_ctrl_hw_22_collect_misr(_DWORD *a1)
{
  __int16 v2; // w19
  unsigned int v3; // w20
  int v4; // w4

  v2 = readl_relaxed_20((unsigned int *)(*(_QWORD *)a1 + 868LL));
  if ( (v2 & 0x100) != 0 )
  {
    v3 = readl_relaxed_20((unsigned int *)(*(_QWORD *)a1 + 872LL));
    if ( a1 )
      goto LABEL_3;
LABEL_5:
    v4 = -1;
    goto LABEL_6;
  }
  v3 = 0;
  if ( !a1 )
    goto LABEL_5;
LABEL_3:
  v4 = a1[14];
LABEL_6:
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: MISR enabled:%d value:0x%x\n", v4, v2 & 0x100, v3);
  return v3;
}
