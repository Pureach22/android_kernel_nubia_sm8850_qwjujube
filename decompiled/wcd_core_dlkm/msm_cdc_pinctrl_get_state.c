__int64 __fastcall msm_cdc_pinctrl_get_state(__int64 a1)
{
  __int64 gpiodata; // x0

  gpiodata = msm_cdc_pinctrl_get_gpiodata(a1);
  if ( gpiodata )
    return *(unsigned __int8 *)(gpiodata + 36);
  else
    return 4294967274LL;
}
