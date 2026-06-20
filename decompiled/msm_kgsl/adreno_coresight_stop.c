__int64 __fastcall adreno_coresight_stop(__int64 result)
{
  unsigned __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x21
  unsigned int v5; // w22
  unsigned int *v6; // x25
  unsigned __int64 v7; // x8
  __int64 v8; // x20
  unsigned int v9; // w21
  unsigned int *v10; // x24

  v1 = *(_QWORD *)(result + 20664);
  v2 = result;
  v3 = result + 20480;
  if ( v1 )
  {
    if ( v1 <= 0xFFFFFFFFFFFFF000LL && *(_BYTE *)(result + 20688) == 1 )
    {
      v4 = *(_QWORD *)(result + 20672);
      if ( *(_DWORD *)(v4 + 8) )
      {
        v5 = 0;
        do
        {
          v6 = (unsigned int *)(*(_QWORD *)v4 + 12LL * (int)v5);
          v6[2] = kgsl_regmap_read(v2 + 13200, *v6);
          result = kgsl_regmap_write(v2 + 13200, 0, *(_DWORD *)(*(_QWORD *)v4 + 12LL * (int)v5++));
        }
        while ( v5 < *(_DWORD *)(v4 + 8) );
      }
    }
  }
  v7 = *(_QWORD *)(v2 + 20696);
  if ( v7 )
  {
    if ( v7 <= 0xFFFFFFFFFFFFF000LL && *(_BYTE *)(v3 + 240) == 1 )
    {
      v8 = *(_QWORD *)(v2 + 20704);
      if ( *(_DWORD *)(v8 + 8) )
      {
        v9 = 0;
        do
        {
          v10 = (unsigned int *)(*(_QWORD *)v8 + 12LL * (int)v9);
          v10[2] = kgsl_regmap_read(v2 + 13200, *v10);
          result = kgsl_regmap_write(v2 + 13200, 0, *(_DWORD *)(*(_QWORD *)v8 + 12LL * (int)v9++));
        }
        while ( v9 < *(_DWORD *)(v8 + 8) );
      }
    }
  }
  return result;
}
