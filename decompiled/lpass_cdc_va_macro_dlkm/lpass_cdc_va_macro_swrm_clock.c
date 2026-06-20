__int64 __fastcall lpass_cdc_va_macro_swrm_clock(_QWORD *a1, char a2)
{
  __int64 regmap; // x0
  __int64 v5; // x20
  unsigned int v6; // w0
  __int64 v7; // x21
  unsigned int v8; // w20

  regmap = dev_get_regmap(*(_QWORD *)(*a1 + 96LL), 0);
  if ( regmap )
  {
    v5 = regmap;
    mutex_lock(a1 + 9);
    if ( (a2 & 1) != 0 )
    {
      _pm_runtime_resume(*a1, 4);
      v6 = lpass_cdc_va_macro_tx_va_mclk_enable(a1, v5, 1);
      v7 = *a1;
      v8 = v6;
      *(_QWORD *)(v7 + 520) = ktime_get_mono_fast_ns();
      _pm_runtime_suspend(*a1, 13);
    }
    else
    {
      v8 = lpass_cdc_va_macro_tx_va_mclk_enable(a1, v5, 0);
    }
    mutex_unlock(a1 + 9);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_swrm_clock__rs, "lpass_cdc_va_macro_swrm_clock") )
      dev_err(*a1, "%s: regmap is NULL\n", "lpass_cdc_va_macro_swrm_clock");
    return (unsigned int)-22;
  }
  return v8;
}
