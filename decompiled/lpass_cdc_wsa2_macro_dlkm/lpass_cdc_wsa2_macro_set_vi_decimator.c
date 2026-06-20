__int64 __fastcall lpass_cdc_wsa2_macro_set_vi_decimator(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 device_ptr; // x0
  __int64 v5; // x8

  v2 = *(_QWORD *)(a1 + 128);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v2 + 24), 4);
  if ( device_ptr )
  {
    v5 = *(_QWORD *)(device_ptr + 152);
    if ( v5 && *(_QWORD *)(v5 + 248) )
    {
      *(_BYTE *)(v5 + 665) = *(_QWORD *)(a2 + 72) != 0;
      return 0;
    }
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs_120, "lpass_cdc_wsa2_macro_get_data") )
      dev_err(*(_QWORD *)(v2 + 24), "%s: priv is null for macro!\n", "lpass_cdc_wsa2_macro_set_vi_decimator");
  }
  else if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs, "lpass_cdc_wsa2_macro_get_data") )
  {
    dev_err(*(_QWORD *)(v2 + 24), "%s: null device for macro!\n", "lpass_cdc_wsa2_macro_set_vi_decimator");
  }
  return 4294967274LL;
}
