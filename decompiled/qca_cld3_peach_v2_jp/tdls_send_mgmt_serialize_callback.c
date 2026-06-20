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
  __int64 v12; // x19
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
  __int16 v51; // w8
  unsigned int v52; // w22
  int v53; // w8
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int16 v62; // w8
  unsigned int v63; // w0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // x8
  __int64 v81; // x9
  __int64 v82; // x0
  __int64 v83; // x0
  _DWORD *v84; // x8
  __int64 v85; // x0
  __int64 v86; // [xsp+10h] [xbp-50h] BYREF
  __int64 v87; // [xsp+18h] [xbp-48h]
  __int64 v88; // [xsp+20h] [xbp-40h]
  __int64 (__fastcall *v89)(); // [xsp+28h] [xbp-38h]
  __int64 v90; // [xsp+30h] [xbp-30h]
  __int64 v91; // [xsp+38h] [xbp-28h]
  _QWORD v92[2]; // [xsp+40h] [xbp-20h] BYREF
  unsigned int v93; // [xsp+50h] [xbp-10h]
  int v94; // [xsp+54h] [xbp-Ch]
  unsigned int *v95; // [xsp+58h] [xbp-8h]

  v11 = *(unsigned int **)(_ReadStatusReg(SP_EL0) + 1808);
  v95 = v11;
  if ( !a1 || (v12 = *(_QWORD *)(a1 + 40)) == 0 )
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
    goto LABEL_51;
  }
  result = 4;
  if ( a2 > 1 )
  {
    if ( a2 == 2 )
    {
      wlan_objmgr_vdev_release_ref(*(_QWORD *)v12, 0x11u, v11, a3, a4, a5, a6, a7, a8, a9, a10);
      _qdf_mem_free(v12);
LABEL_29:
      result = 0;
      goto LABEL_51;
    }
    if ( a2 != 3 )
      goto LABEL_51;
  }
  else
  {
    if ( !a2 )
    {
      v90 = 0;
      v91 = 0;
      v88 = 0;
      v89 = nullptr;
      v86 = 0;
      v87 = 0;
      if ( *(_QWORD *)v12 )
      {
        v19 = *(_QWORD *)(*(_QWORD *)v12 + 152LL);
        if ( v19 && (v20 = *(_QWORD *)(v19 + 80)) != 0 )
        {
          comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v20, 0xAu);
          if ( comp_private_obj )
          {
            v30 = comp_private_obj;
            v31 = _qdf_mem_malloc(*(unsigned __int8 *)(v12 + 76) + 36LL, "tdls_activate_send_mgmt_request", 705);
            if ( v31 )
            {
              v32 = v31;
              qdf_trace_msg(
                0,
                8u,
                "%s: session_id %d tdls_mgmt.dialog %d tdls_mgmt.frame_type %d tdls_mgmt.status_code %d tdls_mgmt.respond"
                "er %d tdls_mgmt.peer_capability %d",
                v22,
                v23,
                v24,
                v25,
                v26,
                v27,
                v28,
                v29,
                "tdls_activate_send_mgmt_request",
                *(unsigned __int8 *)(v12 + 40),
                *(unsigned __int8 *)(v12 + 67),
                *(unsigned __int8 *)(v12 + 66),
                *(unsigned __int16 *)(v12 + 68),
                *(unsigned __int8 *)(v12 + 70),
                *(_DWORD *)(v12 + 72),
                v86,
                v87,
                v88,
                v89,
                v90,
                v91);
              *(_BYTE *)(v32 + 4) = *(_BYTE *)(v12 + 40);
              *(_BYTE *)(v32 + 5) = *(_BYTE *)(v12 + 66);
              *(_BYTE *)(v32 + 6) = *(_BYTE *)(v12 + 67);
              *(_WORD *)(v32 + 8) = *(_WORD *)(v12 + 68);
              *(_BYTE *)(v32 + 10) = *(_BYTE *)(v12 + 70);
              *(_DWORD *)(v32 + 12) = *(_DWORD *)(v12 + 72);
              bsspeer = wlan_objmgr_vdev_try_get_bsspeer(*(_QWORD *)v12, 0x10u);
              if ( bsspeer )
              {
                v42 = bsspeer;
                qdf_mem_copy((void *)(v32 + 16), (const void *)(bsspeer + 48), 6u);
                wlan_objmgr_peer_release_ref(v42, 0x10u, v43, v44, v45, v46, v47, v48, v49, v50);
                qdf_mem_copy((void *)(v32 + 22), (const void *)(v12 + 60), 6u);
                if ( *(_BYTE *)(v12 + 76) )
                {
                  qdf_mem_copy((void *)(v32 + 32), (const void *)(v12 + 77), *(unsigned __int8 *)(v12 + 76));
                  v51 = *(unsigned __int8 *)(v12 + 76);
                }
                else
                {
                  v51 = 0;
                }
                *(_WORD *)(v32 + 2) = v51 + 36;
                if ( *(_BYTE *)(v12 + 57) )
                  v53 = 1;
                else
                  v53 = 3;
                *(_DWORD *)(v32 + 28) = v53;
                qdf_mem_set(&v86, 0x30u, 0);
                qdf_trace_msg(
                  0,
                  8u,
                  "%s: sending TDLS Mgmt Frame req to PE ",
                  v54,
                  v55,
                  v56,
                  v57,
                  v58,
                  v59,
                  v60,
                  v61,
                  "tdls_activate_send_mgmt_request");
                v62 = *(_WORD *)(v30 + 332);
                *(_WORD *)v32 = v62;
                LOWORD(v86) = v62;
                v87 = v32;
                v89 = tdls_activate_send_mgmt_request_flush_cb;
                v63 = scheduler_post_message_debug(
                        0,
                        0,
                        53,
                        (unsigned __int16 *)&v86,
                        0x317u,
                        (__int64)"tdls_activate_send_mgmt_request");
                if ( !v63 )
                {
                  tdls_reset_nss(v30, *(_BYTE *)(v12 + 8), v64, v65, v66, v67, v68, v69, v70, v71);
                  goto LABEL_29;
                }
                v52 = v63;
                _qdf_mem_free(v32);
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
                _qdf_mem_free(v32);
                v52 = 29;
              }
            }
            else
            {
              v52 = 2;
            }
            comp_private_obj = v30;
          }
          else
          {
            v52 = 29;
          }
        }
        else
        {
          qdf_trace_msg(0, 2u, "%s: can't get psoc", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_vdev_get_tdls_soc_obj", a1);
          comp_private_obj = 0;
          v52 = 29;
        }
        tdls_reset_nss(comp_private_obj, *(_BYTE *)(v12 + 8), v22, v23, v24, v25, v26, v27, v28, v29);
        v80 = *(_QWORD *)v12;
        if ( *(_QWORD *)v12 )
        {
          v81 = *(_QWORD *)(v80 + 152);
          v92[1] = 0;
          v94 = 0;
          v93 = v52;
          v92[0] = v80;
          if ( v81 && (v82 = *(_QWORD *)(v81 + 80)) != 0 )
          {
            v83 = wlan_objmgr_psoc_get_comp_private_obj(v82, 0xAu);
            if ( v83 )
            {
              v84 = *(_DWORD **)(v83 + 264);
              if ( v84 )
              {
                v85 = *(_QWORD *)(v83 + 272);
                if ( *(v84 - 1) != 1890320457 )
                  __break(0x8228u);
                ((void (__fastcall *)(__int64, __int64, _QWORD *))v84)(v85, 1, v92);
              }
            }
          }
          else
          {
            qdf_trace_msg(
              0,
              2u,
              "%s: can't get psoc",
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              "wlan_vdev_get_tdls_soc_obj");
          }
        }
        tdls_release_serialization_command(*(_QWORD *)v12, 0xDu, v72, v73, v74, v75, v76, v77, v78, v79);
        result = v52;
        goto LABEL_51;
      }
LABEL_26:
      result = 29;
      goto LABEL_51;
    }
    if ( a2 != 1 )
      goto LABEL_51;
  }
  v14 = *(_QWORD *)v12;
  if ( !*(_QWORD *)v12 )
    goto LABEL_26;
  v15 = *(_QWORD *)(v14 + 152);
  v87 = 0;
  v88 = 16;
  v86 = v14;
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
      v17(v18, 1, &v86);
    }
    goto LABEL_29;
  }
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
