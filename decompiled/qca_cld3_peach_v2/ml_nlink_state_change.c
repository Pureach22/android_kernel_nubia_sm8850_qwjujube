__int64 __fastcall ml_nlink_state_change(__int64 a1, int a2, unsigned int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 result; // x0
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x23
  unsigned int *v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x24
  const char *v43; // x2
  const char *v44; // x3
  __int64 v45; // x0
  __int64 v46; // x23
  unsigned int *v47; // x8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x24
  __int64 v57; // x4
  __int64 v58; // x25
  unsigned int legacy_conn_info; // w24
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 is_disc_active; // x0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  unsigned int updated; // w19
  unsigned int *v86; // x8
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  int _24ghz_social_ch_freq; // w0
  __int64 v96; // x8
  unsigned int v97; // w24
  int v98; // w25
  int v99; // w26
  int v100; // w27
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v109; // x24
  __int64 v110; // x8
  char v111; // w10
  char v112; // w11
  __int16 v113; // w9
  unsigned int *v114; // x8
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  const char *v123; // x3
  const char *v124; // x3
  unsigned int v125; // w26
  unsigned int v126; // w27
  int v127; // w24
  char v128; // w25
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  int v137; // w26
  int v138; // w25
  bool v139; // w0
  int v140; // w8
  int v141; // w25
  bool v142; // w0
  int v143; // w8
  bool v144; // w0
  int v145; // w8
  unsigned int v146; // w4
  char v147; // w24
  unsigned int v148; // w5
  bool v149; // cc
  __int64 v150; // x26
  __int64 v151; // x27
  int v152; // w28
  __int64 v153; // x1
  _BOOL4 is_24ghz_ch_freq; // w25
  unsigned int v155; // w24
  unsigned int v156; // w4
  char v157; // w25
  unsigned int v158; // w5
  const char *v159; // x2
  const char *v160; // x3
  unsigned int v161; // w4
  unsigned int v162; // w5
  unsigned int v163; // w4
  unsigned int v164; // w5
  unsigned int v165; // w4
  unsigned int v166; // w5
  __int64 v167; // [xsp+0h] [xbp-120h]
  __int64 v168; // [xsp+8h] [xbp-118h]
  int v169; // [xsp+1Ch] [xbp-104h]
  _QWORD v170[2]; // [xsp+20h] [xbp-100h] BYREF
  __int16 v171; // [xsp+30h] [xbp-F0h]
  __int64 v172; // [xsp+38h] [xbp-E8h] BYREF
  __int64 v173; // [xsp+40h] [xbp-E0h]
  __int16 v174; // [xsp+48h] [xbp-D8h]
  __int64 v175; // [xsp+50h] [xbp-D0h] BYREF
  __int64 v176; // [xsp+58h] [xbp-C8h]
  __int16 v177; // [xsp+60h] [xbp-C0h]
  unsigned int v178; // [xsp+68h] [xbp-B8h] BYREF
  unsigned __int8 v179[4]; // [xsp+6Ch] [xbp-B4h] BYREF
  int v180; // [xsp+70h] [xbp-B0h] BYREF
  unsigned __int8 v181; // [xsp+74h] [xbp-ACh]
  unsigned int v182; // [xsp+78h] [xbp-A8h] BYREF
  char v183; // [xsp+7Ch] [xbp-A4h]
  int v184; // [xsp+80h] [xbp-A0h] BYREF
  char v185; // [xsp+84h] [xbp-9Ch]
  __int64 v186; // [xsp+88h] [xbp-98h] BYREF
  __int64 v187; // [xsp+90h] [xbp-90h]
  int v188; // [xsp+98h] [xbp-88h]
  _QWORD v189[2]; // [xsp+A0h] [xbp-80h] BYREF
  int v190; // [xsp+B0h] [xbp-70h]
  __int64 v191; // [xsp+B8h] [xbp-68h] BYREF
  __int64 v192; // [xsp+C0h] [xbp-60h]
  int v193; // [xsp+C8h] [xbp-58h]
  __int64 v194; // [xsp+D0h] [xbp-50h] BYREF
  __int64 v195; // [xsp+D8h] [xbp-48h]
  __int64 v196; // [xsp+E0h] [xbp-40h]
  __int64 v197; // [xsp+E8h] [xbp-38h]
  __int64 v198; // [xsp+F0h] [xbp-30h]
  __int64 v199; // [xsp+F8h] [xbp-28h] BYREF
  __int64 v200; // [xsp+100h] [xbp-20h]
  unsigned int v201; // [xsp+108h] [xbp-18h]
  __int64 v202; // [xsp+110h] [xbp-10h]

  v202 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (policy_mgr_is_mlo_in_mode_emlsr(a1, 0, nullptr) & 1) != 0 )
  {
    if ( (wlan_mlme_is_aux_emlsr_support(a1) & 1) == 0 )
    {
      LOWORD(v201) = 0;
      v199 = 0;
      v200 = 0;
      LOWORD(v193) = 0;
      v191 = 0;
      v192 = 0;
      if ( (a3 & 0xFFFFFFFE) != 0x12 )
      {
        v43 = "%s: Don't disable eMLSR links";
LABEL_15:
        v44 = "ml_nlink_state_change_emlsr_no_conc";
        goto LABEL_82;
      }
      if ( (policy_mgr_is_emlsr_sta_concurrency_present(a1) & 1) != 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: eMLSR concurrency not allow to set link",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "ml_nlink_state_change_emlsr_no_conc");
        result = 4;
        goto LABEL_84;
      }
      LOBYTE(v186) = 0;
      LOBYTE(v175) = 0;
      BYTE4(v189[0]) = 0;
      LODWORD(v189[0]) = 0;
      LODWORD(v196) = 0;
      v194 = 0;
      v195 = 0;
      policy_mgr_get_ml_sta_info_psoc(a1, &v186, &v175, (__int64)v189, (__int64)&v194, nullptr, 0, 0);
      if ( (unsigned int)(unsigned __int8)v186 - 6 < 0xFFFFFFFB )
        goto LABEL_83;
      v45 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              LOBYTE(v189[0]),
              90);
      if ( v45 )
      {
        v46 = v45;
        if ( (ml_nlink_all_links_ready_for_state_change(a1, v45, a3) & 1) == 0 )
        {
          wlan_objmgr_vdev_release_ref(v46, 0x5Au, v47, v48, v49, v50, v51, v52, v53, v54, v55);
LABEL_43:
          v43 = "%s: exit no force state change";
          goto LABEL_15;
        }
        v56 = *(_QWORD *)(v46 + 1360);
        if ( v56 && *(_QWORD *)(v56 + 2224) )
        {
          qdf_mutex_acquire(v56 + 1656);
          qdf_mem_copy(&v191, (const void *)(*(_QWORD *)(v56 + 2224) + 1348LL), 0x12u);
          qdf_mutex_release(v56 + 1656);
        }
        else
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: mlo_ctx or sta_ctx null",
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            "ml_nlink_get_curr_force_state");
        }
        ml_nlink_handle_all_link_request(a1, v46, &v199);
        updated = ml_nlink_update_force_command_target(a1, v46);
        wlan_objmgr_vdev_release_ref(v46, 0x5Au, v86, v87, v88, v89, v90, v91, v92, v93, v94);
        if ( updated != 24 )
        {
          if ( !updated )
            goto LABEL_43;
          v124 = "ml_nlink_state_change_emlsr_no_conc";
LABEL_140:
          qdf_trace_msg(0x8Fu, 2u, "%s: exit err %d state change", v6, v7, v8, v9, v10, v11, v12, v13, v124, updated);
          result = updated;
          goto LABEL_84;
        }
        v123 = "ml_nlink_state_change_emlsr_no_conc";
