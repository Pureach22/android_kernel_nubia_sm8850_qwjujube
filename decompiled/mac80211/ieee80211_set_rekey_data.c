__int64 __fastcall ieee80211_set_rekey_data(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x29
  int v4; // w8
  void (__fastcall *v5)(__int64, __int64); // x8
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v9; // x10
  __int64 v10; // x19
  const char *v11; // x9
  __int64 v12; // x20
  unsigned __int64 StatusReg; // x19
  __int64 v14; // x8
  __int64 v15; // [xsp+48h] [xbp+38h]

  if ( !a1 )
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v15 = a2;
      *(_QWORD *)(v3 + 24) = a3;
      _traceiter_drv_set_rekey_data(0, 1536, a2 + 2688, *(_QWORD *)(v3 + 24));
      a1 = 0;
      a2 = v15;
      v14 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v14;
      if ( !v14 || !*(_QWORD *)(StatusReg + 16) )
      {
        preempt_schedule_notrace(0);
        a1 = 0;
        a2 = v15;
      }
    }
LABEL_7:
    v5 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 2000) + 168LL);
    if ( v5 )
    {
      v6 = a1 + 1536;
      v7 = a2 + 7408;
      if ( *((_DWORD *)v5 - 1) != 863566569 )
        __break(0x8228u);
      v5(v6, v7);
    }
    return 0;
  }
  if ( *(_QWORD *)(*(_QWORD *)(a1 + 2000) + 168LL) )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(a2 + 4304) + 1471LL) & 1) == 0 )
    {
      v4 = *(_DWORD *)(a2 + 4312);
      if ( (v4 & 0x20) == 0 && (drv_set_rekey_data___already_done & 1) == 0 )
      {
        v9 = *(_QWORD *)(a2 + 4296);
        drv_set_rekey_data___already_done = 1;
        v10 = a1;
        if ( v9 )
          v11 = (const char *)(v9 + 296);
        else
          v11 = (const char *)(a2 + 4328);
        v12 = a2;
        _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v11, v4);
        a2 = v12;
        a1 = v10;
        __break(0x800u);
      }
    }
    if ( (*(_BYTE *)(a2 + 4312) & 0x20) == 0 )
      return 0;
    goto LABEL_7;
  }
  return 4294967201LL;
}
