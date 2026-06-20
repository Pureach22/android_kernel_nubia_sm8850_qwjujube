__int64 __fastcall hdd_check_and_reject_reassoc_command(__int64 *a1, unsigned __int8 *a2)
{
  __int64 v4; // x8
  __int64 v5; // x22
  __int64 vdev_by_user; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x5
  __int64 v41; // x6
  __int64 v42; // x7
  int v43; // w8
  __int64 result; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // [xsp+8h] [xbp-18h]
  __int64 v54; // [xsp+10h] [xbp-10h] BYREF
  __int64 v55; // [xsp+18h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  WORD2(v54) = 0;
  LODWORD(v54) = 0;
  v5 = *(_QWORD *)(v4 + 24);
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_check_and_reject_reassoc_command");
  if ( !vdev_by_user )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: vdev is NULL",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "hdd_check_and_reject_reassoc_command");
LABEL_10:
    result = 4294967274LL;
    goto LABEL_11;
  }
  v15 = vdev_by_user;
  wlan_vdev_get_bss_peer_mac(vdev_by_user, &v54, v7, v8, v9, v10, v11, v12, v13, v14);
  if ( (unsigned int)ucfg_cm_roam_get_roam_score_algo(*(_QWORD *)(v5 + 8), v16, v17, v18, v19, v20, v21, v22, v23) == 1
    && ucfg_cm_is_bssid_present_on_any_assoc_link(v15, (__int64)a2, v24, v25, v26, v27, v28, v29, v30, v31) )
  {
    if ( a2 )
    {
      v40 = *a2;
      v41 = a2[1];
      v42 = a2[2];
      v43 = a2[5];
    }
    else
    {
      v42 = 0;
      v40 = 0;
      v41 = 0;
      v43 = 0;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev: %d reject self REASSOC cmd on connected bssid%02x:%02x:%02x:**:**:%02x",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "hdd_check_and_reject_reassoc_command",
      *(unsigned __int8 *)(*(_QWORD *)(*a1 + 52824) + 8LL),
      v40,
      v41,
      v42,
      v43,
      v53,
      v54,
      v55);
    ucfg_cm_roam_reject_reassoc_event(
      *(_QWORD *)(v5 + 8),
      v15,
      (unsigned __int8 *)&v54,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52);
    _hdd_objmgr_put_vdev_by_user(v15, 6, "hdd_check_and_reject_reassoc_command");
    goto LABEL_10;
  }
  _hdd_objmgr_put_vdev_by_user(v15, 6, "hdd_check_and_reject_reassoc_command");
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
