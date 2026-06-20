__int64 __fastcall gen7_legacy_snapshot_registers(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v4; // x9
  __int64 v6; // x20
  __int64 v7; // x21
  __int64 v8; // x22

  v4 = a4[1];
  if ( v4 )
  {
    v6 = a1;
    v7 = a2;
    v8 = a3;
    kgsl_regmap_write(a1 + 13200, *(unsigned int *)(v4 + 8));
    a1 = v6;
    a2 = v7;
    a3 = v8;
  }
  return adreno_snapshot_registers_v2(a1, a2, a3, *a4);
}
