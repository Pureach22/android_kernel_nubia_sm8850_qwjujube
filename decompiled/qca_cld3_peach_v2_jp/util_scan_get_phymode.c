__int64 __fastcall util_scan_get_phymode(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  _WORD *v12; // x8
  __int64 v13; // x9
  int v14; // w10
  int v15; // w9
  __int64 result; // x0
  unsigned int v17; // w8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned __int8 *v26; // x8
  unsigned int v27; // w11
  char v28; // w10
  unsigned __int64 v29; // x9
  __int64 v30; // x11
  __int16 *v31; // x8
  __int64 v32; // x9
  __int16 v33; // w10
  int v34; // w8
  unsigned int v35; // w21
  int v36; // w9
  __int64 v37; // x9
  __int64 v38; // x8
  unsigned __int8 *v39; // x9
  int v40; // w14
  int v41; // t1
  unsigned int v42; // w14
  int v43; // w9
  int v44; // w8
  __int64 v45; // x11
  __int64 v46; // x10
  __int64 v47; // x9
  unsigned __int8 *v48; // x22
  unsigned int v49; // w4
  int v50; // w8
  int v51; // w8
  int v52; // w8
  unsigned __int8 *v53; // x21
  int v54; // w8
  unsigned int v55; // w22
  int v56; // w8
  unsigned int v57; // w1
  unsigned int v58; // w21

  if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 1064)) )
  {
    if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 1064)) )
    {
      result = 21;
      if ( !*(_QWORD *)(a2 + 1568) )
        return result;
      v26 = *(unsigned __int8 **)(a2 + 1584);
      if ( !v26 )
        return result;
      v27 = v26[1];
      v28 = v27 - 7;
      if ( v27 < 7 || (v26[5] & 2) == 0 || (_BYTE)v27 == 7 )
        return result;
      v29 = v26[4];
      if ( (v29 & 0x40) != 0 )
      {
        if ( (unsigned __int8)(v27 - 7) < 4u )
          return result;
        v28 = v27 - 10;
        v30 = 12;
      }
      else
      {
        v30 = 9;
      }
      if ( (unsigned __int8)(v28 + ((unsigned int)(char)v29 >> 7)) < 5u )
        return result;
      v53 = &v26[v30 + (v29 >> 7)];
      if ( !v53 )
        return result;
      if ( (v53[1] & 3u) <= 1 )
      {
        if ( (v53[1] & 3) != 0 )
          result = 23;
        goto LABEL_100;
      }
      if ( (v53[1] & 3) != 2 && v53[3] )
      {
        v54 = v53[3] - v53[2];
        if ( v54 < 0 )
          v54 = v53[2] - v53[3];
        if ( (unsigned int)v54 > 8 )
        {
          result = 30;
LABEL_100:
          if ( v53[2] )
          {
            v55 = result;
            v56 = wlan_reg_chan_band_to_freq(a1, v53[2], 4u, v18, v19, v20, v21, v22, v23, v24, v25);
            result = v55;
            *(_DWORD *)(a2 + 1068) = v56;
          }
          v57 = v53[3];
          if ( v53[3] )
          {
            v58 = result;
            *(_DWORD *)(a2 + 1072) = wlan_reg_chan_band_to_freq(a1, v57, 4u, v18, v19, v20, v21, v22, v23, v24, v25);
            return v58;
          }
          return result;
        }
        if ( v54 == 8 )
        {
          result = 29;
          goto LABEL_100;
        }
      }
      result = 27;
      goto LABEL_100;
    }
    v31 = *(__int16 **)(a2 + 1328);
    result = 1;
    if ( !v31 )
      return result;
    v32 = *(_QWORD *)(a2 + 1336);
    if ( !v32 )
      return result;
    v33 = *v31;
    v34 = *(_DWORD *)(v32 + 1) & 3;
    if ( (v33 & 2) != 0 && (*(_DWORD *)(v32 + 1) & 1 | 2) == 3 )
    {
      result = 7;
      v35 = 13;
    }
    else
    {
      result = 5;
      v35 = 11;
    }
    v43 = *(_DWORD *)(a2 + 1064);
    if ( v34 == 3 )
    {
      v44 = v43 - 10;
    }
    else if ( v34 == 1 )
    {
      v44 = v43 + 10;
    }
    else
    {
      v44 = 0;
    }
    v47 = *(_QWORD *)(a2 + 1432);
    v48 = *(unsigned __int8 **)(a2 + 1440);
    *(_DWORD *)(a2 + 1068) = v44;
    if ( !v47 || !v48 )
      goto LABEL_78;
    v49 = v48[2];
    if ( v49 > 1 )
    {
      if ( v49 == 2 )
        goto LABEL_72;
      if ( v49 == 3 )
      {
LABEL_71:
        v35 = 20;
        goto LABEL_74;
      }
    }
    else
    {
      if ( !v48[2] )
      {
LABEL_74:
        if ( v48[3] )
          *(_DWORD *)(a2 + 1068) = wlan_reg_chan_band_to_freq(a1, v48[3], 2u, v18, v19, v20, v21, v22, v23, v24, v25);
        if ( !v48[4] )
        {
          result = v35;
          if ( !*(_QWORD *)(a2 + 1568) )
            return result;
          goto LABEL_79;
        }
        v51 = wlan_reg_chan_band_to_freq(a1, v48[4], 2u, v18, v19, v20, v21, v22, v23, v24, v25);
        result = v35;
        *(_DWORD *)(a2 + 1072) = v51;
LABEL_78:
        if ( !*(_QWORD *)(a2 + 1568) )
          return result;
LABEL_79:
        v52 = result - 11;
        if ( (unsigned int)(result - 11) < 0xA && ((0x345u >> v52) & 1) != 0 )
          return dword_9E6730[v52];
        return result;
      }
      if ( v49 == 1 )
      {
        if ( !v48[4] )
        {
LABEL_68:
          v35 = 17;
          goto LABEL_74;
        }
        v50 = v48[4] - v48[3];
        if ( v50 < 0 )
          v50 = v48[3] - v48[4];
        if ( (unsigned int)v50 <= 8 )
        {
          if ( v50 != 8 )
            goto LABEL_68;
LABEL_72:
          v35 = 19;
          goto LABEL_74;
        }
        goto LABEL_71;
      }
    }
    qdf_trace_msg(0x15u, 8u, "%s: bad channel: %d", v18, v19, v20, v21, v22, v23, v24, v25, "util_scan_get_phymode_5g");
    v35 = 11;
    goto LABEL_74;
  }
  v12 = *(_WORD **)(a2 + 1328);
  if ( v12 )
  {
    v13 = *(_QWORD *)(a2 + 1336);
    if ( v13 )
    {
      v14 = *(_DWORD *)(v13 + 1) & 3;
      if ( (*v12 & 2) != 0 )
      {
        if ( v14 == 3 )
        {
          v15 = *(_DWORD *)(a2 + 1064);
          result = 9;
          v17 = 15;
          goto LABEL_47;
        }
        if ( v14 == 1 )
        {
          v15 = *(_DWORD *)(a2 + 1064);
          result = 8;
          v17 = 14;
LABEL_25:
          v36 = v15 + 10;
          goto LABEL_48;
        }
      }
      v15 = *(_DWORD *)(a2 + 1064);
      result = 6;
      v17 = 12;
      if ( v14 != 3 )
      {
        if ( v14 == 1 )
          goto LABEL_25;
        v36 = 0;
LABEL_48:
        v45 = *(_QWORD *)(a2 + 1432);
        v46 = *(_QWORD *)(a2 + 1440);
        *(_DWORD *)(a2 + 1068) = v36;
        if ( v45 )
        {
          if ( v46 )
          {
            result = v17;
            if ( *(_BYTE *)(v46 + 2) )
            {
              qdf_trace_msg(
                0x15u,
                4u,
                "%s: bad vht_op_chwidth: %d",
                v4,
                v5,
                v6,
                v7,
                v8,
                v9,
                v10,
                v11,
                "util_scan_get_phymode_2g");
              result = 12;
            }
          }
        }
        if ( *(_QWORD *)(a2 + 1568) )
        {
          if ( (unsigned int)(result - 8) >= 8 )
            return 22;
          else
            return dword_A30210[(unsigned int)(result - 8)];
        }
        return result;
      }
LABEL_47:
      v36 = v15 - 10;
      goto LABEL_48;
    }
  }
  if ( *(_QWORD *)(a2 + 1232) )
    return 3;
  v37 = *(_QWORD *)(a2 + 1224);
  if ( v37 )
  {
    v38 = *(unsigned __int8 *)(v37 + 1);
    if ( *(_BYTE *)(v37 + 1) )
    {
      v39 = (unsigned __int8 *)(v37 + 2);
      while ( 1 )
      {
        v41 = *v39++;
        v40 = v41;
        result = 3;
        if ( v41 <= 107 )
        {
          if ( (unsigned int)(v40 - 12) <= 0x3C && ((1LL << ((unsigned __int8)v40 - 12)) & 0x1000001001001041LL) != 0
            || v40 == 96 )
          {
            return result;
          }
        }
        else
        {
          if ( (unsigned int)(v40 - 108) <= 0x38 && ((1LL << ((unsigned __int8)v40 - 108)) & 0x100104100000001LL) != 0 )
            return result;
          v42 = v40 - 176;
          if ( v42 <= 0x3C && ((1LL << v42) & 0x1001000001000001LL) != 0 )
            return result;
        }
        --v38;
        result = 2;
        if ( !v38 )
          return result;
      }
    }
  }
  return 2;
}
