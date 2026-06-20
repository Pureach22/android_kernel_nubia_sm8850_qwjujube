__int64 __fastcall hdd_get_station_remote_ex(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 *sta_info_by_mac; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 *v22; // x20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x21
  __int64 v32; // x20
  unsigned int v33; // w20
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x24
  unsigned int v43; // w8
  unsigned int v44; // w10
  int v45; // w9
  unsigned int v46; // w10
  int v47; // w8
  unsigned int v48; // w9
  unsigned int v49; // w11
  int v50; // w10
  unsigned int v51; // w8
  __int64 v52; // x3
  __int64 v53; // x0
  __int64 v54; // x21
  __int64 *v55; // x3
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x23
  __int64 v65; // x21
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 v74; // x23
  unsigned int v75; // w11
  int v76; // w11
  unsigned int v77; // w12
  int v78; // w12
  int v79; // w8
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  __int64 v88; // x23
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  __int64 v97; // x23
  __int64 v98; // x23
  __int64 *v100; // [xsp+0h] [xbp-30h] BYREF
  __int64 v101; // [xsp+8h] [xbp-28h] BYREF
  char v102[4]; // [xsp+10h] [xbp-20h] BYREF
  int v103; // [xsp+14h] [xbp-1Ch] BYREF
  int v104; // [xsp+18h] [xbp-18h] BYREF
  __int16 v105; // [xsp+1Ch] [xbp-14h]
  __int64 v106; // [xsp+28h] [xbp-8h]

  v106 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v104 = a3;
  v105 = WORD2(a3);
  sta_info_by_mac = hdd_get_sta_info_by_mac(
                      (__int64 **)(a2 + 38848),
                      (unsigned __int8 *)&v104,
                      0xAu,
                      3u,
                      a4,
                      a5,
                      a6,
                      a7,
                      a8,
                      a9,
                      a10,
                      a11);
  v100 = sta_info_by_mac;
  if ( sta_info_by_mac )
  {
    v22 = sta_info_by_mac;
    v102[0] = 0;
    v101 = 0;
    if ( (unsigned int)hdd_get_peer_stats(a2, sta_info_by_mac) )
    {
      v31 = jiffies;
      if ( hdd_get_connected_station_info_ex___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: hdd_get_peer_stats fail",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "hdd_get_connected_station_info_ex",
          v100,
          v101);
        hdd_get_connected_station_info_ex___last_ticks = v31;
      }
      goto LABEL_76;
    }
    if ( (unsigned int)wlan_mlme_get_sap_get_peer_info(*a1, v102) )
    {
      v42 = jiffies;
      if ( hdd_get_connected_station_info_ex___last_ticks_136 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Unable to fetch sap ger peer info",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "hdd_get_connected_station_info_ex",
          v100,
          v101);
        hdd_get_connected_station_info_ex___last_ticks_136 = v42;
      }
    }
    if ( v102[0] != 1 )
    {
      v51 = 26;
      goto LABEL_26;
    }
    v43 = *((_DWORD *)v22 + 117);
    if ( !v43 )
    {
      v47 = 64;
      v48 = *((_DWORD *)v22 + 118);
      if ( v48 )
        goto LABEL_18;
      goto LABEL_24;
    }
    v44 = v43 - 1;
    if ( v43 == 1 )
    {
      v45 = 0;
    }
    else
    {
      v45 = 0;
      if ( (_WORD)v43 )
      {
        v75 = HIWORD(v44);
        v44 = 0;
        if ( !v75 )
        {
          v45 = v43 & 0x1FFFE;
          v44 = 8 * (v43 & 0x1FFFE);
          v76 = v43 & 0x1FFFE;
          do
            v76 -= 2;
          while ( v76 );
          if ( v43 == v45 )
          {
            v46 = v44 - 8;
            goto LABEL_17;
          }
        }
      }
      else
      {
        v44 = 0;
      }
    }
    v46 = v44 - 8;
    do
    {
      ++v45;
      v46 += 8;
    }
    while ( v43 > (unsigned __int16)v45 );
