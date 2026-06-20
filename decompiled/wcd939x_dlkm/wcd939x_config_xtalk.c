__int64 __fastcall wcd939x_config_xtalk(__int64 result, int a2, unsigned int a3)
{
  __int64 v3; // x8
  int v4; // w20
  unsigned __int8 *v5; // x23
  __int64 v6; // x24
  unsigned __int8 *v7; // x23
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x3

  if ( result )
  {
    if ( a3 >= 2 )
    {
      __break(0x5512u);
      return wcd939x_rx_clk_disable(result);
    }
    v3 = *(_QWORD *)(*(_QWORD *)(result + 24) + 152LL);
    if ( *(_DWORD *)(v3 + 4LL * a3 + 272) )
    {
      switch ( a2 )
      {
        case 8:
          v8 = 13600;
          v9 = 0;
          v10 = 0;
          break;
        case 2:
          v8 = 13600;
          v9 = 15;
          v10 = 15;
          break;
        case 1:
          v4 = 4 * a3;
          v5 = *(unsigned __int8 **)(*(_QWORD *)v3 + 144LL);
          if ( (a3 & 1) != 0 )
          {
            v6 = result;
            snd_soc_component_update_bits(result, v4 | 0x3522u, 255, v5[259]);
            v7 = v5 + 258;
          }
          else
          {
            v11 = v5[257];
            v7 = v5 + 256;
            v6 = result;
            snd_soc_component_update_bits(result, v4 | 0x3522u, 255, v11);
          }
          snd_soc_component_update_bits(v6, v4 | 0x3521u, 31, *v7);
          snd_soc_component_update_bits(v6, (unsigned int)(v4 + 13604), 255, 79);
          v8 = v4 | 0x3523u;
          result = v6;
          v9 = 31;
          v10 = 17;
          break;
        default:
          return result;
      }
      return snd_soc_component_update_bits(result, v8, v9, v10);
    }
  }
  else
  {
    result = __ratelimit(&wcd939x_config_xtalk__rs, "wcd939x_config_xtalk");
    if ( (_DWORD)result )
      return printk(&unk_18FA5, "wcd939x_config_xtalk");
  }
  return result;
}
