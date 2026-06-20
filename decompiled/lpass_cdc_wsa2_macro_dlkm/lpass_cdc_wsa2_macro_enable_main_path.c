__int64 __fastcall lpass_cdc_wsa2_macro_enable_main_path(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x20
  __int64 device_ptr; // x0
  __int64 v7; // x8
  __int64 v8; // x20
  __int64 v9; // x21
  unsigned int v10; // w19
  int v11; // w23
  char v12; // w22
  char v13; // w0
  int v14; // w8
  __int64 result; // x0

  v3 = *(_QWORD *)(a1 + 40);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 4);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs, "lpass_cdc_wsa2_macro_get_data") )
      dev_err(*(_QWORD *)(v3 - 184), "%s: null device for macro!\n", "lpass_cdc_wsa2_macro_enable_main_path");
    return 4294967274LL;
  }
  v7 = *(_QWORD *)(device_ptr + 152);
  if ( !v7 || !*(_QWORD *)(v7 + 248) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs_120, "lpass_cdc_wsa2_macro_get_data") )
      dev_err(*(_QWORD *)(v3 - 184), "%s: priv is null for macro!\n", "lpass_cdc_wsa2_macro_enable_main_path");
    return 4294967274LL;
  }
  if ( a3 != 1 )
    return 0;
  v8 = v3 - 208;
  v9 = device_ptr;
  v10 = (*(unsigned __int8 *)(a1 + 76) << 7) + 17408;
  snd_soc_component_update_bits(v8, v10, 64, 64);
  usleep_range_state(500, 510, 2);
  snd_soc_component_update_bits(v8, v10, 64, 0);
  snd_soc_component_update_bits(v8, v10, 32, 32);
  v11 = 8 * *(unsigned __int8 *)(a1 + 76);
  v12 = snd_soc_component_read(v8, (unsigned int)(v11 + 16640));
  v13 = snd_soc_component_read(v8, (unsigned int)(v11 + 16644));
  if ( (v12 & 0xE) == 0xA || (v12 & 0xE0) == 0xA0 || (v14 = v13 & 0xE0, result = 0, v14 == 160) )
  {
    lpass_cdc_wsa_pa_on(v9, 1);
    snd_soc_component_update_bits(v8, v10, 16, 0);
    return 0;
  }
  return result;
}
