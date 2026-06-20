__int64 __fastcall clk_trion_pll_enable(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x1
  unsigned int *v4; // x19
  __int64 result; // x0
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 24);
  v4 = (unsigned int *)(a1 - 48);
  v3 = *(unsigned int *)(a1 - 48);
  v6 = 0;
  result = regmap_read(v2, v3, &v6);
  if ( !(_DWORD)result )
  {
    if ( (v6 & 0x100000) != 0 )
    {
      result = clk_enable_regmap(a1);
      if ( !(_DWORD)result )
        result = wait_for_pll(v4, 0x40000000, 0, "enable");
    }
    else
    {
      regmap_write(v2, *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 19LL), 1);
      result = wait_for_pll(v4, 0x80000000LL, 0, "enable");
      if ( !(_DWORD)result )
      {
        result = regmap_update_bits_base(
                   v2,
                   *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 5LL),
                   7,
                   7,
                   0,
                   0,
                   0);
        if ( !(_DWORD)result )
          result = regmap_update_bits_base(v2, *v4, 1, 1, 0, 0, 0);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
