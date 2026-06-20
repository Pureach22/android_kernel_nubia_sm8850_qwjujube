__int64 __fastcall os_if_nan_process_ndp_cmd(__int64 a1, __int64 a2, unsigned int a3, char a4, __int64 a5)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  const char *v18; // x2
  __int64 result; // x0
  int v20; // w22
  __int64 v21; // x4
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int *v39; // x8
  __int64 v40; // x20
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 *v58; // x20
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  const char *v67; // x2
  unsigned int v68; // w1
  const char *v69; // x2
  unsigned int v70; // w19
  const char *v71; // x2
  __int64 v72; // x23
  unsigned int v73; // w22
  unsigned int v74; // w21
  unsigned int active_peers; // w24
  unsigned int *v76; // x8
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 v93; // x0
  __int64 v94; // x19
  unsigned int v95; // w0
  unsigned int *v96; // x8
  unsigned int v97; // w20
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  __int64 (__fastcall *v106)(_QWORD, __int64 *, _QWORD); // x8
  __int64 *v107; // [xsp+8h] [xbp-208h] BYREF
  __int64 v108; // [xsp+10h] [xbp-200h] BYREF
  __int64 v109; // [xsp+18h] [xbp-1F8h] BYREF
  __int64 v110; // [xsp+20h] [xbp-1F0h]
  __int64 v111; // [xsp+28h] [xbp-1E8h]
  __int64 v112; // [xsp+30h] [xbp-1E0h]
  __int64 v113; // [xsp+38h] [xbp-1D8h]
  __int64 v114; // [xsp+40h] [xbp-1D0h]
  __int64 v115; // [xsp+48h] [xbp-1C8h]
  __int64 (__fastcall *v116)(_QWORD, __int64 *, _QWORD); // [xsp+50h] [xbp-1C0h]
  __int64 v117; // [xsp+58h] [xbp-1B8h]
  __int64 v118; // [xsp+60h] [xbp-1B0h]
  __int64 v119; // [xsp+68h] [xbp-1A8h]
  __int64 v120; // [xsp+70h] [xbp-1A0h]
  __int64 v121; // [xsp+78h] [xbp-198h]
  __int64 v122; // [xsp+80h] [xbp-190h]
  __int64 v123; // [xsp+88h] [xbp-188h]
  __int64 v124; // [xsp+90h] [xbp-180h]
  __int64 v125; // [xsp+98h] [xbp-178h]
  __int64 v126; // [xsp+A0h] [xbp-170h]
  __int64 v127; // [xsp+A8h] [xbp-168h]
  __int64 v128; // [xsp+B0h] [xbp-160h]
  __int64 v129; // [xsp+B8h] [xbp-158h]
  __int64 v130; // [xsp+C0h] [xbp-150h]
  __int64 v131; // [xsp+C8h] [xbp-148h]
  __int64 v132; // [xsp+D0h] [xbp-140h]
  __int64 *v133; // [xsp+D8h] [xbp-138h] BYREF
  __int64 v134; // [xsp+E0h] [xbp-130h]
  _QWORD s[37]; // [xsp+E8h] [xbp-128h] BYREF

  s[36] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x120u);
  if ( (unsigned int)_nla_parse(s, 35, a2, a3, &vendor_attr_policy, 31, 0) )
  {
    v18 = "%s: Invalid NDP vendor command attributes";
LABEL_3:
    qdf_trace_msg(0x48u, 2u, v18, v10, v11, v12, v13, v14, v15, v16, v17, "os_if_nan_process_ndp_cmd");
LABEL_4:
    result = 4294967274LL;
    goto LABEL_5;
  }
  if ( !s[1] )
  {
    v18 = "%s: NAN datapath cmd type failed";
    goto LABEL_3;
  }
  if ( !s[2] )
  {
    v18 = "%s: attr transaction id failed";
    goto LABEL_3;
  }
  v20 = *(_DWORD *)(s[1] + 4LL);
  v21 = *(unsigned __int16 *)(s[2] + 4LL);
  if ( s[6] )
  {
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Transaction Id: %u NDPCmd: %u iface_name: %s",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "os_if_nan_process_ndp_cmd",
      v21,
      (unsigned int)v20,
      s[6] + 4LL);
    if ( v20 <= 4 )
      goto LABEL_10;
