__int64 __fastcall sde_hw_intf_wait_for_esync_src_switch(__int64 a1, char a2)
{
  int v3; // w21
  __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x20
  int v7; // w0

  v3 = a2 & 1;
  v4 = ktime_get(a1);
  v5 = readl_relaxed_9(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + 1168LL);
  if ( (_DWORD)v5 == v3 )
  {
LABEL_5:
    v7 = v3;
  }
  else
  {
    v6 = v4 + 5000000;
    while ( ktime_get(v5) <= v6 )
    {
      usleep_range_state(26, 100, 2);
      __yield();
      v5 = readl_relaxed_9(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + 1168LL);
      if ( (_DWORD)v5 == v3 )
        goto LABEL_5;
    }
    v7 = readl_relaxed_9(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + 1168LL);
  }
  if ( v7 == v3 )
    return 0;
  else
    return 4294967186LL;
}
