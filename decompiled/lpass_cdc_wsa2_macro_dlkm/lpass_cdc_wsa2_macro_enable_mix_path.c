__int64 __fastcall lpass_cdc_wsa2_macro_enable_mix_path(__int64 a1, __int64 a2, int a3)
{
  const char *v3; // x20
  __int64 v5; // x22
  unsigned int v7; // w20
  __int64 v8; // x0
  __int64 v9; // x21
  int v10; // w22
  __int64 v11; // x1
  unsigned int v12; // w0
  __int64 v13; // x1

  v3 = *(const char **)(a1 + 8);
  v5 = *(_QWORD *)(a1 + 40);
  if ( !strcmp(v3, "WSA2_RX0 MIX INP") )
  {
    v7 = 17440;
  }
  else
  {
    if ( strcmp(v3, "WSA2_RX1 MIX INP") )
    {
      if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_enable_mix_path__rs, "lpass_cdc_wsa2_macro_enable_mix_path") )
        dev_err(
          *(_QWORD *)(v5 - 184),
          "%s: No gain register avail for %s\n",
          "lpass_cdc_wsa2_macro_enable_mix_path",
          *(const char **)(a1 + 8));
      return 0;
    }
    v7 = 17568;
  }
  v8 = v5 - 208;
  if ( a3 == 8 )
  {
    snd_soc_component_update_bits(v8, *(unsigned int *)(a1 + 72), 32, 0);
    lpass_cdc_wsa2_macro_enable_swr(a1, v13, 8);
  }
  else if ( a3 == 1 )
  {
    v9 = v5 - 208;
    v10 = *(unsigned __int8 *)(a1 + 76) << 7;
    snd_soc_component_update_bits(v8, (unsigned int)(v10 + 17432), 64, 64);
    usleep_range_state(500, 510, 2);
    snd_soc_component_update_bits(v9, (unsigned int)(v10 + 17432), 64, 0);
    snd_soc_component_update_bits(v9, (unsigned int)(v10 + 17408), 32, 32);
    snd_soc_component_update_bits(v9, (unsigned int)(v10 + 17432), 32, 32);
    lpass_cdc_wsa2_macro_enable_swr(a1, v11, 1);
    v12 = snd_soc_component_read(v9, v7);
    snd_soc_component_write(v9, v7, v12);
  }
  return 0;
}
