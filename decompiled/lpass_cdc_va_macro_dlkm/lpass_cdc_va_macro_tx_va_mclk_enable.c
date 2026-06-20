__int64 __fastcall lpass_cdc_va_macro_tx_va_mclk_enable(_QWORD *a1, __int64 a2, char a3)
{
  int v3; // w8
  int v6; // w21
  unsigned int v7; // w0
  int v8; // w8
  int v10; // w21
  int v11; // w8
  unsigned int v12; // w20

  v3 = *((_DWORD *)a1 + 335);
  if ( (a3 & 1) != 0 )
  {
    if ( !v3 )
    {
      msm_cdc_pinctrl_select_active_state(a1[169]);
      msm_cdc_pinctrl_set_wakeup_capable(a1[169], 0);
    }
    v6 = lpass_cdc_clk_rsc_request_clock(*a1, 0, 0, 1);
    v7 = lpass_cdc_va_macro_mclk_enable(a1, 1);
    v8 = *((_DWORD *)a1 + 335);
    if ( (v7 & 0x80000000) == 0 )
    {
      if ( v8 )
      {
        if ( v6 )
        {
LABEL_7:
          ++*((_DWORD *)a1 + 335);
          return 0;
        }
      }
      else
      {
        if ( *((_BYTE *)a1 + 1344) == 1 )
          regmap_update_bits_base(a2, 12296, 2, 2, 0, 0, 0);
        regmap_update_bits_base(a2, 12296, 1, 1, 0, 0, 0);
        if ( *((_BYTE *)a1 + 1344) == 1 )
          regmap_update_bits_base(a2, 12296, 2, 0, 0, 0, 0);
        *((_BYTE *)a1 + 1344) = 0;
        if ( v6 )
          goto LABEL_7;
      }
      lpass_cdc_clk_rsc_request_clock(*a1, 0, 0, 0);
      goto LABEL_7;
    }
    v12 = v7;
    if ( !v8 )
      msm_cdc_pinctrl_select_sleep_state(a1[169]);
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_tx_va_mclk_enable__rs, "lpass_cdc_va_macro_tx_va_mclk_enable") )
    {
      dev_err(*a1, "%s: request clock enable failed\n", "lpass_cdc_va_macro_tx_va_mclk_enable");
      if ( v6 )
        return v12;
    }
    else if ( v6 )
    {
      return v12;
    }
    lpass_cdc_clk_rsc_request_clock(*a1, 0, 0, 0);
    return v12;
  }
  if ( v3 > 0 )
  {
    v10 = lpass_cdc_clk_rsc_request_clock(*a1, 0, 0, 1);
    v11 = *((_DWORD *)a1 + 335) - 1;
    *((_DWORD *)a1 + 335) = v11;
    if ( !v11 )
      regmap_update_bits_base(a2, 12296, 1, 0, 0, 0, 0);
    lpass_cdc_va_macro_mclk_enable(a1, 0);
    if ( v10 )
    {
      if ( *((_DWORD *)a1 + 335) )
        return 0;
    }
    else
    {
      lpass_cdc_clk_rsc_request_clock(*a1, 0, 0, 0);
      if ( *((_DWORD *)a1 + 335) )
        return 0;
    }
    msm_cdc_pinctrl_select_sleep_state(a1[169]);
    msm_cdc_pinctrl_set_wakeup_capable(a1[169], 1);
    return 0;
  }
  if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_tx_va_mclk_enable__rs_44, "lpass_cdc_va_macro_tx_va_mclk_enable") )
    dev_err(*a1, "va swrm clock users already 0\n");
  *((_DWORD *)a1 + 335) = 0;
  return 0;
}
