__int64 __fastcall lpass_cdc_rx_macro_get_data(__int64 a1, __int64 *a2, _QWORD *a3, __int64 a4)
{
  __int64 device_ptr; // x0
  __int64 v9; // x8
  __int64 result; // x0
  const char *v11; // x1

  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(a1 + 24), 1);
  *a2 = device_ptr;
  if ( !device_ptr )
  {
    result = __ratelimit(&lpass_cdc_rx_macro_get_data__rs, "lpass_cdc_rx_macro_get_data");
    if ( !(_DWORD)result )
      return result;
    v11 = "%s: null device for macro!\n";
    goto LABEL_11;
  }
  v9 = *(_QWORD *)(device_ptr + 152);
  *a3 = v9;
  if ( !v9 )
  {
    result = __ratelimit(&lpass_cdc_rx_macro_get_data__rs_2, "lpass_cdc_rx_macro_get_data");
    if ( !(_DWORD)result )
      return result;
    v11 = "%s: priv is null for macro!\n";
    goto LABEL_11;
  }
  if ( *(_QWORD *)(v9 + 304) )
    return 1;
  result = __ratelimit(&lpass_cdc_rx_macro_get_data__rs_4, "lpass_cdc_rx_macro_get_data");
  if ( (_DWORD)result )
  {
    v11 = "%s: rx_priv component is not initialized!\n";
LABEL_11:
    dev_err(*(_QWORD *)(a1 + 24), v11, a4);
    return 0;
  }
  return result;
}
