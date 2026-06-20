__int64 __fastcall kgsl_snapshot_put_object(__int64 a1)
{
  unsigned int v8; // w10
  int v11; // w8

  list_del(a1 + 40);
  _X8 = (unsigned int *)(*(_QWORD *)(a1 + 32) + 56LL);
  __asm { PRFM            #0x11, [X8] }
  do
    v8 = __ldxr(_X8);
  while ( __stxr(v8 & 0xFFFFEFFB, _X8) );
  _X0 = *(unsigned int **)(a1 + 32);
  if ( _X0 && (unsigned __int64)_X0 <= 0xFFFFFFFFFFFFF000LL )
  {
    __asm { PRFM            #0x11, [X0] }
    do
      v11 = __ldxr(_X0);
    while ( __stlxr(v11 - 1, _X0) );
    if ( v11 == 1 )
    {
      __dmb(9u);
      kgsl_mem_entry_destroy(_X0);
    }
    else if ( v11 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
  }
  return kfree(a1);
}
