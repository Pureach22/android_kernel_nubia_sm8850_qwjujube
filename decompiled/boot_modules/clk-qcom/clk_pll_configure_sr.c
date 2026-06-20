__int64 __fastcall clk_pll_configure_sr(unsigned int *a1, __int64 a2, unsigned int *a3, char a4)
{
  int v8; // w11
  __int64 result; // x0

  regmap_write(a2, *a1, *(unsigned __int16 *)a3);
  regmap_write(a2, a1[1], a3[1]);
  regmap_write(a2, a1[2], a3[2]);
  v8 = a3[10] | a3[11];
  result = regmap_update_bits_base(
             a2,
             a1[3],
             a3[4] | a3[6] | a3[8] | a3[9] | v8,
             a3[3] | a3[5] | a3[7] | a3[9] | v8,
             0,
             0,
             0);
  if ( (a4 & 1) != 0 )
    return qcom_pll_set_fsm_mode(a2, a1[4], 1, 8);
  return result;
}
