__int64 __fastcall kgsl_syncsource_fence_release(_QWORD *a1)
{
  __int64 v1; // x22
  __int64 v3; // x20
  _QWORD *v4; // x21
  _QWORD *v5; // x8
  _QWORD *v6; // x9
  int v13; // w8

  v1 = a1[8];
  v3 = raw_spin_lock_irqsave(v1 + 64);
  v4 = (_QWORD *)(v1 + 48);
  while ( 1 )
  {
    v4 = (_QWORD *)*v4;
    if ( v4 == (_QWORD *)(v1 + 48) )
      break;
    if ( v4 - 9 == a1 )
    {
      dma_fence_signal_locked(a1);
      v5 = (_QWORD *)v4[1];
      if ( (_QWORD *)*v5 == v4 && (v6 = (_QWORD *)*v4, *(_QWORD **)(*v4 + 8LL) == v4) )
      {
        v6[1] = v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v4);
      }
      *v4 = v4;
      v4[1] = v4;
      break;
    }
  }
  raw_spin_unlock_irqrestore(v1 + 64, v3);
  _X20 = a1[8];
  if ( _X20 )
  {
    __asm { PRFM            #0x11, [X20] }
    do
      v13 = __ldxr((unsigned int *)_X20);
    while ( __stlxr(v13 - 1, (unsigned int *)_X20) );
    if ( v13 == 1 )
    {
      __dmb(9u);
      kgsl_process_private_put(*(unsigned int **)(_X20 + 40));
      kfree(_X20);
    }
    else if ( v13 <= 0 )
    {
      refcount_warn_saturate(_X20, 3);
    }
  }
  return kfree(a1);
}
