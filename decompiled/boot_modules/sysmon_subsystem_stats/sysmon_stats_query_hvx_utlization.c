__int64 __fastcall sysmon_stats_query_hvx_utlization(_DWORD *a1)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v4; // x10
  int v6; // w20
  int v7; // w8

  if ( (byte_9603 & 1) == 0 )
    sysmon_smem_init_cdsp();
  result = 4294967170LL;
  if ( qword_96B0 && (unsigned __int64)qword_96B0 <= 0xFFFFFFFFFFFFF000LL )
  {
    __isb(0xFu);
    StatusReg = _ReadStatusReg(CNTVCT_EL0);
    v4 = *(_QWORD *)(qword_96B0 + 4);
    if ( StatusReg - v4 > 0x1D96FF && StatusReg > v4 )
      v6 = 0;
    else
      v6 = *(_DWORD *)qword_96B0;
    v7 = v6;
    if ( v6 == 0xFFFF )
    {
      printk(&unk_98C7, "sysmon_subsystem_stats");
      v7 = 0;
    }
    *a1 = v7;
    return v6 == 0xFFFF;
  }
  return result;
}
