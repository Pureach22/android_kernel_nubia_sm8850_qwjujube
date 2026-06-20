__int64 __fastcall a6xx_gmu_snapshot(__int64 a1, __int64 a2)
{
  a6xx_gmu_device_snapshot();
  a6xx_snapshot(a1, a2);
  gmu_core_regwrite(a1, 129425, 0xFFFFFFFFLL);
  return gmu_core_regwrite(a1, 129427, 32774);
}
