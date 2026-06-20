__int64 __fastcall wcd9378_reset(__int64 a1)
{
  __int64 v1; // x20

  if ( !a1 )
    return 4294967277LL;
  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    return 4294967274LL;
  if ( !*(_QWORD *)(v1 + 40) )
  {
    dev_err(a1, "%s: reset gpio device node not specified\n", "wcd9378_reset");
    return 4294967274LL;
  }
  if ( (int)msm_cdc_pinctrl_get_state(*(_QWORD *)(v1 + 40)) > 0 )
    return 0;
  if ( (unsigned int)msm_cdc_pinctrl_select_sleep_state(*(_QWORD *)(v1 + 40)) )
  {
    dev_err(a1, "%s: wcd sleep state request fail!\n", "wcd9378_reset");
  }
  else
  {
    usleep_range_state(80, 85, 2);
    if ( !(unsigned int)msm_cdc_pinctrl_select_active_state(*(_QWORD *)(v1 + 40)) )
    {
      usleep_range_state(80, 85, 2);
      return 0;
    }
    dev_err(a1, "%s: wcd active state request fail!\n", "wcd9378_reset");
  }
  return 4294966779LL;
}
