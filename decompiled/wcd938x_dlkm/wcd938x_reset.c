__int64 __fastcall wcd938x_reset(__int64 a1)
{
  __int64 v1; // x20

  if ( !a1 )
    return 4294967277LL;
  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return 4294967274LL;
  if ( !*(_QWORD *)(v1 + 24) )
  {
    if ( (unsigned int)__ratelimit(&wcd938x_reset__rs, "wcd938x_reset") )
      dev_err(a1, "%s: reset gpio device node not specified\n", "wcd938x_reset");
    return 4294967274LL;
  }
  if ( (int)msm_cdc_pinctrl_get_state() > 0 )
    return 0;
  if ( !(unsigned int)msm_cdc_pinctrl_select_sleep_state(*(_QWORD *)(v1 + 24)) )
  {
    usleep_range_state(20, 30, 2);
    if ( !(unsigned int)msm_cdc_pinctrl_select_active_state(*(_QWORD *)(v1 + 24)) )
    {
      usleep_range_state(20, 30, 2);
      return 0;
    }
    if ( (unsigned int)__ratelimit(&wcd938x_reset__rs_91, "wcd938x_reset") )
    {
      dev_err(a1, "%s: wcd active state request fail!\n", "wcd938x_reset");
      return 4294966779LL;
    }
    return 4294966779LL;
  }
  if ( !(unsigned int)__ratelimit(&wcd938x_reset__rs_89, "wcd938x_reset") )
    return 4294966779LL;
  dev_err(a1, "%s: wcd sleep state request fail!\n", "wcd938x_reset");
  return 4294966779LL;
}
