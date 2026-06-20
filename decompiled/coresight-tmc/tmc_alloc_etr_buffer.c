unsigned __int64 __fastcall tmc_alloc_etr_buffer(__int64 a1, __int64 a2, __int64 a3, int a4, char a5)
{
  __int64 v9; // x23
  __int64 v10; // x2
  __int64 v11; // x0
  unsigned __int64 v12; // x24
  __int64 v13; // x25
  unsigned int *v15; // x25
  unsigned __int64 v16; // x0
  int v17; // w8
  unsigned int v18; // w8
  unsigned __int64 v19; // x25
  unsigned __int64 v20; // x8
  unsigned int v22; // w8
  unsigned int v23; // w27
  unsigned __int64 v24; // x0
  unsigned __int64 v25; // x28
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x27
  unsigned __int64 v28; // x28
  int v29; // w27
  __int64 v30; // x8
  void (__fastcall *v31)(_QWORD); // x8
  __int64 v32; // x8
  void (__fastcall *v33)(_QWORD); // x8
  unsigned int v39; // w8

  v9 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 152LL);
  if ( *(_DWORD *)(a2 + 668) == -1 )
    v10 = 0xFFFFFFFFLL;
  else
    v10 = 0;
  v11 = _kmalloc_cache_node_noprof(arm64_use_ng_mappings, 3520, v10, 40);
  if ( !v11 )
    return 0;
  v12 = v11;
  if ( *(_DWORD *)(a2 + 668) == -1 )
  {
    v18 = *(_DWORD *)(v9 + 132);
    if ( v18 < a4 << 12 )
    {
      v16 = tmc_alloc_etr_buf(v9, (__int64)a4 << 12, 0xFFFFFFFF);
      if ( v16 < 0xFFFFFFFFFFFFF001LL )
      {
LABEL_10:
        if ( v16 >= 0xFFFFFFFFFFFFF001LL )
          goto LABEL_19;
        *(_QWORD *)v12 = v9;
        *(_QWORD *)(v12 + 8) = v16;
        if ( v12 > 0xFFFFFFFFFFFFF000LL )
          return 0;
        v17 = *(_DWORD *)(*(_QWORD *)(a2 + 688) + 1800LL);
        *(_BYTE *)(v12 + 20) = a5 & 1;
        *(_DWORD *)(v12 + 24) = a4;
        *(_DWORD *)(v12 + 16) = v17;
        *(_QWORD *)(v12 + 32) = a3;
        return v12;
      }
      v18 = *(_DWORD *)(v9 + 132);
    }
    v19 = v18;
    while ( 1 )
    {
      v16 = tmc_alloc_etr_buf(v9, v19, 0xFFFFFFFF);
      if ( v16 < 0xFFFFFFFFFFFFF001LL )
        goto LABEL_10;
      v20 = v19 >> 21;
      v19 >>= 1;
      if ( !v20 )
        goto LABEL_19;
    }
  }
  v13 = *(int *)(*(_QWORD *)(a2 + 688) + 1800LL);
  mutex_lock(v9 + 240);
  _X0 = (unsigned int *)idr_find(v9 + 216, v13);
  if ( _X0 )
  {
LABEL_49:
    __asm { PRFM            #0x11, [X0] }
    do
      v39 = __ldxr(_X0);
    while ( __stxr(v39 + 1, _X0) );
    if ( !v39 || (v15 = _X0, (((v39 + 1) | v39) & 0x80000000) != 0) )
    {
      v15 = _X0;
      refcount_warn_saturate();
    }
    mutex_unlock(v9 + 240);
    v16 = (unsigned __int64)v15;
    goto LABEL_10;
  }
  while ( 1 )
  {
    mutex_unlock(v9 + 240);
    v22 = *(_DWORD *)(v9 + 132);
    if ( *(_DWORD *)(a2 + 668) == -1 )
      v23 = -1;
    else
      v23 = 0;
    if ( a4 << 12 > v22 )
    {
      v24 = tmc_alloc_etr_buf(v9, (__int64)a4 << 12, v23);
      if ( v24 < 0xFFFFFFFFFFFFF001LL )
        goto LABEL_32;
      v22 = *(_DWORD *)(v9 + 132);
    }
    v25 = v22;
    while ( 1 )
    {
      v24 = tmc_alloc_etr_buf(v9, v25, v23);
      if ( v24 < 0xFFFFFFFFFFFFF001LL )
        break;
      v26 = v25 >> 21;
      v25 >>= 1;
      if ( !v26 )
        goto LABEL_19;
    }
LABEL_32:
    v27 = v24;
    mutex_lock(v9 + 240);
    v28 = v27;
    v29 = idr_alloc(v9 + 216, v27, (unsigned int)v13, (unsigned int)(v13 + 1), 3264);
    mutex_unlock(v9 + 240);
    if ( v29 != -28 )
      break;
    v30 = *(_QWORD *)(v28 + 48);
    if ( !v30 || (v31 = *(void (__fastcall **)(_QWORD))(v30 + 24)) == nullptr )
    {
      __break(0x800u);
      v31 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v28 + 48) + 24LL);
    }
    if ( *((_DWORD *)v31 - 1) != 1050944703 )
      __break(0x8228u);
    v31(v28);
    kfree(v28);
    mutex_lock(v9 + 240);
    _X0 = (unsigned int *)idr_find(v9 + 216, v13);
    if ( _X0 )
      goto LABEL_49;
  }
  if ( v29 != -12 )
  {
    v16 = v28;
    goto LABEL_10;
  }
  v32 = *(_QWORD *)(v28 + 48);
  if ( !v32 || (v33 = *(void (__fastcall **)(_QWORD))(v32 + 24)) == nullptr )
  {
    __break(0x800u);
    v33 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v28 + 48) + 24LL);
  }
  if ( *((_DWORD *)v33 - 1) != 1050944703 )
    __break(0x8228u);
  v33(v28);
  kfree(v28);
LABEL_19:
  kfree(v12);
  return 0;
}
