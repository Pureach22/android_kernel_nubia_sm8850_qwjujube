__int64 __fastcall msm_dma_resv_get_excl(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v5; // x20
  __int64 v7; // x0
  __int64 v8; // x20
  __int64 v9; // x1
  int v11; // w8
  unsigned int v18; // w8
  _QWORD v19[2]; // [xsp+0h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
    goto LABEL_24;
  v2 = *(_QWORD *)(a2 + 464);
  if ( v2 )
  {
    if ( !*(_QWORD *)(v2 + 56) )
      goto LABEL_24;
  }
  v3 = *(_QWORD *)(a1 + 24);
  v19[0] = 0;
  if ( v3 )
  {
    _X0 = (unsigned int *)(v3 + 56);
    __asm { PRFM            #0x11, [X0] }
    do
      v18 = __ldxr(_X0);
    while ( __stxr(v18 + 1, _X0) );
    if ( v18 )
    {
      if ( (((v18 + 1) | v18) & 0x80000000) == 0 )
        goto LABEL_7;
      v8 = a2;
      v9 = 1;
    }
    else
    {
      v8 = a2;
      v9 = 2;
    }
    refcount_warn_saturate(_X0, v9);
    a2 = v8;
  }
LABEL_7:
  if ( (unsigned int)dma_resv_get_singleton(*(_QWORD *)(a2 + 464), v3 == 0, v19) )
  {
    v5 = v3;
    if ( !v3 )
      goto LABEL_24;
    goto LABEL_9;
  }
  if ( v3 && v19[0] )
  {
    v7 = _kmalloc_cache_noprof(_drm_dev_dbg, 3264, 128);
    v5 = v7;
    if ( v7 )
      dma_fence_chain_init(v7, v3, v19[0], 1);
    else
      v5 = v3;
LABEL_9:
    _X0 = (unsigned int *)(v5 + 56);
    __asm { PRFM            #0x11, [X0] }
    do
      v11 = __ldxr(_X0);
    while ( __stlxr(v11 - 1, _X0) );
    if ( v11 == 1 )
    {
      __dmb(9u);
      dma_fence_release(_X0);
    }
    else if ( v11 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
    goto LABEL_24;
  }
  if ( v19[0] )
    v3 = v19[0];
  v5 = v3;
  if ( v3 )
    goto LABEL_9;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return 0;
}
