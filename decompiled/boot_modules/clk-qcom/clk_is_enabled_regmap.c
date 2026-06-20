__int64 __fastcall clk_is_enabled_regmap(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x1
  __int64 result; // x0
  int v5; // w8
  bool v6; // zf
  _BOOL4 v7; // w8
  unsigned int v8; // w9
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 24);
  v3 = *(unsigned int *)(a1 + 32);
  v9 = 0;
  result = regmap_read(v2, v3, &v9);
  if ( !(_DWORD)result )
  {
    v5 = *(_DWORD *)(a1 + 36) & v9;
    v6 = v5 == 0;
    v7 = v5 != 0;
    v8 = v6;
    if ( *(_BYTE *)(a1 + 40) == 1 )
      result = v8;
    else
      result = v7;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
