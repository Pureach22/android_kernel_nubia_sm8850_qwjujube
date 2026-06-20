__int64 __fastcall clk_pll_set_rate(__int64 a1, unsigned __int64 a2)
{
  unsigned __int64 *v2; // x20
  unsigned __int64 v3; // x8
  unsigned __int64 v4; // t1
  __int64 v5; // x8
  __int64 v6; // x1
  __int64 v8; // x8
  int v9; // w21
  __int64 v10; // x0
  __int64 v11; // x1
  __int64 v12; // x22
  __int64 result; // x0
  int v14; // [xsp+0h] [xbp-10h] BYREF
  int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int64 **)(a1 - 8);
  if ( !v2 )
    goto LABEL_13;
  v3 = *v2;
  if ( !*v2 )
    goto LABEL_13;
  while ( v3 < a2 )
  {
    v4 = v2[3];
    v2 += 3;
    v3 = v4;
    if ( !v4 )
      goto LABEL_13;
  }
  if ( v2 )
  {
    v5 = *(_QWORD *)(a1 + 24);
    v6 = *(unsigned int *)(a1 - 24);
    v14 = 0;
    regmap_read(v5, v6, &v14);
    v8 = a1;
    v9 = v14 & 7;
    if ( v9 == 7 )
    {
      v10 = *(_QWORD *)(a1 + 24);
      v11 = *(unsigned int *)(a1 - 24);
      v15 = 0;
      regmap_read(v10, v11, &v15);
      if ( (v15 & 0x100000) == 0 )
        regmap_update_bits_base(*(_QWORD *)(a1 + 24), *(unsigned int *)(a1 - 24), 7, 0, 0, 0, 0);
      v8 = a1;
    }
    v12 = v8;
    regmap_update_bits_base(
      *(_QWORD *)(v8 + 24),
      *(unsigned int *)(v8 - 40),
      1023,
      *((unsigned __int16 *)v2 + 4),
      0,
      0,
      0);
    regmap_update_bits_base(
      *(_QWORD *)(v12 + 24),
      *(unsigned int *)(v12 - 36),
      0x7FFFF,
      *((unsigned __int16 *)v2 + 5),
      0,
      0,
      0);
    regmap_update_bits_base(
      *(_QWORD *)(v12 + 24),
      *(unsigned int *)(v12 - 32),
      0x7FFFF,
      *((unsigned __int16 *)v2 + 6),
      0,
      0,
      0);
    regmap_write(*(_QWORD *)(v12 + 24), *(unsigned int *)(v12 - 28), *((unsigned int *)v2 + 4));
    result = 0;
    if ( v9 == 7 )
    {
      clk_pll_enable(a1);
      result = 0;
    }
  }
  else
  {
LABEL_13:
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
