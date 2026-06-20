__int64 __fastcall policy_mgr_mode_specific_modification_on_pcl(
        __int64 a1,
        _DWORD *a2,
        _BYTE *a3,
        unsigned int *a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
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
  unsigned int v20; // w23
  unsigned int v21; // w25
  unsigned int v22; // w28
  __int64 context; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x24
  __int64 v33; // x26
  unsigned int v34; // w23
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
  int v75; // w27
  int v76; // w25
  __int64 v77; // x0
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  __int64 v86; // x27
  size_t v87; // x1
  unsigned int v88; // w24
  unsigned int v89; // w22
  unsigned int v90; // w25
  unsigned int sta_sap_scc_on_dfs_chnl; // w0
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  const char *v100; // x2
  const char *v101; // x2
  const char *v102; // x3
  __int64 v103; // x4
  __int64 v104; // x5
  __int64 v105; // x6
  _BOOL8 v106; // x7
  _BOOL4 v107; // w26
  unsigned __int64 v108; // x23
  unsigned int v109; // w28
  _BOOL4 v110; // w24
  unsigned int v111; // w0
  unsigned int v112; // w23
  _BOOL4 v113; // w25
  unsigned int v114; // w28
  _BOOL4 v115; // w26
  _BOOL4 v116; // [xsp+0h] [xbp-230h]
  __int64 v117; // [xsp+Ch] [xbp-224h]
  char v118; // [xsp+14h] [xbp-21Ch]
  char v119; // [xsp+18h] [xbp-218h]
  _BOOL4 v120; // [xsp+18h] [xbp-218h]
  _BYTE v121[4]; // [xsp+1Ch] [xbp-214h] BYREF
  _QWORD v122[13]; // [xsp+20h] [xbp-210h] BYREF
  _DWORD s[102]; // [xsp+88h] [xbp-1A8h] BYREF
  __int64 v124; // [xsp+220h] [xbp-10h]

  result = 0;
  v124 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (int)a6 > 2 )
  {
    if ( (_DWORD)a6 != 3 )
    {
      if ( (_DWORD)a6 == 5 )
        goto LABEL_60;
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
        goto LABEL_60;
      }
      v20 = a5;
      v21 = a7;
      memset(s, 0, sizeof(s));
      v22 = *a4;
      memset(v122, 0, 102);
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
        goto LABEL_60;
      }
      v32 = context;
      policy_mgr_pcl_modification_for_sap(a1, a2, a3, a4, v20, 6, v21);
      if ( !*a4 )
      {
        v34 = 0;
        v89 = 0;
        v88 = 0;
        v90 = 0;
        v87 = 0;
        if ( !v22 )
          goto LABEL_59;
        goto LABEL_57;
      }
      v33 = 0;
      v34 = 0;
      v118 = 0;
      v119 = 0;
      v117 = (unsigned __int8)v21;
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
            v118 = 1;
          }
          else
          {
            v76 = a2[v33];
            v77 = policy_mgr_get_context(a1);
            if ( !v77 )
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
              if ( v34 >= 0x66 )
                goto LABEL_47;
LABEL_45:
              s[v34] = a2[v33];
              *((_BYTE *)v122 + v34++) = a3[v33];
              goto LABEL_18;
            }
            v86 = v77;
            qdf_mutex_acquire(v77 + 56);
            if ( (BYTE4(qword_81C458) != 1
               || (_DWORD)qword_81C458 == (_DWORD)v117
               || HIDWORD(pm_conc_connection_list) != v76)
              && (BYTE4(qword_81C47C) != 1 || (_DWORD)qword_81C47C == (_DWORD)v117 || HIDWORD(qword_81C464) != v76)
              && (BYTE4(qword_81C4A0) != 1 || (_DWORD)qword_81C4A0 == (_DWORD)v117 || HIDWORD(qword_81C488) != v76)
              && (BYTE4(qword_81C4C4) != 1 || (_DWORD)qword_81C4C4 == (_DWORD)v117 || HIDWORD(qword_81C4AC) != v76)
              && (BYTE4(qword_81C4E8) != 1 || (_DWORD)qword_81C4E8 == (_DWORD)v117 || HIDWORD(qword_81C4D0) != v76) )
            {
              qdf_mutex_release(v86 + 56);
              if ( v34 >= 0x66 )
              {
LABEL_47:
                __break(0x5512u);
LABEL_48:
                v87 = (unsigned int)(4 * v50);
                v88 = v118 & 1;
                v89 = v119 & 1;
                v90 = BYTE4(v117) & 1;
                if ( v22 == v34 )
                {
LABEL_59:
                  result = 0;
                  goto LABEL_60;
                }
LABEL_57:
                qdf_mem_set(a2, v87, 0);
                qdf_mem_set(a3, *a4, 0);
                qdf_mem_copy(a2, s, 4 * v34);
                qdf_mem_copy(a3, v122, v34);
                v101 = "%s: Modified PCL: 6Ghz %d avoid_list %d scc %d inact scc %d";
                v102 = "policy_mgr_pcl_modification_for_ll_lt_sap";
                v103 = v89;
                v104 = v88;
                v105 = v90;
                v106 = 0;
                *a4 = v34;
LABEL_58:
                qdf_trace_msg(
                  0x4Fu,
                  8u,
                  v101,
                  v92,
                  v93,
                  v94,
                  v95,
                  v96,
                  v97,
                  v98,
                  v99,
                  v102,
                  v103,
                  v104,
                  v105,
                  v106,
                  v116);
                goto LABEL_59;
              }
              goto LABEL_45;
            }
            qdf_mutex_release(v86 + 56);
            BYTE4(v117) = 1;
          }
        }
        else
        {
          v119 = 1;
        }
