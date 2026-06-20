__int64 __fastcall lpass_cdc_tx_macro_clk_div_get(__int64 a1, unsigned int a2)
{
  char data; // w8
  __int64 result; // x0
  __int64 v5; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v6[8]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v7; // [xsp+18h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  data = lpass_cdc_tx_macro_get_data(a1, v6, &v5, "lpass_cdc_tx_macro_clk_div_get");
  result = 4294967274LL;
  if ( a2 <= 3 && (data & 1) != 0 )
    result = *(unsigned __int16 *)(v5 + 2LL * a2 + 2528);
  _ReadStatusReg(SP_EL0);
  return result;
}
