__int64 __fastcall lpass_cdc_wsa2_macro_enable_interpolator(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x25
  __int64 device_ptr; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x26
  __int64 v10; // x23
  const char *v11; // x20
  int v12; // w24
  const char *v13; // x1
  unsigned int v15; // w21
  __int64 v16; // x0
  __int64 v17; // x1
  __int64 v18; // x2
  unsigned __int8 v19; // w21
  unsigned __int8 v20; // w21
  __int64 v21; // x0
  __int64 v23; // x22
  unsigned int v24; // w8
  unsigned int v25; // w21
  __int64 v26; // x1
  int v27; // w9
  __int64 v28; // x3
  bool v30; // w8
  __int64 v31; // x23
  unsigned int v32; // w8
  unsigned int v33; // w22
  int v34; // w9
  __int64 v35; // x3
  bool v37; // w8
  __int64 v38; // x0
  __int64 v39; // x1
  unsigned int v40; // w21
  __int64 v41; // x0
  __int64 v42; // x22
  __int64 v43; // x1

  v3 = *(_QWORD *)(a1 + 40);
  device_ptr = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 4);
  if ( !device_ptr )
    goto LABEL_107;
  v7 = *(_QWORD *)(device_ptr + 152);
  if ( !v7 || !*(_QWORD *)(v7 + 248) )
  {
LABEL_11:
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs_120, "lpass_cdc_wsa2_macro_get_data") )
    {
      v13 = "%s: priv is null for macro!\n";
LABEL_16:
      dev_err(*(_QWORD *)(v3 - 184), v13, "lpass_cdc_wsa2_macro_enable_interpolator");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  v8 = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 4);
  if ( !v8 )
  {
LABEL_107:
    if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs, "lpass_cdc_wsa2_macro_get_data") )
    {
      v13 = "%s: null device for macro!\n";
      goto LABEL_16;
    }
    return 4294967274LL;
  }
  v9 = *(_QWORD *)(v8 + 152);
  if ( !v9 )
    goto LABEL_11;
  v10 = *(_QWORD *)(v9 + 248);
  if ( !v10 )
    goto LABEL_11;
  v11 = *(const char **)(a1 + 8);
  v12 = strcmp(v11, "WSA2_RX INT0 INTERP");
  if ( v12 )
  {
    if ( strcmp(v11, "WSA2_RX INT1 INTERP") )
    {
      if ( (unsigned int)__ratelimit(
                           &lpass_cdc_wsa2_macro_enable_interpolator__rs,
                           "lpass_cdc_wsa2_macro_enable_interpolator") )
        dev_err(*(_QWORD *)(v3 - 184), "%s: Interpolator reg not found\n", "lpass_cdc_wsa2_macro_enable_interpolator");
      return 4294967274LL;
    }
    v15 = 17536;
  }
  else
  {
    v15 = 17408;
  }
  if ( a3 == 8 )
  {
    snd_soc_component_update_bits(v3 - 208, 17416, 8, 8);
    v21 = lpass_cdc_wsa2_macro_config_compander(v3 - 208, *(unsigned __int8 *)(a1 + 76), 8);
    v31 = *(unsigned __int8 *)(a1 + 76);
    if ( *(_BYTE *)(v9 + 640) )
    {
      if ( *(_BYTE *)(a1 + 76) )
        v32 = 0;
      else
        v32 = 17424;
      if ( (_DWORD)v31 == 1 )
        v33 = 2;
      else
        v33 = v31 == 0;
      if ( (_DWORD)v31 == 1 )
        v26 = 17552;
      else
        v26 = v32;
      if ( (unsigned int)v31 >= 2 )
        goto LABEL_104;
      v34 = *(_DWORD *)(v9 + 644);
      v35 = 0;
      v37 = v34 == 2 && *(unsigned __int16 *)(v9 + 4 * v31 + 16) > 4u;
      if ( v34 && !v37 )
      {
        if ( *(_BYTE *)(v9 + 600) == 1 )
          v35 = (unsigned __int8)(*(_DWORD *)(v9 + 468) == 0) << 7;
        else
          v35 = 0;
      }
      snd_soc_component_update_bits(v3 - 208, v26, 128, v35);
      snd_soc_component_update_bits(v3 - 208, 18304, v33, 0);
      snd_soc_component_write(v3 - 208, 18320, 0);
      LODWORD(v31) = *(unsigned __int8 *)(a1 + 76);
    }
    v41 = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 4);
    if ( v41 )
    {
      v42 = *(_QWORD *)(v41 + 152);
      if ( v42 && *(_QWORD *)(v42 + 248) )
      {
        if ( *(_DWORD *)(v42 + 4LL * ((_DWORD)v31 == 1) + 480) )
        {
          if ( (_DWORD)v31 == 1 )
            v43 = 18020;
          else
            v43 = 17988;
          snd_soc_component_update_bits(v3 - 208, v43, 1, 0);
          lpass_cdc_wsa2_macro_enable_softclip_clk(v3 - 208, v42, (_DWORD)v31 == 1, 0);
        }
      }
      else if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs_120, "lpass_cdc_wsa2_macro_get_data") )
      {
        dev_err(*(_QWORD *)(v3 - 184), "%s: priv is null for macro!\n", "lpass_cdc_wsa2_macro_config_softclip");
      }
    }
    else if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs, "lpass_cdc_wsa2_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v3 - 184), "%s: null device for macro!\n", "lpass_cdc_wsa2_macro_config_softclip");
    }
    lpass_cdc_was_macro_config_pbr(v3 - 208, *(unsigned __int8 *)(a1 + 76), 8);
    v16 = v3 - 208;
    v17 = v15;
    v18 = 8;
    goto LABEL_102;
  }
  if ( a3 != 2 )
  {
    if ( a3 != 1 )
      return 0;
    v16 = v3 - 208;
    v17 = v15;
    v18 = 1;
LABEL_102:
    lpass_cdc_wsa2_macro_enable_prim_interpolator(v16, v17, v18);
    return 0;
  }
  if ( !v12 )
  {
    v19 = *(_BYTE *)(v9 + 548) - *(_BYTE *)(v9 + 560);
    if ( (unsigned int)snd_soc_component_read(v10, 17428) != v19 )
      snd_soc_component_update_bits(*(_QWORD *)(v9 + 248), 17428, 255, v19);
  }
  if ( !strcmp(*(const char **)(a1 + 8), "WSA2_RX INT1 INTERP") )
  {
    v20 = *(_BYTE *)(v9 + 549) - *(_BYTE *)(v9 + 560);
    if ( (unsigned int)snd_soc_component_read(*(_QWORD *)(v9 + 248), 17556) != v20 )
      snd_soc_component_update_bits(*(_QWORD *)(v9 + 248), 17556, 255, v20);
  }
  v21 = lpass_cdc_wsa2_macro_config_compander(v3 - 208, *(unsigned __int8 *)(a1 + 76), 2);
  v23 = *(unsigned __int8 *)(a1 + 76);
  if ( !*(_BYTE *)(v9 + 640) )
  {
LABEL_73:
    v38 = lpass_cdc_get_device_ptr(*(_QWORD *)(v3 - 184), 4);
    if ( v38 )
    {
      v39 = *(_QWORD *)(v38 + 152);
      if ( v39 && *(_QWORD *)(v39 + 248) )
      {
        if ( *(_DWORD *)(v39 + 4LL * ((_DWORD)v23 == 1) + 480) )
        {
          if ( (_DWORD)v23 == 1 )
            v40 = 18020;
          else
            v40 = 17988;
          lpass_cdc_wsa2_macro_enable_softclip_clk(v3 - 208, v39, (_DWORD)v23 == 1, 1);
          snd_soc_component_update_bits(v3 - 208, v40, 1, 1);
        }
      }
      else if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs_120, "lpass_cdc_wsa2_macro_get_data") )
      {
        dev_err(*(_QWORD *)(v3 - 184), "%s: priv is null for macro!\n", "lpass_cdc_wsa2_macro_config_softclip");
      }
    }
    else if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_get_data__rs, "lpass_cdc_wsa2_macro_get_data") )
    {
      dev_err(*(_QWORD *)(v3 - 184), "%s: null device for macro!\n", "lpass_cdc_wsa2_macro_config_softclip");
    }
    lpass_cdc_was_macro_config_pbr(v3 - 208, *(unsigned __int8 *)(a1 + 76), 2);
    if ( *(_DWORD *)(v9 + 468) )
      snd_soc_component_update_bits(v3 - 208, 17416, 8, 0);
    return 0;
  }
  if ( *(_BYTE *)(a1 + 76) )
    v24 = 0;
  else
    v24 = 17424;
  if ( (_DWORD)v23 == 1 )
    v25 = 2;
  else
    v25 = v23 == 0;
  if ( (_DWORD)v23 == 1 )
    v26 = 17552;
  else
    v26 = v24;
  if ( (unsigned int)v23 < 2 )
  {
    v27 = *(_DWORD *)(v9 + 644);
    v28 = 0;
    v30 = v27 == 2 && *(unsigned __int16 *)(v9 + 4 * v23 + 16) > 4u;
    if ( v27 && !v30 )
    {
      if ( *(_BYTE *)(v9 + 600) == 1 )
        v28 = (unsigned __int8)(*(_DWORD *)(v9 + 468) == 0) << 7;
      else
        v28 = 0;
    }
    snd_soc_component_update_bits(v3 - 208, v26, 128, v28);
    snd_soc_component_update_bits(v3 - 208, 18304, v25, v25);
    LODWORD(v23) = *(unsigned __int8 *)(a1 + 76);
    goto LABEL_73;
  }
LABEL_104:
  __break(0x5512u);
  __asm { SUBG            SP, X6, #0xE0, #2 }
  return lpass_cdc_wsa2_macro_spk_boost_event(v21, v26);
}
