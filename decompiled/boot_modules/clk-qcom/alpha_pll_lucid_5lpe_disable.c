__int64 __fastcall alpha_pll_lucid_5lpe_disable(__int64 a1)
{
  __int64 v2; // x8
  __int64 result; // x0
  int v4; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 - 40);
  v4 = 0;
  result = regmap_read(*(_QWORD *)(a1 + 24), *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(v2 + 5), &v4);
  if ( !(_DWORD)result )
  {
    if ( (v4 & 0x200000) != 0 )
    {
      result = clk_disable_regmap(a1);
    }
    else
    {
      result = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 1, 0, 0, 0, 0);
      if ( !(_DWORD)result )
      {
        result = regmap_update_bits_base(
                   *(_QWORD *)(a1 + 24),
                   *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 5LL),
                   7,
                   0,
                   0,
                   0,
                   0);
        if ( !(_DWORD)result )
        {
          result = regmap_write(
                     *(_QWORD *)(a1 + 24),
                     *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 19LL),
                     0);
          if ( (*(_BYTE *)(a1 - 8) & 0x20) != 0 )
            result = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 4, 0, 0, 0, 0);
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
