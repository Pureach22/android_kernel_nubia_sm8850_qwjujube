__int64 __fastcall qcom_io_pgtable_allocator_register(unsigned int a1)
{
  __int64 v2; // x0
  unsigned int v4; // w19
  __int64 v6; // x0
  __int64 v7; // x21
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x20
  unsigned int v16; // w8

  mutex_lock(&page_pool_xa_lock);
  v2 = xa_load(&page_pool_xa, a1);
  if ( v2 )
  {
    _X0 = (unsigned int *)(v2 + 4);
    __asm { PRFM            #0x11, [X0] }
    do
      v16 = __ldxr(_X0);
    while ( __stxr(v16 + 1, _X0) );
    if ( !v16 || (((v16 + 1) | v16) & 0x80000000) != 0 )
      refcount_warn_saturate();
    v4 = 0;
  }
  else
  {
    v6 = _kmalloc_cache_noprof(vunmap, 3264, 32);
    v7 = v6;
    if ( v6 )
    {
      *(_DWORD *)v6 = a1;
      *(_DWORD *)(v6 + 4) = 1;
      *(_DWORD *)(v6 + 8) = 0;
      *(_QWORD *)(v6 + 16) = v6 + 16;
      *(_QWORD *)(v6 + 24) = v6 + 16;
      v8 = xa_store(&page_pool_xa, a1, v6, 3264);
      v9 = v8 >> 2;
      if ( (v8 & 3) == 2 && v8 > 0xFFFFFFFFFFFFC005LL )
        v4 = v8 >> 2;
      else
        v4 = 0;
      if ( (v4 & 0x80000000) != 0 )
      {
        kfree(v7);
        v4 = v9;
      }
    }
    else
    {
      v4 = -12;
    }
  }
  mutex_unlock(&page_pool_xa_lock);
  return v4;
}
