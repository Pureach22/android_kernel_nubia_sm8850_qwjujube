__int64 __fastcall msm_cdc_pinctrl_get_gpiodata(__int64 a1)
{
  __int64 device_by_node; // x0
  __int64 v2; // x8
  __int64 result; // x0
  __int64 v4; // x19
  void *v5; // x0

  if ( !a1 )
  {
    if ( !(unsigned int)__ratelimit(&msm_cdc_pinctrl_get_gpiodata__rs, "msm_cdc_pinctrl_get_gpiodata") )
      return 0;
    v5 = &unk_9B54;
LABEL_12:
    printk(v5, "msm_cdc_pinctrl_get_gpiodata");
    return 0;
  }
  device_by_node = of_find_device_by_node();
  if ( !device_by_node )
  {
    if ( !(unsigned int)__ratelimit(&msm_cdc_pinctrl_get_gpiodata__rs_4, "msm_cdc_pinctrl_get_gpiodata") )
      return 0;
    v5 = &unk_9EAB;
    goto LABEL_12;
  }
  v2 = device_by_node;
  result = *(_QWORD *)(device_by_node + 168);
  if ( result )
    return result;
  v4 = v2;
  if ( (unsigned int)__ratelimit(&msm_cdc_pinctrl_get_gpiodata__rs_6, "msm_cdc_pinctrl_get_gpiodata") )
    dev_err(v4 + 16, "%s: cannot find cdc gpio info\n", "msm_cdc_pinctrl_get_gpiodata");
  return 0;
}
