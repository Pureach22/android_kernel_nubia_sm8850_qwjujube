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
  __int64 assoc_link_vdev; // x0
  char is_mlo_vdev; // w8
  __int64 *v24; // x8
  __int64 p2p_wdev; // x21
  __int64 v26; // x9
  unsigned int v27; // w8
  size_t v28; // x2
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w8
  __int64 v38; // x12
  unsigned int v39; // w9
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  char v48; // w0
  const char *v49; // x4
  unsigned int *v50; // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  const char *v59; // x2
  __int64 result; // x0
  const char *v61; // x2
  int v62; // [xsp+30h] [xbp-50h] BYREF
  __int64 v63; // [xsp+34h] [xbp-4Ch]
  int v64; // [xsp+3Ch] [xbp-44h]
  unsigned int *v65; // [xsp+40h] [xbp-40h]
  __int64 v66; // [xsp+48h] [xbp-38h]
  int v67; // [xsp+50h] [xbp-30h]
  __int64 v68; // [xsp+54h] [xbp-2Ch]
  __int64 v69; // [xsp+5Ch] [xbp-24h]
  int v70; // [xsp+64h] [xbp-1Ch]
  int v71; // [xsp+68h] [xbp-18h] BYREF
  __int16 v72; // [xsp+6Ch] [xbp-14h]
  int v73; // [xsp+70h] [xbp-10h] BYREF
  __int16 v74; // [xsp+74h] [xbp-Ch]
  __int64 v75; // [xsp+78h] [xbp-8h]

  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v74 = 0;
  v73 = 0;
  v72 = 0;
  v71 = 0;
  if ( a1 )
  {
    v12 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2[2], 15);
    if ( v12 )
    {
      v13 = v12;
      if ( (ucfg_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(a1) & 1) != 0
        && (wlan_mlme_get_p2p_device_mac_addr(v13, (__int64)&v73, v14, v15, v16, v17, v18, v19, v20, v21),
            a2 != (unsigned int *)-24LL)
        && (*((unsigned __int8 *)a2 + 24) == 255
         && *((unsigned __int8 *)a2 + 25) == 255
         && *((unsigned __int8 *)a2 + 26) == 255
         && *((unsigned __int8 *)a2 + 27) == 255
         && *((unsigned __int8 *)a2 + 28) == 255
         && *((unsigned __int8 *)a2 + 29) == 255
         || !(unsigned int)qdf_mem_cmp(a2 + 6, &v73, 6u)) )
      {
        p2p_wdev = osif_vdev_mgr_get_p2p_wdev();
        if ( p2p_wdev )
          goto LABEL_17;
      }
      else
      {
        assoc_link_vdev = v13;
        if ( !*(_DWORD *)(v13 + 16) )
        {
          is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v13, v14, v15, v16, v17, v18, v19, v20, v21);
          assoc_link_vdev = v13;
          if ( (is_mlo_vdev & 1) != 0 )
          {
            assoc_link_vdev = ucfg_mlo_get_assoc_link_vdev(v13);
            if ( !assoc_link_vdev )
            {
              v61 = "%s: Assoc vdev is NULL";
              goto LABEL_31;
            }
          }
        }
        v24 = *(__int64 **)(assoc_link_vdev + 680);
        if ( !v24 )
        {
          v61 = "%s: osif_priv is null";
LABEL_31:
          qdf_trace_msg(0x48u, 2u, v61, v14, v15, v16, v17, v18, v19, v20, v21, "wlan_p2p_rx_callback");
LABEL_32:
          result = wlan_objmgr_vdev_release_ref(v13, 0xFu, v50, v51, v52, v53, v54, v55, v56, v57, v58);
          goto LABEL_33;
        }
        p2p_wdev = *v24;
        if ( *v24 )
        {
LABEL_17:
          v26 = (unsigned __int8)ieee80211_hdrlen(*((unsigned __int8 *)a2 + 20));
          v27 = *a2 - v26;
          if ( v27 >= 6 )
            v28 = 6;
          else
            v28 = v27;
          qdf_mem_copy(&v71, (char *)a2 + v26 + 20, v28);
          qdf_trace_msg(
            0x48u,
            8u,
            "%s: Indicate frame over nl80211, idx:%d and interface %s FC: 0x%x match: %02x%02x%02x%02x%02x%02x",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "wlan_p2p_rx_callback",
            *(unsigned int *)(*(_QWORD *)(p2p_wdev + 32) + 224LL),
            *(_QWORD *)(p2p_wdev + 32) + 296LL,
            *((unsigned __int8 *)a2 + 20),
            (unsigned __int8)v71,
            BYTE1(v71),
            BYTE2(v71),
            HIBYTE(v71),
            (unsigned __int8)v72,
            HIBYTE(v72));
          v38 = *a2;
          v37 = a2[1];
          v39 = a2[4];
          v64 = 0;
          v65 = a2 + 5;
          v66 = v38;
          v67 = 1;
          v68 = 0;
          v69 = 0;
          v62 = 1000 * v37;
          v63 = 100 * v39;
          v70 = 0;
          v40 = cfg80211_rx_mgmt_ext(p2p_wdev, &v62);
          if ( (v48 & 1) != 0 )
            v49 = "Success";
          else
            v49 = "Fail";
          qdf_trace_msg(
            0x48u,
            8u,
            "%s: indicated frame to userspace: %s",
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            "wlan_p2p_rx_callback",
            v49);
          goto LABEL_32;
        }
      }
      v61 = "%s: wdev is null";
      goto LABEL_31;
    }
    v59 = "%s: vdev is null";
  }
  else
  {
    v59 = "%s: psoc is null";
  }
  result = qdf_trace_msg(0x48u, 2u, v59, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_p2p_rx_callback");
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
