__int64 __fastcall tdls_process_add_peer_rsp(
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
  int v18; // w8
  __int64 v19; // x21
  __int64 v20; // x1
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  __int64 v31; // x21
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int *v48; // x8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int v57; // w22
  __int64 v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x22
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned int *v76; // x8
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  void (__fastcall *v85)(__int64, __int64, __int64 *); // x8
  int v86; // w9
  __int64 v87; // x0
  __int64 comp_private_obj; // x0
  unsigned int v90; // w10
  __int64 v91; // x9
  unsigned __int8 v92; // w8
  unsigned int v93; // w23
  char v94; // w10
  int v95; // w11
  __int64 v96; // [xsp+10h] [xbp-40h] BYREF
  __int64 v97; // [xsp+18h] [xbp-38h]
  __int64 v98; // [xsp+20h] [xbp-30h]
  __int64 v99; // [xsp+28h] [xbp-28h]
  __int64 v100; // [xsp+30h] [xbp-20h] BYREF
  __int64 v101; // [xsp+38h] [xbp-18h]
  __int64 v102; // [xsp+40h] [xbp-10h]
  __int64 v103; // [xsp+48h] [xbp-8h]

  v103 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0,
    8u,
    "%s: peer oper %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "tdls_process_add_peer_rsp",
    *(unsigned int *)(a1 + 16));
  v18 = *(_DWORD *)(a1 + 16);
  if ( v18 == 2 )
  {
    v31 = *(_QWORD *)(a1 + 24);
    v101 = 0;
    v102 = 0;
    v100 = 0;
    if ( v31 )
    {
      v30 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              v31,
              *(unsigned __int8 *)(a1 + 10),
              16);
      if ( v30 )
      {
        v96 = 0xE00000000LL;
        v97 = 0;
        v98 = v30;
        v99 = 0;
        qdf_trace_msg(
          0,
          8u,
          "%s: release %s",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "tdls_release_serialization_command",
          "TDLS_ADD_PEER_CMD");
        wlan_serialization_remove_cmd((unsigned int *)&v96, v40, v41, v42, v43, v44, v45, v46, v47);
        wlan_objmgr_vdev_release_ref(v30, 0x10u, v48, v49, v50, v51, v52, v53, v54, v55, v56);
        v57 = 0;
      }
      else
      {
        qdf_trace_msg(
          0,
          2u,
          "%s: invalid vdev: %d",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "tdls_update_peer_rsp",
          *(unsigned __int8 *)(a1 + 10));
        v57 = 4;
      }
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v31, 0xAu);
      if ( comp_private_obj )
      {
        v85 = *(void (__fastcall **)(__int64, __int64, __int64 *))(comp_private_obj + 264);
        if ( v85 )
        {
          v86 = *(_DWORD *)a1;
          v87 = *(_QWORD *)(comp_private_obj + 272);
          goto LABEL_26;
        }
      }
