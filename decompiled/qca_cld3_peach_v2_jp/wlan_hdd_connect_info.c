unsigned __int64 __fastcall wlan_hdd_connect_info(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v5; // x21
  unsigned int v7; // w0
  long double v8; // q0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned __int64 v16; // x22
  unsigned __int64 v17; // x24
  unsigned int v18; // w26
  int v19; // w0
  int v20; // w24
  int v21; // w0
  int v22; // w28
  int v23; // w0
  int v24; // w27
  const char *v25; // x0
  int v26; // w23
  const char *v27; // x26
  const char *v28; // x0
  __int64 v29; // x8
  const char *v30; // x8
  int v31; // w0
  unsigned __int64 v32; // x22
  int v33; // w0
  __int64 v34; // x8
  unsigned __int64 v35; // x22
  unsigned __int64 v36; // x22
  __int64 v37; // x22
  __int64 v39; // [xsp+58h] [xbp-18h]
  __int64 v40; // [xsp+60h] [xbp-10h]

  v5 = *(_QWORD *)(a1 + 52824);
  if ( !hdd_cm_is_vdev_associated((_DWORD *)v5) )
  {
    scnprintf(a2, a3, "\nSTA is not connected\n");
    return v23 & (unsigned int)~(v23 >> 31);
  }
  *(double *)&v8 = scnprintf(a2, a3, "\nCONNECTION DETAILS\n");
  if ( (int)v7 < 1 )
    return 0;
  v16 = v7;
  v17 = a3 - v7;
  if ( (__int64)a3 <= v7 )
    goto LABEL_24;
  v18 = v7;
  if ( hdd_cm_is_vdev_roaming(*(_QWORD *)(a1 + 52824)) )
  {
    scnprintf(a2 + v16, v17, "Roaming is in progress");
    if ( v19 < 1 )
      return v16;
    v16 = v19 + v18;
  }
  v20 = cfg80211_calculate_bitrate(v5 + 696);
  v21 = cfg80211_calculate_bitrate(v5 + 710);
  if ( a3 <= v16 )
    goto LABEL_24;
  v22 = v21;
  if ( v5 == -300 )
  {
    v39 = 0;
    v40 = 0;
  }
  else
  {
    LODWORD(v40) = *(unsigned __int8 *)(v5 + 302);
    HIDWORD(v40) = *(unsigned __int8 *)(v5 + 300);
    LODWORD(v39) = *(unsigned __int8 *)(v5 + 305);
    HIDWORD(v39) = *(unsigned __int8 *)(v5 + 301);
  }
  v24 = *(_DWORD *)(v5 + 692);
  v25 = hdd_ch_width_str(*(_DWORD *)(v5 + 932));
  v26 = *(char *)(v5 + 832);
  v27 = v25;
  v28 = (const char *)hdd_auth_type_str(*(unsigned int *)(v5 + 880));
  v29 = *(unsigned int *)(v5 + 680);
  if ( (unsigned int)v29 > 0xD )
    v30 = "UNKNOWN";
  else
    v30 = off_A2E7C0[v29];
  *(double *)&v8 = scnprintf(
                     a2 + v16,
                     a3 - v16,
                     "ssid = %s\n"
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
                     (const char *)(v5 + 841),
                     HIDWORD(v40),
                     HIDWORD(v39),
                     v40,
                     v39,
                     (const char *)(v5 + 908),
                     (const char *)(v5 + 884),
                     v24,
                     v27,
                     v26,
                     v20,
                     v22,
                     v28,
                     v30);
  if ( v31 >= 1 )
  {
    v32 = v16 + (unsigned int)v31;
    if ( a3 > v32 )
    {
      if ( (*(_BYTE *)(v5 + 763) & 3) != 0 )
      {
        *(double *)&v8 = scnprintf(a2 + v32, a3 - v32, "nss = %u\n", *(unsigned __int8 *)(v5 + 701));
        v34 = v33 & (unsigned int)~(v33 >> 31);
      }
      else
      {
        v34 = 0;
      }
      v35 = v34 + v32;
      if ( a3 > v35 )
      {
        v36 = wlan_hdd_add_ht_cap_info(v5 + 296, a2 + v35, a3 - v35, v8) + v35;
        if ( a3 > v36 )
        {
          v37 = wlan_hdd_add_vht_cap_info(v5 + 296, a2 + v36, a3 - v36) + v36;
          return v37 + wlan_hdd_add_he_cap_info(v5 + 296, a2 + v37, a3 - v37);
        }
      }
    }
LABEL_24:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: No sufficient buf_avail_len",
      *(double *)&v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wlan_hdd_connect_info");
    return a3;
  }
  return v16;
}
