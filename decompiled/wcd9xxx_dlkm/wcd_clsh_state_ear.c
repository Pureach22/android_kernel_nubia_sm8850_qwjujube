__int64 __fastcall wcd_clsh_state_ear(__int64 a1, __int64 a2, __int64 a3, char a4, unsigned int a5)
{
  unsigned int v8; // w23
  __int64 v9; // x3
  unsigned int v10; // w22
  int v11; // w8
  int v12; // w8
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x3
  int v17; // w8
  __int64 v18; // x3

  if ( (a4 & 1) != 0 )
  {
    snd_soc_component_update_bits(a1, 12296, 2, 0);
    v8 = a5 - 1;
    if ( a5 - 1 > 7 )
    {
      v9 = 0;
      v10 = 112;
    }
    else
    {
      v9 = dword_9330[v8];
      v10 = dword_9350[v8];
    }
    snd_soc_component_update_bits(a1, 12296, 4, v9);
    snd_soc_component_update_bits(a1, 12456, 240, v10);
    wcd_clsh_force_iq_ctl(a1, a5, 1);
    v17 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(a2 + 4) = v17 + 1;
    if ( !v17 )
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
    if ( v8 > 7 )
      v18 = 0;
    else
      v18 = dword_9390[v8];
    snd_soc_component_update_bits(a1, 12296, 8, v18);
    wcd_clsh_buck_ctrl(a1, a2, a5, 1);
    if ( a5 >= 9 )
      return dev_err(*(_QWORD *)(a1 + 24), "%s:Invalid mode %d\n", "wcd_clsh_set_hph_mode", a5);
    v13 = a1;
    v16 = dword_8890[a5];
    v14 = 12297;
    v15 = 12;
  }
  else
  {
    snd_soc_component_update_bits(a1, 12297, 12, 0);
    v11 = *(_DWORD *)(a2 + 4) - 1;
    *(_DWORD *)(a2 + 4) = v11;
    if ( !v11 )
    {
      snd_soc_component_update_bits(a1, 12453, 224, 224);
      snd_soc_component_update_bits(a1, 12296, 64, 0);
      usleep_range_state(100, 110, 2);
      snd_soc_component_update_bits(a1, 12463, 224, 224);
      usleep_range_state(500, 550, 2);
    }
    v12 = *(_DWORD *)(a2 + 8) - 1;
    *(_DWORD *)(a2 + 8) = v12;
    if ( !v12 )
    {
      snd_soc_component_update_bits(a1, 12296, 128, 0);
      usleep_range_state(500, 510, 2);
      snd_soc_component_update_bits(a1, 12440, 255, 58);
      usleep_range_state(500, 550, 2);
    }
    snd_soc_component_update_bits(a1, 12600, 32, 0);
    snd_soc_component_update_bits(a1, 12479, 240, 128);
    snd_soc_component_update_bits(a1, 12497, 14, 6);
    snd_soc_component_update_bits(a1, 12296, 4, 0);
    snd_soc_component_update_bits(a1, 12456, 240, 112);
    v13 = a1;
    v14 = 12296;
    v15 = 8;
    v16 = 0;
  }
  return snd_soc_component_update_bits(v13, v14, v15, v16);
}
