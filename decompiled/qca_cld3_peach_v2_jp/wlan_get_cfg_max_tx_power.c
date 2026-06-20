__int64 __fastcall wlan_get_cfg_max_tx_power(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // x0
  __int64 v6; // x21
  __int64 v7; // x22
  char *v8; // x20
  __int64 v9; // x8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned __int64 v18; // x8
  int v19; // w9
  unsigned int v20; // w13
  char *v21; // x12
  unsigned int v23; // w19

  result = wlan_psoc_mlme_get_ext_hdl(a1);
  if ( result )
  {
    v6 = result;
    if ( wlan_reg_is_5ghz_ch_freq(a3) )
    {
      v7 = *(_QWORD *)(v6 + 3704);
      if ( !(_DWORD)v7 )
        return 0;
    }
    else
    {
      if ( !wlan_reg_is_24ghz_ch_freq(a3) )
      {
        if ( wlan_reg_is_6ghz_chan_freq(a3) )
          return wlan_reg_get_channel_reg_power_for_freq(a2, a3, v10, v11, v12, v13, v14, v15, v16, v17);
        return 0;
      }
      v7 = *(_QWORD *)(v6 + 3560);
      if ( !(_DWORD)v7 )
        return 0;
    }
    result = _qdf_mem_malloc((unsigned int)v7, "wlan_get_cfg_max_tx_power", 5132);
    if ( !result )
      return result;
    v8 = (char *)result;
    if ( wlan_reg_is_5ghz_ch_freq(a3) )
    {
      if ( (unsigned int)v7 > 0x100 )
        goto LABEL_27;
      v9 = 3712;
    }
    else
    {
      if ( !wlan_reg_is_24ghz_ch_freq(a3) )
        goto LABEL_18;
      if ( (unsigned int)v7 > 0x80 )
        goto LABEL_27;
      v9 = 3568;
    }
    qdf_mem_copy(v8, (const void *)(v6 + v9), (unsigned int)v7);
LABEL_18:
    v18 = (unsigned __int64)(unsigned int)v7 << 32;
    if ( v18 >= 0x700000001LL )
    {
      v19 = 0;
      do
      {
        while ( 1 )
        {
          v20 = *(_DWORD *)&v8[8 * (unsigned __int8)(v19 + 1)];
          v21 = &v8[8 * (unsigned __int8)v19++];
          if ( v20 <= a3 )
            break;
          v18 -= 0x800000000LL;
          if ( v18 <= 0x700000000LL )
            goto LABEL_26;
        }
        v18 -= 0x800000000LL;
      }
      while ( v20 + (unsigned __int8)v21[4] <= a3 && v18 > 0x700000000LL );
LABEL_26:
      v23 = (unsigned __int8)v21[5];
      goto LABEL_28;
    }
LABEL_27:
    v23 = 0;
LABEL_28:
    _qdf_mem_free((__int64)v8);
    return v23;
  }
  return result;
}
