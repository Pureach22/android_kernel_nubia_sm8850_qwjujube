__int64 __fastcall clk_alpha_pll_hwfsm_disable(__int64 a1)
{
  __int64 v2; // x1
  __int64 v3; // x19
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
    if ( (*(_BYTE *)(a1 - 8) & 1) == 0
      || (result = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 128, 128, 0, 0, 0),
          !(_DWORD)result)
      && (result = wait_for_pll(v3, 0x10000000, 0, "offline"), !(_DWORD)result) )
    {
      result = regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), 0x100000, 0, 0, 0, 0);
      if ( !(_DWORD)result )
        result = wait_for_pll(v3, 0x40000000, 1, "disable");
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
