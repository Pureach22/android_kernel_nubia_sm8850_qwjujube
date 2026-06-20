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
  char v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x4
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 comp_private_obj; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x22
  unsigned int offchan_freq; // w0
  unsigned int v42; // w21
  unsigned int offchan_bw; // w0
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w23
  unsigned int *v53; // x8
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  const char *v62; // x2
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x22
  __int64 v73; // x21
  __int64 v74; // x0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x8
  __int64 v84; // x23
  __int64 v85; // x0
  __int64 v86; // x0
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  __int64 v95; // x6
  int v96; // w4
  __int64 v97; // x24
  __int64 v98; // x0
  int *v99; // x25
  __int64 peer; // x0
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v109; // x27
  unsigned int v110; // w0
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  const char *v119; // x2
  const char *v120; // x22
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  unsigned int updated; // w0
  unsigned int v130; // w1
  char is_dfs_for_freq; // w0
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  unsigned int v140; // w8
  _BYTE v141[4]; // [xsp+14h] [xbp-3Ch] BYREF
  __int64 v142; // [xsp+18h] [xbp-38h] BYREF
  __int64 v143; // [xsp+20h] [xbp-30h] BYREF
  __int64 v144; // [xsp+28h] [xbp-28h]
  __int64 v145; // [xsp+30h] [xbp-20h]
  __int64 v146; // [xsp+38h] [xbp-18h]
  __int64 v147; // [xsp+40h] [xbp-10h]
  __int64 v148; // [xsp+48h] [xbp-8h]

  v148 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)a1;
  v146 = 0;
  v147 = 0;
  v144 = 0;
  v145 = 0;
  v142 = 0;
  v143 = 0;
  v141[0] = 0;
  if ( v10 )
  {
    v11 = tdls_check_is_tdls_allowed(v10);
    v20 = *(unsigned __int8 *)(v10 + 104);
    if ( (v11 & 1) == 0 )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: TDLS not allowed on vdev:%d, Reject setup peer",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "tdls_process_setup_peer",
        v20);
