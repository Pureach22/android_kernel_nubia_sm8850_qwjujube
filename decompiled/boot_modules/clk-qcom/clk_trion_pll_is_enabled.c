__int64 __fastcall clk_trion_pll_is_enabled(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x1
  int v4; // w0
  int v5; // w8
  __int64 result; // x0
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 24);
  v3 = *(unsigned int *)(a1 - 48);
  v7[0] = 0;
  v4 = regmap_read(v2, v3, (char *)v7 + 4);
  v5 = regmap_read(v2, *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 19LL), v7) | v4;
  result = 0;
  if ( !v5 )
    result = v7[0] & BYTE4(v7[0]) & 1;
  _ReadStatusReg(SP_EL0);
  return result;
}
