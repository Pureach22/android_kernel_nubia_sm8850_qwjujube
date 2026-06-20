__int64 __fastcall lpass_cdc_va_macro_clk_div_get(__int64 a1, unsigned int a2)
{
  __int64 device_ptr; // x0
  __int64 v5; // x8
  __int64 result; // x0

  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(a1 + 24), 3);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
      dev_err(*(_QWORD *)(a1 + 24), "%s: null device for macro!\n", "lpass_cdc_va_macro_clk_div_get");
    return 4294967274LL;
  }
  v5 = *(_QWORD *)(device_ptr + 152);
  if ( !v5 || !*(_QWORD *)(v5 + 168) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
      dev_err(*(_QWORD *)(a1 + 24), "%s: priv is null for macro!\n", "lpass_cdc_va_macro_clk_div_get");
    return 4294967274LL;
  }
  if ( a2 > 3 )
    return 4294967274LL;
  if ( (*(_BYTE *)(v5 + 1537) & 1) == 0 )
    return *(unsigned __int16 *)(v5 + 2LL * a2 + 1320);
  result = *(unsigned __int16 *)(v5 + 2LL * a2 + 1320);
  if ( (_DWORD)result == 5 )
    return *(unsigned __int16 *)(v5 + 2LL * a2 + 1328);
  return result;
}
