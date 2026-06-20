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
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  int v40; // w8
  __int64 v41; // x21
  unsigned int v42; // w0
  unsigned int v43; // w19
  unsigned __int8 v44; // w22
  __int64 **context; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x9
  __int64 v55; // x8
  __int64 v56; // x8
  __int64 (*v57)(void); // x8
  int *v58; // x23
  const char *v59; // x2
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  int v85; // [xsp+4h] [xbp-1Ch] BYREF
  int v86; // [xsp+8h] [xbp-18h] BYREF
  __int16 v87; // [xsp+Ch] [xbp-14h]
  int v88; // [xsp+10h] [xbp-10h] BYREF
  __int16 v89; // [xsp+14h] [xbp-Ch]
  __int64 v90; // [xsp+18h] [xbp-8h]

  v12 = (unsigned __int8)a2;
  v90 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = a1[65] + 488LL * (unsigned __int8)a2;
  v85 = 0;
  v86 = 0;
  v87 = 0;
  if ( (unsigned int)wlan_vdev_get_bss_peer_mac(*(_QWORD *)v13, &v86, a3, a4, a5, a6, a7, a8, a9, a10) )
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
  if ( (unsigned int)mlme_get_vdev_stop_type(*(_QWORD *)v13, &v85, v14, v15, v16, v17, v18, v19, v20, v21) )
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
  v31 = _qdf_mem_malloc(8u, "wma_delete_peer_on_vdev_stop", 2845);
  if ( !v31 )
  {
    result = 2;
    goto LABEL_6;
  }
  v40 = v85;
  v41 = v31;
  if ( v85 != 4135 && v85 != 4173 )
  {
    if ( v85 == 4174 )
    {
      v42 = wma_remove_peer(a1, &v86, a2, 1, v32, v33, v34, v35, v36, v37, v38, v39);
      if ( v42 )
      {
        v43 = v42;
        _qdf_mem_free(v41);
        result = v43;
        goto LABEL_6;
      }
      *(_DWORD *)v41 = 0;
      *(_BYTE *)(v41 + 4) = a2;
LABEL_40:
      wma_send_vdev_down_req(a1, v41);
      result = 0;
      goto LABEL_6;
    }
LABEL_45:
    result = 0;
    goto LABEL_6;
  }
  if ( *(_DWORD *)(v13 + 164) == 2 )
  {
    wma_get_cca_stats(a1, a2);
    v40 = v85;
  }
  *(_BYTE *)(v41 + 4) = a2;
  if ( v40 == 4135 )
    v44 = 5;
  else
    v44 = 4;
  *(_DWORD *)v41 = 0;
  context = (__int64 **)_cds_get_context(71, (__int64)"wma_remove_bss_peer", v32, v33, v34, v35, v36, v37, v38, v39);
  v54 = a1[65];
  v89 = 0;
  v55 = v54 + 488LL * v12;
  v88 = 0;
  if ( *(_DWORD *)(v55 + 164) == 7 )
  {
    if ( !context || !*context )
    {
      qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", v46, v47, v48, v49, v50, v51, v52, v53, "cdp_get_vdev_mac_addr");
LABEL_31:
      v59 = "%s: mac_addr is NULL for vdev_id = %d";
      goto LABEL_34;
    }
    v56 = **context;
    if ( !v56 )
      goto LABEL_31;
    v57 = *(__int64 (**)(void))(v56 + 360);
    if ( !v57 )
      goto LABEL_31;
    if ( *((_DWORD *)v57 - 1) != -1168872836 )
      __break(0x8228u);
    v58 = (int *)v57();
    if ( !v58 )
      goto LABEL_31;
  }
  else
  {
    v58 = &v88;
    if ( (unsigned int)wlan_vdev_get_bss_peer_mac(*(_QWORD *)v55, &v88, v46, v47, v48, v49, v50, v51, v52, v53) )
    {
      v59 = "%s: Failed to get bssid for vdev_id: %d";
LABEL_34:
      qdf_trace_msg(0x36u, 2u, v59, v46, v47, v48, v49, v50, v51, v52, v53, "wma_remove_bss_peer", (unsigned __int8)a2);
      goto LABEL_35;
    }
  }
  if ( (unsigned int)wma_remove_peer(a1, v58, a2, 0, v46, v47, v48, v49, v50, v51, v52, v53) )
  {
    v59 = "%s: wma_remove_peer failed vdev_id:%d";
    goto LABEL_34;
  }
  if ( (cds_get_driver_state(v46, v47, v48, v49, v50, v51, v52, v53) & 8) == 0 )
  {
    if ( (wmi_service_enabled(*a1, 0x6Eu, v60, v61, v62, v63, v64, v65, v66, v67) & 1) == 0
      || (qdf_trace_msg(
            0x36u,
            8u,
            "%s: Wait for the peer delete. vdev_id %d",
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            "wma_remove_bss_peer",
            (unsigned __int8)a2),
          wma_fill_hold_req(a1, a2, 0x1023u, v44, v58, v41, 0x1F40u)) )
    {
      if ( (wmi_service_enabled(*a1, 0x6Eu, v77, v78, v79, v80, v81, v82, v83, v84) & 1) == 0 )
        goto LABEL_40;
      goto LABEL_45;
    }
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to allocate request. vdev_id %d",
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      "wma_remove_bss_peer",
      (unsigned __int8)a2);
    *(_DWORD *)v41 = 2;
  }
LABEL_35:
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: Del bss failed vdev:%d",
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    "wma_delete_peer_on_vdev_stop",
    (unsigned __int8)a2);
  v76 = *(_QWORD *)(a1[65] + 488LL * *(unsigned __int8 *)(v41 + 4));
  if ( (*(_DWORD *)(v76 + 16) & 0xFFFFFFFD) != 0 )
  {
    wlan_vdev_mlme_sm_deliver_evt(v76, 0x1Au, 8u, v41, v68, v69, v70, v71, v72, v73, v74, v75);
  }
  else
  {
    wlan_cm_bss_peer_delete_rsp(v76, *(_DWORD *)v41, v68, v69, v70, v71, v72, v73, v74, v75);
    _qdf_mem_free(v41);
  }
  result = 4294967274LL;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
