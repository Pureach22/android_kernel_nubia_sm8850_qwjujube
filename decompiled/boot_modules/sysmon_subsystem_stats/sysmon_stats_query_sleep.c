__int64 __fastcall sysmon_stats_query_sleep(__int64 inited, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned int v5; // w21
  __int64 (__fastcall *v6)(__int64); // x8
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x11
  __int64 result; // x0
  __int64 (__fastcall *v11)(__int64); // x8
  __int64 v12; // x9
  __int64 v13; // x8
  __int64 v14; // x11
  __int64 (__fastcall *v15)(__int64); // x8
  __int64 v16; // x9
  __int64 v17; // x8
  __int64 v18; // x11
  __int64 (__fastcall *v19)(__int64); // x8
  __int64 *v20; // x8
  __int64 (__fastcall *v21)(__int64); // x8
  __int64 v22; // x9
  __int64 v23; // x10
  __int64 v24; // x8
  __int64 v25; // x11

  if ( !(a2 | a3) )
  {
    printk(&unk_9E79, "sysmon_subsystem_stats");
    return 4294967274LL;
  }
  if ( (_DWORD)inited == 5 )
  {
    if ( (byte_9601 & 1) == 0 )
      sysmon_smem_init_cdsp();
    if ( !a2 )
      return 0;
    result = 4294967170LL;
    if ( qword_9648 && (unsigned __int64)qword_9648 <= 0xFFFFFFFFFFFFF000LL )
    {
      if ( *(_QWORD *)(qword_9648 + 8) > *(_QWORD *)(qword_9648 + 16) )
      {
        v11 = (__int64 (__fastcall *)(__int64))arch_timer_read_counter;
        if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
          __break(0x8228u);
        *(_QWORD *)(qword_9648 + 24) += v11(4294967170LL) - *(_QWORD *)(qword_9648 + 8);
      }
      v12 = *(_QWORD *)(qword_9648 + 24);
      v14 = *(_QWORD *)qword_9648;
      v13 = *(_QWORD *)(qword_9648 + 8);
      *(_QWORD *)(a2 + 16) = *(_QWORD *)(qword_9648 + 16);
      *(_QWORD *)(a2 + 24) = v12;
      *(_QWORD *)a2 = v14;
      *(_QWORD *)(a2 + 8) = v13;
      return 0;
    }
    return result;
  }
  if ( (_DWORD)inited != 3 )
  {
    if ( (_DWORD)inited == 2 )
    {
      if ( (g_sysmon_stats & 1) == 0 )
        inited = sysmon_smem_init_adsp();
      if ( a2 )
      {
        v5 = -126;
        if ( qword_9640 && (unsigned __int64)qword_9640 <= 0xFFFFFFFFFFFFF000LL )
        {
          if ( *(_QWORD *)(qword_9640 + 8) > *(_QWORD *)(qword_9640 + 16) )
          {
            v6 = (__int64 (__fastcall *)(__int64))arch_timer_read_counter;
            if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
              __break(0x8228u);
            *(_QWORD *)(qword_9640 + 24) += v6(inited) - *(_QWORD *)(qword_9640 + 8);
          }
          v5 = 0;
          v7 = *(_QWORD *)(qword_9640 + 24);
          v9 = *(_QWORD *)qword_9640;
          v8 = *(_QWORD *)(qword_9640 + 8);
          *(_QWORD *)(a2 + 16) = *(_QWORD *)(qword_9640 + 16);
          *(_QWORD *)(a2 + 24) = v7;
          *(_QWORD *)a2 = v9;
          *(_QWORD *)(a2 + 8) = v8;
        }
        if ( !a3 )
          return v5;
LABEL_40:
        result = 4294967170LL;
        if ( qword_9658 && (unsigned __int64)qword_9658 <= 0xFFFFFFFFFFFFF000LL )
        {
          if ( *(_QWORD *)(qword_9658 + 8) > *(_QWORD *)(qword_9658 + 16) )
          {
            v19 = (__int64 (__fastcall *)(__int64))arch_timer_read_counter;
            if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
              __break(0x8228u);
            *(_QWORD *)(qword_9658 + 24) += v19(4294967170LL) - *(_QWORD *)(qword_9658 + 8);
          }
          v20 = (__int64 *)qword_9658;
LABEL_56:
          v23 = v20[2];
          v22 = v20[3];
          v25 = *v20;
          v24 = v20[1];
          *(_QWORD *)(a3 + 16) = v23;
          *(_QWORD *)(a3 + 24) = v22;
          *(_QWORD *)a3 = v25;
          *(_QWORD *)(a3 + 8) = v24;
          return v5;
        }
        return result;
      }
      v5 = 0;
      if ( a3 )
        goto LABEL_40;
      return v5;
    }
    printk(&unk_986A, "sysmon_subsystem_stats");
    return 4294967274LL;
  }
  if ( (byte_9602 & 1) == 0 )
    inited = sysmon_smem_init_slpi();
  if ( a2 )
  {
    v5 = -126;
    if ( qword_9650 && (unsigned __int64)qword_9650 <= 0xFFFFFFFFFFFFF000LL )
    {
      if ( *(_QWORD *)(qword_9650 + 8) > *(_QWORD *)(qword_9650 + 16) )
      {
        v15 = (__int64 (__fastcall *)(__int64))arch_timer_read_counter;
        if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
          __break(0x8228u);
        *(_QWORD *)(qword_9650 + 24) += v15(inited) - *(_QWORD *)(qword_9650 + 8);
      }
      v5 = 0;
      v16 = *(_QWORD *)(qword_9650 + 24);
      v18 = *(_QWORD *)qword_9650;
      v17 = *(_QWORD *)(qword_9650 + 8);
      *(_QWORD *)(a2 + 16) = *(_QWORD *)(qword_9650 + 16);
      *(_QWORD *)(a2 + 24) = v16;
      *(_QWORD *)a2 = v18;
      *(_QWORD *)(a2 + 8) = v17;
    }
    if ( !a3 )
      return v5;
  }
  else
  {
    v5 = 0;
    if ( !a3 )
      return v5;
  }
  result = 4294967170LL;
  if ( qword_9660 && (unsigned __int64)qword_9660 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( *(_QWORD *)(qword_9660 + 8) > *(_QWORD *)(qword_9660 + 16) )
    {
      v21 = (__int64 (__fastcall *)(__int64))arch_timer_read_counter;
      if ( *(_DWORD *)(arch_timer_read_counter - 4LL) != -1073338243 )
        __break(0x8228u);
      *(_QWORD *)(qword_9660 + 24) += v21(4294967170LL) - *(_QWORD *)(qword_9660 + 8);
    }
    v20 = (__int64 *)qword_9660;
    goto LABEL_56;
  }
  return result;
}
