__int64 __fastcall policy_mgr_is_mlo_sta_present(__int64 a1)
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
  __int64 v21; // x22
  char is_mlo_vdev; // w21
  unsigned int *v23; // x8
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
  __int64 v41; // x22
  unsigned int *v42; // x8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x22
  unsigned int *v61; // x8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x22
  unsigned int *v80; // x8
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 v89; // x0
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  __int64 v98; // x20
  unsigned int *v99; // x8
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v11 = context;
    qdf_mutex_acquire(context + 56);
    if ( (_DWORD)pm_conc_connection_list
      || BYTE4(qword_8D4F00) != 1
      || (v12 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                  a1,
                  (unsigned int)qword_8D4F00,
                  24)) == 0
      || (v21 = v12,
          is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v12, v13, v14, v15, v16, v17, v18, v19, v20),
          wlan_objmgr_vdev_release_ref(v21, 0x18u, v23, v24, v25, v26, v27, v28, v29, v30, v31),
          (is_mlo_vdev & 1) == 0) )
    {
      if ( (_DWORD)qword_8D4F0C
        || BYTE4(qword_8D4F24) != 1
        || (v32 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                    a1,
                    (unsigned int)qword_8D4F24,
                    24)) == 0
        || (v41 = v32,
            is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v32, v33, v34, v35, v36, v37, v38, v39, v40),
            wlan_objmgr_vdev_release_ref(v41, 0x18u, v42, v43, v44, v45, v46, v47, v48, v49, v50),
            (is_mlo_vdev & 1) == 0) )
      {
        if ( (_DWORD)qword_8D4F30
          || BYTE4(qword_8D4F48) != 1
          || (v51 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                      a1,
                      (unsigned int)qword_8D4F48,
                      24)) == 0
          || (v60 = v51,
              is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v51, v52, v53, v54, v55, v56, v57, v58, v59),
              wlan_objmgr_vdev_release_ref(v60, 0x18u, v61, v62, v63, v64, v65, v66, v67, v68, v69),
              (is_mlo_vdev & 1) == 0) )
        {
          if ( !(_DWORD)qword_8D4F54
            && BYTE4(qword_8D4F6C) == 1
            && (v70 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                        a1,
                        (unsigned int)qword_8D4F6C,
                        24)) != 0 )
          {
            v79 = v70;
            is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v70, v71, v72, v73, v74, v75, v76, v77, v78);
            wlan_objmgr_vdev_release_ref(v79, 0x18u, v80, v81, v82, v83, v84, v85, v86, v87, v88);
          }
          else
          {
            is_mlo_vdev = 0;
          }
          if ( (is_mlo_vdev & 1) == 0 )
          {
            if ( !(_DWORD)qword_8D4F78
              && BYTE4(qword_8D4F90) == 1
              && (v89 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                          a1,
                          (unsigned int)qword_8D4F90,
                          24)) != 0 )
            {
              v98 = v89;
              is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v89, v90, v91, v92, v93, v94, v95, v96, v97);
              wlan_objmgr_vdev_release_ref(v98, 0x18u, v99, v100, v101, v102, v103, v104, v105, v106, v107);
            }
            else
            {
              is_mlo_vdev = 0;
            }
          }
        }
      }
    }
    qdf_mutex_release(v11 + 56);
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v3, v4, v5, v6, v7, v8, v9, v10, "policy_mgr_is_mlo_sta_present");
    is_mlo_vdev = 0;
  }
  return is_mlo_vdev & 1;
}