LABEL_138:
        qdf_trace_msg(0x8Fu, 8u, "%s: exit pending force state change", v6, v7, v8, v9, v10, v11, v12, v13, v123);
        result = 24;
        goto LABEL_84;
      }
      v57 = LOBYTE(v189[0]);
LABEL_23:
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: invalid vdev for id %d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "ml_nlink_get_affect_ml_sta",
        v57);
      goto LABEL_83;
    }
LABEL_13:
    result = ml_nlink_state_change_emlsr(a1);
    goto LABEL_84;
  }
  if ( (policy_mgr_is_hw_dbs_capable(a1) & 1) == 0 )
    goto LABEL_13;
  v177 = 0;
  v175 = 0;
  v176 = 0;
  v174 = 0;
  v172 = 0;
  v173 = 0;
  v171 = 0;
  v170[0] = 0;
  v170[1] = 0;
  LOBYTE(v191) = 0;
  LOBYTE(v189[0]) = 0;
  BYTE4(v199) = 0;
  LODWORD(v199) = 0;
  LODWORD(v196) = 0;
  v194 = 0;
  v195 = 0;
  policy_mgr_get_ml_sta_info_psoc(a1, &v191, v189, (__int64)&v199, (__int64)&v194, nullptr, 0, 0);
  if ( (unsigned int)(unsigned __int8)v191 - 6 < 0xFFFFFFFB )
    goto LABEL_83;
  v23 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          a1,
          (unsigned __int8)v199,
          90);
  if ( !v23 )
  {
    v57 = (unsigned __int8)v199;
    goto LABEL_23;
  }
  v32 = v23;
  if ( (ml_nlink_all_links_ready_for_state_change(a1, v23, a3) & 1) == 0 )
  {
    wlan_objmgr_vdev_release_ref(v32, 0x5Au, v33, v34, v35, v36, v37, v38, v39, v40, v41);
    goto LABEL_81;
  }
  v42 = *(_QWORD *)(v32 + 1360);
  if ( v42 && *(_QWORD *)(v42 + 2224) )
  {
    qdf_mutex_acquire(v42 + 1656);
    qdf_mem_copy(v170, (const void *)(*(_QWORD *)(v42 + 2224) + 1348LL), 0x12u);
    qdf_mutex_release(v42 + 1656);
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: mlo_ctx or sta_ctx null",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "ml_nlink_get_curr_force_state");
  }
  ml_nlink_handle_mcc_links(a1, v32, &v175);
  v58 = *(_QWORD *)(v32 + 216);
  v181 = 0;
  v180 = 0;
  v190 = 0;
  v189[0] = 0;
  v189[1] = 0;
  v188 = 0;
  v186 = 0;
  v187 = 0;
  legacy_conn_info = policy_mgr_get_legacy_conn_info(a1, (__int64)&v180, (__int64)v189, (__int64)&v186, 5u);
  if ( (wlan_nan_is_sta_p2p_ndp_supported(a1, v60, v61, v62, v63, v64, v65, v66, v67) & 1) == 0 )
    goto LABEL_33;
  is_disc_active = wlan_nan_is_disc_active(a1, v68, v69, v70, v71, v72, v73, v74, v75);
  if ( !(_BYTE)legacy_conn_info || (is_disc_active & 1) == 0 )
    goto LABEL_33;
  if ( (v186 & 0xFFFFFFFE) == 2 )
  {
    is_disc_active = policy_mgr_is_vdev_high_tput_or_low_latency(a1, (unsigned __int8)v180);
    if ( (is_disc_active & 1) == 0 )
      goto LABEL_72;
  }
  if ( (unsigned __int8)legacy_conn_info != 1 )
  {
    if ( (HIDWORD(v186) & 0xFFFFFFFE) == 2 )
    {
      is_disc_active = policy_mgr_is_vdev_high_tput_or_low_latency(a1, BYTE1(v180));
      if ( (is_disc_active & 1) == 0 )
        goto LABEL_72;
    }
    if ( (unsigned __int8)legacy_conn_info != 2 )
    {
      if ( (v187 & 0xFFFFFFFE) == 2 )
      {
        is_disc_active = policy_mgr_is_vdev_high_tput_or_low_latency(a1, BYTE2(v180));
        if ( (is_disc_active & 1) == 0 )
          goto LABEL_72;
      }
      if ( (unsigned __int8)legacy_conn_info != 3 )
      {
        if ( (HIDWORD(v187) & 0xFFFFFFFE) == 2 )
        {
          is_disc_active = policy_mgr_is_vdev_high_tput_or_low_latency(a1, HIBYTE(v180));
          if ( (is_disc_active & 1) == 0 )
            goto LABEL_72;
        }
        if ( (unsigned __int8)legacy_conn_info != 4 )
        {
          if ( (v188 & 0xFFFFFFFE) == 2 )
          {
            is_disc_active = policy_mgr_is_vdev_high_tput_or_low_latency(a1, v181);
            if ( (is_disc_active & 1) == 0 )
              goto LABEL_72;
          }
          if ( (unsigned __int8)legacy_conn_info != 5 )
            goto LABEL_223;
        }
      }
    }
    wlan_nan_is_disc_active(a1, v68, v69, v70, v71, v72, v73, v74, v75);
  }
  else
  {
LABEL_33:
    if ( wlan_nan_is_disc_active(a1, v68, v69, v70, v71, v72, v73, v74, v75) && (unsigned __int8)legacy_conn_info <= 1u )
    {
      if ( !(unsigned int)wlan_nan_get_5ghz_social_ch_freq(v58, v77, v78, v79, v80, v81, v82, v83, v84) )
      {
LABEL_45:
        if ( (unsigned int)wlan_nan_get_24ghz_social_ch_freq(v58, v77, v78, v79, v80, v81, v82, v83, v84) )
        {
          _24ghz_social_ch_freq = wlan_nan_get_24ghz_social_ch_freq(v58, v77, v78, v79, v80, v81, v82, v83, v84);
          v96 = (unsigned __int8)legacy_conn_info++;
          *((_DWORD *)v189 + v96) = _24ghz_social_ch_freq;
          *((_DWORD *)&v186 + v96) = 5;
        }
        goto LABEL_60;
      }
      is_disc_active = wlan_nan_get_5ghz_social_ch_freq(v58, v77, v78, v79, v80, v81, v82, v83, v84);
      if ( (unsigned __int8)legacy_conn_info <= 5u )
      {
        *((_DWORD *)v189 + (unsigned __int8)legacy_conn_info) = is_disc_active;
        *((_DWORD *)&v186 + (unsigned __int8)legacy_conn_info) = 5;
        if ( (_BYTE)legacy_conn_info )
        {
          legacy_conn_info = 2;
LABEL_68:
          if ( (unsigned int)v186 < 4 || (_DWORD)v186 == 5 )
          {
            ml_nlink_handle_legacy_intf_3_ports(a1, v32, &v172, 0, legacy_conn_info, &v180, v189, &v186);
            ml_nlink_handle_standby_link_3_ports(a1, v32, &v172, legacy_conn_info, v189);
            goto LABEL_71;
          }
          goto LABEL_142;
        }
        legacy_conn_info = 1;
        goto LABEL_45;
      }
LABEL_223:
      __break(1u);
      goto LABEL_224;
    }
  }
