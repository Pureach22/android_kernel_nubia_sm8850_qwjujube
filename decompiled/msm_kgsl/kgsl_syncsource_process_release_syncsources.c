__int64 __fastcall kgsl_syncsource_process_release_syncsources(__int64 a1)
{
  __int64 next; // x0
  __int64 v4; // x21
  _QWORD *v5; // x22
  _QWORD *v6; // x26
  _QWORD *v7; // x8
  _QWORD *v8; // x9
  int v14; // w8
  __int64 result; // x0
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  raw_spin_lock(a1 + 368);
  next = idr_get_next(a1 + 344, &v16);
  if ( next )
  {
    _X20 = next;
    do
    {
      if ( *(_DWORD *)(_X20 + 36) )
      {
        idr_remove(a1 + 344);
        *(_DWORD *)(_X20 + 36) = 0;
      }
      raw_spin_unlock(a1 + 368);
      v4 = raw_spin_lock_irqsave(_X20 + 64);
      v5 = *(_QWORD **)(_X20 + 48);
      if ( v5 != (_QWORD *)(_X20 + 48) )
      {
        do
        {
          v6 = (_QWORD *)*v5;
          dma_fence_signal_locked(v5 - 9);
          v7 = (_QWORD *)v5[1];
          if ( (_QWORD *)*v7 == v5 && (v8 = (_QWORD *)*v5, *(_QWORD **)(*v5 + 8LL) == v5) )
          {
            v8[1] = v7;
            *v7 = v8;
          }
          else
          {
            _list_del_entry_valid_or_report(v5);
          }
          *v5 = v5;
          v5[1] = v5;
          v5 = v6;
        }
        while ( v6 != (_QWORD *)(_X20 + 48) );
      }
      raw_spin_unlock_irqrestore(_X20 + 64, v4);
      __asm { PRFM            #0x11, [X20] }
      do
        v14 = __ldxr((unsigned int *)_X20);
      while ( __stlxr(v14 - 1, (unsigned int *)_X20) );
      if ( v14 == 1 )
      {
        __dmb(9u);
        kgsl_process_private_put(*(unsigned int **)(_X20 + 40));
        kfree(_X20);
      }
      else if ( v14 <= 0 )
      {
        refcount_warn_saturate(_X20, 3);
      }
      ++v16;
      raw_spin_lock(a1 + 368);
      _X20 = idr_get_next(a1 + 344, &v16);
    }
    while ( _X20 );
  }
  result = raw_spin_unlock(a1 + 368);
  _ReadStatusReg(SP_EL0);
  return result;
}
