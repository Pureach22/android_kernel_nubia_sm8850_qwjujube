__int64 __fastcall wma_delete_peer_on_vdev_stop(
        __int64 *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w23
  __int64 v13; // x22
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  _QWORD *peer_by_mac; // x0
  __int64 v32; // x21
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w8
  __int64 v51; // x21
  unsigned int v52; // w0
  unsigned int v53; // w19
  unsigned __int8 v54; // w22
  __int64 **context; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x9
  __int64 v65; // x8
  __int64 v66; // x8
  __int64 (*v67)(void); // x8
  int *v68; // x23
  const char *v69; // x2
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  __int64 v86; // x0
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  int v95; // [xsp+4h] [xbp-1Ch] BYREF
  int v96; // [xsp+8h] [xbp-18h] BYREF
  __int16 v97; // [xsp+Ch] [xbp-14h]
  int v98; // [xsp+10h] [xbp-10h] BYREF
  __int16 v99; // [xsp+14h] [xbp-Ch]
  __int64 v100; // [xsp+18h] [xbp-8h]

  v12 = (unsigned __int8)a2;
  v100 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = a1[65] + 488LL * (unsigned __int8)a2;
  v95 = 0;
  v96 = 0;
  v97 = 0;
  if ( (unsigned int)wlan_vdev_get_bss_peer_mac(*(_QWORD *)v13, &v96, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to get bssid",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wma_delete_peer_on_vdev_stop");
LABEL_5:
    result = 4;
    goto LABEL_6;
  }
  if ( (unsigned int)mlme_get_vdev_stop_type(*(_QWORD *)v13, &v95, v14, v15, v16, v17, v18, v19, v20, v21) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to get wma req msg type for vdev id %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wma_delete_peer_on_vdev_stop",
      (unsigned __int8)a2);
    goto LABEL_5;
  }
  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1[3], &v96, 8u);
  if ( peer_by_mac )
  {
    v32 = (__int64)peer_by_mac;
    v33 = wlan_mlo_link_peer_delete();
    wlan_objmgr_peer_release_ref(v32, 8u, v33, v34, v35, v36, v37, v38, v39, v40);
  }
  v41 = _qdf_mem_malloc(8u, "wma_delete_peer_on_vdev_stop", 2845);
  if ( !v41 )
  {
    result = 2;
    goto LABEL_6;
  }
  v50 = v95;
  v51 = v41;
  if ( v95 != 4135 && v95 != 4173 )
  {
    if ( v95 == 4174 )
    {
      v52 = wma_remove_peer(a1, &v96, a2, 1, v42, v43, v44, v45, v46, v47, v48, v49);
      if ( v52 )
      {
        v53 = v52;
        _qdf_mem_free(v51);
        result = v53;
        goto LABEL_6;
      }
      *(_DWORD *)v51 = 0;
      *(_BYTE *)(v51 + 4) = a2;
LABEL_42:
      wma_send_vdev_down_req(a1, v51);
      result = 0;
      goto LABEL_6;
    }
LABEL_47:
    result = 0;
    goto LABEL_6;
  }
  if ( *(_DWORD *)(v13 + 164) == 2 )
  {
    wma_get_cca_stats(a1, a2);
    v50 = v95;
  }
  *(_BYTE *)(v51 + 4) = a2;
  if ( v50 == 4135 )
    v54 = 5;
  else
    v54 = 4;
  *(_DWORD *)v51 = 0;
  context = (__int64 **)_cds_get_context(71, (__int64)"wma_remove_bss_peer", v42, v43, v44, v45, v46, v47, v48, v49);
  v64 = a1[65];
  v99 = 0;
  v65 = v64 + 488LL * v12;
  v98 = 0;
  if ( *(_DWORD *)(v65 + 164) == 7 )
  {
    if ( !context || !*context )
    {
      qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v56, v57, v58, v59, v60, v61, v62, v63, "cdp_get_vdev_mac_addr");
LABEL_33:
      v69 = "%s: mac_addr is NULL for vdev_id = %d";
      goto LABEL_36;
    }
    v66 = **context;
    if ( !v66 )
      goto LABEL_33;
    v67 = *(__int64 (**)(void))(v66 + 360);
    if ( !v67 )
      goto LABEL_33;
    if ( *((_DWORD *)v67 - 1) != -1168872836 )
      __break(0x8228u);
    v68 = (int *)v67();
    if ( !v68 )
      goto LABEL_33;
  }
  else
  {
    v68 = &v98;
    if ( (unsigned int)wlan_vdev_get_bss_peer_mac(*(_QWORD *)v65, &v98, v56, v57, v58, v59, v60, v61, v62, v63) )
    {
      v69 = "%s: Failed to get bssid for vdev_id: %d";
LABEL_36:
      qdf_trace_msg(0x36u, 2u, v69, v56, v57, v58, v59, v60, v61, v62, v63, "wma_remove_bss_peer", (unsigned __int8)a2);
      goto LABEL_37;
    }
  }
  if ( (unsigned int)wma_remove_peer(a1, v68, a2, 0, v56, v57, v58, v59, v60, v61, v62, v63) )
  {
    v69 = "%s: wma_remove_peer failed vdev_id:%d";
    goto LABEL_36;
  }
  if ( (cds_get_driver_state(v56, v57, v58, v59, v60, v61, v62, v63) & 8) == 0 )
  {
    if ( (wmi_service_enabled(*a1, 0x6Eu, v70, v71, v72, v73, v74, v75, v76, v77) & 1) == 0
      || (qdf_trace_msg(
            0x36u,
            8u,
            "%s: Wait for the peer delete. vdev_id %d",
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            v93,
            v94,
            "wma_remove_bss_peer",
            (unsigned __int8)a2),
          wma_fill_hold_req(a1, a2, 0x1023u, v54, v68, v51, 0x1F40u)) )
    {
      if ( (wmi_service_enabled(*a1, 0x6Eu, v87, v88, v89, v90, v91, v92, v93, v94) & 1) == 0 )
        goto LABEL_42;
      goto LABEL_47;
    }
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to allocate request. vdev_id %d",
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      "wma_remove_bss_peer",
      (unsigned __int8)a2);
    *(_DWORD *)v51 = 2;
  }
LABEL_37:
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: Del bss failed vdev:%d",
    v70,
    v71,
    v72,
    v73,
    v74,
    v75,
    v76,
    v77,
    "wma_delete_peer_on_vdev_stop",
    (unsigned __int8)a2);
  v86 = *(_QWORD *)(a1[65] + 488LL * *(unsigned __int8 *)(v51 + 4));
  if ( (*(_DWORD *)(v86 + 16) & 0xFFFFFFFD) != 0 )
  {
    wlan_vdev_mlme_sm_deliver_evt(v86, 0x1Au, 8u, v51, v78, v79, v80, v81, v82, v83, v84, v85);
  }
  else
  {
    wlan_cm_bss_peer_delete_rsp(v86, *(_DWORD *)v51, v78, v79, v80, v81, v82, v83, v84, v85);
    _qdf_mem_free(v51);
  }
  result = 4294967274LL;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
