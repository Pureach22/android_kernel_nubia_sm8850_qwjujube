__int64 __fastcall sap_get_freq_list(
        __int64 a1,
        __int64 *a2,
        _WORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  __int64 v24; // x24
  int v25; // w26
  unsigned int v26; // w10
  int v27; // w27
  unsigned int v28; // w22
  _QWORD *v29; // x23
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w25
  __int64 v39; // x0
  __int64 v40; // x22
  __int64 v41; // x0
  __int64 v42; // x28
  unsigned int v43; // w28
  __int64 v44; // x19
  unsigned __int8 v45; // w23
  __int64 result; // x0
  __int64 v47; // x0
  bool v48; // zf
  __int64 v49; // x19
  __int64 v50; // x8
  int v51; // w24
  char v52; // w8
  unsigned int v53; // w25
  unsigned int v54; // w0
  unsigned int v55; // w27
  unsigned int v56; // w26
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int v65; // w27
  int v66; // w8
  __int64 v67; // x27
  unsigned int v68; // w0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x27
  unsigned int v78; // w0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  unsigned __int16 v87; // w0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  __int64 v96; // x27
  unsigned int v97; // w0
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  __int64 v106; // x27
  unsigned int v107; // w0
  __int64 v108; // x27
  unsigned __int16 v109; // w0
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  __int64 v118; // x8
  unsigned __int8 v119; // w27
  __int64 v120; // x8
  int v121; // w0
  unsigned __int8 v122; // w27
  __int64 v123; // x8
  int v124; // w0
  int v125; // w0
  __int64 v126; // x8
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  __int64 v135; // x8
  unsigned int v136; // w21
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  char v145; // [xsp+20h] [xbp-70h]
  int v146; // [xsp+24h] [xbp-6Ch]
  unsigned __int8 v147; // [xsp+28h] [xbp-68h]
  __int64 *v148; // [xsp+30h] [xbp-60h]
  unsigned __int8 v149; // [xsp+3Ch] [xbp-54h]
  __int64 v150; // [xsp+40h] [xbp-50h]
  int v151; // [xsp+48h] [xbp-48h]
  char v152; // [xsp+4Ch] [xbp-44h]
  __int64 v153; // [xsp+50h] [xbp-40h]
  __int64 v154; // [xsp+58h] [xbp-38h]
  char v155; // [xsp+64h] [xbp-2Ch]
  __int64 v156; // [xsp+68h] [xbp-28h]
  bool v157; // [xsp+74h] [xbp-1Ch] BYREF
  unsigned int v158; // [xsp+78h] [xbp-18h]
  unsigned int v159; // [xsp+7Ch] [xbp-14h]
  int v160; // [xsp+80h] [xbp-10h]
  unsigned int v161; // [xsp+84h] [xbp-Ch]
  __int64 v162; // [xsp+88h] [xbp-8h]

  v162 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v160 = 0;
  v158 = 0;
  v157 = 0;
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
  {
    qdf_trace_msg(0x39u, 2u, "%s: Invalid MAC context", v15, v16, v17, v18, v19, v20, v21, v22, "sap_get_freq_list");
    *a3 = 0;
    result = 5;
    *a2 = 0;
    goto LABEL_71;
  }
  v23 = *(_QWORD *)(a1 + 1536);
  v24 = context[1];
  v25 = *(_DWORD *)(a1 + 1620);
  v26 = *(_DWORD *)(v23 + 12);
  v27 = *(unsigned __int8 *)(v24 + 3168);
  v28 = *(unsigned __int16 *)(v23 + 42);
  v29 = context;
  v161 = *(_DWORD *)(v23 + 8);
  v159 = v26;
  wlansap_extend_to_acs_range();
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: Chan %d -> %d, width %d HW %d, expanded chan %d -> %d, band chan %d -> %d",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "sap_get_freq_list",
    *(unsigned int *)(*(_QWORD *)(a1 + 1536) + 8LL),
    *(unsigned int *)(*(_QWORD *)(a1 + 1536) + 12LL),
    v28,
    *(unsigned int *)(*(_QWORD *)(a1 + 1536) + 4LL),
    v161,
    v159,
    v160,
    v158);
  v38 = *(unsigned __int8 *)(v29[1] + 3208LL);
  v39 = _qdf_mem_malloc(0x198u, "sap_get_freq_list", 4908);
  if ( !v39 )
  {
    *a3 = 0;
    result = 2;
    *a2 = 0;
    goto LABEL_71;
  }
  v40 = v39;
  v41 = _qdf_mem_malloc(0x96u, "sap_get_freq_list", 4915);
  if ( !v41 )
  {
    v47 = v40;
    *a3 = 0;
    *a2 = 0;
LABEL_11:
    _qdf_mem_free(v47);
    result = 2;
    goto LABEL_71;
  }
  v42 = v41;
  v156 = _qdf_mem_malloc(0x96u, "sap_get_freq_list", 4923);
  if ( !v156 )
  {
    *a3 = 0;
    *a2 = 0;
    _qdf_mem_free(v40);
    v47 = v42;
    goto LABEL_11;
  }
  v150 = v42;
  v43 = (unsigned __int8)v160;
  v148 = a2;
  if ( v158 < (unsigned __int8)v160 )
  {
    v44 = v150;
    v45 = 0;
    goto LABEL_62;
  }
  if ( v27 )
    v48 = v25 == 2;
  else
    v48 = 1;
  v49 = v156;
  v154 = v24 + 4428;
  v50 = v24 + 5248;
  v51 = (unsigned __int8)v160;
  v153 = v50;
  v52 = v48;
  v146 = v38;
  v53 = 0;
  v145 = v52;
  v155 = 0;
  v149 = 0;
  v152 = 0;
  v147 = 0;
  v151 = 100;
  do
  {
    v54 = wlan_reg_ch_to_freq(v43);
    v55 = v161;
    v56 = v54;
    if ( v55 > (unsigned int)wlan_reg_ch_to_freq(v43) )
      goto LABEL_20;
    v65 = v159;
    if ( v65 < (unsigned int)wlan_reg_ch_to_freq(v43) )
      goto LABEL_20;
    v66 = *((unsigned __int8 *)v29 + 17112);
    if ( v66 != 1 )
      goto LABEL_19;
    v67 = v29[2695];
    v68 = wlan_reg_ch_to_freq(v43);
    if ( !(unsigned int)wlan_reg_get_channel_state_from_secondary_list_for_freq(
                          v67,
                          v68,
                          v69,
                          v70,
                          v71,
                          v72,
                          v73,
                          v74,
                          v75,
                          v76) )
    {
      v66 = *((unsigned __int8 *)v29 + 17112);
LABEL_19:
      if ( v66 )
        goto LABEL_20;
      v77 = v29[2695];
      v78 = wlan_reg_ch_to_freq(v43);
      if ( (unsigned int)wlan_reg_get_channel_state_from_secondary_list_for_freq(
                           v77,
                           v78,
                           v79,
                           v80,
                           v81,
                           v82,
                           v83,
                           v84,
                           v85,
                           v86) != 3 )
        goto LABEL_20;
    }
    v87 = wlan_reg_ch_to_freq(v43);
    if ( wlan_reg_is_6ghz_chan_freq(v87)
      || !sap_dfs_is_channel_in_nol_list(a1, v56, 0, v88, v89, v90, v91, v92, v93, v94, v95) )
    {
      wlan_reg_ch_to_freq(v43);
      if ( (wlan_reg_is_dsrc_freq() & 1) == 0
        && (wlansap_is_channel_present_in_acs_list(
              v56,
              *(_QWORD *)(*(_QWORD *)(a1 + 1536) + 16LL),
              *(unsigned __int8 *)(*(_QWORD *)(a1 + 1536) + 24LL))
          & 1) != 0 )
      {
        v96 = v29[2695];
        v97 = wlan_reg_ch_to_freq(v43);
        if ( (wlan_reg_is_dfs_in_secondary_list_for_freq(v96, v97, v98, v99, v100, v101, v102, v103, v104, v105) & 1) != 0 )
        {
          if ( (v145 & 1) != 0 )
            goto LABEL_20;
          v106 = v29[2694];
          v107 = wlan_reg_ch_to_freq(v43);
          if ( (policy_mgr_disallow_mcc(v106, v107) & 1) != 0 )
            goto LABEL_20;
          v151 = *(unsigned __int8 *)(v29[1] + 5372LL);
          v152 = 1;
        }
        wlan_mlme_get_srd_master_mode_for_vdev(v29[2694], *(_DWORD *)(*(_QWORD *)(a1 + 16) + 16LL), &v157);
        if ( v157
          || (v108 = v29[2695],
              v109 = wlan_reg_ch_to_freq(v43),
              (wlan_reg_is_etsi_srd_chan_for_freq(v108, v109, v110, v111, v112, v113, v114, v115, v116, v117) & 1) == 0) )
        {
          v118 = v29[1];
          if ( *(_WORD *)(v118 + 5368) )
          {
            v119 = 0;
            do
            {
              v120 = v153 + 12LL * v119;
              if ( v56 >= *(_DWORD *)v120 && v56 <= *(_DWORD *)(v120 + 4) )
              {
                v151 = *(unsigned __int8 *)(v120 + 8);
                v57 = scnprintf(v150 + v53, 150 - v53, "%d[%d] ", v56, v151);
                v53 += v121;
                if ( v53 >= 0x8B )
                {
                  qdf_trace_msg(
                    0x39u,
                    8u,
                    "ACS Range Freq Normalize factor(%d): %s",
                    v57,
                    v58,
                    v59,
                    v60,
                    v61,
                    v62,
                    v63,
                    v64,
                    (unsigned __int8)(v149 + 1),
                    v150);
                  v53 = 0;
                  v149 = 0;
                }
                else
                {
                  ++v149;
                }
                v49 = v156;
                v152 = 1;
              }
              v118 = v29[1];
              ++v119;
            }
            while ( *(unsigned __int16 *)(v118 + 5368) > (unsigned int)v119 );
          }
          if ( *(_WORD *)(v118 + 5244) )
          {
            v122 = 0;
            do
            {
              v123 = v154 + 8LL * v122;
              if ( v56 == *(_DWORD *)v123 )
              {
                v151 = *(unsigned __int8 *)(v123 + 4);
                v57 = scnprintf(v49, 150, "%d[%d] ", v56, v151);
                v53 += v124;
                if ( v53 >= 0x8B )
                {
                  qdf_trace_msg(
                    0x39u,
                    8u,
                    "ACS Freq Normalize factor(%d): %s",
                    v57,
                    v58,
                    v59,
                    v60,
                    v61,
                    v62,
                    v63,
                    v64,
                    (unsigned __int8)(v155 + 1),
                    v49);
                  v155 = 0;
                }
                else
                {
                  ++v155;
                }
                v152 = 1;
              }
              ++v122;
            }
            while ( *(unsigned __int16 *)(v29[1] + 5244LL) > (unsigned int)v122 );
          }
          if ( (v152 & 1) == 0 || v151 )
          {
            v125 = wlan_reg_ch_to_freq(v43);
            v126 = v147++;
            *(_DWORD *)(v40 + 4 * v126) = v125;
          }
          else
          {
            v151 = 0;
            v152 = 0;
          }
        }
      }
    }
LABEL_20:
    v43 = (unsigned __int8)++v51;
  }
  while ( v158 >= (unsigned __int8)v51 );
  if ( v53 )
  {
    v44 = v150;
    qdf_trace_msg(
      0x39u,
      8u,
      "ACS Range Freq Normalize factor(%d): %s",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v149,
      v150);
    v38 = v146;
  }
  else
  {
    v38 = v146;
    v44 = v150;
  }
  v45 = v147;
