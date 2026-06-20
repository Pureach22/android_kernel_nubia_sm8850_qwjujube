__int64 __fastcall policy_mgr_pcl_modification_for_sap(
        __int64 a1,
        unsigned int *a2,
        void *a3,
        unsigned int *a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7)
{
  __int64 context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w22
  unsigned int v24; // w21
  _BOOL4 v25; // w22
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned int v35; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w28
  const char *v45; // x2
  const char *v46; // x2
  unsigned int v47; // w19
  _BOOL4 v48; // w21
  __int64 v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x28
  unsigned __int64 v59; // x21
  unsigned int v60; // w27
  unsigned __int64 v61; // x8
  char v62; // w9
  size_t v63; // x1
  _BOOL4 v64; // w22
  unsigned int v65; // w0
  unsigned int v66; // w19
  _BOOL4 v67; // w27
  unsigned int v68; // w0
  unsigned int v69; // w26
  _BOOL4 v70; // w19
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  unsigned int indoor_channel_support; // w0
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  char sta_sap_scc_allowed_on_indoor_chnl; // w0
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  char v98; // w8
  unsigned __int64 v99; // x19
  unsigned int v100; // w27
  unsigned __int64 v101; // x8
  size_t v102; // x1
  unsigned int v103; // w21
  _BOOL4 v104; // w19
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  unsigned int v113; // w22
  _BOOL4 v114; // w27
  unsigned int v115; // w0
  unsigned int v116; // w21
  _BOOL4 v117; // w26
  unsigned int v118; // w0
  unsigned int v119; // w22
  unsigned int v120; // w0
  unsigned int v121; // w28
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  _BOOL4 v130; // [xsp+44h] [xbp-24Ch]
  _BOOL4 v131; // [xsp+48h] [xbp-248h]
  _BOOL4 v132; // [xsp+4Ch] [xbp-244h]
  _BOOL4 v133; // [xsp+4Ch] [xbp-244h]
  _BOOL4 v134; // [xsp+50h] [xbp-240h]
  _BOOL4 v135; // [xsp+54h] [xbp-23Ch]
  unsigned int v136; // [xsp+58h] [xbp-238h]
  unsigned int v137; // [xsp+5Ch] [xbp-234h]
  _BOOL4 v138; // [xsp+60h] [xbp-230h]
  __int64 v139; // [xsp+60h] [xbp-230h]
  _BOOL4 v140; // [xsp+60h] [xbp-230h]
  unsigned int v141; // [xsp+6Ch] [xbp-224h]
  __int64 v142; // [xsp+70h] [xbp-220h]
  _BYTE v143[4]; // [xsp+78h] [xbp-218h] BYREF
  _BYTE v144[4]; // [xsp+7Ch] [xbp-214h] BYREF
  __int64 v145; // [xsp+80h] [xbp-210h] BYREF
  __int64 v146; // [xsp+88h] [xbp-208h]
  __int64 v147; // [xsp+90h] [xbp-200h]
  __int64 v148; // [xsp+98h] [xbp-1F8h]
  __int64 v149; // [xsp+A0h] [xbp-1F0h]
  __int64 v150; // [xsp+A8h] [xbp-1E8h]
  __int64 v151; // [xsp+B0h] [xbp-1E0h]
  __int64 v152; // [xsp+B8h] [xbp-1D8h]
  __int64 v153; // [xsp+C0h] [xbp-1D0h]
  __int64 v154; // [xsp+C8h] [xbp-1C8h]
  __int64 v155; // [xsp+D0h] [xbp-1C0h]
  _WORD v156[7]; // [xsp+D8h] [xbp-1B8h] BYREF
  _DWORD s[102]; // [xsp+E8h] [xbp-1A8h] BYREF
  __int64 v158; // [xsp+280h] [xbp-10h]

  v158 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v143[0] = 0;
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v142 = context;
    v23 = *a4;
    policy_mgr_update_with_safe_channel_list(a1, a2, a4, a3, a5);
    v24 = *a4;
    v141 = v23;
    v25 = v23 != *a4;
    if ( a6 == 1 )
    {
      v26 = policy_mgr_get_context(a1);
      if ( v26 )
      {
        if ( *(_DWORD *)(v26 + 960) )
        {
          v35 = policy_mgr_modify_sap_pcl_based_on_mandatory_channel(a1, (__int64)a2, (__int64)a3, a4, a7);
          if ( v35 )
          {
            v44 = v35;
            v45 = "%s: failed to get mandatory modified pcl for SAP";
LABEL_35:
            qdf_trace_msg(0x4Fu, 2u, v45, v36, v37, v38, v39, v40, v41, v42, v43, "policy_mgr_pcl_modification_for_sap");
            goto LABEL_36;
          }
        }
      }
      else
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: Invalid Context",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "policy_mgr_is_sap_mandatory_channel_set");
      }
    }
    v47 = *a4;
    v48 = v24 != *a4;
    memset(s, 0, sizeof(s));
    v155 = 0;
    memset(v156, 0, sizeof(v156));
    v153 = 0;
    v154 = 0;
    v151 = 0;
    v152 = 0;
    v149 = 0;
    v150 = 0;
    v147 = 0;
    v148 = 0;
    v145 = 0;
    v146 = 0;
    v49 = policy_mgr_get_context(a1);
    if ( !v49 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid Context",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "policy_mgr_modify_sap_pcl_based_on_nol");
      goto LABEL_13;
    }
    if ( *a4 > 0x66 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid PCL List Length %d",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "policy_mgr_modify_sap_pcl_based_on_nol");
LABEL_13:
      v46 = "%s: failed to get nol modified pcl for SAP";
      goto LABEL_14;
    }
    v136 = a7;
    v137 = a6;
    v135 = v25;
    if ( *a4 )
    {
      v58 = v49;
      v138 = v48;
      v59 = 0;
      v60 = 0;
      do
      {
        if ( !wlan_reg_is_disable_in_secondary_list_for_freq(
                *(_QWORD *)(v58 + 8),
                a2[v59],
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                v57) )
        {
          if ( v60 >= 0x66 )
LABEL_64:
            __break(0x5512u);
          v62 = *((_BYTE *)a3 + v59);
          s[v60] = a2[v59];
          *((_BYTE *)&v145 + v60++) = v62;
        }
        v61 = *a4;
        ++v59;
      }
      while ( v59 < v61 );
      v63 = (unsigned int)(4 * v61);
      v48 = v138;
    }
    else
    {
      v60 = 0;
      v63 = 0;
    }
    qdf_mem_set(a2, v63, 0);
    qdf_mem_set(a3, *a4, 0);
    qdf_mem_copy(a2, s, 4 * v60);
    qdf_mem_copy(a3, &v145, v60);
    *a4 = v60;
    v64 = v47 != v60;
    v65 = policy_mgr_modify_sap_pcl_based_on_dfs(a1, a2, a3, a4);
    if ( v65 )
    {
      v44 = v65;
      v45 = "%s: failed to get dfs modified pcl for SAP";
      goto LABEL_35;
    }
    v66 = *a4;
    v67 = v60 != *a4;
    wlan_mlme_get_srd_master_mode_for_vdev(a1, 1, v143);
    if ( (v143[0] & 1) == 0 )
    {
      v68 = policy_mgr_modify_pcl_based_on_srd(a1, a2, a3, a4);
      if ( v68 )
      {
        v44 = v68;
        v45 = "%s: Failed to modify SRD in pcl for SAP";
        goto LABEL_35;
      }
    }
    v69 = *a4;
    v70 = v66 != *a4;
    memset(s, 0, sizeof(s));
    v155 = 0;
    memset(v156, 0, sizeof(v156));
    v153 = 0;
    v154 = 0;
    v151 = 0;
    v152 = 0;
    v149 = 0;
    v150 = 0;
    v147 = 0;
    v148 = 0;
    v145 = 0;
    v146 = 0;
    v144[0] = 0;
    v139 = policy_mgr_get_context(a1);
    if ( !v139 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid Context",
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        "policy_mgr_modify_pcl_based_on_indoor");
      v44 = 16;
      goto LABEL_34;
    }
    if ( *a4 >= 0x67 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid PCL List Length %d",
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        "policy_mgr_modify_pcl_based_on_indoor");
      v44 = 16;
