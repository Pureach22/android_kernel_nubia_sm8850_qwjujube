__int64 __fastcall disable_8960(__int64 a1)
{
  int v2; // w20
  __int64 v3; // x0
  __int64 result; // x0
  __int64 v5; // x0
  int v6; // w9
  unsigned int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 8);
  v3 = *(_QWORD *)(a1 + 16);
  v7 = 0;
  result = regmap_read(v3, 13856, &v7);
  if ( !(_DWORD)result )
  {
    v5 = *(_QWORD *)(a1 + 16);
    if ( *(_DWORD *)(a1 + 8) <= 1u )
      v6 = -16777226;
    else
      v6 = -67108874;
    v7 &= v6 & ((8 * (0xFFFFFFFFFFFFFFFFLL >> -(char)v2)) ^ 0xFFFFFFFE);
    result = regmap_write(v5, 13856, v7);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
