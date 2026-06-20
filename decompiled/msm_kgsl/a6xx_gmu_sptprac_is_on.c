bool __fastcall a6xx_gmu_sptprac_is_on(__int64 a1)
{
  _DWORD *v2; // x8
  _BOOL8 result; // x0
  bool v4; // cc
  int v5; // w8
  char v7; // w0
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD **)(a1 + 14264);
  v8 = 0;
  result = 1;
  LODWORD(v2) = *v2 - 615;
  v4 = (unsigned int)v2 > 0xF;
  v5 = (1 << (char)v2) & 0x801B;
  if ( !v4 && v5 != 0 )
  {
    if ( (unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a1 + 11168) + 760LL)) )
    {
      v7 = kgsl_regmap_read(a1 + 13200);
    }
    else
    {
      gmu_core_regread(a1, 129232, &v8);
      v7 = v8;
    }
    result = (v7 & 0x14) == 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
