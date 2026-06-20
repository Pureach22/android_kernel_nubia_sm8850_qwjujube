_QWORD *__fastcall wma_chan_phy_mode(unsigned int a1, unsigned int a2, unsigned __int8 a3)
{
  unsigned __int16 bw_value; // w22
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _QWORD *result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w21
  __int64 v25; // x23
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w8
  int v36; // w9
  int v38; // w9
  bool v40; // zf
  int v41; // w9
  unsigned int v42; // w22

  bw_value = wlan_reg_get_bw_value(a2);
  result = _cds_get_context(54, (__int64)"wma_chan_phy_mode", v7, v8, v9, v10, v11, v12, v13, v14);
  if ( !result )
    return result;
  v24 = a3;
  if ( a3 != 1 && a2 <= 7 && bw_value && (!wlan_reg_is_24ghz_ch_freq(a1) || bw_value < 0x29u) )
  {
    if ( wlan_reg_is_24ghz_ch_freq(a1) )
    {
      if ( a2 - 5 <= 1 )
      {
        v34 = 3;
        if ( a3 <= 6u )
        {
          if ( (unsigned int)a3 - 3 < 3 || !a3 )
            goto LABEL_112;
          if ( a3 != 6 )
            goto LABEL_92;
LABEL_24:
          if ( bw_value == 20 || bw_value == 40 )
            v34 = 4;
          else
            v34 = 0;
          goto LABEL_112;
        }
        if ( a3 > 8u )
        {
          if ( a3 != 9 )
          {
            if ( a3 != 10 )
            {
              if ( a3 != 11 )
                goto LABEL_92;
LABEL_42:
              if ( bw_value == 40 )
                v36 = 26;
              else
                v36 = 0;
              if ( bw_value == 20 )
                v34 = 22;
              else
                v34 = v36;
            }
LABEL_112:
            v42 = v34;
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: phymode %d freq %d ch_width %d dot11_mode %d",
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              "wma_chan_phy_mode",
              v34,
              a1,
              a2,
              a3);
            return (_QWORD *)v42;
          }
LABEL_69:
          if ( bw_value == 20 )
            v34 = 12;
          else
            v34 = 16 * (bw_value == 40);
          goto LABEL_112;
        }
        if ( a3 != 7 )
        {
          if ( a3 != 8 )
            goto LABEL_92;
          goto LABEL_112;
        }
        goto LABEL_76;
      }
      if ( a3 > 6u )
      {
        if ( (unsigned int)a3 - 8 < 2 )
          goto LABEL_69;
        if ( (unsigned int)a3 - 10 < 2 )
          goto LABEL_42;
        if ( a3 == 7 )
          goto LABEL_76;
      }
      else
      {
        if ( a3 <= 3u )
        {
          if ( a3 )
          {
            if ( a3 == 3 )
            {
              if ( bw_value == 20 || bw_value == 40 )
                v34 = 2;
              else
                v34 = 0;
              goto LABEL_112;
            }
            goto LABEL_92;
          }
          goto LABEL_69;
        }
        switch ( a3 )
        {
          case 4u:
            if ( bw_value == 20 || bw_value == 40 )
              v34 = 3;
            else
              v34 = 0;
            goto LABEL_112;
          case 5u:
LABEL_76:
            if ( bw_value == 40 )
              v38 = 10;
            else
              v38 = 0;
            if ( bw_value == 20 )
              v34 = 6;
            else
              v34 = v38;
            goto LABEL_112;
          case 6u:
            goto LABEL_24;
        }
      }
LABEL_92:
      v34 = 0;
      goto LABEL_112;
    }
    if ( (wlan_reg_is_dsrc_freq() & 1) != 0 )
    {
      v34 = 1;
      goto LABEL_112;
    }
    if ( a2 - 5 > 1 )
    {
      v34 = 1;
      if ( a3 > 0xBu )
        goto LABEL_52;
      if ( ((1 << a3) & 0xA0) != 0 )
        goto LABEL_84;
      if ( ((1 << a3) & 0x300) != 0 )
        goto LABEL_57;
      if ( ((1 << a3) & 0xC00) == 0 )
      {
LABEL_52:
        if ( a3 )
          goto LABEL_53;
        goto LABEL_57;
      }
    }
    else
    {
      v34 = 1;
      if ( a3 <= 7u )
      {
        if ( a3 <= 4u )
        {
          if ( !a3 )
            goto LABEL_112;
LABEL_53:
          if ( a3 != 2 )
            goto LABEL_92;
          goto LABEL_112;
        }
        if ( a3 == 5 )
          goto LABEL_112;
        if ( a3 != 7 )
          goto LABEL_92;
LABEL_84:
        if ( bw_value == 20 )
        {
          v34 = 5;
        }
        else if ( bw_value <= 0x27u )
        {
          v34 = 0;
        }
        else
        {
          v34 = 7;
        }
        goto LABEL_112;
      }
      if ( a3 <= 9u )
      {
        if ( a3 == 8 )
          goto LABEL_112;
LABEL_57:
        switch ( bw_value )
        {
          case 0x14u:
            v34 = 11;
            goto LABEL_112;
          case 0x50u:
            v34 = 17;
            goto LABEL_112;
          case 0x28u:
            v34 = 13;
            goto LABEL_112;
        }
        v40 = a2 == 4;
        v34 = 20;
        v41 = 19;
LABEL_108:
        if ( !v40 )
          v34 = 0;
        if ( a2 == 3 )
          v34 = v41;
        goto LABEL_112;
      }
      if ( a3 == 10 )
        goto LABEL_112;
      if ( a3 != 11 )
        goto LABEL_92;
    }
    switch ( bw_value )
    {
      case 0x14u:
        v34 = 21;
        goto LABEL_112;
      case 0x50u:
        v34 = 27;
        goto LABEL_112;
      case 0x28u:
        v34 = 23;
        goto LABEL_112;
    }
    v40 = a2 == 4;
    v34 = 30;
    v41 = 29;
    goto LABEL_108;
  }
  v25 = jiffies;
  if ( wma_chan_phy_mode___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid channel width %d freq %d dot11_mode %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wma_chan_phy_mode",
      a2,
      a1,
      v24);
    wma_chan_phy_mode___last_ticks = v25;
  }
  return nullptr;
}
