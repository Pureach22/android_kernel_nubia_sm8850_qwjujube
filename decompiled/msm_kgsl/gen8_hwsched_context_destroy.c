__int64 __fastcall gen8_hwsched_context_destroy(__int64 result, __int64 a2)
{
  __int64 v3; // x20

  v3 = result;
  if ( *(_DWORD *)(a2 + 1824) )
    result = gmu_core_free_block(result, a2 + 1640);
  if ( *(_DWORD *)(a2 + 2032) )
    return gmu_core_free_block(v3, a2 + 1848);
  return result;
}
