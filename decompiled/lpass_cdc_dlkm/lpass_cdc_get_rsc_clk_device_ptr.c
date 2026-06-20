__int64 __fastcall lpass_cdc_get_rsc_clk_device_ptr(__int64 a1)
{
  __int64 v2; // x8
  void *v4; // x0

  if ( !a1 )
  {
    if ( !(unsigned int)__ratelimit(&lpass_cdc_get_rsc_clk_device_ptr__rs, "lpass_cdc_get_rsc_clk_device_ptr") )
      return 0;
    v4 = &unk_DCD3;
LABEL_9:
    printk(v4, "lpass_cdc_get_rsc_clk_device_ptr");
    return 0;
  }
  if ( !(unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,lpass-cdc") )
  {
    if ( !(unsigned int)__ratelimit(&lpass_cdc_get_rsc_clk_device_ptr__rs_7, "lpass_cdc_get_rsc_clk_device_ptr") )
      return 0;
    v4 = &unk_DA4A;
    goto LABEL_9;
  }
  v2 = *(_QWORD *)(a1 + 152);
  if ( v2 )
    return *(_QWORD *)(v2 + 1080);
  if ( (unsigned int)__ratelimit(&lpass_cdc_get_rsc_clk_device_ptr__rs_8, "lpass_cdc_get_rsc_clk_device_ptr") )
    dev_err(a1, "%s: priv is null\n", "lpass_cdc_get_rsc_clk_device_ptr");
  return 0;
}
