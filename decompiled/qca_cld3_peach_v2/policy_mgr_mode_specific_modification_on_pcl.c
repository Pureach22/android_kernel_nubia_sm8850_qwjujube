__int64 __fastcall policy_mgr_mode_specific_modification_on_pcl(
        __int64 a1,
        _DWORD *a2,
        _BYTE *a3,
        unsigned int *a4,
        __int64 a5,
        __int64 a6,
        unsigned int a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  __int64 result; // x0
  unsigned int v21; // w24
  unsigned int v22; // w27
  __int64 context; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x25
  __int64 v33; // x26
  unsigned int v34; // w24
  unsigned int v35; // w27
  unsigned int v36; // w25
  __int64 v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x24
  unsigned int dfs_master_capability; // w0
  unsigned int v48; // w19
  const char *v49; // x2
  unsigned __int64 v50; // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  int v75; // w28
  int v76; // w27
  __int64 v77; // x0
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  __int64 v86; // x28
  int v87; // w27
  __int64 v88; // x0
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  __int64 v97; // x28
  __int64 v98; // x0
  size_t v99; // x1
  unsigned int v100; // w23
  unsigned int v101; // w22
  unsigned int v102; // w25
  unsigned int v103; // w26
  unsigned int sta_sap_scc_on_dfs_chnl; // w0
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  const char *v113; // x2
  const char *v114; // x2
  const char *v115; // x3
  __int64 v116; // x4
  __int64 v117; // x5
  __int64 v118; // x6
  __int64 v119; // x7
  _BOOL4 v120; // w26
  unsigned __int64 v121; // x23
  unsigned int v122; // w28
  _BOOL4 v123; // w24
  unsigned int v124; // w0
  unsigned int v125; // w23
  _BOOL4 v126; // w25
  unsigned int v127; // w28
  _BOOL4 v128; // w26
  _BOOL4 v129; // [xsp+0h] [xbp-240h]
  char v130; // [xsp+14h] [xbp-22Ch]
  unsigned int v131; // [xsp+18h] [xbp-228h]
  __int64 v132; // [xsp+1Ch] [xbp-224h]
  char v133; // [xsp+24h] [xbp-21Ch]
  char v134; // [xsp+28h] [xbp-218h]
  _BOOL4 v135; // [xsp+28h] [xbp-218h]
  _BYTE v136[4]; // [xsp+2Ch] [xbp-214h] BYREF
  _QWORD v137[13]; // [xsp+30h] [xbp-210h] BYREF
  _DWORD s[102]; // [xsp+98h] [xbp-1A8h] BYREF
  __int64 v139; // [xsp+230h] [xbp-10h]

  result = 0;
  v139 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (int)a6 > 2 )
  {
    if ( (_DWORD)a6 != 3 )
    {
      if ( (_DWORD)a6 == 5 )
        goto LABEL_70;
      if ( (_DWORD)a6 != 6 )
      {
LABEL_15:
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: unexpected mode %d",
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          a15,
          "policy_mgr_mode_specific_modification_on_pcl",
          (unsigned int)a6);
        result = 16;
        goto LABEL_70;
      }
      v21 = a5;
      memset(s, 0, sizeof(s));
      v22 = *a4;
      memset(v137, 0, 102);
      context = policy_mgr_get_context(a1);
      if ( !context )
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: pm_ctx is NULL",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "policy_mgr_pcl_modification_for_ll_lt_sap");
        result = 16;
        goto LABEL_70;
      }
      v32 = context;
      policy_mgr_pcl_modification_for_sap(a1, a2, a3, a4, v21, 6, a7);
      if ( *a4 )
      {
        v33 = 0;
        v34 = 0;
        v130 = 0;
        v131 = v22;
        v133 = 0;
        v134 = 0;
        v132 = (unsigned __int8)a7;
        while ( 1 )
        {
          if ( wlan_reg_is_24ghz_ch_freq(a2[v33])
            || (wlan_reg_is_passive_for_freq(*(_QWORD *)(v32 + 8), a2[v33], v51, v52, v53, v54, v55, v56, v57, v58) & 1) != 0
            || (wlan_reg_is_dfs_for_freq(*(_QWORD *)(v32 + 8), a2[v33], v59, v60, v61, v62, v63, v64, v65, v66) & 1) != 0 )
          {
            goto LABEL_18;
          }
          if ( !wlan_reg_is_6ghz_chan_freq(a2[v33])
            || (v75 = a2[v33], (wlan_reg_is_6ghz_psc_chan_freq(v75, v67, v68, v69, v70, v71, v72, v73, v74) & 1) != 0)
            && wlan_reg_is_6ghz_unii5_chan_freq(v75) )
          {
            if ( (wlan_ll_lt_sap_is_freq_in_avoid_list(a1, (unsigned int)a2[v33]) & 1) != 0 )
            {
              v133 = 1;
            }
            else
            {
              v76 = a2[v33];
              v77 = policy_mgr_get_context(a1);
              if ( v77 )
              {
                v86 = v77;
                qdf_mutex_acquire(v77 + 56);
                if ( BYTE4(qword_8D4F00) == 1
                  && (_DWORD)qword_8D4F00 != (unsigned __int8)a7
                  && HIDWORD(pm_conc_connection_list) == v76
                  || BYTE4(qword_8D4F24) == 1
                  && (_DWORD)qword_8D4F24 != (unsigned __int8)a7
                  && HIDWORD(qword_8D4F0C) == v76
                  || BYTE4(qword_8D4F48) == 1
                  && (_DWORD)qword_8D4F48 != (unsigned __int8)a7
                  && HIDWORD(qword_8D4F30) == v76
                  || BYTE4(qword_8D4F6C) == 1
                  && (_DWORD)qword_8D4F6C != (unsigned __int8)a7
                  && HIDWORD(qword_8D4F54) == v76
                  || BYTE4(qword_8D4F90) == 1
                  && (_DWORD)qword_8D4F90 != (unsigned __int8)a7
                  && HIDWORD(qword_8D4F78) == v76 )
                {
                  qdf_mutex_release(v86 + 56);
                  v22 = v131;
                  BYTE4(v132) = 1;
                  goto LABEL_18;
                }
                qdf_mutex_release(v86 + 56);
              }
              else
              {
                qdf_trace_msg(
                  0x4Fu,
                  2u,
                  "%s: Invalid Context",
                  v78,
                  v79,
                  v80,
                  v81,
                  v82,
                  v83,
                  v84,
                  v85,
                  "policy_mgr_vdev_present_with_freq");
              }
              v87 = a2[v33];
              v88 = policy_mgr_get_context(a1);
              if ( !v88 )
              {
                v98 = qdf_trace_msg(
                        0x4Fu,
                        2u,
                        "%s: Invalid Context",
                        v89,
                        v90,
                        v91,
                        v92,
                        v93,
                        v94,
                        v95,
                        v96,
                        "policy_mgr_inact_vdev_present_with_freq");
LABEL_55:
                v22 = v131;
                if ( v34 >= 0x66 )
                {
                  __break(0x5512u);
                  return policy_mgr_modify_pcl_based_on_dnbs(v98);
                }
                s[v34] = a2[v33];
                *((_BYTE *)v137 + v34++) = a3[v33];
                goto LABEL_18;
              }
              v97 = v88;
              qdf_mutex_acquire(v88 + 56);
              if ( (pm_disabled_ml_links[0] != 1
                 || (unsigned __int8)byte_8D4FCC == (unsigned __int8)a7
                 || dword_8D4FC8 != v87)
                && (byte_8D4FD0 != 1 || (unsigned __int8)byte_8D4FDC == (unsigned __int8)a7 || dword_8D4FD8 != v87) )
              {
                v98 = qdf_mutex_release(v97 + 56);
                goto LABEL_55;
              }
              qdf_mutex_release(v97 + 56);
              v22 = v131;
              v130 = 1;
            }
          }
          else
          {
            v134 = 1;
          }
LABEL_18:
          v50 = *a4;
          if ( ++v33 >= v50 )
          {
            v99 = (unsigned int)(4 * v50);
            v100 = v133 & 1;
            v101 = v134 & 1;
            v102 = BYTE4(v132) & 1;
            v103 = v130 & 1;
            if ( v22 != v34 )
              goto LABEL_67;
LABEL_69:
            result = 0;
            goto LABEL_70;
          }
        }
      }
      v34 = 0;
      v101 = 0;
      v100 = 0;
      v102 = 0;
      v103 = 0;
      v99 = 0;
      if ( !v22 )
        goto LABEL_69;
