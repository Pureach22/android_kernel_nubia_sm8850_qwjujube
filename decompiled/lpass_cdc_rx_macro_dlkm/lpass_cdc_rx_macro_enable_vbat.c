__int64 __fastcall lpass_cdc_rx_macro_enable_vbat(__int64 a1, __int64 a2, int a3)
{
  __int64 v4; // x8
  __int64 v5; // x19
  __int64 v6; // x20
  int v7; // w8
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 result; // x0
  int v13; // w9
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  __int64 v15[2]; // [xsp+10h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 40);
  v14 = 0;
  v15[0] = 0;
  v5 = v4 - 208;
  if ( (lpass_cdc_rx_macro_get_data(v4 - 208, v15, &v14, (__int64)"lpass_cdc_rx_macro_enable_vbat") & 1) != 0 )
  {
    if ( a3 == 8 )
    {
      snd_soc_component_update_bits(v5, 5640, 1, 0);
      snd_soc_component_update_bits(v5, 5636, 1, 0);
      snd_soc_component_update_bits(v5, 5632, 1, 0);
      snd_soc_component_update_bits(v5, 5512, 128, 0);
      snd_soc_component_update_bits(v5, 5568, 2, 0);
      snd_soc_component_update_bits(v5, 4740, 2, 2);
      snd_soc_component_update_bits(v5, 5512, 2, 0);
      snd_soc_component_update_bits(v5, 4828, 255, 0);
      snd_soc_component_update_bits(v5, 4832, 255, 0);
      snd_soc_component_update_bits(v5, 4836, 255, 0);
      snd_soc_component_update_bits(v5, 4840, 255, 0);
      snd_soc_component_update_bits(v5, 4844, 255, 0);
      snd_soc_component_update_bits(v5, 4848, 255, 0);
      snd_soc_component_update_bits(v5, 4852, 255, 0);
      snd_soc_component_update_bits(v5, 4856, 255, 0);
      snd_soc_component_update_bits(v5, 4860, 255, 0);
      v13 = *(_DWORD *)(v14 + 2332) - 1;
      *(_DWORD *)(v14 + 2332) = v13;
      if ( !v13 )
        snd_soc_component_update_bits(v5, 4416, 1, 0);
      snd_soc_component_update_bits(v5, 4740, 1, 0);
      v8 = v5;
      v9 = 4736;
      v10 = 16;
      v11 = 0;
    }
    else
    {
      if ( a3 != 1 )
      {
        result = __ratelimit(&lpass_cdc_rx_macro_enable_vbat__rs, "lpass_cdc_rx_macro_enable_vbat");
        if ( !(_DWORD)result )
          goto LABEL_14;
        dev_err(v15[0], "%s: Invalid event %d\n", "lpass_cdc_rx_macro_enable_vbat", a3);
        goto LABEL_12;
      }
      snd_soc_component_update_bits(v5, 4736, 16, 16);
      snd_soc_component_update_bits(v5, 4740, 1, 1);
      snd_soc_component_update_bits(v5, 5512, 128, 128);
      snd_soc_component_update_bits(v5, 5568, 2, 2);
      snd_soc_component_update_bits(v5, 4740, 2, 0);
      v6 = v14;
      v7 = *(_DWORD *)(v14 + 2332);
      if ( !v7 )
      {
        snd_soc_component_update_bits(v5, 4416, 1, 1);
        v7 = *(_DWORD *)(v6 + 2332);
      }
      *(_DWORD *)(v6 + 2332) = v7 + 1;
      snd_soc_component_update_bits(v5, 5512, 2, 2);
      snd_soc_component_update_bits(v5, 4828, 255, 255);
      snd_soc_component_update_bits(v5, 4832, 255, 3);
      snd_soc_component_update_bits(v5, 4836, 255, 0);
      snd_soc_component_update_bits(v5, 4840, 255, 255);
      snd_soc_component_update_bits(v5, 4844, 255, 3);
      snd_soc_component_update_bits(v5, 4848, 255, 0);
      snd_soc_component_update_bits(v5, 4852, 255, 255);
      snd_soc_component_update_bits(v5, 4856, 255, 3);
      snd_soc_component_update_bits(v5, 4860, 255, 0);
      snd_soc_component_update_bits(v5, 5632, 1, 1);
      snd_soc_component_update_bits(v5, 5636, 1, 1);
      v8 = v5;
      v9 = 5640;
      v10 = 1;
      v11 = 1;
    }
    snd_soc_component_update_bits(v8, v9, v10, v11);
LABEL_12:
    result = 0;
    goto LABEL_14;
  }
  result = 4294967274LL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
