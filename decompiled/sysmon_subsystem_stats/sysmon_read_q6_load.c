__int64 __fastcall sysmon_read_q6_load(int a1)
{
  unsigned __int64 StatusReg; // x8
  __int64 v2; // x9
  unsigned __int64 v3; // x10
  unsigned int v4; // w9

  __isb(0xFu);
  StatusReg = _ReadStatusReg(CNTVCT_EL0);
  switch ( a1 )
  {
    case 5:
      v2 = qword_9670;
      break;
    case 3:
      v2 = qword_9678;
      break;
    case 2:
      v2 = qword_9668;
      break;
    default:
      printk(&unk_986A, "sysmon_subsystem_stats");
      return 4294967274LL;
  }
  v3 = *(_QWORD *)(v2 + 4);
  v4 = *(_DWORD *)v2;
  if ( StatusReg - v3 > 0x1D96FF && StatusReg > v3 )
    return 0;
  else
    return v4;
}
