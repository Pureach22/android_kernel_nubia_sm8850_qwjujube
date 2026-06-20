__int64 __fastcall os_if_nan_process_ndp_responder_req(__int64 a1, _QWORD *a2, __int64 a3)
{
  __int64 v5; // x0
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  __int64 v16; // x19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int ndi_state; // w0
  __int64 v26; // x4
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int *v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w0
  const char *v45; // x2
  __int64 v46; // x8
  __int64 v47; // x22
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int v56; // w20
  __int64 v57; // x8
  int v58; // w9
  __int64 v59; // x8
  __int16 *v60; // x1
  __int16 v61; // t1
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  const char *v70; // x2
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x8
  __int64 v80; // x8
  __int64 v81; // x8
  __int64 v82; // x8
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
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  unsigned int v107; // w0
  __int64 *v108; // [xsp+10h] [xbp-3D0h] BYREF
  __int64 v109; // [xsp+18h] [xbp-3C8h] BYREF
  __int64 v110; // [xsp+20h] [xbp-3C0h]
  _QWORD s[119]; // [xsp+28h] [xbp-3B8h] BYREF

  s[118] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a3 + 32);
  v108 = nullptr;
  result = _osif_vdev_sync_op_start(v5, &v108, (__int64)"os_if_nan_process_ndp_responder_req");
  if ( !(_DWORD)result )
  {
    memset(s, 0, 0x3B0u);
    v15 = a2[12];
    if ( v15 )
    {
      LODWORD(s[2]) = *(_DWORD *)(v15 + 4);
      if ( LODWORD(s[2]) )
      {
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: ndp rsp rejected, using first NDI",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "__os_if_nan_process_ndp_responder_req");
        v16 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_opmode_from_psoc)(a1, 11, 20);
        if ( v16 )
          goto LABEL_5;
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: NAN data iface is not available",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "__os_if_nan_process_ndp_responder_req");
        v56 = -19;
        goto LABEL_41;
      }
      if ( a2 )
      {
        v46 = a2[6];
        if ( v46 )
        {
          v47 = v46 + 4;
          v109 = v46 + 4;
          v110 = 0;
          wlan_objmgr_iterate_obj_list(a1, 2, os_if_get_ndi_vdev_by_ifname_cb, (__int64)&v109, 0, 0x14u);
          if ( v110 )
          {
            if ( !(unsigned int)wlan_objmgr_vdev_try_get_ref(v110, 0x14u, v48, v49, v50, v51, v52, v53, v54, v55) )
            {
              v16 = v110;
              if ( v110 )
              {
                if ( *(_DWORD *)(v110 + 16) != 11 )
                {
                  qdf_trace_msg(
                    0x48u,
                    2u,
                    "%s: Interface found is not NDI",
                    v48,
                    v49,
                    v50,
                    v51,
                    v52,
                    v53,
                    v54,
                    v55,
                    "__os_if_nan_process_ndp_responder_req");
                  v44 = -19;
                  goto LABEL_40;
                }
                if ( (ucfg_nan_is_sta_ndp_concurrency_allowed(a1, v110) & 1) == 0 )
                {
                  qdf_trace_msg(
                    0x48u,
                    2u,
                    "%s: NDP creation not allowed",
                    v71,
                    v72,
                    v73,
                    v74,
                    v75,
                    v76,
                    v77,
                    v78,
                    "__os_if_nan_process_ndp_responder_req");
                  v44 = -95;
                  goto LABEL_40;
                }
LABEL_5:
                ndi_state = ucfg_nan_get_ndi_state();
                if ( ndi_state > 3 || (v26 = ndi_state, ndi_state == 1) )
                {
                  v57 = a2[2];
                  if ( v57 )
                  {
                    v58 = *(unsigned __int16 *)(v57 + 4);
                    v59 = a2[10];
                    LODWORD(s[1]) = v58;
                    if ( v59 )
                    {
                      v60 = (__int16 *)a2[9];
                      HIDWORD(s[1]) = *(_DWORD *)(v59 + 4);
                      if ( v60 )
                      {
                        v61 = *v60;
                        LODWORD(s[35]) = (unsigned __int16)(*v60 - 4);
                        qdf_mem_copy((char *)&s[35] + 4, v60 + 2, (unsigned __int16)(v61 - 4));
                      }
                      else
                      {
                        qdf_trace_msg(
                          0x48u,
                          8u,
                          "%s: NDP app info is unavailable",
                          v27,
                          v28,
                          v29,
                          v30,
                          v31,
                          v32,
                          v33,
                          v34,
                          "__os_if_nan_process_ndp_responder_req",
                          v26);
                      }
                      v79 = a2[8];
                      if ( v79 )
                      {
                        HIDWORD(s[2]) = 4;
                        LODWORD(s[3]) = *(_DWORD *)(v79 + 4);
                      }
                      else
                      {
                        qdf_trace_msg(
                          0x48u,
                          8u,
                          "%s: NDP config data is unavailable",
                          v62,
                          v63,
                          v64,
                          v65,
                          v66,
                          v67,
                          v68,
                          v69,
                          "__os_if_nan_process_ndp_responder_req");
                      }
                      v80 = a2[27];
                      if ( v80 )
                      {
                        BYTE4(s[113]) = 1;
                        qdf_mem_copy((char *)&s[113] + 5, (const void *)(v80 + 4), 0x10u);
                      }
                      v81 = a2[28];
                      if ( v81 )
                      {
                        BYTE5(s[115]) = 1;
                        HIWORD(s[115]) = *(_WORD *)(v81 + 4);
                      }
                      v82 = a2[29];
                      if ( v82 )
                      {
                        LOBYTE(s[116]) = 1;
                        BYTE1(s[116]) = *(_BYTE *)(v82 + 4);
                      }
                      qdf_trace_msg(
                        0x48u,
                        8u,
                        "%s: ipv6 addr present: %d, addr: %pI6",
                        v62,
                        v63,
                        v64,
                        v65,
                        v66,
                        v67,
                        v68,
                        v69,
                        "__os_if_nan_process_ndp_responder_req",
                        BYTE4(s[113]),
                        (char *)&s[113] + 5);
                      qdf_trace_msg(
                        0x48u,
                        8u,
                        "%s: port %d,  present: %d protocol %d,  present: %d",
                        v83,
                        v84,
                        v85,
                        v86,
                        v87,
                        v88,
                        v89,
                        v90,
                        "__os_if_nan_process_ndp_responder_req",
                        HIWORD(s[115]),
                        BYTE5(s[115]),
                        BYTE1(s[116]),
                        LOBYTE(s[116]));
                      if ( !(unsigned int)os_if_nan_parse_security_params(
                                            a2,
                                            &s[72],
                                            (char *)&s[67] + 4,
                                            (char *)&s[72] + 4,
                                            &s[81],
                                            (char *)&s[116] + 4) )
                      {
                        os_if_cstats_log_ndp_responder_req_evt(v16, s);
                        qdf_trace_msg(
                          0x48u,
                          8u,
                          "%s: vdev_id: %d, transaction_id: %d, ndp_rsp %d, ndp_instance_id: %d, ndp_app_info_len: %d, csid: %d",
                          v91,
                          v92,
                          v93,
                          v94,
                          v95,
                          v96,
                          v97,
                          v98,
                          "__os_if_nan_process_ndp_responder_req",
                          *(unsigned __int8 *)(v16 + 168),
                          LODWORD(s[1]),
                          LODWORD(s[2]),
                          HIDWORD(s[1]),
                          LODWORD(s[35]),
                          LODWORD(s[72]));
                        s[0] = v16;
                        v107 = ucfg_nan_req_processor(v16, s, 6u, v99, v100, v101, v102, v103, v104, v105, v106);
                        v44 = qdf_status_to_os_return(v107);
                        if ( !v44 )
                        {
                          v56 = 0;
                          goto LABEL_41;
                        }
                        goto LABEL_40;
                      }
                      v70 = "%s: inconsistent security params in request.";
                    }
                    else
                    {
                      v70 = "%s: Instance ID is unavailable";
                    }
                  }
                  else
                  {
                    v70 = "%s: Transaction ID is unavailable";
                  }
                  qdf_trace_msg(
                    0x48u,
                    2u,
                    v70,
                    v27,
                    v28,
                    v29,
                    v30,
                    v31,
                    v32,
                    v33,
                    v34,
                    "__os_if_nan_process_ndp_responder_req",
                    v26);
                  v44 = -22;
                }
                else
                {
                  qdf_trace_msg(
                    0x48u,
                    2u,
                    "%s: Data request not allowed in current NDI state:%d",
                    v27,
                    v28,
                    v29,
                    v30,
                    v31,
                    v32,
                    v33,
                    v34,
                    "__os_if_nan_process_ndp_responder_req",
                    ndi_state);
                  v44 = -11;
                }
LABEL_40:
                v56 = v44;
                wlan_objmgr_vdev_release_ref(v16, 0x14u, v35, v36, v37, v38, v39, v40, v41, v42, v43);
                goto LABEL_41;
              }
            }
          }
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: NAN data iface %s not available",
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            "__os_if_nan_process_ndp_responder_req",
            v47);
          v56 = -19;
LABEL_41:
          _osif_vdev_sync_op_stop((__int64)v108, (__int64)"os_if_nan_process_ndp_responder_req");
          result = v56;
          goto LABEL_42;
        }
      }
      v45 = "%s: NAN data iface not provided";
    }
    else
    {
      v45 = "%s: ndp_rsp is unavailable";
    }
    qdf_trace_msg(0x48u, 2u, v45, v7, v8, v9, v10, v11, v12, v13, v14, "__os_if_nan_process_ndp_responder_req");
    v56 = -22;
    goto LABEL_41;
  }
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
