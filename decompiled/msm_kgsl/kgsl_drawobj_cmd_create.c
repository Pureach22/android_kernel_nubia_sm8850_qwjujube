__int64 __fastcall kgsl_drawobj_cmd_create(__int64 a1, __int64 a2, int a3, char a4)
{
  __int64 result; // x0
  unsigned int v9; // w8
  unsigned int v10; // w23
  unsigned int v16; // w9
  __int64 v17; // x21
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x9
  __int64 v23; // x1
  unsigned int v26; // w9
  unsigned int v29; // w9
  unsigned int v31; // w8
  __int64 v32; // [xsp+8h] [xbp-8h]

  _X20 = a2;
  result = _kmalloc_cache_noprof(_list_del_entry_valid_or_report, 3520, 168);
  if ( !result )
    return -12;
  if ( !_X20 )
    goto LABEL_23;
  v9 = *(_DWORD *)_X20;
  if ( *(_DWORD *)_X20 )
  {
    do
    {
      __asm { PRFM            #0x11, [X20] }
      do
        v16 = __ldxr((unsigned int *)_X20);
      while ( v16 == v9 && __stxr(v9 + 1, (unsigned int *)_X20) );
      v10 = v9;
      if ( v16 == v9 )
        break;
      v10 = 0;
      v9 = v16;
    }
    while ( v16 );
  }
  else
  {
    v10 = 0;
  }
  if ( (((v10 + 1) | v10) & 0x80000000) == 0 )
  {
    if ( v10 )
      goto LABEL_14;
LABEL_23:
    kfree(result);
    return -2;
  }
  v32 = result;
  refcount_warn_saturate(_X20, 0);
  result = v32;
  if ( !v10 )
    goto LABEL_23;
LABEL_14:
  *(_DWORD *)(result + 32) = 1;
  *(_DWORD *)(result + 16) = a4 & 3;
  *(_QWORD *)(result + 40) = cmdobj_destroy;
  *(_QWORD *)(result + 48) = cmdobj_destroy_object;
  *(_QWORD *)result = a1;
  *(_QWORD *)(result + 8) = _X20;
  *(_QWORD *)(result + 24) = a3 & 0x30093B;
  *(_QWORD *)(result + 88) = result + 88;
  *(_QWORD *)(result + 96) = result + 88;
  *(_QWORD *)(result + 104) = result + 104;
  *(_QWORD *)(result + 112) = result + 104;
  *(_DWORD *)(result + 164) = 0;
  if ( (a4 & 1) != 0 )
  {
    _X8 = (unsigned int *)(*(_QWORD *)(_X20 + 24) + 496LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v26 = __ldxr(_X8);
    while ( __stxr(v26 + 1, _X8) );
    _X8 = (unsigned int *)(*(_QWORD *)(*(_QWORD *)(_X20 + 24) + 488LL) + 56LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v29 = __ldxr(_X8);
    while ( __stxr(v29 + 1, _X8) );
    v17 = result;
    raw_spin_lock(a1 + 14080);
    v18 = *(_QWORD *)(a1 + 14120);
    *(_QWORD *)(a1 + 14120) = v18 | 1;
    if ( (v18 & 1) == 0 )
    {
      v19 = mod_timer(a1 + 14040);
      *(_QWORD *)(a1 + 14128) = ktime_get(v19);
    }
    v20 = *(_QWORD *)(*(_QWORD *)(_X20 + 24) + 488LL);
    v21 = *(_QWORD *)(v20 + 48);
    *(_QWORD *)(v20 + 48) = v21 | 1;
    if ( (v21 & 1) != 0 )
      goto LABEL_21;
    _X0 = *(unsigned int **)(*(_QWORD *)(_X20 + 24) + 488LL);
    __asm { PRFM            #0x11, [X0] }
    do
      v31 = __ldxr(_X0);
    while ( __stxr(v31 + 1, _X0) );
    if ( v31 )
    {
      if ( (((v31 + 1) | v31) & 0x80000000) == 0 )
      {
LABEL_21:
        raw_spin_unlock(a1 + 14080);
        return v17;
      }
      v23 = 1;
    }
    else
    {
      v23 = 2;
    }
    refcount_warn_saturate(_X0, v23);
    goto LABEL_21;
  }
  return result;
}
