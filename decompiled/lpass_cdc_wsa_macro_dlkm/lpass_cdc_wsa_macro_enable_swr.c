__int64 __fastcall lpass_cdc_wsa_macro_enable_swr(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x22
  __int64 device_ptr; // x0
  __int64 v7; // x21
  _QWORD *v8; // x8
  int v10; // w8
  int v11; // w8

  v3 = *(_QWORD *)(a1 + 40);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 2);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(v3 - 184), "%s: null device for macro!\n", "lpass_cdc_wsa_macro_enable_swr");
    return 4294967274LL;
  }
  v7 = *(_QWORD *)(device_ptr + 152);
  if ( !v7 || !*(_QWORD *)(v7 + 360) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs_122, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(v3 - 184), "%s: priv is null for macro!\n", "lpass_cdc_wsa_macro_enable_swr");
    return 4294967274LL;
  }
  if ( a3 != 8 )
  {
    if ( a3 == 1 )
    {
      if ( !strnstr(*(_QWORD *)(a1 + 8), "RX0", 8) && !*(_DWORD *)(v7 + 368) )
        *(_DWORD *)(v7 + 368) = 1;
      if ( !strnstr(*(_QWORD *)(a1 + 8), "RX1", 8) && !*(_DWORD *)(v7 + 372) )
        *(_DWORD *)(v7 + 372) = 1;
      v8 = *(_QWORD **)(v7 + 256);
      if ( v8 )
      {
        swrm_wcd_notify(*v8, 2, 0);
        return 0;
      }
    }
    return 0;
  }
  if ( !strnstr(*(_QWORD *)(a1 + 8), "RX0", 8) )
  {
    v10 = *(_DWORD *)(v7 + 368);
    if ( v10 )
      *(_DWORD *)(v7 + 368) = v10 - 1;
  }
  if ( strnstr(*(_QWORD *)(a1 + 8), "RX1", 8) )
    return 0;
  v11 = *(_DWORD *)(v7 + 372);
  if ( !v11 )
    return 0;
  *(_DWORD *)(v7 + 372) = v11 - 1;
  return 0;
}
