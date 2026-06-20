__int64 __fastcall canoe_tlmm_probe(__int64 a1)
{
  __int64 match_data; // x0
  unsigned int v3; // w19

  match_data = of_device_get_match_data(a1 + 16);
  if ( match_data )
  {
    v3 = msm_pinctrl_probe(a1, match_data);
    msm_gpio_mpm_wake_set(35, 1);
  }
  else
  {
    return (unsigned int)-22;
  }
  return v3;
}
