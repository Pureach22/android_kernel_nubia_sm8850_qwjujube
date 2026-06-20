__int64 __fastcall kgsl_sync_timeline_detach(__int64 a1)
{
  __int64 v3; // x0
  __int64 result; // x0
  int v10; // w8

  _X19 = *(unsigned int **)(a1 + 80);
  v3 = raw_spin_lock_irqsave(a1 + 64);
  *(_QWORD *)(a1 + 80) = 0;
  result = raw_spin_unlock_irqrestore(a1 + 64, v3);
  if ( _X19 )
  {
    __asm { PRFM            #0x11, [X19] }
    do
      v10 = __ldxr(_X19);
    while ( __stlxr(v10 - 1, _X19) );
    if ( v10 == 1 )
    {
      __dmb(9u);
      return kgsl_context_destroy((__int64)_X19);
    }
    else if ( v10 <= 0 )
    {
      return refcount_warn_saturate(_X19, 3);
    }
  }
  return result;
}