LABEL_67:
      qdf_mem_set(a2, v99, 0);
      qdf_mem_set(a3, *a4, 0);
      qdf_mem_copy(a2, s, 4 * v34);
      qdf_mem_copy(a3, v137, v34);
      v114 = "%s: Modified PCL: 6Ghz %d avoid_list %d scc %d inact scc %d";
      v115 = "policy_mgr_pcl_modification_for_ll_lt_sap";
      v116 = v101;
      v117 = v100;
      v118 = v102;
      v119 = v103;
      *a4 = v34;
LABEL_68:
      qdf_trace_msg(0x4Fu, 8u, v114, v105, v106, v107, v108, v109, v110, v111, v112, v115, v116, v117, v118, v119, v129);
      goto LABEL_69;
    }
    v35 = *a4;
    v136[0] = 0;
    policy_mgr_update_with_safe_channel_list(a1, a2, a4, a3, a5);
    v36 = *a4;
    LOBYTE(s[0]) = 0;
    LOBYTE(v137[0]) = 0;
    v37 = policy_mgr_get_context(a1);
    if ( v37 )
    {
      v46 = v37;
      dfs_master_capability = ucfg_mlme_get_dfs_master_capability(a1, s);
      if ( dfs_master_capability )
      {
        v48 = dfs_master_capability;
        v49 = "%s: failed to get dfs master capable";
      }
      else
      {
        sta_sap_scc_on_dfs_chnl = policy_mgr_get_sta_sap_scc_on_dfs_chnl(a1, v137);
        if ( !sta_sap_scc_on_dfs_chnl )
        {
          v120 = 0;
          if ( LOBYTE(s[0]) == 1 && LOBYTE(v137[0]) )
            v120 = *(unsigned __int8 *)(v46 + 2232) == 1;
          v135 = v35 != v36;
          if ( *a4 )
          {
            v121 = 0;
            v122 = 0;
            do
            {
              if ( !wlan_reg_is_passive_or_disable_for_pwrmode(
                      *(_QWORD *)(v46 + 8),
                      a2[v121],
                      0,
                      v38,
                      v39,
                      v40,
                      v41,
                      v42,
                      v43,
                      v44,
                      v45)
                || v120
                && (wlan_reg_is_dfs_for_freq(*(_QWORD *)(v46 + 8), a2[v121], v38, v39, v40, v41, v42, v43, v44, v45) & 1) != 0 )
              {
                a2[v122] = a2[v121];
                a3[v122++] = a3[v121];
              }
              ++v121;
            }
            while ( v121 < *a4 );
          }
          else
          {
            v122 = 0;
          }
          *a4 = v122;
          v123 = v36 != v122;
          v124 = policy_mgr_modify_sap_pcl_based_on_dfs(a1, a2, a3, a4);
          if ( v124 )
          {
            v113 = "%s: failed to get dfs modified pcl for GO";
          }
          else
          {
            v125 = *a4;
            v126 = v122 != *a4;
            wlan_mlme_get_srd_master_mode_for_vdev(a1, 3, v136);
            if ( (v136[0] & 1) != 0 || (v124 = policy_mgr_modify_pcl_based_on_srd(a1, a2, a3, a4)) == 0 )
            {
              v127 = *a4;
              v128 = v125 != *a4;
              v124 = policy_mgr_modify_sap_go_4th_conc_disallow(a1, 3, a2, a3, a4);
              if ( !v124 )
              {
                if ( v35 == *a4 )
                  goto LABEL_69;
                v116 = v135;
                v114 = "%s: Modified by: safe_ch %d enabled %d dfs %d srd %d 4th_conc %d";
                v115 = "policy_mgr_pcl_modification_for_p2p_go";
                v117 = v123;
                v118 = v126;
                v119 = v128;
                v129 = v127 != *a4;
                goto LABEL_68;
              }
              v113 = "%s: failed to modify pcl for 4th go channels";
            }
            else
            {
              v113 = "%s: Failed to modify SRD in pcl for GO";
            }
          }
          v48 = v124;
LABEL_65:
          qdf_trace_msg(
            0x4Fu,
            2u,
            v113,
            v105,
            v106,
            v107,
            v108,
            v109,
            v110,
            v111,
            v112,
            "policy_mgr_pcl_modification_for_p2p_go");
          result = v48;
          goto LABEL_70;
        }
        v48 = sta_sap_scc_on_dfs_chnl;
        v49 = "%s: failed to get sta_sap_scc_on_dfs_chnl";
      }
    }
    else
    {
      v48 = 16;
      v49 = "%s: context is NULL";
    }
    qdf_trace_msg(
      0x4Fu,
      2u,
      v49,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "policy_mgr_modify_pcl_based_on_enabled_channels");
    v113 = "%s: failed to get modified pcl for GO";
    goto LABEL_65;
  }
  if ( (_DWORD)a6 )
  {
    if ( (_DWORD)a6 == 1 )
    {
      result = policy_mgr_pcl_modification_for_sap(a1, a2, a3, a4, a5, a6, a7);
      goto LABEL_70;
    }
    if ( (_DWORD)a6 != 2 )
      goto LABEL_15;
  }
LABEL_70:
  _ReadStatusReg(SP_EL0);
  return result;
}
