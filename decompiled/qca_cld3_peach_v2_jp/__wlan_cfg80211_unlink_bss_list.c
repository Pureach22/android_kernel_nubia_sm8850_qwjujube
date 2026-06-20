__int64 __fastcall _wlan_cfg80211_unlink_bss_list(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        const char *a4,
        unsigned __int8 a5)
{
  __int64 result; // x0
  __int64 v10; // x23
  int v11; // w8
  int v12; // w6
  int v13; // w7
  int v14; // w9
  __int64 bss; // x0
  __int64 v16; // x0
  __int64 v17; // x23
  int v18; // w6
  int v19; // w7
  int v20; // w8
  int v21; // w9
  int v22; // w6
  int v23; // w7
  int v24; // w8
  int v25; // w9
  _BYTE v26[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+28h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = 0;
  if ( a3 )
  {
    if ( (wlan_get_connected_vdev_by_bssid(a2, a3, v26) & 1) != 0 )
    {
      qdf_trace_msg(
        72,
        8,
        "%s: BSS %02x:%02x:%02x:**:**:%02x connected on vdev %d dont unlink",
        "__wlan_cfg80211_unlink_bss_list",
        *a3,
        a3[1],
        a3[2],
        a3[5],
        v26[0]);
      result = 16;
      goto LABEL_18;
    }
    bss = _cfg80211_get_bss(a1, 0, a3, a4, a5, 0, 2, 1);
    v12 = *a3;
    v13 = a3[1];
    v10 = bss;
    v11 = a3[2];
    v14 = a3[5];
    if ( !bss )
      goto LABEL_7;
  }
  else
  {
    v10 = _cfg80211_get_bss(a1, 0, 0, a4, a5, 0, 2, 1);
    v11 = 0;
    v12 = 0;
    v13 = 0;
    v14 = 0;
    if ( !v10 )
    {
LABEL_7:
      qdf_trace_msg(
        72,
        4,
        "%s: BSS %02x:%02x:%02x:**:**:%02x not found",
        "__wlan_cfg80211_unlink_bss_list",
        v12,
        v13,
        v11,
        v14);
      goto LABEL_8;
    }
  }
  qdf_trace_msg(
    72,
    8,
    "%s: unlink entry for ssid:%.*s and BSSID %02x:%02x:%02x:**:**:%02x",
    "__wlan_cfg80211_unlink_bss_list",
    a5,
    a4,
    v12,
    v13,
    v11,
    v14);
  cfg80211_unlink_bss(a1, v10);
  cfg80211_put_bss(a1, v10);
LABEL_8:
  v16 = _cfg80211_get_bss(a1, 0, a3, 0, 0, 0, 2, 1);
  if ( v16 )
  {
    v17 = v16;
    if ( a3 )
    {
      v18 = *a3;
      v19 = a3[1];
      v20 = a3[2];
      v21 = a3[5];
    }
    else
    {
      v20 = 0;
      v18 = 0;
      v19 = 0;
      v21 = 0;
    }
    qdf_trace_msg(
      72,
      8,
      "%s: unlink entry for Hidden ssid:%.*s and BSSID %02x:%02x:%02x:**:**:%02x",
      "__wlan_cfg80211_unlink_bss_list",
      a5,
      a4,
      v18,
      v19,
      v20,
      v21);
    cfg80211_unlink_bss(a1, v17);
    cfg80211_put_bss(a1, v17);
  }
  else
  {
    if ( a3 )
    {
      v22 = *a3;
      v23 = a3[1];
      v24 = a3[2];
      v25 = a3[5];
    }
    else
    {
      v24 = 0;
      v22 = 0;
      v23 = 0;
      v25 = 0;
    }
    qdf_trace_msg(
      72,
      8,
      "%s: Hidden bss not found for ssid:%.*s BSSID: %02x:%02x:%02x:**:**:%02x sid_len %d",
      "__wlan_cfg80211_unlink_bss_list",
      a5,
      a4,
      v22,
      v23,
      v24,
      v25,
      a5);
  }
  result = 0;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
