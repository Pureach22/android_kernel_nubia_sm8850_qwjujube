__int64 __fastcall lpass_cdc_wsa2_macro_spk_boost_event(__int64 a1, __int64 a2, int a3)
{
  const char *v3; // x21
  __int64 v5; // x22
  unsigned int v8; // w20
  unsigned int v9; // w21
  __int64 v10; // x22
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3

  v3 = *(const char **)(a1 + 8);
  v5 = *(_QWORD *)(a1 + 40);
  if ( !strcmp(v3, "WSA2_RX INT0 CHAIN") )
  {
    v8 = 17416;
    v9 = 17664;
    goto LABEL_8;
  }
  if ( !strcmp(v3, "WSA2_RX INT1 CHAIN") )
  {
    v8 = 17544;
    v9 = 17728;
LABEL_8:
    v10 = v5 - 208;
    if ( a3 == 8 )
    {
      snd_soc_component_update_bits(v10, v9, 16, 0);
      v11 = v10;
      v12 = v8;
      v13 = 1;
      v14 = 0;
    }
    else
    {
      if ( a3 != 1 )
        return 0;
      snd_soc_component_update_bits(v10, v8, 1, 1);
      v11 = v10;
      v12 = v9;
      v13 = 16;
      v14 = 16;
    }
    snd_soc_component_update_bits(v11, v12, v13, v14);
    return 0;
  }
  if ( (unsigned int)__ratelimit(&lpass_cdc_wsa2_macro_spk_boost_event__rs, "lpass_cdc_wsa2_macro_spk_boost_event") )
    dev_err(
      *(_QWORD *)(v5 - 184),
      "%s: unknown widget: %s\n",
      "lpass_cdc_wsa2_macro_spk_boost_event",
      *(const char **)(a1 + 8));
  return 4294967274LL;
}
