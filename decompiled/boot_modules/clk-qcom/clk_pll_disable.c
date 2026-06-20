__int64 __fastcall clk_pll_disable(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x1
  __int64 result; // x0
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 24);
  v3 = *(unsigned int *)(a1 - 24);
  v5 = 0;
  result = regmap_read(v2, v3, &v5);
  if ( (v5 & 0x100000) == 0 )
    result = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 24), 7, 0, 0, 0, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
