__int64 __fastcall alpha_pll_lucid_evo_disable(__int64 a1, char a2)
{
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 result; // x0
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 - 40);
  v7 = 0;
  v5 = *(_QWORD *)(a1 + 24);
  result = regmap_read(v5, *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(v4 + 5), &v7);
  if ( !(_DWORD)result )
  {
    if ( (v7 & 0x2000000) != 0 )
    {
      result = clk_disable_regmap(a1);
    }
    else
    {
      result = regmap_update_bits_base(v5, *(unsigned int *)(a1 - 48), 1, 0, 0, 0, 0);
      if ( !(_DWORD)result )
      {
        result = regmap_write(
                   v5,
                   *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 19LL),
                   0);
        if ( (a2 & 1) != 0 || (*(_BYTE *)(a1 - 8) & 0x20) != 0 )
          result = regmap_update_bits_base(v5, *(unsigned int *)(a1 - 48), 4, 0, 0, 0, 0);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
