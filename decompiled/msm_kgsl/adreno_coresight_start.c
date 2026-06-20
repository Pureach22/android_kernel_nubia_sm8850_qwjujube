__int64 __fastcall adreno_coresight_start(__int64 result)
{
  unsigned __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x21
  unsigned int v5; // w22
  unsigned __int64 v6; // x8
  __int64 v7; // x20
  unsigned int v8; // w21

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
          result = kgsl_regmap_write(
                     v2 + 13200,
                     *(_DWORD *)(*(_QWORD *)v4 + 12LL * (int)v5 + 8),
                     *(_DWORD *)(*(_QWORD *)v4 + 12LL * (int)v5));
          ++v5;
        }
        while ( v5 < *(_DWORD *)(v4 + 8) );
      }
    }
  }
  v6 = *(_QWORD *)(v2 + 20696);
  if ( v6 )
  {
    if ( v6 <= 0xFFFFFFFFFFFFF000LL && *(_BYTE *)(v3 + 240) == 1 )
    {
      v7 = *(_QWORD *)(v2 + 20704);
      if ( *(_DWORD *)(v7 + 8) )
      {
        v8 = 0;
        do
        {
          result = kgsl_regmap_write(
                     v2 + 13200,
                     *(_DWORD *)(*(_QWORD *)v7 + 12LL * (int)v8 + 8),
                     *(_DWORD *)(*(_QWORD *)v7 + 12LL * (int)v8));
          ++v8;
        }
        while ( v8 < *(_DWORD *)(v7 + 8) );
      }
    }
  }
  return result;
}
