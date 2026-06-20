__int64 __fastcall ieee80211_set_wakeup(__int64 result, int a2)
{
  __int64 v2; // x19
  __int64 v3; // x29
  __int64 v4; // x1
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  unsigned __int64 StatusReg; // x20
  __int64 v7; // x0
  __int64 v8; // x8

  if ( result )
  {
    v2 = result;
    if ( !*(_QWORD *)(*(_QWORD *)(result + 2000) + 40LL) )
      return result;
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      *(_DWORD *)(v3 - 4) = a2;
      v7 = _traceiter_drv_set_wakeup(0, v2 + 1536, *(_DWORD *)(v3 - 4) & 1);
      a2 = *(_DWORD *)(v3 - 4);
      v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v8;
      if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(v7);
        a2 = *(_DWORD *)(v3 - 4);
      }
    }
  }
  v4 = a2 & 1;
  v5 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(v2 + 2000) + 40LL);
  if ( *((_DWORD *)v5 - 1) != 301796775 )
    __break(0x8228u);
  return v5(v2 + 1536, v4);
}
