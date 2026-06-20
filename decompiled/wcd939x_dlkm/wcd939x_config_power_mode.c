__int64 __fastcall wcd939x_config_power_mode(__int64 result, __int64 a2, __int64 a3, int a4)
{
  __int64 v4; // x20
  unsigned int v5; // w21
  __int64 v6; // x19
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x19
  __int64 v10; // x2
  __int64 v11; // x19
  __int64 v12; // x3

  if ( (_DWORD)a2 == 8 )
  {
    if ( a4 != 5 )
      return result;
    v9 = result;
    snd_soc_component_update_bits(result, 12509, 3, 0);
    v7 = v9;
    v8 = 12509;
    v10 = 12;
  }
  else
  {
    if ( (_DWORD)a2 != 1 )
      return result;
    v4 = *(_QWORD *)(*(_QWORD *)(result + 24) + 152LL);
    if ( a4 == 5 )
    {
      v5 = a3;
      v6 = result;
      snd_soc_component_update_bits(result, 12509, 12, 4);
      result = snd_soc_component_update_bits(v6, 12509, 3, 1);
      if ( v5 < 2 )
      {
        if ( !*(_DWORD *)(v4 + 4LL * v5 + 264) )
          return result;
        if ( (v5 & 1) != 0 )
        {
          snd_soc_component_update_bits(v6, 13676, 127, 33);
          snd_soc_component_update_bits(v6, 13677, 127, 48);
          snd_soc_component_update_bits(v6, 13678, 127, 63);
          snd_soc_component_update_bits(v6, 13679, 127, 72);
          v7 = v6;
          v8 = 13681;
        }
        else
        {
          snd_soc_component_update_bits(v6, 13644, 127, 33);
          snd_soc_component_update_bits(v6, 13645, 127, 48);
          snd_soc_component_update_bits(v6, 13646, 127, 63);
          snd_soc_component_update_bits(v6, 13647, 127, 72);
          v7 = v6;
          v8 = 13649;
        }
        v10 = 63;
        v12 = 12;
        return snd_soc_component_update_bits(v7, v8, v10, v12);
      }
LABEL_21:
      __break(0x5512u);
      return wcd939x_config_compander(result, a2, a3);
    }
    if ( (unsigned int)a3 > 1 )
      goto LABEL_21;
    if ( !*(_DWORD *)(v4 + 4LL * (unsigned int)a3 + 264) )
      return result;
    v11 = result;
    if ( (a3 & 1) != 0 )
    {
      snd_soc_component_update_bits(result, 13676, 127, 30);
      snd_soc_component_update_bits(v11, 13677, 127, 42);
      snd_soc_component_update_bits(v11, 13678, 127, 54);
      snd_soc_component_update_bits(v11, 13679, 127, 60);
      v7 = v11;
      v8 = 13681;
    }
    else
    {
      snd_soc_component_update_bits(result, 13644, 127, 30);
      snd_soc_component_update_bits(v11, 13645, 127, 42);
      snd_soc_component_update_bits(v11, 13646, 127, 54);
      snd_soc_component_update_bits(v11, 13647, 127, 60);
      v7 = v11;
      v8 = 13649;
    }
    v10 = 63;
  }
  v12 = 0;
  return snd_soc_component_update_bits(v7, v8, v10, v12);
}
