__int64 __fastcall gen8_hwsched_process_detached_hw_fences(__int64 a1)
{
  _QWORD *v1; // x20
  __int64 v2; // x22
  _QWORD *v4; // x21
  _QWORD *v5; // x25
  __int64 result; // x0
  int v13; // w8

  v1 = *(_QWORD **)(a1 + 24816);
  v2 = a1 + 24816;
  if ( v1 == (_QWORD *)(a1 + 24816) )
    return 0;
  while ( 1 )
  {
    v4 = v1 - 8;
    v5 = (_QWORD *)*v1;
    result = gen8_send_hw_fence_hfi_wait_ack(a1, (__int64)(v1 - 8), 1);
    if ( (_DWORD)result )
      break;
    _X20 = (unsigned int *)*(v1 - 1);
    adreno_hwsched_remove_hw_fence_entry(a1, v4);
    if ( _X20 )
    {
      __asm { PRFM            #0x11, [X20] }
      do
        v13 = __ldxr(_X20);
      while ( __stlxr(v13 - 1, _X20) );
      if ( v13 == 1 )
      {
        __dmb(9u);
        kgsl_context_destroy(_X20);
      }
      else if ( v13 <= 0 )
      {
        refcount_warn_saturate(_X20, 3);
      }
    }
    v1 = v5;
    if ( v5 == (_QWORD *)v2 )
      return 0;
  }
  return result;
}
