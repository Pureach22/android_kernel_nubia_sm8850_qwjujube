__int64 __fastcall lpass_cdc_va_macro_enable_tx(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x21
  __int64 device_ptr; // x0
  int *v6; // x20
  __int64 result; // x0

  v3 = *(_QWORD *)(a1 + 40);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 3);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
      dev_err(*(_QWORD *)(v3 - 184), "%s: null device for macro!\n", "lpass_cdc_va_macro_enable_tx");
    return 4294967274LL;
  }
  v6 = *(int **)(device_ptr + 152);
  if ( !v6 || !*((_QWORD *)v6 + 21) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
      dev_err(*(_QWORD *)(v3 - 184), "%s: priv is null for macro!\n", "lpass_cdc_va_macro_enable_tx");
    return 4294967274LL;
  }
  if ( a3 != 4 )
  {
    if ( a3 == 2 )
    {
      if ( v6[393] < 1 )
        return 0;
      result = lpass_cdc_clk_rsc_request_clock(*(_QWORD *)v6, *((unsigned __int16 *)v6 + 766), 0, 0);
      --v6[393];
      return result;
    }
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_enable_tx__rs, "lpass_cdc_va_macro_enable_tx") )
      dev_err(*(_QWORD *)v6, "%s: invalid DAPM event %d\n", "lpass_cdc_va_macro_enable_tx", a3);
    return 4294967274LL;
  }
  result = lpass_cdc_clk_rsc_request_clock(*(_QWORD *)v6, *((unsigned __int16 *)v6 + 766), 0, 1);
  if ( !(_DWORD)result )
    ++v6[393];
  return result;
}
