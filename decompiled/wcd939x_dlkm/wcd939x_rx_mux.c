__int64 __fastcall wcd939x_rx_mux(__int64 a1, __int64 a2, int a3, __int64 a4, __int64 a5, __int64 a6, __int64 _X6)
{
  __int64 v7; // x23
  __int64 v9; // x22
  unsigned int v10; // w21
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v14; // x3
  __int64 v15; // x8
  __int64 v16; // x3
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 v19; // x2
  __int64 v20; // x3
  __int64 v21; // x3

  v7 = *(_QWORD *)(a1 + 40);
  v9 = *(_QWORD *)(*(_QWORD *)(v7 - 184) + 152LL);
  v10 = *(_DWORD *)(v9 + 284);
  if ( a3 == 8 )
  {
    if ( v7 == 208 )
    {
      if ( (unsigned int)__ratelimit(&wcd939x_config_xtalk__rs, "wcd939x_config_xtalk") )
        printk(&unk_18FA5, "wcd939x_config_xtalk");
    }
    else
    {
      v12 = *(unsigned __int8 *)(a1 + 76);
      if ( (unsigned int)v12 >= 2 )
        goto LABEL_51;
      if ( *(_DWORD *)(v9 + 4 * v12 + 272) )
        snd_soc_component_update_bits(v7 - 208, 13600, 0, 0);
    }
    wcd939x_config_compander(v7 - 208, 8, *(unsigned __int8 *)(a1 + 76));
    if ( *(_BYTE *)(v9 + 280) && v10 == 5 )
    {
      snd_soc_component_update_bits(v7 - 208, 12509, 3, 0);
      snd_soc_component_update_bits(v7 - 208, 12509, 12, 0);
    }
    wcd939x_rx_clk_disable(v7 - 208);
    return 0;
  }
  if ( a3 != 2 )
  {
    if ( a3 == 1 )
    {
      wcd939x_rx_clk_enable(v7 - 208);
      if ( *(_BYTE *)(v9 + 280) )
        wcd939x_config_power_mode(v7 - 208, 1, *(unsigned __int8 *)(a1 + 76), v10);
      wcd939x_config_compander(v7 - 208, 1, *(unsigned __int8 *)(a1 + 76));
      wcd939x_config_xtalk(v7 - 208, 1, *(unsigned __int8 *)(a1 + 76));
    }
    return 0;
  }
  if ( v7 == 208 )
  {
    if ( (unsigned int)__ratelimit(&wcd939x_config_xtalk__rs, "wcd939x_config_xtalk") )
    {
      printk(&unk_18FA5, "wcd939x_config_xtalk");
      if ( !*(_BYTE *)(v9 + 280) )
        goto LABEL_25;
      goto LABEL_18;
    }
    goto LABEL_17;
  }
  v11 = *(unsigned __int8 *)(a1 + 76);
  if ( (unsigned int)v11 < 2 )
  {
    if ( *(_DWORD *)(v9 + 4 * v11 + 272) )
    {
      snd_soc_component_update_bits(v7 - 208, 13600, 15, 15);
      if ( !*(_BYTE *)(v9 + 280) )
        goto LABEL_25;
      goto LABEL_18;
    }
LABEL_17:
    if ( !*(_BYTE *)(v9 + 280) )
      goto LABEL_25;
LABEL_18:
    if ( v10 == 1 || v10 == 6 )
      v14 = 2;
    else
      v14 = 0;
    snd_soc_component_update_bits(v7 - 208, 13569, 2, v14);
LABEL_25:
    if ( v7 == 208 )
    {
      if ( (unsigned int)__ratelimit(&wcd939x_enable_hph_pcm_index__rs, "wcd939x_enable_hph_pcm_index") )
        printk(&unk_18FA5, "wcd939x_enable_hph_pcm_index");
      return 0;
    }
    v15 = *(_QWORD *)(*(_QWORD *)(v7 - 184) + 152LL);
    if ( !*(_BYTE *)(v15 + 280) )
      return 0;
    if ( *(_BYTE *)(a1 + 76) != 1 )
    {
      if ( !*(_BYTE *)(a1 + 76) )
      {
        v16 = *(unsigned __int8 *)(v15 + 3231);
        if ( (_DWORD)v16 != 2 )
        {
          if ( *(_BYTE *)(v15 + 3231) )
          {
LABEL_33:
            snd_soc_component_update_bits(v7 - 208, 13596, 1, 1);
            v17 = v7 - 208;
            v18 = 13596;
            v19 = 2;
            v20 = 6;
LABEL_47:
            snd_soc_component_update_bits(v17, v18, v19, v20);
            return 0;
          }
          v16 = 3;
        }
        snd_soc_component_update_bits(v7 - 208, 13597, 3, v16);
        goto LABEL_33;
      }
      return 0;
    }
    v21 = *(unsigned __int8 *)(v15 + 3231);
    if ( (_DWORD)v21 != 2 )
    {
      if ( *(_BYTE *)(v15 + 3231) )
      {
LABEL_46:
        snd_soc_component_update_bits(v7 - 208, 13598, 2, 2);
        v17 = v7 - 208;
        v18 = 13598;
        v19 = 4;
        v20 = 12;
        goto LABEL_47;
      }
      v21 = 3;
    }
    snd_soc_component_update_bits(v7 - 208, 13599, 3, v21);
    goto LABEL_46;
  }
LABEL_51:
  __break(0x5512u);
  __asm { SUBG            SP, X6, #0xE0, #2 }
  return wcd939x_rx3_mux();
}
