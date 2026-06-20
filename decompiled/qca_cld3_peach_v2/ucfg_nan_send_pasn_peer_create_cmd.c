__int64 __fastcall ucfg_nan_send_pasn_peer_create_cmd(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  char v13; // w20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  _QWORD *peer_by_mac; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x19
  unsigned int v49; // w20
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  void *v58; // x0
  __int64 v59; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x20
  __int64 comp_private_obj; // x0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned int v78; // w0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  unsigned int v87; // w19
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  unsigned int v112; // w0
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  __int64 v129; // [xsp+0h] [xbp-50h] BYREF
  void *v130; // [xsp+8h] [xbp-48h]
  __int64 (__fastcall *v131)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+10h] [xbp-40h]
  __int64 (__fastcall *v132)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-38h]
  __int64 v133; // [xsp+20h] [xbp-30h]
  __int64 v134; // [xsp+28h] [xbp-28h]
  __int64 v135; // [xsp+30h] [xbp-20h] BYREF
  __int64 v136; // [xsp+38h] [xbp-18h]
  int v137; // [xsp+40h] [xbp-10h] BYREF
  __int16 v138; // [xsp+44h] [xbp-Ch]
  __int64 v139; // [xsp+48h] [xbp-8h]

  v139 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_BYTE *)(a2 + 168);
  v137 = a3;
  v138 = WORD2(a3);
  v133 = 0;
  v134 = 0;
  v131 = nullptr;
  v132 = nullptr;
  v129 = 0;
  v130 = nullptr;
  v136 = 0;
  if ( (nan_is_pairing_allowed(a1, a4, a5, a6, a7, a8, a9, a10, a11) & 1) == 0 )
  {
    qdf_trace_msg(
      0x53u,
      8u,
      "%s: NAN Pairing is not supported",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "ucfg_nan_send_pasn_peer_create_cmd",
      v129,
      v130,
      v131,
      v132,
      v133,
      v134);
    goto LABEL_5;
  }
  if ( ((unsigned __int8)nan_is_peer_exist_for_opmode(a1, (__int64)&v137, 11) & 1) != 0 )
  {
    qdf_trace_msg(
      0x53u,
      8u,
      "%s: NDI peer exist with same mac address%02x:%02x:%02x:**:**:%02x",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "ucfg_nan_send_pasn_peer_create_cmd",
      (unsigned __int8)v137,
      BYTE1(v137),
      BYTE2(v137),
      HIBYTE(v138),
      v129,
      v130,
      v131,
      v132,
      v133,
      v134);
LABEL_5:
    result = 0;
    goto LABEL_6;
  }
  if ( ((unsigned __int8)nan_is_peer_exist_for_opmode(a1, (__int64)&v137, 16) & 1) == 0 )
  {
    v135 = a1;
    LODWORD(v136) = v137;
    WORD2(v136) = v138;
    BYTE6(v136) = v13;
    v58 = (void *)_qdf_mem_malloc(0x10u, "ucfg_nan_send_pasn_peer_create_cmd", 1612);
    v130 = v58;
    if ( !v58 )
    {
      result = 2;
      goto LABEL_6;
    }
    qdf_mem_copy(v58, &v135, 0x10u);
    LOWORD(v129) = 0;
    v131 = nan_pasn_scheduled_handler;
    v132 = nan_pasn_flush_callback;
    v59 = osif_request_alloc(ucfg_nan_send_pasn_peer_create_cmd_req_params);
    if ( !v59 )
    {
      qdf_trace_msg(
        0x53u,
        2u,
        "%s: Request allocation failure",
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "ucfg_nan_send_pasn_peer_create_cmd",
        v129,
        v130,
        v131,
        v132,
        v133,
        v134,
        v135,
        v136);
      nan_pasn_flush_callback((unsigned __int16 *)&v129, v96, v97, v98, v99, v100, v101, v102, v103);
      result = 2;
      goto LABEL_6;
    }
    v68 = v59;
    if ( a1 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
      if ( comp_private_obj )
      {
        *(_QWORD *)(comp_private_obj + 304) = osif_request_cookie(v68);
        v78 = scheduler_post_message_debug(
                0x53u,
                0x53u,
                72,
                (unsigned __int16 *)&v129,
                0x669u,
                (__int64)"ucfg_nan_send_pasn_peer_create_cmd");
        if ( v78 )
        {
          v87 = v78;
          qdf_trace_msg(
            0x53u,
            2u,
            "%s: failed to post msg to NAN component, status: %d",
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            v86,
            "ucfg_nan_send_pasn_peer_create_cmd",
            v129,
            v130,
            v131,
            v132,
            v133,
            v134,
            v135,
            v136);
          nan_pasn_flush_callback((unsigned __int16 *)&v129, v88, v89, v90, v91, v92, v93, v94, v95);
        }
        else
        {
          v112 = osif_request_wait_for_response(v68);
          if ( v112 )
          {
            v87 = v112;
            qdf_trace_msg(
              0x53u,
              2u,
              "%s: NAN request timed out %d",
              v113,
              v114,
              v115,
              v116,
              v117,
              v118,
              v119,
              v120,
              "ucfg_nan_send_pasn_peer_create_cmd",
              v129,
              v130,
              v131,
              v132,
              v133,
              v134,
              v135,
              v136);
          }
          else
          {
            nan_update_pasn_peer_count(a2, 1, v113, v114, v115, v116, v117, v118, v119, v120);
            qdf_trace_msg(
              0x53u,
              8u,
              "%s: peer created successfully",
              v121,
              v122,
              v123,
              v124,
              v125,
              v126,
              v127,
              v128,
              "ucfg_nan_send_pasn_peer_create_cmd",
              v129,
              v130,
              v131,
              v132,
              v133,
              v134,
              v135,
              v136);
            v87 = 0;
          }
        }
        goto LABEL_21;
      }
    }
    else
    {
      qdf_trace_msg(
        0x53u,
        2u,
        "%s: psoc is null",
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "nan_get_psoc_priv_obj",
        v129,
        v130,
        v131,
        v132,
        v133,
        v134,
        v135,
        v136);
    }
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: psoc_nan_obj is null",
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      "ucfg_nan_send_pasn_peer_create_cmd",
      v129);
    nan_pasn_flush_callback((unsigned __int16 *)&v129, v104, v105, v106, v107, v108, v109, v110, v111);
    v87 = 29;
LABEL_21:
    osif_request_put(v68);
    result = v87;
    goto LABEL_6;
  }
  qdf_trace_msg(
    0x53u,
    8u,
    "%s: NAN peer exist with same mac address%02x:%02x:%02x:**:**:%02x",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "ucfg_nan_send_pasn_peer_create_cmd",
    (unsigned __int8)v137,
    BYTE1(v137),
    BYTE2(v137),
    HIBYTE(v138),
    v129,
    v130,
    v131,
    v132,
    v133,
    v134);
  peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, &v137, 0x14u);
  if ( peer_by_mac )
  {
    v48 = (__int64)peer_by_mac;
    v49 = wlan_mlme_clear_peer_private_object_data((__int64)peer_by_mac);
    wlan_objmgr_peer_release_ref(v48, 0x14u, v50, v51, v52, v53, v54, v55, v56, v57);
    result = v49;
  }
  else
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: peer is null",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "ucfg_nan_send_pasn_peer_create_cmd");
    result = 29;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
