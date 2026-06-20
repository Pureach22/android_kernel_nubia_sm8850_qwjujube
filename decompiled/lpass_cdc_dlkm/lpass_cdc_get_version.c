__int64 __fastcall lpass_cdc_get_version(__int64 a1)
{
  __int64 v2; // x8

  if ( !a1 )
  {
    printk(&unk_DCD3, "lpass_cdc_get_version");
    return 4294967274LL;
  }
  if ( !(unsigned int)of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 744LL), "qcom,lpass-cdc") )
  {
    dev_err(a1, "%s: child device for macro not added yet\n", "lpass_cdc_get_version");
    return 4294967274LL;
  }
  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  if ( !v2 )
  {
    dev_err(a1, "%s: priv is null\n", "lpass_cdc_get_version");
    return 4294967274LL;
  }
  return *(unsigned int *)(v2 + 848);
}
