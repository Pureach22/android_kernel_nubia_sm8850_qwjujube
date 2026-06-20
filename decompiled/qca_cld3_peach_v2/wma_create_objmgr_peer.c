__int64 __fastcall wma_create_objmgr_peer(__int64 a1, __int64 a2, unsigned __int8 *a3, int a4, unsigned __int8 *a5)
{
  __int64 v9; // x0
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  _QWORD *peer_by_mac; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w21
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x4
  const char *v39; // x2
  __int64 v40; // x5
  __int64 v41; // x6
  __int64 v42; // x7
  __int64 v43; // x20
  __int64 v44; // x25
  _QWORD *v45; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int v54; // w24
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x0
  unsigned int *v72; // x8
  __int64 v73; // x20
  unsigned int *v74; // x8
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  unsigned int v92; // w21
  _DWORD *v93; // x24
  unsigned int v94; // w1
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  __int64 v103; // x8
  __int64 v104; // x4
  __int64 v105; // [xsp+0h] [xbp-30h]
  __int64 v106; // [xsp+8h] [xbp-28h]
  _BYTE v107[4]; // [xsp+10h] [xbp-20h] BYREF
  _BYTE v108[20]; // [xsp+14h] [xbp-1Ch] BYREF
  __int64 v109; // [xsp+28h] [xbp-8h]

  v109 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_QWORD *)(a1 + 24);
  v107[0] = a2;
  v10 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v9, a2, 8);
  if ( v10 )
  {
    v19 = v10;
    if ( a3 )
    {
      if ( *(_DWORD *)a3 | *((unsigned __int16 *)a3 + 2) )
      {
        peer_by_mac = wlan_objmgr_get_peer_by_mac(*(_QWORD *)(a1 + 24), a3, 8u);
        if ( peer_by_mac )
        {
          v29 = *(unsigned __int8 *)(peer_by_mac[12] + 168LL);
          wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 8u, v21, v22, v23, v24, v25, v26, v27, v28);
          v38 = *a3;
          v39 = "%s: Peer %02x:%02x:%02x:**:**:%02x already exists on vdev %d, current vdev %d";
          v40 = a3[1];
          v41 = a3[2];
          v42 = a3[5];
          LODWORD(v106) = v107[0];
          LODWORD(v105) = v29;
LABEL_27:
          qdf_trace_msg(
            0x36u,
            8u,
            v39,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "wma_create_objmgr_peer",
            v38,
            v40,
            v41,
            v42,
            v105,
            v106);
LABEL_28:
          v43 = 0;
LABEL_29:
          wlan_objmgr_vdev_release_ref(v19, 8u, v74, v75, v76, v77, v78, v79, v80, v81, v82);
          goto LABEL_30;
        }
      }
      if ( (mlo_mgr_ml_peer_exist_on_diff_ml_ctx(a3, v107) & 1) != 0 )
      {
        v38 = *a3;
        v40 = a3[1];
        v41 = a3[2];
        v42 = a3[5];
LABEL_11:
        v39 = "%s: Peer %02x:%02x:%02x:**:**:%02x already exists on different ML dev context";
        goto LABEL_27;
      }
    }
    else if ( (mlo_mgr_ml_peer_exist_on_diff_ml_ctx(0, v107) & 1) != 0 )
    {
      v41 = 0;
      v38 = 0;
      v40 = 0;
      v42 = 0;
      goto LABEL_11;
    }
    v44 = *(_QWORD *)(a1 + 24);
    v108[0] = *(_BYTE *)(v19 + 168);
    if ( a5 )
    {
      if ( *(_DWORD *)a5 | *((unsigned __int16 *)a5 + 2) && (v45 = wlan_objmgr_get_peer_by_mac(v44, a5, 8u)) != nullptr )
      {
        v54 = *(unsigned __int8 *)(v45[12] + 168LL);
        wlan_objmgr_peer_release_ref((__int64)v45, 8u, v46, v47, v48, v49, v50, v51, v52, v53);
        if ( v54 == v108[0] )
        {
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: ML Peer exists on same VDEV %d",
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            "wma_create_peer_validate_mld_address",
            v54);
LABEL_26:
          v38 = *a5;
          v40 = a5[1];
          v39 = "%s: MLD %02x:%02x:%02x:**:**:%02x matches with peer on different MLD context";
          v41 = a5[2];
          v42 = a5[5];
          goto LABEL_27;
        }
        v71 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v44, v54, 8);
        if ( !v71 )
          goto LABEL_26;
        v72 = *(unsigned int **)(v71 + 1360);
        if ( !v72 )
        {
LABEL_25:
          wlan_objmgr_vdev_release_ref(v71, 8u, v72, v30, v31, v32, v33, v34, v35, v36, v37);
          goto LABEL_26;
        }
        if ( v72 != *(unsigned int **)(v19 + 1360) )
        {
          v73 = v71;
          qdf_trace_msg(
            0x36u,
            8u,
            "%s: Peer %02x:%02x:%02x:**:**:%02x already exists on vdev %d, current vdev %d",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "wma_create_peer_validate_mld_address",
            *a5,
            a5[1],
            a5[2],
            a5[5],
            v54,
            v108[0]);
          v71 = v73;
          goto LABEL_25;
        }
        wlan_objmgr_vdev_release_ref(v71, 8u, v72, v30, v31, v32, v33, v34, v35, v36, v37);
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: Allow ML peer on same ML dev context",
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          v90,
          v91,
          "wma_create_peer_validate_mld_address");
      }
      else if ( (mlo_mgr_ml_peer_exist_on_diff_ml_ctx(a5, v108) & 1) != 0 )
      {
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: ML Peer %02x:%02x:%02x:**:**:%02x already exists on different ML dev context",
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          "wma_create_peer_validate_mld_address",
          *a5,
          a5[1],
          a5[2],
          a5[5]);
        goto LABEL_26;
      }
    }
    else if ( (mlo_mgr_ml_peer_exist_on_diff_ml_ctx(0, v108) & 1) != 0 )
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: ML Peer %02x:%02x:%02x:**:**:%02x already exists on different ML dev context",
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        "wma_create_peer_validate_mld_address",
        0,
        0,
        0,
        0);
      v41 = 0;
      v38 = 0;
      v40 = 0;
      v42 = 0;
      v39 = "%s: MLD %02x:%02x:%02x:**:**:%02x matches with peer on different MLD context";
      goto LABEL_27;
    }
    v92 = v107[0];
    v93 = *(_DWORD **)(*(_QWORD *)(a1 + 520) + 488LL * v107[0]);
    if ( !v93 )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Couldn't find vdev for VDEV_%d",
        v63,
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        "wma_get_obj_mgr_peer_type",
        v107[0]);
