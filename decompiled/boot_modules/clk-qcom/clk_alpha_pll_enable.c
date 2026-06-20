__int64 __fastcall clk_alpha_pll_enable(__int64 a1)
{
  __int64 v2; // x1
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 result; // x0
  int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1 - 48;
  v2 = *(unsigned int *)(a1 - 48);
  v4 = *(_QWORD *)(a1 + 24);
  v6 = 0;
  result = regmap_read(v4, v2, &v6);
  if ( !(_DWORD)result )
  {
    if ( (v6 & 0x100000) != 0 )
    {
      result = clk_enable_regmap(a1);
      if ( !(_DWORD)result )
        result = wait_for_pll(v3, 0x40000000, 0, "enable");
    }
    else if ( (~v6 & 7) != 0 )
    {
      result = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 2, 2, 0, 0, 0);
      if ( !(_DWORD)result )
      {
        __dsb(0xFu);
        _const_udelay(21475);
        result = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 4, 4, 0, 0, 0);
        if ( !(_DWORD)result )
        {
          result = wait_for_pll(v3, 0x80000000LL, 0, "enable");
          if ( !(_DWORD)result )
          {
            result = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 1, 1, 0, 0, 0);
            __dsb(0xFu);
          }
        }
      }
    }
    else
    {
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