LABEL_18:
    switch ( v20 )
    {
      case 5:
        if ( (a4 & 1) != 0 )
        {
          result = os_if_nan_process_ndp_responder_req(a1, s, a5);
          goto LABEL_5;
        }
        break;
      case 7:
        if ( (a4 & 1) != 0 )
        {
          result = os_if_nan_process_ndp_end_req(a1, s);
          goto LABEL_5;
        }
        break;
      case 13:
        v133 = nullptr;
        v30 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_opmode_from_psoc)(a1, 11, 20);
        if ( !v30 )
          goto LABEL_4;
        v39 = *(unsigned int **)(v30 + 608);
        if ( !v39 || (v39 = *(unsigned int **)v39) == nullptr || (v40 = *((_QWORD *)v39 + 4)) == 0 )
        {
          wlan_objmgr_vdev_release_ref(v30, 0x14u, v39, v31, v32, v33, v34, v35, v36, v37, v38);
          goto LABEL_4;
        }
        wlan_objmgr_vdev_release_ref(v30, 0x14u, v39, v31, v32, v33, v34, v35, v36, v37, v38);
        result = _osif_vdev_sync_op_start(v40, &v133, (__int64)"os_if_nan_process_ndp_update_config");
        if ( (_DWORD)result )
          goto LABEL_5;
        v110 = 0;
        v111 = 0;
        if ( !s[13] )
        {
          v71 = "%s: ndp update config is unavailable";
          goto LABEL_68;
        }
        if ( !s[10] )
        {
          v71 = "%s: Instance ID is unavailable";
          goto LABEL_68;
        }
        LODWORD(v110) = *(_DWORD *)(s[10] + 4LL);
        if ( s[34] )
        {
          v49 = s[35];
          HIDWORD(v110) = *(_DWORD *)(s[34] + 4LL);
          if ( !s[35] )
            goto LABEL_63;
        }
        else
        {
          v49 = s[35];
          if ( !s[35] )
          {
            v71 = "%s: Max latency and throughput are unavailable";
            goto LABEL_68;
          }
        }
        LODWORD(v111) = *(_DWORD *)(v49 + 4);
LABEL_63:
        v93 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_opmode_from_psoc)(a1, 11, 20);
        if ( v93 )
        {
          v109 = v93;
          v94 = v93;
          v95 = ucfg_nan_req_processor(v93, &v109, 0x12u, v41, v42, v43, v44, v45, v46, v47, v48);
          v97 = qdf_status_to_os_return(v95);
          if ( v97 )
            wlan_objmgr_vdev_release_ref(v94, 0x14u, v96, v98, v99, v100, v101, v102, v103, v104, v105);
          goto LABEL_69;
        }
        v71 = "%s: NAN data interface is not available";
LABEL_68:
        qdf_trace_msg(0x48u, 2u, v71, v41, v42, v43, v44, v45, v46, v47, v48, "__os_if_nan_process_ndp_update_config");
        v97 = -22;
LABEL_69:
        _osif_vdev_sync_op_stop((__int64)v133, (__int64)"os_if_nan_process_ndp_update_config");
        result = v97;
        goto LABEL_5;
      default:
        goto LABEL_36;
    }
LABEL_46:
    v69 = "%s: Unsupported concurrency for NAN datapath";
    goto LABEL_47;
  }
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: Transaction Id: %u NDPCmd: %u iface_name: unspecified",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "os_if_nan_process_ndp_cmd",
    v21,
    (unsigned int)v20);
  if ( v20 > 4 )
    goto LABEL_18;
