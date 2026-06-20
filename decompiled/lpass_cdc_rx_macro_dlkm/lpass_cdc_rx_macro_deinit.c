__int64 __fastcall lpass_cdc_rx_macro_deinit(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // [xsp+8h] [xbp-18h] BYREF
  __int64 v3[2]; // [xsp+10h] [xbp-10h] BYREF

  v3[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = 0;
  if ( (lpass_cdc_rx_macro_get_data(a1, v3, &v2, (__int64)"lpass_cdc_rx_macro_deinit") & 1) != 0 )
  {
    result = 0;
    *(__int64 *)((char *)&qword_130 + v2) = 0;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
