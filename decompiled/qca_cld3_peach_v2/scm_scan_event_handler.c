__int64 __fastcall scm_scan_event_handler(
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
  unsigned int *v9; // x19
  __int64 v10; // x20
  __int64 comp_private_obj; // x22
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w24
  unsigned int time_of_the_day_ms; // w23
  __int64 v22; // x0
  unsigned int v23; // w9
  __int64 v24; // x11
  __int64 v25; // x10
  unsigned int *v26; // x12
  const char *v27; // x2
  __int64 result; // x0
  unsigned int *v29; // x10
  unsigned __int64 v30; // x24
  unsigned __int8 *v31; // x23
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  _QWORD *v41; // x22
  unsigned int v42; // w8
  int v43; // w8
  unsigned __int64 StatusReg; // x8
  __int64 v45; // x8
  void (__fastcall *v46)(__int64, unsigned int *, __int64); // x24
  __int64 v47; // x23
  unsigned int v48; // w8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x8
  __int64 v58; // x0
  const char *v59; // x2
  unsigned int v60; // w1
  unsigned __int8 *v61; // x4
  _QWORD *v62; // x5
  __int64 scan_cmd_using_scan_id; // x0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x2
  unsigned int v73; // w8
  unsigned int v74; // w8
  const char *v75; // x2
  unsigned int *v76; // x8
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  unsigned int v85; // [xsp+10h] [xbp-70h]
  __int64 v86; // [xsp+28h] [xbp-58h] BYREF
  __int64 v87; // [xsp+30h] [xbp-50h]
  __int64 v88; // [xsp+38h] [xbp-48h]
  __int64 v89; // [xsp+40h] [xbp-40h]
  __int64 v90; // [xsp+48h] [xbp-38h]
  __int64 v91; // [xsp+50h] [xbp-30h]
  __int64 v92; // [xsp+58h] [xbp-28h] BYREF
  unsigned int v93; // [xsp+60h] [xbp-20h]
  int v94; // [xsp+64h] [xbp-1Ch]
  __int64 v95; // [xsp+68h] [xbp-18h]
  __int64 v96; // [xsp+70h] [xbp-10h]
  __int64 v97; // [xsp+78h] [xbp-8h]

  v97 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v90 = 0;
  v91 = 0;
  v88 = 0;
  v89 = 0;
  v86 = 0;
  v87 = 0;
  if ( !a1 )
    goto LABEL_15;
  v9 = *(unsigned int **)(a1 + 8);
  if ( !v9 )
  {
    v27 = "%s: NULL scan event received";
    goto LABEL_17;
  }
  v10 = *(_QWORD *)v9;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v9 + 216LL) + 80LL), 3u);
  if ( !comp_private_obj )
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_pdev_get_scan_obj",
      764);
  v85 = v9[7];
  qdf_trace_msg(
    0x15u,
    8u,
    "%s: vdevid:%d, type:%d, reason:%d, freq:%d, reqstr:%d,scanid:%d (0x%x), timestamp:%u",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "scm_scan_event_handler",
    v9[2],
    v9[3],
    v9[4],
    v9[5],
    v9[6],
    v85,
    v85,
    v9[8]);
  if ( v9[3] != 3 )
    goto LABEL_22;
  v20 = v9[5];
  time_of_the_day_ms = qdf_get_time_of_the_day_ms();
  v22 = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(*(_QWORD *)(v10 + 216) + 80LL), 3u);
  if ( !v22 )
  {
    qdf_trace_msg(
      0x15u,
      2u,
      "%s: %s:%u, Failed to get scan object",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_psoc_get_scan_obj_fl",
      "wlan_pdev_get_scan_obj",
      764);
    goto LABEL_22;
  }
  if ( !*(_BYTE *)(*(_QWORD *)(v10 + 216) + 40LL) )
  {
    v23 = *(unsigned __int8 *)(v22 + 17524);
    if ( *(_BYTE *)(v22 + 17524) )
    {
      v24 = 0;
      v25 = *(unsigned __int8 *)(v22 + 17524);
      v26 = (unsigned int *)(v22 + 17532);
      while ( v24 != 102 )
      {
        if ( *(v26 - 1) == v20 )
        {
          *v26 = time_of_the_day_ms;
          goto LABEL_22;
        }
        ++v24;
        v26 += 2;
        if ( *(unsigned __int8 *)(v22 + 17524) == v24 )
        {
          if ( v23 <= 0x65 )
            goto LABEL_20;
          goto LABEL_14;
        }
      }
      goto LABEL_14;
    }
    v25 = 0;
LABEL_20:
    *(_BYTE *)(v22 + 17524) = v23 + 1;
    v29 = (unsigned int *)(v22 + 8 * v25 + 17528);
    *v29 = v20;
    v29[1] = time_of_the_day_ms;
LABEL_22:
    if ( v9[3] - 11 <= 1 )
    {
      v30 = qdf_get_time_of_the_day_ms();
      v31 = (unsigned __int8 *)wlan_objmgr_vdev_get_comp_private_obj(v10, 3u);
      v32 = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(*(_QWORD *)(v10 + 216) + 80LL), 3u);
      v41 = (_QWORD *)v32;
      if ( v32 )
      {
        if ( v31 )
        {
          v42 = v9[3];
          if ( v42 != 12 )
          {
            if ( v42 == 11 )
            {
              v43 = *v31;
              *((_QWORD *)v31 + 2) = v30;
              if ( v43 == 1 )
              {
                qdf_wake_lock_release(v32 + 18384, 0xDu);
                qdf_wake_lock_timeout_acquire((__int64)(v41 + 2298), 1000);
                qdf_runtime_pm_allow_suspend(v41 + 2323);
                *v31 = 0;
                if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                  || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
                  || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                {
                  raw_spin_lock(v41 + 1);
                  v45 = v41[2];
                }
                else
                {
                  raw_spin_lock_bh(v41 + 1);
                  v45 = v41[2] | 1LL;
                  v41[2] = v45;
                }
                v46 = (void (__fastcall *)(__int64, unsigned int *, __int64))v41[2324];
                v47 = v41[2325];
                if ( (v45 & 1) != 0 )
                {
                  v41[2] = v45 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(v41 + 1);
                  if ( v46 )
                    goto LABEL_34;
                }
                else
                {
                  raw_spin_unlock(v41 + 1);
                  if ( v46 )
                  {
LABEL_34:
                    if ( *((_DWORD *)v46 - 1) != 2096486875 )
                      __break(0x8238u);
                    v46(v10, v9 + 2, v47);
                  }
                }
              }
            }
LABEL_63:
            _qdf_mem_free((__int64)v9);
            wlan_objmgr_vdev_release_ref(v10, 0xCu, v76, v77, v78, v79, v80, v81, v82, v83, v84);
            result = 0;
            goto LABEL_64;
          }
          v62 = *((_QWORD **)v31 + 2);
          if ( (((v30 - (_QWORD)v62 - 1000) & ((unsigned __int64)v62 - v30) & 0x8000000000000000LL) != 0LL) == __OFSUB__(v42, 12) )
          {
            *v31 = 1;
            qdf_wake_lock_timeout_acquire(v32 + 18384, 5000);
            qdf_runtime_pm_prevent_suspend(v41 + 2323);
            goto LABEL_63;
          }
          v59 = "%s: Drop duplicate NLO_MATCH current time = %ld, pno complete time = %ld";
          v60 = 8;
          v61 = (unsigned __int8 *)v30;
LABEL_43:
          qdf_trace_msg(0x15u, v60, v59, v33, v34, v35, v36, v37, v38, v39, v40, "scm_pno_event_handler", v61, v62);
          goto LABEL_63;
        }
      }
      else
      {
        qdf_trace_msg(
          0x15u,
          2u,
          "%s: %s:%u, Failed to get scan object",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "wlan_psoc_get_scan_obj_fl",
          "wlan_pdev_get_scan_obj",
          764);
      }
      v59 = "%s: null scan_vdev_obj %pK scan_obj %pK";
      v60 = 2;
      v61 = v31;
      v62 = v41;
      goto LABEL_43;
    }
    v48 = v9[7];
    v87 = 0;
    LODWORD(v86) = 0;
    HIDWORD(v86) = v48;
    LODWORD(v88) = 3;
    BYTE4(v88) = 0;
    v90 = v10;
    v91 = 0;
    if ( (wlan_serialization_is_cmd_present_in_active_queue(a2, a3, a4, a5, a6, a7, a8, a9, 0, (unsigned int *)&v86) & 1) == 0 )
    {
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: Received scan event while request not in active queue",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "scm_scan_event_handler");
      goto LABEL_63;
    }
    v57 = *(_QWORD *)(v10 + 216);
    if ( v57 )
      v58 = *(_QWORD *)(v57 + 80);
    else
      v58 = 0;
    scan_cmd_using_scan_id = wlan_serialization_get_scan_cmd_using_scan_id(
                               v58,
                               *(unsigned __int8 *)(v10 + 168),
                               v9[7],
                               1,
                               v49,
                               v50,
                               v51,
                               v52,
                               v53,
                               v54,
                               v55,
                               v56);
    if ( scan_cmd_using_scan_id )
    {
      v72 = *(_QWORD *)(scan_cmd_using_scan_id + 40);
      if ( v72 )
      {
        if ( *(_DWORD *)(v72 + 12) != v9[6] )
        {
          qdf_trace_msg(
            0x15u,
            2u,
            "%s: req ID mismatch, scan_req_id:%d, event_req_id:%d",
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            "scm_scan_event_handler");
          goto LABEL_63;
        }
        if ( comp_private_obj )
          scm_scan_update_scan_event(comp_private_obj, (_DWORD)v9 + 8, v72);
        v73 = v9[3];
        if ( v73 != 6 && v73 != 4 )
        {
          if ( v73 != 1 )
          {
LABEL_56:
            ((void (__fastcall *)(__int64, unsigned int *))scm_scan_post_event)(v10, v9 + 2);
            goto LABEL_63;
          }
          if ( v9[4] == 1 )
            scm_11d_decide_country_code(v10);
        }
        v74 = v9[7];
        v92 = 3;
        v93 = v74;
        v94 = 0;
        v95 = v10;
        v96 = 1;
        wlan_serialization_remove_cmd((unsigned int *)&v92, v64, v65, v66, v67, v68, v69, v70, v71);
        goto LABEL_56;
      }
      v75 = "%s: NULL umac_cmd";
    }
    else
    {
      v75 = "%s: NULL queued_cmd";
    }
    qdf_trace_msg(0x15u, 2u, v75, v64, v65, v66, v67, v68, v69, v70, v71, "scm_scan_event_handler");
    goto LABEL_63;
  }
LABEL_14:
  __break(0x5512u);
LABEL_15:
  v27 = "%s: NULL msg received ";
LABEL_17:
  qdf_trace_msg(0x15u, 2u, v27, a2, a3, a4, a5, a6, a7, a8, a9, "scm_scan_event_handler");
  result = 29;
LABEL_64:
  _ReadStatusReg(SP_EL0);
  return result;
}
