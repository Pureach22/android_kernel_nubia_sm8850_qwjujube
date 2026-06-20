__int64 __fastcall mlo_fw_roam_sync_req(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned __int64 v15; // x21
  unsigned int *v16; // x27
  unsigned __int64 v17; // x4
  int v18; // w26
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x25
  unsigned int *v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  _QWORD *v38; // x9
  __int64 v39; // x10
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int *v49; // x8
  __int64 v50; // x23
  __int64 result; // x0
  unsigned __int16 *v52; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned __int8 *v61; // x23
  unsigned int *v62; // x8
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  const char *v71; // x2
  const char *v72; // x3
  __int64 v73; // x0
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  unsigned int *v82; // x8
  __int64 v83; // x23
  char v84; // w1
  __int64 mlo_ctx; // x0
  __int64 v86; // x23
  unsigned __int64 v87; // x25
  unsigned __int8 *v88; // x27
  unsigned int v89; // w21
  __int64 v90; // x0
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  _QWORD *v99; // x8
  __int64 v100; // x19
  int v101; // w8
  int v102; // w9
  int v103; // w10
  int v104; // w11
  int v105; // w9
  unsigned int *v106; // x8
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  unsigned int v115; // w28
  unsigned __int8 *v116; // x21
  __int64 v118; // x0
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  __int64 v127; // x26
  _DWORD *v128; // x24
  unsigned int (__fastcall *v130)(__int64, __int64, unsigned __int8 *); // x8
  double v131; // d0
  double v132; // d1
  double v133; // d2
  double v134; // d3
  double v135; // d4
  double v136; // d5
  double v137; // d6
  double v138; // d7
  __int64 v139; // [xsp+0h] [xbp-50h]
  __int64 v140; // [xsp+8h] [xbp-48h]
  __int64 v141; // [xsp+10h] [xbp-40h]
  __int64 v142; // [xsp+18h] [xbp-38h]
  __int64 v143; // [xsp+20h] [xbp-30h]
  int v144; // [xsp+30h] [xbp-20h]

  _ReadStatusReg(SP_EL0);
  if ( !a3 )
  {
    result = 16;
    goto LABEL_53;
  }
  if ( !*(_BYTE *)(a3 + 2497) )
    goto LABEL_20;
  v15 = 0;
  v16 = (unsigned int *)(a3 + 2500);
  do
  {
    if ( v15 == 3 )
      goto LABEL_78;
    v18 = *v16;
    v19 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *v16, 1);
    if ( v19 )
    {
      v28 = v19;
      wlan_vdev_mlme_set_mlo_vdev(v19, v20, v21, v22, v23, v24, v25, v26, v27);
      if ( (unsigned __int8)v18 == (unsigned __int8)a2 )
        goto LABEL_5;
      wlan_vdev_mlme_set_mlo_link_vdev(v28, v30, v31, v32, v33, v34, v35, v36, v37);
      v38 = *(_QWORD **)(v28 + 1360);
      if ( !v38 )
        goto LABEL_5;
      v29 = (unsigned int *)v38[278];
      if ( !v29 )
        goto LABEL_5;
      if ( v38[3] == v28 )
      {
        v39 = *(_QWORD *)v29 | 1LL;
        *(_QWORD *)v29 = v39;
        if ( v38[4] != v28 )
          goto LABEL_5;
      }
      else
      {
        if ( v38[4] != v28 )
          goto LABEL_5;
        v39 = *(_QWORD *)v29;
      }
      *(_QWORD *)v29 = v39 | 2;
LABEL_5:
      wlan_objmgr_vdev_release_ref(v28, 1u, v29, v30, v31, v32, v33, v34, v35, v36, v37);
      goto LABEL_6;
    }
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: VDEV is null",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "mlo_update_for_multi_link_roam");
LABEL_6:
    v17 = *(unsigned __int8 *)(a3 + 2497);
    ++v15;
    v16 += 13;
  }
  while ( v15 < v17 );
  if ( (_DWORD)v17 == 1 )
    goto LABEL_32;
  if ( !*(_BYTE *)(a3 + 2497) )
  {
LABEL_20:
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: MLO_ROAM: Roamed to Legacy",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "mlo_fw_roam_sync_req");
    v40 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
    if ( v40 )
    {
      v49 = (unsigned int *)*(unsigned __int8 *)(v40 + 60);
      if ( ((unsigned __int8)v49 & 2) == 0 )
      {
        v50 = v40;
        mlme_set_single_link_mlo_roaming(v40, 0, v41, v42, v43, v44, v45, v46, v47, v48);
        v40 = v50;
      }
      wlan_objmgr_vdev_release_ref(v40, 1u, v49, v41, v42, v43, v44, v45, v46, v47, v48);
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: VDEV is null",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "mlo_set_single_link_ml_roaming");
    }
    v52 = (unsigned __int16 *)((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                                a1,
                                a2,
                                90);
    if ( v52 )
    {
      v61 = (unsigned __int8 *)v52;
      if ( *((_DWORD *)v52 + 20) | v52[42] )
        qdf_mem_copy(v52 + 37, v52 + 40, 6u);
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: vdev_id %d self mac %02x:%02x:%02x:**:**:%02x",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "mlo_roam_update_vdev_macaddr",
        (unsigned __int8)a2,
        v61[74],
        v61[75],
        v61[76],
        v61[79]);
      wlan_objmgr_vdev_release_ref((__int64)v61, 0x5Au, v62, v63, v64, v65, v66, v67, v68, v69, v70);
      goto LABEL_45;
    }
    v71 = "%s: VDEV is null";
    v72 = "mlo_roam_update_vdev_macaddr";
LABEL_44:
    qdf_trace_msg(0x8Fu, 2u, v71, v53, v54, v55, v56, v57, v58, v59, v60, v72);
    goto LABEL_45;
  }
  if ( *(_DWORD *)(a3 + 56) == 1 )
  {
LABEL_32:
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: MLO_ROAM: Roamed to single link MLO",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "mlo_fw_roam_sync_req");
    v73 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
    if ( v73 )
    {
      v82 = (unsigned int *)*(unsigned __int8 *)(v73 + 60);
      if ( ((unsigned __int8)v82 & 2) == 0 )
      {
        v83 = v73;
        v84 = 1;
        goto LABEL_38;
      }
      goto LABEL_39;
    }
LABEL_42:
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: VDEV is null",
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      "mlo_set_single_link_ml_roaming");
    mlo_ctx = wlan_objmgr_get_mlo_ctx();
    if ( !mlo_ctx )
      goto LABEL_43;
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: MLO_ROAM: Roamed to MLO with %d links",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "mlo_fw_roam_sync_req");
    v73 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
    if ( !v73 )
      goto LABEL_42;
    v82 = (unsigned int *)*(unsigned __int8 *)(v73 + 60);
    if ( ((unsigned __int8)v82 & 2) == 0 )
    {
      v83 = v73;
      v84 = 0;
LABEL_38:
      mlme_set_single_link_mlo_roaming(v73, v84, v74, v75, v76, v77, v78, v79, v80, v81);
      v73 = v83;
    }
