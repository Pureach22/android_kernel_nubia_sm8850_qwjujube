__int64 __fastcall a6xx_gmu_version_info(__int64 a1)
{
  gmu_core_regread(a1, 119800, a1 + 8264);
  gmu_core_regread(a1, 119801, a1 + 8268);
  gmu_core_regread(a1, 119802, a1 + 8272);
  gmu_core_regread(a1, 119803, a1 + 8276);
  return gmu_core_regread(a1, 119804, a1 + 8280);
}
