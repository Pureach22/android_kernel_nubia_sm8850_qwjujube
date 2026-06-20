__int64 __fastcall handle_hw_fences_after_soft_reset(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  if ( !a2 )
    return 0;
  result = gen8_hwsched_process_detached_hw_fences(a1);
  if ( !(_DWORD)result )
    return gen8_hwsched_disable_hw_fence_throttle(a1);
  return result;
}
