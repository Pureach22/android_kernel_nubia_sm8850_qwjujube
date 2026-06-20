__int64 __fastcall lpass_cdc_rx_macro_fir_coeff_num_get(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 result; // x0
  _QWORD *v7; // [xsp+8h] [xbp-18h] BYREF
  __int64 v8[2]; // [xsp+10h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 120);
  v2 = *(_QWORD *)(a1 + 128);
  v7 = nullptr;
  v4 = *(unsigned int *)(v3 + 20);
  if ( !v2 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_rx_macro_fir_coeff_num_get__rs, "lpass_cdc_rx_macro_fir_coeff_num_get") )
    {
      printk(&unk_F49A, "lpass_cdc_rx_macro_fir_coeff_num_get");
      result = 4294967274LL;
      goto LABEL_8;
    }
LABEL_7:
    result = 4294967274LL;
    goto LABEL_8;
  }
  if ( (lpass_cdc_rx_macro_get_data(v2, v8, &v7, (__int64)"lpass_cdc_rx_macro_fir_coeff_num_get") & 1) == 0 )
    goto LABEL_7;
  if ( (unsigned int)v4 < 2 )
  {
    result = 0;
    *(_BYTE *)(a2 + 72) = *((_BYTE *)v7 + v4 + 84);
    goto LABEL_8;
  }
  if ( !(unsigned int)__ratelimit(&lpass_cdc_rx_macro_fir_coeff_num_get__rs_389, "lpass_cdc_rx_macro_fir_coeff_num_get") )
    goto LABEL_7;
  dev_err(*v7, "%s: path_idx:%d is invalid\n", "lpass_cdc_rx_macro_fir_coeff_num_get", v4);
  result = 4294967274LL;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
