unsigned __int64 __fastcall clk_trion_pll_recalc_rate(__int64 a1, __int64 a2)
{
  unsigned __int8 *v4; // x8
  int v5; // w21
  char v6; // w10
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 **)(a1 - 40);
  v8[0] = 0;
  v5 = v4[4] - v4[3];
  regmap_read(*(_QWORD *)(a1 + 24), *(_DWORD *)(a1 - 48) + (unsigned int)v4[1], (char *)v8 + 4);
  regmap_read(
    *(_QWORD *)(a1 + 24),
    *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(*(_QWORD *)(a1 - 40) + 3LL),
    v8);
  v6 = 16;
  _ReadStatusReg(SP_EL0);
  if ( v5 == 4 )
    v6 = 32;
  return 1000 * (((((unsigned __int64)LODWORD(v8[0]) * a2) >> v6) + HIDWORD(v8[0]) * a2 + 999) / 0x3E8);
}
