__int64 __fastcall sysmon_stats_query_q6_load(int a1, _DWORD *a2)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x9
  __int64 v5; // x8
  unsigned __int64 v6; // x10
  int v7; // w8

  if ( !a2 )
  {
    printk(&unk_9E79, "sysmon_subsystem_stats");
    return 4294967274LL;
  }
  if ( a1 != 5 )
  {
    if ( a1 == 3 )
    {
      if ( (byte_9602 & 1) == 0 )
        sysmon_smem_init_slpi();
      result = 4294967170LL;
      if ( qword_9678 && (unsigned __int64)qword_9678 <= 0xFFFFFFFFFFFFF000LL )
      {
        __isb(0xFu);
        StatusReg = _ReadStatusReg(CNTVCT_EL0);
        v5 = qword_9678;
        goto LABEL_20;
      }
      return result;
    }
    if ( a1 == 2 )
    {
      if ( (g_sysmon_stats & 1) == 0 )
        sysmon_smem_init_adsp();
      result = 4294967170LL;
      if ( qword_9668 && (unsigned __int64)qword_9668 <= 0xFFFFFFFFFFFFF000LL )
      {
        __isb(0xFu);
        StatusReg = _ReadStatusReg(CNTVCT_EL0);
        v5 = qword_9668;
LABEL_20:
        result = 0;
        v6 = *(_QWORD *)(v5 + 4);
        v7 = *(_DWORD *)v5;
        if ( StatusReg - v6 > 0x1D96FF && StatusReg > v6 )
          v7 = 0;
        *a2 = v7;
        return result;
      }
      return result;
    }
    printk(&unk_986A, "sysmon_subsystem_stats");
    return 4294967274LL;
  }
  if ( (byte_9601 & 1) == 0 )
    sysmon_smem_init_cdsp();
  result = 4294967170LL;
  if ( qword_9670 && (unsigned __int64)qword_9670 <= 0xFFFFFFFFFFFFF000LL )
  {
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    v5 = qword_9670;
    goto LABEL_20;
  }
  return result;
}
