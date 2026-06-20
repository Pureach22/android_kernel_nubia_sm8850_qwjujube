__int64 __fastcall imported_mem_show(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v5; // x0
  unsigned int v7; // w9
  unsigned int v8; // w21
  unsigned int v14; // w10
  _QWORD *v15; // x21
  __int64 next; // x0
  __int64 v18; // x22
  unsigned int v19; // w8
  unsigned int v20; // w26
  unsigned int v22; // w9
  unsigned __int64 v23; // x26
  unsigned __int64 v24; // x8
  int v26; // w8
  __int64 result; // x0
  _QWORD *v28; // x22
  int v29; // [xsp+Ch] [xbp-14h] BYREF
  int v30; // [xsp+10h] [xbp-10h] BYREF
  int v31; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+18h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v5 = (_QWORD *)_kmalloc_cache_noprof(raw_read_unlock, 3520, 40);
  if ( !v5 )
  {
    result = -12;
    goto LABEL_49;
  }
  if ( !a1 )
    goto LABEL_47;
  _X8 = (unsigned int *)(a1 + 36);
  v7 = *(_DWORD *)(a1 + 36);
  if ( v7 )
  {
    do
    {
      __asm { PRFM            #0x11, [X8] }
      do
        v14 = __ldxr(_X8);
      while ( v14 == v7 && __stxr(v7 + 1, _X8) );
      v8 = v7;
      if ( v14 == v7 )
        break;
      v8 = 0;
      v7 = v14;
    }
    while ( v14 );
  }
  else
  {
    v8 = 0;
  }
  if ( (((v8 + 1) | v8) & 0x80000000) != 0 )
  {
    v28 = v5;
    refcount_warn_saturate(a1 + 36, 0);
    v5 = v28;
    if ( v8 )
      goto LABEL_14;
LABEL_47:
    kfree(v5);
    result = -2;
    goto LABEL_49;
  }
  if ( !v8 )
    goto LABEL_47;
LABEL_14:
  v5[1] = 0xFFFFFFFE00000LL;
  v15 = v5 + 1;
  *v5 = a1;
  v5[2] = v5 + 2;
  v5[3] = v5 + 2;
  v5[4] = process_private_deferred_put;
  raw_spin_lock(a1 + 32);
  next = idr_get_next(a1 + 40, &v31);
  if ( next )
  {
    _X23 = next;
    v18 = 0;
    while ( 1 )
    {
      v29 = 0;
      v30 = 0;
      if ( _X23 <= 0xFFFFFFFFFFFFF000LL )
      {
        v19 = *(_DWORD *)_X23;
        if ( *(_DWORD *)_X23 )
        {
          do
          {
            __asm { PRFM            #0x11, [X23] }
            do
              v22 = __ldxr((unsigned int *)_X23);
            while ( v22 == v19 && __stxr(v19 + 1, (unsigned int *)_X23) );
            v20 = v19;
            if ( v22 == v19 )
              break;
            v20 = 0;
            v19 = v22;
          }
          while ( v22 );
        }
        else
        {
          v20 = 0;
        }
        if ( (((v20 + 1) | v20) & 0x80000000) != 0 )
        {
          refcount_warn_saturate(_X23, 0);
          if ( v20 )
          {
LABEL_31:
            raw_spin_unlock(a1 + 32);
            if ( (*(_QWORD *)(_X23 + 80) & 0xE0LL) == 0x80 )
            {
              v23 = *(_QWORD *)(_X23 + 48);
              kgsl_get_egl_counts(_X23, &v30, &v29);
              LODWORD(v24) = v29 + v30;
              if ( (unsigned int)(v29 + v30) <= 1 )
                v24 = 1;
              else
                v24 = (unsigned int)v24;
              v18 += v23 / v24;
            }
            __asm { PRFM            #0x11, [X23] }
            do
              v26 = __ldxr((unsigned int *)_X23);
            while ( __stlxr(v26 - 1, (unsigned int *)_X23) );
            if ( v26 == 1 )
            {
              __dmb(9u);
              kgsl_mem_entry_destroy((_QWORD *)_X23);
            }
            else if ( v26 <= 0 )
            {
              refcount_warn_saturate(_X23, 3);
            }
            raw_spin_lock(a1 + 32);
          }
        }
        else if ( v20 )
        {
          goto LABEL_31;
        }
      }
      ++v31;
      _X23 = idr_get_next(a1 + 40, &v31);
      if ( !_X23 )
        goto LABEL_45;
    }
  }
  v18 = 0;
LABEL_45:
  raw_spin_unlock(a1 + 32);
  queue_work_on(32, qword_3A908, v15);
  result = (int)scnprintf(a3, 4096, "%llu\n", v18);
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
