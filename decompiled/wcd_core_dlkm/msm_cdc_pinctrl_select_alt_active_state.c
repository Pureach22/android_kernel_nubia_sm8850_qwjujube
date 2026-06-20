__int64 __fastcall msm_cdc_pinctrl_select_alt_active_state(__int64 a1)
{
  __int64 gpiodata; // x0
  __int64 v2; // x8

  gpiodata = msm_cdc_pinctrl_get_gpiodata(a1);
  if ( gpiodata )
  {
    if ( *(_QWORD *)(gpiodata + 24) )
    {
      v2 = *(_QWORD *)gpiodata;
      *(_BYTE *)(gpiodata + 36) = 1;
      return pinctrl_select_state(v2);
    }
    if ( (unsigned int)__ratelimit(
                         &msm_cdc_pinctrl_select_alt_active_state__rs,
                         "msm_cdc_pinctrl_select_alt_active_state") )
      printk(&unk_9A73, "msm_cdc_pinctrl_select_alt_active_state");
  }
  return 4294967274LL;
}
