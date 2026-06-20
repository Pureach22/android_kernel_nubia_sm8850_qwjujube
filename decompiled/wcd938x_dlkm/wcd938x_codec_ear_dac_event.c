__int64 __fastcall wcd938x_codec_ear_dac_event(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x8
  __int64 v4; // x19
  __int64 v5; // x20
  int v6; // w0
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x2
  int v14; // w8
  __int64 v15; // x4

  v3 = *(_QWORD *)(a1 + 40);
  v4 = v3 - 208;
  v5 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
  if ( a3 == 8 )
  {
    if ( (*(_BYTE *)(v5 + 3188) & 1) != 0 )
    {
      snd_soc_component_update_bits(v4, 13391, 1, 0);
      v11 = v4;
      v12 = 13321;
      v13 = 4;
    }
    else
    {
      if ( (*(_QWORD *)(v5 + 352) & 0x2000) == 0 )
      {
        snd_soc_component_update_bits(v4, 13390, 4, 0);
        snd_soc_component_update_bits(v4, 13321, 1, 0);
      }
      if ( *(_BYTE *)(v5 + 288) != 1 )
        goto LABEL_18;
      v11 = v4;
      v12 = 13332;
      v13 = 2;
    }
    snd_soc_component_update_bits(v11, v12, v13, 0);
LABEL_18:
    snd_soc_component_update_bits(v4, 12299, 128, 0);
    snd_soc_component_update_bits(v4, 12524, 128, 128);
    return 0;
  }
  if ( a3 != 1 )
    return 0;
  wcd938x_rx_clk_enable(v3 - 208);
  v6 = snd_soc_component_read(v4, 13392);
  *(_DWORD *)(v5 + 3188) = v6;
  if ( (v6 & 1) != 0 )
  {
    snd_soc_component_update_bits(v4, 12524, 128, 0);
    snd_soc_component_update_bits(v4, 13391, 1, 1);
    snd_soc_component_update_bits(v4, 13321, 4, 4);
    v7 = v4;
    v8 = 12299;
    v9 = 128;
    v10 = 128;
    goto LABEL_12;
  }
  snd_soc_component_update_bits(v4, 13390, 4, 4);
  snd_soc_component_update_bits(v4, 13321, 1, 1);
  if ( *(_BYTE *)(v5 + 288) == 1 )
  {
    v7 = v4;
    v8 = 13332;
    v9 = 2;
    v10 = 2;
LABEL_12:
    snd_soc_component_update_bits(v7, v8, v9, v10);
  }
  usleep_range_state(5000, 5010, 2);
  v14 = *(_DWORD *)(v5 + 3184);
  if ( !v14 )
  {
    snd_soc_component_update_bits(v4, 12452, 4, 0);
    v14 = *(_DWORD *)(v5 + 3184);
  }
  v15 = *(unsigned int *)(v5 + 264);
  *(_DWORD *)(v5 + 3184) = v14 + 1;
  wcd_cls_h_fsm(v4, v5 + 224, 1, 1, v15);
  return 0;
}
