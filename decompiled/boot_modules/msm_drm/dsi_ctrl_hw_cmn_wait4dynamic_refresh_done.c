__int64 __fastcall dsi_ctrl_hw_cmn_wait4dynamic_refresh_done(_DWORD *a1)
{
  __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x20
  int v5; // w3
  int v6; // w0
  unsigned int v7; // w19

  v2 = ktime_get(a1);
  v3 = readl_13((unsigned int *)(*(_QWORD *)a1 + 272LL));
  if ( (v3 & 0x10000000) != 0 )
  {
LABEL_5:
    if ( (v3 & 0x10000000) != 0 )
    {
LABEL_9:
      v6 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 272LL));
      writel_relaxed_16(v6 | 0x10000000, (unsigned int *)(*(_QWORD *)a1 + 272LL));
      return 0;
    }
  }
  else
  {
    v4 = v2 + 84000000;
    while ( ktime_get(v3) <= v4 )
    {
      usleep_range_state(251, 1000, 2);
      __yield();
      v3 = readl_13((unsigned int *)(*(_QWORD *)a1 + 272LL));
      if ( (v3 & 0x10000000) != 0 )
        goto LABEL_5;
    }
    if ( (readl_13((unsigned int *)(*(_QWORD *)a1 + 272LL)) & 0x10000000) != 0 )
      goto LABEL_9;
  }
  if ( a1 )
    v5 = a1[14];
  else
    v5 = -1;
  v7 = -110;
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: wait4dynamic refresh timedout %d\n", v5, -110);
  return v7;
}
