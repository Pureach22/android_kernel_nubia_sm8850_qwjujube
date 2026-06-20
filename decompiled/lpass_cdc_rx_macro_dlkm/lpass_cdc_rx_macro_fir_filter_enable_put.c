__int64 __fastcall lpass_cdc_rx_macro_fir_filter_enable_put(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v4; // x21
  __int64 v5; // x20
  int v6; // w8
  unsigned int v7; // w0
  unsigned int v8; // w0
  unsigned int v9; // w22
  __int64 result; // x0
  __int64 v11; // x19
  unsigned int v12; // w19
  __int64 v13; // [xsp+8h] [xbp-18h] BYREF
  __int64 v14[2]; // [xsp+10h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 128);
  v13 = 0;
  if ( !v2 )
  {
    if ( (unsigned int)__ratelimit(
                         &lpass_cdc_rx_macro_fir_filter_enable_put__rs,
                         "lpass_cdc_rx_macro_fir_filter_enable_put") )
    {
      printk(&unk_F49A, "lpass_cdc_rx_macro_fir_filter_enable_put");
      result = 4294967274LL;
      goto LABEL_15;
    }
    goto LABEL_12;
  }
  if ( (lpass_cdc_rx_macro_get_data(v2, v14, &v13, (__int64)"lpass_cdc_rx_macro_fir_filter_enable_put") & 1) == 0 )
  {
LABEL_12:
    result = 4294967274LL;
    goto LABEL_15;
  }
  v4 = v13;
  v5 = *(_QWORD *)(v13 + 2344);
  if ( !v5 || *(_BYTE *)(v13 + 93) != 1 )
    goto LABEL_14;
  v6 = *(unsigned __int8 *)(a2 + 72);
  *(_BYTE *)(v13 + 88) = *(_BYTE *)(a2 + 72) != 0;
  if ( !v6 )
  {
    snd_soc_component_update_bits(v2, 5212, 13, 0);
    snd_soc_component_update_bits(v2, 5404, 13, 0);
    snd_soc_component_update_bits(v2, 5120, 128, 0);
    snd_soc_component_update_bits(v2, 5312, 128, 0);
    snd_soc_component_update_bits(v2, 4100, 1, 0);
    v11 = *(_QWORD *)(v4 + 2344);
    clk_disable(v11);
    clk_unprepare(v11);
    goto LABEL_14;
  }
  v7 = clk_prepare(v5);
  if ( !v7 )
  {
    v8 = clk_enable(v5);
    if ( !v8 )
    {
LABEL_10:
      snd_soc_component_write(v2, 5216, *(unsigned __int8 *)(v4 + 84));
      snd_soc_component_write(v2, 5408, *(unsigned __int8 *)(v4 + 85));
      snd_soc_component_update_bits(v2, 4100, 1, 1);
      snd_soc_component_update_bits(v2, 5120, 128, 128);
      snd_soc_component_update_bits(v2, 5312, 128, 128);
      snd_soc_component_update_bits(v2, 5212, 13, 5);
      snd_soc_component_update_bits(v2, 5404, 13, 5);
LABEL_14:
      result = 0;
      goto LABEL_15;
    }
    v9 = v8;
    clk_unprepare(v5);
    v7 = v9;
  }
  if ( (v7 & 0x80000000) == 0 )
    goto LABEL_10;
  v12 = v7;
  if ( (unsigned int)__ratelimit(
                       &lpass_cdc_rx_macro_fir_filter_enable_put__rs_404,
                       "lpass_cdc_rx_macro_fir_filter_enable_put") )
    dev_err(*(_QWORD *)v4, "%s:hifi_fir_clk enable failed\n", "lpass_cdc_rx_macro_fir_filter_enable_put");
  result = v12;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
