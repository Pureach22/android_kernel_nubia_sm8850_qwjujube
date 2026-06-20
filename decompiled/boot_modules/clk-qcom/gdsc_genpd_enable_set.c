__int64 __fastcall gdsc_genpd_enable_set(__int64 a1, __int64 a2)
{
  __int64 v3; // x19
  __int64 result; // x0
  __int64 v5; // x20
  __int64 v7; // x0
  unsigned int v8; // w0
  unsigned int v9; // w20
  unsigned int v10; // w8
  unsigned int v17; // w10
  unsigned int v18; // w8
  __int64 v19; // x0

  if ( !*(_QWORD *)(a1 + 24) )
  {
    v5 = *(_QWORD *)(a1 + 16);
    v7 = _kmalloc_cache_noprof(trace_handle_return, 3520, 912);
    *(_QWORD *)(a1 + 24) = v7;
    if ( !v7 )
      return 4294967284LL;
    dev_set_name(v7, "%s:debug", *(const char **)(v5 + 1288));
    *(_QWORD *)(*(_QWORD *)(a1 + 24) + 808LL) = gdsc_debug_dev_release;
    v8 = device_register(*(_QWORD *)(a1 + 24));
    if ( v8 )
    {
      v9 = v8;
      put_device(*(_QWORD *)(a1 + 24));
    }
    else
    {
      v18 = pm_genpd_add_device(v5, *(_QWORD *)(a1 + 24));
      v19 = *(_QWORD *)(a1 + 24);
      if ( !v18 )
      {
        pm_runtime_enable(v19);
        v3 = *(_QWORD *)(a1 + 24);
        if ( a2 )
          goto LABEL_3;
LABEL_21:
        if ( *(_DWORD *)(v3 + 500) == 2 && (*(_WORD *)(v3 + 488) & 7) == 0 )
          return 0;
        return _pm_runtime_idle(v3, 4);
      }
      v9 = v18;
      device_unregister(v19);
    }
    kfree(*(_QWORD *)(a1 + 24));
    *(_QWORD *)(a1 + 24) = 0;
    return v9;
  }
  v3 = *(_QWORD *)(a1 + 24);
  if ( !a2 )
    goto LABEL_21;
LABEL_3:
  result = _pm_runtime_resume(v3, 4);
  if ( (result & 0x80000000) == 0 )
    return 0;
  v10 = *(_DWORD *)(v3 + 480);
  do
  {
    if ( !v10 )
      break;
    _X12 = (unsigned int *)(v3 + 480);
    __asm { PRFM            #0x11, [X12] }
    while ( 1 )
    {
      v17 = __ldxr(_X12);
      if ( v17 != v10 )
        break;
      if ( !__stlxr(v10 - 1, _X12) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v17 == v10;
    v10 = v17;
  }
  while ( !_ZF );
  return result;
}
