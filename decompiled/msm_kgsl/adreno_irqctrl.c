__int64 __fastcall adreno_irqctrl(__int64 result, int a2)
{
  unsigned int v2; // w8
  _QWORD *v3; // x19
  __int64 v4; // x20
  int v5; // w21
  __int64 (__fastcall *v6)(__int64, _BOOL8); // x8
  _BOOL8 v7; // x1

  v2 = *(_DWORD *)(result + 20888);
  if ( v2 )
  {
    v3 = *(_QWORD **)(*(_QWORD *)(result + 14264) + 40LL);
    if ( *(_DWORD *)(*v3 + 64LL) <= 0xFFFFFFFD )
    {
      v4 = result;
      if ( !a2 )
        v2 = 0;
      v5 = a2;
      kgsl_regmap_write(result + 13200, v2);
      a2 = v5;
      result = v4;
    }
    v6 = (__int64 (__fastcall *)(__int64, _BOOL8))v3[32];
    if ( v6 )
    {
      v7 = a2 != 0;
      if ( *((_DWORD *)v6 - 1) != 1163613936 )
        __break(0x8228u);
      return v6(result, v7);
    }
  }
  return result;
}
