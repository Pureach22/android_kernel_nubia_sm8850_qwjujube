__int64 __fastcall tdls_process_setup_peer(
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
  __int64 v10; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  char is_link_switch_in_progress; // w0
  __int64 v20; // x4
  const char *v21; // x2
  unsigned int v22; // w23
  unsigned int *v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 comp_private_obj; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x22
  unsigned int offchan_freq; // w0
  unsigned int v53; // w21
  unsigned int offchan_bw; // w0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  const char *v63; // x2
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x22
  __int64 v74; // x21
  __int64 v75; // x0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  __int64 v84; // x8
  __int64 v85; // x23
  __int64 v86; // x0
  __int64 v87; // x0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  __int64 v96; // x6
  int v97; // w4
  __int64 v98; // x24
  __int64 v99; // x0
  int *v100; // x25
  __int64 peer; // x0
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  __int64 v110; // x27
  unsigned int v111; // w0
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  const char *v120; // x2
  const char *v121; // x22
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  unsigned int updated; // w0
  unsigned int v131; // w1
  char is_dfs_for_freq; // w0
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  unsigned int v141; // w8
  _BYTE v142[4]; // [xsp+14h] [xbp-3Ch] BYREF
  __int64 v143; // [xsp+18h] [xbp-38h] BYREF
  __int64 v144; // [xsp+20h] [xbp-30h] BYREF
  __int64 v145; // [xsp+28h] [xbp-28h]
  __int64 v146; // [xsp+30h] [xbp-20h]
  __int64 v147; // [xsp+38h] [xbp-18h]
  __int64 v148; // [xsp+40h] [xbp-10h]
  __int64 v149; // [xsp+48h] [xbp-8h]

  v149 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)a1;
  v147 = 0;
  v148 = 0;
  v145 = 0;
  v146 = 0;
  v143 = 0;
  v144 = 0;
  v142[0] = 0;
  if ( v10 )
  {
    if ( (tdls_check_is_tdls_allowed(v10) & 1) == 0 )
    {
      v20 = *(unsigned __int8 *)(v10 + 168);
      v21 = "%s: TDLS not allowed on vdev:%d, Reject setup peer";
      goto LABEL_7;
    }
    is_link_switch_in_progress = mlo_mgr_is_link_switch_in_progress(v10);
    v20 = *(unsigned __int8 *)(v10 + 168);
    if ( (is_link_switch_in_progress & 1) != 0 )
    {
      v21 = "%s: TDLS not allowed on vdev:%d, Link switch in progress";
LABEL_7:
      qdf_trace_msg(0, 2u, v21, v11, v12, v13, v14, v15, v16, v17, v18, "tdls_process_setup_peer", v20);
LABEL_17:
      v22 = 4;
LABEL_18:
      wlan_objmgr_vdev_release_ref(v10, 0x11u, v23, v24, v25, v26, v27, v28, v29, v30, v31);
      goto LABEL_19;
    }
    qdf_trace_msg(
      0,
      8u,
      "%s: vdev:%d Configure external TDLS peer %02x:%02x:%02x:**:**:%02x",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "tdls_process_setup_peer",
      v20,
      *(unsigned __int8 *)(a1 + 8),
      *(unsigned __int8 *)(a1 + 9),
      *(unsigned __int8 *)(a1 + 10),
      *(unsigned __int8 *)(a1 + 13));
    qdf_mem_set(&v143, 0x30u, 0);
    v143 = v10;
    qdf_mem_copy(&v144, (const void *)(a1 + 8), 6u);
    v40 = *(_QWORD *)(v10 + 216);
    if ( v40 && (v41 = *(_QWORD *)(v40 + 80)) != 0 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v41, 0xAu);
      if ( comp_private_obj )
      {
        v51 = comp_private_obj;
        offchan_freq = tdls_get_offchan_freq(v10, comp_private_obj);
        if ( *(_QWORD *)(v10 + 216) )
        {
          v53 = offchan_freq;
          HIDWORD(v145) = offchan_freq;
          offchan_bw = tdls_get_offchan_bw(v51, offchan_freq);
          if ( !HIDWORD(v146) )
            HIDWORD(v146) = (unsigned __int8)tdls_get_opclass_from_bandwidth(v10, v53, offchan_bw, v142);
          qdf_trace_msg(
            0,
            8u,
            "%s: peer chan %d peer opclass %d reg_bw_offset %d",
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            "tdls_process_setup_peer",
            HIDWORD(v145));
          v73 = v143;
          v74 = *(_QWORD *)(v143 + 216);
          if ( v143 )
          {
            v75 = wlan_objmgr_vdev_get_comp_private_obj(v143, 0xAu);
            v84 = *(_QWORD *)(v73 + 216);
            v85 = v75;
            if ( v84 )
            {
              v86 = *(_QWORD *)(v84 + 80);
              if ( v86 )
              {
                v87 = wlan_objmgr_psoc_get_comp_private_obj(v86, 0xAu);
                v96 = v87;
                if ( v74 && v85 && v87 )
                {
                  v97 = *(_DWORD *)(v87 + 156);
                  if ( (v97 & 0x180) == 0 || (v97 & 0x40) == 0 )
                  {
                    qdf_trace_msg(
                      0,
                      2u,
                      "%s: TDLS ext ctrl or Imp Trig not enabled, %x",
                      v88,
                      v89,
                      v90,
                      v91,
                      v92,
                      v93,
                      v94,
                      v95,
                      "tdls_config_force_peer");
                    v22 = 11;
                    goto LABEL_18;
                  }
                  if ( (v97 & 0x100) != 0 )
                  {
                    qdf_trace_msg(
                      0,
                      8u,
                      "%s: liberal mode set",
                      v88,
                      v89,
                      v90,
                      v91,
                      v92,
                      v93,
                      v94,
                      v95,
                      "tdls_config_force_peer");
                  }
                  else
                  {
                    v98 = v87;
                    v99 = _qdf_mem_malloc(0x444u, "tdls_config_force_peer", 2056);
                    if ( !v99 )
                    {
                      v22 = 2;
                      goto LABEL_18;
                    }
                    v100 = (int *)v99;
                    peer = tdls_get_peer(v85, &v144);
                    if ( !peer )
                    {
                      qdf_trace_msg(
                        0,
                        2u,
                        "%s: peer %02x:%02x:%02x:**:**:%02x does not exist",
                        v102,
                        v103,
                        v104,
                        v105,
                        v106,
                        v107,
                        v108,
                        v109,
                        "tdls_config_force_peer",
                        (unsigned __int8)v144,
                        BYTE1(v144),
                        BYTE2(v144),
                        BYTE5(v144));
                      v22 = 29;
LABEL_47:
                      _qdf_mem_free((__int64)v100);
                      goto LABEL_18;
                    }
                    v110 = peer;
                    v111 = tdls_set_force_peer(v85, &v144, 1);
                    if ( v111 )
                    {
                      v22 = v111;
                      v120 = "%s: set force peer failed";
LABEL_46:
                      qdf_trace_msg(
                        0,
                        2u,
                        v120,
                        v112,
                        v113,
                        v114,
                        v115,
                        v116,
                        v117,
                        v118,
                        v119,
                        "tdls_config_force_peer");
                      goto LABEL_47;
                    }
                    *v100 = *(unsigned __int8 *)(v73 + 168);
                    qdf_mem_copy(v100 + 1, &v144, 6u);
                    v100[3] = 3;
                    updated = tdls_wma_update_peer_state(v98, v100, v122, v123, v124, v125, v126, v127, v128, v129);
                    if ( updated )
                    {
                      v22 = updated;
                      v120 = "%s: update peer state failed";
                      goto LABEL_46;
                    }
                    v131 = HIDWORD(v145);
                    ++*(_BYTE *)(v98 + 213);
                    is_dfs_for_freq = wlan_reg_is_dfs_for_freq(
                                        v74,
                                        v131,
                                        v112,
                                        v113,
                                        v114,
                                        v115,
                                        v116,
                                        v117,
                                        v118,
                                        v119);
                    v141 = HIDWORD(v145);
                    if ( (is_dfs_for_freq & 1) != 0 )
                    {
                      qdf_trace_msg(
                        0,
                        2u,
                        "%s: Resetting TDLS off-channel freq from %d to %d",
                        v133,
                        v134,
                        v135,
                        v136,
                        v137,
                        v138,
                        v139,
                        v140,
                        "tdls_config_force_peer",
                        HIDWORD(v145),
                        5180);
                      v141 = 5180;
                      HIDWORD(v145) = 5180;
                    }
                    tdls_set_extctrl_param(v110, v141, (unsigned int)v146, HIDWORD(v146), (unsigned int)v147);
                    tdls_set_callback(v110, v148);
                    tdls_set_ct_mode(*(_QWORD *)v98, v73);
                  }
                  v22 = 0;
                  goto LABEL_18;
                }
LABEL_38:
                qdf_trace_msg(
                  0,
                  2u,
                  "%s: pdev: %pK, vdev_obj: %pK, soc_obj: %pK",
                  v88,
                  v89,
                  v90,
                  v91,
                  v92,
                  v93,
                  v94,
                  v95,
                  "tdls_config_force_peer",
                  v74,
                  v85,
                  v96);
                goto LABEL_17;
              }
            }
            v121 = "%s: can't get psoc";
          }
          else
          {
            v121 = "%s: NULL vdev";
            qdf_trace_msg(0, 2u, "%s: NULL vdev", v65, v66, v67, v68, v69, v70, v71, v72, "wlan_vdev_get_tdls_vdev_obj");
            v85 = 0;
          }
          qdf_trace_msg(0, 2u, v121, v76, v77, v78, v79, v80, v81, v82, v83, "wlan_vdev_get_tdls_soc_obj");
          v96 = 0;
          goto LABEL_38;
        }
        v63 = "%s: NULL pdev object";
LABEL_16:
        qdf_trace_msg(0, 2u, v63, v43, v44, v45, v46, v47, v48, v49, v50, "tdls_process_setup_peer");
        goto LABEL_17;
      }
    }
    else
    {
      qdf_trace_msg(0, 2u, "%s: can't get psoc", v32, v33, v34, v35, v36, v37, v38, v39, "wlan_vdev_get_tdls_soc_obj");
    }
    v63 = "%s: NULL soc object";
    goto LABEL_16;
  }
  qdf_trace_msg(0, 2u, "%s: NULL vdev object", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_setup_peer");
  v22 = 29;
LABEL_19:
  _qdf_mem_free(a1);
  _ReadStatusReg(SP_EL0);
  return v22;
}
