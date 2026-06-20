__int64 __fastcall kgsl_ioctl_gpumem_sync_cache_bulk(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 v5; // x23
  unsigned __int64 v6; // x24
  __int64 v7; // x20
  unsigned __int64 v8; // x22
  __int64 v9; // x21
  __int64 v10; // x8
  size_t v11; // x25
  __int64 v12; // x26
  __int64 v13; // x22
  int v14; // w8
  unsigned int v15; // w28
  unsigned int v16; // w26
  int v17; // w27
  unsigned int v18; // w25
  int v25; // w8
  int v26; // w8
  __int64 v27; // x25
  int v30; // w8
  unsigned __int64 StatusReg; // x21
  __int64 v32; // x22

  if ( !*a3 || (unsigned int)(*((_DWORD *)a3 + 2) - 1025) < 0xFFFFFC00 )
    return -22;
  v5 = *(_QWORD *)(a1 + 8);
  v6 = 4LL * *((unsigned int *)a3 + 2);
  v7 = _kmalloc_noprof(v6, 3520);
  if ( !v7 )
    return -12;
  while ( 1 )
  {
    v8 = 8LL * *((unsigned int *)a3 + 2);
    v9 = _kmalloc_noprof(v8, 3520);
    if ( !v9 )
      break;
    v10 = *((unsigned int *)a3 + 2);
    if ( (unsigned int)v10 >> 29 )
    {
      __break(0x800u);
      v13 = -14;
      goto LABEL_43;
    }
    v11 = 4 * v10;
    v12 = *a3;
    _check_object_size(v7, 4 * v10, 0);
    if ( inline_copy_from_user_0(v7, v12, v11) )
    {
      v13 = -14;
      goto LABEL_43;
    }
    sort(v7, *((unsigned int *)a3 + 2), 4, mem_id_cmp, 0);
    if ( !*((_DWORD *)a3 + 2) )
    {
      v13 = 0;
      *((_DWORD *)a3 + 3) &= ~0x80000000;
      goto LABEL_43;
    }
    v14 = 0;
    v15 = 0;
    v16 = 0;
    while ( v6 > 4LL * v14 )
    {
      v17 = v14;
      v18 = *(_DWORD *)(v7 + 4LL * v14);
      if ( v18 != v15 )
      {
        _X0 = kgsl_sharedmem_find_id(v5, v18);
        if ( _X0 )
        {
          if ( ((_X0[20] >> 26) | 0xFFFFFFFC) > 0xFFFFFFFD )
          {
            if ( v8 <= 8 * (unsigned __int64)v16 )
              break;
            *(_QWORD *)(v9 + 8LL * v16++) = _X0;
            v15 = v18;
          }
          else if ( (unsigned __int64)_X0 <= 0xFFFFFFFFFFFFF000LL )
          {
            __asm { PRFM            #0x11, [X0] }
            do
              v25 = __ldxr(_X0);
            while ( __stlxr(v25 - 1, _X0) );
            if ( v25 == 1 )
            {
              __dmb(9u);
              kgsl_mem_entry_destroy(_X0);
            }
            else if ( v25 <= 0 )
            {
              refcount_warn_saturate(_X0, 3);
            }
          }
        }
      }
      v14 = v17 + 1;
      if ( (unsigned int)(v17 + 1) >= *((_DWORD *)a3 + 2) )
      {
        *((_DWORD *)a3 + 3) &= ~0x80000000;
        if ( !v16 )
        {
LABEL_37:
          v13 = 0;
          goto LABEL_43;
        }
        v26 = 0;
        v5 = 0xFFFFFFFFLL;
        while ( v8 > 8LL * v26 )
        {
          v27 = v26;
          kgsl_gpumem_sync_cache(
            *(_QWORD *)(v9 + 8LL * v26),
            0,
            *(_QWORD *)(*(_QWORD *)(v9 + 8LL * v26) + 48LL),
            *((_DWORD *)a3 + 3));
          _X0 = *(unsigned int **)(v9 + 8 * v27);
          if ( _X0 && (unsigned __int64)_X0 <= 0xFFFFFFFFFFFFF000LL )
          {
            __asm { PRFM            #0x11, [X0] }
            do
              v30 = __ldxr(_X0);
            while ( __stlxr(v30 - 1, _X0) );
            if ( v30 == 1 )
            {
              __dmb(9u);
              kgsl_mem_entry_destroy(_X0);
            }
            else if ( v30 <= 0 )
            {
              refcount_warn_saturate(_X0, 3);
            }
          }
          v26 = v27 + 1;
          if ( v16 == (_DWORD)v27 + 1 )
            goto LABEL_37;
        }
        break;
      }
    }
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v32 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &kgsl_ioctl_gpumem_sync_cache_bulk__alloc_tag;
    v6 = 4LL * *((unsigned int *)a3 + 2);
    v7 = _kmalloc_noprof(v6, 3520);
    *(_QWORD *)(StatusReg + 80) = v32;
    if ( !v7 )
      return -12;
  }
  v13 = -12;
LABEL_43:
  kfree(v9);
  kfree(v7);
  return v13;
}
