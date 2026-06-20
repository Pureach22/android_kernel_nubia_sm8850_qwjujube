__int64 __fastcall clk_zonda_pll_disable(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x1
  __int64 result; // x0
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 24);
  v3 = *(unsigned int *)(a1 - 48);
  v5 = 0;
  regmap_read(v2, v3, &v5);
  if ( (v5 & 0x100000) != 0 )
  {
    result = clk_disable_regmap(a1);
  }
  else
  {
    regmap_update_bits_base(v2, *(unsigned int *)(a1 - 48), 1, 0, 0, 0, 0);
    regmap_update_bits_base(
      v2,
      *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 5LL),
      15,
      0,
      0,
      0,
      0);
    regmap_update_bits_base(v2, *(unsigned int *)(a1 - 48), 6, 0, 0, 0, 0);
    result = regmap_write(v2, *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 19LL), 0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
