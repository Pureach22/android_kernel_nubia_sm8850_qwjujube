__int64 __fastcall a6xx_counter_load(__int64 result, __int64 a2)
{
  int *v2; // x8
  int v3; // w19
  int v4; // w21
  const char *v5; // x8
  __int64 v6; // x22
  __int64 v7; // x23
  int v8; // w0
  int v9; // w8
  __int64 v10; // x22
  __int64 v11; // x23

  v2 = *(int **)(result + 14264);
  v3 = *(_DWORD *)(a2 + 20);
  v4 = *v2;
  if ( *v2 != 650 && v4 != 660 )
  {
    v5 = *((const char **)v2 + 3);
    if ( !v5 || (v6 = result, v7 = a2, v8 = strcmp(v5, "qcom,adreno-gpu-a642l"), a2 = v7, v9 = v8, result = v6, v9) )
    {
      if ( v4 != 643 && v4 != 662 )
      {
        v10 = result;
        v11 = a2;
        kgsl_regmap_write(result + 13200, *(unsigned int *)(a2 + 32));
        kgsl_regmap_write(v10 + 13200, *(unsigned int *)(v11 + 36));
        return kgsl_regmap_write(v10 + 13200, (unsigned int)(1 << v3));
      }
    }
  }
  return result;
}
