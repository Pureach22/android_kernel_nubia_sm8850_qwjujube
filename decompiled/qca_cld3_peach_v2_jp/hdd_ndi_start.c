__int64 __fastcall hdd_ndi_start(
        const char *a1,
        __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x22
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 adapter_by_iface_name; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x19
  unsigned int inited; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // w20
  __int64 result; // x0
  __int64 vdev_by_user; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x21
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned int *v68; // x8
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x8
  __int64 v86; // x20
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  __int64 v95; // x23
  int v96; // w24
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  __int64 v113; // x0
  unsigned __int8 v114; // w1
  char v115; // w8
  unsigned int started; // w0
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  const char *v141; // x2
  unsigned int v142; // w1
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  void *v151; // x0
  __int64 v152; // x21
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  __int64 v161; // x22
  __int64 v162; // x24
  unsigned int *v163; // x26
  double v164; // d0
  double v165; // d1
  double v166; // d2
  double v167; // d3
  double v168; // d4
  double v169; // d5
  double v170; // d6
  double v171; // d7
  _QWORD v172[86]; // [xsp+0h] [xbp-2F0h] BYREF
  __int64 v173; // [xsp+2B0h] [xbp-40h] BYREF
  __int64 v174; // [xsp+2B8h] [xbp-38h]
  __int64 v175; // [xsp+2C0h] [xbp-30h]
  __int64 v176; // [xsp+2C8h] [xbp-28h] BYREF
  _QWORD v177[2]; // [xsp+2D0h] [xbp-20h] BYREF
  int v178; // [xsp+2E0h] [xbp-10h]
  __int64 v179; // [xsp+2E8h] [xbp-8h]

  v179 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"hdd_ndi_start", a3, a4, a5, a6, a7, a8, a9, a10);
  qdf_trace_msg(0x33u, 8u, "%s: enter", v13, v14, v15, v16, v17, v18, v19, v20, "hdd_ndi_start");
  if ( !context )
    goto LABEL_8;
  adapter_by_iface_name = hdd_get_adapter_by_iface_name((__int64)context, a1);
  if ( !adapter_by_iface_name )
  {
    qdf_trace_msg(0x33u, 2u, "%s: adapter is null", v22, v23, v24, v25, v26, v27, v28, v29, "hdd_ndi_start");
LABEL_8:
    result = 4294967274LL;
    goto LABEL_9;
  }
  v30 = adapter_by_iface_name;
  inited = hdd_init_nan_data_mode(adapter_by_iface_name);
  if ( inited )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to init nan data intf, status :%d",
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      "hdd_ndi_start",
      inited);
LABEL_5:
    v40 = -14;
