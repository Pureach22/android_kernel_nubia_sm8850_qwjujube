__int64 __fastcall reg_set_2g_channel_params_for_freq(
        __int64 a1,
        unsigned __int16 a2,
        __int64 a3,
        unsigned __int16 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int16 v15; // w8
  unsigned int v16; // w20
  __int16 v17; // w10
  unsigned int v18; // w23
  unsigned int v19; // w12
  __int64 v20; // x21
  const char *v21; // x2
  __int64 result; // x0
  signed int v24; // w3
  unsigned int v25; // w8
  unsigned int v26; // w24
  unsigned int v27; // w8
  char v28; // w9
  unsigned int v29; // w8

  v15 = 0;
  v16 = a2;
  v17 = 101;
  while ( 1 )
  {
    v18 = (v15 + v17) / 2;
    v19 = *(_DWORD *)(channel_map + 12LL * (int)v18);
    if ( v19 == a2 )
      break;
    if ( v19 >= a2 )
      v17 = v18 - 1;
    else
      v15 = v18 + 1;
    if ( v15 > v17 )
    {
      v20 = jiffies;
      if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x51u,
          8u,
          "%s: invalid channel center frequency %d",
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          a12,
          "reg_get_chan_enum_for_freq",
          a2);
        reg_get_chan_enum_for_freq___last_ticks = v20;
      }
LABEL_10:
      v21 = "%s: chan freq is not valid";
      return qdf_trace_msg(0x51u, 2u, v21, a5, a6, a7, a8, a9, a10, a11, a12, "reg_set_2g_channel_params_for_freq");
    }
  }
  if ( v18 >= 0x66 )
    goto LABEL_10;
  result = reg_get_pdev_obj(a1, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !result )
  {
    v21 = "%s: reg pdev priv obj is NULL";
    return qdf_trace_msg(0x51u, 2u, v21, a5, a6, a7, a8, a9, a10, a11, a12, "reg_set_2g_channel_params_for_freq");
  }
  v24 = *(_DWORD *)a3;
  if ( *(_DWORD *)a3 >= 9u )
  {
    v24 = 1;
    *(_DWORD *)a3 = 1;
    if ( a4 )
      goto LABEL_25;
    goto LABEL_15;
  }
  v25 = v24 - 1;
  if ( (unsigned int)(v24 - 1) <= 6 && ((0x4Fu >> v25) & 1) != 0 )
  {
    v24 = dword_AD8194[v25];
    if ( !a4 )
    {
LABEL_15:
      if ( v16 - 2412 > 0x14 )
      {
        if ( v16 - 2437 >= 0x24 )
          a4 = 0;
        else
          a4 = a2 - 20;
      }
      else
      {
        a4 = a2 + 20;
      }
    }
  }
LABEL_25:
  v26 = *(unsigned __int16 *)(result + 36LL * v18 + 22);
  if ( v24 <= 4 )
    goto LABEL_43;
  while ( 1 )
  {
    if ( v24 > 6 )
    {
      if ( v24 == 7 || v24 == 9 )
      {
        if ( v26 >= 0x140 )
          goto LABEL_54;
        goto LABEL_27;
      }
      if ( v24 == 8 )
        goto LABEL_65;
      goto LABEL_54;
    }
    if ( v24 != 5 )
      break;
    if ( v26 >= 5 )
      goto LABEL_54;
LABEL_27:
    while ( 1 )
    {
      v24 = (unsigned int)v24 > 7 ? 8 : get_next_lower_bandwidth_get_next_lower_bw[v24];
      *(_DWORD *)a3 = v24;
      if ( v24 > 4 )
        break;
LABEL_43:
      if ( v24 <= 1 )
      {
        if ( v24 )
        {
          if ( v24 != 1 || v26 >= 0x28 )
            goto LABEL_54;
        }
        else if ( v26 >= 0x14 )
        {
          goto LABEL_54;
        }
      }
      else if ( v24 == 2 )
      {
        if ( v26 >= 0x50 )
          goto LABEL_54;
      }
      else if ( v26 >= 0xA0 )
      {
        goto LABEL_54;
      }
    }
  }
  if ( v26 < 0xA )
    goto LABEL_27;
LABEL_54:
  result = reg_get_2g_bonded_channel_state_for_freq(a1, v16, a4, v24, a5, a6, a7, a8, a9, a10, a11, a12);
  v24 = *(_DWORD *)a3;
  if ( (result & 0xFFFFFFFE) != 2 )
    goto LABEL_27;
  if ( v24 != 1 )
  {
    *(_BYTE *)(a3 + 4) = 0;
    *(_DWORD *)(a3 + 8) = v16;
    if ( a2 != 2484 )
    {
      v29 = (v16 - 2407) / 5;
      goto LABEL_64;
    }
    goto LABEL_62;
  }
  v27 = (a4 + v16) >> 1;
  if ( a4 > (unsigned int)a2 )
    v28 = 1;
  else
    v28 = 3;
  *(_BYTE *)(a3 + 4) = v28;
  *(_DWORD *)(a3 + 8) = v27;
  if ( v27 == 2484 )
  {
LABEL_62:
    LOBYTE(v29) = 14;
    goto LABEL_64;
  }
  v29 = (v27 - 2407) / 5;
LABEL_64:
  *(_BYTE *)(a3 + 5) = v29;
LABEL_65:
  *(_DWORD *)(a3 + 12) = 0;
  *(_BYTE *)(a3 + 6) = 0;
  return result;
}
