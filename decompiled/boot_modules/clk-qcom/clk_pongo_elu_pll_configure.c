__int64 __fastcall clk_pongo_elu_pll_configure(unsigned int *a1, __int64 a2, unsigned int *a3)
{
  __int64 v6; // x8
  unsigned int v7; // w22
  __int64 v8; // x1
  int v9; // w23
  __int64 result; // x0
  unsigned __int8 *v11; // x8
  int v12; // w8
  int v13; // [xsp+Ch] [xbp-14h] BYREF
  int v14; // [xsp+10h] [xbp-10h] BYREF
  int v15; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *((_QWORD *)a1 + 1);
  v13 = 0;
  v7 = *a3;
  regmap_update_bits_base(a2, *a1 + *(unsigned __int8 *)(v6 + 5), 3, 3, 0, 0, 0);
  v8 = *a1;
  v15 = 0;
  v14 = 0;
  v9 = regmap_read(a2, v8, &v15);
  result = regmap_read(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 19LL), &v14);
  if ( (unsigned int)result | v9 || (v14 & 1) == 0 || (v15 & 1) == 0 )
  {
    result = regmap_read(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 1LL), &v13);
    v13 &= 0xFFFu;
    if ( !v13 )
    {
      v11 = *((unsigned __int8 **)a1 + 1);
      if ( v11[1] )
      {
        regmap_write(a2, *a1 + v11[1], v7);
        v11 = *((unsigned __int8 **)a1 + 1);
      }
      if ( v11[3] )
      {
        regmap_write(a2, *a1 + v11[3], a3[3]);
        v11 = *((unsigned __int8 **)a1 + 1);
      }
      if ( v11[8] )
      {
        regmap_write(a2, *a1 + v11[8], a3[5]);
        v11 = *((unsigned __int8 **)a1 + 1);
      }
      if ( v11[9] )
      {
        regmap_write(a2, *a1 + v11[9], a3[6]);
        v11 = *((unsigned __int8 **)a1 + 1);
      }
      if ( v11[10] )
      {
        regmap_write(a2, *a1 + v11[10], a3[7]);
        v11 = *((unsigned __int8 **)a1 + 1);
      }
      if ( v11[11] )
      {
        regmap_write(a2, *a1 + v11[11], a3[8]);
        v11 = *((unsigned __int8 **)a1 + 1);
      }
      if ( v11[5] )
      {
        regmap_write(a2, *a1 + v11[5], a3[9] | 3);
        v11 = *((unsigned __int8 **)a1 + 1);
      }
      if ( v11[6] )
      {
        regmap_write(a2, *a1 + v11[6], a3[10]);
        v11 = *((unsigned __int8 **)a1 + 1);
      }
      if ( v11[12] )
      {
        regmap_write(a2, *a1 + v11[12], a3[12]);
        v11 = *((unsigned __int8 **)a1 + 1);
      }
      if ( v11[13] )
      {
        regmap_write(a2, *a1 + v11[13], a3[14]);
        v11 = *((unsigned __int8 **)a1 + 1);
      }
      if ( v11[14] )
      {
        regmap_write(a2, *a1 + v11[14], a3[16]);
        v11 = *((unsigned __int8 **)a1 + 1);
      }
      if ( v11[15] )
      {
        regmap_write(a2, *a1 + v11[15], a3[17]);
        v11 = *((unsigned __int8 **)a1 + 1);
      }
      v12 = v11[16];
      if ( v12 )
        regmap_write(a2, *a1 + v12, a3[18]);
      regmap_update_bits_base(a2, *a1, 1, 0, 0, 0, 0);
      regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 19LL), 1);
      regmap_update_bits_base(a2, *a1, 4, 4, 0, 0, 0);
      regmap_update_bits_base(a2, *a1, 1024, 1024, 0, 0, 0);
      *((_QWORD *)a1 + 9) = a2;
      if ( (unsigned int)wait_for_pll(a1, 0x80000000LL, 0, "enable") )
      {
        if ( !*((_QWORD *)a1 + 8) )
          clk_hw_get_name(a1 + 12);
        printk(&unk_282BE);
      }
      regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 19LL), 0);
      result = regmap_update_bits_base(a2, *a1, 4096, 4096, 0, 0, 0);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
