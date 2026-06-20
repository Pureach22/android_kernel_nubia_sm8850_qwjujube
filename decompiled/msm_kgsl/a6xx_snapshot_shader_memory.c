__int64 __fastcall a6xx_snapshot_shader_memory(__int64 a1, _DWORD *a2, unsigned __int64 a3, __int64 a4)
{
  _DWORD *v4; // x21
  _DWORD *v6; // x20
  __int64 result; // x0
  __int64 v8; // x8
  int *v9; // x8
  int v10; // w22
  const char *v11; // x0
  _DWORD *v12; // x23
  __int64 v13; // x24
  int v14; // w0
  int v15; // w8
  __int64 v16; // x23

  v4 = *(_DWORD **)a4;
  v6 = a2 + 3;
  if ( (crash_dump_valid & 1) != 0 )
  {
    if ( 4 * (unsigned __int64)(unsigned int)v4[1] + 12 > a3 )
    {
      if ( (unsigned int)__ratelimit(&a6xx_snapshot_shader_memory__rs, "a6xx_snapshot_shader_memory") )
        goto LABEL_20;
      return 0;
    }
    *a2 = *v4;
    a2[1] = *(_DWORD *)(a4 + 8);
    a2[2] = v4[1];
    memcpy(
      a2 + 3,
      (const void *)(*(_QWORD *)(a6xx_crashdump_registers + 8) + *(_QWORD *)(a4 + 16)),
      4LL * (unsigned int)v4[1]);
    v8 = (unsigned int)v4[1];
    return 4 * v8 + 12;
  }
  if ( *(_BYTE *)(a1 + 11306) != 1 )
    return 0;
  if ( 4 * (unsigned __int64)(unsigned int)v4[1] + 12 > a3 )
  {
    if ( (unsigned int)__ratelimit(&a6xx_legacy_snapshot_shader__rs, "a6xx_legacy_snapshot_shader") )
LABEL_20:
      dev_err(*(_QWORD *)a1, "snapshot: not enough snapshot memory for section %s\n", "SHADER MEMORY");
    return 0;
  }
  v9 = *(int **)(a1 + 14264);
  v10 = *v9;
  if ( *v9 != 660 )
  {
    v11 = *((const char **)v9 + 3);
    if ( !v11 || (v12 = a2, v13 = a4, v14 = strcmp(v11, "qcom,adreno-gpu-a642l"), a2 = v12, a4 = v13, v14) )
    {
      if ( v10 != 643 && v10 != 662 )
      {
        v15 = *v4;
LABEL_22:
        *a2 = v15;
        a2[1] = *(_DWORD *)(a4 + 8);
        a2[2] = v4[1];
        kgsl_regmap_write(a1 + 13200, (unsigned int)(*(_DWORD *)(a4 + 8) | (*v4 << 8)));
        __dsb(0xFu);
        if ( !v4[1] )
          return 12;
        v16 = 0;
        do
        {
          v6[v16++] = kgsl_regmap_read(a1 + 13200);
          v8 = (unsigned int)v4[1];
        }
        while ( (unsigned int)v16 < (unsigned int)v8 );
        return 4 * v8 + 12;
      }
    }
  }
  v15 = *v4;
  result = 0;
  if ( *v4 != 41 && v15 != 51 )
    goto LABEL_22;
  return result;
}
