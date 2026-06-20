__int64 __fastcall lpass_cdc_va_macro_hw_params(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 device_ptr; // x0
  __int64 v7; // x8
  int v8; // w9
  unsigned int v9; // w21
  __int64 v11; // x19
  __int64 v12; // x9
  unsigned __int64 v13; // x10
  __int64 v14; // x23
  unsigned __int64 v15; // x26
  unsigned int v16; // w22

  v3 = *(_QWORD *)(a3 + 96);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 + 24), 3);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs, "lpass_cdc_va_macro_get_data") )
      dev_err(*(_QWORD *)(v3 + 24), "%s: null device for macro!\n", "lpass_cdc_va_macro_hw_params");
    return 4294967274LL;
  }
  v7 = *(_QWORD *)(device_ptr + 152);
  if ( !v7 || !*(_QWORD *)(v7 + 168) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_get_data__rs_65, "lpass_cdc_va_macro_get_data") )
      dev_err(*(_QWORD *)(v3 + 24), "%s: priv is null for macro!\n", "lpass_cdc_va_macro_hw_params");
    return 4294967274LL;
  }
  v8 = *(_DWORD *)(a2 + 296);
  *(_BYTE *)(v7 + 1537) = (unsigned int)v8 > 0x3E80;
  if ( v8 <= 47999 )
  {
    switch ( v8 )
    {
      case 8000:
        v9 = 0;
        goto LABEL_26;
      case 16000:
        v9 = 1;
        goto LABEL_26;
      case 32000:
        v9 = 3;
        goto LABEL_26;
    }
    goto LABEL_21;
  }
  if ( v8 > 191999 )
  {
    if ( v8 == 192000 )
    {
      v9 = 6;
      goto LABEL_26;
    }
    if ( v8 == 384000 )
    {
      v9 = 7;
      goto LABEL_26;
    }
    goto LABEL_21;
  }
  if ( v8 == 48000 )
  {
    v9 = 4;
    goto LABEL_26;
  }
  if ( v8 != 96000 )
  {
LABEL_21:
    v11 = device_ptr;
    if ( (unsigned int)__ratelimit(&lpass_cdc_va_macro_hw_params__rs, "lpass_cdc_va_macro_hw_params") )
      dev_err(v11, "%s: Invalid TX sample rate: %d\n", "lpass_cdc_va_macro_hw_params", *(_DWORD *)(a2 + 296));
    return 4294967274LL;
  }
  v9 = 5;
LABEL_26:
  v12 = *(unsigned int *)(a3 + 8);
  if ( (unsigned int)v12 > 4 )
  {
LABEL_31:
    __break(0x5512u);
  }
  else
  {
    v13 = 0;
    v14 = v7 + 1256;
    while ( v13 <= 3 && ((unsigned __int8)(-1LL << v13) & (unsigned __int8)*(_QWORD *)(v14 + 8 * v12) & 0xF) != 0 )
    {
      v15 = __clz(__rbit64((unsigned __int8)(-1LL << v13) & (unsigned __int8)*(_QWORD *)(v14 + 8 * v12) & 0xF));
      v16 = ((_DWORD)v15 << 7) + 13312;
      snd_soc_component_update_bits(v3, v16, 15, v9);
      snd_soc_component_update_bits(v3, v16, 16, 16);
      v12 = *(unsigned int *)(a3 + 8);
      v13 = v15 + 1;
      if ( (unsigned int)v12 >= 5 )
        goto LABEL_31;
    }
  }
  return 0;
}
