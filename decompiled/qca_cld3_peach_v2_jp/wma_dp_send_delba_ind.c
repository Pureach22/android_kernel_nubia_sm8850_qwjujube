__int64 __fastcall wma_dp_send_delba_ind(
        unsigned int a1,
        unsigned __int8 *a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  _QWORD *context; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _QWORD *v27; // x19
  __int64 system_time; // x25
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x24
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned __int64 v47; // x27
  __int64 last_delba_sent_time; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int *v65; // x8
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned int *v75; // x8
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  _BYTE *v84; // x0
  _BYTE *v85; // x24
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7

  context = _cds_get_context(54, (__int64)"wma_dp_send_delba_ind", a6, a7, a8, a9, a10, a11, a12, a13);
  if ( !a2 || (v27 = context) == nullptr )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: wma handle or mac addr is NULL",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wma_dp_send_delba_ind");
    return 4294967274LL;
  }
  system_time = qdf_mc_timer_get_system_time();
  v29 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v27[3], a1, 77);
  if ( v29 )
  {
    v38 = v29;
    if ( (wlan_mlme_is_ba_2k_jump_iot_ap(v29, v30, v31, v32, v33, v34, v35, v36, v37) & 1) != 0 )
      v47 = 3000;
    else
      v47 = 300;
    last_delba_sent_time = wlan_mlme_get_last_delba_sent_time(v38, v39, v40, v41, v42, v43, v44, v45, v46);
    if ( a5 == 1 && last_delba_sent_time && system_time - last_delba_sent_time < v47 )
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Drop DELBA, last sent ts: %lu current ts: %lu",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "wma_drop_delba",
        last_delba_sent_time,
        system_time);
      wlan_mlme_set_last_delba_sent_time(v38, system_time, v57, v58, v59, v60, v61, v62, v63, v64);
      wlan_objmgr_vdev_release_ref(v38, 0x4Du, v65, v66, v67, v68, v69, v70, v71, v72, v73);
      return 0;
    }
    wlan_mlme_set_last_delba_sent_time(v38, system_time, v49, v50, v51, v52, v53, v54, v55, v56);
    wlan_objmgr_vdev_release_ref(v38, 0x4Du, v75, v76, v77, v78, v79, v80, v81, v82, v83);
  }
  else
  {
    qdf_trace_msg(0x36u, 2u, "%s: vdev is NULL", v30, v31, v32, v33, v34, v35, v36, v37, "wma_drop_delba");
  }
  v84 = (_BYTE *)_qdf_mem_malloc(9u, "wma_dp_send_delba_ind", 3132);
  if ( v84 )
  {
    *v84 = a1;
    v85 = v84;
    qdf_mem_copy(v84 + 1, a2, 6u);
    v85[7] = a3;
    v85[8] = a4;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: req delba_ind vdev %d %02x:%02x:%02x:**:**:%02x tid %d reason %d",
      v86,
      v87,
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      "wma_dp_send_delba_ind",
      (unsigned __int8)a1,
      *a2,
      a2[1],
      a2[2],
      a2[5],
      a3,
      a4);
    wma_send_msg_high_priority(v27, 4543, v85, 0);
    return 0;
  }
  return 4294967284LL;
}
