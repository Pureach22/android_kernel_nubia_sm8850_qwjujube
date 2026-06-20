__int64 __fastcall rx_swrm_clock(int *a1, char a2)
{
  __int64 regmap; // x0
  __int64 v5; // x21
  __int64 updated; // x0
  unsigned int v7; // w20
  __int64 v8; // x21
  int v9; // w8
  int v10; // w8
  unsigned int active; // w0
  __int64 v12; // x21

  regmap = dev_get_regmap(*(_QWORD *)(*(_QWORD *)a1 + 96LL), 0);
  if ( regmap )
  {
    v5 = regmap;
    mutex_lock(a1 + 38);
    if ( (a2 & 1) == 0 )
    {
      v9 = a1[17];
      if ( v9 <= 0 )
      {
        if ( (unsigned int)__ratelimit(&rx_swrm_clock__rs_41, "rx_swrm_clock") )
          dev_err(*(_QWORD *)a1, "%s: rx swrm clock users already reset\n", "rx_swrm_clock");
        v7 = 0;
        a1[17] = 0;
      }
      else
      {
        v10 = v9 - 1;
        a1[17] = v10;
        if ( v10 )
        {
          v7 = 0;
        }
        else
        {
          regmap_update_bits_base(v5, 4360, 1, 0, 0, 0, 0);
          lpass_cdc_rx_macro_mclk_enable(a1, 0);
          v7 = msm_cdc_pinctrl_select_sleep_state(*((_QWORD *)a1 + 37));
          if ( (v7 & 0x80000000) != 0 && (unsigned int)__ratelimit(&rx_swrm_clock__rs_43, "rx_swrm_clock") )
            dev_err(*(_QWORD *)a1, "%s: rx swr pinctrl disable failed\n", "rx_swrm_clock");
        }
      }
      goto LABEL_30;
    }
    updated = _pm_runtime_resume(*(_QWORD *)a1, 4);
    if ( a1[17] )
    {
      v7 = 0;
LABEL_5:
      v8 = *(_QWORD *)a1;
      *(_QWORD *)(v8 + 520) = ktime_get_mono_fast_ns(updated);
      _pm_runtime_suspend(*(_QWORD *)a1, 13);
      ++a1[17];
LABEL_30:
      mutex_unlock(a1 + 38);
      return v7;
    }
    active = msm_cdc_pinctrl_select_active_state(*((_QWORD *)a1 + 37));
    if ( (active & 0x80000000) != 0 )
    {
      v7 = active;
      if ( (unsigned int)__ratelimit(&rx_swrm_clock__rs_37, "rx_swrm_clock") )
        dev_err(*(_QWORD *)a1, "%s: rx swr pinctrl enable failed\n", "rx_swrm_clock");
    }
    else
    {
      v7 = lpass_cdc_rx_macro_mclk_enable(a1, 1);
      if ( (v7 & 0x80000000) == 0 )
      {
        if ( *((_BYTE *)a1 + 73) == 1 )
          regmap_update_bits_base(v5, 4360, 2, 2, 0, 0, 0);
        updated = regmap_update_bits_base(v5, 4360, 1, 1, 0, 0, 0);
        if ( *((_BYTE *)a1 + 73) == 1 )
          updated = regmap_update_bits_base(v5, 4360, 2, 0, 0, 0, 0);
        *((_BYTE *)a1 + 73) = 0;
        goto LABEL_5;
      }
      msm_cdc_pinctrl_select_sleep_state(*((_QWORD *)a1 + 37));
      if ( (unsigned int)__ratelimit(&rx_swrm_clock__rs_39, "rx_swrm_clock") )
        dev_err(*(_QWORD *)a1, "%s: rx request clock enable failed\n", "rx_swrm_clock");
    }
    v12 = *(_QWORD *)a1;
    *(_QWORD *)(v12 + 520) = ((__int64 (*)(void))ktime_get_mono_fast_ns)();
    _pm_runtime_suspend(*(_QWORD *)a1, 13);
    goto LABEL_30;
  }
  if ( (unsigned int)__ratelimit(&rx_swrm_clock__rs, "rx_swrm_clock") )
    dev_err(*(_QWORD *)a1, "%s: regmap is NULL\n", "rx_swrm_clock");
  return (unsigned int)-22;
}
