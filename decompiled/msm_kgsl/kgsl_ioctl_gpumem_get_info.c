__int64 __fastcall kgsl_ioctl_gpumem_get_info(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w1
  unsigned __int64 v4; // x0
  __int64 v7; // x8
  unsigned __int64 v8; // x9
  int v14; // w8

  v3 = *(_DWORD *)(a3 + 8);
  v4 = *(_QWORD *)(a1 + 8);
  if ( v3 )
  {
    _X0 = (unsigned __int64)kgsl_sharedmem_find_id(v4, v3);
    if ( !_X0 )
      return -22;
  }
  else
  {
    if ( !*(_QWORD *)a3 )
      return -22;
    _X0 = kgsl_sharedmem_find(v4, *(_QWORD *)a3);
    if ( !_X0 )
      return -22;
  }
  v7 = 0;
  *(_QWORD *)a3 = *(_QWORD *)(_X0 + 32);
  *(_DWORD *)(a3 + 8) = *(_DWORD *)(_X0 + 248);
  *(_DWORD *)(a3 + 12) = *(_QWORD *)(_X0 + 80);
  v8 = *(_QWORD *)(_X0 + 48);
  *(_QWORD *)(a3 + 16) = v8;
  if ( (*(_DWORD *)(_X0 + 56) & 1) != 0 )
    v8 = (v8 + 0x1FFF) & 0xFFFFFFFFFFFFF000LL;
  *(_QWORD *)(a3 + 24) = v8;
  *(_QWORD *)(a3 + 32) = 0;
  if ( _X0 <= 0xFFFFFFFFFFFFF000LL )
  {
    __asm { PRFM            #0x11, [X0] }
    do
      v14 = __ldxr((unsigned int *)_X0);
    while ( __stlxr(v14 - 1, (unsigned int *)_X0) );
    if ( v14 == 1 )
    {
      __dmb(9u);
      kgsl_mem_entry_destroy((_QWORD *)_X0);
    }
    else if ( v14 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
    return 0;
  }
  return v7;
}
