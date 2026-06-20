unsigned __int64 __fastcall clk_alpha_pll_postdiv_fabia_recalc_rate(__int64 a1, unsigned __int64 a2)
{
  __int64 v4; // x8
  unsigned __int64 result; // x0
  unsigned __int64 v6; // x9
  unsigned int v7; // w10
  __int64 v8; // x11
  unsigned __int64 v9; // x12
  unsigned __int64 v10; // x8
  unsigned int v11; // w13
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 - 8);
  v12 = 0;
  LODWORD(result) = regmap_read(
                      *(_QWORD *)(a1 + 24),
                      *(_DWORD *)(a1 - 16) + (unsigned int)*(unsigned __int8 *)(v4 + 5),
                      &v12);
  if ( (_DWORD)result )
  {
    result = (int)result;
  }
  else
  {
    v6 = *(_QWORD *)(a1 + 160);
    v7 = (v12 >> *(_DWORD *)(a1 + 144)) & ~(unsigned int)(-1LL << *(_BYTE *)(a1 - 12));
    v12 = v7;
    if ( v6 )
    {
      v8 = *(_QWORD *)(a1 + 152);
      v9 = 0;
      v10 = 1;
      v11 = 1;
      while ( *(_DWORD *)(v8 + 8 * v9) != v7 )
      {
        v9 = v11++;
        if ( v6 <= v9 )
          goto LABEL_10;
      }
      v10 = *(unsigned int *)(v8 + 8 * v9 + 4);
    }
    else
    {
      v10 = 1;
    }
LABEL_10:
    result = a2 / v10;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
