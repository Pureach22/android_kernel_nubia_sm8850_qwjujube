__int64 __fastcall lpass_cdc_wsa_macro_enable_mix_path(__int64 a1, __int64 a2, int a3)
{
  const char *v3; // x20
  __int64 v5; // x24
  int v7; // w8
  int v8; // w9
  int v9; // w10
  unsigned int v10; // w20
  int v11; // w8
  unsigned int v12; // w23
  unsigned int v13; // w21
  __int64 v14; // x0
  __int64 v15; // x1
  unsigned int v16; // w0
  __int64 v17; // x1

  v3 = *(const char **)(a1 + 8);
  v5 = *(_QWORD *)(a1 + 40);
  if ( !strcmp(v3, "WSA_RX0 MIX INP") )
  {
    v7 = *(unsigned __int8 *)(a1 + 76);
    v8 = 9216;
    v9 = 9240;
    v10 = 9248;
  }
  else
  {
    if ( strcmp(v3, "WSA_RX1 MIX INP") )
    {
      if ( (unsigned int)__ratelimit(&lpass_cdc_wsa_macro_enable_mix_path__rs, "lpass_cdc_wsa_macro_enable_mix_path") )
        dev_err(
          *(_QWORD *)(v5 - 184),
          "%s: No gain register avail for %s\n",
          "lpass_cdc_wsa_macro_enable_mix_path",
          *(const char **)(a1 + 8));
      return 0;
    }
    v7 = *(unsigned __int8 *)(a1 + 76);
    v8 = 9344;
    v9 = 9368;
    v10 = 9376;
  }
  v11 = v7 << 7;
  v12 = v11 + v8;
  v13 = v11 + v9;
  v14 = v5 - 208;
  if ( a3 == 8 )
  {
    snd_soc_component_update_bits(v14, *(unsigned int *)(a1 + 72), 32, 0);
    lpass_cdc_wsa_macro_enable_swr(a1, v17, 8);
  }
  else if ( a3 == 1 )
  {
    snd_soc_component_update_bits(v14, v13, 64, 64);
    usleep_range_state(500, 510, 2);
    snd_soc_component_update_bits(v5 - 208, v13, 64, 0);
    snd_soc_component_update_bits(v5 - 208, v12, 32, 32);
    snd_soc_component_update_bits(v5 - 208, v13, 32, 32);
    lpass_cdc_wsa_macro_enable_swr(a1, v15, 1);
    v16 = snd_soc_component_read(v5 - 208, v10);
    snd_soc_component_write(v5 - 208, v10, v16);
  }
  return 0;
}
