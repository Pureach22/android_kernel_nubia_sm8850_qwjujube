__int64 __fastcall kgsl_ioctl_cmdstream_freememontimestamp_ctxtid(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 owner; // x0
  unsigned __int64 v7; // x0
  __int64 result; // x0
  __int64 v10; // x21
  int v12; // w8
  int v18; // w8
  __int64 v19; // x20
  int v21; // w8

  if ( *(_DWORD *)(a3 + 16) != 2 )
    return -22;
  owner = kgsl_context_get_owner(a1, *(_DWORD *)a3);
  if ( !owner )
    return -22;
  _X19 = (unsigned int *)owner;
  v7 = kgsl_sharedmem_find(a1[1], *(_QWORD *)(a3 + 8));
  if ( !v7 )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v12 = __ldxr(_X19);
    while ( __stlxr(v12 - 1, _X19) );
    if ( v12 == 1 )
    {
      __dmb(9u);
      kgsl_context_destroy((__int64)_X19);
      return -22;
    }
    if ( v12 <= 0 )
    {
      refcount_warn_saturate(_X19, 3);
      return -22;
    }
    return -22;
  }
  _X20 = (unsigned int *)v7;
  result = gpumem_free_entry_on_timestamp(*a1, v7, _X19, *(unsigned int *)(a3 + 20));
  if ( (unsigned __int64)_X20 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_23;
  __asm { PRFM            #0x11, [X20] }
  do
    v18 = __ldxr(_X20);
  while ( __stlxr(v18 - 1, _X20) );
  if ( v18 == 1 )
  {
    __dmb(9u);
    v10 = result;
    kgsl_mem_entry_destroy(_X20);
LABEL_7:
    result = v10;
    goto LABEL_23;
  }
  if ( v18 <= 0 )
  {
    v10 = result;
    refcount_warn_saturate(_X20, 3);
    goto LABEL_7;
  }
LABEL_23:
  __asm { PRFM            #0x11, [X19] }
  do
    v21 = __ldxr(_X19);
  while ( __stlxr(v21 - 1, _X19) );
  if ( v21 == 1 )
  {
    __dmb(9u);
    v19 = result;
    kgsl_context_destroy((__int64)_X19);
    return v19;
  }
  if ( v21 <= 0 )
  {
    v19 = result;
    refcount_warn_saturate(_X19, 3);
    return v19;
  }
  return result;
}
