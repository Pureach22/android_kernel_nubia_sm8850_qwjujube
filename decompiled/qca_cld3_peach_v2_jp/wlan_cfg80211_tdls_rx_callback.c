__int64 __fastcall wlan_cfg80211_tdls_rx_callback(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x0
  __int64 *v12; // x8
  __int64 v13; // x19
  __int64 v14; // x21
  unsigned int v15; // w8
  __int64 v16; // x12
  unsigned int v17; // w9
  unsigned int *v18; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  const char *v27; // x2
  __int64 result; // x0
  const char *v29; // x2
  int v30; // [xsp+0h] [xbp-40h] BYREF
  __int64 v31; // [xsp+4h] [xbp-3Ch]
  int v32; // [xsp+Ch] [xbp-34h]
  unsigned int *v33; // [xsp+10h] [xbp-30h]
  __int64 v34; // [xsp+18h] [xbp-28h]
  int v35; // [xsp+20h] [xbp-20h]
  __int64 v36; // [xsp+24h] [xbp-1Ch]
  __int64 v37; // [xsp+2Ch] [xbp-14h]
  int v38; // [xsp+34h] [xbp-Ch]
  __int64 v39; // [xsp+38h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v11 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2[2], 17);
    if ( v11 )
    {
      v12 = *(__int64 **)(v11 + 608);
      v13 = v11;
      if ( v12 )
      {
        v14 = *v12;
        if ( *v12 )
        {
          qdf_trace_msg(
            0x48u,
            4u,
            "%s: Indicate frame over nl80211, vdev id:%d, idx:%d",
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            "wlan_cfg80211_tdls_rx_callback",
            a2[2],
            *(unsigned int *)(*(_QWORD *)(v14 + 32) + 224LL));
          v16 = *a2;
          v15 = a2[1];
          v17 = a2[4];
          v32 = 0;
          v33 = a2 + 5;
          v35 = 1;
          v34 = v16;
          v36 = 0;
          v30 = 1000 * v15;
          v31 = 100 * v17;
          v37 = 0;
          v38 = 0;
          v19 = cfg80211_rx_mgmt_ext(v14, &v30);
LABEL_12:
          result = wlan_objmgr_vdev_release_ref(v13, 0x11u, v18, v19, v20, v21, v22, v23, v24, v25, v26);
          goto LABEL_13;
        }
        v29 = "%s: wdev is null";
      }
      else
      {
        v29 = "%s: osif_priv is null";
      }
      qdf_trace_msg(0x48u, 2u, v29, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_cfg80211_tdls_rx_callback");
      goto LABEL_12;
    }
    v27 = "%s: vdev is null";
  }
  else
  {
    v27 = "%s: psoc is null";
  }
  result = qdf_trace_msg(0x48u, 2u, v27, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_cfg80211_tdls_rx_callback");
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
