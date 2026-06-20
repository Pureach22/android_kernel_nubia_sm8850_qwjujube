__int64 __fastcall a6xx_gpu_keepalive(__int64 a1, char a2)
{
  __int64 result; // x0

  result = gmu_core_isenabled(a1);
  if ( (result & 1) != 0 )
    return gmu_core_regwrite(a1, 129219, a2 & 1);
  return result;
}
