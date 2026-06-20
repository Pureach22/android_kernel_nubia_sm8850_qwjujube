__int64 __fastcall alpha_pll_lucid_5lpe_enable(__int64 a1)
{
  int v2; // w8
  __int64 v3; // x20
  __int64 v4; // x9
  __int64 result; // x0
  __int64 v6; // x21
  __int64 v7; // x1
  int v8; // [xsp+Ch] [xbp-14h] BYREF
  int v9; // [xsp+10h] [xbp-10h] BYREF
  int v10; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1 - 48;
  v2 = *(_DWORD *)(a1 - 48);
  v4 = *(_QWORD *)(a1 - 40);
  v8 = 0;
  result = regmap_read(*(_QWORD *)(a1 + 24), v2 + (unsigned int)*(unsigned __int8 *)(v4 + 5), &v8);
  if ( !(_DWORD)result )
  {
    if ( (v8 & 0x200000) != 0 )
    {
      result = clk_enable_regmap(a1);
      if ( !(_DWORD)result )
        result = wait_for_pll(v3, 0x80000000LL, 0, "enable");
    }
    else
    {
      v6 = *(_QWORD *)(a1 + 24);
      v7 = *(unsigned int *)(a1 - 48);
      v10 = 0;
      v9 = 0;
      regmap_read(v6, v7, &v10);
      regmap_read(v6, *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 19LL), &v9);
      result = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 4, 4, 0, 0, 0);
      if ( !(_DWORD)result )
      {
        regmap_write(
          *(_QWORD *)(a1 + 24),
          *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 19LL),
          1);
        result = wait_for_pll(v3, 0x80000000LL, 0, "enable");
        if ( !(_DWORD)result )
        {
          result = regmap_update_bits_base(
                     *(_QWORD *)(a1 + 24),
                     *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 5LL),
                     7,
                     7,
                     0,
                     0,
                     0);
          if ( !(_DWORD)result )
            result = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 1, 1, 0, 0, 0);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
