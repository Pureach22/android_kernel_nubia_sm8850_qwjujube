__int64 __fastcall i3c_geni_runtime_get_mutex_lock(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x8
  __int64 result; // x0
  int v5; // w0
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x0
  unsigned int v10; // w20
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x0
  __int64 v14; // x8
  unsigned int v15; // w9
  unsigned int v22; // w11

  v2 = a1 + 20480;
  mutex_lock(a1 + 2616);
  v3 = *(_QWORD *)(a1 + 8);
  *(_DWORD *)(a1 + 2552) = 0;
  if ( (*(_WORD *)(v3 + 488) & 7) != 0 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 2528), "PM runtime disabled\n");
    v9 = *(_QWORD *)(a1 + 8);
    if ( v9 )
      dev_err(v9, "PM runtime disabled\n");
    else
      printk(&unk_13BA4, v6, v7, v8);
    if ( *(_QWORD *)(a1 + 8) )
      i3c_trace_log();
  }
  if ( *(_BYTE *)(v2 + 1170) == 1 && *(_BYTE *)(v2 + 1161) == 1 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 2528), "%s: client controls the PM, return\n", "i3c_geni_runtime_get_mutex_lock");
    result = *(_QWORD *)(a1 + 8);
    if ( !result )
      return result;
    i3c_trace_log();
    return 0;
  }
  v5 = _pm_runtime_resume(*(_QWORD *)(a1 + 8), 4);
  if ( (v5 & 0x80000000) == 0 )
    return 0;
  v10 = v5;
  ipc_log_string(*(_QWORD *)(a1 + 2528), "error turning on SE resources:%d\n", v5);
  v13 = *(_QWORD *)(a1 + 8);
  if ( v13 )
    dev_err(v13, "error turning on SE resources:%d\n", v10);
  else
    printk(&unk_13606, v10, v11, v12);
  if ( *(_QWORD *)(a1 + 8) )
  {
    i3c_trace_log();
    v14 = *(_QWORD *)(a1 + 8);
  }
  else
  {
    v14 = 0;
  }
  v15 = *(_DWORD *)(v14 + 480);
  do
  {
    if ( !v15 )
      break;
    _X13 = (unsigned int *)(v14 + 480);
    __asm { PRFM            #0x11, [X13] }
    while ( 1 )
    {
      v22 = __ldxr(_X13);
      if ( v22 != v15 )
        break;
      if ( !__stlxr(v15 - 1, _X13) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v22 == v15;
    v15 = v22;
  }
  while ( !_ZF );
  _pm_runtime_set_status(*(_QWORD *)(a1 + 8), 2);
  mutex_unlock(a1 + 2616);
  return v10;
}