LABEL_6:
    hdd_close_ndi(v30);
    result = v40;
    goto LABEL_9;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(v30 + 52824), 0x52u, (__int64)"hdd_ndi_start");
  if ( !vdev_by_user )
  {
    qdf_trace_msg(0x33u, 2u, "%s: vdev is NULL", v43, v44, v45, v46, v47, v48, v49, v50, "hdd_ndi_start");
    v40 = -22;
    goto LABEL_6;
  }
  v51 = vdev_by_user;
  hdd_cstats_log_ndi_create_req_evt(vdev_by_user, a2);
  ucfg_nan_set_ndp_create_transaction_id(v51, a2, v52, v53, v54, v55, v56, v57, v58, v59);
  _ucfg_nan_set_ndi_state(v51, 0, (__int64)"hdd_ndi_start", v60, v61, v62, v63, v64, v65, v66, v67);
  _hdd_objmgr_put_vdev_by_user(v51, 0x52u, (__int64)"hdd_ndi_start", v68, v69, v70, v71, v72, v73, v74, v75, v76);
  v178 = 0;
  v177[0] = 0;
  v177[1] = 0;
  v175 = 0;
  v176 = 0;
  v173 = 0;
  v174 = 0;
  memset(v172, 0, sizeof(v172));
  v85 = *(_QWORD *)(v30 + 24);
  if ( !v85 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter", v77, v78, v79, v80, v81, v82, v83, v84, "hdd_ndi_start_bss");
    goto LABEL_27;
  }
  v86 = *(_QWORD *)(v85 + 16);
  qdf_trace_msg(0x33u, 8u, "%s: enter", v77, v78, v79, v80, v81, v82, v83, v84, "hdd_ndi_start_bss");
  if ( !v86 )
  {
LABEL_27:
    v141 = "%s: mac ctx NULL";
    v142 = 8;
    goto LABEL_28;
  }
  v95 = *(_QWORD *)(v30 + 24);
  v96 = 5745;
  if ( (wlan_reg_is_freq_enabled(*(_QWORD *)(v95 + 8), 0x1671u, v87, v88, v89, v90, v91, v92, v93, v94) & 1) == 0 )
  {
    v96 = 5220;
    if ( (wlan_reg_is_freq_enabled(*(_QWORD *)(v95 + 8), 0x1464u, v97, v98, v99, v100, v101, v102, v103, v104) & 1) == 0 )
    {
      v96 = 2437;
      if ( (wlan_reg_is_freq_enabled(*(_QWORD *)(v95 + 8), 0x985u, v105, v106, v107, v108, v109, v110, v111, v112) & 1) == 0 )
      {
        v151 = (void *)_qdf_mem_malloc(0xEA0u, "hdd_ndi_select_valid_freq", 293);
        if ( v151 )
        {
          v152 = (__int64)v151;
          if ( !(unsigned int)ucfg_reg_get_current_chan_list(*(_QWORD *)(v95 + 8), v151) )
          {
            v162 = 0;
            while ( 1 )
            {
              v163 = (unsigned int *)(v152 + v162);
              if ( (*(_BYTE *)(v152 + v162 + 12) & 9) == 0
                && !wlan_reg_is_6ghz_chan_freq(*v163)
                && (wlan_reg_is_freq_enabled(
                      *(_QWORD *)(v95 + 8),
                      *v163,
                      v164,
                      v165,
                      v166,
                      v167,
                      v168,
                      v169,
                      v170,
                      v171)
                  & 1) != 0 )
              {
                break;
              }
              v162 += 36;
              if ( v162 == 3672 )
                goto LABEL_33;
            }
            v96 = *(_DWORD *)(v152 + v162);
            _qdf_mem_free(v152);
            goto LABEL_16;
          }
          v161 = jiffies;
          if ( hdd_ndi_select_valid_freq___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Failed to get the current channel list",
              v153,
              v154,
              v155,
              v156,
              v157,
              v158,
              v159,
              v160,
              "hdd_ndi_select_valid_freq");
            hdd_ndi_select_valid_freq___last_ticks = v161;
          }
LABEL_33:
          _qdf_mem_free(v152);
        }
        v141 = "%s: Unable to retrieve channel list for NAN";
        v142 = 2;
LABEL_28:
        qdf_trace_msg(0x33u, v142, v141, v87, v88, v89, v90, v91, v92, v93, v94, "hdd_ndi_start_bss");
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: NDI start bss failed",
          v143,
          v144,
          v145,
          v146,
          v147,
          v148,
          v149,
          v150,
          "hdd_ndi_start");
        goto LABEL_5;
      }
    }
  }
LABEL_16:
  v113 = *(_QWORD *)(v86 + 21560);
  v114 = *(_BYTE *)(*(_QWORD *)(v30 + 52824) + 8LL);
  HIDWORD(v173) = 1024;
  LODWORD(v174) = v96;
  LOBYTE(v173) = v114;
  if ( !wlan_vdev_id_is_open_cipher(v113, v114) )
    BYTE1(v173) = 1;
  sme_get_network_params(v86, (__int64)&v173);
  v115 = *(_BYTE *)(*(_QWORD *)(v30 + 52824) + 8LL);
  LODWORD(v172[46]) = v174;
  HIDWORD(v172[47]) = v175;
  LOBYTE(v172[0]) = v115;
  BYTE1(v172[47]) = BYTE4(v174);
  if ( (_BYTE)v176 )
  {
    qdf_mem_copy((char *)&v172[48] + 1, (char *)&v176 + 1, (unsigned __int8)v176);
    LOBYTE(v172[48]) = v176;
  }
  if ( BYTE5(v177[0]) )
  {
    qdf_mem_copy((char *)&v172[49] + 6, (char *)v177 + 6, BYTE5(v177[0]));
    BYTE5(v172[49]) = BYTE5(v177[0]);
  }
  started = sme_start_bss(v86, *(_BYTE *)(*(_QWORD *)(v30 + 52824) + 8LL), (__int64)v172);
  if ( started )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: NDI sme_RoamConnect session %d failed with status %d -> NotConnected",
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      "hdd_ndi_start_bss",
      *(unsigned __int8 *)(*(_QWORD *)(v30 + 52824) + 8LL),
      started,
      v172[0]);
    hdd_conn_set_connection_state(v30, 0, v125, v126, v127, v128, v129, v130, v131, v132);
  }
  qdf_trace_msg(0x33u, 8u, "%s: exit", v117, v118, v119, v120, v121, v122, v123, v124, "hdd_ndi_start_bss", v172[0]);
  hdd_create_adapter_sysfs_files(v30);
  qdf_trace_msg(0x33u, 8u, "%s: exit", v133, v134, v135, v136, v137, v138, v139, v140, "hdd_ndi_start");
  result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
