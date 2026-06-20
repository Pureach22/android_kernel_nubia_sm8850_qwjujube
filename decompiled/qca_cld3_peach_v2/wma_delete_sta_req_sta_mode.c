__int64 __fastcall wma_delete_sta_req_sta_mode(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  unsigned int *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x21
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned __int8 v56; // w1
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  int v65; // w8
  int v66; // w4
  int v67; // w8
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7

  result = wmi_service_enabled(*a1, 0x9Cu, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( (result & 1) != 0 )
  {
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
               a1[3],
               *(unsigned __int8 *)(a2 + 10),
               8);
    if ( result )
    {
      v21 = result;
      if ( (ucfg_pmo_get_moddtim_user_enable(result) & 1) != 0 )
        v23 = ucfg_pmo_set_moddtim_user_enable(v21, 0);
      result = wlan_objmgr_vdev_release_ref(v21, 8u, v22, v23, v24, v25, v26, v27, v28, v29, v30);
    }
  }
  *(_DWORD *)(a1[65] + 488LL * *(unsigned __int8 *)(a2 + 10) + 212) = 0;
  if ( *(_BYTE *)(a2 + 11) != 4 )
  {
    v65 = *(unsigned __int8 *)(a2 + 8);
    *(_DWORD *)(a2 + 4) = 0;
    if ( !v65 )
      return result;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: vdev_id %d status %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_delete_sta_req_sta_mode",
      *(unsigned __int8 *)(a2 + 10),
      0);
    return wma_send_msg_high_priority(a1, 4132, a2, 0);
  }
  result = _qdf_mem_malloc(0x444u, "wma_del_tdls_sta", 6068);
  if ( !result )
  {
    v66 = 2;
LABEL_17:
    v67 = *(unsigned __int8 *)(a2 + 8);
    *(_DWORD *)(a2 + 4) = v66;
    if ( !v67 )
      return result;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Sending del rsp to umac (status: %d)",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "wma_del_tdls_sta");
    return wma_send_msg_high_priority(a1, 4132, a2, 0);
  }
  v39 = result;
  *(_DWORD *)(result + 12) = 2;
  *(_DWORD *)result = *(unsigned __int8 *)(a2 + 10);
  *(_BYTE *)(result + 1088) = *(_BYTE *)(a2 + 8) != 0;
  qdf_mem_copy((void *)(result + 4), (const void *)(a2 + 12), 6u);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: sending tdls_peer_state for peer mac: %02x:%02x:%02x:**:**:%02x, peerState: %d",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "wma_del_tdls_sta",
    *(unsigned __int8 *)(v39 + 4),
    *(unsigned __int8 *)(v39 + 5),
    *(unsigned __int8 *)(v39 + 6),
    *(unsigned __int8 *)(v39 + 9),
    *(_DWORD *)(v39 + 12));
  result = wma_update_tdls_peer_state(a1, v39);
  if ( (result & 0x80000000) != 0 )
  {
    result = qdf_trace_msg(
               0x36u,
               2u,
               "%s: wma_update_tdls_peer_state returned failure",
               v48,
               v49,
               v50,
               v51,
               v52,
               v53,
               v54,
               v55,
               "wma_del_tdls_sta");
    v66 = 16;
    goto LABEL_17;
  }
  if ( *(_BYTE *)(a2 + 8) )
  {
    result = wmi_service_enabled(*a1, 0x6Eu, v48, v49, v50, v51, v52, v53, v54, v55);
    if ( (result & 1) != 0 )
    {
      v56 = *(_BYTE *)(a2 + 10);
      *(_DWORD *)(a2 + 4) = 0;
      if ( wma_fill_hold_req(a1, v56, 0x1023u, 2u, (const void *)(a2 + 12), a2, 0x1F40u) )
        return wma_acquire_wakelock(a1 + 391, 3000);
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to allocate vdev_id %d",
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        "wma_del_tdls_sta",
        *(unsigned __int8 *)(a2 + 10));
      result = wma_remove_req((__int64)a1, *(_BYTE *)(a2 + 10), 2u, v68, v69, v70, v71, v72, v73, v74, v75);
      v66 = 2;
      goto LABEL_17;
    }
  }
  return result;
}
