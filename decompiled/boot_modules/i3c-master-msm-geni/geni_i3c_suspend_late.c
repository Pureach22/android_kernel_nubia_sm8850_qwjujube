__int64 __fastcall geni_i3c_suspend_late(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x22
  unsigned __int64 v4; // x20
  int v5; // w8
  __int64 v6; // x0
  __int64 result; // x0
  unsigned int v8; // w8
  unsigned int v15; // w10
  __int64 v16; // x21
  __int64 v17; // x0
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x0

  v1 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD *)(v1 + 2536);
  if ( v3 )
  {
    if ( *(_DWORD *)(v1 + 2544) )
    {
      v4 = sched_clock(a1);
      ipc_log_string(v3, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_suspend_late", v4, v4 / 0x3E8);
    }
    else
    {
      v4 = 0;
    }
  }
  else
  {
    v4 = -22;
  }
  if ( *(_BYTE *)(v1 + 21460) == 1 && *(_BYTE *)(v1 + 21461) == 1 && (unsigned int)geni_i3c_enable_naon_ibi_clks(v1, 0) )
  {
    ipc_log_string(*(_QWORD *)(v1 + 2528), "%s:  NAON clock failure\n", "geni_i3c_suspend_late");
    v20 = *(_QWORD *)(v1 + 8);
    if ( v20 )
      dev_err(v20, "%s:  NAON clock failure\n", "geni_i3c_suspend_late");
    else
      printk(&unk_13A7A, "geni_i3c_suspend_late", v18, v19);
    if ( *(_QWORD *)(v1 + 8) )
      i3c_trace_log();
    return 4294967285LL;
  }
  else
  {
    v5 = *(_DWORD *)(a1 + 500);
    if ( *(_BYTE *)(v1 + 21641) != 1 )
    {
      if ( v5 != 2 )
      {
        ipc_log_string(*(_QWORD *)(v1 + 2528), "%s: Forced suspend\n", "geni_i3c_suspend_late");
        if ( *(_QWORD *)(v1 + 8) )
          i3c_trace_log();
        geni_i3c_runtime_suspend(a1);
        _pm_runtime_disable(a1, 1);
        v8 = *(_DWORD *)(a1 + 480);
        do
        {
          if ( !v8 )
            break;
          _X12 = (unsigned int *)(a1 + 480);
          __asm { PRFM            #0x11, [X12] }
          while ( 1 )
          {
            v15 = __ldxr(_X12);
            if ( v15 != v8 )
              break;
            if ( !__stlxr(v8 - 1, _X12) )
            {
              __dmb(0xBu);
              break;
            }
          }
          _ZF = v15 == v8;
          v8 = v15;
        }
        while ( !_ZF );
        _pm_runtime_set_status(a1, 2);
        pm_runtime_enable(a1);
      }
      v16 = *(_QWORD *)(v1 + 2536);
      if ( v16 )
      {
        result = 0;
        if ( !v4 || !*(_DWORD *)(v1 + 2544) )
          return result;
        v17 = sched_clock(0);
        ipc_log_string(v16, "%s:took %llu nsec(%llu usec)\n", "geni_i3c_suspend_late", v17 - v4, (v17 - v4) / 0x3E8);
      }
      return 0;
    }
    v6 = *(_QWORD *)(v1 + 2528);
    if ( v5 == 2 )
    {
      ipc_log_string(v6, "%s: Do not allow system suspend when PM runtime is not suspended\n", "geni_i3c_suspend_late");
      result = *(_QWORD *)(v1 + 8);
      if ( !result )
        return result;
      i3c_trace_log();
      return 0;
    }
    ipc_log_string(v6, ":%s: Wait for pm client to call put_sync\n", "geni_i3c_suspend_late");
    if ( *(_QWORD *)(v1 + 8) )
      i3c_trace_log();
    return 4294967280LL;
  }
}
