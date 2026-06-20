__int64 __fastcall lpass_cdc_wsa_macro_set_digital_volume(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v3; // x23
  __int64 device_ptr; // x0
  __int64 v7; // x22
  unsigned int v8; // w0
  int v9; // w8
  unsigned int v10; // w19
  char v11; // w0
  int v12; // w9
  const char *v13; // x1

  v2 = *(_QWORD *)(a1 + 120);
  v3 = *(_QWORD *)(a1 + 128);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 + 24), 2);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs, "lpass_cdc_wsa_macro_get_data") )
    {
      v13 = "%s: null device for macro!\n";
      goto LABEL_20;
    }
    return 4294967274LL;
  }
  v7 = *(_QWORD *)(device_ptr + 152);
  if ( !v7 || !*(_QWORD *)(v7 + 360) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs_122, "lpass_cdc_wsa_macro_get_data") )
    {
      v13 = "%s: priv is null for macro!\n";
LABEL_20:
      dev_err(*(_QWORD *)(v3 + 24), v13, "lpass_cdc_wsa_macro_set_digital_volume");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v8 = snd_soc_put_volsw(a1, a2);
  v9 = *(_DWORD *)(v2 + 12);
  if ( v9 == 9364 )
  {
    v10 = v8;
    v11 = snd_soc_component_read(*(_QWORD *)(v7 + 360), 9364);
    v12 = *(_DWORD *)(v7 + 688);
    *(_BYTE *)(v7 + 677) = v11;
    goto LABEL_13;
  }
  if ( v9 != 9236 )
  {
    if ( (unsigned int)__ratelimit(
                         &lpass_cdc_wsa_macro_set_digital_volume__rs_265,
                         "lpass_cdc_wsa_macro_set_digital_volume") )
      dev_err(*(_QWORD *)v7, "%s: Incorrect RX Path selected\n", "lpass_cdc_wsa_macro_set_digital_volume");
    return 4294967274LL;
  }
  v10 = v8;
  v11 = snd_soc_component_read(*(_QWORD *)(v7 + 360), 9236);
  v12 = *(_DWORD *)(v7 + 688);
  *(_BYTE *)(v7 + 676) = v11;
LABEL_13:
  if ( *(_BYTE *)(v7 + 154) == 1 )
  {
    if ( v12 )
      snd_soc_component_update_bits(
        *(_QWORD *)(v7 + 360),
        *(unsigned int *)(v2 + 12),
        255,
        (unsigned __int8)(v11 - v12));
  }
  return v10;
}
