__int64 __fastcall clk_trion_pll_configure(unsigned int *a1, __int64 a2, unsigned int *a3)
{
  __int64 v6; // x1
  int v7; // w22
  __int64 result; // x0
  unsigned int v9; // w8
  __int64 v10; // x2
  unsigned __int8 *v11; // x8
  int v12; // w8
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a1;
  v13[0] = 0;
  v7 = regmap_read(a2, v6, (char *)v13 + 4);
  result = regmap_read(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 19LL), v13);
  if ( (unsigned int)result | v7 || (v13[0] & 1) == 0 || (v13[0] & 0x100000000LL) == 0 )
  {
    if ( *(_BYTE *)(*((_QWORD *)a1 + 1) + 1LL) )
      regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 1LL), *a3);
    v9 = a3[1];
    if ( v9 )
      v10 = v9;
    else
      v10 = 68;
    regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 2LL), v10);
    v11 = *((unsigned __int8 **)a1 + 1);
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
    if ( v11[5] )
    {
      regmap_write(a2, *a1 + v11[5], a3[9]);
      v11 = *((unsigned __int8 **)a1 + 1);
    }
    if ( v11[6] )
    {
      regmap_write(a2, *a1 + v11[6], a3[10]);
      v11 = *((unsigned __int8 **)a1 + 1);
    }
    if ( v11[7] )
    {
      regmap_write(a2, *a1 + v11[7], a3[11]);
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
    v12 = v11[14];
    if ( v12 )
      regmap_write(a2, *a1 + v12, a3[16]);
    regmap_update_bits_base(a2, *a1, 0x800000, 0x800000, 0, 0, 0);
    if ( (a1[10] & 0x10) != 0 )
      regmap_update_bits_base(a2, *a1, 0x1000000, 0x1000000, 0, 0, 0);
    regmap_update_bits_base(a2, *a1, 1, 0, 0, 0, 0);
    regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 19LL), 0);
    result = regmap_update_bits_base(a2, *a1, 4, 4, 0, 0, 0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
