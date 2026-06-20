__int64 __fastcall msm_cdc_pinctrl_select_sleep_state(__int64 a1)
{
  __int64 gpiodata; // x0
  __int64 v2; // x8

  gpiodata = msm_cdc_pinctrl_get_gpiodata(a1);
  if ( gpiodata )
  {
    if ( *(_QWORD *)(gpiodata + 16) )
    {
      v2 = *(_QWORD *)gpiodata;
      *(_BYTE *)(gpiodata + 36) = 0;
      return pinctrl_select_state(v2);
    }
    if ( (unsigned int)__ratelimit(&msm_cdc_pinctrl_select_sleep_state__rs, "msm_cdc_pinctrl_select_sleep_state") )
      printk(&unk_9B31, "msm_cdc_pinctrl_select_sleep_state");
  }
  return 4294967274LL;
}
