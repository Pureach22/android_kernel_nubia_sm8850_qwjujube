__int64 __fastcall lpass_cdc_rx_macro_fir_coeff_num_put(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x21
  unsigned int v4; // w20
  __int64 v5; // x19
  __int64 result; // x0
  int v7; // w8
  _QWORD *v8; // [xsp+8h] [xbp-18h] BYREF
  __int64 v9[2]; // [xsp+10h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 120);
  v3 = *(_QWORD *)(a1 + 128);
  v4 = *(unsigned __int8 *)(a2 + 72);
  v8 = nullptr;
  v5 = *(unsigned int *)(v2 + 20);
  if ( !v3 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_rx_macro_fir_coeff_num_put__rs, "lpass_cdc_rx_macro_fir_coeff_num_put") )
      printk(&unk_F49A, "lpass_cdc_rx_macro_fir_coeff_num_put");
    goto LABEL_9;
  }
  if ( (lpass_cdc_rx_macro_get_data(v3, v9, &v8, (__int64)"lpass_cdc_rx_macro_fir_coeff_num_put") & 1) == 0 )
  {
LABEL_9:
    result = 4294967274LL;
    goto LABEL_10;
  }
  if ( v4 >= 0xC9 )
  {
    if ( (unsigned int)__ratelimit(
                         &lpass_cdc_rx_macro_fir_coeff_num_put__rs_391,
                         "lpass_cdc_rx_macro_fir_coeff_num_put") )
    {
      dev_err(
        *v8,
        "%s: inavlid total number of RX_FIR coefficients:%d in path:%d\n",
        "lpass_cdc_rx_macro_fir_coeff_num_put",
        v4,
        v5);
      if ( (unsigned int)v5 <= 1 )
        goto LABEL_6;
    }
    else if ( (unsigned int)v5 <= 1 )
    {
LABEL_6:
      result = 4294967274LL;
      *((_BYTE *)v8 + v5 + 84) = 0;
      goto LABEL_10;
    }
LABEL_16:
    __break(0x5512u);
  }
  if ( (unsigned int)v5 > 1 )
    goto LABEL_16;
  v7 = LODWORD(v8[v5 + 285]) + HIDWORD(v8[v5 + 284]);
  *((_BYTE *)v8 + v5 + 84) = v4;
  if ( v7 == v4 )
    result = ((__int64 (__fastcall *)(__int64))set_fir_filter_coeff)(v3);
  else
    result = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
