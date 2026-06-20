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
  __int64 assoc_link_vdev; // x0
  int v12; // w8
  __int64 v13; // x19
  char is_mlo_vdev; // w8
  __int64 *v15; // x8
  __int64 v16; // x21
  unsigned int v17; // w8
  __int64 v18; // x12
  unsigned int v19; // w9
  unsigned int *v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x2
  __int64 result; // x0
  const char *v31; // x2
  int v32; // [xsp+0h] [xbp-40h] BYREF
  __int64 v33; // [xsp+4h] [xbp-3Ch]
  int v34; // [xsp+Ch] [xbp-34h]
  unsigned int *v35; // [xsp+10h] [xbp-30h]
  __int64 v36; // [xsp+18h] [xbp-28h]
  int v37; // [xsp+20h] [xbp-20h]
  __int64 v38; // [xsp+24h] [xbp-1Ch]
  __int64 v39; // [xsp+2Ch] [xbp-14h]
  int v40; // [xsp+34h] [xbp-Ch]
  __int64 v41; // [xsp+38h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    assoc_link_vdev = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                        a1,
                        a2[2],
                        17);
    if ( assoc_link_vdev )
    {
      v12 = *(_DWORD *)(assoc_link_vdev + 16);
      v13 = assoc_link_vdev;
      if ( (v12 == 15 || !v12)
        && (is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(assoc_link_vdev, a3, a4, a5, a6, a7, a8, a9, a10),
            assoc_link_vdev = v13,
            (is_mlo_vdev & 1) != 0)
        && (assoc_link_vdev = ucfg_mlo_get_assoc_link_vdev(v13)) == 0 )
      {
        v31 = "%s: assoc vdev is null";
      }
      else
      {
        v15 = *(__int64 **)(assoc_link_vdev + 680);
        if ( v15 )
        {
          v16 = *v15;
          if ( *v15 )
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
              *(unsigned int *)(*(_QWORD *)(v16 + 32) + 224LL));
            v18 = *a2;
            v17 = a2[1];
            v19 = a2[4];
            v34 = 0;
            v35 = a2 + 5;
            v37 = 1;
            v36 = v18;
            v38 = 0;
            v32 = 1000 * v17;
            v33 = 100 * v19;
            v39 = 0;
            v40 = 0;
            v21 = cfg80211_rx_mgmt_ext(v16, &v32);
LABEL_17:
            result = wlan_objmgr_vdev_release_ref(v13, 0x11u, v20, v21, v22, v23, v24, v25, v26, v27, v28);
            goto LABEL_18;
          }
          v31 = "%s: wdev is null";
        }
        else
        {
          v31 = "%s: osif_priv is null";
        }
      }
      qdf_trace_msg(0x48u, 2u, v31, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_cfg80211_tdls_rx_callback");
      goto LABEL_17;
    }
    v29 = "%s: vdev is null";
  }
  else
  {
    v29 = "%s: psoc is null";
  }
  result = qdf_trace_msg(0x48u, 2u, v29, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_cfg80211_tdls_rx_callback");
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
