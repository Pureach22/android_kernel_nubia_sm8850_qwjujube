__int64 __fastcall wlan_hdd_cfg80211_send_set_ltf_keyseed_mlo_vdev(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        unsigned __int8 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 result; // x0
  _DWORD *v17; // x28
  __int16 v18; // w9
  unsigned __int64 i; // x25
  const char *v20; // x2
  __int64 v21; // x26
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 peer; // x27
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int16 v47; // w9
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int16 v56; // w9
  __int64 v57; // [xsp+0h] [xbp-40h]
  unsigned __int16 v58; // [xsp+14h] [xbp-2Ch] BYREF
  int v59; // [xsp+18h] [xbp-28h]
  __int16 v60; // [xsp+1Ch] [xbp-24h]
  int v61; // [xsp+20h] [xbp-20h] BYREF
  __int16 v62; // [xsp+24h] [xbp-1Ch]
  _QWORD v63[3]; // [xsp+28h] [xbp-18h] BYREF

  v63[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58 = 0;
  v63[0] = 0;
  v63[1] = 0;
  result = wlan_vdev_mlme_is_mlo_vdev(a2, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( (result & 1) != 0 )
  {
    v17 = a4 + 1;
    v18 = *(_WORD *)(a4 + 5);
    v61 = *(_DWORD *)(a4 + 1);
    v62 = v18;
    v59 = v61;
    v60 = v18;
    result = mlo_sta_get_vdev_list(a2, &v58, v63);
    if ( v58 )
    {
      for ( i = 0; i < v58; ++i )
      {
        if ( i == 2 )
        {
          __break(0x5512u);
          __break(1u);
        }
        v21 = v63[i];
        if ( !hdd_get_link_info_by_vdev((__int64)a1, *(unsigned __int8 *)(v21 + 168)) )
          goto LABEL_6;
        if ( *(_DWORD *)(a3 + 40) == 1 )
        {
          if ( (wlan_vdev_mlme_is_mlo_vdev(v21, v22, v23, v24, v25, v26, v27, v28, v29) & 1) != 0 )
          {
            peer = (__int64)wlan_hdd_ml_sap_get_peer((_QWORD *)v21, &v61);
            if ( peer )
            {
LABEL_17:
              qdf_mem_copy(&v61, (const void *)(peer + 48), 6u);
              wlan_objmgr_peer_release_ref(peer, 6u, v39, v40, v41, v42, v43, v44, v45, v46);
LABEL_18:
              v47 = v62;
              *v17 = v61;
              *(_WORD *)(a4 + 5) = v47;
              *a4 = *(_BYTE *)(v21 + 168);
              if ( (unsigned int)wlan_crypto_set_ltf_keyseed(*a1, v30, v31, v32, v33, v34, v35, v36, v37) )
              {
                LODWORD(v57) = a4[6];
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Set LTF Keyseed failed vdev:%d for peer: %02x:%02x:%02x:**:**:%02x",
                  v48,
                  v49,
                  v50,
                  v51,
                  v52,
                  v53,
                  v54,
                  v55,
                  "wlan_hdd_cfg80211_send_set_ltf_keyseed_mlo_vdev",
                  *a4,
                  a4[1],
                  a4[2],
                  a4[3],
                  v57);
              }
              goto LABEL_6;
            }
          }
        }
        else
        {
          peer = wlan_objmgr_vdev_try_get_bsspeer(v21, 6u);
          if ( peer )
            goto LABEL_17;
        }
        if ( (*(_BYTE *)(v21 + 60) & 2) == 0 || *(_DWORD *)(a3 + 40) )
        {
          v20 = "%s: Peer is null";
        }
        else
        {
          if ( !(unsigned int)wlan_hdd_mlo_copy_partner_addr_from_mlie(v21, (__int64)&v61) )
            goto LABEL_18;
          v20 = "%s: Failed to get peer address from ML IEs";
        }
        qdf_trace_msg(
          0x33u,
          2u,
          v20,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "wlan_hdd_cfg80211_send_set_ltf_keyseed_mlo_vdev");
LABEL_6:
        result = mlo_release_vdev_ref(v21);
      }
    }
    v56 = v60;
    *v17 = v59;
    *(_WORD *)(a4 + 5) = v56;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
