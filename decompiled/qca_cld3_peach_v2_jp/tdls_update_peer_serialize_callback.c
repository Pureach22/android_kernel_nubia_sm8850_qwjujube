void __fastcall tdls_update_peer_serialize_callback(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *v11; // x8
  __int64 v12; // x19
  unsigned __int8 *v13; // x23
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 comp_private_obj; // x20
  __int64 v17; // x19
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x21
  int v28; // w22
  void (__fastcall *v29)(__int64, __int64, __int64 *); // x8
  __int64 peer; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  int v39; // w8
  __int64 v40; // x0
  __int64 v41; // x22
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x4
  __int64 v52; // x5
  const char *v53; // x2
  __int64 v54; // x6
  __int64 v55; // x7
  unsigned int v56; // w1
  int updated; // w0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  int v66; // [xsp+0h] [xbp-30h]
  __int64 v67; // [xsp+8h] [xbp-28h]
  __int64 v68; // [xsp+10h] [xbp-20h] BYREF
  __int64 v69; // [xsp+18h] [xbp-18h]
  __int64 v70; // [xsp+20h] [xbp-10h]
  __int64 v71; // [xsp+28h] [xbp-8h]

  v71 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || (v11 = *(__int64 **)(a1 + 40)) == nullptr )
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: cmd: %pK, reason: %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tdls_update_peer_serialize_callback",
      a1,
      (unsigned int)a2);
    goto LABEL_37;
  }
  if ( a2 > 1 )
  {
    if ( a2 == 2 )
    {
      v17 = *(_QWORD *)(a1 + 40);
      wlan_objmgr_vdev_release_ref(*v11, 0x11u, (unsigned int *)v11, a3, a4, a5, a6, a7, a8, a9, a10);
      _qdf_mem_free(v17);
      goto LABEL_37;
    }
    if ( a2 == 3 )
      goto LABEL_10;
  }
  else
  {
    if ( a2 )
    {
      if ( a2 != 1 )
        goto LABEL_37;
LABEL_10:
      tdls_internal_update_peer_rsp(*(_QWORD *)(a1 + 40));
      goto LABEL_37;
    }
    v69 = 0;
    v70 = 0;
    v68 = 0;
    v12 = *v11;
    if ( !*v11 )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: vdev object NULL when add TDLS peer",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "tdls_activate_update_peer",
        a1);
      goto LABEL_37;
    }
    v13 = (unsigned __int8 *)v11;
    v14 = *(_QWORD *)(v12 + 152);
    if ( v14 && (v15 = *(_QWORD *)(v14 + 80)) != 0 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v15, 0xAu);
    }
    else
    {
      qdf_trace_msg(0, 2u, "%s: can't get psoc", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_get_tdls_soc_obj", a1);
      comp_private_obj = 0;
    }
    v18 = wlan_objmgr_vdev_get_comp_private_obj(v12, 0xAu);
    v27 = v18;
    if ( !comp_private_obj || !v18 )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: soc_obj: %pK, vdev_obj: %pK",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "tdls_activate_update_peer",
        comp_private_obj,
        v18);
      goto LABEL_37;
    }
    if ( *(_DWORD *)(comp_private_obj + 8) <= 1u )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: TDLS mode disabled OR not enabled, current mode %d",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "tdls_validate_current_mode");
      v28 = 11;
      v29 = *(void (__fastcall **)(__int64, __int64, __int64 *))(comp_private_obj + 264);
      if ( !v29 )
        goto LABEL_37;
      goto LABEL_34;
    }
    peer = tdls_find_peer(v18, v13 + 8);
    if ( !peer )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: %02x:%02x:%02x:**:**:%02x not exist. return invalid",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "tdls_activate_update_peer",
        v13[8],
        v13[9],
        v13[10],
        v13[13]);
      v28 = 4;
      v29 = *(void (__fastcall **)(__int64, __int64, __int64 *))(comp_private_obj + 264);
      if ( !v29 )
        goto LABEL_37;
      goto LABEL_34;
    }
    v39 = *(_DWORD *)(peer + 36);
    if ( v39 == 5 || (*(_BYTE *)(peer + 30) & 1) == 0 )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: %02x:%02x:%02x:**:**:%02x link %d. update peer rejected",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "tdls_activate_update_peer",
        v13[8],
        v13[9],
        v13[10],
        v13[13],
        *(_DWORD *)(peer + 36),
        v67,
        v68,
        v69,
        v70,
        v71);
      v28 = 12;
      v29 = *(void (__fastcall **)(__int64, __int64, __int64 *))(comp_private_obj + 264);
      if ( !v29 )
        goto LABEL_37;
      goto LABEL_34;
    }
    if ( v39 == 4 )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: %02x:%02x:%02x:**:**:%02x link %d. update peer is igonored as tdls state is already connected ",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "tdls_activate_update_peer",
        v13[8],
        v13[9],
        v13[10],
        v13[13],
        4,
        v67,
        v68,
        v69,
        v70,
        v71);
      v28 = 0;
      v29 = *(void (__fastcall **)(__int64, __int64, __int64 *))(comp_private_obj + 264);
      if ( !v29 )
        goto LABEL_37;
      goto LABEL_34;
    }
    v41 = peer;
    if ( tdls_is_progress(v27, v13 + 8, 1) )
    {
      v51 = v13[8];
      v52 = v13[9];
      v53 = "%s: %02x:%02x:%02x:**:**:%02x TDLS setuping. Req declined.";
      v54 = v13[10];
      v55 = v13[13];
      v56 = 4;
LABEL_46:
      qdf_trace_msg(
        0,
        v56,
        v53,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "tdls_activate_update_peer",
        v51,
        v52,
        v54,
        v55,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71);
      v28 = 12;
LABEL_47:
      tdls_set_link_status(v27, v13 + 8, 0, 0xFFFFFFFFLL);
      v29 = *(void (__fastcall **)(__int64, __int64, __int64 *))(comp_private_obj + 264);
      if ( !v29 )
        goto LABEL_37;
LABEL_34:
      v40 = *(_QWORD *)(comp_private_obj + 272);
      LODWORD(v70) = v28;
      v68 = v12;
      if ( *((_DWORD *)v29 - 1) != 1890320457 )
        __break(0x8228u);
      v29(v40, 3, &v68);
      goto LABEL_37;
    }
    if ( *(unsigned __int16 *)(comp_private_obj + 200) <= (unsigned int)*(unsigned __int16 *)(comp_private_obj + 202) )
    {
      v51 = v13[8];
      v52 = v13[9];
      v54 = v13[10];
      v55 = v13[13];
      v53 = "%s: %02x:%02x:%02x:**:**:%02x Request declined. Current: %d, Max allowed: %d.";
      LODWORD(v67) = *(unsigned __int16 *)(comp_private_obj + 200);
      v56 = 2;
      v66 = *(unsigned __int16 *)(comp_private_obj + 202);
      goto LABEL_46;
    }
    if ( v13[67] )
      *(_BYTE *)(v41 + 673) = v13[72];
    tdls_set_peer_caps(v27, v13 + 8, v13 + 8);
    updated = tdls_pe_update_peer(v13);
    if ( updated )
    {
      v28 = updated;
      qdf_trace_msg(
        0,
        2u,
        "%s: %02x:%02x:%02x:**:**:%02x update peer failed with status %d",
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        "tdls_activate_update_peer",
        v13[8],
        v13[9],
        v13[10],
        v13[13],
        updated,
        v67,
        v68,
        v69,
        v70,
        v71);
      goto LABEL_47;
    }
  }
LABEL_37:
  _ReadStatusReg(SP_EL0);
}
