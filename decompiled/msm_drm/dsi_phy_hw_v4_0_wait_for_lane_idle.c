__int64 __fastcall dsi_phy_hw_v4_0_wait_for_lane_idle(_DWORD *a1, char a2)
{
  char v4; // w0
  int v5; // w20
  int v6; // w4
  __int64 v7; // x0
  __int64 v8; // x21
  __int64 v9; // x0
  int v10; // w8
  __int64 v11; // x21
  int v12; // w4
  int v14; // w3

  v4 = readl_relaxed_13((unsigned int *)(*(_QWORD *)a1 + 24LL));
  __dsb(0xFu);
  v5 = v4 & 0x20 | a2 & 0xF | 0x10;
  if ( a1 )
    v6 = a1[7];
  else
    v6 = -1;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: polling for lanes to be in stop state, mask=0x%08x\n", v6, v5);
  v8 = ktime_get(v7);
  v9 = readl_7((unsigned int *)(*(_QWORD *)a1 + 332LL));
  v10 = v9 & v5;
  if ( ((unsigned int)v9 & v5) != v5 )
  {
    v11 = v8 + 100000;
    while ( ktime_get(v9) <= v11 )
    {
      usleep_range_state(3, 10, 2);
      __yield();
      v9 = readl_7((unsigned int *)(*(_QWORD *)a1 + 332LL));
      v10 = v9 & v5;
      if ( ((unsigned int)v9 & v5) == v5 )
        goto LABEL_8;
    }
    v12 = readl_7((unsigned int *)(*(_QWORD *)a1 + 332LL));
    if ( (v12 & v5) != v5 )
      goto LABEL_11;
    return 0;
  }
LABEL_8:
  v12 = v9;
  if ( v10 == v5 )
    return 0;
LABEL_11:
  if ( a1 )
    v14 = a1[7];
  else
    v14 = -1;
  drm_dev_printk(
    0,
    &unk_248D72,
    "*ERROR* [msm-dsi-error]: DSI_%d: lanes not in stop state, LANE_STATUS=0x%08x\n",
    v14,
    v12);
  return 4294967186LL;
}
