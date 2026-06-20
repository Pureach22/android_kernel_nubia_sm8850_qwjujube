__int64 __fastcall clk_lucid_evo_pll_configure(unsigned int *a1, __int64 a2, int *a3)
{
  __int64 v6; // x8
  int v7; // w23
  __int64 v8; // x1
  int v9; // w22
  __int64 result; // x0
  __int64 v11; // x1
  int v12; // w22
  unsigned __int8 *v13; // x8
  int v14; // w8
  int v15; // [xsp+Ch] [xbp-14h] BYREF
  int v16; // [xsp+10h] [xbp-10h] BYREF
  int v17; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *((_QWORD *)a1 + 1);
  v15 = 0;
  v7 = *a3;
  regmap_update_bits_base(a2, *a1 + *(unsigned __int8 *)(v6 + 5), 7, 7, 0, 0, 0);
  v8 = *a1;
  v17 = 0;
  v16 = 0;
  v9 = regmap_read(a2, v8, &v17);
  result = regmap_read(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 19LL), &v16);
  if ( (unsigned int)result | v9 || (v16 & 1) == 0 || (v17 & 1) == 0 )
  {
    if ( (a1[10] & 0x20) != 0 )
      regmap_update_bits_base(a2, *a1, 4, 0, 0, 0, 0);
    result = regmap_read(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 1LL), &v15);
    v15 = (unsigned __int16)v15;
    if ( !(_WORD)v15 )
    {
      v11 = *a1;
      v17 = 0;
      v16 = 0;
      v12 = regmap_read(a2, v11, &v17);
      result = regmap_read(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 19LL), &v16);
      if ( (unsigned int)result | v12 || (v16 & 1) == 0 || (v17 & 1) == 0 )
      {
        v13 = *((unsigned __int8 **)a1 + 1);
        if ( v13[1] )
        {
          regmap_write(a2, *a1 + v13[1], v7 | 0x44440000u);
          v13 = *((unsigned __int8 **)a1 + 1);
        }
        if ( v13[3] )
        {
          regmap_write(a2, *a1 + v13[3], (unsigned int)a3[3]);
          v13 = *((unsigned __int8 **)a1 + 1);
        }
        if ( v13[8] )
        {
          regmap_write(a2, *a1 + v13[8], (unsigned int)a3[5]);
          v13 = *((unsigned __int8 **)a1 + 1);
        }
        if ( v13[9] )
        {
          regmap_write(a2, *a1 + v13[9], (unsigned int)a3[6]);
          v13 = *((unsigned __int8 **)a1 + 1);
        }
        if ( v13[10] )
        {
          regmap_write(a2, *a1 + v13[10], (unsigned int)a3[7]);
          v13 = *((unsigned __int8 **)a1 + 1);
        }
        if ( v13[5] )
        {
          regmap_write(a2, *a1 + v13[5], a3[9] | 7u);
          v13 = *((unsigned __int8 **)a1 + 1);
        }
        if ( v13[6] )
        {
          regmap_write(a2, *a1 + v13[6], (unsigned int)a3[10]);
          v13 = *((unsigned __int8 **)a1 + 1);
        }
        if ( v13[12] )
        {
          regmap_write(a2, *a1 + v13[12], (unsigned int)a3[12]);
          v13 = *((unsigned __int8 **)a1 + 1);
        }
        if ( v13[13] )
        {
          regmap_write(a2, *a1 + v13[13], (unsigned int)a3[14]);
          v13 = *((unsigned __int8 **)a1 + 1);
        }
        if ( v13[14] )
        {
          regmap_write(a2, *a1 + v13[14], (unsigned int)a3[16]);
          v13 = *((unsigned __int8 **)a1 + 1);
        }
        v14 = v13[15];
        if ( v14 )
          regmap_write(a2, *a1 + v14, (unsigned int)a3[17]);
        result = regmap_update_bits_base(a2, *a1, 1, 0, 0, 0, 0);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
