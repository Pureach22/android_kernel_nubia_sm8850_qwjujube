__int64 __fastcall memtype_sysfs_show(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v6; // x0
  unsigned int v8; // w9
  unsigned int v9; // w22
  unsigned int v15; // w10
  _QWORD *v16; // x21
  __int64 v17; // x22
  __int64 v18; // x24
  __int64 i; // x23
  unsigned int v21; // w8
  unsigned int v22; // w28
  unsigned int v24; // w9
  unsigned int *v25; // x25
  unsigned int *v27; // x25
  int v29; // w8
  __int64 result; // x0
  _QWORD *v31; // x24
  int v32; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v33; // [xsp+8h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  v6 = (_QWORD *)_kmalloc_cache_noprof(raw_read_unlock, 3520, 40);
  if ( !v6 )
  {
    result = -12;
    goto LABEL_45;
  }
  if ( a1 == 504 )
    goto LABEL_43;
  _X8 = (unsigned int *)(a1 - 468);
  v8 = *(_DWORD *)(a1 - 468);
  if ( v8 )
  {
    do
    {
      __asm { PRFM            #0x11, [X8] }
      do
        v15 = __ldxr(_X8);
      while ( v15 == v8 && __stxr(v8 + 1, _X8) );
      v9 = v8;
      if ( v15 == v8 )
        break;
      v9 = 0;
      v8 = v15;
    }
    while ( v15 );
  }
  else
  {
    v9 = 0;
  }
  if ( (((v9 + 1) | v9) & 0x80000000) != 0 )
  {
    v31 = v6;
    refcount_warn_saturate(a1 - 468, 0);
    v6 = v31;
    if ( v9 )
      goto LABEL_14;
LABEL_43:
    kfree(v6);
    result = -2;
    goto LABEL_45;
  }
  if ( !v9 )
    goto LABEL_43;
LABEL_14:
  *v6 = a1 - 504;
  v6[1] = 0xFFFFFFFE00000LL;
  v16 = v6 + 1;
  v17 = a1 - 472;
  v6[2] = v6 + 2;
  v6[3] = v6 + 2;
  v6[4] = process_private_deferred_put;
  raw_spin_lock(a1 - 472);
  v18 = a1 - 464;
  _X0 = (unsigned int *)idr_get_next(a1 - 464, &v32);
  for ( i = 0; _X0; _X0 = (unsigned int *)idr_get_next(v18, &v32) )
  {
    if ( (unsigned __int64)_X0 <= 0xFFFFFFFFFFFFF000LL )
    {
      v21 = *_X0;
      if ( *_X0 )
      {
        do
        {
          __asm { PRFM            #0x11, [X0] }
          do
            v24 = __ldxr(_X0);
          while ( v24 == v21 && __stxr(v21 + 1, _X0) );
          v22 = v21;
          if ( v24 == v21 )
            break;
          v22 = 0;
          v21 = v24;
        }
        while ( v24 );
      }
      else
      {
        v22 = 0;
      }
      if ( (((v22 + 1) | v22) & 0x80000000) != 0 )
      {
        v27 = _X0;
        refcount_warn_saturate(_X0, 0);
        _X0 = v27;
        if ( v22 )
        {
LABEL_31:
          v25 = _X0;
          raw_spin_unlock(v17);
          _X0 = v25;
          if ( *((unsigned __int8 *)v25 + 81) == *(_DWORD *)(a2 - 8) )
            i += *((_QWORD *)v25 + 6);
          __asm { PRFM            #0x11, [X0] }
          do
            v29 = __ldxr(v25);
          while ( __stlxr(v29 - 1, v25) );
          if ( v29 == 1 )
          {
            __dmb(9u);
            kgsl_mem_entry_destroy(v25);
          }
          else if ( v29 <= 0 )
          {
            refcount_warn_saturate(v25, 3);
          }
          raw_spin_lock(v17);
        }
      }
      else if ( v22 )
      {
        goto LABEL_31;
      }
    }
    ++v32;
  }
  raw_spin_unlock(v17);
  queue_work_on(32, qword_3A908, v16);
  result = (int)scnprintf(a3, 4096, "%llu\n", i);
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
