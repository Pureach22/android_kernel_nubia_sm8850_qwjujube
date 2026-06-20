__int64 __fastcall inc_byte(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  unsigned int v3; // w21
  _QWORD v5[6]; // [xsp+0h] [xbp-30h] BYREF

  v5[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = global_memory;
  if ( (*(_BYTE *)(a1 + 112) & 1) == 0 )
  {
    v2 = a1;
    memset(v5, 0, 40);
    init_wait_entry(v5, 0);
    a1 = prepare_to_wait_event(v2 + 88, v5, 1);
    if ( (*(_BYTE *)(v2 + 112) & 1) != 0 )
    {
LABEL_5:
      a1 = finish_wait(v2 + 88, v5);
    }
    else
    {
      while ( !a1 )
      {
        schedule();
        a1 = prepare_to_wait_event(v2 + 88, v5, 1);
        if ( *(_BYTE *)(v2 + 112) == 1 )
          goto LABEL_5;
      }
    }
  }
  if ( (kthread_should_stop(a1) & 1) == 0 )
  {
    if ( (_DWORD)qword_B680 )
    {
      v3 = 0;
      do
      {
        ipclite_global_atomic_inc(v1);
        ++v3;
      }
      while ( v3 < (unsigned int)qword_B680 );
    }
    ++threads_completed;
    _wake_up(&thread_wq, 1, 1, 0);
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
