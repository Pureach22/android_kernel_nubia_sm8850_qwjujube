__int64 __fastcall tdls_process_del_peer_rsp(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x4
  __int64 v11; // x5
  const void *v12; // x22
  __int64 v13; // x6
  __int64 v14; // x7
  int v15; // w8
  __int64 comp_private_obj; // x21
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x20
  unsigned int v27; // w23
  __int64 v28; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x24
  unsigned __int16 v38; // w8
  unsigned __int8 v39; // w25
  unsigned __int8 *v40; // x23
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 peer; // x25
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x5
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x0
  __int64 v76; // x2
  __int64 v77; // x0
  __int64 v78; // x26
  __int64 v79; // x27
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  _QWORD *v88; // x28
  __int64 v89; // x4
  __int64 v90; // x5
  __int64 v91; // x6
  __int64 v92; // x7
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  unsigned int *v101; // x8
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  _DWORD *v110; // x8
  __int64 v111; // x0
  void (__fastcall *v113)(_QWORD); // x8
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  __int64 v122; // [xsp+0h] [xbp-50h]
  __int64 v123; // [xsp+8h] [xbp-48h]
  _QWORD *v124[4]; // [xsp+10h] [xbp-40h] BYREF
  _QWORD v125[4]; // [xsp+30h] [xbp-20h] BYREF

  v125[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  v12 = a1 + 8;
  v11 = a1[8];
  v13 = a1[9];
  v14 = a1[10];
  v15 = a1[13];
  memset(v125, 0, 24);
  qdf_trace_msg(
    0,
    8u,
    "%s: del peer rsp: vdev %d  peer %02x:%02x:%02x:**:**:%02x",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "tdls_process_del_peer_rsp",
    v10,
    v11,
    v13,
    v14,
    v15);
  comp_private_obj = *((_QWORD *)a1 + 2);
  v17 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          comp_private_obj,
          *a1,
          16);
  if ( !v17 )
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: invalid vdev: %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "tdls_process_del_peer_rsp",
      *a1);
    v27 = 4;
    goto LABEL_42;
  }
  v26 = v17;
  if ( comp_private_obj )
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(comp_private_obj, 0xAu);
  else
    qdf_trace_msg(0, 2u, "%s: NULL psoc", v18, v19, v20, v21, v22, v23, v24, v25, "wlan_psoc_get_tdls_soc_obj");
  v28 = wlan_objmgr_vdev_get_comp_private_obj(v26, 0xAu);
  v37 = v28;
  if ( !comp_private_obj || !v28 )
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: soc object:%pK, vdev object:%pK",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "tdls_process_del_peer_rsp",
      comp_private_obj,
      v28);
    v27 = 16;
    goto LABEL_37;
  }
  v38 = *(_WORD *)(comp_private_obj + 200);
  if ( !v38 )
  {
LABEL_19:
    v27 = 16;
    goto LABEL_20;
  }
  v39 = 0;
  while ( 1 )
  {
    v40 = (unsigned __int8 *)(comp_private_obj + 32 + 9LL * v39);
    if ( *v40 != *a1 )
      goto LABEL_11;
    if ( !(unsigned int)qdf_mem_cmp(v40 + 3, v12, 6u) )
      break;
    v38 = *(_WORD *)(comp_private_obj + 200);
LABEL_11:
    if ( v38 <= (unsigned int)++v39 )
      goto LABEL_19;
  }
  qdf_trace_msg(
    0,
    8u,
    "%s: TDLS: del STA with sta_idx %d",
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    "tdls_process_del_peer_rsp",
    v39);
  peer = tdls_find_peer(v37, v12);
  if ( peer )
  {
    LODWORD(v122) = *(_DWORD *)(peer + 36);
    qdf_trace_msg(
      0,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02x status is %d",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "tdls_process_del_peer_rsp",
      a1[8],
      a1[9],
      a1[10],
      a1[13],
      v122);
    if ( (*(_DWORD *)(peer + 36) & 0xFFFFFFFE) == 4 )
    {
      if ( *(_WORD *)(comp_private_obj + 202) )
        v66 = (unsigned __int16)--*(_WORD *)(comp_private_obj + 202);
      else
        v66 = 0;
      qdf_trace_msg(
        0,
        8u,
        "%s: vdev %d connected peer count %d",
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        "tdls_decrement_peer_count",
        *(unsigned __int8 *)(v26 + 168),
        v66);
      if ( !*(_WORD *)(comp_private_obj + 202) )
      {
        v113 = *(void (__fastcall **)(_QWORD))(comp_private_obj + 616);
        if ( v113 )
        {
          if ( *((_DWORD *)v113 - 1) != 1458356883 )
            __break(0x8228u);
          v113(v26);
        }
      }
      tdls_update_6g_power(v26, comp_private_obj, 0);
      if ( *(_WORD *)(comp_private_obj + 202) == 1 )
        tdls_set_tdls_offchannelmode(v26, 1);
    }
    tdls_reset_peer(v37, v12);
    if ( *(unsigned __int8 *)(peer + 674) >= 3u )
    {
      *(_DWORD *)(peer + 32) = -1;
      qdf_trace_msg(
        0,
        8u,
        "%s: Sta Kickout Threshold reached, set cap to unsupported",
        v114,
        v115,
        v116,
        v117,
        v118,
        v119,
        v120,
        v121,
        "tdls_process_del_peer_rsp");
    }
  }
  else
  {
    tdls_reset_peer(v37, v12);
  }
  *(_WORD *)v40 = 255;
  v40[2] = -1;
  qdf_mem_set(v40 + 3, 6u, 0);
  v27 = 0;
  if ( !peer )
  {
LABEL_20:
    v75 = tdls_find_peer(v37, v12);
    if ( v75 )
    {
      if ( *(_DWORD *)(v75 + 36) == 5 )
        v76 = 0xFFFFFFFFLL;
      else
        v76 = 4294967291LL;
      tdls_set_peer_link_status(v75, 0, v76);
    }
  }
  v124[0] = nullptr;
  v77 = wlan_objmgr_vdev_get_comp_private_obj(v26, 0xAu);
  if ( v77 )
  {
    v78 = 0;
    v79 = v77 + 8;
    while ( (unsigned int)qdf_list_peek_front((_QWORD *)(v79 + 24 * v78), v124) )
    {
LABEL_27:
      if ( ++v78 == 16 )
      {
        qdf_trace_msg(
          0,
          8u,
          "%s: try to set vdev %d to unforce",
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          "tdls_process_unforce_link_mode",
          *(unsigned __int8 *)(v26 + 168));
        tdls_set_link_unforce(v26);
        goto LABEL_37;
      }
    }
    while ( 1 )
    {
      v88 = v124[0];
      if ( v124[0] == (_QWORD *)-24LL )
      {
        v91 = 0;
        v89 = 0;
        v90 = 0;
        v92 = 0;
      }
      else
      {
        v89 = *((unsigned __int8 *)v124[0] + 24);
        v90 = *((unsigned __int8 *)v124[0] + 25);
        v91 = *((unsigned __int8 *)v124[0] + 26);
        v92 = *((unsigned __int8 *)v124[0] + 29);
      }
      LODWORD(v123) = *(unsigned __int8 *)(v26 + 168);
      LODWORD(v122) = *((_DWORD *)v124[0] + 9);
      qdf_trace_msg(
        0,
        8u,
        "%s: Peer: %02x:%02x:%02x:**:**:%02xlink status %d, vdev id %d",
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        "tdls_process_unforce_link_mode",
        v89,
        v90,
        v91,
        v92,
        v122,
        v123);
      if ( (unsigned int)(*((_DWORD *)v88 + 9) - 3) < 2 )
        break;
      if ( (unsigned int)qdf_list_peek_next((_QWORD *)(v79 + 24 * v78), v124[0], v124) )
        goto LABEL_27;
    }
  }
LABEL_37:
  v124[0] = (_QWORD *)0xF00000000LL;
  v124[1] = nullptr;
  v124[2] = (_QWORD *)v26;
  v124[3] = nullptr;
  qdf_trace_msg(
    0,
    8u,
    "%s: release %s",
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    "tdls_release_serialization_command",
    "TDLS_DEL_PEER_CMD");
  wlan_serialization_remove_cmd((unsigned int *)v124, v93, v94, v95, v96, v97, v98, v99, v100);
  wlan_objmgr_vdev_release_ref(v26, 0x10u, v101, v102, v103, v104, v105, v106, v107, v108, v109);
  if ( comp_private_obj )
  {
    v110 = *(_DWORD **)(comp_private_obj + 264);
    if ( v110 )
    {
      v111 = *(_QWORD *)(comp_private_obj + 272);
      v125[0] = v26;
      if ( *(v110 - 1) != 1890320457 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD *))v110)(v111, 4, v125);
    }
  }
LABEL_42:
  _qdf_mem_free((__int64)a1);
  _ReadStatusReg(SP_EL0);
  return v27;
}
