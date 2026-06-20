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
  int v47; // w9
  unsigned int v48; // w8
  unsigned int v49; // w9
  __int64 v50; // x9
  unsigned __int8 *v51; // x22
  unsigned int v52; // w4
  int v53; // w8
  int v54; // w8
  int v55; // w8
  __int64 v56; // x0
  __int64 v57; // x2
  __int64 v58; // x1
  __int64 v59; // x3
  unsigned __int8 *v60; // x22
  unsigned int v61; // w21
  int v62; // w8

  if ( !wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a2 + 1192)) )
  {
    if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 1192)) )
    {
      result = 21;
      if ( !*(_QWORD *)(a2 + 1696) )
        return result;
      v26 = *(unsigned __int8 **)(a2 + 1712);
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
      v60 = &v26[v30 + (v29 >> 7)];
      if ( !v60 )
        return result;
      if ( (v60[1] & 3u) <= 1 )
      {
        if ( (v60[1] & 3) != 0 )
          v61 = 23;
        else
          v61 = 21;
        goto LABEL_104;
      }
      if ( (v60[1] & 3) != 2 && v60[3] )
      {
        v62 = v60[3] - v60[2];
        if ( v62 < 0 )
          v62 = v60[2] - v60[3];
        if ( (unsigned int)v62 > 8 )
        {
          v61 = 30;
LABEL_104:
          if ( v60[2] )
            *(_DWORD *)(a2 + 1196) = wlan_reg_chan_band_to_freq(a1, v60[2], 4u, v18, v19, v20, v21, v22, v23, v24, v25);
          if ( v60[3] )
            *(_DWORD *)(a2 + 1200) = wlan_reg_chan_band_to_freq(a1, v60[3], 4u, v18, v19, v20, v21, v22, v23, v24, v25);
          v56 = a1;
          v58 = a2;
          v57 = v61;
          v59 = 4;
          return util_scan_get_phymode_11be(v56, v58, v57, v59);
        }
        if ( v62 == 8 )
        {
          v61 = 29;
          goto LABEL_104;
        }
      }
      v61 = 27;
      goto LABEL_104;
    }
    v31 = *(__int16 **)(a2 + 1456);
    result = 1;
    if ( !v31 )
      return result;
    v32 = *(_QWORD *)(a2 + 1464);
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
    v43 = *(_DWORD *)(a2 + 1192);
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
    v50 = *(_QWORD *)(a2 + 1560);
    v51 = *(unsigned __int8 **)(a2 + 1568);
    *(_DWORD *)(a2 + 1196) = v44;
    if ( !v50 || !v51 )
      goto LABEL_81;
    v52 = v51[2];
    if ( v52 > 1 )
    {
      if ( v52 == 2 )
        goto LABEL_75;
      if ( v52 == 3 )
      {
LABEL_74:
        v35 = 20;
        goto LABEL_77;
      }
    }
    else
    {
      if ( !v51[2] )
      {
LABEL_77:
        if ( v51[3] )
          *(_DWORD *)(a2 + 1196) = wlan_reg_chan_band_to_freq(a1, v51[3], 2u, v18, v19, v20, v21, v22, v23, v24, v25);
        if ( !v51[4] )
        {
          result = v35;
          if ( !*(_QWORD *)(a2 + 1696) )
            return result;
          goto LABEL_82;
        }
        v54 = wlan_reg_chan_band_to_freq(a1, v51[4], 2u, v18, v19, v20, v21, v22, v23, v24, v25);
        result = v35;
        *(_DWORD *)(a2 + 1200) = v54;
LABEL_81:
        if ( !*(_QWORD *)(a2 + 1696) )
          return result;
LABEL_82:
        v55 = result - 11;
        if ( (unsigned int)(result - 11) > 9 || ((0x345u >> v55) & 1) == 0 )
          return result;
        v56 = a1;
        v57 = dword_AD8540[v55];
        v58 = a2;
        v59 = 2;
        return util_scan_get_phymode_11be(v56, v58, v57, v59);
      }
      if ( v52 == 1 )
      {
        if ( !v51[4] )
        {
LABEL_71:
          v35 = 17;
          goto LABEL_77;
        }
        v53 = v51[4] - v51[3];
        if ( v53 < 0 )
          v53 = v51[3] - v51[4];
        if ( (unsigned int)v53 <= 8 )
        {
          if ( v53 != 8 )
            goto LABEL_71;
LABEL_75:
          v35 = 19;
          goto LABEL_77;
        }
        goto LABEL_74;
      }
    }
    qdf_trace_msg(0x15u, 8u, "%s: bad channel: %d", v18, v19, v20, v21, v22, v23, v24, v25, "util_scan_get_phymode_5g");
    v35 = 11;
    goto LABEL_77;
  }
  v12 = *(_WORD **)(a2 + 1456);
  if ( v12 )
  {
    v13 = *(_QWORD *)(a2 + 1464);
    if ( v13 )
    {
      v14 = *(_DWORD *)(v13 + 1) & 3;
      if ( (*v12 & 2) != 0 )
      {
        if ( v14 == 3 )
        {
          v15 = *(_DWORD *)(a2 + 1192);
          result = 9;
          v17 = 15;
          goto LABEL_47;
        }
        if ( v14 == 1 )
        {
          v15 = *(_DWORD *)(a2 + 1192);
          result = 8;
          v17 = 14;
LABEL_25:
          v36 = v15 + 10;
          goto LABEL_48;
        }
      }
      v15 = *(_DWORD *)(a2 + 1192);
      result = 6;
      v17 = 12;
      if ( v14 != 3 )
      {
        if ( v14 == 1 )
          goto LABEL_25;
        v36 = 0;
LABEL_48:
        v45 = *(_QWORD *)(a2 + 1560);
        v46 = *(_QWORD *)(a2 + 1568);
        *(_DWORD *)(a2 + 1196) = v36;
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
        if ( *(_QWORD *)(a2 + 1696) )
        {
          v47 = result - 8;
          if ( (unsigned int)(result - 8) > 7 )
          {
            v49 = 32;
            v48 = 22;
          }
          else
          {
            v48 = dword_B35608[v47];
            v49 = dword_B352E8[v47];
          }
          if ( *(_QWORD *)(a2 + 1800) )
            return v49;
          else
            return v48;
        }
        return result;
      }
LABEL_47:
      v36 = v15 - 10;
      goto LABEL_48;
    }
  }
  if ( *(_QWORD *)(a2 + 1360) )
    return 3;
  v37 = *(_QWORD *)(a2 + 1352);
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