LABEL_29:
      _qdf_mem_free(a1);
      goto LABEL_30;
    }
    qdf_trace_msg(0, 2u, "%s: psoc is NULL", v10, v11, v12, v13, v14, v15, v16, v17, "tdls_update_peer_rsp");
    v57 = 16;
  }
  else
  {
    if ( v18 == 1 )
    {
      v19 = *(_QWORD *)(a1 + 24);
      v20 = *(unsigned __int8 *)(a1 + 10);
      v101 = 0;
      v102 = 0;
      v100 = 0;
      v21 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v19, v20, 16);
      if ( !v21 )
      {
        qdf_trace_msg(
          0,
          2u,
          "%s: invalid vdev: %d",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "tdls_add_peer_rsp",
          *(unsigned __int8 *)(a1 + 10));
        v57 = 4;
        goto LABEL_29;
      }
      v30 = v21;
      if ( v19 )
        v19 = wlan_objmgr_psoc_get_comp_private_obj(v19, 0xAu);
      else
        qdf_trace_msg(0, 2u, "%s: NULL psoc", v22, v23, v24, v25, v26, v27, v28, v29, "wlan_psoc_get_tdls_soc_obj");
      v58 = wlan_objmgr_vdev_get_comp_private_obj(v30, 0xAu);
      v67 = v58;
      if ( v19 && v58 )
      {
        if ( *(_DWORD *)a1 )
        {
          qdf_trace_msg(
            0,
            2u,
            "%s: add sta failed. status code(=%d)",
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            "tdls_add_peer_rsp");
        }
        else
        {
          v90 = *(unsigned __int16 *)(v19 + 200);
          if ( *(_WORD *)(v19 + 200) )
          {
            v91 = v19 + 32;
            if ( *(_BYTE *)(v19 + 33) == 1 )
            {
              v92 = 0;
              while ( 1 )
              {
                v93 = ++v92;
                if ( v90 <= v92 )
                  break;
                if ( (*(_BYTE *)(v91 + 9LL * v92 + 1) & 1) == 0 )
                {
                  v91 += 9LL * v92;
                  goto LABEL_38;
                }
              }
            }
            else
            {
              v93 = 0;
              v92 = 0;
LABEL_38:
              v94 = *(_BYTE *)(a1 + 10);
              *(_BYTE *)(v91 + 2) = v92;
              *(_BYTE *)(v91 + 1) = 1;
              *(_BYTE *)v91 = v94;
              v95 = *(_DWORD *)(a1 + 4);
              *(_WORD *)(v91 + 7) = *(_WORD *)(a1 + 8);
              *(_DWORD *)(v91 + 3) = v95;
              qdf_trace_msg(
                0,
                8u,
                "%s: TDLS: Add sta mac at idx %d%02x:%02x:%02x:**:**:%02x",
                v59,
                v60,
                v61,
                v62,
                v63,
                v64,
                v65,
                v66,
                "tdls_add_peer_rsp",
                v92,
                *(unsigned __int8 *)(a1 + 4),
                *(unsigned __int8 *)(a1 + 5),
                *(unsigned __int8 *)(a1 + 6),
                *(unsigned __int8 *)(a1 + 9));
              v90 = *(unsigned __int16 *)(v19 + 200);
            }
            if ( v90 > v93 )
            {
              if ( !(unsigned int)tdls_set_valid(v67, a1 + 4) )
              {
                v57 = 0;
                goto LABEL_19;
              }
              qdf_trace_msg(0, 2u, "%s: set staid failed", v59, v60, v61, v62, v63, v64, v65, v66, "tdls_add_peer_rsp");
            }
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0,
          2u,
          "%s: soc object:%pK, vdev object:%pK",
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          "tdls_add_peer_rsp",
          v19,
          v58);
      }
      v57 = 16;
LABEL_19:
      v96 = 0xE00000000LL;
      v97 = 0;
      v98 = v30;
      v99 = 0;
      qdf_trace_msg(
        0,
        8u,
        "%s: release %s",
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        "tdls_release_serialization_command",
        "TDLS_ADD_PEER_CMD");
      wlan_serialization_remove_cmd((unsigned int *)&v96, v68, v69, v70, v71, v72, v73, v74, v75);
      wlan_objmgr_vdev_release_ref(v30, 0x10u, v76, v77, v78, v79, v80, v81, v82, v83, v84);
      if ( v19 )
      {
        v85 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v19 + 264);
        if ( v85 )
        {
          v86 = *(_DWORD *)a1;
          v87 = *(_QWORD *)(v19 + 272);
LABEL_26:
          v100 = v30;
          LODWORD(v102) = v86;
          if ( *((_DWORD *)v85 - 1) != 1890320457 )
            __break(0x8228u);
          v85(v87, 3, &v100);
          goto LABEL_29;
        }
      }
      goto LABEL_29;
    }
    v57 = 4;
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return v57;
}
