__int64 __fastcall lpass_cdc_wsa2_macro_mute_stream(__int64 a1, int a2)
{
  __int64 result; // x0
  __int64 v3; // x19
  __int64 device_ptr; // x0
  __int64 v6; // x21
  unsigned int v7; // w8
  __int64 v8; // x8
  __int64 v9; // x20
  __int64 v10; // x20
  __int64 regmap; // x0
  __int64 v12; // x20

  if ( a2 )
    return 0;
  v3 = *(_QWORD *)(a1 + 96);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 + 24), 4);
  if ( !device_ptr )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs, "lpass_cdc_wsa2_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v3 + 24), "%s: null device for macro!\n", "lpass_cdc_wsa2_macro_mute_stream");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v6 = *(_QWORD *)(device_ptr + 152);
  if ( !v6 || !*(_QWORD *)(v6 + 248) )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs_120, "lpass_cdc_wsa2_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v3 + 24), "%s: priv is null for macro!\n", "lpass_cdc_wsa2_macro_mute_stream");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v7 = *(_DWORD *)(a1 + 8);
  if ( v7 == 3 )
    goto LABEL_9;
  if ( v7 != 2 )
  {
    if ( v7 != 1 )
      goto LABEL_23;
LABEL_9:
    lpass_cdc_wsa_pa_on(device_ptr, 0);
    v8 = a1;
    if ( (*(_DWORD *)(a1 + 8) | 2) == 3 )
    {
      v9 = *(_QWORD *)(a1 + 96);
      snd_soc_component_update_bits(v9, 17408, 16, 0);
      snd_soc_component_update_bits(v9, 17432, 16, 0);
      snd_soc_component_update_bits(v9, 17536, 16, 0);
      snd_soc_component_update_bits(v9, 17560, 16, 0);
      v8 = a1;
    }
    if ( (*(_BYTE *)(v6 + 665) & 1) != 0 )
      goto LABEL_22;
    goto LABEL_20;
  }
  v10 = device_ptr;
  regmap = dev_get_regmap(*(_QWORD *)(*(_QWORD *)v6 + 96LL), 0);
  if ( !regmap )
  {
    dev_err(v10, "%s: regmap is NULL\n", "lpass_cdc_wsa2_macro_mute_stream");
    goto LABEL_21;
  }
  v12 = regmap;
  regmap_update_bits_base(regmap, 16968, 3, 0, 0, 0, 0);
  regmap_update_bits_base(v12, 17000, 3, 0, 0, 0, 0);
  regmap_update_bits_base(v12, 17032, 3, 0, 0, 0, 0);
  regmap_update_bits_base(v12, 17064, 3, 0, 0, 0, 0);
  v8 = a1;
  if ( (*(_BYTE *)(v6 + 665) & 1) == 0 )
  {
LABEL_20:
    lpass_cdc_wsa2_macro_enable_vi_decimator(v3);
LABEL_21:
    v8 = a1;
  }
LABEL_22:
  v7 = *(_DWORD *)(v8 + 8);
LABEL_23:
  if ( v7 >= 8 )
  {
    __break(0x5512u);
    JUMPOUT(0xE59C);
  }
  if ( (*(_QWORD *)(v6 + 264 + 8LL * v7) & 0x10) == 0 && (*(_QWORD *)(v6 + 264 + 8LL * v7) & 0x20) == 0 )
    return 0;
  result = *(_QWORD *)(v6 + 656);
  if ( result )
  {
    if ( (unsigned int)readl((unsigned int *)result) != 1 )
      writel(1u, *(unsigned int **)(v6 + 656));
    return 0;
  }
  return result;
}
