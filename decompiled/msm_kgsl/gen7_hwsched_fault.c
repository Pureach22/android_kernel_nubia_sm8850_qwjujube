__int64 __fastcall gen7_hwsched_fault(__int64 a1, int a2)
{
  __int64 v4; // x0
  int v5; // w8
  __int64 v6; // x21
  unsigned int v10; // w9
  unsigned __int64 v17; // x10
  unsigned __int64 v20; // x9
  unsigned __int64 v23; // x10
  unsigned __int64 v26; // x9

  v4 = to_gen7_hwsched_hfi();
  v5 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 16);
  if ( (*(_QWORD *)(a1 + 22496) & 0x10) != 0 )
  {
    v6 = v4;
    if ( (v5 & 0xFFFF00) != 0 )
    {
      _X8 = (unsigned __int64 *)(a1 + 23200);
      __asm { PRFM            #0x11, [X8] }
      do
        v17 = __ldxr(_X8);
      while ( __stxr(v17 & 0xFFFFFFFFFFFFFFFELL, _X8) );
      _X8 = (unsigned __int64 *)(a1 + 23200);
      __asm { PRFM            #0x11, [X8] }
      do
        v20 = __ldxr(_X8);
      while ( __stxr(v20 | 4, _X8) );
      __dmb(0xAu);
    }
    else
    {
      raw_spin_lock(a1 + 23152);
      _X8 = (unsigned __int64 *)(a1 + 23200);
      __asm { PRFM            #0x11, [X8] }
      do
        v23 = __ldxr(_X8);
      while ( __stxr(v23 & 0xFFFFFFFFFFFFFFFELL, _X8) );
      _X8 = (unsigned __int64 *)(a1 + 23200);
      __asm { PRFM            #0x11, [X8] }
      do
        v26 = __ldxr(_X8);
      while ( __stxr(v26 | 4, _X8) );
      raw_spin_unlock(a1 + 23152);
    }
    _wake_up(a1 + 23160, 3, 0, 0);
    timer_delete_sync(v6 + 136);
  }
  _X8 = (unsigned int *)(a1 + 24448);
  __asm { PRFM            #0x11, [X8] }
  do
    v10 = __ldxr(_X8);
  while ( __stxr(v10 | a2, _X8) );
  __dmb(0xAu);
  return kthread_queue_work(*(_QWORD *)(a1 + 24400), a1 + 24408);
}
