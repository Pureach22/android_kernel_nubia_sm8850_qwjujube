__int64 __fastcall ndi_cleanup_pasn_peer_from_nan(
        __int64 a1,
        unsigned int a2,
        const void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 comp_private_obj; // x0
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x24
  __int64 v25; // x0
  unsigned int v26; // w23
  _DWORD *v27; // x8
  __int64 v28; // x19
  unsigned int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w20
  const char *v39; // x2
  const char *v40; // x2
  const char *v42; // x2
  __int64 v43; // x0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x23
  __int64 v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w24
  unsigned int *v63; // x8
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned int *v72; // x8
  __int64 v73; // x25
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  unsigned int *v82; // x8
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  unsigned int v91; // w0

  if ( !a1 )
  {
    v40 = "%s: psoc is null";
LABEL_14:
    qdf_trace_msg(0x53u, 2u, v40, a4, a5, a6, a7, a8, a9, a10, a11, "nan_is_pairing_allowed");
    goto LABEL_15;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
  if ( !comp_private_obj )
  {
    v40 = "%s: psoc_nan_obj is NULL";
    goto LABEL_14;
  }
  if ( (*(_WORD *)(comp_private_obj + 232) & 0x100) != 0 && (*(_DWORD *)(comp_private_obj + 228) & 1) != 0 )
  {
    v15 = wlan_objmgr_psoc_get_comp_private_obj(a1, 0xFu);
    if ( v15 )
    {
      if ( *(_QWORD *)(v15 + 176) )
      {
        v24 = v15;
        v25 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_opmode_from_psoc)(a1, 16, 20);
        if ( v25 )
        {
          v26 = *(unsigned __int8 *)(v25 + 104);
          v27 = *(_DWORD **)(v24 + 176);
          v28 = v25;
          if ( *(v27 - 1) != -232243948 )
            __break(0x8228u);
          v29 = ((__int64 (__fastcall *)(__int64, _QWORD, const void *, __int64, _QWORD))v27)(a1, v26, a3, 13, 0);
          if ( v29 )
          {
            v38 = v29;
            v39 = "%s: NAN PASN peer delete request fails";
            goto LABEL_29;
          }
          v43 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v26, 20);
          if ( v43 )
          {
            v52 = v43;
            v53 = wlan_objmgr_vdev_get_comp_private_obj(v43, 0xFu);
            if ( v53 )
            {
              v62 = *(unsigned __int8 *)(v53 + 107);
              if ( v62 < 5 )
              {
                v73 = v53;
                qdf_mem_copy((void *)(v53 + 6LL * *(unsigned __int8 *)(v53 + 107) + 108), a3, 6u);
                qdf_trace_msg(
                  0x53u,
                  8u,
                  "%s: add peer to migrated list at index %d",
                  v74,
                  v75,
                  v76,
                  v77,
                  v78,
                  v79,
                  v80,
                  v81,
                  "nan_add_peer_in_migrated_addr_list",
                  v62);
                v82 = (unsigned int *)((unsigned int)(unsigned __int8)(*(_BYTE *)(v73 + 107))++ + 1);
                wlan_objmgr_vdev_release_ref(v52, 0x14u, v82, v83, v84, v85, v86, v87, v88, v89, v90);
                v91 = nan_set_ndi_vdev_id_for_migrated_peer(a1, a3, a2);
                if ( !v91 )
                {
                  v38 = 0;
                  goto LABEL_30;
                }
                v38 = v91;
                v39 = "%s: fail to add ndi vdev id in NAN peer";
LABEL_29:
                qdf_trace_msg(0x53u, 2u, v39, v30, v31, v32, v33, v34, v35, v36, v37, "ndi_cleanup_pasn_peer_from_nan");
LABEL_30:
                wlan_objmgr_vdev_release_ref(v28, 0x14u, v72, v30, v31, v32, v33, v34, v35, v36, v37);
                return v38;
              }
              qdf_trace_msg(
                0x53u,
                2u,
                "%s: num migrated peers %d more than max migrated peers",
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                v60,
                v61,
                "nan_add_peer_in_migrated_addr_list",
                *(unsigned __int8 *)(v53 + 107));
              v38 = 16;
            }
            else
            {
              qdf_trace_msg(
                0x53u,
                2u,
                "%s: NAN vdev priv obj is null",
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                v60,
                v61,
                "nan_add_peer_in_migrated_addr_list");
              v38 = 29;
            }
            wlan_objmgr_vdev_release_ref(v52, 0x14u, v63, v64, v65, v66, v67, v68, v69, v70, v71);
          }
          else
          {
            qdf_trace_msg(
              0x53u,
              2u,
              "%s: vdev is null",
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              "nan_add_peer_in_migrated_addr_list");
            v38 = 29;
          }
          v39 = "%s: fail to add peer addr in migrated list";
          goto LABEL_29;
        }
        v42 = "%s: Failed to get nan vdev";
      }
      else
      {
        v42 = "%s: NAN PASN peer delete ops is NULL";
      }
    }
    else
    {
      v42 = "%s: psoc_nan_obj is null";
    }
    qdf_trace_msg(0x53u, 2u, v42, v16, v17, v18, v19, v20, v21, v22, v23, "ndi_cleanup_pasn_peer_from_nan");
    return 29;
  }
LABEL_15:
  qdf_trace_msg(
    0x53u,
    8u,
    "%s: NAN pairing is not allowed",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "ndi_cleanup_pasn_peer_from_nan");
  return 0;
}
