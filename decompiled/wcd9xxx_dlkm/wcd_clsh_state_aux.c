__int64 __fastcall wcd_clsh_state_aux(__int64 a1, __int64 a2, __int64 a3, char a4, unsigned int a5)
{
  unsigned int v8; // w22
  __int64 v9; // x3
  int v10; // w8
  __int64 v12; // x3
  unsigned int v13; // w22
  int v14; // w8

  if ( (a4 & 1) != 0 )
  {
    v8 = a5 - 1;
    if ( a5 - 1 > 7 )
      v9 = 0;
    else
      v9 = dword_9390[v8];
    snd_soc_component_update_bits(a1, 12296, 8, v9);
    if ( v8 > 7 )
    {
      v12 = 0;
      v13 = 112;
    }
    else
    {
      v12 = dword_9330[v8];
      v13 = dword_9350[v8];
    }
    snd_soc_component_update_bits(a1, 12296, 4, v12);
    snd_soc_component_update_bits(a1, 12456, 240, v13);
    v14 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(a2 + 4) = v14 + 1;
    if ( !v14 )
    {
      snd_soc_component_update_bits(a1, 12453, 224, 224);
      snd_soc_component_update_bits(a1, 12296, 64, 64);
      usleep_range_state(100, 110, 2);
      snd_soc_component_update_bits(a1, 12463, 224, 224);
      usleep_range_state(500, 550, 2);
    }
    snd_soc_component_update_bits(a1, 12487, 15, 10);
    snd_soc_component_update_bits(a1, 12487, 240, 160);
    usleep_range_state(100, 110, 2);
    return wcd_clsh_buck_ctrl(a1, a2, a5, 1);
  }
  else
  {
    wcd_clsh_buck_ctrl(a1, a2, a5, 0);
    v10 = *(_DWORD *)(a2 + 4) - 1;
    *(_DWORD *)(a2 + 4) = v10;
    if ( !v10 )
    {
      snd_soc_component_update_bits(a1, 12453, 224, 224);
      snd_soc_component_update_bits(a1, 12296, 64, 0);
      usleep_range_state(100, 110, 2);
      snd_soc_component_update_bits(a1, 12463, 224, 224);
      usleep_range_state(500, 550, 2);
    }
    snd_soc_component_update_bits(a1, 12296, 4, 0);
    snd_soc_component_update_bits(a1, 12456, 240, 112);
    return snd_soc_component_update_bits(a1, 12296, 8, 0);
  }
}
