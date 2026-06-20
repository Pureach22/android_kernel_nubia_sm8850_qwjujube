_BYTE *__fastcall icnss_pdr_notifier_cb(_BYTE *result, __int64 a2, __int64 a3)
{
  int v3; // w20
  char v5; // w8
  _BYTE *v6; // x20
  __int64 v7; // x8
  unsigned __int64 v14; // x10
  unsigned __int64 v17; // x9
  const char *v18; // x21
  unsigned __int64 v21; // x10
  unsigned __int64 v24; // x9
  unsigned __int64 v27; // x10
  _BYTE v28[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28[0] = 0;
  if ( a3 )
  {
    v3 = (int)result;
    result = (_BYTE *)ipc_log_string(
                        icnss_ipc_log_context,
                        "icnss2: PD service notification: 0x%x state: 0x%lx\n",
                        (_DWORD)result,
                        *(_QWORD *)(a3 + 1832));
    if ( v3 == 0x1FFFFFFF )
    {
      _X8 = (unsigned __int64 *)(a3 + 1832);
      __asm { PRFM            #0x11, [X8] }
      do
        v14 = __ldxr(_X8);
      while ( __stxr(v14 & 0xFFFFFFFFFFFFDFFFLL, _X8) );
    }
    else if ( v3 == 0xFFFFFFF )
    {
      result = (_BYTE *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 2);
      if ( result )
      {
        v5 = *(_BYTE *)(a3 + 3250);
        v6 = result;
        *result = 1;
        if ( (v5 & 1) != 0 )
        {
          if ( *(_BYTE *)(a3 + 5680) == 1 )
          {
            v7 = 2;
            *result = 0;
          }
          else
          {
            v7 = 1;
          }
        }
        else
        {
          _X8 = (unsigned __int64 *)(penv + 1832);
          __asm { PRFM            #0x11, [X8] }
          do
            v17 = __ldxr(_X8);
          while ( __stxr(v17 | 0x40000, _X8) );
          if ( (*(_QWORD *)(a3 + 1832) & 0x1000) != 0 )
          {
            ++*(_DWORD *)(a3 + 2512);
            v7 = 3;
          }
          else
          {
            v7 = 0;
            ++*(_DWORD *)(a3 + 2508);
          }
        }
        v18 = icnss_pdr_cause[v7];
        printk("%sicnss2: PD service down, state: 0x%lx: cause: %s\n", byte_13289B, *(_QWORD *)(a3 + 1832), v18);
        ipc_log_string(
          icnss_ipc_log_context,
          "%sicnss2: PD service down, state: 0x%lx: cause: %s\n",
          (const char *)&unk_12DBF3,
          *(_QWORD *)(a3 + 1832),
          v18);
        if ( (*(_QWORD *)(a3 + 1832) & 0x2000) == 0 )
        {
          _X8 = (unsigned __int64 *)(a3 + 1832);
          __asm { PRFM            #0x11, [X8] }
          do
            v24 = __ldxr(_X8);
          while ( __stxr(v24 | 0x2000, _X8) );
          icnss_ignore_fw_timeout(1);
          if ( (*(_QWORD *)(a3 + 1832) & 4) != 0 )
          {
            _X8 = (unsigned __int64 *)(a3 + 1832);
            __asm { PRFM            #0x11, [X8] }
            do
              v27 = __ldxr(_X8);
            while ( __stxr(v27 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
            v28[0] = *v6;
            icnss_call_driver_uevent((_QWORD *)a3, 1, (__int64)v28);
          }
        }
        _X8 = (unsigned __int64 *)(a3 + 1832);
        __asm { PRFM            #0x11, [X8] }
        do
          v21 = __ldxr(_X8);
        while ( __stxr(v21 & 0xFFFFFFFFFFFFEFFFLL, _X8) );
        if ( *v6 == 1 )
          mod_timer(a3 + 6016, jiffies + 15000LL);
        result = (_BYTE *)icnss_driver_event_post(a3, 5u, 1, (__int64)v6);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
