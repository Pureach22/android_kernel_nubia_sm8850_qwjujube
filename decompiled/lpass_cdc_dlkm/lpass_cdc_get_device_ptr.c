__int64 __fastcall lpass_cdc_get_device_ptr(__int64 a1, unsigned __int16 a2)
{
  __int64 v4; // x8
  void *v6; // x0

  if ( !a1 )
  {
    if ( !(unsigned int)__ratelimit(&lpass_cdc_get_device_ptr__rs, "lpass_cdc_get_device_ptr") )
      return 0;
    v6 = &unk_DCD3;
LABEL_10:
    printk(v6, "lpass_cdc_get_device_ptr");
    return 0;
  }
  if ( !(unsigned int)of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,lpass-cdc") )
  {
    if ( !(unsigned int)__ratelimit(&lpass_cdc_get_device_ptr__rs_4, "lpass_cdc_get_device_ptr") )
      return 0;
    v6 = &unk_DA4A;
    goto LABEL_10;
  }
  if ( a2 <= 4u )
  {
    v4 = *(_QWORD *)(a1 + 152);
    if ( v4 )
      return *(_QWORD *)(v4 + 112LL * a2 + 256);
  }
  if ( (unsigned int)__ratelimit(&lpass_cdc_get_device_ptr__rs_5, "lpass_cdc_get_device_ptr") )
    dev_err(a1, "%s: priv is null or invalid macro\n", "lpass_cdc_get_device_ptr");
  return 0;
}
