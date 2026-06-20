__int64 __fastcall wcd939x_codec_hphr_dac_event(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x3
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3

  v3 = *(_QWORD *)(a1 + 40);
  v4 = v3 - 208;
  if ( a3 == 8 )
  {
    snd_soc_component_update_bits(v3 - 208, 12609, 63, 1);
    v6 = v4;
    v7 = 0;
LABEL_14:
    snd_soc_component_update_bits(v6, 13390, 8, v7);
    return 0;
  }
  v5 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
  if ( a3 == 2 )
  {
    snd_soc_component_update_bits(v4, 12609, 63, 29);
    if ( *(_BYTE *)(v5 + 280) )
      goto LABEL_18;
    if ( *(_BYTE *)(v5 + 308) == 1 )
    {
      snd_soc_component_update_bits(v4, 13332, 1, 1);
      if ( *(_BYTE *)(v5 + 309) != 1 || (snd_soc_component_read(v4, 13332) & 2) != 0 )
        usleep_range_state(5000, 5010, 2);
      v8 = v4;
      v9 = 12602;
      v10 = 2;
      v11 = 0;
    }
    else
    {
      snd_soc_component_update_bits(v4, 13332, 1, 0);
      v8 = v4;
      v9 = 12502;
      v10 = 32;
      v11 = 32;
    }
    snd_soc_component_update_bits(v8, v9, v10, v11);
    if ( *(_BYTE *)(v5 + 280) )
    {
LABEL_18:
      snd_soc_component_write(v4, 12453, 235);
      if ( *(_DWORD *)(v5 + 284) == 4 )
        snd_soc_component_write(v4, 12613, 82);
      else
        snd_soc_component_write(v4, 12613, 100);
    }
  }
  else if ( a3 == 1 )
  {
    if ( !*(_BYTE *)(v5 + 280) )
      snd_soc_component_update_bits(v4, 12505, 128, 0);
    wcd939x_config_2Vpk_mode(v4, v5, 0);
    v6 = v4;
    v7 = 8;
    goto LABEL_14;
  }
  return 0;
}
