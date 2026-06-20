__int64 __fastcall reg_set_2g_channel_params_for_freq(
        __int64 a1,
        unsigned __int16 a2,
        unsigned int *a3,
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
  __int16 v16; // w8
  unsigned int v17; // w20
  __int16 v18; // w10
  unsigned int v19; // w24
  unsigned int v20; // w12
  __int64 v21; // x21
  const char *v22; // x2
  __int64 result; // x0
  __int64 v24; // x1
  __int64 v25; // x2
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x3
  unsigned int v29; // w24
  unsigned int v30; // w8
  char v31; // w9
  unsigned int v32; // w8

  v16 = 0;
  v17 = a2;
  v18 = 101;
  while ( 1 )
  {
    v19 = (v16 + v18) / 2;
    v20 = *(_DWORD *)(channel_map + 12LL * (int)v19);
    if ( v20 == a2 )
      break;
    if ( v20 >= a2 )
      v18 = v19 - 1;
    else
      v16 = v19 + 1;
    if ( v16 > v18 )
    {
      v21 = jiffies;
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
        reg_get_chan_enum_for_freq___last_ticks = v21;
      }
LABEL_10:
      v22 = "%s: chan freq is not valid";
      return qdf_trace_msg(0x51u, 2u, v22, a5, a6, a7, a8, a9, a10, a11, a12, "reg_set_2g_channel_params_for_freq");
    }
  }
  if ( v19 >= 0x66 )
    goto LABEL_10;
  result = reg_get_pdev_obj(a1, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !result )
  {
    v22 = "%s: reg pdev priv obj is NULL";
    return qdf_trace_msg(0x51u, 2u, v22, a5, a6, a7, a8, a9, a10, a11, a12, "reg_set_2g_channel_params_for_freq");
  }
  v28 = *a3;
  if ( (unsigned int)v28 < 9 )
  {
    if ( a4 || (unsigned int)(v28 - 1) > 3 )
      goto LABEL_24;
    goto LABEL_19;
  }
  v28 = 1;
  *a3 = 1;
  if ( !a4 )
  {
LABEL_19:
    if ( v17 - 2412 > 0x14 )
    {
      if ( v17 - 2437 >= 0x24 )
        a4 = 0;
      else
        a4 = a2 - 20;
    }
    else
    {
      a4 = a2 + 20;
    }
  }
LABEL_24:
  v29 = *(unsigned __int16 *)(result + 36LL * v19 + 22);
  if ( (int)v28 <= 3 )
    goto LABEL_41;
LABEL_31:
  if ( (int)v28 <= 5 )
  {
    if ( (_DWORD)v28 != 4 )
    {
      if ( v29 < 5 )
        goto LABEL_26;
      goto LABEL_52;
    }
  }
  else
  {
    if ( (_DWORD)v28 == 6 )
    {
      if ( v29 < 0xA )
        goto LABEL_26;
      goto LABEL_52;
    }
    if ( (_DWORD)v28 != 9 )
    {
      if ( (_DWORD)v28 == 8 )
        goto LABEL_63;
LABEL_52:
      result = reg_get_2g_bonded_channel_state_for_freq(a1, v17, a4, v28, a5, a6, a7, a8, a9, a10, a11, a12);
      v28 = *a3;
      if ( (result & 0xFFFFFFFE) != 2 )
        goto LABEL_26;
      if ( (_DWORD)v28 == 1 )
      {
        v30 = (a4 + v17) >> 1;
        if ( a4 > (unsigned int)a2 )
          v31 = 1;
        else
          v31 = 3;
        *((_BYTE *)a3 + 4) = v31;
        a3[2] = v30;
        if ( v30 != 2484 )
        {
          v32 = (v30 - 2407) / 5;
LABEL_62:
          *((_BYTE *)a3 + 5) = v32;
LABEL_63:
          a3[3] = 0;
          *((_BYTE *)a3 + 6) = 0;
          return result;
        }
      }
      else
      {
        *((_BYTE *)a3 + 4) = 0;
        a3[2] = v17;
        if ( a2 != 2484 )
        {
          v32 = (v17 - 2407) / 5;
          goto LABEL_62;
        }
      }
      LOBYTE(v32) = 14;
      goto LABEL_62;
    }
  }
LABEL_47:
  if ( v29 >= 0xA0 )
    goto LABEL_52;
  while ( 1 )
  {
LABEL_26:
    if ( (unsigned int)v28 > 7 )
    {
      v28 = 8;
      goto LABEL_30;
    }
    if ( (_DWORD)v28 == 7 )
      break;
    v28 = get_next_lower_bandwidth_get_next_lower_bw[(unsigned int)v28];
LABEL_30:
    *a3 = v28;
    if ( (int)v28 > 3 )
      goto LABEL_31;
LABEL_41:
    if ( (int)v28 > 1 )
    {
      if ( (_DWORD)v28 != 2 )
        goto LABEL_47;
      if ( v29 >= 0x50 )
        goto LABEL_52;
    }
    else if ( (_DWORD)v28 )
    {
      if ( (_DWORD)v28 != 1 || v29 >= 0x28 )
        goto LABEL_52;
    }
    else if ( v29 >= 0x14 )
    {
      goto LABEL_52;
    }
  }
  __break(0x5512u);
  return reg_set_channel_params_for_pwrmode(result, v24, v25, v28, v26, v27);
}
