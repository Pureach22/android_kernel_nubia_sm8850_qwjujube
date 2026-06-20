__int64 __fastcall dsi_ctrl_hw_cmn_collect_misr(__int64 a1, int a2)
{
  __int64 v2; // x8
  unsigned int *v5; // x0
  int v6; // w19
  int v7; // w19
  __int64 v8; // x8
  unsigned int v9; // w21
  int v10; // w4

  v2 = 164;
  if ( a2 == 2 )
    v2 = 160;
  v5 = (unsigned int *)(*(_QWORD *)a1 + v2);
  if ( a2 == 2 )
    v6 = 0x10000000;
  else
    v6 = 0x10000;
  v7 = readl_relaxed_19(v5) & v6;
  if ( v7 )
  {
    v8 = 320;
    if ( a2 == 2 )
      v8 = 308;
    v9 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + v8));
    if ( a1 )
      goto LABEL_10;
LABEL_12:
    v10 = -1;
    goto LABEL_13;
  }
  v9 = 0;
  if ( !a1 )
    goto LABEL_12;
LABEL_10:
  v10 = *(_DWORD *)(a1 + 56);
LABEL_13:
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: MISR enabled %x value: 0x%x\n", v10, v7, v9);
  return v9;
}
