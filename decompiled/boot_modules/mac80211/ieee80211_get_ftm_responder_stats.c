__int64 __fastcall ieee80211_get_ftm_responder_stats(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 v5; // x29
  int v6; // w8
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x10
  __int64 v12; // x19
  const char *v13; // x9
  __int64 v14; // x20
  unsigned __int64 StatusReg; // x22
  unsigned __int64 v16; // x8
  __int64 ftm_responder_stats; // x0
  __int64 v18; // x8

  if ( a1 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(a2 + 4304) + 1471LL) & 1) == 0 )
    {
      v6 = *(_DWORD *)(a2 + 4312);
      if ( (v6 & 0x20) == 0 && (drv_get_ftm_responder_stats___already_done & 1) == 0 )
      {
        v11 = *(_QWORD *)(a2 + 4296);
        drv_get_ftm_responder_stats___already_done = 1;
        v12 = a1;
        if ( v11 )
          v13 = (const char *)(v11 + 296);
        else
          v13 = (const char *)(a2 + 4328);
        v14 = a2;
        _warn_printk("%s: Failed check-sdata-in-driver check, flags: 0x%x\n", v13, v6);
        a2 = v14;
        a1 = v12;
        __break(0x800u);
      }
    }
    if ( (*(_BYTE *)(a2 + 4312) & 0x20) != 0 )
    {
      v8 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 2000) + 816LL);
      if ( v8 )
      {
        v9 = a1 + 1536;
        v10 = a2 + 7408;
        if ( *((_DWORD *)v8 - 1) != 1794470179 )
          __break(0x8228u);
        return v8(v9, v10);
      }
      else
      {
        return 4294967201LL;
      }
    }
    else
    {
      return 4294967291LL;
    }
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v16 = *(unsigned int *)(StatusReg + 40);
    *(_DWORD *)(v5 - 4) = 0;
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask + ((v16 >> 3) & 0x1FFFFFF8)) >> v16) & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      ftm_responder_stats = _traceiter_drv_get_ftm_responder_stats(0, v3 + 1536, v4 + 2688, v2);
      v18 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v18;
      if ( !v18 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(ftm_responder_stats);
    }
    return *(unsigned int *)(v5 - 4);
  }
}
