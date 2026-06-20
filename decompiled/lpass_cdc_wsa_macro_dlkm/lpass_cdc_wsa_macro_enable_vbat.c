__int64 __fastcall lpass_cdc_wsa_macro_enable_vbat(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x23
  __int64 device_ptr; // x0
  __int64 v7; // x24
  const char *v8; // x20
  __int64 v9; // x22
  __int64 v10; // x19
  int v11; // w0
  unsigned int v12; // w23
  unsigned int v13; // w20
  __int64 v14; // x22
  int v15; // w8
  __int64 v16; // x0
  __int64 v17; // x1
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 result; // x0
  __int64 v21; // x8
  int v22; // w9

  v3 = *(_QWORD *)(a1 + 40);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 2);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(v3 - 184), "%s: null device for macro!\n", "lpass_cdc_wsa_macro_enable_vbat");
    return 4294967274LL;
  }
  v7 = *(_QWORD *)(device_ptr + 152);
  if ( !v7 || !*(_QWORD *)(v7 + 360) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_get_data__rs_122, "lpass_cdc_wsa_macro_get_data") )
      dev_err(*(_QWORD *)(v3 - 184), "%s: priv is null for macro!\n", "lpass_cdc_wsa_macro_enable_vbat");
    return 4294967274LL;
  }
  v8 = *(const char **)(a1 + 8);
  v9 = device_ptr;
  v10 = v3 - 208;
  if ( strcmp(v8, "WSA_RX INT0 VBAT") )
  {
    v11 = strcmp(v8, "WSA_RX INT1 VBAT");
    v12 = v11 == 0;
    if ( v11 )
      v13 = 0;
    else
      v13 = 9352;
    if ( a3 != 8 )
      goto LABEL_9;
LABEL_20:
    snd_soc_component_update_bits(v10, 10504, 1, 0);
    snd_soc_component_update_bits(v10, 10500, 1, 0);
    snd_soc_component_update_bits(v10, 10496, 1, 0);
    snd_soc_component_update_bits(v10, v13, 128, 0);
    snd_soc_component_update_bits(v10, 8580, 2, 2);
    snd_soc_component_update_bits(v10, v13, 2, 0);
    snd_soc_component_update_bits(v10, 8668, 255, 0);
    snd_soc_component_update_bits(v10, 8672, 255, 0);
    snd_soc_component_update_bits(v10, 8676, 255, 0);
    snd_soc_component_update_bits(v10, 8680, 255, 0);
    snd_soc_component_update_bits(v10, 8684, 255, 0);
    snd_soc_component_update_bits(v10, 8688, 255, 0);
    snd_soc_component_update_bits(v10, 8692, 255, 0);
    snd_soc_component_update_bits(v10, 8696, 255, 0);
    snd_soc_component_update_bits(v10, 8700, 255, 0);
    v21 = v7 + 4LL * v12;
    v22 = *(_DWORD *)(v21 + 616) - 1;
    *(_DWORD *)(v21 + 616) = v22;
    if ( !v22 )
    {
      snd_soc_component_update_bits(v10, (32 * v12) | 0x2640, 1, 0);
      snd_soc_component_update_bits(v10, 8472, (unsigned int)(1 << v12), 0);
    }
    snd_soc_component_update_bits(v10, 8580, 1, 0);
    v16 = v10;
    v17 = 8576;
    v18 = 16;
    v19 = 0;
    goto LABEL_23;
  }
  v12 = 0;
  v13 = 9224;
  if ( a3 == 8 )
    goto LABEL_20;
LABEL_9:
  if ( a3 == 1 )
  {
    snd_soc_component_update_bits(v10, 8576, 16, 16);
    snd_soc_component_update_bits(v10, 8580, 1, 1);
    snd_soc_component_update_bits(v10, v13, 128, 128);
    snd_soc_component_update_bits(v10, 8580, 2, 0);
    v14 = v7 + 616;
    v15 = *(_DWORD *)(v7 + 616 + 4LL * v12);
    if ( !v15 )
    {
      snd_soc_component_update_bits(v10, (32 * v12) | 0x2640, 1, 1);
      snd_soc_component_update_bits(v10, 8472, (unsigned int)(1 << v12), (unsigned int)(1 << v12));
      v15 = *(_DWORD *)(v14 + 4LL * v12);
    }
    *(_DWORD *)(v14 + 4LL * v12) = v15 + 1;
    snd_soc_component_update_bits(v10, v13, 2, 2);
    snd_soc_component_update_bits(v10, 8668, 255, 255);
    snd_soc_component_update_bits(v10, 8672, 255, 3);
    snd_soc_component_update_bits(v10, 8676, 255, 0);
    snd_soc_component_update_bits(v10, 8680, 255, 255);
    snd_soc_component_update_bits(v10, 8684, 255, 3);
    snd_soc_component_update_bits(v10, 8688, 255, 0);
    snd_soc_component_update_bits(v10, 8692, 255, 255);
    snd_soc_component_update_bits(v10, 8696, 255, 3);
    snd_soc_component_update_bits(v10, 8700, 255, 0);
    snd_soc_component_update_bits(v10, 10496, 1, 1);
    snd_soc_component_update_bits(v10, 10500, 1, 1);
    v16 = v10;
    v17 = 10504;
    v18 = 1;
    v19 = 1;
LABEL_23:
    snd_soc_component_update_bits(v16, v17, v18, v19);
    return 0;
  }
  result = __ratelimit(&lpass_cdc_wsa_macro_enable_vbat__rs, "lpass_cdc_wsa_macro_enable_vbat");
  if ( (_DWORD)result )
  {
    dev_err(v9, "%s: Invalid event %d\n", "lpass_cdc_wsa_macro_enable_vbat", a3);
    return 0;
  }
  return result;
}
