__int64 __fastcall wlan_hdd_cfg80211_del_key(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5,
        const void *a6)
{
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 *v26; // x20
  unsigned int v27; // w22
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  bool v36; // zf
  _QWORD *peer_by_mac; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  int v46; // w8
  __int64 v47; // x21
  unsigned int v48; // w22
  const char *v49; // x2
  __int64 v50; // x23
  unsigned int ref; // w0
  unsigned int v52; // w22
  double v53; // d0
  char v54; // w0
  char v55; // w19
  unsigned int *v56; // x8
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // x0
  __int64 v81; // [xsp+0h] [xbp-20h] BYREF
  int v82; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int16 v83; // [xsp+Ch] [xbp-14h]
  __int64 v84; // [xsp+18h] [xbp-8h]

  v84 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v81 = 0;
  result = _osif_vdev_sync_op_start(a2, &v81, "wlan_hdd_cfg80211_del_key");
  if ( (_DWORD)result )
    goto LABEL_27;
  if ( a1 )
  {
    v83 = 0;
    v82 = 0;
    qdf_trace_msg(0x33u, 8u, "%s: enter", v10, v11, v12, v13, v14, v15, v16, v17, "__wlan_hdd_cfg80211_del_key");
    if ( a6 )
    {
      v26 = (__int64 *)(a1 + 1536);
      v27 = _wlan_hdd_validate_context(v26, "__wlan_hdd_cfg80211_del_key");
      if ( v27 )
      {
LABEL_26:
        _osif_vdev_sync_op_stop(v81, "wlan_hdd_cfg80211_del_key");
        result = v27;
LABEL_27:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      qdf_mem_copy(&v82, a6, 6u);
      if ( !(v82 | v83) || (v82 == -1 ? (v36 = (__int16)v83 == -1) : (v36 = 0), v36) )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid mac address",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "__wlan_hdd_cfg80211_del_key");
        v27 = -22;
      }
      else
      {
        peer_by_mac = wlan_objmgr_get_peer_by_mac(*v26, &v82, 6u);
        if ( peer_by_mac )
        {
          v46 = *((_DWORD *)peer_by_mac + 17);
          if ( v46 == 14 )
          {
            v50 = peer_by_mac[11];
            v47 = (__int64)peer_by_mac;
            ref = wlan_objmgr_vdev_try_get_ref(v50, 6u, v38, v39, v40, v41, v42, v43, v44, v45);
            if ( !ref )
            {
              v52 = *(unsigned __int8 *)(v50 + 104);
              v53 = wlan_hdd_is_key_associated_with_peer(v50, a4, &v82);
              v55 = v54;
              wlan_objmgr_vdev_release_ref(v50, 6u, v56, v53, v57, v58, v59, v60, v61, v62, v63);
              wlan_objmgr_peer_release_ref(v47, 6u, v64, v65, v66, v67, v68, v69, v70, v71);
              if ( (v55 & 1) != 0 )
              {
                v48 = ucfg_nan_send_delete_pasn_peer(*v26, v52, &v82);
                if ( v48 )
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: NAN pasn peer delete failed",
                    v72,
                    v73,
                    v74,
                    v75,
                    v76,
                    v77,
                    v78,
                    v79,
                    "__wlan_hdd_cfg80211_del_key");
              }
              else
              {
                v48 = 16;
              }
              goto LABEL_24;
            }
            v48 = ref;
            v49 = "%s: get vdev ref fails";
          }
          else
          {
            if ( v46 != 12 )
            {
              v48 = 0;
              goto LABEL_23;
            }
            v47 = (__int64)peer_by_mac;
            v48 = wifi_pos_send_pasn_peer_deauth(*v26, &v82);
            if ( !v48 )
            {
LABEL_21:
              peer_by_mac = (_QWORD *)v47;
LABEL_23:
              wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 6u, v38, v39, v40, v41, v42, v43, v44, v45);
LABEL_24:
              v27 = qdf_status_to_os_return(v48);
              goto LABEL_25;
            }
            v49 = "%s: send_pasn_peer_deauth failed";
          }
          qdf_trace_msg(0x33u, 2u, v49, v38, v39, v40, v41, v42, v43, v44, v45, "__wlan_hdd_cfg80211_del_key");
          goto LABEL_21;
        }
        v27 = 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Peer mac address is NULL",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "__wlan_hdd_cfg80211_del_key");
      v27 = 0;
    }
LABEL_25:
    qdf_trace_msg(0x33u, 8u, "%s: exit", v38, v39, v40, v41, v42, v43, v44, v45, "__wlan_hdd_cfg80211_del_key");
    goto LABEL_26;
  }
  __break(0x800u);
  v80 = MEMORY[0xFFFFFFFFFA83684C]();
  return wlan_hdd_cfg80211_set_default_key(v80);
}
