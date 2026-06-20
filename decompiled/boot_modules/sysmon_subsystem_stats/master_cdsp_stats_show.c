__int64 __fastcall master_cdsp_stats_show(__int64 a1)
{
  __int64 inited; // x0
  __int64 v3; // x20
  int v4; // w22
  unsigned int v5; // w8
  __int64 v6; // x2
  int v7; // w8
  const char *v8; // x2
  unsigned int v9; // w8
  __int64 v10; // x2
  __int64 v11; // x20
  __int64 (__fastcall *v12)(__int64); // x8
  __int64 result; // x0
  __int64 i; // x20
  _DWORD *v15; // x8
  int v16; // w3
  unsigned __int64 v17; // x20
  int v18; // w2
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v20; // x10
  __int64 v22; // x2
  unsigned int v23; // w0
  unsigned int v24; // w0
  unsigned int v25; // [xsp+4h] [xbp-2ACh] BYREF
  unsigned int v26; // [xsp+8h] [xbp-2A8h] BYREF
  _DWORD v27[67]; // [xsp+Ch] [xbp-2A4h] BYREF
  _DWORD s[100]; // [xsp+118h] [xbp-198h] BYREF
  __int64 v29; // [xsp+2A8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v26 = 0;
  memset(s, 0, sizeof(s));
  inited = (__int64)memset(v27, 0, sizeof(v27));
  if ( (byte_9601 & 1) != 0 )
  {
    if ( !byte_9601 )
      goto LABEL_60;
  }
  else
  {
    inited = sysmon_smem_init_cdsp();
    if ( (byte_9601 & 1) == 0 )
    {
LABEL_60:
      result = 0;
      goto LABEL_61;
    }
  }
  v3 = qword_9628;
  if ( qword_9628 )
  {
    v4 = *(_DWORD *)qword_9628;
    seq_write(a1, "\nsysMon stats:\n\n", 16);
    seq_printf(a1, "Core clock(KHz): %d\n", *(_DWORD *)(v3 + 4));
    seq_printf(a1, "Ab vote(Bytes): %llu\n", *(_QWORD *)(v3 + 8));
    seq_printf(a1, "Ib vote(Bytes): %llu\n", *(_QWORD *)(v3 + 16));
    v5 = *(_DWORD *)(v3 + 24);
    if ( v5 )
      v6 = v5;
    else
      v6 = 0xFFFFFFFFLL;
    inited = seq_printf(a1, "Sleep latency(usec): %u\n", v6);
    if ( (v4 & 0xFE) != 0 )
    {
      v7 = *(_DWORD *)(v3 + 36);
      if ( (v7 & 0x80000000) == 0 )
      {
        if ( v7 )
          v8 = "ON";
        else
          v8 = (const char *)&unk_9845;
        seq_printf(a1, "HMX Power state: %s\n", v8);
        inited = seq_printf(a1, "HMX Clock(KHz): %d\n", *(_DWORD *)(v3 + 40));
      }
    }
  }
  else
  {
    LOBYTE(v4) = 0;
  }
  if ( qword_9688 )
  {
    seq_write(a1, "\nDSPPM stats:\n\n", 15);
    seq_printf(a1, "Version: %u\n", *(_DWORD *)qword_9688);
    v9 = *(_DWORD *)(qword_9688 + 4);
    if ( v9 )
      v10 = v9;
    else
      v10 = 0xFFFFFFFFLL;
    seq_printf(a1, "Sleep latency(usec): %u\n", v10);
    seq_printf(a1, "Timestamp: %u\n", *(_DWORD *)(qword_9688 + 8));
    seq_printf(a1, "Pid: %d, Num active clients: %d\n", *(_DWORD *)(qword_9688 + 12), *(_DWORD *)(qword_9688 + 16));
    seq_printf(a1, "Pid: %d, Num active clients: %d\n", *(_DWORD *)(qword_9688 + 20), *(_DWORD *)(qword_9688 + 24));
    seq_printf(a1, "Pid: %d, Num active clients: %d\n", *(_DWORD *)(qword_9688 + 28), *(_DWORD *)(qword_9688 + 32));
    seq_printf(a1, "Pid: %d, Num active clients: %d\n", *(_DWORD *)(qword_9688 + 36), *(_DWORD *)(qword_9688 + 40));
    inited = seq_printf(
               a1,
               "Pid: %d, Num active clients: %d\n",
               *(_DWORD *)(qword_9688 + 44),
               *(_DWORD *)(qword_9688 + 48));
  }
  if ( qword_9648 )
  {
    v11 = *(_QWORD *)(qword_9648 + 24);
    if ( *(_QWORD *)(qword_9648 + 8) > *(_QWORD *)(qword_9648 + 16) )
    {
      v12 = (__int64 (__fastcall *)(__int64))arch_timer_read_counter;
      if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
        __break(0x8228u);
      v11 = v12(inited) + v11 - *(_QWORD *)(qword_9648 + 8);
    }
    seq_write(a1, "\nLPM stats:\n\n", 13);
    seq_printf(a1, "Count = %u\n", *(_DWORD *)(qword_9648 + 4));
    seq_printf(a1, "Last Entered At = %llu\n", *(_QWORD *)(qword_9648 + 8));
    seq_printf(a1, "Last Exited At = %llu\n", *(_QWORD *)(qword_9648 + 16));
    seq_printf(a1, "Accumulated Duration = %llu\n", v11);
  }
  if ( !qword_9610 )
  {
LABEL_36:
    if ( qword_9638 )
    {
      seq_write(a1, "\nDDR stats :\n", 13);
      if ( (unsigned int)((__int64 (__fastcall *)(_DWORD *))sysmon_stats_query_ddr_residency)(v27) )
      {
        seq_write(a1, "DDR Stats Query API failed\n", 27);
        result = 4294967170LL;
        goto LABEL_61;
      }
      if ( v27[64] )
      {
        v17 = 0;
        do
        {
          if ( v17 == 32 )
            __break(0x5512u);
          seq_printf(a1, "%u : DDR Clock(KHz) : %u \tActive Time(sec) : %u\n", v17, v27[v17], v27[v17 + 32]);
          v18 = v27[64];
          ++v17;
        }
        while ( v17 < v27[64] );
      }
      else
      {
        v18 = 0;
      }
      seq_printf(a1, "Number of DDR clock levels = %u\n", v18);
      seq_printf(a1, "Power collapse time(sec) = %u\n", v27[65]);
      seq_printf(a1, "Current DDR clock(KHz) = %u\n", v27[66]);
    }
    if ( qword_9670 )
    {
      seq_write(a1, "\nQ6 load:\n\n", 11);
      __isb(0xFu);
      StatusReg = _ReadStatusReg(CNTVCT_EL0);
      v20 = *(_QWORD *)(qword_9670 + 4);
      if ( StatusReg - v20 > 0x1D96FF && StatusReg > v20 )
        v22 = 0;
      else
        v22 = *(unsigned int *)qword_9670;
      seq_printf(a1, "Average Q6 load in KCPS = %u\n", v22);
    }
    v23 = sysmon_stats_query_hmx_utlization(&v26);
    if ( v23 )
    {
      seq_printf(a1, "\nHMX stats not available, error code: %d\n", v23);
    }
    else
    {
      seq_write(a1, "\nHMX stats:\n\n", 13);
      seq_printf(a1, "HMX utilization in percentage = %u\n", v26);
    }
    v24 = sysmon_stats_query_hvx_utlization(&v25);
    if ( v24 )
    {
      seq_printf(a1, "\nHVX stats not available, error code: %d\n", v24);
    }
    else
    {
      seq_write(a1, "\nHVX Stats:\n\n", 13);
      seq_printf(a1, "HVX utilization in percentage = %u\n", v25);
    }
    goto LABEL_60;
  }
  if ( !(unsigned int)sysmon_stats_query_power_residency(5, s) )
  {
    seq_write(a1, "\nPower Stats:\n\n", 15);
    for ( i = 0; i != 32; ++i )
    {
      v15 = &s[i];
      v16 = v15[1];
      if ( v16 )
        seq_printf(a1, "%u : Core Clock(KHz) : %u \tActive Time(sec) : %u\n", i, v16, v15[33]);
    }
    seq_printf(a1, "Power collapse time(sec) = %u\n", s[65]);
    seq_printf(a1, "Total LPI time(sec) = %u\n", s[66]);
    if ( (v4 & 0xFE) != 0 )
      seq_printf(a1, "Current core clock(KHz) = %u\n", s[99]);
    goto LABEL_36;
  }
  result = 4294967170LL;
LABEL_61:
  _ReadStatusReg(SP_EL0);
  return result;
}
