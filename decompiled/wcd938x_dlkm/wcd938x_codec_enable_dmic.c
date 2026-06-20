__int64 __fastcall wcd938x_codec_enable_dmic(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x23
  unsigned int v4; // w8
  __int64 v5; // x24
  unsigned int v6; // w20
  char v7; // w27
  unsigned int v8; // w21
  char v9; // w26
  unsigned int v10; // w19
  unsigned int v11; // w22
  char v12; // w25
  __int64 v14; // x23

  v3 = *(_QWORD *)(a1 + 40);
  v4 = *(unsigned __int8 *)(a1 + 76);
  v5 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
  if ( v4 > 3 )
  {
    if ( v4 - 4 < 2 )
    {
      v9 = 0;
      v6 = 0;
      v12 = 1;
      v8 = 15;
      v7 = 2;
      v10 = 13406;
      v11 = 13411;
    }
    else
    {
      if ( v4 - 6 >= 2 )
        goto LABEL_11;
      v6 = 0;
      v12 = 1;
      v8 = 240;
      v9 = 4;
      v7 = 3;
      v10 = 13407;
      v11 = 13411;
    }
LABEL_15:
    v14 = v3 - 208;
    if ( a3 == 8 )
    {
      wcd938x_tx_connect_port(v14, v4 + 34, 0, 0);
      snd_soc_component_update_bits(v14, 13402, (unsigned int)(1 << v7), (unsigned int)(1 << v7));
      if ( (v12 & 1) == 0 )
        snd_soc_component_update_bits(v14, v6, 128, 0);
      snd_soc_component_update_bits(v14, v10, 8, 0);
    }
    else if ( a3 == 1 )
    {
      snd_soc_component_update_bits(v14, 13402, (unsigned int)(1 << v7), 0);
      usleep_range_state(250, 260, 2);
      if ( (v12 & 1) == 0 )
        snd_soc_component_update_bits(v14, v6, 128, 128);
      snd_soc_component_update_bits(v14, v11, v8, (unsigned int)(3 << v9));
      snd_soc_component_update_bits(v14, v10, 8, 8);
      snd_soc_component_update_bits(v14, 13403, 6, 6);
      return swr_slvdev_datapath_control(*(_QWORD *)(v5 + 48), *(unsigned __int8 *)(*(_QWORD *)(v5 + 48) + 64LL), 1);
    }
    return 0;
  }
  if ( v4 < 2 )
  {
    v7 = 0;
    v9 = 0;
    v6 = 0;
    v12 = 1;
    v8 = 15;
    v10 = 13404;
    v11 = 13410;
    goto LABEL_15;
  }
  if ( v4 == 2 )
  {
    v12 = 0;
    v8 = 240;
    v9 = 4;
    v7 = 1;
    v10 = 13405;
    v11 = 13410;
    v6 = 13405;
    goto LABEL_15;
  }
  if ( v4 == 3 )
  {
    v6 = 0;
    v7 = 1;
    v8 = 240;
    v9 = 4;
    v10 = 13405;
    v11 = 13410;
    v12 = 1;
    goto LABEL_15;
  }
LABEL_11:
  if ( (unsigned int)__ratelimit(&wcd938x_codec_enable_dmic__rs, "wcd938x_codec_enable_dmic") )
    dev_err(*(_QWORD *)(v3 - 184), "%s: Invalid DMIC Selection\n", "wcd938x_codec_enable_dmic");
  return 4294967274LL;
}
