__int64 __fastcall lpass_cdc_tx_macro_deinit(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v3[8]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v4; // [xsp+18h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = 0;
  if ( (lpass_cdc_tx_macro_get_data(a1, v3, &v2, "lpass_cdc_tx_macro_deinit") & 1) != 0 )
  {
    result = 0;
    *(__int64 *)((char *)&qword_78 + v2) = 0;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
