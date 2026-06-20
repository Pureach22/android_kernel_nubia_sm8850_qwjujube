__int64 __fastcall policy_mgr_mode_specific_connection_count_with_mlo(__int64 a1, int a2)
{
  __int64 context; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  unsigned int v14; // w20
  int v15; // w25
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x20
  char is_mlo_vdev; // w23
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x23
  char v46; // w24
  unsigned int *v47; // x8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w8
  __int64 v57; // x0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x23
  char v67; // w24
  unsigned int *v68; // x8
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  int v77; // w8
  __int64 v78; // x0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x23
  char v88; // w24
  unsigned int *v89; // x8
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  int v98; // w8
  __int64 v99; // x0
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  __int64 v108; // x21
  char v109; // w22
  unsigned int *v110; // x8
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v13 = context;
    qdf_mutex_acquire(context + 56);
    v14 = 0;
    if ( BYTE4(qword_8D4F00) == 1 )
    {
      v15 = 0;
      if ( (_DWORD)pm_conc_connection_list == a2 )
      {
        v16 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                a1,
                (unsigned int)qword_8D4F00,
                24);
        if ( v16
          && (v25 = v16,
              is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v16, v17, v18, v19, v20, v21, v22, v23, v24),
              wlan_objmgr_vdev_release_ref(v25, 0x18u, v27, v28, v29, v30, v31, v32, v33, v34, v35),
              (is_mlo_vdev & 1) != 0) )
        {
          v14 = 1;
          v15 = 1;
        }
        else
        {
          v15 = 0;
          v14 = 1;
        }
      }
    }
    else
    {
      v15 = 0;
    }
    if ( BYTE4(qword_8D4F24) == 1 && (_DWORD)qword_8D4F0C == a2 )
    {
      v36 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              (unsigned int)qword_8D4F24,
              24);
      if ( v36
        && (v45 = v36,
            v46 = wlan_vdev_mlme_is_mlo_vdev(v36, v37, v38, v39, v40, v41, v42, v43, v44),
            wlan_objmgr_vdev_release_ref(v45, 0x18u, v47, v48, v49, v50, v51, v52, v53, v54, v55),
            (v46 & 1) != 0) )
      {
        v56 = v15 ^ 1;
        v15 = 1;
        v14 += v56;
      }
      else
      {
        ++v14;
      }
    }
    if ( BYTE4(qword_8D4F48) == 1 && (_DWORD)qword_8D4F30 == a2 )
    {
      v57 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              (unsigned int)qword_8D4F48,
              24);
      if ( v57
        && (v66 = v57,
            v67 = wlan_vdev_mlme_is_mlo_vdev(v57, v58, v59, v60, v61, v62, v63, v64, v65),
            wlan_objmgr_vdev_release_ref(v66, 0x18u, v68, v69, v70, v71, v72, v73, v74, v75, v76),
            (v67 & 1) != 0) )
      {
        v77 = v15 ^ 1;
        v15 = 1;
        v14 += v77;
      }
      else
      {
        ++v14;
      }
    }
    if ( BYTE4(qword_8D4F6C) == 1 && (_DWORD)qword_8D4F54 == a2 )
    {
      v78 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              (unsigned int)qword_8D4F6C,
              24);
      if ( v78
        && (v87 = v78,
            v88 = wlan_vdev_mlme_is_mlo_vdev(v78, v79, v80, v81, v82, v83, v84, v85, v86),
            wlan_objmgr_vdev_release_ref(v87, 0x18u, v89, v90, v91, v92, v93, v94, v95, v96, v97),
            (v88 & 1) != 0) )
      {
        v98 = v15 ^ 1;
        v15 = 1;
        v14 += v98;
      }
      else
      {
        ++v14;
      }
    }
    if ( BYTE4(qword_8D4F90) == 1 && (_DWORD)qword_8D4F78 == a2 )
    {
      v99 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              (unsigned int)qword_8D4F90,
              24);
      if ( v99
        && (v108 = v99,
            v109 = wlan_vdev_mlme_is_mlo_vdev(v99, v100, v101, v102, v103, v104, v105, v106, v107),
            wlan_objmgr_vdev_release_ref(v108, 0x18u, v110, v111, v112, v113, v114, v115, v116, v117, v118),
            (v109 & 1) != 0) )
      {
        v14 += v15 ^ 1;
      }
      else
      {
        ++v14;
      }
    }
    qdf_mutex_release(v13 + 56);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "policy_mgr_mode_specific_connection_count_with_mlo");
    return 0;
  }
  return v14;
}
