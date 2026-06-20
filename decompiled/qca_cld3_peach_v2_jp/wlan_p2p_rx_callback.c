__int64 __fastcall wlan_p2p_rx_callback(
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
  __int64 v12; // x0
  __int64 v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 *v22; // x8
  __int64 p2p_wdev; // x21
  __int64 v24; // x9
  unsigned int v25; // w8
  size_t v26; // x2
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w8
  __int64 v36; // x12
  unsigned int v37; // w9
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  char v46; // w0
  const char *v47; // x4
  unsigned int *v48; // x8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  const char *v57; // x2
  __int64 result; // x0
  const char *v59; // x2
  int v60; // [xsp+30h] [xbp-50h] BYREF
  __int64 v61; // [xsp+34h] [xbp-4Ch]
  int v62; // [xsp+3Ch] [xbp-44h]
  unsigned int *v63; // [xsp+40h] [xbp-40h]
  __int64 v64; // [xsp+48h] [xbp-38h]
  int v65; // [xsp+50h] [xbp-30h]
  __int64 v66; // [xsp+54h] [xbp-2Ch]
  __int64 v67; // [xsp+5Ch] [xbp-24h]
  int v68; // [xsp+64h] [xbp-1Ch]
  int v69; // [xsp+68h] [xbp-18h] BYREF
  __int16 v70; // [xsp+6Ch] [xbp-14h]
  int v71; // [xsp+70h] [xbp-10h] BYREF
  __int16 v72; // [xsp+74h] [xbp-Ch]
  __int64 v73; // [xsp+78h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v72 = 0;
  v71 = 0;
  v70 = 0;
  v69 = 0;
  if ( a1 )
  {
    v12 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2[2], 15);
    if ( v12 )
    {
      v13 = v12;
      if ( (ucfg_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(a1) & 1) != 0
        && (wlan_mlme_get_p2p_device_mac_addr(v13, (__int64)&v71, v14, v15, v16, v17, v18, v19, v20, v21),
            a2 != (unsigned int *)-24LL)
        && (*((unsigned __int8 *)a2 + 24) == 255
         && *((unsigned __int8 *)a2 + 25) == 255
         && *((unsigned __int8 *)a2 + 26) == 255
         && *((unsigned __int8 *)a2 + 27) == 255
         && *((unsigned __int8 *)a2 + 28) == 255
         && *((unsigned __int8 *)a2 + 29) == 255
         || !(unsigned int)qdf_mem_cmp(a2 + 6, &v71, 6u)) )
      {
        p2p_wdev = osif_vdev_mgr_get_p2p_wdev();
        if ( p2p_wdev )
          goto LABEL_14;
      }
      else
      {
        v22 = *(__int64 **)(v13 + 608);
        if ( !v22 )
        {
          v59 = "%s: osif_priv is null";
LABEL_27:
          qdf_trace_msg(0x48u, 2u, v59, v14, v15, v16, v17, v18, v19, v20, v21, "wlan_p2p_rx_callback");
LABEL_28:
          result = wlan_objmgr_vdev_release_ref(v13, 0xFu, v48, v49, v50, v51, v52, v53, v54, v55, v56);
          goto LABEL_29;
        }
        p2p_wdev = *v22;
        if ( *v22 )
        {
LABEL_14:
          v24 = (unsigned __int8)ieee80211_hdrlen(*((unsigned __int8 *)a2 + 20));
          v25 = *a2 - v24;
          if ( v25 >= 6 )
            v26 = 6;
          else
            v26 = v25;
          qdf_mem_copy(&v69, (char *)a2 + v24 + 20, v26);
          qdf_trace_msg(
            0x48u,
            8u,
            "%s: Indicate frame over nl80211, idx:%d and interface %s FC: 0x%x match: %02x%02x%02x%02x%02x%02x",
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            "wlan_p2p_rx_callback",
            *(unsigned int *)(*(_QWORD *)(p2p_wdev + 32) + 224LL),
            *(_QWORD *)(p2p_wdev + 32) + 296LL,
            *((unsigned __int8 *)a2 + 20),
            (unsigned __int8)v69,
            BYTE1(v69),
            BYTE2(v69),
            HIBYTE(v69),
            (unsigned __int8)v70,
            HIBYTE(v70));
          v36 = *a2;
          v35 = a2[1];
          v37 = a2[4];
          v62 = 0;
          v63 = a2 + 5;
          v64 = v36;
          v65 = 1;
          v66 = 0;
          v67 = 0;
          v60 = 1000 * v35;
          v61 = 100 * v37;
          v68 = 0;
          v38 = cfg80211_rx_mgmt_ext(p2p_wdev, &v60);
          if ( (v46 & 1) != 0 )
            v47 = "Success";
          else
            v47 = "Fail";
          qdf_trace_msg(
            0x48u,
            8u,
            "%s: indicated frame to userspace: %s",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "wlan_p2p_rx_callback",
            v47);
          goto LABEL_28;
        }
      }
      v59 = "%s: wdev is null";
      goto LABEL_27;
    }
    v57 = "%s: vdev is null";
  }
  else
  {
    v57 = "%s: psoc is null";
  }
  result = qdf_trace_msg(0x48u, 2u, v57, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_p2p_rx_callback");
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