LABEL_60:
  if ( !(_BYTE)legacy_conn_info )
    goto LABEL_72;
  if ( (unsigned __int8)legacy_conn_info != 1 )
    goto LABEL_68;
  if ( (int)v186 > 1 )
  {
    if ( (unsigned int)(v186 - 2) >= 2 )
    {
      if ( (_DWORD)v186 == 5 )
        goto LABEL_71;
      goto LABEL_142;
    }
    v97 = v189[0];
    LOBYTE(v178) = 0;
    v182 = 0;
    BYTE4(v191) = 0;
    LODWORD(v191) = 0;
    v201 = 0;
    v199 = 0;
    v200 = 0;
    v185 = 0;
    v184 = 0;
    v197 = 0;
    v198 = 0;
    v195 = 0;
    v196 = 0;
    v194 = 0;
    if ( (policy_mgr_is_vdev_high_tput_or_low_latency(a1, (unsigned __int8)v180) & 1) == 0 )
      goto LABEL_71;
    is_disc_active = ml_nlink_get_link_info(
                       a1,
                       v32,
                       1u,
                       5u,
                       &v194,
                       (unsigned int *)&v199,
                       (unsigned __int8 *)&v191,
                       &v184,
                       &v178,
                       &v182);
    v98 = (unsigned __int8)v178;
    if ( (unsigned __int8)v178 < 2u )
      goto LABEL_71;
    if ( (_DWORD)v199 == v97 )
    {
      v99 = 0;
      v100 = 1 << v184;
    }
    else
    {
      is_disc_active = policy_mgr_2_freq_always_on_same_mac(a1, (unsigned int)v199, v97);
      if ( (is_disc_active & 1) != 0 )
        v99 = 1 << v184;
      else
        v99 = 0;
      v100 = 0;
    }
    if ( HIDWORD(v199) == v97 )
    {
      v100 = 1 << SBYTE1(v184);
    }
    else
    {
      is_disc_active = policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(v199), v97);
      if ( (is_disc_active & 1) != 0 )
        v99 |= 1 << SBYTE1(v184);
    }
    if ( v98 == 2 )
      goto LABEL_199;
    if ( (_DWORD)v200 == v97 )
    {
      v100 = 1 << SBYTE2(v184);
    }
    else
    {
      is_disc_active = policy_mgr_2_freq_always_on_same_mac(a1, (unsigned int)v200, v97);
      if ( (is_disc_active & 1) != 0 )
        v99 |= 1 << SBYTE2(v184);
    }
    if ( v98 == 3 )
      goto LABEL_199;
    if ( HIDWORD(v200) == v97 )
    {
      v100 = 1 << SHIBYTE(v184);
    }
    else
    {
      is_disc_active = policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(v200), v97);
      if ( (is_disc_active & 1) != 0 )
        v99 |= 1 << SHIBYTE(v184);
    }
    if ( v98 == 4 )
      goto LABEL_199;
    if ( v201 == v97 )
    {
      v100 = 1 << v185;
    }
    else
    {
      is_disc_active = policy_mgr_2_freq_always_on_same_mac(a1, v201, v97);
      if ( (is_disc_active & 1) != 0 )
        v99 |= 1 << v185;
    }
    if ( v98 == 5 )
    {
LABEL_199:
      if ( (v182 & ~v99) != 0 )
      {
        if ( v99 )
        {
          WORD1(v172) = v99;
          v155 = v182 & ~(v100 | v99);
          if ( v155 )
          {
            v163 = 0;
            v157 = 0;
            v164 = v182 & ~(v100 | v99);
            while ( 1 )
            {
              if ( (v164 & 1) != 0 )
              {
                if ( v163 >= 0xF )
                  goto LABEL_218;
                ++v157;
              }
              v149 = v164 > 1;
              ++v163;
              v164 >>= 1;
              if ( !v149 )
                goto LABEL_219;
            }
          }
        }
        else
        {
          LOWORD(v155) = v182 & ~(_WORD)v100;
          if ( (v182 & ~v100) != 0 )
          {
            v165 = 0;
            v157 = 0;
            v166 = v182 & ~v100;
            while ( 1 )
            {
              if ( (v166 & 1) != 0 )
              {
                if ( v165 >= 0xF )
                  goto LABEL_218;
                ++v157;
              }
              v149 = v166 > 1;
              ++v165;
              v166 >>= 1;
              if ( !v149 )
                goto LABEL_219;
            }
          }
        }
        goto LABEL_221;
      }
      v159 = "%s: unexpected ML conc with legacy P2P freq %d";
      v160 = "ml_nlink_handle_legacy_p2p_intf";
      goto LABEL_210;
    }
    goto LABEL_224;
  }
  if ( !(_DWORD)v186 )
  {
    v97 = v189[0];
    LOBYTE(v178) = 0;
    v182 = 0;
    BYTE4(v191) = 0;
    LODWORD(v191) = 0;
    v201 = 0;
    v199 = 0;
    v200 = 0;
    v185 = 0;
    v184 = 0;
    v197 = 0;
    v198 = 0;
    v195 = 0;
    v196 = 0;
    v194 = 0;
    is_disc_active = ml_nlink_get_link_info(
                       a1,
                       v32,
                       1u,
                       5u,
                       &v194,
                       (unsigned int *)&v199,
                       (unsigned __int8 *)&v191,
                       &v184,
                       &v178,
                       &v182);
    v150 = (unsigned __int8)v178;
    if ( (unsigned __int8)v178 < 2uLL )
      goto LABEL_71;
    v151 = 0;
    v152 = 0;
    v169 = 0;
    do
    {
      if ( v151 == 5 )
        goto LABEL_224;
      v153 = *((unsigned int *)&v199 + v151);
      if ( (_DWORD)v153 == v97 )
      {
        v169 = 1 << *((_BYTE *)&v184 + v151);
      }
      else
      {
        is_disc_active = policy_mgr_2_freq_always_on_same_mac(a1, v153, v97);
        if ( (is_disc_active & 1) != 0
          || (is_disc_active = wlan_cm_same_band_sta_allowed(a1), (is_disc_active & 1) == 0)
          && (is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&v199 + v151)),
              is_disc_active = wlan_reg_is_24ghz_ch_freq(v97),
              ((is_24ghz_ch_freq ^ (unsigned int)is_disc_active) & 1) == 0)
          && (is_disc_active = policy_mgr_are_sbs_chan(a1, *((_DWORD *)&v199 + v151), v97), (is_disc_active & 1) == 0) )
        {
          v152 |= 1 << *((_BYTE *)&v184 + v151);
        }
      }
      ++v151;
    }
    while ( v150 != v151 );
    if ( (v182 & ~v152) != 0 )
    {
      if ( v152 )
      {
        WORD1(v172) = v152;
        v155 = v182 & ~(v169 | v152);
        if ( !v155 )
          goto LABEL_221;
        v156 = 0;
        v157 = 0;
        v158 = v182 & ~(v169 | v152);
        while ( 1 )
        {
          if ( (v158 & 1) != 0 )
          {
            if ( v156 >= 0xF )
              goto LABEL_218;
            ++v157;
          }
          v149 = v158 > 1;
          ++v156;
          v158 >>= 1;
          if ( !v149 )
            goto LABEL_219;
        }
      }
      LOWORD(v155) = v182 & ~(_WORD)v169;
      if ( (v182 & ~v169) == 0 )
        goto LABEL_221;
      v161 = 0;
      v157 = 0;
      v162 = v182 & ~v169;
      while ( 1 )
      {
        if ( (v162 & 1) != 0 )
        {
          if ( v161 >= 0xF )
          {
LABEL_218:
            qdf_trace_msg(
              0x8Fu,
              2u,
              "%s: linkid invalid %d 0x%x",
              v77,
              v78,
              v79,
              v80,
              v81,
              v82,
              v83,
              v84,
              "convert_link_bitmap_to_link_ids");
LABEL_219:
            if ( (v157 & 0xFE) == 0 )
              goto LABEL_221;
            WORD1(v173) = v155;
            LOBYTE(v173) = v157 - 1;
            goto LABEL_71;
          }
          ++v157;
        }
        v149 = v162 > 1;
        ++v161;
        v162 >>= 1;
        if ( !v149 )
          goto LABEL_219;
      }
    }
    v159 = "%s: unexpected ML conc with legacy STA freq %d";
    v160 = "ml_nlink_handle_legacy_sta_intf";
