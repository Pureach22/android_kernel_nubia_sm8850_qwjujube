__int64 __fastcall lpass_cdc_wsa_macro_rx_mux_get(__int64 a1, __int64 a2)
{
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x20
  __int64 device_ptr; // x0
  __int64 v9; // x8
  unsigned __int64 v10; // x9

  v5 = snd_soc_dapm_kcontrol_widget();
  v6 = *(_QWORD *)(v5 + 40);
  v7 = v5;
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v6 - 184), 2);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(v6 - 184), "%s: null device for macro!\n", "lpass_cdc_wsa_macro_rx_mux_get");
    return 4294967274LL;
  }
  v9 = *(_QWORD *)(device_ptr + 152);
  if ( !v9 || !*(_QWORD *)(v9 + 360) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs_122, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(v6 - 184), "%s: priv is null for macro!\n", "lpass_cdc_wsa_macro_rx_mux_get");
    return 4294967274LL;
  }
  v10 = *(unsigned __int8 *)(v7 + 76);
  if ( v10 >= 9 )
  {
    __break(0x5512u);
    __asm { SM3TT2A         V13.4S, V13.4S, V11.S[1] }
    return lpass_cdc_wsa_macro_rx_mux_put();
  }
  else
  {
    *(_QWORD *)(a2 + 72) = *(int *)(v9 + 4 * v10 + 520);
    return 0;
  }
}
