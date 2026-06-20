__int64 __fastcall ieee80211_get_ringparam(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 v5; // x22
  void (__fastcall *v6)(__int64, __int64, __int64, __int64, __int64); // x8
  unsigned __int64 StatusReg; // x23
  __int64 ringparam; // x0
  __int64 v10; // x8

  v5 = **(_QWORD **)(a1 + 992);
  if ( v5 )
  {
    *(_QWORD *)(a2 + 24) = 0;
    *(_QWORD *)a2 = 0;
    *(_QWORD *)(a2 + 8) = 0;
    v2 = a2;
    *(_DWORD *)(a2 + 32) = 0;
    v3 = a2 + 32;
    *(_QWORD *)(a2 + 16) = 0;
    v4 = a2 + 16;
    mutex_lock(*(_QWORD *)(v5 + 1608));
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
      ringparam = _traceiter_drv_get_ringparam(0, 1536, v3, v4, v2 + 20, v2 + 4);
      v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v10;
      if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(ringparam);
    }
  }
  v6 = *(void (__fastcall **)(__int64, __int64, __int64, __int64, __int64))(*(_QWORD *)(v5 + 2000) + 496LL);
  if ( v6 )
  {
    if ( *((_DWORD *)v6 - 1) != 244602660 )
      __break(0x8228u);
    v6(v5 + 1536, v3, v4, v2 + 20, v2 + 4);
  }
  return mutex_unlock(*(_QWORD *)(v5 + 1608));
}
