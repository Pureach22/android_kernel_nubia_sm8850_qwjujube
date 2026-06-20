__int64 __fastcall tdls_implicit_send_discovery_request(
        _QWORD *a1,
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
  __int64 v11; // x8
  __int64 comp_private_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x20
  __int64 v23; // x8
  __int64 v24; // x21
  __int64 v25; // x0
  const char *v26; // x2
  const char *v27; // x2
  unsigned int v28; // w1
  __int64 result; // x0
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
  void (__fastcall *v66)(__int64, __int64, __int64 *); // x8
  __int64 v67; // x0
  __int64 v68; // x2
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // [xsp+0h] [xbp-20h] BYREF
  __int64 v78; // [xsp+8h] [xbp-18h] BYREF
  __int64 v79; // [xsp+10h] [xbp-10h]
  __int64 v80; // [xsp+18h] [xbp-8h]

  v80 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *a1;
  v78 = 0;
  v79 = 0;
  v77 = 0;
  if ( !v9 )
  {
    v26 = "%s: NULL vdev";
    goto LABEL_10;
  }
  v10 = *(_QWORD *)(v9 + 152);
  if ( !v10 || (v11 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v26 = "%s: can't get psoc";
LABEL_10:
    qdf_trace_msg(0, 2u, v26, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_vdev_get_tdls_soc_obj", v77, v78, v79, v80);
    goto LABEL_11;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v11, 0xAu);
  if ( !comp_private_obj )
  {
LABEL_11:
    v27 = "%s: tdls_psoc_obj is NULL";
    v28 = 4;
LABEL_12:
    result = qdf_trace_msg(
               0,
               v28,
               v27,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               "tdls_implicit_send_discovery_request",
               v77);
    goto LABEL_13;
  }
  v22 = a1[97];
  if ( !v22 )
  {
    v27 = "%s: curr_peer is NULL";
    v28 = 2;
    goto LABEL_12;
  }
  v23 = *(_QWORD *)(*a1 + 152LL);
  v24 = comp_private_obj;
  if ( v23 )
    v25 = *(_QWORD *)(v23 + 80);
  else
    v25 = 0;
  peer_by_mac = wlan_objmgr_get_peer_by_mac(v25, (_BYTE *)(v22 + 24), 0x11u);
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
      *(unsigned __int8 *)(peer_by_mac[11] + 104LL),
      v77,
      v78,
      v79,
      v80);
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
                 v77,
                 v78,
                 v79,
                 v80);
    }
    else
    {
      if ( *(_DWORD *)(v22 + 32) != -1 )
        tdls_set_peer_link_status(v22, 1, 0);
      qdf_mem_copy((char *)&v78 + 2, (const void *)(v22 + 24), 6u);
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
        v78,
        v79,
        v80);
      v66 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v24 + 264);
      v65 = *(_QWORD *)(v24 + 272);
      if ( *((_DWORD *)v66 - 1) != 1890320457 )
        __break(0x8228u);
      v66(v65, 5, &v77);
      v67 = *a1;
      v68 = (unsigned int)(*((_DWORD *)a1 + 183) - 1000);
      ++*((_DWORD *)a1 + 192);
      tdls_timer_restart(v67, a1 + 70, v68);
      result = qdf_trace_msg(
                 0,
                 8u,
                 "%s: discovery count %u timeout %u msec",
                 v69,
                 v70,
                 v71,
                 v72,
                 v73,
                 v74,
                 v75,
                 v76,
                 "tdls_implicit_send_discovery_request",
                 *((unsigned int *)a1 + 192),
                 (unsigned int)(*((_DWORD *)a1 + 183) - 1000));
    }
  }
  a1[97] = 0;
  *((_DWORD *)a1 + 241) = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
