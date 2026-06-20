__int64 __fastcall ndi_add_pasn_peer_to_nan(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w22
  __int64 v23; // x19
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  _DWORD *v41; // x8
  unsigned int v42; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  unsigned int v51; // w21
  const char *v52; // x2
  const char *v53; // x2
  unsigned int *v55; // x8
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  const char *v64; // x2
  __int64 v65; // x0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned __int8 v74; // w8
  __int64 v75; // x0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x20
  __int64 v85; // x0
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  unsigned int v94; // w22
  unsigned int *v95; // x8
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  __int64 v104; // x8
  _DWORD *v105; // x24
  unsigned int v107; // w23
  void *v108; // x0
  unsigned int *v113; // x8
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7

  if ( !a1 )
  {
    v53 = "%s: psoc is null";
LABEL_15:
    qdf_trace_msg(0x53u, 2u, v53, a3, a4, a5, a6, a7, a8, a9, a10, "nan_is_pairing_allowed");
    goto LABEL_16;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
    v53 = "%s: psoc_nan_obj is NULL";
    goto LABEL_15;
  }
  if ( (*(_WORD *)(comp_private_obj + 232) & 0x200) != 0 && (*(_DWORD *)(comp_private_obj + 228) & 1) != 0 )
  {
    v13 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_opmode_from_psoc)(a1, 16, 20);
    if ( !v13 )
    {
      qdf_trace_msg(
        0x53u,
        2u,
        "%s: Failed to get nan vdev",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "ndi_add_pasn_peer_to_nan");
      return 29;
    }
    v22 = *(unsigned __int8 *)(v13 + 168);
    v23 = v13;
    if ( (nan_is_peer_migrated(a1, *(unsigned __int8 *)(v13 + 168), a2) & 1) == 0 )
    {
      qdf_trace_msg(
        0x53u,
        8u,
        "%s: NAN PASN peer is not migrated",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "ndi_add_pasn_peer_to_nan");
LABEL_20:
      v51 = 0;
LABEL_36:
      wlan_objmgr_vdev_release_ref(v23, 0x14u, v55, v56, v57, v58, v59, v60, v61, v62, v63);
      return v51;
    }
    v32 = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
    if ( v32 )
    {
      v41 = *(_DWORD **)(v32 + 168);
      if ( v41 )
      {
        if ( *(v41 - 1) != 933372279 )
          __break(0x8228u);
        v42 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))v41)(a1, a2, v22, 12);
        if ( v42 )
        {
          v51 = v42;
          v52 = "%s: NAN PASN peer create request fails";
LABEL_35:
          qdf_trace_msg(0x53u, 2u, v52, v43, v44, v45, v46, v47, v48, v49, v50, "ndi_add_pasn_peer_to_nan");
          goto LABEL_36;
        }
        v65 = wlan_objmgr_vdev_get_comp_private_obj(v23, 0xFu);
        if ( v65 )
        {
          v74 = *(_BYTE *)(v65 + 105) + 1;
          *(_BYTE *)(v65 + 105) = v74;
          qdf_trace_msg(
            0x53u,
            8u,
            "%s: Pasn peer count:%d",
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            "nan_update_pasn_peer_count",
            v74);
        }
        else
        {
          qdf_trace_msg(
            0x53u,
            2u,
            "%s: NAN vdev priv obj is null",
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            v72,
            v73,
            "nan_update_pasn_peer_count");
        }
        v75 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v22, 20);
        if ( !v75 )
        {
          qdf_trace_msg(
            0x53u,
            2u,
            "%s: vdev is null",
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            v83,
            "nan_remove_peer_in_migrated_addr_list");
          v51 = 29;
LABEL_34:
          v52 = "%s: fail to remove peer addr in migrated list";
          goto LABEL_35;
        }
        v84 = v75;
        v85 = wlan_objmgr_vdev_get_comp_private_obj(v75, 0xFu);
        if ( !v85 )
        {
          qdf_trace_msg(
            0x53u,
            2u,
            "%s: NAN vdev priv obj is null",
            v86,
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            v93,
            "nan_remove_peer_in_migrated_addr_list");
          v51 = 29;
          goto LABEL_33;
        }
        v94 = *(unsigned __int8 *)(v85 + 107);
        if ( v94 >= 6 )
        {
          qdf_trace_msg(
            0x53u,
            2u,
            "%s: idx %d more than max migrated peers",
            v86,
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            v93,
            "nan_remove_peer_in_migrated_addr_list",
            *(unsigned __int8 *)(v85 + 107));
          v51 = 16;
LABEL_33:
          wlan_objmgr_vdev_release_ref(v84, 0x14u, v95, v96, v97, v98, v99, v100, v101, v102, v103);
          goto LABEL_34;
        }
        if ( !*(_BYTE *)(v85 + 107) )
        {
          qdf_trace_msg(
            0x53u,
            8u,
            "%s: last migrated peer removed",
            v86,
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            v93,
            "nan_remove_peer_in_migrated_addr_list");
LABEL_71:
          wlan_objmgr_vdev_release_ref(v84, 0x14u, v113, v114, v115, v116, v117, v118, v119, v120, v121);
          goto LABEL_20;
        }
        v104 = v85 + 108;
        v105 = (_DWORD *)v85;
        if ( *(_DWORD *)a2 == *(_DWORD *)(v85 + 108)
          && *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(v85 + 112) )
        {
          v107 = 0;
          v108 = (void *)(v85 + 108);
        }
        else
        {
          v107 = *(unsigned __int8 *)(v85 + 107);
          if ( v94 == 1 )
            goto LABEL_70;
          v108 = (void *)(v85 + 114);
          if ( *(_DWORD *)a2 == *(_DWORD *)((char *)v105 + 114)
            && *(unsigned __int16 *)(a2 + 4) == *((unsigned __int16 *)v105 + 59) )
          {
            v107 = 1;
          }
          else
          {
            v107 = v94;
            if ( v94 == 2 )
              goto LABEL_70;
            v108 = v105 + 30;
            if ( *(_DWORD *)a2 != v105[30] || *(unsigned __int16 *)(a2 + 4) != *((unsigned __int16 *)v105 + 62) )
            {
              v107 = v94;
              if ( v94 != 3 )
              {
                v108 = (char *)v105 + 126;
                if ( *(_DWORD *)a2 == *(_DWORD *)((char *)v105 + 126)
                  && *(unsigned __int16 *)(a2 + 4) == *((unsigned __int16 *)v105 + 65) )
                {
                  v107 = 3;
                }
                else
                {
                  v107 = v94;
                  if ( v94 == 4 )
                    goto LABEL_70;
                  v108 = v105 + 33;
                  v107 = v94;
                  if ( *(_DWORD *)a2 != v105[33] || *(unsigned __int16 *)(a2 + 4) != *((unsigned __int16 *)v105 + 68) )
                    goto LABEL_70;
                  v107 = 4;
                }
                goto LABEL_69;
              }
LABEL_70:
              qdf_trace_msg(
                0x53u,
                8u,
                "%s: peer remove from migrated list at index %d with max peer %d",
                v86,
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                v93,
                "nan_remove_peer_in_migrated_addr_list",
                v107,
                v94);
              v113 = (unsigned int *)((unsigned int)(unsigned __int8)(*((_BYTE *)v105 + 107))-- - 1);
              goto LABEL_71;
            }
            v107 = 2;
          }
        }
LABEL_69:
        qdf_mem_copy(v108, (const void *)(v104 + 6LL * (v94 - 1)), 6u);
        goto LABEL_70;
      }
      v64 = "%s: NAN PASN peer create ops is NULL";
    }
    else
    {
      v64 = "%s: psoc_nan_obj is null";
    }
    qdf_trace_msg(0x53u, 2u, v64, v33, v34, v35, v36, v37, v38, v39, v40, "ndi_add_pasn_peer_to_nan");
    v51 = 29;
    goto LABEL_36;
  }
LABEL_16:
  qdf_trace_msg(
    0x53u,
    8u,
    "%s: NAN pairing is not allowed",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "ndi_add_pasn_peer_to_nan");
  return 0;
}
