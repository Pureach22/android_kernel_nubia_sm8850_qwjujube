unsigned __int64 __fastcall _clk_rcg2_recalc_rate(__int64 a1, unsigned __int64 a2, unsigned int a3)
{
  int v3; // w22
  int v7; // w8
  char is_enabled; // w0
  unsigned int v9; // w8
  __int64 v10; // x23
  int v11; // w9
  int v12; // w10
  __int64 v13; // x0
  int v14; // w9
  bool v15; // w23
  unsigned int v16; // w9
  __int64 freq; // x0
  unsigned int v18; // w10
  _QWORD v20[2]; // [xsp+0h] [xbp-10h] BYREF

  v3 = (a3 >> 8) & 7;
  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(unsigned __int8 *)(a1 - 16);
  v20[0] = 0;
  if ( v7 != 1 )
    goto LABEL_8;
  if ( *(_BYTE *)(a1 + 155) != 1 )
  {
    if ( !v3 )
      goto LABEL_5;
LABEL_8:
    v9 = *(unsigned __int8 *)(a1 - 44);
    if ( *(_BYTE *)(a1 - 44) )
    {
      v10 = -1LL << v9;
      regmap_read(
        *(_QWORD *)(a1 + 24),
        *(_DWORD *)(a1 - 48) + (unsigned int)*(unsigned __int8 *)(a1 + 144) + 8,
        (char *)v20 + 4);
      v11 = *(_DWORD *)(a1 - 48);
      v12 = *(unsigned __int8 *)(a1 + 144);
      v13 = *(_QWORD *)(a1 + 24);
      HIDWORD(v20[0]) &= ~(_DWORD)v10;
      regmap_read(v13, (unsigned int)(v11 + v12 + 12), v20);
      v9 = HIDWORD(v20[0]);
      v14 = ~LODWORD(v20[0]) & ~(_DWORD)v10;
      v15 = (a3 & 0x3000) == 0;
      v16 = HIDWORD(v20[0]) + v14;
      LODWORD(v20[0]) = v16;
      if ( v3 )
        goto LABEL_16;
    }
    else
    {
      v16 = 0;
      v15 = 1;
      if ( v3 )
        goto LABEL_16;
    }
    if ( (*(_BYTE *)(a1 - 16) & 1) != 0 )
    {
      freq = qcom_find_freq(*(_QWORD *)(a1 - 8));
      if ( !freq )
      {
        a2 = -22;
        goto LABEL_24;
      }
      v16 = v20[0];
      v9 = HIDWORD(v20[0]);
      v18 = *(unsigned __int8 *)(freq + 9);
      if ( !*(_BYTE *)(freq + 9) )
      {
LABEL_18:
        if ( !v15 )
          a2 = a2 % v16 * v9 / v16 + a2 / v16 * v9;
        if ( *(_BYTE *)(a1 - 16) == 1 && !*(_QWORD *)(a1 - 24) )
          goto LABEL_22;
        goto LABEL_24;
      }
LABEL_17:
      a2 = 2 * (a2 % (v18 + 1)) / (v18 + 1) + 2 * (a2 / (v18 + 1));
      goto LABEL_18;
    }
LABEL_16:
    v18 = a3 & ~(unsigned int)(-1LL << *(_BYTE *)(a1 - 43));
    if ( !v18 )
      goto LABEL_18;
    goto LABEL_17;
  }
  is_enabled = clk_hw_is_enabled(a1);
  if ( v3 || (is_enabled & 1) != 0 )
    goto LABEL_8;
LABEL_5:
  a2 = *(_QWORD *)(a1 - 24);
  if ( !a2 )
  {
    a2 = cxo_f;
LABEL_22:
    *(_QWORD *)(a1 - 24) = a2;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return a2;
}
