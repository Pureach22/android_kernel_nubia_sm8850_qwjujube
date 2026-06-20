__int64 __fastcall policy_mgr_get_connection_count_with_mlo(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  char is_mlo_vdev; // w22
  unsigned int *v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w21
  int v33; // w24
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x22
  char v44; // w23
  unsigned int *v45; // x8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  int v54; // w8
  __int64 v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x22
  char v65; // w23
  unsigned int *v66; // x8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  int v75; // w8
  __int64 v76; // x0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x22
  char v86; // w23
  unsigned int *v87; // x8
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  int v96; // w8
  __int64 v97; // x0
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  __int64 v106; // x20
  char v107; // w22
  unsigned int *v108; // x8
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v11 = context;
    qdf_mutex_acquire(context + 56);
    if ( BYTE4(qword_8D4F00) == 1 )
    {
      v12 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              (unsigned int)qword_8D4F00,
              24);
      if ( v12
        && (v21 = v12,
            is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v12, v13, v14, v15, v16, v17, v18, v19, v20),
            wlan_objmgr_vdev_release_ref(v21, 0x18u, v23, v24, v25, v26, v27, v28, v29, v30, v31),
            (is_mlo_vdev & 1) != 0)
        && !(_DWORD)pm_conc_connection_list )
      {
        v32 = 1;
        v33 = 1;
      }
      else
      {
        v33 = 0;
        v32 = 1;
      }
    }
    else
    {
      v32 = 0;
      v33 = 0;
    }
    if ( BYTE4(qword_8D4F24) == 1 )
    {
      v34 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              (unsigned int)qword_8D4F24,
              24);
      if ( v34
        && (v43 = v34,
            v44 = wlan_vdev_mlme_is_mlo_vdev(v34, v35, v36, v37, v38, v39, v40, v41, v42),
            wlan_objmgr_vdev_release_ref(v43, 0x18u, v45, v46, v47, v48, v49, v50, v51, v52, v53),
            (v44 & 1) != 0)
        && !(_DWORD)qword_8D4F0C )
      {
        v54 = v33 ^ 1;
        v33 = 1;
        v32 += v54;
      }
      else
      {
        ++v32;
      }
    }
    if ( BYTE4(qword_8D4F48) == 1 )
    {
      v55 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              (unsigned int)qword_8D4F48,
              24);
      if ( v55
        && (v64 = v55,
            v65 = wlan_vdev_mlme_is_mlo_vdev(v55, v56, v57, v58, v59, v60, v61, v62, v63),
            wlan_objmgr_vdev_release_ref(v64, 0x18u, v66, v67, v68, v69, v70, v71, v72, v73, v74),
            (v65 & 1) != 0)
        && !(_DWORD)qword_8D4F30 )
      {
        v75 = v33 ^ 1;
        v33 = 1;
        v32 += v75;
      }
      else
      {
        ++v32;
      }
    }
    if ( BYTE4(qword_8D4F6C) == 1 )
    {
      v76 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              (unsigned int)qword_8D4F6C,
              24);
      if ( v76
        && (v85 = v76,
            v86 = wlan_vdev_mlme_is_mlo_vdev(v76, v77, v78, v79, v80, v81, v82, v83, v84),
            wlan_objmgr_vdev_release_ref(v85, 0x18u, v87, v88, v89, v90, v91, v92, v93, v94, v95),
            (v86 & 1) != 0)
        && !(_DWORD)qword_8D4F54 )
      {
        v96 = v33 ^ 1;
        v33 = 1;
        v32 += v96;
      }
      else
      {
        ++v32;
      }
    }
    if ( BYTE4(qword_8D4F90) == 1 )
    {
      v97 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              (unsigned int)qword_8D4F90,
              24);
      if ( v97
        && (v106 = v97,
            v107 = wlan_vdev_mlme_is_mlo_vdev(v97, v98, v99, v100, v101, v102, v103, v104, v105),
            wlan_objmgr_vdev_release_ref(v106, 0x18u, v108, v109, v110, v111, v112, v113, v114, v115, v116),
            (v107 & 1) != 0)
        && !(_DWORD)qword_8D4F78 )
      {
        v32 += v33 ^ 1;
      }
      else
      {
        ++v32;
      }
    }
    qdf_mutex_release(v11 + 56);
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "policy_mgr_get_connection_count_with_mlo");
    return 0;
  }
  return v32;
}