LABEL_210:
    qdf_trace_msg(0x8Fu, 8u, v159, v77, v78, v79, v80, v81, v82, v83, v84, v160, v97);
    goto LABEL_71;
  }
  if ( (_DWORD)v186 != 1 )
  {
LABEL_142:
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: unexpected legacy intf mode %d",
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      "ml_nlink_handle_legacy_intf");
    goto LABEL_72;
  }
  v125 = (unsigned __int8)v180;
  v126 = v189[0];
  v179[0] = 0;
  v185 = 0;
  v184 = 0;
  v201 = 0;
  v199 = 0;
  v200 = 0;
  v183 = 0;
  v182 = 0;
  v197 = 0;
  v198 = 0;
  v195 = 0;
  v196 = 0;
  v194 = 0;
  v193 = 0;
  v191 = 0;
  v192 = 0;
  ml_nlink_get_link_info(a1, v32, 1u, 5u, &v194, (unsigned int *)&v199, (unsigned __int8 *)&v184, &v182, v179, &v178);
  v127 = v179[0];
  if ( v179[0] < 2u )
    goto LABEL_71;
  v128 = policy_mgr_check_2ghz_only_sap_affected_link(a1, v125, v126, v179[0], (unsigned int *)&v199);
  if ( (v128 & 1) != 0 )
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: 2G only SAP vdev %d ch freq %d is not SCC with any MLO STA link",
      v129,
      v130,
      v131,
      v132,
      v133,
      v134,
      v135,
      v136,
      "ml_nlink_handle_legacy_sap_intf",
      v125,
      v126);
  v137 = policy_mgr_mode_specific_connection_count(a1, 5, &v191);
  if ( wlan_reg_is_24ghz_ch_freq(v199) && (_DWORD)v199 != 2437 && v137 )
    WORD1(v172) |= 1 << v182;
  if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(v199)) && HIDWORD(v199) != 2437 && v137 )
    WORD1(v172) |= 1 << SBYTE1(v182);
  if ( v127 != 2 )
  {
    if ( wlan_reg_is_24ghz_ch_freq(v200) && (_DWORD)v200 != 2437 && v137 )
      WORD1(v172) |= 1 << SBYTE2(v182);
    if ( v127 != 3 )
    {
      if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(v200)) && HIDWORD(v200) != 2437 && v137 )
        WORD1(v172) |= 1 << SHIBYTE(v182);
      if ( v127 != 4 )
      {
        is_disc_active = wlan_reg_is_24ghz_ch_freq(v201);
        if ( (is_disc_active & 1) != 0 && v201 != 2437 && v137 )
          WORD1(v172) |= 1 << v183;
        if ( v127 != 5 )
        {
LABEL_224:
          __break(0x5512u);
          return ml_nlink_state_change_emlsr(is_disc_active);
        }
      }
    }
  }
  if ( (v128 & 1) == 0 )
    goto LABEL_71;
  if ( wlan_reg_is_24ghz_ch_freq(v199) )
    v138 = 0;
  else
    v138 = 1 << v182;
  v139 = wlan_reg_is_24ghz_ch_freq(HIDWORD(v199));
  v140 = 1 << SBYTE1(v182);
  if ( v139 )
    v140 = 0;
  v141 = v140 | v138;
  if ( v127 == 2 )
    goto LABEL_130;
  v142 = wlan_reg_is_24ghz_ch_freq(v200);
  v143 = 1 << SBYTE2(v182);
  if ( v142 )
    v143 = 0;
  v141 |= v143;
  if ( v127 == 3 )
    goto LABEL_130;
  v144 = wlan_reg_is_24ghz_ch_freq(HIDWORD(v200));
  v145 = 1 << SHIBYTE(v182);
  if ( v144 )
    v145 = 0;
  v141 |= v145;
  if ( v127 == 4 || wlan_reg_is_24ghz_ch_freq(v201) )
  {
LABEL_130:
    if ( !v141 )
      goto LABEL_71;
  }
  else
  {
    v141 |= 1 << v183;
  }
  v146 = 0;
  v147 = 0;
  v148 = v141;
  while ( (v148 & 1) == 0 )
  {
LABEL_132:
    v149 = v148 > 1;
    ++v146;
    v148 >>= 1;
    if ( !v149 )
      goto LABEL_194;
  }
  if ( v146 < 0xF )
  {
    ++v147;
    goto LABEL_132;
  }
  qdf_trace_msg(
    0x8Fu,
    2u,
    "%s: linkid invalid %d 0x%x",
    v77,
    v78,
    v79,
    v80,
    v81,
    v82,
    v83,
    v84,
    "convert_link_bitmap_to_link_ids");
