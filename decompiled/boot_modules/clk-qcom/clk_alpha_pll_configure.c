__int64 __fastcall clk_alpha_pll_configure(unsigned int *a1, __int64 a2, unsigned int *a3)
{
  unsigned __int8 *v6; // x9
  int v7; // w8
  int v8; // w10
  __int64 result; // x0
  __int64 v10; // x2
  __int64 v11; // x2

  regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 1LL), *a3);
  regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 3LL), a3[3]);
  regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 8LL), a3[5]);
  v6 = *((unsigned __int8 **)a1 + 1);
  v7 = *a1;
  if ( v6[9] - v6[8] == 4 )
  {
    regmap_write(a2, v7 + (unsigned int)v6[9], a3[6]);
    v7 = *a1;
    v6 = *((unsigned __int8 **)a1 + 1);
  }
  if ( v6[4] - v6[3] == 4 )
  {
    regmap_write(a2, v7 + (unsigned int)v6[4], a3[4]);
    v7 = *a1;
    v6 = *((unsigned __int8 **)a1 + 1);
  }
  v8 = a3[20] | a3[19] | a3[21] | a3[22];
  result = regmap_update_bits_base(
             a2,
             v7 + (unsigned int)v6[5],
             a3[26] | a3[28] | a3[30] | v8,
             a3[25] | a3[27] | a3[29] | a3[23] | a3[24] | v8,
             0,
             0,
             0);
  v10 = a3[13];
  if ( (_DWORD)v10 )
  {
    result = regmap_update_bits_base(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 12LL), v10, a3[12], 0, 0, 0);
  }
  else if ( *(_BYTE *)(*((_QWORD *)a1 + 1) + 12LL) )
  {
    result = regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 12LL), a3[12]);
  }
  v11 = a3[15];
  if ( (_DWORD)v11 )
  {
    result = regmap_update_bits_base(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 13LL), v11, a3[14], 0, 0, 0);
  }
  else if ( *(_BYTE *)(*((_QWORD *)a1 + 1) + 13LL) )
  {
    result = regmap_write(a2, *a1 + *(unsigned __int8 *)(*((_QWORD *)a1 + 1) + 13LL), a3[14]);
  }
  if ( (a1[10] & 4) != 0 )
    return qcom_pll_set_fsm_mode(a2, *a1, 6, 0);
  return result;
}
