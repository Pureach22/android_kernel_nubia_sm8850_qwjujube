__int64 __usercall ieee80211_start_pmsr@<X0>(__int64 a1@<X0>, __int64 a2@<X1>, __int64 a3@<X8>)
{
  __int64 v3; // x29
  int v4; // w8
  __int64 v6; // x10
  __int64 v7; // x19
  __int64 v8; // x20
  const char *v9; // x9
  __int64 (__fastcall *v10)(__int64, __int64); // x8
  __int64 v11; // x0
  __int64 v12; // x1
  unsigned __int64 StatusReg; // x19
  __int64 v14; // x8

  if ( a1 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(a2 + 1600) + 1471LL) & 1) != 0
      || (v4 = *(_DWORD *)(a2 + 1608), (v4 & 0x20) != 0)
      || (drv_start_pmsr___already_done & 1) != 0 )
    {
      if ( (*(_BYTE *)(a2 + 1608) & 0x20) == 0 )
        return 4294967291LL;
    }
    else
    {
      v6 = *(_QWORD *)(a2 + 1592);
      drv_start_pmsr___already_done = 1;
      v7 = a1;
      v8 = a2;
      if ( v6 )
        v9 = (const char *)(v6 + 296);
      else
        v9 = (const char *)(a2 + 1624);
      _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v9, v4);
      a2 = v8;
      a1 = v7;
      __break(0x800u);
      if ( (*(_BYTE *)(v8 + 1608) & 0x20) == 0 )
        return 4294967291LL;
    }
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
      *(_QWORD *)(v3 + 24) = a2;
      _traceiter_drv_start_pmsr(0, 1536, a3);
      a2 = *(_QWORD *)(v3 + 24);
      a1 = 0;
      v14 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v14;
      if ( !v14 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(0);
        a2 = *(_QWORD *)(v3 + 24);
        a1 = 0;
      }
    }
  }
  v10 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 2000) + 824LL);
  if ( !v10 )
    return 4294967201LL;
  v11 = a1 + 1536;
  v12 = a2 + 4704;
  if ( *((_DWORD *)v10 - 1) != -955556555 )
    __break(0x8228u);
  return v10(v11, v12);
}