LABEL_17:
    v47 = v46 + 72;
    v48 = *((_DWORD *)v22 + 118);
    if ( v48 )
    {
LABEL_18:
      v49 = v48 - 1;
      if ( v48 == 1 )
      {
        v50 = 0;
      }
      else
      {
        v50 = 0;
        if ( (_WORD)v48 )
        {
          v77 = HIWORD(v49);
          v49 = 0;
          if ( !v77 )
          {
            v50 = v48 & 0x1FFFE;
            v49 = 0;
            v78 = v48 & 0x1FFFE;
            do
            {
              v78 -= 2;
              v49 += 16;
            }
            while ( v78 );
            if ( v48 == v50 )
              goto LABEL_25;
          }
        }
        else
        {
          v49 = 0;
        }
      }
      do
      {
        ++v50;
        v49 += 8;
      }
      while ( v48 > (unsigned __int16)v50 );
LABEL_25:
      v51 = v47 + v49 + 26;
LABEL_26:
      if ( *((_BYTE *)v22 + 152) )
        v52 = v51 + 20;
      else
        v52 = v51;
      v53 = _cfg80211_alloc_reply_skb(a1[3], 103, 197, v52);
      if ( !v53 )
      {
        v65 = jiffies;
        if ( hdd_get_connected_station_info_ex___last_ticks_137 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: wlan_cfg80211_vendor_cmd_alloc_reply_skb failed",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "hdd_get_connected_station_info_ex");
          hdd_get_connected_station_info_ex___last_ticks_137 = v65;
        }
        v33 = -12;
        goto LABEL_77;
      }
      v54 = v53;
      if ( *(_DWORD *)((char *)v22 + 38) | *((unsigned __int16 *)v22 + 21) )
        v55 = (__int64 *)((char *)v22 + 38);
      else
        v55 = v22 + 4;
      if ( (unsigned int)nla_put(v53, 1, 6, v55) )
      {
        v64 = jiffies;
        if ( hdd_get_connected_station_info_ex___last_ticks_138 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to put MAC address",
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            "hdd_get_connected_station_info_ex");
          hdd_get_connected_station_info_ex___last_ticks_138 = v64;
        }
      }
      else
      {
        if ( v102[0] != 1 || !(unsigned int)hdd_add_peer_stats(v54, v22) )
        {
          if ( *((_BYTE *)v22 + 152) )
          {
            v79 = *((unsigned __int8 *)v22 + 136);
            LODWORD(v101) = 7;
            if ( v79 == 1 )
              HIDWORD(v101) = 1;
            else
              v79 = 0;
            if ( *((_BYTE *)v22 + 144) == 1 )
            {
              v79 |= 2u;
              HIDWORD(v101) = v79;
            }
            if ( *((_BYTE *)v22 + 145) == 1 )
              HIDWORD(v101) = v79 | 4;
            if ( (unsigned int)nla_put(v54, 2, 8, &v101) )
            {
              v88 = jiffies;
              if ( hdd_get_connected_station_info_ex___last_ticks_141 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Failed to put STA flags",
                  v80,
                  v81,
                  v82,
                  v83,
                  v84,
                  v85,
                  v86,
                  v87,
                  "hdd_get_connected_station_info_ex");
                hdd_get_connected_station_info_ex___last_ticks_141 = v88;
              }
              goto LABEL_75;
            }
            if ( *((_DWORD *)v22 + 35) >= 4u )
            {
              v98 = jiffies;
              if ( hdd_get_connected_station_info_ex___last_ticks_143 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Invalid guard_interval %d",
                  v80,
                  v81,
                  v82,
                  v83,
                  v84,
                  v85,
                  v86,
                  v87,
                  "hdd_get_connected_station_info_ex");
                hdd_get_connected_station_info_ex___last_ticks_143 = v98;
              }
              goto LABEL_75;
            }
            v103 = *((_DWORD *)v22 + 35);
            if ( (unsigned int)nla_put(v54, 3, 4, &v103) )
            {
              v97 = jiffies;
              if ( hdd_get_connected_station_info_ex___last_ticks_145 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Failed to put guard_interval",
                  v89,
                  v90,
                  v91,
                  v92,
                  v93,
                  v94,
                  v95,
                  v96,
                  "hdd_get_connected_station_info_ex");
                hdd_get_connected_station_info_ex___last_ticks_145 = v97;
              }
              goto LABEL_75;
            }
          }
          v33 = cfg80211_vendor_cmd_reply(v54);
LABEL_77:
          hdd_put_sta_info_ref(a2 + 38848, (__int64 *)&v100, 1, 0xAu, v23, v24, v25, v26, v27, v28, v29, v30);
          goto LABEL_78;
        }
        v74 = jiffies;
        if ( hdd_get_connected_station_info_ex___last_ticks_140 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: hdd_add_peer_stats fail",
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            "hdd_get_connected_station_info_ex");
          hdd_get_connected_station_info_ex___last_ticks_140 = v74;
        }
      }
LABEL_75:
      sk_skb_reason_drop(0, v54, 2);
LABEL_76:
      v33 = -22;
      goto LABEL_77;
    }
LABEL_24:
    v49 = v48;
    goto LABEL_25;
  }
  v32 = jiffies;
  if ( hdd_get_station_remote_ex___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to get peer STA %02x:%02x:%02x:**:**:%02x",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "hdd_get_station_remote_ex",
      (unsigned __int8)v104,
      BYTE1(v104),
      BYTE2(v104),
      HIBYTE(v105),
      v100);
    hdd_get_station_remote_ex___last_ticks = v32;
  }
  v33 = -6;
LABEL_78:
  _ReadStatusReg(SP_EL0);
  return v33;
}
