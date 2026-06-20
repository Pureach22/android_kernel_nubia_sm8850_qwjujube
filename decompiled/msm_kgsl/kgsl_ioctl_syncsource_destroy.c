__int64 __fastcall kgsl_ioctl_syncsource_destroy(__int64 a1, __int64 a2, unsigned int *a3)
{
  __int64 v3; // x20
  __int64 v5; // x0
  __int64 v7; // x20
  _QWORD *v8; // x21
  _QWORD *v9; // x23
  _QWORD *v10; // x8
  _QWORD *v11; // x9
  int v18; // w8

  v3 = *(_QWORD *)(a1 + 8);
  raw_spin_lock(v3 + 368);
  v5 = idr_find(v3 + 344, *a3);
  if ( v5 )
  {
    _X19 = v5;
    if ( *(_DWORD *)(v5 + 36) )
    {
      idr_remove(v3 + 344);
      *(_DWORD *)(_X19 + 36) = 0;
    }
    raw_spin_unlock(v3 + 368);
    v7 = raw_spin_lock_irqsave(_X19 + 64);
    v8 = *(_QWORD **)(_X19 + 48);
    if ( v8 != (_QWORD *)(_X19 + 48) )
    {
      do
      {
        v9 = (_QWORD *)*v8;
        dma_fence_signal_locked(v8 - 9);
        v10 = (_QWORD *)v8[1];
        if ( (_QWORD *)*v10 == v8 && (v11 = (_QWORD *)*v8, *(_QWORD **)(*v8 + 8LL) == v8) )
        {
          v11[1] = v10;
          *v10 = v11;
        }
        else
        {
          _list_del_entry_valid_or_report(v8);
        }
        *v8 = v8;
        v8[1] = v8;
        v8 = v9;
      }
      while ( v9 != (_QWORD *)(_X19 + 48) );
    }
    raw_spin_unlock_irqrestore(_X19 + 64, v7);
    __asm { PRFM            #0x11, [X19] }
    do
      v18 = __ldxr((unsigned int *)_X19);
    while ( __stlxr(v18 - 1, (unsigned int *)_X19) );
    if ( v18 == 1 )
    {
      __dmb(9u);
      kgsl_process_private_put(*(unsigned int **)(_X19 + 40));
      kfree(_X19);
    }
    else if ( v18 <= 0 )
    {
      refcount_warn_saturate(_X19, 3);
    }
    return 0;
  }
  else
  {
    raw_spin_unlock(v3 + 368);
    return -22;
  }
}
