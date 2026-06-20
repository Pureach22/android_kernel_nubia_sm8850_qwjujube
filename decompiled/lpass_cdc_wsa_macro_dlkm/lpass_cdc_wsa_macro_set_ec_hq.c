__int64 __fastcall lpass_cdc_wsa_macro_set_ec_hq(__int64 a1, __int64 a2)
{
  __int64 v4; // x19
  int v5; // w21
  __int64 v6; // x20
  __int64 device_ptr; // x0
  __int64 v8; // x8

  v4 = *(_QWORD *)(a1 + 128);
  v5 = *(_DWORD *)(a2 + 72);
  v6 = *(unsigned int *)(*(_QWORD *)(a1 + 120) + 20LL);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v4 + 24), 2);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(v4 + 24), "%s: null device for macro!\n", "lpass_cdc_wsa_macro_set_ec_hq");
    return 4294967274LL;
  }
  v8 = *(_QWORD *)(device_ptr + 152);
  if ( !v8 || !*(_QWORD *)(v8 + 360) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs_122, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(v4 + 24), "%s: priv is null for macro!\n", "lpass_cdc_wsa_macro_set_ec_hq");
    return 4294967274LL;
  }
  if ( (unsigned int)v6 > 1 )
  {
    __break(0x5512u);
    __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
    return lpass_cdc_wsa_macro_pbr_enable_get();
  }
  else
  {
    *(_DWORD *)(v8 + 4 * v6 + 24) = v5;
    return 0;
  }
}
