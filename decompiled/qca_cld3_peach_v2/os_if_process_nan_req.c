__int64 __fastcall os_if_process_nan_req(__int64 a1, unsigned int a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x20
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  const char *v15; // x2
  const char *v16; // x3
  __int64 result; // x0
  __int64 v18; // x4
  __int64 v19; // x22
  unsigned int v20; // w23
  int v21; // w25
  unsigned __int16 v22; // w22
  void *v23; // x0
  __int64 v24; // x19
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w20
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  const char *v42; // x2
  unsigned int v43; // w1
  const void *v44; // x21
  __int16 v45; // w23
  __int64 v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int *v55; // x8
  __int64 v56; // x19
  unsigned int v57; // w22
  unsigned int *v58; // x8
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w0
  const char *v68; // x2
  const char *v69; // x3
  unsigned __int16 v70; // w24
  __int64 v71; // x0
  __int64 v72; // x20
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  char disable_6g_nan; // w0
  _WORD *v82; // x1
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  unsigned int v99; // w21
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  int v108; // [xsp+Ch] [xbp-34h] BYREF
  __int64 v109; // [xsp+10h] [xbp-30h] BYREF
  _WORD *v110; // [xsp+18h] [xbp-28h]
  __int64 v111; // [xsp+20h] [xbp-20h]
  __int64 v112; // [xsp+28h] [xbp-18h]
  __int64 v113; // [xsp+30h] [xbp-10h]
  __int64 v114; // [xsp+38h] [xbp-8h]

  v114 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 80);
  v112 = 0;
  v113 = 0;
  v110 = nullptr;
  v111 = 0;
  v109 = 0;
  if ( (unsigned int)_nla_parse(&v109, 4, a3, a4, &nan_attr_policy, 31, 0) )
  {
    v15 = "%s: Invalid NAN vendor command attributes";
LABEL_3:
    v16 = "os_if_process_nan_req";
LABEL_4:
    qdf_trace_msg(0x48u, 2u, v15, v7, v8, v9, v10, v11, v12, v13, v14, v16);
LABEL_5:
    result = 4294967274LL;
    goto LABEL_6;
  }
  if ( !v110 )
  {
    v15 = "%s: NAN cmd data missing!";
    goto LABEL_3;
  }
  if ( (ucfg_is_nan_dbs_supported(v6, v7, v8, v9, v10, v11, v12, v13, v14) & 1) == 0
    && (ucfg_is_nan_conc_control_supported(v6, v7, v8, v9, v10, v11, v12, v13, v14) & 1) == 0 )
  {
    policy_mgr_check_and_stop_opportunistic_timer(v6, a2);
  }
  if ( !v111 )
  {
    v22 = *v110 - 4;
    v23 = (void *)_qdf_mem_malloc(v22 + 24LL, "os_if_nan_generic_req", 2934);
    if ( v23 )
    {
      v24 = (__int64)v23;
      qdf_mem_set(v23, (unsigned int)v22 + 24, 0);
      *(_QWORD *)v24 = v6;
      *(_WORD *)(v24 + 8) = v22;
      nla_memcpy(v24 + 17, v110, v22);
      v33 = ucfg_nan_discovery_req((__int64 *)v24, 0, v25, v26, v27, v28, v29, v30, v31, v32);
      if ( v33 )
      {
        v42 = "%s: Unable to send a NAN request";
        v43 = 2;
      }
      else
      {
        v42 = "%s: Successfully sent a NAN request";
        v43 = 8;
      }
      qdf_trace_msg(0x48u, v43, v42, v34, v35, v36, v37, v38, v39, v40, v41, "os_if_nan_generic_req");
      _qdf_mem_free(v24);
      result = qdf_status_to_os_return(v33);
      goto LABEL_6;
    }
LABEL_40:
    result = 4294967284LL;
    goto LABEL_6;
  }
  v18 = *(unsigned int *)(v111 + 4);
  if ( (_DWORD)v18 == 2 )
  {
    os_if_cstats_log_disable_nan_disc_evt(a1, a2);
    v44 = v110 + 2;
    v45 = *v110;
    v46 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v6, a2, 20);
    if ( !v46 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: vdev is null for id %d",
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        "os_if_process_nan_disable_req",
        (unsigned __int8)a2);
      result = qdf_status_to_os_return(0x1Du);
      goto LABEL_6;
    }
    v55 = (unsigned int *)*(unsigned int *)(v46 + 16);
    if ( (_DWORD)v55 == 16 )
    {
      v56 = v46;
      v57 = ucfg_nan_cache_disable_req_info(v6, 1);
      wlan_objmgr_vdev_release_ref(v56, 0x14u, v58, v59, v60, v61, v62, v63, v64, v65, v66);
      v67 = v57;
      if ( v57 )
      {
LABEL_32:
        result = qdf_status_to_os_return(v67);
        goto LABEL_6;
      }
    }
    else
    {
      wlan_objmgr_vdev_release_ref(v46, 0x14u, v55, v47, v48, v49, v50, v51, v52, v53, v54);
    }
    v67 = ucfg_disable_nan_discovery(v6, v44, (unsigned __int16)(v45 - 4));
    goto LABEL_32;
  }
  if ( (_DWORD)v18 != 1 )
  {
    v68 = "%s: Unrecognized NAN subcmd type(%d)";
    v69 = "os_if_process_nan_req";
LABEL_42:
    qdf_trace_msg(0x48u, 2u, v68, v7, v8, v9, v10, v11, v12, v13, v14, v69, v18);
    goto LABEL_5;
  }
  v108 = 0;
  if ( !v112 )
  {
    v15 = "%s: NAN Social channel for 2.4Gz is unavailable!";
    v16 = "os_if_process_nan_enable_req";
    goto LABEL_4;
  }
  v19 = *(_QWORD *)(a1 + 80);
  v20 = *(_DWORD *)(v112 + 4);
  if ( v113 )
    v21 = *(_DWORD *)(v113 + 4);
  else
    v21 = 0;
  if ( (ucfg_is_nan_enable_allowed(*(_QWORD *)(a1 + 80), v20, a2, v7, v8, v9, v10, v11, v12, v13, v14) & 1) == 0 )
  {
    v68 = "%s: NAN Enable not allowed at this moment for channel %d";
    v69 = "os_if_process_nan_enable_req";
    v18 = v20;
    goto LABEL_42;
  }
  v70 = *v110 - 4;
  v71 = _qdf_mem_malloc(v70 + 40LL, "os_if_process_nan_enable_req", 3014);
  if ( !v71 )
    goto LABEL_40;
  v72 = v71;
  *(_DWORD *)(v71 + 8) = v20;
  if ( v21 )
    *(_DWORD *)(v71 + 12) = v21;
  *(_QWORD *)v71 = v19;
  *(_QWORD *)(v71 + 16) = a1;
  *(_WORD *)(v71 + 24) = v70;
  ucfg_mlme_get_fine_time_meas_cap(v19, &v108);
  *(_DWORD *)(v72 + 28) = v108;
  disable_6g_nan = ucfg_get_disable_6g_nan(v19, v73, v74, v75, v76, v77, v78, v79, v80);
  v82 = v110;
  *(_BYTE *)(v72 + 32) = disable_6g_nan & 1;
  nla_memcpy(v72 + 33, v82, v70);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: Sending NAN Enable Req. NAN Ch Freq: %d %d",
    v83,
    v84,
    v85,
    v86,
    v87,
    v88,
    v89,
    v90,
    "os_if_process_nan_enable_req",
    *(unsigned int *)(v72 + 8),
    *(unsigned int *)(v72 + 12));
  v99 = ucfg_nan_discovery_req((__int64 *)v72, 1u, v91, v92, v93, v94, v95, v96, v97, v98);
  if ( v99 )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Unable to send NAN Enable request",
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      "os_if_process_nan_enable_req");
  }
  else
  {
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Successfully sent NAN Enable request",
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      "os_if_process_nan_enable_req");
    os_if_cstats_log_nan_disc_enable_req_evt(a2, v72);
  }
  _qdf_mem_free(v72);
  result = qdf_status_to_os_return(v99);
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