LABEL_14:
      v52 = 4;
      goto LABEL_15;
    }
    qdf_trace_msg(
      0,
      8u,
      "%s: vdev:%d Configure external TDLS peer %02x:%02x:%02x:**:**:%02x",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "tdls_process_setup_peer",
      v20,
      *(unsigned __int8 *)(a1 + 8),
      *(unsigned __int8 *)(a1 + 9),
      *(unsigned __int8 *)(a1 + 10),
      *(unsigned __int8 *)(a1 + 13));
    qdf_mem_set(&v142, 0x30u, 0);
    v142 = v10;
    qdf_mem_copy(&v143, (const void *)(a1 + 8), 6u);
    v29 = *(_QWORD *)(v10 + 152);
    if ( v29 && (v30 = *(_QWORD *)(v29 + 80)) != 0 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v30, 0xAu);
      if ( comp_private_obj )
      {
        v40 = comp_private_obj;
        offchan_freq = tdls_get_offchan_freq(v10, comp_private_obj);
        if ( *(_QWORD *)(v10 + 152) )
        {
          v42 = offchan_freq;
          HIDWORD(v144) = offchan_freq;
          offchan_bw = tdls_get_offchan_bw(v40, offchan_freq);
          if ( !HIDWORD(v145) )
            HIDWORD(v145) = (unsigned __int8)tdls_get_opclass_from_bandwidth(v10, v42, offchan_bw, v141);
          qdf_trace_msg(
            0,
            8u,
            "%s: peer chan %d peer opclass %d reg_bw_offset %d",
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            "tdls_process_setup_peer",
            HIDWORD(v144));
          v72 = v142;
          v73 = *(_QWORD *)(v142 + 152);
          if ( v142 )
          {
            v74 = wlan_objmgr_vdev_get_comp_private_obj(v142, 0xAu);
            v83 = *(_QWORD *)(v72 + 152);
            v84 = v74;
            if ( v83 )
            {
              v85 = *(_QWORD *)(v83 + 80);
              if ( v85 )
              {
                v86 = wlan_objmgr_psoc_get_comp_private_obj(v85, 0xAu);
                v95 = v86;
                if ( v73 && v84 && v86 )
                {
                  v96 = *(_DWORD *)(v86 + 156);
                  if ( (v96 & 0x180) != 0 && (v96 & 0x40) != 0 )
                  {
                    if ( (v96 & 0x100) != 0 )
                    {
                      qdf_trace_msg(
                        0,
                        8u,
                        "%s: liberal mode set",
                        v87,
                        v88,
                        v89,
                        v90,
                        v91,
                        v92,
                        v93,
                        v94,
                        "tdls_config_force_peer");
                    }
                    else
                    {
                      v97 = v86;
                      v98 = _qdf_mem_malloc(0x444u, "tdls_config_force_peer", 2056);
                      if ( !v98 )
                      {
                        v52 = 2;
                        goto LABEL_15;
                      }
                      v99 = (int *)v98;
                      peer = tdls_get_peer(v84, &v143);
                      if ( !peer )
                      {
                        qdf_trace_msg(
                          0,
                          2u,
                          "%s: peer %02x:%02x:%02x:**:**:%02x does not exist",
                          v101,
                          v102,
                          v103,
                          v104,
                          v105,
                          v106,
                          v107,
                          v108,
                          "tdls_config_force_peer",
                          (unsigned __int8)v143,
                          BYTE1(v143),
                          BYTE2(v143),
                          BYTE5(v143));
                        v52 = 29;
LABEL_44:
                        _qdf_mem_free((__int64)v99);
                        goto LABEL_15;
                      }
                      v109 = peer;
                      v110 = tdls_set_force_peer(v84, &v143, 1);
                      if ( v110 )
                      {
                        v52 = v110;
                        v119 = "%s: set force peer failed";
LABEL_43:
                        qdf_trace_msg(
                          0,
                          2u,
                          v119,
                          v111,
                          v112,
                          v113,
                          v114,
                          v115,
                          v116,
                          v117,
                          v118,
                          "tdls_config_force_peer");
                        goto LABEL_44;
                      }
                      *v99 = *(unsigned __int8 *)(v72 + 104);
                      qdf_mem_copy(v99 + 1, &v143, 6u);
                      v99[3] = 3;
                      updated = tdls_wma_update_peer_state(v97, v99, v121, v122, v123, v124, v125, v126, v127, v128);
                      if ( updated )
                      {
                        v52 = updated;
                        v119 = "%s: update peer state failed";
                        goto LABEL_43;
                      }
                      v130 = HIDWORD(v144);
                      ++*(_BYTE *)(v97 + 213);
                      is_dfs_for_freq = wlan_reg_is_dfs_for_freq(
                                          v73,
                                          v130,
                                          v111,
                                          v112,
                                          v113,
                                          v114,
                                          v115,
                                          v116,
                                          v117,
                                          v118);
                      v140 = HIDWORD(v144);
                      if ( (is_dfs_for_freq & 1) != 0 )
                      {
                        qdf_trace_msg(
                          0,
                          2u,
                          "%s: Resetting TDLS off-channel freq from %d to %d",
                          v132,
                          v133,
                          v134,
                          v135,
                          v136,
                          v137,
                          v138,
                          v139,
                          "tdls_config_force_peer",
                          HIDWORD(v144),
                          5180);
                        v140 = 5180;
                        HIDWORD(v144) = 5180;
                      }
                      tdls_set_extctrl_param(v109, v140, (unsigned int)v145, HIDWORD(v145), (unsigned int)v146);
                      tdls_set_callback(v109, v147);
                      tdls_set_ct_mode(*(_QWORD *)v97, v72);
                    }
                    v52 = 0;
                  }
                  else
                  {
                    qdf_trace_msg(
                      0,
                      2u,
                      "%s: TDLS ext ctrl or Imp Trig not enabled, %x",
                      v87,
                      v88,
                      v89,
                      v90,
                      v91,
                      v92,
                      v93,
                      v94,
                      "tdls_config_force_peer");
                    v52 = 11;
                  }
LABEL_15:
                  wlan_objmgr_vdev_release_ref(v10, 0x11u, v53, v54, v55, v56, v57, v58, v59, v60, v61);
                  goto LABEL_16;
                }
                goto LABEL_35;
              }
            }
            v120 = "%s: can't get psoc";
          }
          else
          {
            v120 = "%s: NULL vdev";
            qdf_trace_msg(0, 2u, "%s: NULL vdev", v64, v65, v66, v67, v68, v69, v70, v71, "wlan_vdev_get_tdls_vdev_obj");
            v84 = 0;
          }
          qdf_trace_msg(0, 2u, v120, v75, v76, v77, v78, v79, v80, v81, v82, "wlan_vdev_get_tdls_soc_obj");
          v95 = 0;
LABEL_35:
          qdf_trace_msg(
            0,
            2u,
            "%s: pdev: %pK, vdev_obj: %pK, soc_obj: %pK",
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            v93,
            v94,
            "tdls_config_force_peer",
            v73,
            v84,
            v95);
          goto LABEL_14;
        }
        v62 = "%s: NULL pdev object";
        goto LABEL_13;
      }
    }
    else
    {
      qdf_trace_msg(0, 2u, "%s: can't get psoc", v21, v22, v23, v24, v25, v26, v27, v28, "wlan_vdev_get_tdls_soc_obj");
    }
    v62 = "%s: NULL soc object";
LABEL_13:
    qdf_trace_msg(0, 2u, v62, v32, v33, v34, v35, v36, v37, v38, v39, "tdls_process_setup_peer");
    goto LABEL_14;
  }
  qdf_trace_msg(0, 2u, "%s: NULL vdev object", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_setup_peer");
  v52 = 29;
LABEL_16:
  _qdf_mem_free(a1);
  _ReadStatusReg(SP_EL0);
  return v52;
}
