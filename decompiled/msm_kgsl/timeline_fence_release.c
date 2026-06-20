__int64 __fastcall timeline_fence_release(__int64 *a1)
{
  __int64 v1; // x20
  __int64 v3; // x9
  _QWORD *v4; // x10
  __int64 **v5; // x8
  __int64 *v6; // x10
  __int64 *v7; // x11
  unsigned __int64 v8; // x8
  int v15; // w8

  v1 = a1[8];
  v3 = raw_spin_lock_irqsave(v1 + 24);
  v4 = (_QWORD *)(v1 + 40);
  while ( 1 )
  {
    v4 = (_QWORD *)*v4;
    if ( v4 == (_QWORD *)(v1 + 40) )
      break;
    if ( v4 - 9 == a1 )
    {
      v5 = (__int64 **)a1[10];
      v6 = a1 + 9;
      if ( *v5 == a1 + 9 && (v7 = (__int64 *)*v6, *(__int64 **)(*v6 + 8) == v6) )
      {
        v7[1] = (__int64)v5;
        *v5 = v7;
      }
      else
      {
        _list_del_entry_valid_or_report(a1 + 9);
      }
      a1[9] = (__int64)(a1 + 9);
      a1[10] = (__int64)v6;
      break;
    }
  }
  raw_spin_unlock_irqrestore(v1 + 24, v3);
  log_kgsl_timeline_fence_release_event(*(unsigned int *)(a1[8] + 8), a1[5]);
  v8 = a1[8];
  if ( v8 && v8 <= 0xFFFFFFFFFFFFF000LL )
  {
    _X0 = (unsigned int *)(v8 + 32);
    __asm { PRFM            #0x11, [X0] }
    do
      v15 = __ldxr(_X0);
    while ( __stlxr(v15 - 1, _X0) );
    if ( v15 == 1 )
    {
      __dmb(9u);
      kgsl_timeline_destroy((__int64)_X0);
    }
    else if ( v15 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
  }
  return dma_fence_free(a1);
}
