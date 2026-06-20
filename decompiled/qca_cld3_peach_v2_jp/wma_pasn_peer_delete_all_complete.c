__int64 __fastcall wma_pasn_peer_delete_all_complete(
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
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w19
  _QWORD *v20; // x20
  _QWORD *v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x21
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x21
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x19
  unsigned int *v50; // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7

  context = _cds_get_context(54, (__int64)"wma_pasn_peer_delete_all_complete", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    v19 = *(unsigned __int8 *)(a1 + 104);
    v20 = context;
    v21 = wma_find_remove_req_msgtype((__int64)context, v19, 0, 0x11C7u);
    if ( v21 )
    {
      v30 = (__int64)v21;
      qdf_mc_timer_stop((__int64)v21);
      qdf_mc_timer_destroy(v30);
      _qdf_mem_free(v30);
      wma_release_wakelock((__int64)(v20 + 391), v31, v32, v33, v34, v35, v36, v37, v38);
      if ( (unsigned int)wlan_get_opmode_from_vdev_id(v20[4], v19) == 16 )
        return 0;
      v39 = v20[2];
      v40 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v20[3], v19, 8);
      if ( v40 )
      {
        v49 = v40;
        lim_pasn_peer_del_all_resp_vdev_delete_resume(v39, v40, v41, v42, v43, v44, v45, v46, v47, v48);
        wlan_objmgr_vdev_release_ref(v49, 8u, v50, v51, v52, v53, v54, v55, v56, v57, v58);
        return 0;
      }
      qdf_trace_msg(0x36u, 2u, "%s: Vdev is NULL", v41, v42, v43, v44, v45, v46, v47, v48, "wma_resume_vdev_delete");
      return 29;
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: vdev:%d Failed to lookup pasn peer del req",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "wma_pasn_peer_delete_all_complete",
        v19);
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: wma_handle is NULL",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wma_pasn_peer_delete_all_complete");
    return 16;
  }
}
