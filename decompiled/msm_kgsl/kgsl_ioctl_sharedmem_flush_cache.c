__int64 __fastcall kgsl_ioctl_sharedmem_flush_cache(__int64 a1, __int64 a2, unsigned __int64 *a3)
{
  unsigned __int64 v3; // x0
  __int64 result; // x0
  __int64 v6; // x20
  int v12; // w8

  v3 = kgsl_sharedmem_find(*(_QWORD *)(a1 + 8), *a3);
  if ( !v3 )
    return -22;
  _X19 = (unsigned int *)v3;
  result = (int)kgsl_gpumem_sync_cache(v3, 0, *(_QWORD *)(v3 + 48), 3);
  if ( (unsigned __int64)_X19 <= 0xFFFFFFFFFFFFF000LL )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v12 = __ldxr(_X19);
    while ( __stlxr(v12 - 1, _X19) );
    v6 = (int)result;
    if ( v12 == 1 )
    {
      __dmb(9u);
      kgsl_mem_entry_destroy(_X19);
    }
    else if ( v12 <= 0 )
    {
      refcount_warn_saturate(_X19, 3);
    }
    return v6;
  }
  return result;
}
