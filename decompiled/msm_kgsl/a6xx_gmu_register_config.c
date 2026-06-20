__int64 __fastcall a6xx_gmu_register_config(__int64 a1)
{
  __int64 v1; // x8
  unsigned __int64 v3; // x8
  unsigned int v4; // w23
  __int64 v5; // x8
  __int64 v6; // x2
  const char *v7; // x0
  unsigned int v8; // w24
  int v9; // w0
  __int64 result; // x0
  __int64 v11; // x3
  int v12; // w8

  v1 = *(_QWORD *)(a1 + 14264);
  *(_DWORD *)(a1 - 368) = 0;
  if ( *(_BYTE *)(v1 + 156) == 1 )
  {
    gmu_core_regwrite(a1, 129265, 1);
    gmu_core_regwrite(a1, 129264, 1);
  }
  gmu_core_regwrite(a1, 129484, 1);
  gmu_core_regwrite(a1, 129052, 0);
  gmu_core_regwrite(a1, 129025, 2);
  gmu_core_regwrite(a1, 129413, *(unsigned int *)(*(_QWORD *)(a1 - 1608) + 184LL));
  gmu_core_regwrite(a1, 129412, 1);
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 33LL) & 0x80) != 0 )
    gmu_core_regwrite(a1, 146179, 2);
  gmu_core_regwrite(a1, 146193, 2157971616LL);
  gmu_core_regwrite(a1, 129069, 16466);
  if ( **(_DWORD **)(a1 + 14264) != 630 )
    kgsl_regmap_write(a1 + 13200, 0);
  v3 = *(_QWORD *)(a1 + 8664);
  if ( v3 && v3 <= 0xFFFFFFFFFFFFF000LL )
    gmu_core_regwrite(a1, 129488, *(unsigned int *)(v3 + 184));
  gmu_core_regwrite(a1, 129281, *(unsigned int *)(a1 - 372));
  v4 = *(_DWORD *)(a1 + 14248);
  v5 = *(_QWORD *)(a1 + 14264);
  v6 = v4 & 0xFFFF0000 | (((v4 >> 8) & 0xF) << 12) | ((v4 & 0xF) << 8);
  if ( *(_DWORD *)v5 == 660 )
  {
    v7 = *(const char **)(v5 + 24);
    if ( v7 )
    {
      v8 = *(_DWORD *)(a1 + 14248) & 0xFFFF0000
         | (((*(_DWORD *)(a1 + 14248) >> 8) & 0xF) << 12)
         | ((*(_DWORD *)(a1 + 14248) & 0xF) << 8);
      v9 = strcmp(v7, "qcom,adreno-gpu-a660-shima");
      v6 = v8;
      if ( !v9 )
        v6 = v8 | (v4 >> 4 << 28);
    }
  }
  gmu_core_regwrite(a1, 129410, v6);
  gmu_core_regwrite(a1, 129280, *(_DWORD *)(*(_QWORD *)(a1 - 1624) + 184LL) & 0xFFFFF000 | 0xF);
  gmu_core_regwrite(a1, 128015, 1);
  gmu_core_regwrite(a1, 128000, 1);
  gmu_core_regwrite(a1, 128001, 1);
  gmu_core_regwrite(a1, 129216, 163841024);
  if ( *(_DWORD *)(a1 - 448) == 3 )
  {
    gmu_core_regwrite(a1, 129217, *(_DWORD *)(a1 + 24036) | 0xA0000u);
    gmu_core_regrmw(a1, 129216, 3, 3);
    gmu_core_regwrite(a1, 129218, *(_DWORD *)(a1 + 24036) | 0xA0000u);
    gmu_core_regrmw(a1, 129216, 5, 5);
  }
  result = gmu_core_regrmw(a1, 129256, 3857, 3857);
  if ( (*(_BYTE *)(a1 + 20432) & 1) != 0 )
  {
    v11 = 253104128;
    v12 = **(_DWORD **)(a1 + 14264);
    if ( (unsigned int)(v12 - 620) >= 3 )
    {
      if ( v12 == 650 )
        v11 = 253104128;
      else
        v11 = 420810752;
    }
  }
  else
  {
    if ( (*(_BYTE *)(a1 + 20437) & 1) == 0 )
      return result;
    v11 = 420942592;
  }
  gmu_core_regrmw(a1, 129089, 4294967040LL, v11);
  return gmu_core_regwrite(a1, 146198, 1);
}
