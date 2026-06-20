void __fastcall tdls_add_peer_serialize_callback(
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
  unsigned int *v11; // x8
  __int64 v12; // x19
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 comp_private_obj; // x20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x21
  int v34; // w22
  __int64 peer; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x22
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x4
  __int64 v54; // x5
  const char *v55; // x2
  __int64 v56; // x6
  __int64 v57; // x7
  unsigned int v58; // w1
  int v59; // w0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  void (__fastcall *v68)(__int64, __int64, __int64 *); // x8
  __int64 v69; // x0
  int v70; // [xsp+0h] [xbp-30h]
  __int64 v71; // [xsp+8h] [xbp-28h]
  __int64 v72; // [xsp+10h] [xbp-20h] BYREF
  __int64 v73; // [xsp+18h] [xbp-18h]
  __int64 v74; // [xsp+20h] [xbp-10h]
  unsigned int *v75; // [xsp+28h] [xbp-8h]

  v11 = *(unsigned int **)(_ReadStatusReg(SP_EL0) + 1808);
  v75 = v11;
  if ( !a1 || (v12 = *(_QWORD *)(a1 + 40)) == 0 )
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
      "tdls_add_peer_serialize_callback",
      a1,
      (unsigned int)a2);
    goto LABEL_42;
  }
  if ( a2 <= 1 )
  {
    if ( a2 )
    {
      if ( a2 != 1 )
        goto LABEL_42;
LABEL_10:
      tdls_internal_add_peer_rsp(*(_QWORD *)(a1 + 40));
      goto LABEL_42;
    }
    v73 = 0;
    v74 = 0;
    v72 = 0;
    if ( !*(_QWORD *)v12 )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: vdev null when add tdls peer",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "tdls_activate_add_peer",
        a1);
      goto LABEL_42;
    }
    v13 = *(_QWORD *)(*(_QWORD *)v12 + 216LL);
    if ( v13 && (v14 = *(_QWORD *)(v13 + 80)) != 0 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v14, 0xAu);
    }
    else
    {
      qdf_trace_msg(0, 2u, "%s: can't get psoc", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_get_tdls_soc_obj", a1);
      comp_private_obj = 0;
    }
    if ( *(_QWORD *)v12 )
    {
      v24 = wlan_objmgr_vdev_get_comp_private_obj(*(_QWORD *)v12, 0xAu);
      v33 = v24;
      if ( comp_private_obj && v24 )
      {
        if ( *(_DWORD *)(comp_private_obj + 8) <= 1u )
        {
          qdf_trace_msg(
            0,
            2u,
            "%s: TDLS mode disabled OR not enabled, current mode %d",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "tdls_validate_current_mode");
          v34 = 11;
          goto LABEL_38;
        }
        peer = tdls_get_peer(v24, v12 + 8);
        if ( !peer )
        {
          qdf_trace_msg(
            0,
            2u,
            "%s: peer: %02x:%02x:%02x:**:**:%02x not exist. invalid",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "tdls_activate_add_peer",
            *(unsigned __int8 *)(v12 + 8),
            *(unsigned __int8 *)(v12 + 9),
            *(unsigned __int8 *)(v12 + 10),
            *(unsigned __int8 *)(v12 + 13));
          v34 = 4;
          goto LABEL_38;
        }
        if ( *(_DWORD *)(peer + 36) > 3u || *(_BYTE *)(peer + 30) == 1 )
        {
          qdf_trace_msg(
            0,
            4u,
            "%s: link_status %d add peer ignored",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "tdls_activate_add_peer");
          v34 = 0;
          goto LABEL_38;
        }
        v44 = peer;
        if ( tdls_is_progress(v33, v12 + 8, 1) )
        {
          v53 = *(unsigned __int8 *)(v12 + 8);
          v54 = *(unsigned __int8 *)(v12 + 9);
          v55 = "%s: %02x:%02x:%02x:**:**:%02x TDLS setuping. Req declined.";
          v56 = *(unsigned __int8 *)(v12 + 10);
          v57 = *(unsigned __int8 *)(v12 + 13);
          v58 = 4;
        }
        else
        {
          if ( *(unsigned __int16 *)(comp_private_obj + 200) > (unsigned int)*(unsigned __int16 *)(comp_private_obj + 202) )
          {
            tdls_set_peer_link_status(v44, 3, 0);
            v59 = tdls_pe_add_peer(v12);
            if ( !v59 )
              goto LABEL_42;
            v34 = v59;
            qdf_trace_msg(
              0,
              2u,
              "%s: %02x:%02x:%02x:**:**:%02x add peer failed with status %d",
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              "tdls_activate_add_peer",
              *(unsigned __int8 *)(v12 + 8),
              *(unsigned __int8 *)(v12 + 9),
              *(unsigned __int8 *)(v12 + 10),
              *(unsigned __int8 *)(v12 + 13),
              v59,
              v71,
              v72,
              v73,
              v74,
              v75);
            goto LABEL_37;
          }
          v53 = *(unsigned __int8 *)(v12 + 8);
          v54 = *(unsigned __int8 *)(v12 + 9);
          v56 = *(unsigned __int8 *)(v12 + 10);
          v57 = *(unsigned __int8 *)(v12 + 13);
          v55 = "%s: %02x:%02x:%02x:**:**:%02x Request declined. Current %d, Max allowed %d.";
          LODWORD(v71) = *(unsigned __int16 *)(comp_private_obj + 200);
          v58 = 2;
          v70 = *(unsigned __int16 *)(comp_private_obj + 202);
        }
        qdf_trace_msg(
          0,
          v58,
          v55,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "tdls_activate_add_peer",
          v53,
          v54,
          v56,
          v57,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75);
        v34 = 12;
LABEL_37:
        tdls_set_link_status(v33, v12 + 8, 0, 0xFFFFFFFFLL);
LABEL_38:
        v68 = *(void (__fastcall **)(__int64, __int64, __int64 *))(comp_private_obj + 264);
        if ( v68 )
        {
          LODWORD(v74) = v34;
          v69 = *(_QWORD *)(comp_private_obj + 272);
          v72 = *(_QWORD *)v12;
          if ( *((_DWORD *)v68 - 1) != 1890320457 )
            __break(0x8228u);
          v68(v69, 3, &v72);
        }
        goto LABEL_42;
      }
    }
    else
    {
      qdf_trace_msg(0, 2u, "%s: NULL vdev", v16, v17, v18, v19, v20, v21, v22, v23, "wlan_vdev_get_tdls_vdev_obj");
      v33 = 0;
    }
    qdf_trace_msg(
      0,
      2u,
      "%s: soc_obj: %pK, vdev_obj: %pK",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "tdls_activate_add_peer",
      comp_private_obj,
      v33);
    goto LABEL_42;
  }
  if ( a2 == 2 )
  {
    wlan_objmgr_vdev_release_ref(*(_QWORD *)v12, 0x11u, v11, a3, a4, a5, a6, a7, a8, a9, a10);
    _qdf_mem_free(v12);
    goto LABEL_42;
  }
  if ( a2 == 3 )
    goto LABEL_10;
LABEL_42:
  _ReadStatusReg(SP_EL0);
}
