__int64 __fastcall kgsl_sync_fence_event_cb(__int64 a1, __int64 a2, unsigned int *a3)
{
  int v10; // w8

  kgsl_sync_timeline_signal(*(unsigned int **)(*(_QWORD *)a3 + 56LL), a3[2]);
  _X0 = *(unsigned int **)a3;
  if ( *(_QWORD *)a3 )
  {
    __asm { PRFM            #0x11, [X0] }
    do
      v10 = __ldxr(_X0);
    while ( __stlxr(v10 - 1, _X0) );
    if ( v10 == 1 )
    {
      __dmb(9u);
      kgsl_context_destroy((__int64)_X0);
    }
    else if ( v10 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
  }
  return kfree(a3);
}
