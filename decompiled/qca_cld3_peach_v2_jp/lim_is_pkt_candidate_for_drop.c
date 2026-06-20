_QWORD *__fastcall lim_is_pkt_candidate_for_drop(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v6; // x8
  __int64 session_by_bssid; // x0
  _QWORD *result; // x0
  _WORD *v9; // x20
  unsigned int *v10; // x8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w22
  __int64 v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x20
  int v30; // w8
  unsigned __int64 v31; // t2
  _QWORD *peer_by_mac; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x8
  __int64 v42; // x22
  bool is_vdev_roam_started; // w8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x22
  __int64 comp_private_obj; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x10
  __int64 v63; // x9
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned int *v72; // x8
  unsigned int v73; // w20
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x19
  unsigned int *v83; // x8
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  __int64 v92; // x21
  __int64 v93; // x0
  _BYTE v94[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v95; // [xsp+18h] [xbp-8h]

  v95 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  switch ( a3 )
  {
    case 5u:
      goto LABEL_4;
    case 0xBu:
      v9 = *(_WORD **)(a2 + 16);
      result = wlan_objmgr_get_vdev_by_macaddr_from_pdev(*(_QWORD *)(a1 + 21560), v9 + 2, 7u);
      if ( !result )
        goto LABEL_48;
      wlan_objmgr_vdev_release_ref((__int64)result, 7u, v10, v11, v12, v13, v14, v15, v16, v17, v18);
      v19 = (unsigned __int16)v9[11];
      v20 = lim_search_pre_auth_list(a1, v9 + 5);
      if ( v20 && (*v9 & 0x800) != 0 && *(unsigned __int16 *)(v20 + 544) == v19 >> 4 )
      {
        v29 = jiffies;
        if ( lim_is_pkt_candidate_for_drop___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: auth frame, seq num: %d is already processed, drop it",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "lim_is_pkt_candidate_for_drop");
          lim_is_pkt_candidate_for_drop___last_ticks = v29;
        }
        result = &off_0 + 7;
        goto LABEL_48;
      }
      goto LABEL_37;
    case 8u:
LABEL_4:
      v6 = *(_QWORD *)(a2 + 16);
      v94[0] = 0;
      session_by_bssid = pe_find_session_by_bssid(a1, v6 + 16, v94);
      if ( session_by_bssid && *(_BYTE *)(session_by_bssid + 7279) )
      {
        qdf_trace(53, 0xFu, 0, 0);
        result = nullptr;
        goto LABEL_48;
      }
      if ( *(_DWORD *)(a2 + 40) < 0xCu )
      {
        result = &off_0 + 5;
        goto LABEL_48;
      }
      if ( (*(_BYTE *)(*(_QWORD *)(a2 + 24) + 10LL) & 2) == 0 )
        goto LABEL_42;
      if ( (*(_BYTE *)(*(_QWORD *)(a2 + 24) + 10LL) & 1) != 0 )
      {
        result = &off_0 + 2;
        goto LABEL_48;
      }
      goto LABEL_36;
  }
  HIDWORD(v31) = a3;
  LODWORD(v31) = a3;
  v30 = v31 >> 1;
  if ( (unsigned int)(v30 - 5) >= 2 )
  {
    if ( v30 != 1 )
    {
      if ( v30 )
        goto LABEL_42;
      goto LABEL_19;
    }
LABEL_37:
    result = wlan_objmgr_get_vdev_by_macaddr_from_pdev(
               *(_QWORD *)(a1 + 21560),
               (const void *)(*(_QWORD *)(a2 + 16) + 4LL),
               7u);
    if ( !result )
      goto LABEL_48;
    v72 = (unsigned int *)*((unsigned int *)result + 4);
    if ( (_DWORD)v72 == 1 )
    {
      v73 = *((unsigned __int8 *)result + 104);
      wlan_objmgr_vdev_release_ref((__int64)result, 7u, v72, v64, v65, v66, v67, v68, v69, v70, v71);
      result = wlan_objmgr_pdev_get_roam_vdev(*(_QWORD *)(a1 + 21560), 7u);
      if ( result )
      {
        v82 = (__int64)result;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: vdev %d roaming in progress, reject client connect to SAP vdev %d",
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          "lim_is_pkt_candidate_for_drop",
          *((unsigned __int8 *)result + 104),
          v73);
        wlan_objmgr_vdev_release_ref(v82, 7u, v83, v84, v85, v86, v87, v88, v89, v90, v91);
        result = &qword_8 + 2;
      }
      goto LABEL_48;
    }
    wlan_objmgr_vdev_release_ref((__int64)result, 7u, v72, v64, v65, v66, v67, v68, v69, v70, v71);
LABEL_42:
    result = nullptr;
    goto LABEL_48;
  }
LABEL_19:
  peer_by_mac = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(a1 + 21552), (_BYTE *)(*(_QWORD *)(a2 + 16) + 10LL), 7u);
  if ( !peer_by_mac )
    goto LABEL_45;
  v41 = peer_by_mac[11];
  if ( !v41 )
  {
    wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 7u, v33, v34, v35, v36, v37, v38, v39, v40);
    result = &off_0 + 6;
    goto LABEL_48;
  }
  if ( !*(_DWORD *)(v41 + 16) )
  {
    v42 = (__int64)peer_by_mac;
    is_vdev_roam_started = wlan_cm_is_vdev_roam_started(peer_by_mac[11], v33, v34, v35, v36, v37, v38, v39, v40);
    peer_by_mac = (_QWORD *)v42;
    if ( is_vdev_roam_started && (a3 == 12 || a3 == 10) )
    {
      wlan_objmgr_peer_release_ref(v42, 7u, v44, v45, v46, v47, v48, v49, v50, v51);
      result = &qword_8 + 1;
      goto LABEL_48;
    }
  }
  v52 = (__int64)peer_by_mac;
  comp_private_obj = wlan_objmgr_peer_get_comp_private_obj((__int64)peer_by_mac, 0);
  if ( !comp_private_obj )
  {
    wlan_objmgr_peer_release_ref(v52, 7u, v54, v55, v56, v57, v58, v59, v60, v61);
LABEL_45:
    if ( a3 )
      result = &off_0 + 6;
    else
      result = nullptr;
    goto LABEL_48;
  }
  if ( a3 )
    v62 = 32;
  else
    v62 = 24;
  v63 = *(_QWORD *)(comp_private_obj + v62);
  if ( !v63 || (__int64)(1000 * (jiffies / 0xFAuLL) - v63 + 4 * (jiffies % 0xFAuLL) - 1000) >= 0 )
  {
    *(_QWORD *)(comp_private_obj + v62) = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
    wlan_objmgr_peer_release_ref(v52, 7u, v54, v55, v56, v57, v58, v59, v60, v61);
LABEL_36:
    if ( (a3 | 2) != 2 )
      goto LABEL_42;
    goto LABEL_37;
  }
  v92 = jiffies;
  v93 = v52;
  if ( lim_is_pkt_candidate_for_drop___last_ticks_58 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: %s: Dropping subtype 0x%x frame. %s %d ms %s %d ms",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      "lim_is_pkt_candidate_for_drop",
      "lim_is_pkt_candidate_for_drop",
      a3,
      "It is received after",
      1000 * (unsigned int)(jiffies / 0xFAuLL) - (unsigned int)v63 + 4 * (jiffies % 0xFAuLL),
      "of last frame. Allow it only after",
      1000);
    v93 = v52;
    lim_is_pkt_candidate_for_drop___last_ticks_58 = v92;
  }
  wlan_objmgr_peer_release_ref(v93, 7u, v54, v55, v56, v57, v58, v59, v60, v61);
  result = &qword_8;
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
