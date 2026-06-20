__int64 __fastcall qdf_thread_join(__int64 a1)
{
  __int64 result; // x0
  unsigned int v4; // w20
  int v10; // w9
  unsigned int v11; // w19

  result = kthread_stop();
  _X8 = (unsigned int *)(a1 + 64);
  __asm { PRFM            #0x11, [X8] }
  do
    v10 = __ldxr(_X8);
  while ( __stlxr(v10 - 1, _X8) );
  if ( v10 == 1 )
  {
    __dmb(9u);
    v4 = result;
    _put_task_struct(a1);
    return v4;
  }
  else if ( v10 <= 0 )
  {
    v11 = result;
    refcount_warn_saturate(_X8, 3);
    return v11;
  }
  return result;
}
