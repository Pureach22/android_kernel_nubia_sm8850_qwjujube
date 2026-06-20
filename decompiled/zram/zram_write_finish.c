unsigned int *__fastcall zram_write_finish(__int64 a1, int a2, __int64 a3, int a4)
{
  unsigned int *v4; // x19
  __int64 v5; // x24
  __int64 v7; // x25
  unsigned __int64 *v10; // x20
  __int64 v11; // x8
  unsigned __int64 v18; // x9
  unsigned __int64 v21; // x9
  __int64 v22; // x20
  unsigned int *result; // x0
  unsigned __int64 v26; // x9
  int v28; // w8
  unsigned __int64 v31; // x9

  v4 = *(unsigned int **)a1;
  v5 = *(unsigned int *)(a1 + 16);
  v7 = *(_QWORD *)(a1 + 24);
  v10 = **(unsigned __int64 ***)a1;
  raw_spin_lock(*v10 + 16 * v5 + 12);
  zram_free_page(v10, v5);
  if ( a2 == 4096 )
  {
    *(_DWORD *)(*v10 + 16 * v5 + 8) |= 0x10000u;
    _X8 = v10 + 18;
    __asm { PRFM            #0x11, [X8] }
    do
      v18 = __ldxr(_X8);
    while ( __stxr(v18 + 1, _X8) );
    _X8 = v10 + 19;
    __asm { PRFM            #0x11, [X8] }
    do
      v21 = __ldxr(_X8);
    while ( __stxr(v21 + 1, _X8) );
    v11 = 16 * v5;
    if ( !a4 )
      goto LABEL_9;
  }
  else
  {
    v11 = 16 * v5;
    if ( !a4 )
    {
LABEL_9:
      *(_QWORD *)(*v10 + v11) = v7;
      *(_DWORD *)(*v10 + v11 + 8) = *(_DWORD *)(*v10 + v11 + 8) & 0xFFFFE000 | a2;
      goto LABEL_10;
    }
  }
  *(_DWORD *)(*v10 + v11 + 8) |= 1LL << a4;
  *(_QWORD *)(*v10 + v11) = a3;
LABEL_10:
  *(_DWORD *)(*v10 + v11 + 8) &= ~0x20000u;
  raw_spin_unlock(*v10 + v11 + 12);
  _X8 = v10 + 20;
  __asm { PRFM            #0x11, [X8] }
  do
    v26 = __ldxr(_X8);
  while ( __stxr(v26 + 1, _X8) );
  result = v4 + 6;
  __asm { PRFM            #0x11, [X0] }
  do
    v28 = __ldxr(result);
  while ( __stlxr(v28 - 1, result) );
  if ( v28 == 1 )
  {
    __dmb(9u);
    if ( *(_BYTE *)(*((_QWORD *)v4 + 1) + 25LL) == 10 )
    {
      _X8 = (unsigned __int64 *)(*(_QWORD *)v4 + 120LL);
      __asm { PRFM            #0x11, [X8] }
      do
        v31 = __ldxr(_X8);
      while ( __stxr(v31 + 1, _X8) );
    }
    v22 = *((_QWORD *)v4 + 1);
    bio_end_io_acct_remapped(v22, *((_QWORD *)v4 + 2), *(_QWORD *)(v22 + 8));
    bio_endio(v22);
    return (unsigned int *)kfree(v4);
  }
  else if ( v28 <= 0 )
  {
    return (unsigned int *)refcount_warn_saturate(result, 3);
  }
  return result;
}