LABEL_34:
      v45 = "%s: failed to get indoor modified pcl for SAP";
      goto LABEL_35;
    }
    indoor_channel_support = ucfg_mlme_get_indoor_channel_support(a1, v144);
    if ( indoor_channel_support )
    {
      v44 = indoor_channel_support;
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: failed to get indoor channel skip info",
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        "policy_mgr_modify_pcl_based_on_indoor");
      goto LABEL_34;
    }
    v134 = v70;
    sta_sap_scc_allowed_on_indoor_chnl = policy_mgr_get_sta_sap_scc_allowed_on_indoor_chnl(a1);
    v98 = v144[0];
    if ( (v144[0] & 1) == 0 && (sta_sap_scc_allowed_on_indoor_chnl & 1) != 0 )
    {
      if ( (policy_mgr_is_special_mode_active_5g(a1, 2) & 1) != 0
        || (policy_mgr_is_special_mode_active_5g(a1, 0) & 1) != 0 )
      {
        goto LABEL_53;
      }
      v98 = v144[0];
    }
    if ( (v98 & 1) == 0 )
    {
      v132 = v67;
      if ( *a4 )
      {
        v99 = 0;
        v100 = 0;
        do
        {
          if ( (wlan_reg_is_freq_indoor_in_secondary_list(
                  *(_QWORD *)(v139 + 8),
                  a2[v99],
                  v90,
                  v91,
                  v92,
                  v93,
                  v94,
                  v95,
                  v96,
                  v97)
              & 1) != 0 )
          {
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: Remove freq: %d from PCL as it's indoor",
              v90,
              v91,
              v92,
              v93,
              v94,
              v95,
              v96,
              v97,
              "policy_mgr_modify_pcl_based_on_indoor",
              a2[v99]);
          }
          else
          {
            if ( v100 >= 0x66 )
              goto LABEL_64;
            s[v100] = a2[v99];
            *((_BYTE *)&v145 + v100++) = *((_BYTE *)a3 + v99);
          }
          v101 = *a4;
          ++v99;
        }
        while ( v99 < v101 );
        v102 = (unsigned int)(4 * v101);
      }
      else
      {
        v100 = 0;
        v102 = 0;
      }
      qdf_mem_set(a2, v102, 0);
      qdf_mem_set(a3, *a4, 0);
      qdf_mem_copy(a2, s, 4 * v100);
      qdf_mem_copy(a3, &v145, v100);
      *a4 = v100;
      v67 = v132;
    }
