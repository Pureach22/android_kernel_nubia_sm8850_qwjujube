__int64 __fastcall wlan_hdd_p2p_connection_info(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  int v6; // w0
  unsigned int v7; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x21
  __int64 v17; // x22
  int v18; // w27
  int v19; // w23
  const char *v20; // x0
  int v21; // w26
  const char *v22; // x28
  const char *v23; // x0
  __int64 v24; // x8
  const char *v25; // x8
  __int64 result; // x0
  int v27; // w0
  int v28; // w8
  unsigned int v29; // [xsp+54h] [xbp-1Ch]
  int v30; // [xsp+58h] [xbp-18h]
  int v31; // [xsp+5Ch] [xbp-14h]
  int v32; // [xsp+60h] [xbp-10h]
  int v33; // [xsp+64h] [xbp-Ch]
  int v34; // [xsp+68h] [xbp-8h]
  int v35; // [xsp+6Ch] [xbp-4h]

  v3 = *(_QWORD *)(a1 + 52832);
  if ( !v3 )
    return 0;
  if ( !hdd_cm_is_vdev_associated(*(_DWORD **)(a1 + 52832)) )
  {
    scnprintf(a2, a3, "P2P_Client is not connected\n");
    if ( (v6 & 0x80000000) == 0 )
      return 0;
  }
  v8 = scnprintf(a2, a3, "\nP2P_CLIENT CONNECTION DETAILS\n");
  if ( (int)v7 < 1 )
    return 0;
  v16 = a3 - v7;
  if ( a3 <= v7 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: No sufficient buf_avail_len",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wlan_hdd_p2p_connection_info");
    return a3;
  }
  else
  {
    v29 = v7;
    v17 = v7;
    v30 = cfg80211_calculate_bitrate(v3 + 704);
    v18 = cfg80211_calculate_bitrate(v3 + 718);
    v19 = *(_DWORD *)(v3 + 700);
    v34 = *(unsigned __int8 *)(v3 + 308);
    v35 = *(unsigned __int8 *)(v3 + 316);
    v32 = *(unsigned __int8 *)(v3 + 310);
    v33 = *(unsigned __int8 *)(v3 + 309);
    v31 = *(unsigned __int8 *)(v3 + 313);
    v20 = hdd_ch_width_str(*(_DWORD *)(v3 + 940));
    v21 = *(char *)(v3 + 840);
    v22 = v20;
    v23 = (const char *)hdd_auth_type_str(*(unsigned int *)(v3 + 888));
    v24 = *(unsigned int *)(v3 + 688);
    if ( (unsigned int)v24 > 0xD )
      v25 = "UNKNOWN";
    else
      v25 = off_B340A8[v24];
    scnprintf(
      a2 + v17,
      v16,
      "ssid = %.*s\n"
      "bssid = %02x:%02x:%02x:**:**:%02x\n"
      "connect_time = %s\n"
      "auth_time = %s\n"
      "freq = %u\n"
      "ch_width = %s\n"
      "signal = %ddBm\n"
      "tx_bit_rate = %u\n"
      "rx_bit_rate = %u\n"
      "last_auth_type = %s\n"
      "dot11mode = %s\n",
      v35,
      (const char *)(v3 + 317),
      v34,
      v33,
      v32,
      v31,
      (const char *)(v3 + 916),
      (const char *)(v3 + 892),
      v19,
      v22,
      v21,
      v30,
      v18,
      v23,
      v25);
    v28 = v27;
    result = v17;
    if ( (v28 & 0x80000000) == 0 )
      return v28 + v29;
  }
  return result;
}
