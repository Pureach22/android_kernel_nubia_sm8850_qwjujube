__int64 __fastcall kgsl_sync_timeline_create(unsigned int *a1)
{
  unsigned int v1; // w8
  unsigned int v3; // w20
  unsigned int v9; // w9
  __int64 v10; // x0
  unsigned __int64 StatusReg; // x8
  _QWORD *v12; // x20
  __int64 v14; // x8
  int v16; // w8

  if ( !a1 )
    return 4294967294LL;
  v1 = *a1;
  _X19 = (__int64)a1;
  if ( *a1 )
  {
    do
    {
      __asm { PRFM            #0x11, [X19] }
      do
        v9 = __ldxr(a1);
      while ( v9 == v1 && __stxr(v1 + 1, a1) );
      v3 = v1;
      if ( v9 == v1 )
        break;
      v3 = 0;
      v1 = v9;
    }
    while ( v9 );
  }
  else
  {
    v3 = 0;
  }
  if ( (((v3 + 1) | v3) & 0x80000000) == 0 )
  {
    if ( v3 )
      goto LABEL_13;
    return 4294967294LL;
  }
  refcount_warn_saturate(a1, 0);
  if ( !v3 )
    return 4294967294LL;
LABEL_13:
  v10 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 88);
  if ( v10 )
  {
    *(_DWORD *)v10 = 1;
    StatusReg = _ReadStatusReg(SP_EL0);
    v12 = (_QWORD *)v10;
    snprintf(
      (char *)(v10 + 4),
      0x20u,
      "%s_%u-%.15s(%d)-%.15s(%d)",
      *(const char **)(*(_QWORD *)(_X19 + 40) + 8LL),
      *(_DWORD *)(_X19 + 4),
      (const char *)(*(_QWORD *)(StatusReg + 1864) + 2320LL),
      *(_DWORD *)(*(_QWORD *)(StatusReg + 1864) + 1800LL),
      (const char *)(StatusReg + 2320),
      *(_DWORD *)(StatusReg + 1800));
    v12[5] = dma_fence_context_alloc(1);
    v12[6] = v12 + 6;
    v12[7] = v12 + 6;
    v14 = *(_QWORD *)(_X19 + 40);
    v12[10] = _X19;
    *(_QWORD *)(_X19 + 56) = v12;
    v12[8] = 0;
    v12[9] = v14;
    return 0;
  }
  else
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v16 = __ldxr((unsigned int *)_X19);
    while ( __stlxr(v16 - 1, (unsigned int *)_X19) );
    if ( v16 == 1 )
    {
      __dmb(9u);
      kgsl_context_destroy(_X19);
    }
    else if ( v16 <= 0 )
    {
      refcount_warn_saturate(_X19, 3);
    }
    return 4294967284LL;
  }
}
