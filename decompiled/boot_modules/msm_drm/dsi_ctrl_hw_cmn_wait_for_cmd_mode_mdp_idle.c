__int64 __fastcall dsi_ctrl_hw_cmn_wait_for_cmd_mode_mdp_idle(_DWORD *a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x20
  int v6; // w3

  v2 = ktime_get(a1);
  v3 = readl_13((unsigned int *)(*(_QWORD *)a1 + 8LL));
  if ( (v3 & 4) == 0 )
    return 0;
  v4 = v2 + 200000000;
  while ( ktime_get(v3) <= v4 )
  {
    usleep_range_state(501, 2000, 2);
    __yield();
    v3 = readl_13((unsigned int *)(*(_QWORD *)a1 + 8LL));
    if ( (v3 & 4) == 0 )
      return 0;
  }
  if ( (readl_13((unsigned int *)(*(_QWORD *)a1 + 8LL)) & 4) == 0 )
    return 0;
  if ( a1 )
    v6 = a1[14];
  else
    v6 = -1;
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: timed out waiting for idle\n", v6);
  return 4294967186LL;
}
