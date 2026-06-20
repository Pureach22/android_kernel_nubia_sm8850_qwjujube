__int64 __fastcall wcd_clsh_buck_ctrl(__int64 result, __int64 a2, unsigned int a3, char a4)
{
  int v4; // w8
  __int64 v6; // x19
  __int64 v7; // x3
  int v8; // w8

  v4 = *(_DWORD *)(a2 + 8);
  v6 = result;
  if ( (a4 & 1) != 0 )
  {
    *(_DWORD *)(a2 + 8) = v4 + 1;
    if ( v4 )
      return result;
    v7 = 128;
  }
  else
  {
    v8 = v4 - 1;
    *(_DWORD *)(a2 + 8) = v8;
    if ( v8 )
      return result;
    v7 = 0;
  }
  snd_soc_component_update_bits(result, 12296, 128, v7);
  usleep_range_state(500, 510, 2);
  if ( a3 <= 5 && ((1 << a3) & 0x36) != 0 )
    snd_soc_component_update_bits(v6, 12441, 2, 0);
  snd_soc_component_update_bits(v6, 12440, 255, 58);
  return usleep_range_state(500, 550, 2);
}
