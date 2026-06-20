__int64 __fastcall lpass_cdc_wsa2_macro_enable_echo(__int64 a1)
{
  __int64 v1; // x19
  __int64 device_ptr; // x0
  __int64 v4; // x22
  __int64 v5; // x19
  __int64 v6; // x20
  unsigned int v7; // w0
  const char *v8; // x8
  unsigned int v9; // w21
  int v10; // w0
  unsigned int v11; // w8
  unsigned int v12; // w8
  const char *v13; // x1
  int v15; // w20
  int v16; // w20

  v1 = *(_QWORD *)(a1 + 40);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v1 - 184), 4);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs, "lpass_cdc_wsa2_macro_get_data") )
    {
      v13 = "%s: null device for macro!\n";
      goto LABEL_18;
    }
    return 4294967274LL;
  }
  v4 = *(_QWORD *)(device_ptr + 152);
  if ( !v4 || !*(_QWORD *)(v4 + 248) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs_120, "lpass_cdc_wsa2_macro_get_data") )
    {
      v13 = "%s: priv is null for macro!\n";
LABEL_18:
      dev_err(*(_QWORD *)(v1 - 184), v13, "lpass_cdc_wsa2_macro_enable_echo");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v5 = v1 - 208;
  v6 = device_ptr;
  v7 = snd_soc_component_read(v5, 16656);
  v8 = *(const char **)(a1 + 8);
  v9 = v7;
  v10 = strcmp(v8, "WSA2 RX_MIX EC0_MUX");
  v11 = v9 >> 3;
  if ( !v10 )
    LOBYTE(v11) = v9;
  v12 = (v11 & 7) - 1;
  if ( v12 >= 2 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_enable_echo__rs, "lpass_cdc_wsa2_macro_enable_echo") )
      dev_err(v6, "%s: EC mix control not set correctly\n", "lpass_cdc_wsa2_macro_enable_echo");
    return 4294967274LL;
  }
  v15 = (unsigned __int16)v12;
  if ( *(_DWORD *)(v4 + 4LL * (unsigned __int16)v12 + 24) )
  {
    snd_soc_component_update_bits(v5, 16656, (unsigned int)(1 << v12), (unsigned int)(1 << v12));
    v16 = v15 << 6;
    snd_soc_component_update_bits(v5, v16 | 0x4680u, 1, 1);
    snd_soc_component_update_bits(v5, v16 | 0x4684u, 30, 8);
  }
  return 0;
}
