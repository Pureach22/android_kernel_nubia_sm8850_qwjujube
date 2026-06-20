__int64 __fastcall kgsl_ioctl_gpumem_free_id(__int64 a1, __int64 a2, unsigned int *a3)
{
  unsigned int *id; // x0
  __int64 result; // x0
  __int64 v6; // x20
  int v12; // w8

  id = kgsl_sharedmem_find_id(*(_QWORD *)(a1 + 8), *a3);
  if ( !id )
    return -22;
  _X19 = id;
  result = gpumem_free_entry((unsigned __int64)id);
  if ( (unsigned __int64)_X19 <= 0xFFFFFFFFFFFFF000LL )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v12 = __ldxr(_X19);
    while ( __stlxr(v12 - 1, _X19) );
    v6 = result;
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
