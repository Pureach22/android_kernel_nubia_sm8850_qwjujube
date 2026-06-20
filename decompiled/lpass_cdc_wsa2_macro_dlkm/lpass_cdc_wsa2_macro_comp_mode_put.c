__int64 __fastcall lpass_cdc_wsa2_macro_comp_mode_put(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 device_ptr; // x0
  __int64 v6; // x22
  __int64 v7; // x0
  unsigned __int64 v8; // x9
  __int64 v9; // x8

  v2 = *(_QWORD *)(a1 + 128);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v2 + 24), 4);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs, "lpass_cdc_wsa2_macro_get_data") )
      dev_err(*(_QWORD *)(v2 + 24), "%s: null device for macro!\n", "lpass_cdc_wsa2_macro_comp_mode_put");
    return 4294967274LL;
  }
  v6 = *(_QWORD *)(device_ptr + 152);
  if ( !v6 || !*(_QWORD *)(v6 + 248) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs_120, "lpass_cdc_wsa2_macro_get_data") )
      dev_err(*(_QWORD *)(v2 + 24), "%s: priv is null for macro!\n", "lpass_cdc_wsa2_macro_comp_mode_put");
    return 4294967274LL;
  }
  strnstr(a1 + 32, "RX0", 9);
  v7 = strnstr(a1 + 32, "RX1", 9);
  v8 = *(_QWORD *)(a2 + 72);
  if ( v8 > 0x12 )
    return 0;
  v9 = v7;
  *(_DWORD *)(v6 + 4LL * (v9 != 0) + 16) = v8;
  return 0;
}
