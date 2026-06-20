__int64 __fastcall wifi_pos_handle_ranging_peer_create(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned __int8 a4)
{
  _QWORD *legacy_ops; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  _DWORD **v17; // x23
  __int64 v18; // x0
  __int64 v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w28
  __int64 i; // x25
  const char *v30; // x2
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned __int8 *peer_by_mac; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned __int8 *v48; // x24
  __int64 v49; // x4
  __int64 v50; // x5
  __int64 v51; // x6
  __int64 v52; // x7
  _DWORD *v53; // x8
  unsigned int v54; // w0
  __int64 v55; // x4
  __int64 v56; // x5
  __int64 v57; // x6
  __int64 v58; // x7
  __int64 vdev_priv_obj; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned __int8 v68; // w8
  int v69; // w27
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  _BYTE *v78; // x0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x4
  __int64 v88; // x5
  __int64 v89; // x6
  __int64 v90; // x7
  unsigned __int8 *v91; // x0
  unsigned __int8 *v92; // x24
  _BYTE *peer_private_object; // x0
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  unsigned int *v110; // x8
  __int64 v111; // x0
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  unsigned int *v121; // x8
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  __int64 v130; // [xsp+0h] [xbp-10h]

  legacy_ops = (_QWORD *)wifi_pos_get_legacy_ops(a1);
  if ( !legacy_ops || (v17 = (_DWORD **)legacy_ops, !*legacy_ops) )
  {
    v30 = "%s: legacy callbacks is not registered";
LABEL_7:
    qdf_trace_msg(0x25u, 2u, v30, v9, v10, v11, v12, v13, v14, v15, v16, "wifi_pos_handle_ranging_peer_create");
    return 16;
  }
  v18 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 13);
  if ( !v18 )
  {
    v30 = "%s: Vdev object is null";
    goto LABEL_7;
  }
  v19 = v18;
  qdf_trace_msg(
    0x25u,
    8u,
    "%s: vdev:%d PASN peer create request received. Num peers:%d",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "wifi_pos_handle_ranging_peer_create",
    (unsigned __int8)a3,
    a4);
  v28 = 0;
  if ( a4 )
  {
    for ( i = a4; i; --i )
    {
      peer_by_mac = (unsigned __int8 *)wlan_objmgr_get_peer_by_mac(a1, a2, 0xDu);
      if ( !peer_by_mac )
      {
        v53 = *v17;
        if ( *(*v17 - 1) != -1587159217 )
          __break(0x8228u);
        v54 = ((__int64 (__fastcall *)(__int64, unsigned __int8 *, _QWORD))v53)(a1, a2, a3);
        if ( v54 )
        {
          v28 = v54;
          wifi_pos_set_11az_failed_peers(v19, a2);
        }
        else
        {
          vdev_priv_obj = wifi_pos_get_vdev_priv_obj(v19);
          if ( vdev_priv_obj )
          {
            v68 = *(_BYTE *)(vdev_priv_obj + 12264) + 1;
            *(_BYTE *)(vdev_priv_obj + 12264) = v68;
            qdf_trace_msg(
              0x25u,
              8u,
              "%s: Pasn peer count:%d",
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              "wifi_pos_update_pasn_peer_count",
              v68);
          }
          else
          {
            qdf_trace_msg(
              0x25u,
              2u,
              "%s: Wifi pos vdev priv obj is null",
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              "wifi_pos_update_pasn_peer_count");
          }
          if ( a2[19] == 1 )
          {
            v91 = (unsigned __int8 *)wlan_objmgr_get_peer_by_mac(a1, a2, 0xDu);
            if ( v91 )
            {
              v92 = v91;
              peer_private_object = (_BYTE *)wifi_pos_get_peer_private_object(
                                               (__int64)v91,
                                               v20,
                                               v21,
                                               v22,
                                               v23,
                                               v24,
                                               v25,
                                               v26,
                                               v27);
              if ( peer_private_object )
              {
                *peer_private_object = 1;
                LODWORD(v130) = 1;
                qdf_trace_msg(
                  0x25u,
                  8u,
                  "%s: peer_mac:%02x:%02x:%02x:**:**:%02x value:%d",
                  v94,
                  v95,
                  v96,
                  v97,
                  v98,
                  v99,
                  v100,
                  v101,
                  "wifi_pos_set_peer_ltf_keyseed_required",
                  v92[48],
                  v92[49],
                  v92[50],
                  v92[53],
                  v130);
              }
              else
              {
                qdf_trace_msg(
                  0x25u,
                  2u,
                  "%s: peer private object is null",
                  v94,
                  v95,
                  v96,
                  v97,
                  v98,
                  v99,
                  v100,
                  v101,
                  "wifi_pos_set_peer_ltf_keyseed_required");
              }
              wlan_objmgr_peer_release_ref((__int64)v92, 0xDu, v102, v103, v104, v105, v106, v107, v108, v109);
            }
          }
          if ( !*(_DWORD *)(v19 + 16) )
            wifi_pos_add_peer_to_list(v19, a2, 1);
          v28 = 0;
        }
        goto LABEL_10;
      }
      v48 = peer_by_mac;
      if ( *((_DWORD *)peer_by_mac + 17) != 12 )
      {
        if ( a2 )
        {
          v55 = *a2;
          v56 = a2[1];
          v57 = a2[2];
          v58 = a2[5];
        }
        else
        {
          v57 = 0;
          v55 = 0;
          v56 = 0;
          v58 = 0;
        }
        LODWORD(v130) = *((_DWORD *)peer_by_mac + 17);
        qdf_trace_msg(
          0x25u,
          8u,
          "%s: Peer: %02x:%02x:%02x:**:**:%02xof type:%d already exist",
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          "wifi_pos_handle_ranging_peer_create",
          v55,
          v56,
          v57,
          v58,
          v130);
        wifi_pos_set_11az_failed_peers(v19, a2);
        goto LABEL_9;
      }
      if ( a2 )
      {
        v49 = *a2;
        v50 = a2[1];
        v51 = a2[2];
        v52 = a2[5];
      }
      else
      {
        v51 = 0;
        v49 = 0;
        v50 = 0;
        v52 = 0;
      }
      qdf_trace_msg(
        0x25u,
        8u,
        "%s: PASN Peer: %02x:%02x:%02x:**:**:%02xalready exists",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "wifi_pos_handle_ranging_peer_create",
        v49,
        v50,
        v51,
        v52);
      wifi_pos_add_peer_to_list(v19, a2, 0);
      v69 = a2[19];
      v78 = (_BYTE *)wifi_pos_get_peer_private_object((__int64)v48, v70, v71, v72, v73, v74, v75, v76, v77);
      if ( v69 == 1 )
      {
        if ( v78 )
        {
          *v78 = 1;
          v87 = v48[48];
          v88 = v48[49];
          v89 = v48[50];
          v90 = v48[53];
          LODWORD(v130) = 1;
LABEL_29:
          qdf_trace_msg(
            0x25u,
            8u,
            "%s: peer_mac:%02x:%02x:%02x:**:**:%02x value:%d",
            v79,
            v80,
            v81,
            v82,
            v83,
            v84,
            v85,
            v86,
            "wifi_pos_set_peer_ltf_keyseed_required",
            v87,
            v88,
            v89,
            v90,
            v130);
          goto LABEL_9;
        }
      }
      else if ( v78 )
      {
        *v78 = 0;
        v87 = v48[48];
        v88 = v48[49];
        v89 = v48[50];
        v90 = v48[53];
        LODWORD(v130) = 0;
        goto LABEL_29;
      }
      qdf_trace_msg(
        0x25u,
        2u,
        "%s: peer private object is null",
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        "wifi_pos_set_peer_ltf_keyseed_required");
LABEL_9:
      wlan_objmgr_peer_release_ref((__int64)v48, 0xDu, v31, v32, v33, v34, v35, v36, v37, v38);
LABEL_10:
      a2 += 380;
    }
  }
  v110 = (unsigned int *)*(unsigned int *)(v19 + 16);
  if ( !(_DWORD)v110 )
  {
    v111 = wifi_pos_get_vdev_priv_obj(v19);
    if ( !v111 )
    {
      qdf_trace_msg(
        0x25u,
        2u,
        "%s: Wifi pos vdev priv obj is null",
        v112,
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        v119,
        "wifi_pos_handle_ranging_peer_create");
      wlan_objmgr_vdev_release_ref(v19, 0xDu, v121, v122, v123, v124, v125, v126, v127, v128, v129);
      return 16;
    }
    v28 = wifi_pos_check_and_initiate_pasn_authentication(v19, v111);
  }
  wlan_objmgr_vdev_release_ref(v19, 0xDu, v110, v20, v21, v22, v23, v24, v25, v26, v27);
  return v28;
}
