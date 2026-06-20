__int64 __fastcall lpass_cdc_wsa_macro_deinit(__int64 a1)
{
  __int64 device_ptr; // x0
  __int64 v3; // x8

  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(a1 + 24), 2);
  if ( device_ptr )
  {
    v3 = *(_QWORD *)(device_ptr + 152);
    if ( v3 && *(_QWORD *)(v3 + 360) )
    {
      *(_QWORD *)(v3 + 360) = 0;
      return 0;
    }
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs_122, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(a1 + 24), "%s: priv is null for macro!\n", "lpass_cdc_wsa_macro_deinit");
  }
  else if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs, "lpass_cdc_wsa_macro_get_data") )
  {
    dev_err(*(_QWORD *)(a1 + 24), "%s: null device for macro!\n", "lpass_cdc_wsa_macro_deinit");
  }
  return 4294967274LL;
}
