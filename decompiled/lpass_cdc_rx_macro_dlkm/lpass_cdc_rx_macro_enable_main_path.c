__int64 __fastcall lpass_cdc_rx_macro_enable_main_path(__int64 a1, __int64 a2, int a3)
{
  __int64 v5; // x22
  __int64 v6; // x19
  __int64 v7; // x2
  __int64 result; // x0
  int v9; // w22
  int v10; // w21
  unsigned __int8 v11; // w20
  unsigned __int8 v12; // w0
  unsigned int v13; // w0
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  __int64 v15[2]; // [xsp+10h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 40);
  v14 = 0;
  v6 = v5 - 208;
  if ( (lpass_cdc_rx_macro_get_data(v5 - 208, v15, &v14, (__int64)"lpass_cdc_rx_macro_enable_main_path") & 1) == 0 )
  {
LABEL_4:
    result = 4294967274LL;
    goto LABEL_15;
  }
  v7 = *(unsigned __int8 *)(a1 + 76);
  if ( (unsigned int)v7 >= 3 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_rx_macro_enable_main_path__rs, "lpass_cdc_rx_macro_enable_main_path") )
    {
      dev_err(
        *(_QWORD *)(v5 - 184),
        "%s: Invalid Interpolator value %d for name %s\n",
        "lpass_cdc_rx_macro_enable_main_path",
        *(unsigned __int8 *)(a1 + 76),
        *(const char **)(a1 + 8));
      result = 4294967274LL;
      goto LABEL_15;
    }
    goto LABEL_4;
  }
  if ( a3 == 8 )
  {
    lpass_cdc_rx_macro_enable_interp_clk(v5 - 208, 8, v7);
  }
  else
  {
    v9 = 192 * v7;
    if ( a3 == 2 )
    {
      v13 = snd_soc_component_read(v6, v9 | 0x1414u);
      snd_soc_component_write(v6, v9 | 0x1414u, v13);
    }
    else if ( a3 == 1 )
    {
      lpass_cdc_rx_macro_set_idle_detect_thr(v6, v14);
      lpass_cdc_rx_macro_enable_interp_clk(v6, 1, *(unsigned __int8 *)(a1 + 76));
      v10 = 8 * *(unsigned __int8 *)(a1 + 76);
      v11 = snd_soc_component_read(v6, (unsigned int)(v10 + 4480));
      v12 = snd_soc_component_read(v6, (unsigned int)(v10 + 4484));
      if ( (v11 & 0xFu) - 1 < 4 || (unsigned int)(v11 >> 4) - 1 < 4 || (unsigned int)(v12 >> 4) - 1 <= 3 )
        snd_soc_component_update_bits(v6, v9 | 0x1400u, 32, 32);
    }
  }
  result = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
