__int64 __fastcall wma_delete_all_pasn_peers(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 *v19; // x19
  unsigned int v20; // w20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v38; // x2
  __int64 rx_ops; // x0
  __int64 (__fastcall *v40)(_QWORD); // x8
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w20
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x21
  __int64 v76; // x0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x19
  unsigned int *v86; // x8
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7

  context = _cds_get_context(54, (__int64)"wma_delete_all_pasn_peers", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v38 = "%s: wma handle is NULL";
    goto LABEL_14;
  }
  v19 = context;
  v20 = *(unsigned __int8 *)(a1 + 104);
  wma_acquire_wakelock((__int64)(context + 391), 0x1F40u, v11, v12, v13, v14, v15, v16, v17, v18);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Delete all PASN peer of vdev:%d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "wma_delete_all_pasn_peers",
    *(unsigned __int8 *)(a1 + 104));
  if ( (unsigned int)wlan_get_opmode_from_vdev_id(v19[4], v20) != 16 )
  {
    rx_ops = wifi_pos_get_rx_ops(v19[3]);
    if ( rx_ops )
    {
      v40 = *(__int64 (__fastcall **)(_QWORD))(rx_ops + 40);
      if ( v40 )
      {
        if ( *((_DWORD *)v40 - 1) != 1263140689 )
          __break(0x8228u);
        v41 = v40(a1);
        if ( v41 )
        {
          v50 = v41;
          wma_release_wakelock((__int64)(v19 + 391), v42, v43, v44, v45, v46, v47, v48, v49);
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Delete all ranging peers failed",
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            "wma_delete_all_pasn_peers");
          return v50;
        }
        goto LABEL_4;
      }
    }
    v38 = "%s: rx_ops is NULL";
LABEL_14:
    qdf_trace_msg(0x36u, 2u, v38, v11, v12, v13, v14, v15, v16, v17, v18, "wma_delete_all_pasn_peers");
    return 29;
  }
  wlan_nan_vdev_delete_all_pasn_peers(a1);
LABEL_4:
  if ( wma_fill_hold_req(v19, v20, 0x11C7u, 0xBu, nullptr, 0, 0x1F40u) )
    return 0;
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: Failed to allocate request for vdev_id %d",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "wma_delete_all_pasn_peers",
    v20);
  wma_remove_req((__int64)v19, v20, 0xBu, v59, v60, v61, v62, v63, v64, v65, v66);
  wma_release_wakelock((__int64)(v19 + 391), v67, v68, v69, v70, v71, v72, v73, v74);
  v75 = v19[2];
  v76 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v19[3], v20, 8);
  if ( v76 )
  {
    v85 = v76;
    lim_pasn_peer_del_all_resp_vdev_delete_resume(v75, v76, v77, v78, v79, v80, v81, v82, v83, v84);
    wlan_objmgr_vdev_release_ref(v85, 8u, v86, v87, v88, v89, v90, v91, v92, v93, v94);
  }
  else
  {
    qdf_trace_msg(0x36u, 2u, "%s: Vdev is NULL", v77, v78, v79, v80, v81, v82, v83, v84, "wma_resume_vdev_delete");
  }
  return 16;
}