LABEL_62:
  _qdf_mem_free(v156);
  _qdf_mem_free(v44);
  if ( v45 )
  {
    v135 = 0;
    *a3 = v45;
    *v148 = v40;
    do
    {
      *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 1536) + 16LL) + v135) = *(_DWORD *)(v40 + v135);
      v135 += 4;
    }
    while ( 4LL * v45 != v135 );
    *(_BYTE *)(*(_QWORD *)(a1 + 1536) + 24LL) = v45;
    sap_dump_acs_channel(*(_QWORD *)(a1 + 1536));
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      4u,
      "%s: No active channels present for the current region",
      v127,
      v128,
      v129,
      v130,
      v131,
      v132,
      v133,
      v134,
      "sap_get_freq_list");
    if ( v38 )
    {
      v136 = v161;
      if ( v136 > (unsigned int)wlan_reg_ch_to_freq(v158) )
        qdf_trace_msg(
          0x39u,
          4u,
          "%s: SAP can't be started as due to LTE COEX",
          v137,
          v138,
          v139,
          v140,
          v141,
          v142,
          v143,
          v144,
          "sap_get_freq_list");
    }
    *a3 = 0;
    *v148 = 0;
    _qdf_mem_free(v40);
  }
  result = 0;
LABEL_71:
  _ReadStatusReg(SP_EL0);
  return result;
}
