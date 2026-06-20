__int64 __fastcall kgsl_ioctl_gpumem_sync_cache(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w1
  unsigned __int64 v4; // x0
  __int64 result; // x0
  __int64 v8; // x20
  int v14; // w8

  v3 = *(_DWORD *)(a3 + 8);
  v4 = *(_QWORD *)(a1 + 8);
  if ( v3 )
  {
    _X19 = kgsl_sharedmem_find_id(v4, v3);
    if ( !_X19 )
      return -22;
  }
  else
  {
    if ( !*(_QWORD *)a3 )
      return -22;
    _X19 = (unsigned int *)kgsl_sharedmem_find(v4, *(_QWORD *)a3);
    if ( !_X19 )
      return -22;
  }
  result = (int)kgsl_gpumem_sync_cache(_X19, *(_QWORD *)(a3 + 16), *(_QWORD *)(a3 + 24), *(unsigned int *)(a3 + 12));
  if ( (unsigned __int64)_X19 <= 0xFFFFFFFFFFFFF000LL )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v14 = __ldxr(_X19);
    while ( __stlxr(v14 - 1, _X19) );
    v8 = (int)result;
    if ( v14 == 1 )
    {
      __dmb(9u);
      kgsl_mem_entry_destroy(_X19);
    }
    else if ( v14 <= 0 )
    {
      refcount_warn_saturate(_X19, 3);
    }
    return v8;
  }
  return result;
}
