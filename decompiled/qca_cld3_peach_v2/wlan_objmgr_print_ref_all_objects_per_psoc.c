__int64 __fastcall wlan_objmgr_print_ref_all_objects_per_psoc(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned __int64 v26; // x8
  __int64 v27; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v29; // x8
  unsigned int v30; // w20
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7

  qdf_trace_msg(
    0x57u,
    1u,
    "%s: Ref counts of PEER",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_objmgr_print_ref_all_objects_per_psoc");
  wlan_objmgr_iterate_obj_list_all_noref(a1, 3, wlan_objmgr_psoc_peer_ref_print);
  qdf_trace_msg(
    0x57u,
    1u,
    "%s: Ref counts of VDEV",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "wlan_objmgr_print_ref_all_objects_per_psoc");
  wlan_objmgr_iterate_obj_list_all_noref(a1, 2, wlan_objmgr_psoc_vdev_ref_print);
  qdf_trace_msg(
    0x57u,
    1u,
    "%s: Ref counts of PDEV",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "wlan_objmgr_print_ref_all_objects_per_psoc");
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v26 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v26 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v26 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 2816);
    v27 = *(_QWORD *)(a1 + 64);
    if ( !v27 )
      goto LABEL_11;
LABEL_5:
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v27 + 1248);
      v29 = *(_QWORD *)(v27 + 1256);
      v30 = *(unsigned __int8 *)(v27 + 40);
      if ( (v29 & 1) == 0 )
      {
LABEL_9:
        raw_spin_unlock(v27 + 1248);
LABEL_10:
        qdf_trace_msg(
          0x57u,
          1u,
          "%s: pdev ID is %d",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "wlan_objmgr_psoc_pdev_ref_print",
          v30);
        wlan_objmgr_print_ref_ids(v27 + 92, 1u, v39, v40, v41, v42, v43, v44, v45, v46);
        goto LABEL_11;
      }
    }
    else
    {
      raw_spin_lock_bh(v27 + 1248);
      v29 = *(_QWORD *)(v27 + 1256) | 1LL;
      *(_QWORD *)(v27 + 1256) = v29;
      v30 = *(unsigned __int8 *)(v27 + 40);
      if ( (v29 & 1) == 0 )
        goto LABEL_9;
    }
    *(_QWORD *)(v27 + 1256) = v29 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v27 + 1248);
    goto LABEL_10;
  }
  raw_spin_lock_bh(a1 + 2816);
  *(_QWORD *)(a1 + 2824) |= 1uLL;
  v27 = *(_QWORD *)(a1 + 64);
  if ( v27 )
    goto LABEL_5;
LABEL_11:
  v47 = *(_QWORD *)(a1 + 2824);
  if ( (v47 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 2824) = v47 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 2816);
  }
  else
  {
    raw_spin_unlock(a1 + 2816);
  }
  qdf_trace_msg(
    0x57u,
    1u,
    "%s:  Ref counts of PSOC",
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    "wlan_objmgr_print_ref_all_objects_per_psoc");
  wlan_objmgr_print_ref_ids(a1 + 1684, 1u, v56, v57, v58, v59, v60, v61, v62, v63);
  return 0;
}
