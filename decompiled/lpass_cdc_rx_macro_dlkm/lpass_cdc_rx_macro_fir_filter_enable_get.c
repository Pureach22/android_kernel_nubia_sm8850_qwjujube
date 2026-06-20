__int64 __fastcall lpass_cdc_rx_macro_fir_filter_enable_get(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v5; // [xsp+8h] [xbp-18h] BYREF
  __int64 v6[2]; // [xsp+10h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 128);
  v5 = 0;
  if ( !v2 )
  {
    if ( (unsigned int)__ratelimit(
                         &lpass_cdc_rx_macro_fir_filter_enable_get__rs,
                         "lpass_cdc_rx_macro_fir_filter_enable_get") )
      printk(&unk_F49A, "lpass_cdc_rx_macro_fir_filter_enable_get");
    goto LABEL_6;
  }
  if ( (lpass_cdc_rx_macro_get_data(v2, v6, &v5, (__int64)"lpass_cdc_rx_macro_fir_filter_enable_get") & 1) == 0 )
  {
LABEL_6:
    result = 4294967274LL;
    goto LABEL_7;
  }
  result = 0;
  *(_BYTE *)(a2 + 72) = *(_BYTE *)(v5 + 88);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
