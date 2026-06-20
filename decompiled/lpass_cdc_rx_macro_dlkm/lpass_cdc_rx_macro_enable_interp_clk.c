__int64 __fastcall lpass_cdc_rx_macro_enable_interp_clk(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x3
  int v10; // w24
  unsigned __int16 v11; // w27
  int v12; // w23
  __int64 v13; // x22
  __int64 v14; // x28
  int v15; // w8
  unsigned int v16; // w23
  unsigned int v17; // w8
  __int64 v18; // x3
  int v19; // w8
  __int64 v20; // x22
  __int64 v21; // x8
  int v22; // w9
  int v23; // w8
  unsigned int v24; // w21
  __int64 v25; // [xsp+8h] [xbp-18h] BYREF
  __int64 v26[2]; // [xsp+10h] [xbp-10h] BYREF

  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v26[0] = 0;
  if ( !a1 )
  {
    result = __ratelimit(&lpass_cdc_rx_macro_enable_interp_clk__rs, "lpass_cdc_rx_macro_enable_interp_clk");
    if ( (_DWORD)result )
      result = printk(&unk_F49A, "lpass_cdc_rx_macro_enable_interp_clk");
    goto LABEL_68;
  }
  result = lpass_cdc_rx_macro_get_data(a1, v26, &v25, (__int64)"lpass_cdc_rx_macro_enable_interp_clk");
  if ( (result & 1) == 0 )
    goto LABEL_68;
  v10 = 192 * a3;
  if ( a3 == 2 )
    v11 = 5580;
  else
    v11 = 192 * a3 + 5184;
  v12 = a2 & 3;
  if ( (a2 & 3) != 0 )
  {
    if ( a3 >= 3 )
      goto LABEL_71;
    v13 = v25;
    v14 = v25 + 20;
    v15 = *(_DWORD *)(v25 + 20 + 4LL * a3);
    if ( !v15 )
    {
      snd_soc_component_update_bits(a1, (unsigned __int16)(192 * a3 + 5120), 16, 16);
      snd_soc_component_update_bits(a1, v11, 1, 1);
      snd_soc_component_update_bits(a1, (unsigned __int16)(192 * a3 + 5120), 32, 32);
      snd_soc_component_update_bits(a1, (unsigned __int16)(v10 + 5132), 3, 3);
      if ( *(_BYTE *)(v13 + 473) && !*(_BYTE *)(v13 + 16) )
      {
        v16 = a3 == 1 ? 2 : a3 == 0;
        if ( a3 != 2 )
        {
          snd_soc_component_update_bits(a1, 6016, v16, v16);
          if ( (a2 & 0xC) != 0 )
          {
            snd_soc_component_update_bits(a1, 6016, v16, 0);
            *(_BYTE *)(v13 + 472) = 0;
            snd_soc_component_write(a1, 6032, 0);
          }
        }
      }
      if ( *(_BYTE *)(v13 + 97) == 1 )
        lpass_cdc_rx_macro_hd2_control(a1, v13, a3, a2);
      lpass_cdc_rx_macro_hphdelay_lutbypass(a1, v13, a3, a2);
      if ( !*(_BYTE *)(v13 + 16) )
      {
        v17 = snd_soc_component_read(a1, v10 | 0x1400u) & 0xF;
        if ( v17 >= 6 )
          v18 = v17 >= 8 ? 2 * (unsigned int)(v17 < 0xB) : 1LL;
        else
          v18 = 3;
        snd_soc_component_update_bits(a1, v10 | 0x1410u, 3, v18);
        if ( (a2 & 0xC) != 0 )
          snd_soc_component_update_bits(a1, v10 | 0x1410u, 3, 3);
      }
      lpass_cdc_rx_macro_config_compander(a1, v13, a3, a2);
      v12 = a2 & 3;
      if ( a3 == 2 )
      {
        lpass_cdc_rx_macro_config_softclip(a1, v13, a2);
        if ( !*(_DWORD *)(v13 + 2328) )
          snd_soc_component_update_bits(a1, 5512, 4, 0);
        if ( (a2 & 0xC) != 0 )
          snd_soc_component_update_bits(a1, 5512, 4, 4);
      }
      lpass_cdc_rx_macro_config_classh(a1, v13, a3, a2);
      if ( *(_BYTE *)(v13 + 16) && a3 != 2 && (*(_BYTE *)(v13 + 86) & 1) == 0 )
      {
        v19 = *(_DWORD *)(v13 + 2356);
        if ( !v19 )
        {
          snd_soc_component_update_bits(a1, 4104, 2, 2);
          v19 = *(_DWORD *)(v13 + 2356);
        }
        *(_DWORD *)(v13 + 2356) = v19 + 1;
      }
      result = lpass_cdc_notify_wcd_rx_clk(v26[0], *(unsigned __int8 *)(v13 + 86));
      v15 = *(_DWORD *)(v14 + 4LL * a3);
    }
    *(_DWORD *)(v14 + 4LL * a3) = v15 + 1;
  }
  if ( (a2 & 0xC) != 0 )
  {
    if ( a3 <= 3 )
    {
      v20 = v25;
      v21 = v25 + 20;
      v22 = *(_DWORD *)(v25 + 20 + 4LL * a3) - 1;
      *(_DWORD *)(v25 + 20 + 4LL * a3) = v22;
      if ( a3 != 3 )
      {
        if ( v22 > 0 )
          goto LABEL_68;
        *(_DWORD *)(v21 + 4LL * a3) = 0;
        snd_soc_component_update_bits(a1, (unsigned __int16)(192 * a3 + 5120), 16, 16);
        if ( *(_BYTE *)(v20 + 16) && a3 != 2 && (*(_BYTE *)(v20 + 86) & 1) == 0 )
        {
          v23 = *(_DWORD *)(v20 + 2356);
          if ( v23 == 1 )
          {
            snd_soc_component_update_bits(a1, 4104, 2, 0);
            v23 = *(_DWORD *)(v20 + 2356);
          }
          *(_DWORD *)(v20 + 2356) = (v23 - 1) & ~((v23 - 1) >> 31);
        }
        snd_soc_component_update_bits(a1, v11, 1, 0);
        snd_soc_component_update_bits(a1, (unsigned __int16)(192 * a3 + 5120), 32, 0);
        snd_soc_component_update_bits(a1, (unsigned __int16)(192 * a3 + 5120), 64, 64);
        snd_soc_component_update_bits(a1, (unsigned __int16)(192 * a3 + 5120), 64, 0);
        snd_soc_component_update_bits(a1, (unsigned __int16)(192 * a3 + 5120), 15, 4);
        snd_soc_component_update_bits(a1, (unsigned __int16)(v10 + 5132), 3, 0);
        lpass_cdc_rx_macro_config_classh(a1, v20, a3, a2);
        lpass_cdc_rx_macro_config_compander(a1, v20, a3, a2);
        if ( a3 == 2 )
        {
          lpass_cdc_rx_macro_config_softclip(a1, v20, a2);
          if ( v12 && !*(_DWORD *)(v20 + 2328) )
            snd_soc_component_update_bits(a1, 5512, 4, 0);
          snd_soc_component_update_bits(a1, 5512, 4, 4);
        }
        result = lpass_cdc_rx_macro_hphdelay_lutbypass(a1, v20, a3, a2);
        if ( *(_BYTE *)(v20 + 97) == 1 )
          result = lpass_cdc_rx_macro_hd2_control(a1, v20, a3, a2);
        if ( !*(_BYTE *)(v20 + 473) || *(_BYTE *)(v20 + 16) )
          goto LABEL_68;
        if ( a3 == 1 )
          v24 = 2;
        else
          v24 = a3 == 0;
        if ( a3 <= 1 && v12 )
        {
          snd_soc_component_update_bits(a1, 6016, v24, v24);
LABEL_70:
          snd_soc_component_update_bits(a1, 6016, v24, 0);
          *(_BYTE *)(v20 + 472) = 0;
          result = snd_soc_component_write(a1, 6032, 0);
          goto LABEL_68;
        }
        if ( a3 <= 1 )
          goto LABEL_70;
LABEL_68:
        _ReadStatusReg(SP_EL0);
        return result;
      }
    }
  }
  else if ( a3 <= 2 )
  {
    goto LABEL_68;
  }
LABEL_71:
  __break(0x5512u);
  return lpass_cdc_rx_macro_hd2_control(result, v7, v8, v9);
}
