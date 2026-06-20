__int64 __fastcall lpass_cdc_clear_amic_tx_hold(__int64 a1, __int16 a2)
{
  __int64 result; // x0
  __int64 v5; // x8
  void *v6; // x0

  if ( !a1 )
  {
    v6 = &unk_DCD3;
    return printk(v6, "lpass_cdc_clear_amic_tx_hold");
  }
  result = of_device_is_compatible(*(_QWORD *)(a1 + 744), "qcom,lpass-cdc");
  if ( !(_DWORD)result )
  {
    v6 = &unk_DA4A;
    return printk(v6, "lpass_cdc_clear_amic_tx_hold");
  }
  v5 = *(_QWORD *)(a1 + 152);
  if ( !v5 )
    return dev_err(a1, "%s: priv is null\n", "lpass_cdc_clear_amic_tx_hold");
  if ( (unsigned __int16)(a2 - 1) <= 3u )
    return blocking_notifier_call_chain(v5 + 1008, *(&off_112D8 + (unsigned __int16)(a2 - 1)), *(_QWORD *)(v5 + 1000));
  return result;
}
