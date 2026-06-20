__int64 __fastcall lpass_cdc_rx_macro_config_classh(__int64 result, __int64 a2, unsigned int a3, char a4)
{
  int v4; // w8
  int v5; // w9
  __int64 v6; // x19
  __int64 v7; // x3
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x19
  __int64 v11; // x19
  __int64 v12; // x20
  unsigned int v13; // w21
  __int64 v14; // x20
  unsigned int v15; // w21
  __int64 v16; // x19
  __int64 v17; // x3

  if ( a3 == 2 )
    return result;
  if ( (a4 & 0xC) == 0 )
  {
    if ( (a4 & 3) == 0 )
      return result;
    v5 = *(_DWORD *)(a2 + 76);
    *(_DWORD *)(a2 + 76) = v5 + 1;
    if ( v5 )
    {
      if ( ((v5 + 1) & 0x80000000) == 0 )
        goto LABEL_9;
    }
    else
    {
      v11 = result;
      v12 = a2;
      v13 = a3;
      snd_soc_component_update_bits(*(_QWORD *)(a2 + 304), 4608, 1, 1);
      a3 = v13;
      a2 = v12;
      result = v11;
      if ( (*(_DWORD *)(v12 + 76) & 0x80000000) == 0 )
      {
LABEL_9:
        if ( a3 > 1 )
          goto LABEL_10;
        goto LABEL_19;
      }
    }
    *(_DWORD *)(a2 + 76) = 0;
    if ( a3 > 1 )
      goto LABEL_10;
LABEL_19:
    v14 = a2;
    v15 = a3;
    v16 = result;
    snd_soc_component_update_bits(result, 4640, 255, 192);
    snd_soc_component_update_bits(v16, 4636, 15, 0);
    a3 = v15;
    a2 = v14;
    result = v16;
    if ( v15 == 1 )
    {
      if ( *(_BYTE *)(v14 + 87) )
        v17 = 57;
      else
        v17 = 28;
      snd_soc_component_update_bits(v16, 4620, 63, v17);
      snd_soc_component_update_bits(v16, 4616, 7, 0);
      v8 = v16;
      v9 = 5316;
      return snd_soc_component_update_bits(v8, v9, 64, 64);
    }
LABEL_10:
    if ( a3 )
      return result;
    v6 = result;
    if ( *(_BYTE *)(a2 + 87) )
      v7 = 57;
    else
      v7 = 28;
    snd_soc_component_update_bits(result, 4620, 63, v7);
    snd_soc_component_update_bits(v6, 4616, 7, 0);
    v8 = v6;
    v9 = 5124;
    return snd_soc_component_update_bits(v8, v9, 64, 64);
  }
  v4 = *(_DWORD *)(a2 + 76) - 1;
  *(_DWORD *)(a2 + 76) = v4;
  if ( v4 )
  {
    if ( (v4 & 0x80000000) == 0 )
      return result;
  }
  else
  {
    v10 = a2;
    result = snd_soc_component_update_bits(*(_QWORD *)(a2 + 304), 4608, 1, 0);
    a2 = v10;
    if ( (*(_DWORD *)(v10 + 76) & 0x80000000) == 0 )
      return result;
  }
  *(_DWORD *)(a2 + 76) = 0;
  return result;
}
