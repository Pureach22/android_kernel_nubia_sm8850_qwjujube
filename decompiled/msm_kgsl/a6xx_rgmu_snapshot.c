__int64 __fastcall a6xx_rgmu_snapshot(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  adreno_snapshot_registers(a1, a2, &a6xx_rgmu_registers, 23);
  a6xx_snapshot(a1, a2);
  gmu_core_regwrite(a1, 129425, 0xFFFFFFFFLL);
  result = gmu_core_regwrite(a1, 129427, 4278190080LL);
  if ( *(_BYTE *)(a1 + 13192) == 1 )
    ++*(_DWORD *)(a1 - 20);
  return result;
}
