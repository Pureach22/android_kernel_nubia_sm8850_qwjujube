__int64 __fastcall tdls_send_mgmt_serialize_callback(
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
  _QWORD *v12; // x19
  __int64 result; // x0
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x0
  void (__fastcall *v17)(__int64, __int64, __int64 *); // x8
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 comp_private_obj; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  __int64 v31; // x0
  __int64 v32; // x21
  __int64 bsspeer; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x22
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int16 v59; // w8
  unsigned int v60; // w22
  int v61; // w8
  __int64 tdls_vdev_obj; // x22
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int16 v80; // w8
  unsigned int v81; // w0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  __int64 v98; // x8
  __int64 v99; // x9
  __int64 v100; // x0
  __int64 v101; // x0
  _DWORD *v102; // x8
  __int64 v103; // x0
  unsigned int v109; // w9
  __int64 v110; // [xsp+10h] [xbp-50h] BYREF
  __int64 v111; // [xsp+18h] [xbp-48h]
  __int64 v112; // [xsp+20h] [xbp-40h]
  __int64 (__fastcall *v113)(); // [xsp+28h] [xbp-38h]
  __int64 v114; // [xsp+30h] [xbp-30h]
  __int64 v115; // [xsp+38h] [xbp-28h]
  _QWORD v116[2]; // [xsp+40h] [xbp-20h] BYREF
  unsigned int v117; // [xsp+50h] [xbp-10h]
  int v118; // [xsp+54h] [xbp-Ch]
  unsigned int *v119; // [xsp+58h] [xbp-8h]

  v11 = *(unsigned int **)(_ReadStatusReg(SP_EL0) + 1808);
  v119 = v11;
  if ( !a1 || (v12 = *(_QWORD **)(a1 + 40)) == nullptr )
  {
    qdf_trace_msg(
      0,
      2u,
      "%s: invalid params cmd: %pK, ",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tdls_send_mgmt_serialize_callback",
      a1);
    result = 29;
    goto LABEL_57;
  }
  result = 4;
  if ( a2 <= 1 )
  {
    if ( a2 )
    {
      if ( a2 != 1 )
        goto LABEL_57;
      goto LABEL_10;
    }
    v114 = 0;
    v115 = 0;
    v112 = 0;
    v113 = nullptr;
    v110 = 0;
    v111 = 0;
    if ( !*v12 )
      goto LABEL_26;
    v19 = *(_QWORD *)(*v12 + 216LL);
    if ( v19 && (v20 = *(_QWORD *)(v19 + 80)) != 0 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v20, 0xAu);
      if ( comp_private_obj )
      {
        v30 = comp_private_obj;
        v31 = _qdf_mem_malloc(*((unsigned __int8 *)v12 + 76) + 36LL, "tdls_activate_send_mgmt_request", 705);
        if ( v31 )
        {
          v32 = v31;
          qdf_trace_msg(
            0,
            8u,
            "%s: session_id %d tdls_mgmt.dialog %d tdls_mgmt.frame_type %d tdls_mgmt.status_code %d tdls_mgmt.responder %"
            "d tdls_mgmt.peer_capability %d",
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            "tdls_activate_send_mgmt_request",
            *((unsigned __int8 *)v12 + 40),
            *((unsigned __int8 *)v12 + 67),
            *((unsigned __int8 *)v12 + 66),
            *((unsigned __int16 *)v12 + 34),
            *((unsigned __int8 *)v12 + 70),
            *((_DWORD *)v12 + 18),
            v110,
            v111,
            v112,
            v113,
            v114,
            v115);
          *(_BYTE *)(v32 + 4) = *((_BYTE *)v12 + 40);
          *(_BYTE *)(v32 + 5) = *((_BYTE *)v12 + 66);
          *(_BYTE *)(v32 + 6) = *((_BYTE *)v12 + 67);
          *(_WORD *)(v32 + 8) = *((_WORD *)v12 + 34);
          *(_BYTE *)(v32 + 10) = *((_BYTE *)v12 + 70);
          *(_DWORD *)(v32 + 12) = *((_DWORD *)v12 + 18);
          bsspeer = wlan_objmgr_vdev_try_get_bsspeer(*v12, 0x10u);
          if ( bsspeer )
          {
            v42 = bsspeer;
            qdf_mem_copy((void *)(v32 + 16), (const void *)(bsspeer + 48), 6u);
            wlan_objmgr_peer_release_ref(v42, 0x10u, v43, v44, v45, v46, v47, v48, v49, v50);
            qdf_mem_copy((void *)(v32 + 22), (char *)v12 + 60, 6u);
            if ( *((_BYTE *)v12 + 76) )
            {
              qdf_mem_copy((void *)(v32 + 32), (char *)v12 + 77, *((unsigned __int8 *)v12 + 76));
              v59 = *((unsigned __int8 *)v12 + 76);
            }
            else
            {
              v59 = 0;
            }
            *(_WORD *)(v32 + 2) = v59 + 36;
            if ( *((_BYTE *)v12 + 57) )
              v61 = 1;
            else
              v61 = 3;
            *(_DWORD *)(v32 + 28) = v61;
            if ( (wlan_vdev_mlme_is_mlo_vdev(*v12, v51, v52, v53, v54, v55, v56, v57, v58) & 1) == 0
              || wlan_mlo_get_tdls_link_vdev(*v12)
              || *(_BYTE *)(v32 + 5) != 10 )
            {
              goto LABEL_44;
            }
            tdls_vdev_obj = wlan_vdev_get_tdls_vdev_obj(*v12);
            if ( (unsigned int)qdf_mc_timer_get_current_state(tdls_vdev_obj + 560) != 21 )
            {
              tdls_timer_restart(
                *(_QWORD *)tdls_vdev_obj,
                tdls_vdev_obj + 560,
                *(_DWORD *)(tdls_vdev_obj + 732) - 1000,
                v63,
                v64,
                v65,
                v66,
                v67,
                v68,
                v69,
                v70);
              _X8 = (unsigned int *)(v30 + 628);
              __asm { PRFM            #0x11, [X8] }
              do
                v109 = __ldxr(_X8);
              while ( __stxr(v109 + 1, _X8) );
LABEL_44:
              qdf_mem_set(&v110, 0x30u, 0);
              qdf_trace_msg(
                0,
                8u,
                "%s: sending TDLS Mgmt Frame req to PE ",
                v72,
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                "tdls_activate_send_mgmt_request");
              v80 = *(_WORD *)(v30 + 332);
              *(_WORD *)v32 = v80;
              LOWORD(v110) = v80;
              v111 = v32;
              v113 = tdls_activate_send_mgmt_request_flush_cb;
              v81 = scheduler_post_message_debug(
                      0,
                      0,
                      53,
                      (unsigned __int16 *)&v110,
                      0x317u,
                      (__int64)"tdls_activate_send_mgmt_request");
              if ( !v81 )
              {
                tdls_reset_nss(v30, *((_BYTE *)v12 + 8), v82, v83, v84, v85, v86, v87, v88, v89);
                goto LABEL_29;
              }
              v60 = v81;
              _qdf_mem_free(v32);
              goto LABEL_46;
            }
          }
          else
          {
            qdf_trace_msg(
              0,
              2u,
              "%s: bss peer is null",
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              "tdls_activate_send_mgmt_request");
          }
          _qdf_mem_free(v32);
          v60 = 29;
        }
        else
        {
          v60 = 2;
        }
LABEL_46:
        comp_private_obj = v30;
        goto LABEL_47;
      }
      v60 = 29;
    }
    else
    {
      qdf_trace_msg(0, 2u, "%s: can't get psoc", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_get_tdls_soc_obj", a1);
      comp_private_obj = 0;
      v60 = 29;
    }
LABEL_47:
    tdls_reset_nss(comp_private_obj, *((_BYTE *)v12 + 8), v22, v23, v24, v25, v26, v27, v28, v29);
    v98 = *v12;
    if ( *v12 )
    {
      v99 = *(_QWORD *)(v98 + 216);
      v116[1] = 0;
      v118 = 0;
      v117 = v60;
      v116[0] = v98;
      if ( v99 && (v100 = *(_QWORD *)(v99 + 80)) != 0 )
      {
        v101 = wlan_objmgr_psoc_get_comp_private_obj(v100, 0xAu);
        if ( v101 )
        {
          v102 = *(_DWORD **)(v101 + 264);
          if ( v102 )
          {
            v103 = *(_QWORD *)(v101 + 272);
            if ( *(v102 - 1) != 1890320457 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, __int64, _QWORD *))v102)(v103, 1, v116);
          }
        }
      }
      else
      {
        qdf_trace_msg(0, 2u, "%s: can't get psoc", v90, v91, v92, v93, v94, v95, v96, v97, "wlan_vdev_get_tdls_soc_obj");
      }
    }
    tdls_release_serialization_command(*v12, 0xDu, v90, v91, v92, v93, v94, v95, v96, v97);
    result = v60;
    goto LABEL_57;
  }
  if ( a2 == 2 )
  {
    wlan_objmgr_vdev_release_ref(*v12, 0x11u, v11, a3, a4, a5, a6, a7, a8, a9, a10);
    _qdf_mem_free((__int64)v12);
LABEL_29:
    result = 0;
    goto LABEL_57;
  }
  if ( a2 != 3 )
    goto LABEL_57;
LABEL_10:
  v14 = *v12;
  if ( !*v12 )
  {
LABEL_26:
    result = 29;
    goto LABEL_57;
  }
  v15 = *(_QWORD *)(v14 + 216);
  v111 = 0;
  v112 = 16;
  v110 = v14;
  if ( !v15 || (v16 = *(_QWORD *)(v15 + 80)) == 0 )
  {
    qdf_trace_msg(0, 2u, "%s: can't get psoc", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_get_tdls_soc_obj", a1);
    goto LABEL_29;
  }
  result = wlan_objmgr_psoc_get_comp_private_obj(v16, 0xAu);
  if ( result )
  {
    v17 = *(void (__fastcall **)(__int64, __int64, __int64 *))(result + 264);
    if ( v17 )
    {
      v18 = *(_QWORD *)(result + 272);
      if ( *((_DWORD *)v17 - 1) != 1890320457 )
        __break(0x8228u);
      v17(v18, 1, &v110);
    }
    goto LABEL_29;
  }
LABEL_57:
  _ReadStatusReg(SP_EL0);
  return result;
}
