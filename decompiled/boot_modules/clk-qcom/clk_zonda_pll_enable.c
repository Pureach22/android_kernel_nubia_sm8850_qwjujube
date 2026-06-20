__int64 __fastcall clk_zonda_pll_enable(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x1
  __int64 v4; // x21
  const char *v5; // x3
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 result; // x0
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 24);
  v4 = a1 - 48;
  v3 = *(unsigned int *)(a1 - 48);
  v9 = 0;
  regmap_read(v2, v3, &v9);
  if ( (v9 & 0x100000) != 0 )
  {
    result = clk_enable_regmap(a1);
    if ( !(_DWORD)result )
      result = wait_for_pll(v4, 0x40000000, 0, "enable");
  }
  else
  {
    regmap_update_bits_base(v2, *(unsigned int *)(a1 - 48), 2, 2, 0, 0, 0);
    _const_udelay(4295);
    regmap_update_bits_base(v2, *(unsigned int *)(a1 - 48), 4, 4, 0, 0, 0);
    regmap_write(v2, *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 19LL), 1);
    regmap_read(v2, *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 12LL), &v9);
    if ( (v9 & 0x10000) != 0 )
    {
      v5 = "freq enable";
      v6 = v4;
      v7 = 0x20000000;
    }
    else
    {
      v5 = "enable";
      v6 = v4;
      v7 = 0x80000000LL;
    }
    result = wait_for_pll(v6, v7, 0, v5);
    if ( !(_DWORD)result )
    {
      regmap_update_bits_base(
        v2,
        *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 5LL),
        15,
        15,
        0,
        0,
        0);
      regmap_update_bits_base(v2, *(unsigned int *)(a1 - 48), 1, 1, 0, 0, 0);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