LABEL_18:
        v50 = *a4;
        if ( ++v33 >= v50 )
          goto LABEL_48;
      }
    }
    v35 = *a4;
    v121[0] = 0;
    policy_mgr_update_with_safe_channel_list(a1, a2, a4, a3, a5);
    v36 = *a4;
    LOBYTE(s[0]) = 0;
    LOBYTE(v122[0]) = 0;
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
        sta_sap_scc_on_dfs_chnl = policy_mgr_get_sta_sap_scc_on_dfs_chnl(a1, v122);
        if ( !sta_sap_scc_on_dfs_chnl )
        {
          v107 = 0;
          if ( LOBYTE(s[0]) == 1 && LOBYTE(v122[0]) )
            v107 = *(unsigned __int8 *)(v46 + 2232) == 1;
          v120 = v35 != v36;
          if ( *a4 )
          {
            v108 = 0;
            v109 = 0;
            do
            {
              if ( !wlan_reg_is_passive_or_disable_for_pwrmode(
                      *(_QWORD *)(v46 + 8),
                      a2[v108],
                      0,
                      v38,
                      v39,
                      v40,
                      v41,
                      v42,
                      v43,
                      v44,
                      v45)
                || v107
                && (wlan_reg_is_dfs_for_freq(*(_QWORD *)(v46 + 8), a2[v108], v38, v39, v40, v41, v42, v43, v44, v45) & 1) != 0 )
              {
                a2[v109] = a2[v108];
                a3[v109++] = a3[v108];
              }
              ++v108;
            }
            while ( v108 < *a4 );
          }
          else
          {
            v109 = 0;
          }
          *a4 = v109;
          v110 = v36 != v109;
          v111 = policy_mgr_modify_sap_pcl_based_on_dfs(a1, a2, a3, a4);
          if ( v111 )
          {
            v100 = "%s: failed to get dfs modified pcl for GO";
          }
          else
          {
            v112 = *a4;
            v113 = v109 != *a4;
            wlan_mlme_get_srd_master_mode_for_vdev(a1, 3, v121);
            if ( (v121[0] & 1) != 0 || (v111 = policy_mgr_modify_pcl_based_on_srd(a1, a2, a3, a4)) == 0 )
            {
              v114 = *a4;
              v115 = v112 != *a4;
              v111 = policy_mgr_modify_sap_go_4th_conc_disallow(a1, 3, a2, a3, a4);
              if ( !v111 )
              {
                if ( v35 == *a4 )
                  goto LABEL_59;
                v103 = v120;
                v101 = "%s: Modified by: safe_ch %d enabled %d dfs %d srd %d 4th_conc %d";
                v102 = "policy_mgr_pcl_modification_for_p2p_go";
                v104 = v110;
                v105 = v113;
                v106 = v115;
                v116 = v114 != *a4;
                goto LABEL_58;
              }
              v100 = "%s: failed to modify pcl for 4th go channels";
            }
            else
            {
              v100 = "%s: Failed to modify SRD in pcl for GO";
            }
          }
          v48 = v111;
          goto LABEL_55;
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
    v100 = "%s: failed to get modified pcl for GO";
LABEL_55:
    qdf_trace_msg(0x4Fu, 2u, v100, v92, v93, v94, v95, v96, v97, v98, v99, "policy_mgr_pcl_modification_for_p2p_go");
    result = v48;
    goto LABEL_60;
  }
  if ( (_DWORD)a6 )
  {
    if ( (_DWORD)a6 == 1 )
    {
      result = policy_mgr_pcl_modification_for_sap(a1, a2, a3, a4, a5, a6, a7);
      goto LABEL_60;
    }
    if ( (_DWORD)a6 != 2 )
      goto LABEL_15;
  }
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return result;
}
