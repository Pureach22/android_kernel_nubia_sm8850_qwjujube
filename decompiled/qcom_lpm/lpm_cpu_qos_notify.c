__int64 __fastcall lpm_cpu_qos_notify(__int64 a1)
{
  unsigned __int64 StatusReg; // x19
  unsigned __int64 v2; // x0
  __int64 v3; // x8

  if ( *(_DWORD *)(a1 - 12) )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v2 = *(unsigned int *)(a1 - 16);
    ++*(_DWORD *)(StatusReg + 16);
    if ( (_DWORD)v2 != *(_DWORD *)(StatusReg + 40)
      && (*((_QWORD *)&_cpu_online_mask + (v2 >> 6)) & (1LL << v2)) != 0
      && (*((_QWORD *)&_cpu_active_mask + (v2 >> 6)) & (1LL << v2)) != 0 )
    {
      v2 = wake_up_if_idle(v2);
    }
    v3 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v3;
    if ( !v3 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule(v2);
  }
  return 1;
}
