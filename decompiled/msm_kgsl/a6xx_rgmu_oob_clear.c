__int64 __fastcall a6xx_rgmu_oob_clear(__int64 result, int a2)
{
  int v2; // w8

  if ( a2 != 1 )
    return gmu_core_regwrite(result, 129428, (unsigned int)(1LL << ((unsigned __int8)a2 + 24)));
  v2 = *(_DWORD *)(result - 8) - 1;
  *(_DWORD *)(result - 8) = v2;
  if ( !v2 )
    return gmu_core_regwrite(result, 129428, (unsigned int)(1LL << ((unsigned __int8)a2 + 24)));
  return result;
}