LABEL_39:
    wlan_objmgr_vdev_release_ref(v73, 1u, v82, v74, v75, v76, v77, v78, v79, v80, v81);
    mlo_ctx = wlan_objmgr_get_mlo_ctx();
    if ( !mlo_ctx )
    {
LABEL_43:
      v71 = "%s: Invalid mlo ctx";
      v72 = "mlo_roam_update_all_vdev_macaddr";
      goto LABEL_44;
    }
  }
  if ( *(_BYTE *)(a3 + 2497) )
  {
    v86 = mlo_ctx;
    v87 = 0;
    v88 = (unsigned __int8 *)(a3 + 2551);
    v144 = *(unsigned __int8 *)(a3 + 13);
    while ( v87 != 3 )
    {
      v115 = *(v88 - 51);
      if ( v115 != 255 )
      {
        v116 = v88 - 5;
        if ( *(_DWORD *)(v88 - 5) | *(unsigned __int16 *)(v88 - 1) )
        {
          if ( *(_DWORD *)v116 != -1 || *(__int16 *)(v88 - 1) != -1 )
          {
            v118 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                     a1,
                     *(v88 - 51),
                     90);
            if ( v118 )
            {
              v127 = v118;
              if ( v144 != v115 )
              {
                v128 = (_DWORD *)(v118 + 86);
                if ( *(_DWORD *)v116 != *(_DWORD *)(v118 + 86)
                  || *(unsigned __int16 *)(v88 - 1) != *(unsigned __int16 *)(v118 + 90) )
                {
                  v130 = *(unsigned int (__fastcall **)(__int64, __int64, unsigned __int8 *))(*(_QWORD *)(v86 + 360)
                                                                                            + 16LL);
                  if ( *((_DWORD *)v130 - 1) != -812663418 )
                    __break(0x8228u);
                  if ( v130(v118, v118 + 86, v88 - 5) )
                  {
                    if ( v88 == (_BYTE *)&off_0 + 5 )
                    {
                      v103 = 0;
                      v101 = 0;
                      v102 = 0;
                      v104 = 0;
                    }
                    else
                    {
                      v101 = *(v88 - 5);
                      v102 = *(v88 - 4);
                      v103 = *(v88 - 3);
                      v104 = *v88;
                    }
                    LODWORD(v143) = v104;
                    LODWORD(v142) = v103;
                    LODWORD(v141) = v102;
                    LODWORD(v140) = v101;
                    LODWORD(v139) = *(unsigned __int8 *)(v127 + 91);
                    qdf_trace_msg(
                      0x8Fu,
                      2u,
                      "%s: vdev id %d failed to change self mac %02x:%02x:%02x:**:**:%02x to %02x:%02x:%02x:**:**:%02x",
                      v131,
                      v132,
                      v133,
                      v134,
                      v135,
                      v136,
                      v137,
                      v138,
                      "mlo_roam_update_all_vdev_macaddr",
                      v115,
                      *(unsigned __int8 *)(v127 + 86),
                      *(unsigned __int8 *)(v127 + 87),
                      *(unsigned __int8 *)(v127 + 88),
                      v139,
                      v140,
                      v141,
                      v142,
                      v143);
                  }
                  v105 = *(_DWORD *)v116;
                  *(_WORD *)(v127 + 90) = *(_WORD *)(v88 - 1);
                  *v128 = v105;
                }
              }
              qdf_mem_copy((void *)(v127 + 74), v88 - 5, 6u);
              wlan_objmgr_vdev_release_ref(v127, 0x5Au, v106, v107, v108, v109, v110, v111, v112, v113, v114);
            }
            else
            {
              qdf_trace_msg(
                0x8Fu,
                2u,
                "%s: Invalid vdev %d",
                v119,
                v120,
                v121,
                v122,
                v123,
                v124,
                v125,
                v126,
                "mlo_roam_update_all_vdev_macaddr",
                v115);
            }
          }
        }
      }
      ++v87;
      v88 += 52;
      if ( v87 >= *(unsigned __int8 *)(a3 + 2497) )
        goto LABEL_45;
    }
LABEL_78:
    __break(0x5512u);
  }
LABEL_45:
  ml_nlink_conn_change_notify(a1, a2, 2, 0);
  result = cm_fw_roam_sync_req(a1, a2, (unsigned __int8 *)a3, a4);
  if ( (_DWORD)result )
  {
    v89 = result;
    v90 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
    if ( v90 )
    {
      v99 = *(_QWORD **)(v90 + 1360);
      if ( v99 )
      {
        v99 = (_QWORD *)v99[278];
        if ( v99 )
        {
          v100 = v90;
          qdf_mem_set(v99, 8u, 0);
          v90 = v100;
        }
      }
      wlan_objmgr_vdev_release_ref(v90, 1u, (unsigned int *)v99, v91, v92, v93, v94, v95, v96, v97, v98);
    }
    else
    {
      qdf_trace_msg(0x8Fu, 2u, "%s: VDEV is null", v91, v92, v93, v94, v95, v96, v97, v98, "mlo_clear_link_bmap");
    }
    result = v89;
  }
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return result;
}
