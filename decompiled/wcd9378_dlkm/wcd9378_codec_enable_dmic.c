__int64 __fastcall wcd9378_codec_enable_dmic(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x23
  unsigned int v4; // w8
  unsigned int v5; // w19
  __int64 v6; // x25
  char v7; // w28
  char v8; // w26
  unsigned int v9; // w20
  char v10; // w27
  unsigned int v11; // w21
  unsigned int v12; // w22
  __int64 v13; // x23

  v3 = *(_QWORD *)(a1 + 40);
  v4 = *(unsigned __int8 *)(a1 + 76);
  v5 = 1075315804;
  v6 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
  if ( v4 > 2 )
  {
    if ( v4 - 4 < 2 )
    {
      v8 = 0;
      v9 = 0;
      v5 = 1075315806;
      v12 = 1075315811;
      v10 = 1;
      v11 = 15;
      v7 = 2;
      goto LABEL_10;
    }
    if ( v4 == 3 )
    {
      v9 = 0;
      v5 = 1075315805;
      v7 = 1;
      v11 = 240;
      v8 = 4;
      v12 = 1075315810;
      v10 = 1;
LABEL_10:
      v13 = v3 - 208;
      if ( a3 == 8 )
      {
        wcd9378_tx_connect_port(v13, v4 + 34, 0, 0);
        snd_soc_component_update_bits(v13, 1075315802, (unsigned int)(1 << v7), (unsigned int)(1 << v7));
        if ( (v10 & 1) == 0 )
          snd_soc_component_update_bits(v13, v9, 128, 0);
        snd_soc_component_update_bits(v13, v5, 8, 0);
      }
      else if ( a3 == 1 )
      {
        snd_soc_component_update_bits(v13, 1075315802, (unsigned int)(1 << v7), 0);
        usleep_range_state(250, 260, 2);
        if ( (v10 & 1) == 0 )
          snd_soc_component_update_bits(v13, v9, 128, 128);
        snd_soc_component_update_bits(v13, v12, v11, (unsigned int)(3 << v8));
        snd_soc_component_update_bits(v13, v5, 8, 8);
        snd_soc_component_update_bits(v13, 1075315803, 6, 6);
        return swr_slvdev_datapath_control(*(_QWORD *)(v6 + 64), *(unsigned __int8 *)(*(_QWORD *)(v6 + 64) + 64LL), 1);
      }
      return 0;
    }
  }
  else
  {
    if ( v4 < 2 )
    {
      v7 = 0;
      v8 = 0;
      v9 = 0;
      v10 = 1;
      v11 = 15;
      v12 = 1075315810;
      goto LABEL_10;
    }
    if ( v4 == 2 )
    {
      v5 = 1075315805;
      v10 = 0;
      v11 = 240;
      v8 = 4;
      v7 = 1;
      v12 = 1075315810;
      v9 = 1075315805;
      goto LABEL_10;
    }
  }
  if ( (unsigned int)__ratelimit(&wcd9378_codec_enable_dmic__rs, "wcd9378_codec_enable_dmic") )
    dev_err(*(_QWORD *)(v3 - 184), "%s: Invalid DMIC Selection\n", "wcd9378_codec_enable_dmic");
  return 4294967274LL;
}
