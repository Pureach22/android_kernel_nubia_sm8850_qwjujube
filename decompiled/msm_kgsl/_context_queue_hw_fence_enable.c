__int64 __fastcall context_queue_hw_fence_enable(__int64 result)
{
  __int64 v1; // x19
  unsigned __int64 v8; // x9

  if ( (*(_DWORD *)(result + 8280) & 0xFFF0000u) > 0x20000 )
  {
    v1 = result;
    result = gen7_hfi_send_get_value(result, 121, 0);
    if ( (_DWORD)result == 1 )
    {
      _X8 = (unsigned __int64 *)(v1 + 22496);
      __asm { PRFM            #0x11, [X8] }
      do
        v8 = __ldxr(_X8);
      while ( __stxr(v8 | 8, _X8) );
      return adreno_hwsched_register_hw_fence(v1);
    }
  }
  return result;
}
