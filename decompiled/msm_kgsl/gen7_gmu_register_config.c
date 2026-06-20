__int64 __fastcall gen7_gmu_register_config(__int64 a1)
{
  __int64 v1; // x21
  unsigned int v3; // w8
  __int64 v4; // x3
  unsigned __int64 v5; // x8
  int v6; // w8
  __int64 v7; // x2
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 14264);
  *(_DWORD *)(a1 - 692) = 0;
  gmu_core_regwrite(a1, 129265, 1);
  gmu_core_regwrite(a1, 129264, 1);
  gmu_core_regwrite(a1, 129052, 0);
  gmu_core_regwrite(a1, 129025, 2);
  gmu_core_regwrite(a1, 129413, *(unsigned int *)(*(_QWORD *)(a1 - 1728) + 184LL));
  gmu_core_regwrite(a1, 129412, 1);
  gmu_core_regwrite(a1, 146193, 2160593056LL);
  gmu_core_regwrite(a1, 129069, 16466);
  kgsl_regmap_multi_write(a1 + 13200, *(_QWORD *)(v1 + 168), *(unsigned int *)(v1 + 176));
  v3 = **(_DWORD **)(a1 + 14264);
  if ( v3 >> 1 == 230528 )
  {
    v4 = 0x20000000;
LABEL_5:
    kgsl_regmap_rmw(a1 + 13200, 15360, 3758096384LL, v4);
    goto LABEL_6;
  }
  v4 = 0x40000000;
  if ( v3 == 463104 || v3 == 462336 )
    goto LABEL_5;
LABEL_6:
  kgsl_regmap_write(a1 + 13200, 0);
  v5 = *(_QWORD *)(a1 + 8664);
  if ( v5 && v5 <= 0xFFFFFFFFFFFFF000LL )
    gmu_core_regwrite(a1, 129488, *(unsigned int *)(v5 + 184));
  gmu_core_regwrite(a1, 129486, *(unsigned int *)(a1 - 696));
  v6 = **(_DWORD **)(a1 + 14264);
  if ( (unsigned int)(v6 - 458752) < 2 || v6 == 459776 || v6 == 459520 )
    v7 = *(_DWORD *)(a1 + 14248) & 0xFFFF0000
       | (((*(_DWORD *)(a1 + 14248) >> 8) & 0xF) << 12)
       | ((*(_DWORD *)(a1 + 14248) & 0xF) << 8);
  else
    v7 = (unsigned int)(v6 << 8);
  gmu_core_regwrite(a1, 129487, v7);
  gmu_core_regwrite(a1, 129485, *(_DWORD *)(*(_QWORD *)(a1 - 1760) + 184LL) & 0xFFFFF000 | 0xF);
  gmu_core_regwrite(a1, 128015, 1);
  gmu_core_regwrite(a1, 128000, 1);
  result = gmu_core_regwrite(a1, 128001, 1);
  if ( *(_BYTE *)(a1 + 20437) == 1 )
    return gmu_core_regrmw(a1, 129089, 4294967040LL, 420942592);
  return result;
}
