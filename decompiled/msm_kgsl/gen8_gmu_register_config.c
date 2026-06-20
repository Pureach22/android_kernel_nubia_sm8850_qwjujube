__int64 __fastcall gen8_gmu_register_config(__int64 a1)
{
  __int64 v1; // x21
  unsigned __int64 v3; // x8
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 14264);
  *(_DWORD *)(a1 - 796) = 0;
  gmu_core_regwrite(a1, 129001, 15);
  gmu_core_regwrite(a1, 129005, 1);
  gmu_core_regwrite(a1, 129004, 1);
  gmu_core_regwrite(a1, 129052, 0);
  gmu_core_regwrite(a1, 129025, 2);
  gmu_core_regwrite(a1, 129413, *(unsigned int *)(*(_QWORD *)(a1 - 1776) + 184LL));
  gmu_core_regwrite(a1, 129412, 1);
  gmu_core_regwrite(a1, 146193, 2160593088LL);
  gmu_core_regwrite(a1, 129069, 16466);
  kgsl_regmap_multi_write(a1 + 13200, *(_QWORD *)(v1 + 144), *(unsigned int *)(v1 + 152));
  kgsl_regmap_write(a1 + 13200, 8);
  v3 = *(_QWORD *)(a1 + 8664);
  if ( v3 && v3 <= 0xFFFFFFFFFFFFF000LL )
    gmu_core_regwrite(a1, 129483, *(unsigned int *)(v3 + 184));
  gmu_core_regwrite(a1, 129481, *(unsigned int *)(a1 - 800));
  gmu_core_regwrite(a1, 129482, (unsigned int)(**(_DWORD **)(a1 + 14264) << 8));
  gmu_core_regwrite(a1, 129480, *(_DWORD *)(*(_QWORD *)(a1 - 1808) + 184LL) & 0xFFFFF000 | 0xF);
  gmu_core_regwrite(a1, 128015, 1);
  gmu_core_regwrite(a1, 128000, 1);
  result = gmu_core_regwrite(a1, 128001, 1);
  if ( *(_BYTE *)(a1 + 20437) == 1 )
    return gmu_core_regrmw(a1, 130112, 4294967040LL, 420942592);
  return result;
}
