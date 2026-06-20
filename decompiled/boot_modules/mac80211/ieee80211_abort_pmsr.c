__int64 __usercall ieee80211_abort_pmsr@<X0>(__int64 result@<X0>, __int64 a2@<X1>, __int64 a3@<X8>)
{
  __int64 v3; // x29
  int v4; // w8
  void (__fastcall *v5)(__int64, __int64); // x8
  __int64 v6; // x19
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x10
  __int64 v10; // x19
  __int64 v11; // x20
  const char *v12; // x9
  unsigned __int64 StatusReg; // x19
  __int64 v14; // x8

  if ( !result )
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      *(_QWORD *)(v3 + 24) = a2;
      _traceiter_drv_abort_pmsr(0, 1536, a3);
      a2 = *(_QWORD *)(v3 + 24);
      result = 0;
      v14 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v14;
      if ( !v14 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(0);
        result = 0;
        a2 = *(_QWORD *)(v3 + 24);
      }
    }
  }
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 1600) + 1471LL) & 1) != 0
    || (v4 = *(_DWORD *)(a2 + 1608), (v4 & 0x20) != 0)
    || (drv_abort_pmsr___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(a2 + 1608) & 0x20) == 0 )
      return result;
  }
  else
  {
    v9 = *(_QWORD *)(a2 + 1592);
    drv_abort_pmsr___already_done = 1;
    v10 = result;
    v11 = a2;
    if ( v9 )
      v12 = (const char *)(v9 + 296);
    else
      v12 = (const char *)(a2 + 1624);
    _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v12, v4);
    a2 = v11;
    result = v10;
    __break(0x800u);
    if ( (*(_BYTE *)(v11 + 1608) & 0x20) == 0 )
      return result;
  }
  v5 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(result + 2000) + 832LL);
  if ( v5 )
  {
    v6 = result;
    v7 = result + 1536;
    v8 = a2 + 4704;
    if ( *((_DWORD *)v5 - 1) != 2127142274 )
      __break(0x8228u);
    v5(v7, v8);
    return v6;
  }
  return result;
}
