__int64 __fastcall lpass_cdc_rx_macro_enable_mix_path(__int64 a1, __int64 a2, int a3)
{
  __int64 v5; // x22
  __int64 v6; // x19
  unsigned int v7; // w2
  __int64 result; // x0
  int v9; // w22
  __int64 v10; // x1
  __int64 v11; // x0
  __int64 v12; // x2
  __int64 v13; // x3
  unsigned int v14; // w0
  __int64 v15; // [xsp+8h] [xbp-18h] BYREF
  __int64 v16[2]; // [xsp+10h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 40);
  v15 = 0;
  v6 = v5 - 208;
  if ( (lpass_cdc_rx_macro_get_data(v5 - 208, v16, &v15, (__int64)"lpass_cdc_rx_macro_enable_mix_path") & 1) != 0 )
  {
    v7 = *(unsigned __int8 *)(a1 + 76);
    if ( v7 >= 3 )
    {
      if ( (unsigned int)__ratelimit(&lpass_cdc_rx_macro_enable_mix_path__rs, "lpass_cdc_rx_macro_enable_mix_path") )
      {
        dev_err(
          *(_QWORD *)(v5 - 184),
          "%s: Invalid Interpolator value %d for name %s\n",
          "lpass_cdc_rx_macro_enable_mix_path",
          *(unsigned __int8 *)(a1 + 76),
          *(const char **)(a1 + 8));
        result = 4294967274LL;
        goto LABEL_13;
      }
      goto LABEL_4;
    }
    v9 = 192 * v7;
    if ( a3 != 8 )
    {
      if ( a3 == 2 )
      {
        v14 = snd_soc_component_read(v6, v9 | 0x1420u);
        snd_soc_component_write(v6, v9 | 0x1420u, v14);
      }
      else if ( a3 == 1 )
      {
        lpass_cdc_rx_macro_set_idle_detect_thr(v6, v15);
        lpass_cdc_rx_macro_enable_interp_clk(v6, 1, *(unsigned __int8 *)(a1 + 76));
        v10 = v9 | 0x1418u;
        v11 = v6;
        v12 = 32;
        v13 = 32;
LABEL_11:
        snd_soc_component_update_bits(v11, v10, v12, v13);
      }
      result = 0;
      goto LABEL_13;
    }
    snd_soc_component_update_bits(v6, v9 | 0x1418u, 32, 0);
    lpass_cdc_rx_macro_enable_interp_clk(v6, 8, *(unsigned __int8 *)(a1 + 76));
    snd_soc_component_update_bits(v6, v9 | 0x1418u, 64, 64);
    v10 = v9 | 0x1418u;
    v11 = v6;
    v12 = 64;
    v13 = 0;
    goto LABEL_11;
  }
LABEL_4:
  result = 4294967274LL;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
