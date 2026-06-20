__int64 __fastcall get_mmap_entry(unsigned __int64 a1, unsigned __int64 *a2, __int64 a3, __int64 a4)
{
  __int64 v9; // x8
  __int64 v10; // x8
  unsigned int v11; // w19
  __int64 v12; // x9
  unsigned __int64 v13; // x10
  int v19; // w8

  _X0 = (unsigned __int64)kgsl_sharedmem_find_id(a1, a3);
  if ( !_X0 )
  {
    _X0 = kgsl_sharedmem_find(a1, a3 << 12);
    if ( !_X0 )
      return (unsigned int)-22;
  }
  v9 = *(_QWORD *)(_X0 + 72);
  if ( !v9 || !*(_DWORD *)v9 || !*(_QWORD *)(v9 + 8) )
  {
    v11 = -22;
    if ( _X0 > 0xFFFFFFFFFFFFF000LL )
      return v11;
    goto LABEL_25;
  }
  v10 = *(_QWORD *)(_X0 + 80);
  if ( (v10 & 0x60) == 0 )
  {
    v12 = *(_QWORD *)(_X0 + 48);
    if ( (*(_DWORD *)(_X0 + 56) & 1) != 0 )
      v13 = (v12 + 0x1FFF) & 0xFFFFFFFFFFFFF000LL;
    else
      v13 = *(_QWORD *)(_X0 + 48);
    if ( _X0 == -8 || (v10 & 0x10000000) == 0 )
    {
      if ( v13 == a4 || v12 == a4 )
        goto LABEL_24;
    }
    else if ( v13 == a4 )
    {
LABEL_24:
      v11 = 0;
      *a2 = _X0;
      return v11;
    }
    v11 = -34;
    if ( _X0 > 0xFFFFFFFFFFFFF000LL )
      return v11;
    goto LABEL_25;
  }
  v11 = -16;
  if ( _X0 > 0xFFFFFFFFFFFFF000LL )
    return v11;
LABEL_25:
  __asm { PRFM            #0x11, [X0] }
  do
    v19 = __ldxr((unsigned int *)_X0);
  while ( __stlxr(v19 - 1, (unsigned int *)_X0) );
  if ( v19 == 1 )
  {
    __dmb(9u);
    kgsl_mem_entry_destroy((_QWORD *)_X0);
  }
  else if ( v19 <= 0 )
  {
    refcount_warn_saturate(_X0, 3);
  }
  return v11;
}
