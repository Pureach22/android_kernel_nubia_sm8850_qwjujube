__int64 __fastcall lpass_cdc_tx_macro_get_data(__int64 a1, __int64 *a2, _QWORD *a3, __int64 a4)
{
  __int64 device_ptr; // x0
  __int64 v9; // x8
  __int64 result; // x0

  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(a1 + 24), 0);
  *a2 = device_ptr;
  if ( !device_ptr )
  {
    result = __ratelimit(&lpass_cdc_tx_macro_get_data__rs, "lpass_cdc_tx_macro_get_data");
    if ( !(_DWORD)result )
      return result;
    dev_err(*(_QWORD *)(a1 + 24), "%s: null device for macro!\n", a4);
    return 0;
  }
  v9 = *(_QWORD *)(device_ptr + 152);
  *a3 = v9;
  if ( !v9 )
  {
    result = __ratelimit(&lpass_cdc_tx_macro_get_data__rs_84, "lpass_cdc_tx_macro_get_data");
    if ( !(_DWORD)result )
      return result;
    dev_err(*(_QWORD *)(a1 + 24), "%s: priv is null for macro!\n", a4);
    return 0;
  }
  if ( *(_QWORD *)(v9 + 120) )
    return 1;
  result = __ratelimit(&lpass_cdc_tx_macro_get_data__rs_85, "lpass_cdc_tx_macro_get_data");
  if ( (_DWORD)result )
  {
    dev_err(*(_QWORD *)(a1 + 24), "%s: tx_priv->component not initialized!\n", a4);
    return 0;
  }
  return result;
}
