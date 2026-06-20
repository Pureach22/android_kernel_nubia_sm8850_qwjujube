__int64 synx_dma_fence_util_init()
{
  unsigned __int64 v0; // x0
  __int64 v1; // x4
  __int64 v2; // x5
  _DWORD *v3; // x20
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x21
  unsigned __int64 v6; // x19
  __int64 v7; // x4
  __int64 v8; // x5
  unsigned __int64 v9; // x20
  unsigned __int64 v10; // x0
  unsigned int v11; // w0
  __int64 v12; // x5
  unsigned int v13; // w21
  unsigned __int64 v14; // x9
  __int64 v17; // x3
  unsigned __int64 v24; // x4
  int v27; // w8
  int v29; // w8

  v0 = _kmalloc_cache_noprof(alt_cb_patch_nops, 3520, 4);
  v3 = (_DWORD *)v0;
  if ( !v0 || v0 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (synx_debug & 1) == 0 )
      return -12;
    v17 = 377;
LABEL_24:
    printk(&unk_2B2C1, &unk_29207, "synx_dma_fence_util_init", v17, v1, v2);
    return -12;
  }
  v4 = _kmalloc_cache_noprof(raw_spin_lock_bh, 3520, 64);
  if ( !v4 || v4 >= 0xFFFFFFFFFFFFF001LL )
  {
    kfree(v3);
    if ( (synx_debug & 1) == 0 )
      return -12;
    v17 = 384;
    goto LABEL_24;
  }
  *v3 = 0;
  _X8 = &test_dma_seq_counter;
  __asm { PRFM            #0x11, [X8] }
  do
    v24 = __ldxr((unsigned __int64 *)&test_dma_seq_counter);
  while ( __stlxr(v24 + 1, (unsigned __int64 *)&test_dma_seq_counter) );
  __dmb(0xBu);
  v5 = v4;
  dma_fence_init();
  v6 = v5;
  dma_fence_enable_sw_signaling(v5);
  v9 = _kmalloc_cache_noprof(raw_spin_unlock_bh, 3520, 24);
  v10 = v5;
  if ( !v9 || v9 >= 0xFFFFFFFFFFFFF001LL )
  {
    if ( (synx_debug & 1) != 0 )
    {
      printk(&unk_2B2C1, &unk_29207, "synx_dma_fence_util_init", 397, v7, v8);
      v10 = v5;
    }
    _X0 = (unsigned int *)(v10 + 56);
    __asm { PRFM            #0x11, [X0] }
    do
      v27 = __ldxr(_X0);
    while ( __stlxr(v27 - 1, _X0) );
    if ( v27 == 1 )
    {
      __dmb(9u);
      dma_fence_release(_X0);
      return -12;
    }
    if ( v27 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
      return -12;
    }
    return -12;
  }
  v11 = dma_fence_add_callback(v5, v9, synx_dma_fence_callback);
  if ( v11 )
  {
    v13 = v11;
    v14 = v6;
    if ( v11 == -2 )
    {
      if ( (synx_debug & 8) == 0 )
        goto LABEL_16;
      printk(&unk_29E2A, &unk_2A972, "synx_dma_fence_util_init", 407, v6, v12);
    }
    else
    {
      if ( (synx_debug & 1) == 0 )
        goto LABEL_16;
      printk(&unk_2958D, &unk_29207, "synx_dma_fence_util_init", 410, v6, v11);
    }
    v14 = v6;
LABEL_16:
    _X0 = (unsigned int *)(v14 + 56);
    __asm { PRFM            #0x11, [X0] }
    do
      v29 = __ldxr(_X0);
    while ( __stlxr(v29 - 1, _X0) );
    if ( v29 == 1 )
    {
      __dmb(9u);
      dma_fence_release(_X0);
    }
    else if ( v29 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
    kfree(v9);
    return (int)v13;
  }
  if ( (synx_debug & 8) != 0 )
    printk(&unk_29023, &unk_2A972, "synx_dma_fence_util_init", 419, v5, v9);
  return v5;
}
