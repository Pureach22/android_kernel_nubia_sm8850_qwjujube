__int64 __fastcall lpass_cdc_is_va_macro_registered(__int64 a1)
{
  __int64 v2; // x8
  char v3; // w8

  if ( !a1 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_is_va_macro_registered__rs, "lpass_cdc_is_va_macro_registered") )
      printk(&unk_DCD3, "lpass_cdc_is_va_macro_registered");
    goto LABEL_10;
  }
  if ( !(unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 744LL), "qcom,lpass-cdc") )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_is_va_macro_registered__rs_18, "lpass_cdc_is_va_macro_registered") )
      dev_err(a1, "%s: child device calling is not added yet\n", "lpass_cdc_is_va_macro_registered");
    goto LABEL_10;
  }
  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  if ( !v2 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_is_va_macro_registered__rs_20, "lpass_cdc_is_va_macro_registered") )
      dev_err(a1, "%s: priv is null\n", "lpass_cdc_is_va_macro_registered");
LABEL_10:
    v3 = 0;
    return v3 & 1;
  }
  v3 = *(_BYTE *)(v2 + 220);
  return v3 & 1;
}
