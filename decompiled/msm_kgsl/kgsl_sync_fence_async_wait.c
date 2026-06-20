__int64 __fastcall kgsl_sync_fence_async_wait(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 fence; // x0
  __int64 v6; // x19
  __int64 v7; // x20
  int v8; // w0
  int v9; // w21
  __int64 (__fastcall *v10)(_QWORD); // x8
  int v18; // w8
  int v20; // w8

  fence = sync_file_get_fence();
  if ( !fence )
    return -22;
  v6 = fence;
  v7 = _kmalloc_cache_noprof(raw_read_unlock, 3520, 48);
  if ( v7 )
  {
    *(_QWORD *)(v7 + 24) = v6;
    *(_QWORD *)(v7 + 32) = a3;
    *(_QWORD *)(v7 + 40) = a2;
    v8 = dma_fence_add_callback(v6, v7, kgsl_sync_fence_callback);
    if ( v8 )
    {
      v9 = v8;
      kfree(v7);
      if ( (*(_QWORD *)(v6 + 48) & 1) != 0 )
      {
        v7 = 0;
      }
      else
      {
        v10 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v6 + 8) + 32LL);
        if ( !v10 )
          goto LABEL_12;
        if ( *((_DWORD *)v10 - 1) != 1879296680 )
          __break(0x8228u);
        if ( (v10(v6) & 1) != 0 )
        {
          dma_fence_signal(v6);
          v7 = 0;
        }
        else
        {
LABEL_12:
          v7 = v9;
        }
      }
      _X0 = (unsigned int *)(v6 + 56);
      __asm { PRFM            #0x11, [X0] }
      do
        v18 = __ldxr(_X0);
      while ( __stlxr(v18 - 1, _X0) );
      if ( v18 == 1 )
      {
        __dmb(9u);
        dma_fence_release(_X0);
      }
      else if ( v18 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
    }
  }
  else
  {
    _X0 = (unsigned int *)(v6 + 56);
    __asm { PRFM            #0x11, [X0] }
    do
      v20 = __ldxr(_X0);
    while ( __stlxr(v20 - 1, _X0) );
    if ( v20 == 1 )
    {
      __dmb(9u);
      dma_fence_release(_X0);
    }
    else if ( v20 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
    return -12;
  }
  return v7;
}
