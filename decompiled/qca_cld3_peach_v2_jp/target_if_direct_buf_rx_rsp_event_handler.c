__int64 __fastcall target_if_direct_buf_rx_rsp_event_handler(
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
  __int64 psoc_from_scn_hdl; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x21
  __int64 v23; // x23
  const char *v24; // x2
  __int64 result; // x0
  unsigned int v26; // w22
  __int64 pdev_by_id; // x0
  __int64 v28; // x19
  __int64 comp_private_obj; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x9
  _QWORD *v39; // x22
  int v40; // w8
  const char *v41; // x2
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  const char *v50; // x2
  unsigned int *v51; // x8
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int *v60; // x8
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x4
  __int64 v78; // x5
  __int64 v79; // x6
  const char *v80; // x2
  unsigned int v81; // w20
  unsigned int *v82; // x8
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  unsigned int v91; // w27
  unsigned int v92; // w23
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 (__fastcall *v109)(__int64, __int64 *); // x8
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  const char *v118; // x2
  __int64 v119; // [xsp+0h] [xbp-A0h] BYREF
  __int64 v120; // [xsp+8h] [xbp-98h]
  __int64 v121; // [xsp+10h] [xbp-90h]
  __int64 v122; // [xsp+18h] [xbp-88h]
  __int64 v123; // [xsp+20h] [xbp-80h]
  unsigned int v124; // [xsp+2Ch] [xbp-74h] BYREF
  __int64 v125; // [xsp+30h] [xbp-70h] BYREF
  __int64 v126; // [xsp+38h] [xbp-68h]
  __int64 v127; // [xsp+40h] [xbp-60h]
  __int64 v128; // [xsp+48h] [xbp-58h]
  _QWORD v129[10]; // [xsp+50h] [xbp-50h] BYREF

  v129[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v124 = 0;
  v122 = 0;
  v123 = 0;
  v120 = 0;
  v121 = 0;
  v119 = 0;
  v128 = 0;
  memset(v129, 0, 72);
  v126 = 0;
  v127 = 0;
  v125 = 0;
  qdf_trace_msg(0x5Bu, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_direct_buf_rx_rsp_event_handler");
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v24 = "%s: psoc is null";
    goto LABEL_8;
  }
  v21 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v21 || (v22 = *(_QWORD *)(v21 + 16)) == 0 )
  {
    v24 = "%s: WMI handle is null";
    goto LABEL_8;
  }
  v23 = psoc_from_scn_hdl;
  if ( !(unsigned int)wmi_extract_dbr_buf_release_fixed(*(_QWORD *)(v21 + 16), a2, &v119) )
  {
    qdf_trace_msg(
      0x5Bu,
      8u,
      "%s: Num buf release entry = %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "target_if_direct_buf_rx_rsp_event_handler",
      (unsigned int)v120);
    v26 = (unsigned __int8)v119;
    pdev_by_id = wlan_objmgr_get_pdev_by_id(v23, v119, 0x1Eu);
    if ( pdev_by_id )
    {
      v28 = pdev_by_id;
      v26 = 0;
      goto LABEL_13;
    }
    v28 = wlan_objmgr_get_pdev_by_id(v23, 0, 0x1Eu);
    if ( v28 )
    {
      qdf_trace_msg(
        0x5Bu,
        8u,
        "%s: update srng id from %d to %d",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "dbr_get_pdev_and_srng_id",
        0,
        v26);
      if ( v26 < 2 )
      {
LABEL_13:
        comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(v28, 8u);
        if ( comp_private_obj )
        {
          if ( HIDWORD(v119) >= *(_DWORD *)comp_private_obj )
          {
            qdf_trace_msg(
              0x5Bu,
              2u,
              "%s: Invalid module id:%d",
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              "target_if_direct_buf_rx_rsp_event_handler");
LABEL_31:
            wlan_objmgr_pdev_release_ref(v28, 0x1Eu, v51, v52, v53, v54, v55, v56, v57, v58, v59);
            goto LABEL_9;
          }
          v38 = *(_QWORD *)(comp_private_obj + 8);
          v39 = (_QWORD *)(v38 + 112LL * HIDWORD(v119) + 56LL * v26);
          if ( v39 )
          {
            if ( (*(_BYTE *)(v38 + 112LL * BYTE4(v119) + 49) & 1) == 0 )
            {
              qdf_trace_msg(
                0x5Bu,
                2u,
                "%s: no target support for mod_id %d",
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                "target_if_direct_buf_rx_rsp_event_handler");
              wlan_objmgr_pdev_release_ref(v28, 0x1Eu, v60, v61, v62, v63, v64, v65, v66, v67, v68);
              result = 11;
              goto LABEL_10;
            }
            v123 = _qdf_mem_malloc(12LL * (unsigned int)v120, "target_if_direct_buf_rx_rsp_event_handler", 2208);
            if ( v123 )
            {
              v40 = v120;
              if ( HIDWORD(v120) <= (unsigned int)v120 )
              {
                if ( (unsigned int)v121 <= (unsigned int)v120 )
                {
                  if ( HIDWORD(v121) <= (unsigned int)v120 )
                  {
                    if ( (unsigned int)v122 <= (unsigned int)v120 )
                    {
                      if ( !(_DWORD)v120 )
                        goto LABEL_37;
                      v91 = 0;
                      v92 = 0;
                      while ( 1 )
                      {
                        if ( (unsigned int)wmi_extract_dbr_buf_release_entry(
                                             v22,
                                             a2,
                                             v92,
                                             v123 + 12LL * (unsigned __int8)v92) )
                        {
                          qdf_trace_msg(
                            0x5Bu,
                            2u,
                            "%s: Unable to extract DBR buf entry %d",
                            v93,
                            v94,
                            v95,
                            v96,
                            v97,
                            v98,
                            v99,
                            v100,
                            "target_if_direct_buf_rx_rsp_event_handler",
                            v91 + 1);
                          goto LABEL_36;
                        }
                        if ( (unsigned int)target_if_get_dbr_data(v28, v39, &v119, &v125, v92, &v124) )
                          break;
                        LOBYTE(v129[0]) = 0;
                        if ( HIDWORD(v120) > v91 )
                          LOBYTE(v129[0]) = (unsigned int)wmi_extract_dbr_buf_metadata(v22, a2, v92, (char *)v129 + 4) == 0;
                        BYTE1(v129[0]) = 0;
                        if ( (unsigned int)v121 > v91 )
                          BYTE1(v129[0]) = (unsigned int)wmi_extract_dbr_buf_cv_metadata(v22, a2, v92, (char *)v129 + 4) == 0;
                        BYTE2(v129[0]) = 0;
                        if ( HIDWORD(v121) > v91 )
                          BYTE2(v129[0]) = (unsigned int)wmi_extract_dbr_buf_cqi_metadata(
                                                           v22,
                                                           a2,
                                                           v92,
                                                           (char *)v129 + 4) == 0;
                        BYTE3(v129[0]) = 0;
                        if ( (unsigned int)v122 > v91 )
                          BYTE3(v129[0]) = (unsigned int)wmi_extract_dbr_buf_wifi_radar_metadata(
                                                           v22,
                                                           a2,
                                                           v92,
                                                           (char *)v129 + 4) == 0;
                        v109 = (__int64 (__fastcall *)(__int64, __int64 *))v39[5];
                        if ( *((_DWORD *)v109 - 1) != 2109988550 )
                          __break(0x8228u);
                        if ( (v109(v28, &v125) & 1) != 0
                          && (unsigned int)target_if_dbr_replenish_ring(
                                             v28,
                                             v39,
                                             v126,
                                             v124,
                                             v110,
                                             v111,
                                             v112,
                                             v113,
                                             v114,
                                             v115,
                                             v116,
                                             v117) )
                        {
                          v118 = "%s: Ring replenish failed";
                          goto LABEL_62;
                        }
                        v91 = (unsigned __int8)++v92;
                        v40 = 0;
                        if ( (unsigned int)v120 <= (unsigned __int8)v92 )
                          goto LABEL_37;
                      }
                      v118 = "%s: DBR data get failed";
LABEL_62:
                      qdf_trace_msg(
                        0x5Bu,
                        2u,
                        v118,
                        v101,
                        v102,
                        v103,
                        v104,
                        v105,
                        v106,
                        v107,
                        v108,
                        "target_if_direct_buf_rx_rsp_event_handler");
LABEL_36:
                      v40 = 16;
LABEL_37:
                      v81 = v40;
                      _qdf_mem_free(v123);
                      wlan_objmgr_pdev_release_ref(v28, 0x1Eu, v82, v83, v84, v85, v86, v87, v88, v89, v90);
                      result = v81;
                      goto LABEL_10;
                    }
                    qdf_trace_msg(
                      0x5Bu,
                      2u,
                      "%s: More than expected number of wifi radar metadata",
                      v30,
                      v31,
                      v32,
                      v33,
                      v34,
                      v35,
                      v36,
                      v37,
                      "target_if_direct_buf_rx_rsp_event_handler");
                    v79 = (unsigned int)v120;
                    v77 = HIDWORD(v120);
                    v78 = (unsigned int)v122;
                    v80 = "%s: meta_data_entry:%d wifi_radar_meta_data_entry:%d buf_release_entry:%d";
                  }
                  else
                  {
                    qdf_trace_msg(
                      0x5Bu,
                      2u,
                      "%s: More than expected number of cqi metadata",
                      v30,
                      v31,
                      v32,
                      v33,
                      v34,
                      v35,
                      v36,
                      v37,
                      "target_if_direct_buf_rx_rsp_event_handler");
                    v79 = (unsigned int)v120;
                    v77 = HIDWORD(v120);
                    v78 = HIDWORD(v121);
                    v80 = "%s: meta_data_entry:%d cqi_meta_data_entry:%d buf_release_entry:%d";
                  }
LABEL_35:
                  qdf_trace_msg(
                    0x5Bu,
                    2u,
                    v80,
                    v69,
                    v70,
                    v71,
                    v72,
                    v73,
                    v74,
                    v75,
                    v76,
                    "target_if_direct_buf_rx_rsp_event_handler",
                    v77,
                    v78,
                    v79);
                  goto LABEL_36;
                }
                v41 = "%s: More than expected number of cv metadata";
              }
              else
              {
                v41 = "%s: More than expected number of metadata";
              }
              qdf_trace_msg(
                0x5Bu,
                2u,
                v41,
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                "target_if_direct_buf_rx_rsp_event_handler");
              v77 = HIDWORD(v120);
              v78 = (unsigned int)v121;
              v79 = (unsigned int)v120;
              v80 = "%s: meta_data_entry:%d cv_meta_data_entry:%d buf_release_entry:%d";
              goto LABEL_35;
            }
            v50 = "%s: invalid dbr_entries";
          }
          else
          {
            v50 = "%s: dir buf rx module param is null";
          }
        }
        else
        {
          v50 = "%s: dir buf rx object is null";
        }
        qdf_trace_msg(
          0x5Bu,
          2u,
          v50,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "target_if_direct_buf_rx_rsp_event_handler");
        goto LABEL_31;
      }
    }
    else
    {
      v26 = 0;
    }
    qdf_trace_msg(
      0x5Bu,
      2u,
      "%s: invalid pdev or srng, pdev %pK, srng %d",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "target_if_direct_buf_rx_rsp_event_handler",
      v28,
      v26);
    result = 4;
    goto LABEL_10;
  }
  v24 = "%s: unable to extract DBR rsp fixed param";
LABEL_8:
  qdf_trace_msg(0x5Bu, 2u, v24, v13, v14, v15, v16, v17, v18, v19, v20, "target_if_direct_buf_rx_rsp_event_handler");
LABEL_9:
  result = 16;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
