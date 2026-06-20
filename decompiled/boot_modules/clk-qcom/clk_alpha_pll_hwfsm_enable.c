__int64 __fastcall clk_alpha_pll_hwfsm_enable(__int64 a1)
{
  __int64 v2; // x1
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 result; // x0
  char v6; // w9
  __int64 v7; // x2
  int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1 - 48;
  v2 = *(unsigned int *)(a1 - 48);
  v4 = *(_QWORD *)(a1 + 24);
  v8 = 0;
  result = regmap_read(v4, v2, &v8);
  if ( !(_DWORD)result )
  {
    v6 = *(_BYTE *)(a1 - 8);
    v7 = v8 | 0x100000u;
    v8 |= 0x100000u;
    if ( (v6 & 1) != 0 )
    {
      v7 = (unsigned int)v7 & 0xFFFFFF7F;
      v8 = v7;
    }
    result = regmap_write(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 48), v7);
    if ( !(_DWORD)result )
    {
      __dsb(0xFu);
      result = wait_for_pll(v3, 0x40000000, 0, "enable");
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
