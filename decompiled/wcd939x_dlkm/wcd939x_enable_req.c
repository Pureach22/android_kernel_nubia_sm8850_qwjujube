__int64 __fastcall wcd939x_enable_req(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x8
  __int64 v5; // x19
  __int64 v6; // x22
  __int64 v7; // x2
  __int64 updated; // x0
  unsigned int v10; // w23
  unsigned int v11; // w8
  __int64 v12; // x2
  unsigned __int64 v13; // x8
  __int64 v14; // x21
  int v15; // w24
  unsigned int v16; // w21
  __int64 v17; // x0
  __int64 v18; // x2
  __int64 v19; // x3

  v3 = *(_QWORD *)(a1 + 40);
  v5 = v3 - 208;
  v6 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
  if ( a3 == 8 )
  {
    v11 = *(unsigned __int8 *)(a1 + 76);
    if ( v11 > 1 )
    {
      if ( v11 == 2 )
      {
        snd_soc_component_update_bits(v5, 13329, 15, 0);
        v12 = 64;
        goto LABEL_32;
      }
      if ( v11 == 3 )
      {
        snd_soc_component_update_bits(v5, 13329, 240, 0);
        v12 = 128;
        goto LABEL_32;
      }
    }
    else
    {
      if ( !*(_BYTE *)(a1 + 76) )
      {
        snd_soc_component_update_bits(v5, 13328, 15, 0);
        v12 = 16;
        goto LABEL_32;
      }
      if ( v11 == 1 )
      {
        snd_soc_component_update_bits(v5, 13328, 240, 0);
        v12 = 32;
LABEL_32:
        snd_soc_component_update_bits(v5, 13321, v12, 0);
      }
    }
    if ( !*(_DWORD *)(v6 + 304) )
    {
      snd_soc_component_update_bits(v5, 13320, 16, 0);
      snd_soc_component_update_bits(v5, 13320, 8, 0);
      if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 256) + 112LL) + 88LL) )
      {
        if ( (snd_soc_component_read(v5, 12297) & 0xC0) == 0 && !*(_DWORD *)(v6 + 304) )
          wcd_usbss_audio_config(0, 0, 1);
      }
    }
    return 0;
  }
  if ( a3 != 1 )
    return 0;
  snd_soc_component_update_bits(v3 - 208, 13320, 8, 8);
  snd_soc_component_update_bits(v5, 13320, 16, 16);
  snd_soc_component_update_bits(v5, 13399, 2, 2);
  snd_soc_component_update_bits(v5, 13399, 1, 0);
  if ( *(unsigned __int8 *)(a1 + 76) >= 4u )
  {
    updated = __ratelimit(&wcd939x_tx_channel_config__rs, "wcd939x_tx_channel_config");
    if ( (_DWORD)updated )
      updated = printk(&unk_19A47, "wcd939x_tx_channel_config");
    v10 = -22;
  }
  else
  {
    v7 = (unsigned int)dword_274C0[*(unsigned __int8 *)(a1 + 76)];
    updated = snd_soc_component_update_bits(v5, dword_274D0[*(unsigned __int8 *)(a1 + 76)], v7, (unsigned int)v7);
    v10 = 0;
  }
  v13 = *(unsigned __int8 *)(a1 + 76);
  if ( v13 >= 4 )
  {
    __break(0x5512u);
    __asm { SUBG            SP, X6, #0xE0, #2 }
    return wcd939x_tx_swr_ctrl(updated);
  }
  v14 = *(unsigned int *)(v6 + 4 * v13 + 288);
  if ( (unsigned int)v14 >= 7 )
  {
    if ( (unsigned int)__ratelimit(&wcd939x_get_adc_mode__rs, "wcd939x_get_adc_mode") )
      printk(&unk_18C4C, "wcd939x_get_adc_mode");
    v15 = -22;
  }
  else
  {
    v15 = dword_26818[v14];
  }
  v16 = *(unsigned __int8 *)(a1 + 76);
  if ( v16 > 1 )
  {
    if ( v16 == 2 )
    {
      snd_soc_component_update_bits(v5, 13329, 15, v15 & 0xEF);
      v17 = v5;
      v18 = 64;
      v19 = 64;
    }
    else
    {
      if ( v16 != 3 )
        goto LABEL_42;
      snd_soc_component_update_bits(v5, 13329, 240, (16 * v15) & 0xEF0);
      v17 = v5;
      v18 = 128;
      v19 = 128;
    }
  }
  else if ( *(_BYTE *)(a1 + 76) )
  {
    if ( v16 != 1 )
      goto LABEL_42;
    if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v6 + 256) + 112LL) + 88LL) )
      wcd_usbss_audio_config(0, 0, 4);
    snd_soc_component_update_bits(v5, 13328, 240, (16 * v15) & 0xEF0);
    v17 = v5;
    v18 = 32;
    v19 = 32;
  }
  else
  {
    snd_soc_component_update_bits(v5, 13328, 15, v15 & 0xEF);
    v17 = v5;
    v18 = 16;
    v19 = 16;
  }
  snd_soc_component_update_bits(v17, 13321, v18, v19);
  v16 = *(unsigned __int8 *)(a1 + 76);
LABEL_42:
  if ( v16 >= 4 )
  {
    if ( (unsigned int)__ratelimit(&wcd939x_tx_channel_config__rs, "wcd939x_tx_channel_config") )
      printk(&unk_19A47, "wcd939x_tx_channel_config");
    return v10 | 0xFFFFFFEA;
  }
  else
  {
    snd_soc_component_update_bits(v5, dword_274D0[v16], (unsigned int)dword_274C0[v16], 0);
    return v10;
  }
}
