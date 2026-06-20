__int64 __fastcall wcd9378_hph_sequencer_enable(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x22
  __int64 v4; // x23
  __int64 v5; // x19
  unsigned int v6; // w8
  unsigned int v7; // w8
  __int64 v8; // x3
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 result; // x0
  __int64 v12; // x8
  unsigned int v13; // w20
  __int64 v14; // x25
  unsigned int v15; // w26
  __int64 v16; // x0
  __int64 v17; // x1
  unsigned int v18; // w19
  unsigned int v19; // w20
  _BYTE v20[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 40);
  v4 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
  v20[0] = 2;
  v5 = *(_QWORD *)(v4 + 64);
  if ( a3 == 8 )
  {
    snd_soc_component_update_bits(v3 - 208, 1086325896, 255, 3);
    if ( *(_BYTE *)(v4 + 392) == 1 && (*(_BYTE *)(v4 + 393) & 1) != 0 )
    {
      v9 = 17000;
      v10 = 17100;
    }
    else
    {
      v9 = 30000;
      v10 = 30100;
    }
    usleep_range_state(v9, v10, 2);
    result = wcd9378_pde_act_ps_check(v3 - 208, 1086850176, 3);
    if ( (_DWORD)result )
    {
      v19 = result;
      dev_err(*(_QWORD *)(v3 - 184), "%s: HPH sequencer tear down failed\n", "wcd9378_hph_sequencer_enable");
      result = v19;
    }
    v12 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
    if ( (*(_QWORD *)(v12 + 16) & 0x400) == 0
      && (*(_QWORD *)(v12 + 16) & 0x800) == 0
      && (*(_QWORD *)(v12 + 16) & 0x1000) == 0 )
    {
      v13 = result;
      regmap_write(*(_QWORD *)(v4 + 48), 1086341897, 1);
      regmap_write(*(_QWORD *)(v4 + 48), 1086341898, 1);
      swr_write(v5, *(unsigned __int8 *)(v5 + 64), 76, v20);
      result = v13;
    }
  }
  else if ( a3 == 1 )
  {
    regmap_write(*(_QWORD *)(v4 + 48), 1086324744, 2);
    if ( *(_BYTE *)(v4 + 392) != 1 || (*(_BYTE *)(v4 + 393) & 1) == 0 )
    {
      snd_soc_component_update_bits(v3 - 208, 1075315991, 7, 7);
      snd_soc_component_update_bits(v3 - 208, 1075315996, 7, 7);
    }
    v6 = *(_DWORD *)(v4 + 360);
    if ( v6 <= 8 && ((1 << v6) & 0x1C8) != 0 )
    {
      snd_soc_component_update_bits(v3 - 208, 1075315050, 128, 128);
      v6 = *(_DWORD *)(v4 + 360);
    }
    v7 = v6 - 1;
    if ( v7 > 7 )
      v8 = 3;
    else
      v8 = dword_5F824[v7];
    snd_soc_component_update_bits(v3 - 208, 1086324896, 255, v8);
    snd_soc_component_update_bits(v3 - 208, 1086325896, 255, 0);
    v14 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
    if ( (*(_BYTE *)(v14 + 392) & 1) == 0 && (*(_BYTE *)(v14 + 393) & 1) == 0 )
    {
      v15 = *(unsigned __int16 *)(v14 + 364);
      regmap_write(*(_QWORD *)(v14 + 48), 1086350097, v15 >> 8);
      regmap_write(*(_QWORD *)(v14 + 48), 1086341905, (unsigned __int8)v15);
      regmap_write(*(_QWORD *)(v14 + 48), 1086350098, v15 >> 8);
      regmap_write(*(_QWORD *)(v14 + 48), 1086341906, (unsigned __int8)v15);
    }
    if ( *(_BYTE *)(v4 + 392) == 1 && (*(_BYTE *)(v4 + 393) & 1) != 0 )
    {
      v16 = 15000;
      v17 = 15100;
    }
    else
    {
      v16 = 26000;
      v17 = 26100;
    }
    usleep_range_state(v16, v17, 2);
    regmap_write(*(_QWORD *)(v4 + 48), 1086341897, 0);
    regmap_write(*(_QWORD *)(v4 + 48), 1086341898, 0);
    if ( *(_DWORD *)(v4 + 8) == 10 )
      regmap_write(*(_QWORD *)(v4 + 48), 1082131336, 0);
    swr_write(v5, *(unsigned __int8 *)(v5 + 64), 76, v20);
    swr_slvdev_datapath_control(*(_QWORD *)(v4 + 56), *(unsigned __int8 *)(*(_QWORD *)(v4 + 56) + 64LL), 1);
    v18 = wcd9378_pde_act_ps_check(v3 - 208, 1086850176, 0);
    result = 0;
    if ( v18 )
    {
      dev_err(*(_QWORD *)(v3 - 184), "%s: HPH sequencer power on failed\n", "wcd9378_hph_sequencer_enable");
      result = v18;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
