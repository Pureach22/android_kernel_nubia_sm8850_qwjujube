__int64 __fastcall wcd939x_config_compander(__int64 result, char a2, int a3)
{
  __int64 v4; // x20
  unsigned int v5; // w8
  __int64 v7; // x20
  __int16 v8; // w8
  char v9; // w9
  bool v10; // zf
  unsigned __int16 v11; // w21
  unsigned int v12; // w19
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x3
  __int64 v17; // x21
  char v18; // w0
  char v19; // w0
  __int64 v20; // x1

  if ( a3 < 2 )
  {
    if ( result )
    {
      v4 = *(_QWORD *)(*(_QWORD *)(result + 24) + 152LL);
      if ( !*(_BYTE *)(v4 + 280) )
        return result;
      if ( *(_DWORD *)(v4 + 4LL * (unsigned int)a3 + 264) )
      {
        if ( a3 )
          v5 = 12502;
        else
          v5 = 12499;
        v7 = result;
        result = snd_soc_component_update_bits(result, v5, 32, 0);
        v8 = 32 * a3;
        v9 = a2;
        v10 = (a2 & 3) == 0;
        v11 = 32 * a3 + 13632;
        if ( v10 )
        {
          if ( (v9 & 0xC) == 0 )
            return result;
          snd_soc_component_update_bits(v7, 13332, 3, 0);
          snd_soc_component_update_bits(v7, 12595, 31, 4);
          snd_soc_component_update_bits(v7, 12598, 31, 4);
          snd_soc_component_update_bits(v7, 12499, 32, 32);
          snd_soc_component_update_bits(v7, 12502, 32, 32);
          v14 = (unsigned __int16)(32 * a3 + 13632);
          v13 = v7;
          v15 = 3;
          v16 = 2;
        }
        else
        {
          if ( a3 )
            v12 = 1;
          else
            v12 = 2;
          snd_soc_component_update_bits(v7, (v8 + 13639) & 0xFFE7, 30, 0);
          snd_soc_component_update_bits(v7, v11, 1, 1);
          usleep_range_state(250, 260, 2);
          snd_soc_component_update_bits(v7, v11, 2, 2);
          snd_soc_component_update_bits(v7, v11, 2, 0);
          v13 = v7;
          v14 = 13332;
          v15 = v12;
          v16 = v12;
        }
        return snd_soc_component_update_bits(v13, v14, v15, v16);
      }
      else
      {
        v17 = result;
        v18 = snd_soc_component_read(result, 12595);
        snd_soc_component_update_bits(v17, 12595, 31, v18 & 0x1F);
        v19 = snd_soc_component_read(v17, 12598);
        snd_soc_component_update_bits(v17, 12598, 31, v19 & 0x1F);
        if ( a3 )
          v20 = 12502;
        else
          v20 = 12499;
        snd_soc_component_update_bits(v17, v20, 32, 32);
        return wcd939x_config_2Vpk_mode(v17, v4, 2);
      }
    }
    else
    {
      result = __ratelimit(&wcd939x_config_compander__rs_385, "wcd939x_config_compander");
      if ( (_DWORD)result )
        return printk(&unk_18FA5, "wcd939x_config_compander");
    }
  }
  else
  {
    result = __ratelimit(&wcd939x_config_compander__rs, "wcd939x_config_compander");
    if ( (_DWORD)result )
      return printk(&unk_19C01, "wcd939x_config_compander");
  }
  return result;
}
