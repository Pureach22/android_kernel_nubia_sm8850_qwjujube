__int64 __fastcall tdls_check_and_indicate_delete_all_peers(__int64 a1, unsigned int a2)
{
  char v4; // w21
  int pdev_id_from_vdev_id; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 pdev_by_id; // x0
  __int64 v15; // x22
  int opmode_from_vdev_id; // w23
  unsigned int *v17; // x8
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  const char *v26; // x2
  __int64 result; // x0
  __int64 v28; // x0
  _QWORD *v29; // x21
  __int64 v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x19
  unsigned int *v40; // x8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // [xsp+8h] [xbp-38h] BYREF
  _QWORD *v58; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v59)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v60)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+20h] [xbp-20h]
  __int64 v61; // [xsp+28h] [xbp-18h]
  __int64 v62; // [xsp+30h] [xbp-10h]
  __int64 v63; // [xsp+38h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = policy_mgr_mode_specific_connection_count(a1, 0, nullptr);
  pdev_id_from_vdev_id = wlan_get_pdev_id_from_vdev_id(a1, a2, 0x10u);
  if ( pdev_id_from_vdev_id == -1 )
  {
    v26 = "%s: Invalid pdev id";
    goto LABEL_8;
  }
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, pdev_id_from_vdev_id, 0x10u);
  if ( !pdev_by_id )
  {
    v26 = "%s: pdev is NULL";
    goto LABEL_8;
  }
  v15 = pdev_by_id;
  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(pdev_by_id, a2);
  wlan_objmgr_pdev_release_ref(v15, 0x10u, v17, v18, v19, v20, v21, v22, v23, v24, v25);
  if ( opmode_from_vdev_id == 2 && v4 )
  {
    v26 = "%s: STA + P2P concurrency. No action on P2P vdev";
LABEL_8:
    qdf_trace_msg(0, 8u, v26, v6, v7, v8, v9, v10, v11, v12, v13, "tdls_check_and_indicate_delete_all_peers");
LABEL_9:
    result = 4;
    goto LABEL_10;
  }
  v61 = 0;
  v62 = 0;
  v59 = nullptr;
  v60 = nullptr;
  v57 = 0;
  v58 = nullptr;
  v28 = _qdf_mem_malloc(8u, "tdls_delete_all_peers_indication", 1977);
  if ( !v28 )
  {
    result = 29;
    goto LABEL_10;
  }
  v29 = (_QWORD *)v28;
  v30 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 16);
  if ( !v30 )
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: vdev:%d does not exist",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "tdls_delete_all_peers_indication",
      (unsigned __int8)a2);
    _qdf_mem_free((__int64)v29);
    goto LABEL_9;
  }
  *v29 = v30;
  v58 = v29;
  v59 = tdls_process_cmd;
  v39 = v30;
  LOWORD(v57) = 24;
  v60 = tdls_post_msg_flush_cb;
  result = scheduler_post_message_debug(
             0,
             0,
             72,
             (unsigned __int16 *)&v57,
             0x7CEu,
             (__int64)"tdls_delete_all_peers_indication");
  if ( (_DWORD)result )
  {
    wlan_objmgr_vdev_release_ref(v39, 0x10u, v40, v41, v42, v43, v44, v45, v46, v47, v48);
    _qdf_mem_free((__int64)v29);
    qdf_trace_msg(
      0,
      1u,
      "%s: message post failed ",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "tdls_delete_all_peers_indication");
    result = 16;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
