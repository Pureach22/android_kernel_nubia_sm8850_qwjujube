__int64 __fastcall msm_geni_serial_power_on(_QWORD *a1)
{
  __int64 v2; // x0
  __int64 v3; // x24
  int v4; // w20
  int v5; // w0
  unsigned int v6; // w0
  unsigned int v7; // w22
  __int64 v8; // x8
  unsigned int v9; // w9
  unsigned int v16; // w11
  unsigned int v20; // w9

  v2 = a1[43];
  if ( (*(_WORD *)(v2 + 488) & 7) != 0 )
  {
    if ( *(_DWORD *)(v2 + 500) == 2 )
    {
      v3 = a1[26];
      v4 = mutex_trylock(v3 + 272);
      ipc_log_string(a1[119], "%s:Manual resume\n", "msm_geni_serial_power_on");
      _ftrace_dbg(a1[43], "%s:Manual resume\n");
      _pm_runtime_disable(a1[43], 1);
      v5 = msm_geni_serial_runtime_resume(a1[43]);
      if ( v5 )
      {
        ipc_log_string(a1[119], "%s:Manual RPM CB failed %d\n", "msm_geni_serial_power_on", v5);
        _ftrace_dbg(a1[43], "%s:Manual RPM CB failed %d\n");
      }
      else
      {
        _X8 = (unsigned int *)(a1[43] + 480LL);
        __asm { PRFM            #0x11, [X8] }
        do
          v20 = __ldxr(_X8);
        while ( __stxr(v20 + 1, _X8) );
        _pm_runtime_set_status(a1[43], 0);
      }
      pm_runtime_enable(a1[43]);
      if ( v4 )
        mutex_unlock(v3 + 272);
    }
    return 0;
  }
  v6 = _pm_runtime_resume();
  if ( (v6 & 0x80000000) == 0 )
    return 0;
  v7 = v6;
  ipc_log_string(a1[119], "%s Err\n", "msm_geni_serial_power_on");
  _ftrace_dbg(a1[43], "%s Err\n");
  v8 = a1[43];
  v9 = *(_DWORD *)(v8 + 480);
  do
  {
    if ( !v9 )
      break;
    _X13 = (unsigned int *)(v8 + 480);
    __asm { PRFM            #0x11, [X13] }
    while ( 1 )
    {
      v16 = __ldxr(_X13);
      if ( v16 != v9 )
        break;
      if ( !__stlxr(v9 - 1, _X13) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v16 == v9;
    v9 = v16;
  }
  while ( !_ZF );
  _pm_runtime_set_status(a1[43], 2);
  return v7;
}
