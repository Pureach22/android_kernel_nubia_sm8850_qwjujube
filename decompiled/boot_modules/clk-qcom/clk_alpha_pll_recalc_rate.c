unsigned __int64 __fastcall clk_alpha_pll_recalc_rate(__int64 a1, __int64 a2)
{
  unsigned __int8 *v4; // x8
  int v5; // w11
  __int64 v6; // x0
  int v7; // w21
  unsigned __int64 v8; // x8
  char v9; // w10
  __int64 v11; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v12; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v13; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 **)(a1 - 40);
  v13 = 0;
  v5 = *(_DWORD *)(a1 - 48);
  v12 = 0;
  v6 = *(_QWORD *)(a1 + 24);
  v11 = 0;
  v7 = v4[4] - v4[3];
  regmap_read(v6, v5 + (unsigned int)v4[1], &v13);
  regmap_read(
    *(_QWORD *)(a1 + 24),
    *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 5LL),
    &v11);
  LODWORD(v8) = 0;
  if ( (v11 & 0x1000000) != 0 )
  {
    regmap_read(
      *(_QWORD *)(a1 + 24),
      *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 3LL),
      &v12);
    if ( v7 == 4 )
    {
      regmap_read(
        *(_QWORD *)(a1 + 24),
        *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 4LL),
        (char *)&v11 + 4);
      v8 = (v12 | ((unsigned __int64)HIDWORD(v11) << 32)) >> 8;
    }
    else
    {
      LODWORD(v8) = (unsigned __int16)v12;
    }
  }
  v9 = 16;
  _ReadStatusReg(SP_EL0);
  if ( v7 == 4 )
    v9 = 32;
  return 1000 * (((((unsigned __int64)(unsigned int)v8 * a2) >> v9) + v13 * a2 + 999) / 0x3E8);
}
