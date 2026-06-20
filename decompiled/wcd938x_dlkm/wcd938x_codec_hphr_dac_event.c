__int64 __fastcall wcd938x_codec_hphr_dac_event(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x20

  v3 = *(_QWORD *)(a1 + 40);
  v4 = v3 - 208;
  switch ( a3 )
  {
    case 8:
      v5 = v3 - 208;
      v6 = 12598;
      v7 = 15;
      v8 = 1;
      goto LABEL_12;
    case 2:
      v9 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
      snd_soc_component_update_bits(v4, 12598, 15, 2);
      if ( *(_BYTE *)(v9 + 289) == 1 )
      {
        snd_soc_component_update_bits(v4, 13332, 1, 1);
        if ( *(_BYTE *)(v9 + 288) != 1 || (snd_soc_component_read(v4, 13332) & 2) != 0 )
          usleep_range_state(5000, 5010, 2);
        v5 = v4;
        v6 = 12602;
        v7 = 2;
        v8 = 0;
      }
      else
      {
        snd_soc_component_update_bits(v4, 13332, 1, 0);
        v5 = v4;
        v6 = 12502;
        v7 = 32;
        v8 = 32;
      }
      goto LABEL_12;
    case 1:
      wcd938x_rx_clk_enable(v3 - 208);
      snd_soc_component_update_bits(v4, 13321, 2, 2);
      snd_soc_component_update_bits(v4, 13390, 8, 8);
      v5 = v4;
      v6 = 12505;
      v7 = 128;
      v8 = 0;
LABEL_12:
      snd_soc_component_update_bits(v5, v6, v7, v8);
      break;
  }
  return 0;
}