LABEL_39:
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Invalid obj peer type. Unable to create peer %d",
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        "wma_create_objmgr_peer",
        0);
      goto LABEL_28;
    }
    if ( a4 == 2 )
    {
      v94 = 6;
    }
    else
    {
      if ( a4 == 6 )
      {
        if ( v93[4] == 16 )
          v94 = 14;
        else
          v94 = 12;
        goto LABEL_50;
      }
      if ( (unsigned int)qdf_mem_cmp((char *)v93 + 74, a3, 6u) && (unsigned int)qdf_mem_cmp(v93 + 20, a3, 6u) )
      {
        v103 = *(_QWORD *)(a1 + 520) + 488LL * v92;
        v104 = *(unsigned int *)(v103 + 164);
        if ( (int)v104 > 2 )
        {
          if ( (_DWORD)v104 == 3 )
          {
            v94 = 9;
          }
          else
          {
            if ( (_DWORD)v104 != 7 )
            {
LABEL_54:
              qdf_trace_msg(
                0x36u,
                2u,
                "%s: Couldn't find peertype for type %d and sub type %d",
                v63,
                v64,
                v65,
                v66,
                v67,
                v68,
                v69,
                v70,
                "wma_get_obj_mgr_peer_type",
                v104,
                *(unsigned int *)(v103 + 168));
              goto LABEL_39;
            }
            v94 = 10;
          }
        }
        else
        {
          if ( (_DWORD)v104 != 1 )
          {
            if ( (_DWORD)v104 == 2 )
            {
              if ( *(_DWORD *)(v103 + 168) == 2 )
                v94 = 3;
              else
                v94 = 2;
              goto LABEL_50;
            }
            goto LABEL_54;
          }
          v94 = 4;
        }
      }
      else
      {
        v94 = 1;
      }
    }
LABEL_50:
    v43 = wlan_objmgr_peer_obj_create(v19, v94, a3, v63, v64, v65, v66, v67, v68, v69, v70);
    goto LABEL_29;
  }
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: Invalid obj vdev. Unable to create peer",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "wma_create_objmgr_peer");
  v43 = 0;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return v43;
}
