__int64 __fastcall reg_get_5g_bonded_channel_for_pwrmode(
        __int64 a1,
        unsigned __int16 a2,
        unsigned int a3,
        unsigned __int16 **a4,
        unsigned int a5,
        unsigned __int16 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  unsigned int _320_bonded_channel_state_for_pwrmode; // w0
  unsigned int v18; // w8
  unsigned int v19; // w9
  unsigned int v20; // w21
  unsigned __int16 *bonded_chan_entry; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w23
  unsigned int v32; // w8
  unsigned __int16 *v33; // x22
  char v34; // w24
  unsigned __int64 v35; // x25
  unsigned int channel_state_for_pwrmode; // w0
  __int64 v37; // x20
  _QWORD v39[3]; // [xsp+8h] [xbp-18h]

  v39[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 == 7 )
  {
    v18 = 0;
    v39[0] = 0;
    v39[1] = 0;
    if ( (unsigned __int16)(a2 >> 2) >= 0x55Fu && a2 <= 0x1658u )
    {
      v39[0] = &bonded_chan_320mhz_list_freq;
      v18 = 1;
    }
    v19 = a2 >> 4;
    if ( a2 >= 0x1743u && v19 <= 0x186 )
      v39[v18++] = &unk_AD7E84;
    if ( v18 <= 1 )
    {
      if ( a2 >= 0x17E3u && v19 <= 0x190 )
        v39[v18++] = &unk_AD7E88;
      if ( v18 <= 1 )
      {
        if ( a2 >= 0x1883u && v19 <= 0x19A )
          v39[v18++] = &unk_AD7E8C;
        if ( v18 <= 1 )
        {
          if ( a2 >= 0x1923u && v19 <= 0x1A4 )
            v39[v18++] = &unk_AD7E90;
          if ( v18 <= 1 )
          {
            if ( a2 >= 0x19C3u && v19 <= 0x1AE )
              v39[v18++] = &unk_AD7E94;
            if ( v18 <= 1 )
            {
              if ( a2 >= 0x1A63u && v19 <= 0x1B8 )
              {
                v39[v18] = &unk_AD7E98;
                v18 = 1;
              }
              if ( !v18 )
              {
                v20 = 4;
                qdf_trace_msg(
                  0x51u,
                  4u,
                  "%s: No 320MHz bonded pair for freq %d",
                  a7,
                  a8,
                  a9,
                  a10,
                  a11,
                  a12,
                  a13,
                  a14,
                  "reg_get_chan_state_for_320",
                  a2);
                goto LABEL_46;
              }
            }
          }
        }
      }
    }
    *a4 = (unsigned __int16 *)v39[0];
    _320_bonded_channel_state_for_pwrmode = reg_get_320_bonded_channel_state_for_pwrmode(a1, a2);
    goto LABEL_32;
  }
  if ( !a3 )
  {
    _320_bonded_channel_state_for_pwrmode = reg_get_channel_state_for_pwrmode(
                                              a1,
                                              a2,
                                              a5,
                                              a7,
                                              a8,
                                              a9,
                                              a10,
                                              a11,
                                              a12,
                                              a13,
                                              a14);
LABEL_32:
    v20 = _320_bonded_channel_state_for_pwrmode;
    goto LABEL_46;
  }
  bonded_chan_entry = reg_get_bonded_chan_entry(a2, a3, 0, a7, a8, a9, a10, a11, a12, a13, a14);
  *a4 = bonded_chan_entry;
  if ( !bonded_chan_entry )
  {
    v37 = jiffies;
    if ( reg_get_5g_bonded_channel_for_pwrmode___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: bonded_chan_ptr_ptr is NULL",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "reg_get_5g_bonded_channel_for_pwrmode");
      reg_get_5g_bonded_channel_for_pwrmode___last_ticks = v37;
      v20 = 4;
      goto LABEL_46;
    }
    goto LABEL_44;
  }
  v31 = *bonded_chan_entry;
  v32 = bonded_chan_entry[1];
  v33 = bonded_chan_entry;
  if ( v31 > v32 )
  {
LABEL_44:
    v20 = 4;
    goto LABEL_46;
  }
  v34 = 0;
  v35 = a6;
  v20 = 4;
  do
  {
    if ( ((v35 >> v34) & 1) == 0 )
    {
      channel_state_for_pwrmode = reg_get_channel_state_for_pwrmode(
                                    a1,
                                    (unsigned __int16)v31,
                                    a5,
                                    v23,
                                    v24,
                                    v25,
                                    v26,
                                    v27,
                                    v28,
                                    v29,
                                    v30);
      LOWORD(v32) = v33[1];
      if ( channel_state_for_pwrmode < v20 )
        v20 = channel_state_for_pwrmode;
    }
    LOWORD(v31) = v31 + 20;
    ++v34;
  }
  while ( (unsigned __int16)v31 <= (unsigned int)(unsigned __int16)v32 );
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return v20;
}
