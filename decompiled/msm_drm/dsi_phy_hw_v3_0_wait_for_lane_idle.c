__int64 __fastcall dsi_phy_hw_v3_0_wait_for_lane_idle(_DWORD *a1, char a2)
{
  int v3; // w20
  int v4; // w4
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x0
  int v8; // w8
  __int64 v9; // x21
  int v10; // w4
  int v12; // w3

  v3 = a2 & 0xF | 0x10;
  if ( a1 )
    v4 = a1[7];
  else
    v4 = -1;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: polling for lanes to be in stop state, mask=0x%08x\n", v4, v3);
  v6 = ktime_get(v5);
  v7 = readl_6((unsigned int *)(*(_QWORD *)a1 + 248LL));
  v8 = v7 & v3;
  if ( ((unsigned int)v7 & v3) != v3 )
  {
    v9 = v6 + 100000;
    while ( ktime_get(v7) <= v9 )
    {
      usleep_range_state(3, 10, 2);
      __yield();
      v7 = readl_6((unsigned int *)(*(_QWORD *)a1 + 248LL));
      v8 = v7 & v3;
      if ( ((unsigned int)v7 & v3) == v3 )
        goto LABEL_8;
    }
    v10 = readl_6((unsigned int *)(*(_QWORD *)a1 + 248LL));
    if ( (v10 & v3) != v3 )
      goto LABEL_11;
    return 0;
  }
LABEL_8:
  v10 = v7;
  if ( v8 == v3 )
    return 0;
LABEL_11:
  if ( a1 )
    v12 = a1[7];
  else
    v12 = -1;
  drm_dev_printk(
    0,
    &unk_248D72,
    "*ERROR* [msm-dsi-error]: DSI_%d: lanes not in stop state, LANE_STATUS=0x%08x\n",
    v12,
    v10);
  return 4294967186LL;
}
