__int64 __fastcall tdls_vdev_obj_create_notification(
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
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 comp_private_obj; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w22
  const char *v30; // x2
  const char *v31; // x2
  unsigned int v32; // w0
  unsigned int v33; // w1
  __int64 (__fastcall *v35)(_QWORD); // x8
  __int64 v36; // x20
  __int64 v37; // x21
  unsigned int v38; // w0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x8
  __int64 v48; // x0
  _DWORD *v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x3
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x1
  void (__fastcall *v68)(_QWORD); // x8

  qdf_trace_msg(
    0,
    8u,
    "%s: tdls vdev mode %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "tdls_vdev_obj_create_notification",
    *(unsigned int *)(a1 + 16));
  if ( (*(_DWORD *)(a1 + 16) | 2) != 2 )
    return 0;
  if ( !a1 )
  {
    v30 = "%s: NULL vdev";
    goto LABEL_11;
  }
  v18 = *(_QWORD *)(a1 + 216);
  if ( !v18 || (v19 = *(_QWORD *)(v18 + 80)) == 0 )
  {
    v30 = "%s: can't get psoc";
LABEL_11:
    qdf_trace_msg(0, 2u, v30, v10, v11, v12, v13, v14, v15, v16, v17, "wlan_vdev_get_tdls_soc_obj");
    goto LABEL_12;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v19, 0xAu);
  if ( !comp_private_obj )
  {
LABEL_12:
    v31 = "%s: get soc by vdev failed";
    v32 = 0;
    v33 = 2;
    v29 = 2;
    goto LABEL_13;
  }
  if ( (*(_BYTE *)(comp_private_obj + 156) & 0x20) == 0 )
  {
    qdf_trace_msg(
      0,
      8u,
      "%s: disabled in ini",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "tdls_vdev_obj_create_notification");
    return 11;
  }
  v35 = *(__int64 (__fastcall **)(_QWORD))(comp_private_obj + 592);
  v36 = comp_private_obj;
  if ( !v35 )
    goto LABEL_19;
  if ( *((_DWORD *)v35 - 1) != 1263140689 )
    __break(0x8228u);
  v29 = v35(a1);
  if ( !v29 )
  {
LABEL_19:
    v37 = _qdf_mem_malloc(0x410u, "tdls_vdev_obj_create_notification", 268);
    if ( !v37 )
    {
      v29 = 2;
      goto LABEL_33;
    }
    v38 = wlan_objmgr_vdev_component_obj_attach(a1, 0xAu, v37, 0);
    if ( v38 )
    {
      v29 = v38;
      qdf_trace_msg(
        0,
        2u,
        "%s: Failed to attach vdev tdls component",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "tdls_vdev_obj_create_notification");
LABEL_33:
      v68 = *(void (__fastcall **)(_QWORD))(v36 + 600);
      if ( v68 )
      {
        if ( *((_DWORD *)v68 - 1) != 1458356883 )
          __break(0x8228u);
        v68(a1);
      }
      if ( v37 )
        _qdf_mem_free(v37);
      return v29;
    }
    *(_QWORD *)v37 = a1;
    v47 = *(_QWORD *)(a1 + 216);
    if ( v47 && (v48 = *(_QWORD *)(v47 + 80)) != 0 )
    {
      v49 = (_DWORD *)wlan_objmgr_psoc_get_comp_private_obj(v48, 0xAu);
      if ( v49 )
      {
        *(_DWORD *)(v37 + 732) = v49[26];
        *(_DWORD *)(v37 + 736) = v49[27];
        *(_DWORD *)(v37 + 740) = v49[29];
        *(_DWORD *)(v37 + 744) = v49[30];
        *(_DWORD *)(v37 + 748) = v49[31];
        *(_DWORD *)(v37 + 752) = v49[32];
        *(_DWORD *)(v37 + 756) = v49[33];
        *(_DWORD *)(v37 + 760) = v49[34];
        *(_QWORD *)(v37 + 8) = v37 + 8;
        *(_QWORD *)(v37 + 16) = v37 + 8;
        *(_QWORD *)(v37 + 24) = 0xA00000000LL;
        *(_QWORD *)(v37 + 32) = v37 + 32;
        *(_QWORD *)(v37 + 40) = v37 + 32;
        *(_QWORD *)(v37 + 48) = 0xA00000000LL;
        *(_QWORD *)(v37 + 56) = v37 + 56;
        *(_QWORD *)(v37 + 64) = v37 + 56;
        *(_QWORD *)(v37 + 72) = 0xA00000000LL;
        *(_QWORD *)(v37 + 80) = v37 + 80;
        *(_QWORD *)(v37 + 88) = v37 + 80;
        *(_QWORD *)(v37 + 96) = 0xA00000000LL;
        *(_QWORD *)(v37 + 104) = v37 + 104;
        *(_QWORD *)(v37 + 112) = v37 + 104;
        *(_QWORD *)(v37 + 120) = 0xA00000000LL;
        *(_QWORD *)(v37 + 128) = v37 + 128;
        *(_QWORD *)(v37 + 136) = v37 + 128;
        *(_QWORD *)(v37 + 144) = 0xA00000000LL;
        *(_QWORD *)(v37 + 152) = v37 + 152;
        *(_QWORD *)(v37 + 160) = v37 + 152;
        *(_QWORD *)(v37 + 168) = 0xA00000000LL;
        *(_QWORD *)(v37 + 176) = v37 + 176;
        *(_QWORD *)(v37 + 184) = v37 + 176;
        *(_QWORD *)(v37 + 192) = 0xA00000000LL;
        *(_QWORD *)(v37 + 200) = v37 + 200;
        *(_QWORD *)(v37 + 208) = v37 + 200;
        *(_QWORD *)(v37 + 216) = 0xA00000000LL;
        *(_QWORD *)(v37 + 224) = v37 + 224;
        *(_QWORD *)(v37 + 232) = v37 + 224;
        *(_QWORD *)(v37 + 240) = 0xA00000000LL;
        *(_QWORD *)(v37 + 248) = v37 + 248;
        *(_QWORD *)(v37 + 256) = v37 + 248;
        *(_QWORD *)(v37 + 264) = 0xA00000000LL;
        *(_QWORD *)(v37 + 272) = v37 + 272;
        *(_QWORD *)(v37 + 280) = v37 + 272;
        *(_QWORD *)(v37 + 288) = 0xA00000000LL;
        *(_QWORD *)(v37 + 296) = v37 + 296;
        *(_QWORD *)(v37 + 304) = v37 + 296;
        *(_QWORD *)(v37 + 312) = 0xA00000000LL;
        *(_QWORD *)(v37 + 320) = v37 + 320;
        *(_QWORD *)(v37 + 328) = v37 + 320;
        *(_QWORD *)(v37 + 336) = 0xA00000000LL;
        *(_QWORD *)(v37 + 344) = v37 + 344;
        *(_QWORD *)(v37 + 352) = v37 + 344;
        *(_QWORD *)(v37 + 360) = 0xA00000000LL;
        *(_QWORD *)(v37 + 368) = v37 + 368;
        *(_QWORD *)(v37 + 376) = v37 + 368;
        v58 = *(_QWORD *)v37;
        *(_QWORD *)(v37 + 384) = 0xA00000000LL;
        qdf_mc_timer_init(v37 + 392, 0, (__int64)tdls_ct_handler, v58);
        qdf_mc_timer_init(v37 + 560, 0, (__int64)tdls_discovery_timeout_peer_cb, *(_QWORD *)v37);
        *(_QWORD *)(v37 + 952) = 0;
        v29 = qdf_event_create((_DWORD *)(v37 + 1000));
        if ( v29 )
        {
LABEL_29:
          tdls_vdev_deinit(v37);
LABEL_32:
          wlan_objmgr_vdev_component_obj_detach(a1, 0xAu, v37);
          goto LABEL_33;
        }
        v32 = ucfg_scan_register_event_handler(
                *(_QWORD *)(a1 + 216),
                (__int64)tdls_scan_complete_event_handler,
                v36,
                v59,
                v60,
                v61,
                v62,
                v63,
                v64,
                v65,
                v66);
        v29 = v32;
        if ( v32 )
        {
          qdf_trace_msg(
            0,
            2u,
            "%s: scan event register failed ",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "tdls_vdev_obj_create_notification");
          qdf_event_destroy(v37 + 1000, v67);
          goto LABEL_29;
        }
        v31 = "%s: tdls object attach to vdev successfully";
        v33 = 8;
LABEL_13:
        qdf_trace_msg(v32, v33, v31, v21, v22, v23, v24, v25, v26, v27, v28, "tdls_vdev_obj_create_notification");
        return v29;
      }
    }
    else
    {
      qdf_trace_msg(0, 2u, "%s: can't get psoc", v39, v40, v41, v42, v43, v44, v45, v46, "wlan_vdev_get_tdls_soc_obj");
    }
    qdf_trace_msg(0, 2u, "%s: tdls soc obj NULL", v50, v51, v52, v53, v54, v55, v56, v57, "tdls_vdev_init");
    v29 = 16;
    goto LABEL_32;
  }
  return v29;
}
