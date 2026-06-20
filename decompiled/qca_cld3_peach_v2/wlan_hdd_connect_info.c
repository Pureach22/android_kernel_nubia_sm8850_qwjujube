__int64 __fastcall wlan_hdd_connect_info(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x25
  char v7; // w26
  unsigned int v8; // w0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x21
  __int64 v18; // x22
  __int64 vdev_by_user; // x0
  __int64 v20; // x8
  __int64 v21; // x23
  __int64 v22; // x0
  char current_hw_mode; // w27
  unsigned int *v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x0
  __int64 v34; // x8
  const char *v35; // x8
  const char *v36; // x9
  unsigned int v37; // w0
  char v38; // w24
  __int64 v39; // x22
  _BOOL4 v40; // w25
  __int64 v41; // x27
  int v42; // w3
  unsigned int v43; // w0
  unsigned int v44; // w0
  unsigned int v45; // w0
  int v46; // w28
  int v47; // w0
  int v48; // w24
  int v49; // w23
  const char *v50; // x0
  int v51; // w25
  const char *v52; // x26
  const char *v53; // x0
  __int64 v54; // x10
  const char *v55; // x9
  unsigned int v56; // w0
  __int64 v57; // x23
  __int64 v58; // x21
  int v59; // w0
  __int64 v60; // x8
  __int64 v61; // x23
  __int64 v62; // x8
  int v63; // w0
  __int64 v64; // x23
  char v65; // w8
  __int64 v66; // x21
  int v67; // w0
  __int64 v68; // x8
  char v69; // w8
  int v70; // w0
  unsigned int v71; // w1
  char v73; // [xsp+6Ch] [xbp-14h]
  __int64 v74; // [xsp+70h] [xbp-10h]
  __int64 v75; // [xsp+78h] [xbp-8h]
  _BOOL4 v76; // [xsp+7Ch] [xbp-4h]

  if ( !hdd_cm_is_vdev_associated(*(_DWORD **)(a1 + 52832)) )
  {
    scnprintf(a2, a3, "STA is not connected\n");
    return 0;
  }
  v6 = *(_QWORD *)(a1 + 52832);
  if ( v6 == a1 + 52840 && *(_DWORD *)(v6 + 976) == 255 )
  {
    v7 = 1;
    v9 = scnprintf(a2, a3, "CONNECTION DETAILS: Non-ML connection\n");
  }
  else
  {
    v7 = 0;
    v9 = scnprintf(a2, a3, "CONNECTION DETAILS: ML connection\n");
  }
  if ( !v8 )
    return 0;
  v17 = v8;
  v18 = a3 - v8;
  if ( a3 <= v8 )
    goto LABEL_63;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52832), 0x58u, (__int64)"wlan_hdd_connect_info");
  if ( !vdev_by_user )
    return v17;
  v20 = *(_QWORD *)(vdev_by_user + 216);
  v21 = vdev_by_user;
  v22 = v20 ? *(_QWORD *)(v20 + 80) : 0LL;
  current_hw_mode = ucfg_policy_mgr_find_current_hw_mode(v22);
  _hdd_objmgr_put_vdev_by_user(
    v21,
    0x58u,
    (__int64)"wlan_hdd_connect_info",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32);
  v73 = v7;
  if ( v6 == -308 )
  {
    v74 = 0;
    v75 = 0;
  }
  else
  {
    LODWORD(v75) = *(unsigned __int8 *)(v6 + 310);
    HIDWORD(v75) = *(unsigned __int8 *)(v6 + 308);
    LODWORD(v74) = *(unsigned __int8 *)(v6 + 313);
    HIDWORD(v74) = *(unsigned __int8 *)(v6 + 309);
  }
  v33 = (const char *)hdd_auth_type_str(*(unsigned int *)(v6 + 888));
  v34 = *(unsigned int *)(v6 + 688);
  v35 = (unsigned int)v34 > 0xD ? "UNKNOWN" : off_B340A8[v34];
  v36 = (unsigned __int8)(current_hw_mode + 1) > 0xBu ? "UNKNOWN" : off_B34048[(unsigned __int8)(current_hw_mode + 1)];
  v9 = scnprintf(
         a2 + v17,
         v18,
         "ssid: %s\n"
         "bssid: %02x:%02x:%02x:**:**:%02x\n"
         "connect_time: %s\n"
         "auth_time: %s\n"
         "last_auth_type: %s\n"
         "dot11mode: %s\n"
         "current HW mode: %s\n",
         (const char *)(v6 + 849),
         HIDWORD(v75),
         HIDWORD(v74),
         v75,
         v74,
         (const char *)(v6 + 916),
         (const char *)(v6 + 892),
         v33,
         v35,
         v36);
  if ( !v37 )
    return v17;
  v17 += v37;
  if ( v17 >= (unsigned __int64)a3 )
  {
LABEL_63:
    v71 = 2;
LABEL_64:
    qdf_trace_msg(
      0x33u,
      v71,
      "%s: No sufficient buf_avail_len",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "wlan_hdd_connect_info");
    return a3;
  }
  else if ( a1 && a1 != -52840 )
  {
    v38 = v7;
    v39 = 0;
    v40 = 0;
    v41 = a1 + 53528;
    while ( 1 )
    {
      if ( (unsigned __int64)(0x71B3F945A27B1F49LL * (v39 >> 3)) > 2 )
        return v17;
      if ( (v38 & 1) != 0 )
        goto LABEL_38;
      v42 = *(_DWORD *)(v41 + v39 + 288);
      if ( v42 != 255 )
        break;
LABEL_60:
      v39 += 6088;
      if ( v41 + v39 == 688 )
        return v17;
    }
    v9 = scnprintf(a2 + v17, a3 - v17, "\nlink_id: %d\n", v42);
    if ( !v43 )
      return v17;
    v17 += v43;
    if ( a3 <= v17 )
      goto LABEL_66;
    v40 = *(unsigned __int8 *)(v41 + v39 - 680) == 255 && *(_DWORD *)(v41 + v39 + 288) != 255;
    v9 = scnprintf(a2 + v17, a3 - v17, "stand-by link: %d\n", v40);
    if ( !v44 )
      return v17;
    v17 += v44;
    if ( v17 >= a3 )
      goto LABEL_66;
LABEL_38:
    v76 = v40;
    if ( !v40 && hdd_cm_is_vdev_roaming(v41 + v39 - 688) )
    {
      scnprintf(a2 + v17, a3 - v17, "Roaming is in progress");
      if ( !v45 )
        return v17;
      v17 += v45;
    }
    v46 = cfg80211_calculate_bitrate(v41 + v39 + 16);
    v47 = cfg80211_calculate_bitrate(v41 + v39 + 30);
    v48 = *(_DWORD *)(v41 + v39 + 12);
    v49 = v47;
    v50 = hdd_ch_width_str(*(_DWORD *)(v41 + v39 + 252));
    v51 = *(char *)(v41 + v39 + 152);
    v52 = v50;
    v53 = (const char *)hdd_auth_type_str(*(unsigned int *)(v41 + v39 + 200));
    v54 = *(unsigned int *)(v41 + v39);
    v55 = "UNKNOWN";
    if ( (unsigned int)v54 <= 0xD )
      v55 = off_B340A8[v54];
    v9 = scnprintf(
           a2 + v17,
           a3 - v17,
           "freq: %u\n"
           "ch_width: %s\n"
           "signal: %ddBm\n"
           "tx_bit_rate: %u\n"
           "rx_bit_rate: %u\n"
           "last_auth_type: %s\n"
           "dot11mode: %s\n",
           v48,
           v52,
           v51,
           v46,
           v49,
           v53,
           v55);
    if ( !v56 )
      return v17;
    v57 = v17 + v56;
    if ( a3 <= v57 )
      goto LABEL_66;
    v58 = v41 + v39;
    if ( (*(_BYTE *)(v41 + v39 + 83) & 3) != 0 )
    {
      v9 = scnprintf(a2 + v57, a3 - v57, "nss = %u\n", *(unsigned __int8 *)(v58 + 21));
      v60 = v59 & (unsigned int)~(v59 >> 31);
    }
    else
    {
      v60 = 0;
    }
    v38 = v73;
    v40 = v76;
    v61 = v60 + v57;
    if ( a3 <= v61
      || ((*(_BYTE *)(v58 + 83) & 1) != 0
        ? (v9 = scnprintf(
                  a2 + v61,
                  a3 - v61,
                  "ht_cap_info = %x\n"
                  "ampdu_params_info = %x\n"
                  "extended_ht_cap_info = %x\n"
                  "tx_BF_cap_info = %x\n"
                  "antenna_selection_info = %x\n"
                  "ht_rx_higest = %x\n"
                  "ht_tx_params = %x\n",
                  *(unsigned __int16 *)(v41 + v39 + 45),
                  *(unsigned __int8 *)(v41 + v39 + 47),
                  *(unsigned __int16 *)(v41 + v39 + 64),
                  *(_DWORD *)(v41 + v39 + 66),
                  *(unsigned __int8 *)(v41 + v39 + 70),
                  *(unsigned __int16 *)(v41 + v39 + 58),
                  *(unsigned __int8 *)(v41 + v39 + 60)),
           v62 = v63 & (unsigned int)~(v63 >> 31))
        : (v62 = 0),
          v64 = v62 + v61,
          a3 <= v64) )
    {
LABEL_66:
      v71 = 8;
      goto LABEL_64;
    }
    v65 = *(_BYTE *)(v58 + 83);
    if ( (v65 & 2) != 0 )
    {
      scnprintf(
        a2 + v64,
        a3 - v64,
        "vht_cap_info = %x\nrx_mcs_map = %x\nrx_highest = %x\ntx_mcs_map = %x\ntx_highest = %x\n",
        *(_DWORD *)(v41 + v39 + 71),
        *(unsigned __int16 *)(v41 + v39 + 75),
        *(unsigned __int16 *)(v41 + v39 + 77),
        *(unsigned __int16 *)(v41 + v39 + 79),
        *(unsigned __int16 *)(v41 + v39 + 81));
      v69 = *(_BYTE *)(v58 + 83);
      v66 = (v70 & (unsigned int)~(v70 >> 31)) + v64;
      if ( (v69 & 0x40) != 0 )
        goto LABEL_56;
    }
    else
    {
      v66 = v64;
      if ( (v65 & 0x40) != 0 )
      {
LABEL_56:
        scnprintf(
          a2 + v66,
          a3 - v66,
          "mac_cap_info = 0x%02x%02x%02x%02x%02x%02x\n"
          "phy_cap_ch_width = 0x%02x\n"
          "phy_cap_8_to_23 = 0x%02x%02x\n"
          "phy_cap_24_to_39 = 0x%02x%02x\n"
          "phy_cap_40_to_55 = 0x%02x%02x\n"
          "phy_cap_56_to_71 = 0x%02x%02x\n"
          "phy_cap_72_to_87 = 0x%02x%02x\n",
          *(unsigned __int8 *)(v41 + v39 + 120),
          *(unsigned __int8 *)(v41 + v39 + 119),
          *(unsigned __int8 *)(v41 + v39 + 118),
          *(unsigned __int8 *)(v41 + v39 + 117),
          *(unsigned __int8 *)(v41 + v39 + 116),
          *(unsigned __int8 *)(v41 + v39 + 115),
          *(unsigned __int8 *)(v41 + v39 + 121),
          *(unsigned __int8 *)(v41 + v39 + 123),
          *(unsigned __int8 *)(v41 + v39 + 122),
          *(unsigned __int8 *)(v41 + v39 + 125),
          *(unsigned __int8 *)(v41 + v39 + 124),
          *(unsigned __int8 *)(v41 + v39 + 127),
          *(unsigned __int8 *)(v41 + v39 + 126),
          *(unsigned __int8 *)(v41 + v39 + 129),
          *(unsigned __int8 *)(v41 + v39 + 128),
          *(unsigned __int8 *)(v41 + v39 + 131),
          *(unsigned __int8 *)(v41 + v39 + 130));
        v68 = v67 & (unsigned int)~(v67 >> 31);
        goto LABEL_59;
      }
    }
    v68 = 0;
LABEL_59:
    v17 = v68 + v66;
    if ( (v73 & 1) != 0 )
      return v17;
    goto LABEL_60;
  }
  return v17;
}