LABEL_53:
    v140 = v48;
    v103 = *a4;
    v104 = v69 != *a4;
    if ( (unsigned int)policy_mgr_filter_passive_ch(
                         *(_QWORD *)(v142 + 8),
                         (__int64)a2,
                         a4,
                         v90,
                         v91,
                         v92,
                         v93,
                         v94,
                         v95,
                         v96,
                         v97) )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: failed to filter passive channels",
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        "policy_mgr_pcl_modification_for_sap");
    }
    else
    {
      v131 = v64;
      v133 = v67;
      v113 = *a4;
      v114 = v103 != *a4;
      v115 = policy_mgr_modify_sap_pcl_for_6G_channels(a1, a2, a3, a4);
      if ( v115 )
      {
        v44 = v115;
        v45 = "%s: failed to modify pcl for 6G channels";
        goto LABEL_35;
      }
      v116 = *a4;
      v117 = v113 != *a4;
      v118 = policy_mgr_modify_sap_go_4th_conc_disallow(a1, 1, a2, a3, a4);
      if ( v118 )
      {
        v44 = v118;
        v45 = "%s: failed to modify pcl for 4th sap channels";
        goto LABEL_35;
      }
      v119 = *a4;
      v130 = v116 != *a4;
      v120 = policy_mgr_modify_sap_pcl_filter_mcc(a1, a2, a3, a4, v137);
      if ( v120 )
      {
        v44 = v120;
        v45 = "%s: failed to modify pcl for filter mcc";
        goto LABEL_35;
      }
      v121 = *a4;
      policy_mgr_modify_dual_sap_band_pcl_filter(a1, a2, a3, a4, v137, v142, v136);
      if ( v141 != *a4 )
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: Modified by: safe_ch %d mandatory %d nol %d dfs %d srd %d indoor %d passive %d 6 Ghz %d 4th_conc %d mcc %d dual_sap %d",
          v122,
          v123,
          v124,
          v125,
          v126,
          v127,
          v128,
          v129,
          "policy_mgr_pcl_modification_for_sap",
          v135,
          v140,
          v131,
          v133,
          v134,
          v104,
          v114,
          v117,
          v130,
          v119 != v121,
          v121 != *a4);
    }
    v44 = 0;
    goto LABEL_36;
  }
  v46 = "%s: Invalid context";
LABEL_14:
  qdf_trace_msg(0x4Fu, 2u, v46, v15, v16, v17, v18, v19, v20, v21, v22, "policy_mgr_pcl_modification_for_sap");
  v44 = 16;
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return v44;
}
