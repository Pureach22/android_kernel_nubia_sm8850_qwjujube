unsigned __int64 __fastcall clk_pll_recalc_rate(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x1
  int v6; // w9
  int v7; // w10
  unsigned __int64 v8; // x21
  __int64 v10; // [xsp+8h] [xbp-18h] BYREF
  int v11; // [xsp+10h] [xbp-10h] BYREF
  int v12; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 24);
  v5 = *(unsigned int *)(a1 - 40);
  v12 = 0;
  v11 = 0;
  v10 = 0;
  regmap_read(v4, v5, &v12);
  regmap_read(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 36), &v11);
  regmap_read(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 32), (char *)&v10 + 4);
  v7 = HIDWORD(v10);
  v6 = v11;
  v8 = (v12 & 0x3FF) * a2;
  v12 &= 0x3FFu;
  HIDWORD(v10) &= 0x7FFFFu;
  v11 &= 0x7FFFFu;
  if ( HIDWORD(v10) )
    v8 += (*(_QWORD *)&v6 & 0x7FFFFuLL) * a2 / (*(_QWORD *)&v7 & 0x7FFFFuLL);
  if ( *(_BYTE *)(a1 - 15) )
  {
    regmap_read(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 28), &v10);
    v8 /= (((unsigned int)v10 >> *(_BYTE *)(a1 - 14)) & ~(unsigned int)(-1LL << *(_BYTE *)(a1 - 15))) + 1;
  }
  _ReadStatusReg(SP_EL0);
  return v8;
}