LABEL_10:
  if ( v20 == 1 )
  {
    if ( (ucfg_is_nan_conc_control_supported(a1, v22, v23, v24, v25, v26, v27, v28, v29) & 1) == 0
      || ucfg_is_nan_disc_active(a1, v50, v51, v52, v53, v54, v55, v56, v57) )
    {
      result = os_if_nan_process_ndi_create(a1, s, a5);
      goto LABEL_5;
    }
    v69 = "%s: NDI creation is not allowed when NAN discovery is not running";
LABEL_47:
    qdf_trace_msg(0x48u, 2u, v69, v22, v23, v24, v25, v26, v27, v28, v29, "os_if_nan_process_ndp_cmd");
    result = 4294967201LL;
    goto LABEL_5;
  }
  if ( v20 != 2 )
  {
    if ( v20 == 3 )
    {
      if ( (a4 & 1) != 0 )
      {
        result = os_if_nan_process_ndp_initiator_req(a1, s);
        goto LABEL_5;
      }
      goto LABEL_46;
    }
LABEL_36:
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Unrecognized NDP vendor cmd %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "os_if_nan_process_ndp_cmd",
      (unsigned int)v20);
    goto LABEL_4;
  }
  v107 = nullptr;
  qdf_trace_msg(0x48u, 8u, "%s: enter", v22, v23, v24, v25, v26, v27, v28, v29, "os_if_nan_process_ndi_delete");
  if ( !s[6] )
    goto LABEL_4;
  v58 = (__int64 *)(s[6] + 4LL);
  v108 = 0;
  result = osif_net_dev_from_ifname(a1, s[6] + 4LL, &v108);
  if ( !(_DWORD)result )
  {
    result = _osif_vdev_sync_trans_start_wait(v108, &v107, (__int64)"os_if_nan_process_ndi_delete");
    if ( !(_DWORD)result )
    {
      v131 = 0;
      v132 = 0;
      v129 = 0;
      v130 = 0;
      v127 = 0;
      v128 = 0;
      v125 = 0;
      v126 = 0;
      v123 = 0;
      v124 = 0;
      v121 = 0;
      v122 = 0;
      v119 = 0;
      v120 = 0;
      v117 = 0;
      v118 = 0;
      v115 = 0;
      v116 = nullptr;
      v113 = 0;
      v114 = 0;
      v111 = 0;
      v112 = 0;
      v109 = 0;
      v110 = 0;
      if ( s[2] )
      {
        v133 = v58;
        v134 = 0;
        wlan_objmgr_iterate_obj_list(a1, 2, os_if_get_ndi_vdev_by_ifname_cb, (__int64)&v133, 0, 0x14u);
        if ( !v134
          || (unsigned int)wlan_objmgr_vdev_try_get_ref(v134, 0x14u, v59, v60, v61, v62, v63, v64, v65, v66)
          || (v72 = v134) == 0 )
        {
          v67 = "%s: Nan datapath interface is not present";
          v68 = 8;
LABEL_52:
          qdf_trace_msg(0x48u, v68, v67, v59, v60, v61, v62, v63, v64, v65, v66, "__os_if_nan_process_ndi_delete");
          v70 = -22;
LABEL_53:
          osif_vdev_sync_trans_stop((__int64)v107);
          result = v70;
          goto LABEL_5;
        }
        v73 = *(unsigned __int8 *)(v134 + 104);
        v74 = *(unsigned __int16 *)(s[2] + 4LL);
        active_peers = ucfg_nan_get_active_peers(v134, v59, v60, v61, v62, v63, v64, v65, v66);
        wlan_objmgr_vdev_release_ref(v72, 0x14u, v76, v77, v78, v79, v80, v81, v82, v83, v84);
        if ( active_peers )
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: NDP peers active: %d, active NDPs may not be terminated",
            v85,
            v86,
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            "__os_if_nan_process_ndi_delete",
            active_peers);
        if ( !(unsigned int)ucfg_nan_get_callbacks(a1, &v109, v85, v86, v87, v88, v89, v90, v91, v92) )
        {
          v106 = v116;
          if ( *((_DWORD *)v116 - 1) != 1148628466 )
            __break(0x8228u);
          v70 = v106(v73, v58, v74);
          goto LABEL_53;
        }
        v67 = "%s: Couldn't get ballback object";
      }
      else
      {
        v67 = "%s: Transaction id is unavailable";
      }
      v68 = 2;
      goto LABEL_52;
    }
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