LABEL_194:
  if ( (v147 & 0xFE) != 0 )
  {
    WORD1(v173) = v141;
    LOBYTE(v173) = v147 - 1;
    goto LABEL_71;
  }
LABEL_221:
  LOBYTE(v173) = 0;
LABEL_71:
  LODWORD(v168) = HIWORD(v172);
  LODWORD(v167) = BYTE4(v172);
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: inactive 0x%x active 0x%x inact num %d 0x%x act num %d 0x%x dyn 0x%x",
    v77,
    v78,
    v79,
    v80,
    v81,
    v82,
    v83,
    v84,
    "ml_nlink_handle_legacy_intf",
    WORD1(v172),
    (unsigned __int16)v172,
    (unsigned __int8)v173,
    WORD1(v173),
    v167,
    v168,
    WORD2(v173));
LABEL_72:
  WORD1(v175) |= WORD1(v172);
  if ( (_BYTE)v173 && (unsigned __int8)v173 >= (unsigned int)(unsigned __int8)v176 )
  {
    LOBYTE(v176) = v173;
    WORD1(v176) = WORD1(v173);
  }
  ml_nlink_handle_dynamic_inactive(a1, v32, v170, &v175);
  v109 = *(_QWORD *)(v32 + 1360);
  if ( v109 && *(_QWORD *)(v109 + 2224) )
  {
    qdf_mutex_acquire(v109 + 1656);
    v110 = *(_QWORD *)(v109 + 2224);
    v111 = BYTE4(v175);
    v112 = v176;
    *(_DWORD *)(v110 + 1376) = v175;
    v113 = WORD1(v176);
    *(_DWORD *)(v110 + 1372) = a2;
    *(_BYTE *)(v110 + 1380) = v111;
    *(_BYTE *)(v110 + 1384) = v112;
    *(_WORD *)(v110 + 1386) = v113;
    qdf_mutex_release(v109 + 1656);
  }
  else
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: mlo_ctx or sta_ctx null",
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      v108,
      "ml_nlink_update_concurrency_link_request");
  }
  ml_nlink_handle_all_link_request(a1, v32, &v175);
  updated = ml_nlink_update_force_command_target(a1, v32);
  wlan_objmgr_vdev_release_ref(v32, 0x5Au, v114, v115, v116, v117, v118, v119, v120, v121, v122);
  if ( updated == 24 )
  {
    v123 = "ml_nlink_state_change_mlmr";
    goto LABEL_138;
  }
  if ( updated )
  {
    v124 = "ml_nlink_state_change_mlmr";
    goto LABEL_140;
  }
LABEL_81:
  v43 = "%s: exit no force state change";
  v44 = "ml_nlink_state_change_mlmr";
LABEL_82:
  qdf_trace_msg(0x8Fu, 8u, v43, v6, v7, v8, v9, v10, v11, v12, v13, v44);
LABEL_83:
  result = 0;
LABEL_84:
  _ReadStatusReg(SP_EL0);
  return result;
}
