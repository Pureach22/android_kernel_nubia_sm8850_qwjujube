__int64 __fastcall reg_get_chan_state_for_320(
        __int64 a1,
        unsigned __int16 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        _QWORD *a13)
{
  void *v14; // x2
  unsigned int v15; // w8
  unsigned int v16; // w9
  __int64 result; // x0
  _QWORD v18[3]; // [xsp+8h] [xbp-18h]

  v18[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  v18[1] = 0;
  if ( a3 > 6424 )
  {
    if ( a3 > 6744 )
    {
      if ( a3 == 6745 )
      {
        v14 = &unk_AD7E94;
        goto LABEL_48;
      }
      if ( a3 == 6905 )
      {
        v14 = &unk_AD7E98;
        goto LABEL_48;
      }
    }
    else
    {
      if ( a3 == 6425 )
      {
        v14 = &unk_AD7E8C;
        goto LABEL_48;
      }
      if ( a3 == 6585 )
      {
        v14 = &unk_AD7E90;
        goto LABEL_48;
      }
    }
  }
  else
  {
    if ( a3 <= 6104 )
    {
      v14 = &bonded_chan_320mhz_list_freq;
      if ( !a3 )
      {
        v15 = 0;
        if ( (unsigned __int16)(a2 >> 2) >= 0x55Fu && a2 <= 0x1658u )
        {
          v15 = 1;
          v18[0] = &bonded_chan_320mhz_list_freq;
        }
        v16 = a2 >> 4;
        if ( a2 >= 0x1743u && v16 <= 0x186 )
          v18[v15++] = &unk_AD7E84;
        if ( v15 <= 1 )
        {
          if ( a2 >= 0x17E3u && v16 <= 0x190 )
            v18[v15++] = &unk_AD7E88;
          if ( v15 <= 1 )
          {
            if ( a2 >= 0x1883u && v16 <= 0x19A )
              v18[v15++] = &unk_AD7E8C;
            if ( v15 <= 1 )
            {
              if ( a2 >= 0x1923u && v16 <= 0x1A4 )
                v18[v15++] = &unk_AD7E90;
              if ( v15 <= 1 )
              {
                if ( a2 >= 0x19C3u && v16 <= 0x1AE )
                  v18[v15++] = &unk_AD7E94;
                if ( v15 <= 1 )
                {
                  if ( a2 >= 0x1A63u && v16 <= 0x1B8 )
                  {
                    v18[v15] = &unk_AD7E98;
                    v15 = 1;
                  }
                  if ( !v15 )
                    goto LABEL_44;
                }
              }
            }
          }
        }
        v14 = (void *)v18[0];
LABEL_49:
        *a13 = v14;
        result = reg_get_320_bonded_channel_state_for_pwrmode(a1, a2);
        goto LABEL_50;
      }
      if ( a3 != 5650 )
        goto LABEL_44;
LABEL_48:
      v18[0] = v14;
      goto LABEL_49;
    }
    if ( a3 == 6105 )
    {
      v14 = &unk_AD7E84;
      goto LABEL_48;
    }
    if ( a3 == 6265 )
    {
      v14 = &unk_AD7E88;
      goto LABEL_48;
    }
  }
LABEL_44:
  qdf_trace_msg(
    0x51u,
    4u,
    "%s: No 320MHz bonded pair for freq %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "reg_get_chan_state_for_320",
    a2);
  result = 4;
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
