__int64 __fastcall master_adsp_stats_show(__int64 a1)
{
  __int64 inited; // x0
  __int64 v3; // x20
  unsigned int v4; // w8
  __int64 v5; // x2
  unsigned int v6; // w8
  __int64 v7; // x2
  __int64 v8; // x20
  __int64 (__fastcall *v9)(__int64); // x8
  __int64 v10; // x20
  __int64 (__fastcall *v11)(__int64); // x8
  __int64 result; // x0
  __int64 i; // x20
  _DWORD *v14; // x8
  int v15; // w3
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v17; // x10
  __int64 v19; // x2
  _DWORD s[100]; // [xsp+8h] [xbp-198h] BYREF
  __int64 v21; // [xsp+198h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  inited = (__int64)memset(s, 0, sizeof(s));
  if ( (g_sysmon_stats & 1) != 0 )
  {
    if ( !g_sysmon_stats )
      goto LABEL_43;
  }
  else
  {
    inited = sysmon_smem_init_adsp();
    if ( (g_sysmon_stats & 1) == 0 )
    {
LABEL_43:
      result = 0;
      goto LABEL_44;
    }
  }
  v3 = qword_9620;
  if ( qword_9620 )
  {
    seq_write(a1, "\nsysMon stats:\n\n", 16);
    seq_printf(a1, "Core clock(KHz): %d\n", *(_DWORD *)(v3 + 4));
    seq_printf(a1, "Ab vote(Bytes): %llu\n", *(_QWORD *)(v3 + 8));
    seq_printf(a1, "Ib vote(Bytes): %llu\n", *(_QWORD *)(v3 + 16));
    v4 = *(_DWORD *)(v3 + 24);
    if ( v4 )
      v5 = v4;
    else
      v5 = 0xFFFFFFFFLL;
    inited = seq_printf(a1, "Sleep latency(usec): %u\n", v5);
  }
  if ( qword_9680 )
  {
    seq_write(a1, "\nDSPPM stats:\n\n", 15);
    seq_printf(a1, "Version: %u\n", *(_DWORD *)qword_9680);
    v6 = *(_DWORD *)(qword_9680 + 4);
    if ( v6 )
      v7 = v6;
    else
      v7 = 0xFFFFFFFFLL;
    seq_printf(a1, "Sleep latency(usec): %u\n", v7);
    seq_printf(a1, "Timestamp: %u\n", *(_DWORD *)(qword_9680 + 8));
    seq_printf(a1, "Pid: %d, Num active clients: %d\n", *(_DWORD *)(qword_9680 + 12), *(_DWORD *)(qword_9680 + 16));
    seq_printf(a1, "Pid: %d, Num active clients: %d\n", *(_DWORD *)(qword_9680 + 20), *(_DWORD *)(qword_9680 + 24));
    seq_printf(a1, "Pid: %d, Num active clients: %d\n", *(_DWORD *)(qword_9680 + 28), *(_DWORD *)(qword_9680 + 32));
    seq_printf(a1, "Pid: %d, Num active clients: %d\n", *(_DWORD *)(qword_9680 + 36), *(_DWORD *)(qword_9680 + 40));
    inited = seq_printf(
               a1,
               "Pid: %d, Num active clients: %d\n",
               *(_DWORD *)(qword_9680 + 44),
               *(_DWORD *)(qword_9680 + 48));
  }
  if ( qword_9640 )
  {
    v8 = *(_QWORD *)(qword_9640 + 24);
    if ( *(_QWORD *)(qword_9640 + 8) > *(_QWORD *)(qword_9640 + 16) )
    {
      v9 = (__int64 (__fastcall *)(__int64))arch_timer_read_counter;
      if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
        __break(0x8228u);
      v8 = v9(inited) + v8 - *(_QWORD *)(qword_9640 + 8);
    }
    seq_write(a1, "\nLPM stats:\n\n", 13);
    seq_printf(a1, "Count = %u\n", *(_DWORD *)(qword_9640 + 4));
    seq_printf(a1, "Last Entered At = %llu\n", *(_QWORD *)(qword_9640 + 8));
    seq_printf(a1, "Last Exited At = %llu\n", *(_QWORD *)(qword_9640 + 16));
    inited = seq_printf(a1, "Accumulated Duration = %llu\n", v8);
  }
  if ( qword_9658 )
  {
    v10 = *(_QWORD *)(qword_9658 + 24);
    if ( *(_QWORD *)(qword_9658 + 8) > *(_QWORD *)(qword_9658 + 16) )
    {
      v11 = (__int64 (__fastcall *)(__int64))arch_timer_read_counter;
      if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
        __break(0x8228u);
      v10 = v11(inited) + v10 - *(_QWORD *)(qword_9658 + 8);
    }
    seq_write(a1, "\nLPI stats:\n\n", 13);
    seq_printf(a1, "Count = %u\n", *(_DWORD *)(qword_9658 + 4));
    seq_printf(a1, "Last Entered At = %llu\n", *(_QWORD *)(qword_9658 + 8));
    seq_printf(a1, "Last Exited At = %llu\n", *(_QWORD *)(qword_9658 + 16));
    seq_printf(a1, "Accumulated Duration = %llu\n", v10);
  }
  if ( !qword_9608 )
  {
LABEL_35:
    if ( qword_9668 )
    {
      seq_write(a1, "\nQ6 load:\n\n", 11);
      __isb(0xFu);
      StatusReg = _ReadStatusReg(CNTVCT_EL0);
      v17 = *(_QWORD *)(qword_9668 + 4);
      if ( StatusReg - v17 > 0x1D96FF && StatusReg > v17 )
        v19 = 0;
      else
        v19 = *(unsigned int *)qword_9668;
      seq_printf(a1, "Average Q6 load in KCPS = %u\n", v19);
    }
    goto LABEL_43;
  }
  if ( !(unsigned int)sysmon_stats_query_power_residency(2, s) )
  {
    seq_write(a1, "\nPower Stats:\n\n", 15);
    for ( i = 0; i != 32; ++i )
    {
      v14 = &s[i];
      v15 = v14[1];
      if ( v15 )
        seq_printf(a1, "%u : Core Clock(KHz): %u \tActive Time(sec): %u\n", i, v15, v14[33]);
    }
    seq_printf(a1, "Power collapse time(sec) = %u\n", s[65]);
    seq_printf(a1, "Total LPI time(sec) = %u\n", s[66]);
    goto LABEL_35;
  }
  result = 4294967170LL;
LABEL_44:
  _ReadStatusReg(SP_EL0);
  return result;
}
