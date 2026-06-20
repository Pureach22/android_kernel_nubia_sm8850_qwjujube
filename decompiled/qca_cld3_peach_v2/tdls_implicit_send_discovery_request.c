__int64 __fastcall tdls_implicit_send_discovery_request(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v12; // x0
  __int64 comp_private_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  __int64 result; // x0
  const char *v24; // x2
  const char *v25; // x2
  unsigned int v26; // w1
  __int64 v27; // x20
  __int64 v28; // x8
  __int64 v29; // x0
  _QWORD *peer_by_mac; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x20
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned __int8 *is_progress; // x0
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
  __int64 v65; // x0
  double (__fastcall *v66)(__int64, __int64, __int64 *); // x8
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
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // [xsp+0h] [xbp-20h] BYREF
  __int64 v86; // [xsp+8h] [xbp-18h] BYREF
  __int64 v87; // [xsp+10h] [xbp-10h]
  __int64 v88; // [xsp+18h] [xbp-8h]

  v88 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *a1;
  v86 = 0;
  v87 = 0;
  v85 = 0;
  if ( !v9 )
  {
    v24 = "%s: NULL vdev";
    goto LABEL_9;
  }
  v10 = *(_QWORD *)(v9 + 216);
  if ( !v10 || (v12 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v24 = "%s: can't get psoc";
LABEL_9:
    qdf_trace_msg(0, 2u, v24, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_vdev_get_tdls_soc_obj", v85, v86, v87, v88);
    goto LABEL_10;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v12, 0xAu);
  if ( !comp_private_obj )
  {
LABEL_10:
    v25 = "%s: tdls_psoc_obj is NULL";
    v26 = 4;
LABEL_11:
    result = qdf_trace_msg(
               0,
               v26,
               v25,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               "tdls_implicit_send_discovery_request",
               v85);
    goto LABEL_12;
  }
  v22 = comp_private_obj;
  if ( (mlo_mgr_is_link_switch_in_progress(*a1) & 1) != 0 )
  {
    result = qdf_trace_msg(
               0,
               4u,
               "%s: vdev:%d Link Switch in progress. TDLS discovery not allowed",
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               "tdls_implicit_send_discovery_request",
               *(unsigned __int8 *)(*a1 + 168),
               v85,
               v86,
               v87,
               v88);
    goto LABEL_12;
  }
  v27 = a1[97];
  if ( !v27 )
  {
    v25 = "%s: curr_peer is NULL";
    v26 = 2;
    goto LABEL_11;
  }
  v28 = *(_QWORD *)(*a1 + 216);
  if ( v28 )
    v29 = *(_QWORD *)(v28 + 80);
  else
    v29 = 0;
  peer_by_mac = wlan_objmgr_get_peer_by_mac(v29, (_BYTE *)(v27 + 24), 0x11u);
  if ( peer_by_mac )
  {
    v39 = (__int64)peer_by_mac;
    qdf_trace_msg(
      0,
      4u,
      "%s: Peer (type = %d) exists on vdev:%d, don't initiate discovery",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "tdls_implicit_send_discovery_request",
      *((unsigned int *)peer_by_mac + 17),
      *(unsigned __int8 *)(peer_by_mac[12] + 168LL),
      v85,
      v86,
      v87,
      v88);
    result = wlan_objmgr_peer_release_ref(v39, 0x11u, v40, v41, v42, v43, v44, v45, v46, v47);
  }
  else
  {
    is_progress = (unsigned __int8 *)tdls_is_progress(a1, 0, 0);
    if ( is_progress )
    {
      result = qdf_trace_msg(
                 0,
                 4u,
                 "%s: %02x:%02x:%02x:**:**:%02x ongoing. pre_setup ignored",
                 v49,
                 v50,
                 v51,
                 v52,
                 v53,
                 v54,
                 v55,
                 v56,
                 "tdls_implicit_send_discovery_request",
                 is_progress[24],
                 is_progress[25],
                 is_progress[26],
                 is_progress[29],
                 v85,
                 v86,
                 v87,
                 v88);
    }
    else
    {
      if ( *(_DWORD *)(v27 + 32) != -1 )
        tdls_set_peer_link_status(v27, 1, 0);
      qdf_mem_copy((char *)&v86 + 2, (const void *)(v27 + 24), 6u);
      qdf_trace_msg(
        0,
        8u,
        "%s: Implicit TDLS, Send Discovery request event",
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        "tdls_implicit_send_discovery_request",
        *a1,
        v86,
        v87,
        v88);
      v66 = *(double (__fastcall **)(__int64, __int64, __int64 *))(v22 + 264);
      v65 = *(_QWORD *)(v22 + 272);
      if ( *((_DWORD *)v66 - 1) != 1890320457 )
        __break(0x8228u);
      v67 = v66(v65, 5, &v85);
      result = wlan_vdev_mlme_is_mlo_vdev(*a1, v67, v68, v69, v70, v71, v72, v73, v74);
      if ( (result & 1) == 0 )
      {
        v75 = *a1;
        v76 = (unsigned int)(*((_DWORD *)a1 + 183) - 1000);
        ++*((_DWORD *)a1 + 192);
        tdls_timer_restart(v75, a1 + 70, v76);
        result = qdf_trace_msg(
                   0,
                   8u,
                   "%s: discovery count %u timeout %u msec",
                   v77,
                   v78,
                   v79,
                   v80,
                   v81,
                   v82,
                   v83,
                   v84,
                   "tdls_implicit_send_discovery_request",
                   *((unsigned int *)a1 + 192),
                   (unsigned int)(*((_DWORD *)a1 + 183) - 1000));
      }
    }
  }
  a1[97] = 0;
  *((_DWORD *)a1 + 241) = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
