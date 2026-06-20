__int64 __fastcall reg_get_320_bonded_channel_state_for_pwrmode(
        __int64 a1,
        unsigned int a2,
        unsigned __int16 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        _WORD *a13,
        unsigned int a14,
        char a15,
        unsigned __int16 a16)
{
  unsigned int v16; // w8
  __int64 v19; // x23
  unsigned int v20; // w22
  bool v21; // w23
  unsigned int v22; // w8
  char v23; // w28
  unsigned __int64 v24; // x20
  unsigned int v25; // w27
  unsigned int v26; // w24
  unsigned int channel_state_for_pwrmode; // w0
  __int16 v28; // w26
  __int16 v29; // w9
  __int16 v30; // w10
  unsigned int v31; // w1
  unsigned int v32; // w11
  unsigned int v33; // w23
  unsigned int v34; // w25
  __int64 v35; // x22
  unsigned int v36; // w8
  __int64 v37; // x8
  __int64 v38; // x9
  __int64 v39; // x9
  int v40; // w9
  unsigned int v41; // w8
  int chan_state; // w0
  __int16 v43; // w9
  __int16 v44; // w10
  unsigned int v45; // w1
  unsigned int v46; // w12
  __int64 v47; // x21
  unsigned __int16 v52; // [xsp+18h] [xbp-8h]

  *a13 = -1;
  if ( !a3 )
    return 4;
  v16 = *a3;
  v19 = a1;
  if ( v16 <= 0xFED3 )
  {
    v23 = 0;
    v24 = a16;
    v25 = 4;
    v20 = 3;
    v26 = (unsigned __int16)(v16 + 300);
    v52 = 0;
    do
    {
      v28 = v16;
      if ( ((v24 >> v23) & 1) == 0 )
      {
        if ( (a15 & 1) != 0 )
        {
          channel_state_for_pwrmode = reg_get_channel_state_for_pwrmode(
                                        v19,
                                        (unsigned __int16)v16,
                                        a14,
                                        a4,
                                        a5,
                                        a6,
                                        a7,
                                        a8,
                                        a9,
                                        a10,
                                        a11);
        }
        else
        {
          v29 = 0;
          v30 = 101;
          while ( 1 )
          {
            v31 = (v29 + v30) / 2;
            v32 = *(_DWORD *)(channel_map + 12LL * (int)v31);
            if ( v32 == (unsigned __int16)v16 )
              break;
            if ( v32 >= (unsigned __int16)v16 )
              v30 = v31 - 1;
            else
              v29 = v31 + 1;
            if ( v29 > v30 )
            {
              v33 = a14;
              v34 = v20;
              v35 = jiffies;
              if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x51u,
                  8u,
                  "%s: invalid channel center frequency %d",
                  a4,
                  a5,
                  a6,
                  a7,
                  a8,
                  a9,
                  a10,
                  a11,
                  "reg_get_chan_enum_for_freq",
                  (unsigned __int16)v16);
                reg_get_chan_enum_for_freq___last_ticks = v35;
              }
              v20 = v34;
              a14 = v33;
              v19 = a1;
              goto LABEL_7;
            }
          }
          if ( v31 > 0x65 )
          {
LABEL_7:
            channel_state_for_pwrmode = 4;
            goto LABEL_8;
          }
          channel_state_for_pwrmode = reg_get_chan_state(v19, v31, a14, 0, a4, a5, a6, a7, a8, a9, a10, a11);
        }
        if ( (channel_state_for_pwrmode & 0xFFFFFFFB) != 0 )
        {
          if ( channel_state_for_pwrmode == 2 )
            v20 = 2;
          *a13 &= ~(unsigned __int16)(1LL << v23);
          v52 += 20;
        }
LABEL_8:
        if ( channel_state_for_pwrmode < v25 )
          v25 = channel_state_for_pwrmode;
      }
      LOWORD(v16) = v28 + 20;
      ++v23;
    }
    while ( v26 >= (unsigned __int16)(v28 + 20) );
    v36 = (unsigned __int16)*a13;
    v21 = v52 < 0xA0u;
    if ( v36 <= 0xEFF )
    {
      if ( (unsigned __int16)*a13 <= 0xBFu )
      {
        if ( v36 > 0x3F )
          goto LABEL_80;
        v37 = 1LL << v36;
        v39 = 0x8001000000009008LL;
        goto LABEL_48;
      }
      if ( (unsigned __int16)*a13 > 0x2FFu )
      {
        if ( (unsigned __int16)*a13 > 0xBFFu )
        {
          if ( v36 == 3072 || v36 == 3087 )
            goto LABEL_49;
        }
        else if ( v36 == 768 || v36 == 783 )
        {
          goto LABEL_49;
        }
        goto LABEL_80;
      }
      v41 = v36 - 192;
      if ( v41 > 0x30 )
      {
LABEL_80:
        v20 = v25;
        goto LABEL_49;
      }
      v37 = 1LL << v41;
      v38 = 32769;
LABEL_47:
      v39 = v38 & 0xFFFFFFFFFFFFLL | 0x1000000000000LL;
LABEL_48:
      if ( (v37 & v39) != 0 )
        goto LABEL_49;
      goto LABEL_80;
    }
    if ( (unsigned __int16)*a13 < 0xF000u )
    {
      if ( (unsigned __int16)*a13 <= 0x300Eu )
      {
        if ( v36 == 3840 || v36 == 12288 )
          goto LABEL_49;
        goto LABEL_80;
      }
      if ( v36 == 12303 || v36 == 49152 )
        goto LABEL_49;
      v40 = 49167;
    }
    else
    {
      if ( (unsigned __int16)*a13 <= 0xF0BFu )
      {
        if ( v36 - 61440 > 0x30 )
          goto LABEL_80;
        v37 = 1LL << v36;
        v38 = 4105;
        goto LABEL_47;
      }
      if ( v36 == 61632 || v36 == 64512 )
        goto LABEL_49;
      v40 = 62208;
    }
    if ( v36 == v40 )
      goto LABEL_49;
    goto LABEL_80;
  }
  v20 = 4;
  v21 = 1;
LABEL_49:
  if ( (a15 & 1) != 0 )
  {
    chan_state = reg_get_channel_state_for_pwrmode(a1, a2, a14, a4, a5, a6, a7, a8, a9, a10, a11);
  }
  else
  {
    v43 = 0;
    v44 = 101;
    while ( 1 )
    {
      v45 = (v43 + v44) / 2;
      v46 = *(_DWORD *)(channel_map + 12LL * (int)v45);
      if ( v46 == a2 )
        break;
      if ( v46 >= a2 )
        v44 = v45 - 1;
      else
        v43 = v45 + 1;
      if ( v43 > v44 )
      {
        v47 = jiffies;
        if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: invalid channel center frequency %d",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "reg_get_chan_enum_for_freq",
            a2);
          reg_get_chan_enum_for_freq___last_ticks = v47;
        }
        goto LABEL_60;
      }
    }
    if ( v45 > 0x65 )
    {
LABEL_60:
      chan_state = 4;
      goto LABEL_62;
    }
    chan_state = reg_get_chan_state(a1, v45, a14, 0, a4, a5, a6, a7, a8, a9, a10, a11);
  }
LABEL_62:
  v22 = 4;
  if ( (v20 & 0xFFFFFFFB) == 0 || !v21 )
  {
    if ( (chan_state & 0xFFFFFFFB) != 0 )
      return v20;
    else
      return 4;
  }
  return v22;
}
