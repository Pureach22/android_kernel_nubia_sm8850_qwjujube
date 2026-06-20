__int64 __fastcall gen7_hwsched_context_destroy(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = adreno_hwsched_context_queue_enabled(a1);
  if ( (result & 1) != 0 )
  {
    if ( *(_DWORD *)(a2 + 1824) )
      result = gmu_core_free_block(a1, a2 + 1640);
    if ( *(_DWORD *)(a2 + 2032) )
      return gmu_core_free_block(a1, a2 + 1848);
  }
  return result;
}
