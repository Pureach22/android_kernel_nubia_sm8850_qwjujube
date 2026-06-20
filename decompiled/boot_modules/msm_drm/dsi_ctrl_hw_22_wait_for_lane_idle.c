__int64 __fastcall dsi_ctrl_hw_22_wait_for_lane_idle(__int64 a1, unsigned int a2)
{
  unsigned int v3; // w20
  int v4; // w4
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x0
  __int64 v9; // x21
  int v10; // w3

  v3 = (a2 << 19) & 0x100000
     | (((a2 >> 2) & 1) << 24) & 0xEFFFFFFF
     | (((a2 >> 3) & 1) << 28)
     | ((int)(a2 << 31) >> 31) & 0x11000;
  if ( a1 )
    v4 = *(_DWORD *)(a1 + 56);
  else
    v4 = -1;
  _drm_dev_dbg(
    0,
    0,
    0,
    "[msm-dsi-debug]: DSI_%d: %s: polling for fifo empty, mask=0x%08x\n",
    v4,
    "dsi_ctrl_hw_22_wait_for_lane_idle",
    v3);
  v6 = ktime_get(v5);
  v7 = readl_14(*(_QWORD *)a1 + 12LL);
  if ( ((unsigned int)v7 & v3) != 0 )
    return 0;
  v9 = v6 + 100000;
  while ( ktime_get(v7) <= v9 )
  {
    usleep_range_state(3, 10, 2);
    __yield();
    v7 = readl_14(*(_QWORD *)a1 + 12LL);
    if ( ((unsigned int)v7 & v3) != 0 )
      goto LABEL_11;
  }
  LODWORD(v7) = readl_14(*(_QWORD *)a1 + 12LL);
LABEL_11:
  if ( ((unsigned int)v7 & v3) != 0 )
    return 0;
  if ( a1 )
    v10 = *(_DWORD *)(a1 + 56);
  else
    v10 = -1;
  drm_dev_printk(
    0,
    &unk_248D72,
    "*ERROR* [msm-dsi-error]: DSI_%d: %s: fifo not empty, FIFO_STATUS=0x%08x\n",
    v10,
    "dsi_ctrl_hw_22_wait_for_lane_idle",
    v7);
  return 4294967186LL;
}
