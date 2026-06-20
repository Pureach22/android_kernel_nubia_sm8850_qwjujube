__int64 __fastcall _lpass_cdc_tx_macro_mclk_enable(__int64 a1, char a2)
{
  __int64 result; // x0
  __int64 v4; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v5[8]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v6; // [xsp+18h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = 0;
  if ( (lpass_cdc_tx_macro_get_data(a1, v5, &v4, "__lpass_cdc_tx_macro_mclk_enable") & 1) != 0 )
    result = lpass_cdc_tx_macro_mclk_enable(v4, a2 & 1);
  else
    result = 4294967274LL;
  _ReadStatusReg(SP_EL0);
  return result;
}
