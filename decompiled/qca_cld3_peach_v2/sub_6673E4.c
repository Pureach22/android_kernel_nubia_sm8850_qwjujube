// positive sp value has been detected, the output may be wrong!
__int64 __fastcall sub_6673E4(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        __int64 a12,
        __int64 a13,
        int a14)
{
  __int64 v14; // x19
  _QWORD *v15; // x20
  __int64 v16; // x21
  __int64 v17; // x22
  __int64 v18; // x23
  unsigned __int16 *v19; // x24
  int v20; // w25
  __int64 v21; // x27
  unsigned __int8 *v22; // x28
  unsigned int v24; // w19
  unsigned int v25; // w9
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x26
  __int64 v35; // x2
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  const char *v44; // x4
  __int64 v45; // x26
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x5
  __int64 v55; // x6
  __int64 v56; // x7
  int v57; // w8
  unsigned __int8 *v58; // x26
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x5
  __int64 v68; // x6
  __int64 v69; // x7
  int v70; // w8
  unsigned int v71; // w0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned __int8 v80; // w8
  __int64 v81; // x8
  unsigned int v82; // w20
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  int v91; // w0
  __int64 v92; // x21
  __int64 v93; // x21
  __int64 v94; // [xsp-250h] [xbp-250h]
  __int64 v95; // [xsp-240h] [xbp-240h]
  __int64 v96; // [xsp-238h] [xbp-238h] BYREF
  __int64 v97; // [xsp-230h] [xbp-230h]
  __int64 v98; // [xsp-228h] [xbp-228h]
  __int64 v99; // [xsp-218h] [xbp-218h]
  __int64 v100; // [xsp-210h] [xbp-210h]
  __int64 v101; // [xsp-208h] [xbp-208h]
  __int64 v102; // [xsp-1F0h] [xbp-1F0h]
  _WORD *v103; // [xsp-1E8h] [xbp-1E8h]

  if ( (a14 & 0x20000000) == 0 )
    return wifi_pos_register_get_phy_mode_cb(a1, a2);
LABEL_18:
  if ( v22 )
  {
    v54 = *v22;
    v55 = *(unsigned __int8 *)(v14 + v18 + 5);
    v56 = *(unsigned __int8 *)(v14 + v18 + 6);
    v57 = *(unsigned __int8 *)(v14 + v18 + 9);
  }
  else
  {
    v56 = 0;
    v54 = 0;
    v55 = 0;
    v57 = 0;
  }
  LODWORD(v94) = v57;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Peer mac[%d]: %02x:%02x:%02x:**:**:%02x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    v21,
    (unsigned int)v16,
    v54,
    v55,
    v56,
    v94);
  while ( 1 )
  {
    if ( v97 )
    {
      v58 = (unsigned __int8 *)(v14 + v18);
      nla_memcpy(v14 + v18 + 10, v97, 6);
      if ( v14 + v18 == -10 )
      {
        v69 = 0;
        v67 = 0;
        v68 = 0;
        v70 = 0;
      }
      else
      {
        v67 = *(unsigned __int8 *)(v14 + v18 + 10);
        v68 = v58[11];
        v69 = v58[12];
        v70 = v58[15];
      }
      LODWORD(v94) = v70;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Src addr[%d]: %02x:%02x:%02x:**:**:%02x",
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v21,
        (unsigned int)v16,
        v67,
        v68,
        v69,
        v94);
    }
    if ( v100 )
    {
      v71 = osif_nl_to_crypto_akm_type(*(_DWORD *)(v100 + 4));
      *(_DWORD *)(v14 + v18 + 280) = v71;
      qdf_trace_msg(0x33u, 8u, "%s: akm:0x%x ", v72, v73, v74, v75, v76, v77, v78, v79, v21, v71);
    }
    if ( v101 )
    {
      *(_DWORD *)(v14 + v18 + 284) = *(_DWORD *)(v101 + 4);
      qdf_trace_msg(0x33u, 8u, "%s: cipher:0x%x ", v46, v47, v48, v49, v50, v51, v52, v53, v21);
    }
    v80 = *(_BYTE *)(v14 + 1) + 1;
    *(_BYTE *)(v14 + 1) = v80;
    if ( v80 >= 0x10u )
    {
      v93 = jiffies;
      if ( wlan_hdd_cfg80211_send_pasn_auth_status___last_ticks_11 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid num_peers:%d",
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          "wlan_hdd_cfg80211_send_pasn_auth_status",
          v80);
        wlan_hdd_cfg80211_send_pasn_auth_status___last_ticks_11 = v93;
      }
      goto LABEL_41;
    }
    ++v16;
    v18 += 288;
    v81 = (*v19 + 3) & 0x1FFFC;
    v20 -= v81;
    v19 = (unsigned __int16 *)((char *)v19 + v81);
    if ( v20 <= 3 )
      break;
    v25 = *v19;
    if ( v25 < 4 || v20 < v25 )
      break;
    if ( ((__int16)v19[1] & 0x80000000) == 0 )
    {
      do_trace_netlink_extack("NLA_F_NESTED is missing");
LABEL_37:
      v92 = jiffies;
      if ( wlan_hdd_cfg80211_send_pasn_auth_status___last_ticks_4 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: nla_parse failed",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "wlan_hdd_cfg80211_send_pasn_auth_status");
        wlan_hdd_cfg80211_send_pasn_auth_status___last_ticks_4 = v92;
      }
LABEL_41:
      _qdf_mem_free(v14);
      v91 = -22;
      goto LABEL_3;
    }
    if ( (unsigned int)_nla_parse(&v96, 10, v19 + 2, (unsigned __int16)(v25 - 4), v17, 31, 0) )
      goto LABEL_37;
    if ( !v99 )
    {
      *(_DWORD *)(v14 + v18 + 288) = 5;
      if ( v102 )
      {
        if ( v103 )
        {
          v34 = v14 + v18;
          *(_WORD *)(v34 + 276) = *(_WORD *)(v102 + 4);
          v35 = (unsigned __int16)(*v103 - 4);
          *(_DWORD *)(v34 + 16) = v35;
          nla_memcpy(v14 + v18 + 20, v103, v35);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: comeback_after:%d cookie:%s cookie_len:%d",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "wlan_hdd_fill_comeback_params",
            *(unsigned __int16 *)(v34 + 276),
            v34 + 20,
            *(unsigned int *)(v34 + 16));
          goto LABEL_15;
        }
        v44 = "peer_cookie";
      }
      else
      {
        v44 = "comeback_after";
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: %s is not present",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "wlan_hdd_fill_comeback_params",
        v44);
      *(_DWORD *)(v14 + v18 + 288) = 1;
    }
LABEL_15:
    if ( v16 == 16 )
    {
      __break(0x5512u);
      __break(0x800u);
      JUMPOUT(0x66C488);
    }
    v45 = v14 + v18;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: PASN auth status:%d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v21,
      *(unsigned int *)(v14 + v18 + 288));
    if ( v98 )
    {
      v22 = (unsigned __int8 *)(v45 + 4);
      nla_memcpy(v45 + 4, v98, 6);
      goto LABEL_18;
    }
  }
  v82 = ((__int64 (__fastcall *)(_QWORD, __int64))wifi_pos_send_pasn_auth_status)(*v15, v14);
  if ( v82 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Send pasn auth status failed",
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      "wlan_hdd_cfg80211_send_pasn_auth_status");
  _qdf_mem_free(v14);
  v91 = qdf_status_to_os_return(v82);
LABEL_3:
  v24 = v91;
  _osif_vdev_sync_op_stop(v95, (__int64)"wlan_hdd_wifi_pos_send_pasn_auth_status");
  _ReadStatusReg(SP_EL0);
  return v24;
}
