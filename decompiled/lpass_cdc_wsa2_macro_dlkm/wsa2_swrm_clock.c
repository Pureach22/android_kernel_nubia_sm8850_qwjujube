__int64 __fastcall wsa2_swrm_clock(_QWORD *a1, char a2)
{
  __int64 regmap; // x0
  __int64 v5; // x21
  __int64 updated; // x0
  __int16 v7; // w8
  unsigned int v8; // w20
  __int64 v9; // x21
  __int16 v10; // w8
  unsigned int active; // w0

  regmap = dev_get_regmap(*(_QWORD *)(*a1 + 96LL), 0);
  if ( regmap )
  {
    v5 = regmap;
    mutex_lock(a1 + 12);
    if ( (a2 & 1) == 0 )
    {
      if ( *((_WORD *)a1 + 19) )
      {
        v10 = *((_WORD *)a1 + 19) - 1;
        *((_WORD *)a1 + 19) = v10;
        if ( v10 )
        {
          v8 = 0;
        }
        else
        {
          regmap_update_bits_base(v5, 16392, 1, 0, 0, 0, 0);
          lpass_cdc_wsa2_macro_mclk_enable(a1, 0);
          v8 = msm_cdc_pinctrl_select_sleep_state(a1[30]);
          if ( (v8 & 0x80000000) != 0 && (unsigned int)__ratelimit(&wsa2_swrm_clock__rs_50, "wsa2_swrm_clock") )
            dev_err(*a1, "%s: wsa2 swr pinctrl disable failed\n", "wsa2_swrm_clock");
        }
      }
      else
      {
        if ( (unsigned int)__ratelimit(&wsa2_swrm_clock__rs_48, "wsa2_swrm_clock") )
          dev_err(*a1, "%s: clock already disabled\n", "wsa2_swrm_clock");
        v8 = 0;
        *((_WORD *)a1 + 19) = 0;
      }
      goto LABEL_31;
    }
    updated = _pm_runtime_resume(*a1, 4);
    v7 = *((_WORD *)a1 + 19);
    if ( v7 )
    {
      v8 = 0;
LABEL_5:
      v9 = *a1;
      *((_WORD *)a1 + 19) = v7 + 1;
LABEL_30:
      *(_QWORD *)(v9 + 520) = ktime_get_mono_fast_ns(updated);
      _pm_runtime_suspend(*a1, 13);
LABEL_31:
      mutex_unlock(a1 + 12);
      return v8;
    }
    active = msm_cdc_pinctrl_select_active_state(a1[30]);
    if ( (active & 0x80000000) != 0 )
    {
      v8 = active;
      updated = __ratelimit(&wsa2_swrm_clock__rs_44, "wsa2_swrm_clock");
      if ( (_DWORD)updated )
        updated = dev_err(*a1, "%s: wsa2 swr pinctrl enable failed\n", "wsa2_swrm_clock");
    }
    else
    {
      v8 = lpass_cdc_wsa2_macro_mclk_enable(a1, 1);
      if ( (v8 & 0x80000000) == 0 )
      {
        if ( *((_BYTE *)a1 + 41) == 1 )
          regmap_update_bits_base(v5, 16392, 2, 2, 0, 0, 0);
        regmap_update_bits_base(v5, 16392, 1, 1, 0, 0, 0);
        if ( *((_BYTE *)a1 + 41) == 1 )
          regmap_update_bits_base(v5, 16392, 2, 0, 0, 0, 0);
        updated = regmap_update_bits_base(v5, 16392, 28, 12, 0, 0, 0);
        v7 = *((_WORD *)a1 + 19);
        *((_BYTE *)a1 + 41) = 0;
        goto LABEL_5;
      }
      msm_cdc_pinctrl_select_sleep_state(a1[30]);
      updated = __ratelimit(&wsa2_swrm_clock__rs_46, "wsa2_swrm_clock");
      if ( (_DWORD)updated )
        updated = dev_err(*a1, "%s: wsa2 request clock enable failed\n", "wsa2_swrm_clock");
    }
    v9 = *a1;
    goto LABEL_30;
  }
  if ( (unsigned int)__ratelimit(&wsa2_swrm_clock__rs, "wsa2_swrm_clock") )
    dev_err(*a1, "%s: regmap is NULL\n", "wsa2_swrm_clock");
  return (unsigned int)-22;
}
