__int64 __fastcall lpass_cdc_wsa_macro_mclk_event(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x21
  __int64 device_ptr; // x0
  __int64 v6; // x19
  __int64 result; // x0

  v3 = *(_QWORD *)(a1 + 40);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 2);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(v3 - 184), "%s: null device for macro!\n", "lpass_cdc_wsa_macro_mclk_event");
    return 4294967274LL;
  }
  v6 = *(_QWORD *)(device_ptr + 152);
  if ( !v6 || !*(_QWORD *)(v6 + 360) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs_122, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(v3 - 184), "%s: priv is null for macro!\n", "lpass_cdc_wsa_macro_mclk_event");
    return 4294967274LL;
  }
  if ( a3 != 8 )
  {
    if ( a3 == 1 )
    {
      result = lpass_cdc_wsa_macro_mclk_enable(*(_QWORD **)(device_ptr + 152), 1);
      if ( (_DWORD)result )
        *(_BYTE *)(v6 + 154) = 0;
      else
        *(_BYTE *)(v6 + 154) = 1;
      return result;
    }
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_mclk_event__rs, "lpass_cdc_wsa_macro_mclk_event") )
      dev_err(*(_QWORD *)v6, "%s: invalid DAPM event %d\n", "lpass_cdc_wsa_macro_mclk_event", a3);
    return 4294967274LL;
  }
  if ( *(_BYTE *)(v6 + 154) == 1 )
  {
    lpass_cdc_wsa_macro_mclk_enable(*(_QWORD **)(device_ptr + 152), 0);
    *(_BYTE *)(v6 + 154) = 0;
  }
  return 0;
}
