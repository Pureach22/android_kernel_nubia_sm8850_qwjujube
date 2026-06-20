__int64 __fastcall kgsl_ioctl_gpuobj_sync(__int64 a1, __int64 a2, __int64 *a3)
{
  unsigned __int64 v5; // x23
  __int64 v6; // x26
  unsigned __int64 v7; // x21
  size_t v8; // x1
  size_t v9; // x2
  __int64 v10; // x22
  __int64 v11; // x25
  int v12; // w8
  __int64 v13; // x24
  __int64 v14; // x28
  __int64 v15; // x9
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x20
  size_t v18; // x27
  __int64 v19; // x9
  unsigned __int64 v20; // x26
  unsigned __int64 v21; // x8
  size_t v23; // x8
  int v24; // w0
  unsigned int *id; // x0
  unsigned int v26; // w20
  unsigned int v27; // w8
  unsigned __int64 v28; // x9
  int v29; // w0
  __int64 v30; // x20
  int v31; // w8
  int v32; // w8
  int v33; // w25
  int v39; // w8
  unsigned __int64 StatusReg; // x20
  __int64 v41; // x21
  __int64 v42; // [xsp+8h] [xbp-8h]

  if ( (unsigned int)(*((_DWORD *)a3 + 3) - 129) < 0xFFFFFF80 )
    return -22;
  v42 = *(_QWORD *)(a1 + 8);
  v5 = 24LL * *((unsigned int *)a3 + 3);
  v6 = _kmalloc_noprof(v5, 3520);
  if ( !v6 )
    return -12;
  while ( 1 )
  {
    v7 = 8LL * *((unsigned int *)a3 + 3);
    v10 = _kmalloc_noprof(v7, 3520);
    if ( !v10 )
      break;
    if ( !*((_DWORD *)a3 + 3) )
    {
LABEL_32:
      v26 = 0;
      while ( 1 )
      {
        v27 = *((_DWORD *)a3 + 3);
        if ( v26 >= v27 )
          break;
        if ( v7 <= 8LL * (int)v26 )
          goto LABEL_61;
        v28 = 24LL * (int)v26;
        if ( v5 <= v28 || v5 <= v28 + 8 || v5 < v28 + 20 )
          goto LABEL_61;
        v29 = kgsl_gpumem_sync_cache(
                *(_QWORD *)(v10 + 8LL * (int)v26),
                *(_QWORD *)(v6 + 24LL * (int)v26),
                *(_QWORD *)(v6 + 24LL * (int)v26 + 8),
                *(_DWORD *)(v6 + 24LL * (int)v26 + 20));
        ++v26;
        if ( v29 )
        {
          v30 = v29;
          goto LABEL_47;
        }
      }
      v30 = 0;
      if ( v27 )
        goto LABEL_48;
LABEL_60:
      kfree(v10);
      goto LABEL_65;
    }
    v11 = *a3;
    v12 = 0;
    while ( 1 )
    {
      v13 = v12;
      v14 = v6;
      v15 = 3LL * v12;
      v16 = *((unsigned int *)a3 + 2);
      v17 = 8 * v15;
      v18 = v16 >= 0x18 ? 24LL : *((unsigned int *)a3 + 2);
      v19 = v16 <= 0x18 ? 24LL : *((unsigned int *)a3 + 2);
      v20 = v6 + v17;
      v9 = v19 - v18;
      if ( (unsigned int)v16 > 0x17 )
        break;
      v21 = v18 + 24LL * (int)v13;
      _CF = v5 >= v21;
      v23 = v5 - v21;
      if ( _CF )
        v8 = v23;
      else
        v8 = 0;
      if ( v8 < v9 )
        goto LABEL_62;
      memset((void *)(v20 + v18), 0, v9);
LABEL_23:
      _check_object_size(v20, v18, 0);
      if ( inline_copy_from_user_0(v20, v11, v18) )
      {
        v30 = -14;
        v6 = v14;
        goto LABEL_47;
      }
      if ( v5 <= v17 + 16 )
        goto LABEL_61;
      id = kgsl_sharedmem_find_id(v42, *(_DWORD *)(v20 + 16));
      if ( v7 <= 8 * v13 )
        goto LABEL_61;
      *(_QWORD *)(v10 + 8 * v13) = id;
      if ( id )
      {
        if ( v5 < v17 + 20 || (*(_DWORD *)(v20 + 20) & 0x80000000) != 0 && v5 <= v17 )
          goto LABEL_61;
        v11 += 24;
        v6 = v14;
      }
      else
      {
        v6 = v14;
      }
      v12 = v13 + 1;
      if ( (unsigned int)(v13 + 1) >= *((_DWORD *)a3 + 3) )
        goto LABEL_32;
    }
    if ( (_DWORD)v16 == 24 )
      goto LABEL_23;
    v24 = check_zeroed_user(v11 + v18, v19 - v18);
    if ( v24 >= 1 )
      goto LABEL_23;
    v6 = v14;
    if ( v24 )
      v31 = v24;
    else
      v31 = -7;
    v30 = v31;
LABEL_47:
    if ( !*((_DWORD *)a3 + 3) )
      goto LABEL_60;
LABEL_48:
    v32 = 0;
    while ( v7 > 8LL * v32 )
    {
      v33 = v32;
      _X0 = *(unsigned int **)(v10 + 8LL * v32);
      if ( _X0 && (unsigned __int64)_X0 <= 0xFFFFFFFFFFFFF000LL )
      {
        __asm { PRFM            #0x11, [X0] }
        do
          v39 = __ldxr(_X0);
        while ( __stlxr(v39 - 1, _X0) );
        if ( v39 == 1 )
        {
          __dmb(9u);
          kgsl_mem_entry_destroy(_X0);
        }
        else if ( v39 <= 0 )
        {
          refcount_warn_saturate(_X0, 3);
        }
      }
      v32 = v33 + 1;
      if ( (unsigned int)(v33 + 1) >= *((_DWORD *)a3 + 3) )
        goto LABEL_60;
    }
LABEL_61:
    __break(1u);
LABEL_62:
    _fortify_panic(15, v8, v9);
    StatusReg = _ReadStatusReg(SP_EL0);
    v41 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &kgsl_ioctl_gpuobj_sync__alloc_tag;
    v5 = 24LL * *((unsigned int *)a3 + 3);
    v6 = _kmalloc_noprof(v5, 3520);
    *(_QWORD *)(StatusReg + 80) = v41;
    if ( !v6 )
      return -12;
  }
  v30 = -12;
LABEL_65:
  kfree(v6);
  return v30;
}
