__int64 __fastcall lpass_cdc_rx_set_fir_capability(__int64 a1, char a2)
{
  __int64 result; // x0
  __int64 v4; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v5[8]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v6; // [xsp+18h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = 0;
  if ( !a1 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_rx_set_fir_capability__rs, "lpass_cdc_rx_set_fir_capability") )
      printk(&unk_F49A, "lpass_cdc_rx_set_fir_capability");
    goto LABEL_6;
  }
  if ( (lpass_cdc_rx_macro_get_data(a1, v5, &v4, "lpass_cdc_rx_set_fir_capability") & 1) == 0 )
  {
LABEL_6:
    result = 4294967274LL;
    goto LABEL_7;
  }
  result = 0;
  *(_BYTE *)(v4 + 93) = a2 & 1;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
