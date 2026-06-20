_QWORD *__fastcall wma_chan_phy_mode(unsigned int a1, unsigned int a2, unsigned int a3)
{
  unsigned int bw_value; // w22
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
  int v34; // w8
  unsigned int v35; // w0
  int v37; // w8
  int v38; // w9
  int v40; // w9
  bool v42; // zf
  int v43; // w8
  int v44; // w9
  unsigned int v45; // w22

  bw_value = wlan_reg_get_bw_value(a2);
  result = _cds_get_context(54, (__int64)"wma_chan_phy_mode", v7, v8, v9, v10, v11, v12, v13, v14);
  if ( !result )
    return result;
  v24 = (unsigned __int8)a3;
  if ( (unsigned __int8)a3 != 1
    && a2 <= 7
    && (_WORD)bw_value
    && (!wlan_reg_is_24ghz_ch_freq(a1) || (unsigned __int16)bw_value < 0x29u) )
  {
    if ( wlan_reg_is_24ghz_ch_freq(a1) )
    {
      if ( a2 - 5 <= 1 )
      {
        v34 = (unsigned __int8)a3;
        v35 = 3;
        if ( (unsigned __int8)a3 <= 6u )
        {
          if ( (unsigned int)(unsigned __int8)a3 - 3 < 3 || !(_BYTE)a3 )
            goto LABEL_113;
          goto LABEL_22;
        }
        if ( (unsigned __int8)a3 > 8u )
        {
          if ( (unsigned __int8)a3 != 9 )
          {
            if ( (unsigned __int8)a3 != 10 )
            {
              if ( (unsigned __int8)a3 != 11 )
                goto LABEL_92;
LABEL_41:
              if ( (unsigned __int16)bw_value == 40 )
                v38 = 26;
              else
                v38 = 0;
              if ( (unsigned __int16)bw_value == 20 )
                v35 = 22;
              else
                v35 = v38;
            }
LABEL_113:
            v45 = v35;
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
              v35,
              a1,
              a2,
              (unsigned __int8)a3);
            return (_QWORD *)v45;
          }
LABEL_69:
          if ( (unsigned __int16)bw_value == 20 )
            v35 = 12;
          else
            v35 = 16 * ((unsigned __int16)bw_value == 40);
          goto LABEL_113;
        }
        if ( (unsigned __int8)a3 != 7 )
        {
          if ( (unsigned __int8)a3 != 8 )
            goto LABEL_92;
          goto LABEL_113;
        }
        goto LABEL_76;
      }
      v34 = (unsigned __int8)a3;
      if ( (unsigned __int8)a3 <= 6u )
      {
        if ( (unsigned __int8)a3 <= 3u )
        {
          if ( (_BYTE)a3 )
          {
            if ( (unsigned __int8)a3 == 3 )
            {
              if ( (unsigned __int16)bw_value == 20 || (unsigned __int16)bw_value == 40 )
                v35 = 2;
              else
                v35 = 0;
              goto LABEL_113;
            }
            goto LABEL_92;
          }
          goto LABEL_69;
        }
        if ( (unsigned __int8)a3 == 4 )
        {
          if ( (unsigned __int16)bw_value == 20 || (unsigned __int16)bw_value == 40 )
            v35 = 3;
          else
            v35 = 0;
          goto LABEL_113;
        }
        if ( (unsigned __int8)a3 != 5 )
        {
LABEL_22:
          if ( v34 == 6 )
          {
            if ( (unsigned __int16)bw_value == 20 || (unsigned __int16)bw_value == 40 )
              v35 = 4;
            else
              v35 = 0;
            goto LABEL_113;
          }
          goto LABEL_92;
        }
LABEL_76:
        if ( (unsigned __int16)bw_value == 40 )
          v40 = 10;
        else
          v40 = 0;
        if ( (unsigned __int16)bw_value == 20 )
          v35 = 6;
        else
          v35 = v40;
        goto LABEL_113;
      }
      if ( (unsigned int)(unsigned __int8)a3 - 8 < 2 )
        goto LABEL_69;
      if ( (unsigned int)(unsigned __int8)a3 - 10 < 2 )
        goto LABEL_41;
      if ( (unsigned __int8)a3 == 7 )
        goto LABEL_76;
LABEL_92:
      v35 = wma_eht_chan_phy_mode(a1, a3, bw_value, a2);
      goto LABEL_113;
    }
    if ( (wlan_reg_is_dsrc_freq() & 1) != 0 )
    {
      v35 = 1;
      goto LABEL_113;
    }
    if ( a2 - 5 > 1 )
    {
      v37 = (unsigned __int8)a3;
      v35 = 1;
      if ( (unsigned __int8)a3 > 0xBu )
        goto LABEL_51;
      if ( ((1 << a3) & 0xA0) != 0 )
        goto LABEL_84;
      if ( ((1 << a3) & 0x300) != 0 )
        goto LABEL_57;
      if ( ((1 << a3) & 0xC00) == 0 )
      {
LABEL_51:
        if ( (_BYTE)a3 )
          goto LABEL_52;
        goto LABEL_57;
      }
    }
    else
    {
      v37 = (unsigned __int8)a3;
      v35 = 1;
      if ( (unsigned __int8)a3 <= 7u )
      {
        if ( (unsigned __int8)a3 <= 4u )
        {
          if ( !(_BYTE)a3 )
            goto LABEL_113;
LABEL_52:
          if ( v37 != 2 )
            goto LABEL_92;
          goto LABEL_113;
        }
        if ( (unsigned __int8)a3 == 5 )
          goto LABEL_113;
        if ( (unsigned __int8)a3 != 7 )
          goto LABEL_92;
LABEL_84:
        if ( (unsigned __int16)bw_value == 20 )
        {
          v35 = 5;
        }
        else if ( (unsigned __int16)bw_value <= 0x27u )
        {
          v35 = 0;
        }
        else
        {
          v35 = 7;
        }
        goto LABEL_113;
      }
      if ( (unsigned __int8)a3 <= 9u )
      {
        if ( (unsigned __int8)a3 == 8 )
          goto LABEL_113;
        if ( (unsigned __int8)a3 != 9 )
          goto LABEL_92;
LABEL_57:
        switch ( (unsigned __int16)bw_value )
        {
          case 0x14u:
            v35 = 11;
            goto LABEL_113;
          case 0x50u:
            v35 = 17;
            goto LABEL_113;
          case 0x28u:
            v35 = 13;
            goto LABEL_113;
        }
        v42 = a2 == 4;
        v43 = 20;
        v44 = 19;
LABEL_108:
        if ( !v42 )
          v43 = 0;
        if ( a2 == 3 )
          v35 = v44;
        else
          v35 = v43;
        goto LABEL_113;
      }
      if ( (unsigned __int8)a3 == 10 )
        goto LABEL_113;
      if ( (unsigned __int8)a3 != 11 )
        goto LABEL_92;
    }
    switch ( (unsigned __int16)bw_value )
    {
      case 0x14u:
        v35 = 21;
        goto LABEL_113;
      case 0x50u:
        v35 = 27;
        goto LABEL_113;
      case 0x28u:
        v35 = 23;
        goto LABEL_113;
    }
    v42 = a2 == 4;
    v43 = 30;
    v44 = 29;
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
