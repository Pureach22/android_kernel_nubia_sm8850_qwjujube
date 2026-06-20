__int64 __fastcall policy_mgr_get_channel_list(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int *a4,
        _BYTE *a5,
        unsigned int a6,
        unsigned int *a7)
{
  __int64 comp_private_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v23; // x2
  __int64 result; // x0
  __int64 v25; // x25
  __int64 v26; // x24
  unsigned int *v27; // x19
  __int64 v28; // x28
  __int64 v29; // x22
  __int64 v30; // x27
  __int64 v31; // x21
  __int64 v32; // x0
  unsigned int v33; // w20
  __int64 v34; // x26
  __int64 v35; // x22
  __int64 v36; // x28
  __int64 v37; // x21
  unsigned int valid_chans; // w0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int v47; // w8
  int v48; // w9
  unsigned int *v49; // x19
  __int64 v50; // x23
  int v51; // w20
  unsigned int v52; // w21
  unsigned int v53; // w26
  __int64 v54; // x9
  unsigned int v55; // w8
  bool is_24ghz_ch_freq; // w8
  unsigned int v57; // w0
  bool is_5ghz_ch_freq; // w8
  unsigned __int8 is_6ghz_conc_mode_supported; // w0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  int v68; // w12
  char v69; // w23
  _BYTE *v70; // x20
  __int64 v71; // x1
  __int64 v72; // x0
  __int64 v73; // x2
  unsigned int v74; // w23
  __int64 v75; // x7
  unsigned int *v76; // x21
  __int64 v77; // x7
  int v78; // w8
  __int64 v79; // x7
  __int64 v80; // x1
  __int64 v81; // x0
  __int64 v82; // x2
  __int64 v83; // x3
  __int64 v84; // x4
  unsigned int *v85; // x0
  _BYTE *v86; // x1
  __int64 v87; // x2
  unsigned int *v88; // x3
  __int64 v89; // x4
  __int64 v90; // x7
  __int64 v91; // x7
  __int64 v92; // x7
  char v93; // w25
  char v94; // w25
  __int64 v95; // x6
  __int64 v96; // x5
  __int64 v97; // x7
  unsigned int *v98; // x0
  _BYTE *v99; // x1
  __int64 v100; // x2
  unsigned int *v101; // x3
  __int64 v102; // x4
  __int64 v103; // x7
  __int64 v104; // x7
  __int64 v105; // x7
  __int64 v106; // x1
  __int64 v107; // x0
  __int64 v108; // x2
  __int64 v109; // x7
  char v110; // w25
  unsigned int *v111; // x25
  __int64 v112; // x7
  __int64 v113; // x1
  __int64 v114; // x0
  __int64 v115; // x2
  __int64 v116; // x3
  __int64 v117; // x7
  char v118; // w25
  __int64 v119; // x6
  __int64 v120; // x7
  unsigned int *v121; // x0
  _BYTE *v122; // x1
  __int64 v123; // x2
  unsigned int *v124; // x3
  __int64 v125; // x5
  unsigned int *v126; // x25
  char v127; // w26
  __int64 v128; // x0
  unsigned int *v129; // x1
  _BYTE *v130; // x2
  __int64 v131; // x3
  unsigned int *v132; // x4
  __int64 v133; // x5
  __int64 v134; // x0
  unsigned int *v135; // x1
  _BYTE *v136; // x2
  __int64 v137; // x3
  unsigned int *v138; // x4
  __int64 v139; // x5
  __int64 v140; // x7
  __int64 v141; // x7
  char v142; // w25
  __int64 v143; // x25
  __int64 v144; // x7
  char v145; // w26
  char v146; // w25
  __int64 v147; // x7
  unsigned int *v148; // x5
  __int64 v149; // x7
  _BYTE *v150; // x6
  __int64 v151; // x6
  __int64 v152; // x7
  __int64 v153; // x7
  char v154; // w25
  __int64 v155; // x6
  __int64 v156; // x5
  __int64 v157; // x7
  __int64 v158; // x7
  unsigned int *v159; // x0
  _BYTE *v160; // x1
  __int64 v161; // x2
  unsigned int *v162; // x3
  char v163; // w26
  __int64 v164; // x7
  __int64 v165; // x7
  __int64 v166; // x25
  __int64 v167; // x0
  double v168; // d0
  double v169; // d1
  double v170; // d2
  double v171; // d3
  double v172; // d4
  double v173; // d5
  double v174; // d6
  double v175; // d7
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  __int64 v184; // x7
  char v185; // [xsp+8h] [xbp-88h]
  char v186; // [xsp+8h] [xbp-88h]
  unsigned int *v187; // [xsp+28h] [xbp-68h]
  _BYTE *v188; // [xsp+30h] [xbp-60h]
  unsigned int v189; // [xsp+3Ch] [xbp-54h]
  unsigned int *v190; // [xsp+40h] [xbp-50h]
  char v191; // [xsp+40h] [xbp-50h]
  char v192; // [xsp+40h] [xbp-50h]
  char v193; // [xsp+40h] [xbp-50h]
  char v194; // [xsp+40h] [xbp-50h]
  char v195; // [xsp+40h] [xbp-50h]
  char v196; // [xsp+40h] [xbp-50h]
  char v197; // [xsp+40h] [xbp-50h]
  unsigned int v198; // [xsp+48h] [xbp-48h]
  unsigned int v199; // [xsp+4Ch] [xbp-44h]
  __int64 v200; // [xsp+50h] [xbp-40h]
  __int64 v201; // [xsp+58h] [xbp-38h]
  __int64 v202; // [xsp+60h] [xbp-30h]
  __int64 v203; // [xsp+68h] [xbp-28h]
  _BYTE v204[4]; // [xsp+70h] [xbp-20h] BYREF
  _BYTE v205[4]; // [xsp+74h] [xbp-1Ch] BYREF
  unsigned int v206; // [xsp+78h] [xbp-18h] BYREF
  unsigned int v207; // [xsp+7Ch] [xbp-14h] BYREF
  unsigned int v208; // [xsp+80h] [xbp-10h] BYREF
  unsigned int v209; // [xsp+84h] [xbp-Ch] BYREF
  __int64 v210; // [xsp+88h] [xbp-8h]

  v210 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v209 = 0;
  v205[0] = 0;
  v204[0] = 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
  {
    v23 = "%s: Invalid Context";
    goto LABEL_9;
  }
  if ( !a4 || !a7 )
  {
    v23 = "%s: pcl_channels or len is NULL";
    goto LABEL_9;
  }
  *a7 = 0;
  if ( !a2 )
  {
    qdf_trace_msg(0x4Fu, 8u, "%s: pcl is 0", v15, v16, v17, v18, v19, v20, v21, v22, "policy_mgr_get_channel_list");
    result = 0;
    goto LABEL_10;
  }
  if ( a2 != 52 )
  {
    v198 = a2;
    v25 = comp_private_obj;
    v199 = a3;
    v26 = a1;
    v190 = a7;
    v27 = a4;
    v28 = _qdf_mem_malloc(0x198u, "policy_mgr_get_channel_list", 3360);
    v29 = _qdf_mem_malloc(0x198u, "policy_mgr_get_channel_list", 3361);
    v30 = _qdf_mem_malloc(0x198u, "policy_mgr_get_channel_list", 3362);
    v31 = _qdf_mem_malloc(0x198u, "policy_mgr_get_channel_list", 3363);
    v203 = _qdf_mem_malloc(0x198u, "policy_mgr_get_channel_list", 3364);
    v201 = _qdf_mem_malloc(0x198u, "policy_mgr_get_channel_list", 3365);
    v32 = _qdf_mem_malloc(0x14u, "policy_mgr_get_channel_list", 3367);
    v200 = v32;
    if ( v28 )
    {
      v189 = a6;
      v33 = 2;
      v34 = v29;
      if ( v29 )
      {
        v35 = v28;
        v36 = v31;
        if ( v30 )
        {
          v37 = v201;
          if ( !v36 || !v203 || !v201 || !v32 )
            goto LABEL_121;
          valid_chans = policy_mgr_get_valid_chans(v26, v35, &v209);
          if ( valid_chans )
          {
            v33 = valid_chans;
            qdf_trace_msg(
              0x4Fu,
              2u,
              "%s: Error in getting valid channels",
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              "policy_mgr_get_channel_list");
LABEL_121:
            _qdf_mem_free(v35);
            _qdf_mem_free(v34);
            _qdf_mem_free(v30);
            _qdf_mem_free(v36);
            _qdf_mem_free(v203);
            _qdf_mem_free(v200);
            _qdf_mem_free(v37);
            result = v33;
            goto LABEL_10;
          }
          v47 = v209;
          v202 = v34;
          v187 = v27;
          v188 = a5;
          if ( v209 >= 0x66 )
            v48 = 102;
          else
            v48 = v209;
          v209 = v48;
          if ( v47 )
          {
            v49 = v190;
            v50 = 0;
            v51 = 0;
            v52 = 0;
            v53 = 0;
            while ( 1 )
            {
              is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v35 + 4 * v50));
              v57 = *(_DWORD *)(v35 + 4 * v50);
              if ( is_24ghz_ch_freq )
              {
                v54 = v202;
                v55 = v53++;
              }
              else
              {
                is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(v57);
                v57 = *(_DWORD *)(v35 + 4 * v50);
                if ( is_5ghz_ch_freq )
                {
                  v55 = v52;
                  v54 = v30;
                  ++v52;
                }
                else
                {
                  if ( !wlan_reg_is_6ghz_chan_freq(v57) )
                    goto LABEL_28;
                  v57 = *(_DWORD *)(v35 + 4 * v50);
                  v54 = v203;
                  v55 = v51++;
                }
              }
              *(_DWORD *)(v54 + 4LL * v55) = v57;
LABEL_28:
              if ( ++v50 >= (unsigned __int64)v209 )
                goto LABEL_35;
            }
          }
          v49 = v190;
          v53 = 0;
          v52 = 0;
          v51 = 0;
LABEL_35:
          is_6ghz_conc_mode_supported = policy_mgr_is_6ghz_conc_mode_supported(v26, v199);
          if ( (is_6ghz_conc_mode_supported & 1) != 0 )
            v68 = v51;
          else
            v68 = 0;
          v206 = 102;
          v207 = 5;
          v208 = 102;
          v69 = is_6ghz_conc_mode_supported ^ 1;
          v70 = v188;
          switch ( v198 )
          {
            case 1u:
              v76 = v187;
              v74 = v189;
              v86 = v188;
              v85 = v187;
              goto LABEL_95;
            case 2u:
              v129 = v187;
              v74 = v189;
              v133 = 0;
              v185 = v68;
              v128 = v26;
              v130 = v188;
              v131 = v189;
              v132 = v49;
              v151 = v30;
              v152 = v52;
              v76 = v187;
              goto LABEL_104;
            case 3u:
            case 4u:
            case 0x33u:
              v71 = v199;
              v72 = v26;
              v73 = 0;
              goto LABEL_107;
            case 5u:
              v143 = v200;
              get_sub_channels(v26, v36, &v208, v200, &v207, v201, &v206, v30, v52, v203, v68);
              v144 = v69 & 1;
              v76 = v187;
              v145 = v69;
              v74 = v189;
              add_chlist_to_pcl(v187, v188, v189, v49, 255, v36, v208, v144);
              v95 = v207;
              v97 = v145 & 1;
              v98 = v187;
              v99 = v188;
              v100 = v189;
              v101 = v49;
              v102 = 235;
              goto LABEL_112;
            case 6u:
            case 0x16u:
              v76 = v187;
              v74 = v189;
              policy_mgr_get_connection_channels(v26, v199, 0, 0, 0, v187, v188, v189, v49);
              v85 = v187;
              v86 = v188;
              v87 = v189;
              v88 = v49;
              v89 = 235;
              goto LABEL_96;
            case 7u:
            case 0x17u:
              v80 = v199;
              v81 = v26;
              v82 = 0;
              goto LABEL_77;
            case 8u:
            case 0x18u:
              v76 = v187;
              v74 = v189;
              policy_mgr_add_24g_to_pcl(v187, v188, v189, v49, 255, v202, v53);
              v71 = v199;
              v72 = v26;
              v73 = 0;
              v83 = 0;
              v84 = 1;
              goto LABEL_92;
            case 9u:
            case 0x19u:
              v74 = v189;
              v90 = v52;
              v76 = v187;
              policy_mgr_add_5g_to_pcl(v26, v187, v188, v189, v49, 0, v30, v90, v203, (_BYTE)v68);
              v71 = v199;
              v72 = v26;
              v73 = 0;
              v83 = 0;
              v84 = 2;
              goto LABEL_92;
            case 0xAu:
              v80 = v199;
              v81 = v26;
              v82 = 4;
LABEL_77:
              v126 = v187;
              v74 = v189;
              v127 = v68;
              policy_mgr_get_connection_channels(v81, v80, v82, 0, 0, v187, v188, v189, v49);
              v128 = v26;
              v129 = v187;
              v130 = v188;
              v131 = v189;
              v132 = v49;
              v133 = 1;
              v185 = v127;
              goto LABEL_103;
            case 0xBu:
              v106 = v199;
              v107 = v26;
              v108 = 2;
              goto LABEL_87;
            case 0xCu:
              v113 = v199;
              v114 = v26;
              v115 = 2;
              goto LABEL_102;
            case 0xDu:
              v111 = v187;
              v74 = v189;
              v195 = v68;
              policy_mgr_get_connection_channels(v26, v199, 2, 0, 0, v187, v188, v189, v49);
              v134 = v26;
              v135 = v187;
              v136 = v188;
              v137 = v189;
              v138 = v49;
              v139 = 2;
              v186 = v195;
              goto LABEL_81;
            case 0xEu:
              v111 = v187;
              v74 = v189;
              v194 = v68;
              policy_mgr_get_connection_channels(v26, v199, 4, 0, 0, v187, v188, v189, v49);
              v134 = v26;
              v135 = v187;
              v136 = v188;
              v137 = v189;
              v138 = v49;
              v186 = v194;
              v139 = 1;
LABEL_81:
              v140 = v52;
              v76 = v111;
              policy_mgr_add_5g_to_pcl(v134, v135, v136, v137, v138, v139, v30, v140, v203, v186);
              goto LABEL_82;
            case 0xFu:
              v74 = v189;
              v146 = v68;
              policy_mgr_get_connection_channels(v26, v199, 4, 0, 0, v187, v188, v189, v49);
              v147 = v52;
              v76 = v187;
              policy_mgr_add_5g_to_pcl(v26, v187, v188, v189, v49, 1, v30, v147, v203, v146);
              v71 = v199;
              v72 = v26;
              v73 = 3;
              v83 = 0;
              v84 = 2;
              v148 = v187;
              goto LABEL_93;
            case 0x10u:
              v111 = v187;
              v74 = v189;
              v192 = v68;
              policy_mgr_get_connection_channels(v26, v199, 4, 0, 0, v187, v188, v189, v49);
              v112 = v52;
              v76 = v187;
              policy_mgr_add_5g_to_pcl(v26, v187, v188, v189, v49, 1, v30, v112, v203, v192);
              policy_mgr_get_connection_channels(v26, v199, 3, 0, 2, v187, v188, v189, v49);
LABEL_82:
              v85 = v111;
              goto LABEL_89;
            case 0x11u:
              v106 = v199;
              v107 = v26;
              v108 = 1;
LABEL_87:
              v116 = 0;
              goto LABEL_88;
            case 0x12u:
              v113 = v199;
              v114 = v26;
              v115 = 1;
LABEL_102:
              v126 = v187;
              v74 = v189;
              v163 = v68;
              policy_mgr_get_connection_channels(v114, v113, v115, 0, 0, v187, v188, v189, v49);
              v185 = v163;
              v128 = v26;
              v129 = v187;
              v130 = v188;
              v131 = v189;
              v132 = v49;
              v133 = 2;
LABEL_103:
              v151 = v30;
              v152 = v52;
              v76 = v126;
LABEL_104:
              policy_mgr_add_5g_to_pcl(v128, v129, v130, v131, v132, v133, v151, v152, v203, v185);
              break;
            case 0x13u:
              v106 = v199;
              v107 = v26;
              v108 = 3;
              v116 = 1;
LABEL_88:
              v76 = v187;
              v74 = v189;
              policy_mgr_get_connection_channels(v107, v106, v108, v116, 0, v187, v188, v189, v49);
              v85 = v187;
LABEL_89:
              v86 = v188;
              v87 = v74;
              v88 = v49;
              v89 = 215;
              goto LABEL_96;
            case 0x14u:
              v71 = v199;
              v72 = v26;
              v73 = 2;
              goto LABEL_107;
            case 0x15u:
              v71 = v199;
              v72 = v26;
              v73 = 1;
LABEL_107:
              v83 = 0;
              goto LABEL_108;
            case 0x1Au:
              get_sub_channels(v26, v36, &v208, v200, &v207, v201, &v206, v30, v52, v203, v68);
              v109 = v69 & 1;
              v76 = v187;
              v110 = v69;
              v74 = v189;
              add_chlist_to_pcl(v187, v188, v189, v49, 255, v36, v208, v109);
              add_chlist_to_pcl(v187, v188, v189, v49, 235, v200, v207, v110 & 1);
              v95 = v206;
              v97 = v110 & 1;
              v98 = v187;
              v99 = v188;
              v100 = v189;
              v101 = v49;
              v102 = 215;
              goto LABEL_71;
            case 0x1Bu:
              get_sub_channels(v26, v36, &v208, v200, &v207, v201, &v206, v30, v52, v203, v68);
              v76 = v187;
              v193 = v69;
              v74 = v189;
              add_chlist_to_pcl(v187, v188, v189, v49, 255, v202, v53, 0);
              add_chlist_to_pcl(v187, v188, v189, v49, 235, v200, v207, v193 & 1);
              v95 = v208;
              v97 = v193 & 1;
              v98 = v187;
              v99 = v188;
              v100 = v189;
              v101 = v49;
              v102 = 215;
              v96 = v36;
              goto LABEL_118;
            case 0x1Cu:
              get_sub_channels(v26, v36, &v208, v200, &v207, v201, &v206, v30, v52, v203, v68);
              v76 = v187;
              v191 = v69;
              v74 = v189;
              add_chlist_to_pcl(v187, v188, v189, v49, 255, v202, v53, 0);
              add_chlist_to_pcl(v187, v188, v189, v49, 235, v200, v207, v191 & 1);
              add_chlist_to_pcl(v187, v188, v189, v49, 215, v36, v208, v191 & 1);
              v95 = v206;
              v97 = v191 & 1;
              v98 = v187;
              v99 = v188;
              v100 = v189;
              v101 = v49;
              v102 = 195;
LABEL_71:
              v96 = v201;
              goto LABEL_118;
            case 0x1Du:
              get_sub_channels(v26, v36, &v208, v200, &v207, v201, &v206, v30, v52, v203, v68);
              v76 = v187;
              v94 = v69;
              v74 = v189;
              add_chlist_to_pcl(v187, v188, v189, v49, 255, v202, v53, 0);
              add_chlist_to_pcl(v187, v188, v189, v49, 235, v36, v208, v94 & 1);
              v95 = v207;
              v96 = v200;
              v97 = v94 & 1;
              v98 = v187;
              v99 = v188;
              v100 = v189;
              v101 = v49;
              v102 = 215;
              goto LABEL_118;
            case 0x1Eu:
              v143 = v200;
              get_sub_channels(v26, v36, &v208, v200, &v207, v201, &v206, v30, v52, v203, v68);
              v164 = v69 & 1;
              v76 = v187;
              v196 = v69;
              v74 = v189;
              add_chlist_to_pcl(v187, v188, v189, v49, 255, v36, v208, v164);
              add_chlist_to_pcl(v187, v188, v189, v49, 235, v202, v53, 0);
              v95 = v207;
              v98 = v187;
              v99 = v188;
              v100 = v189;
              v101 = v49;
              v97 = v196 & 1;
              v102 = 215;
LABEL_112:
              v96 = v143;
              goto LABEL_118;
            case 0x1Fu:
              get_sub_channels(v26, v36, &v208, v200, &v207, v201, &v206, v30, v52, v203, v68);
              v157 = v69 & 1;
              v76 = v187;
              v154 = v69;
              v74 = v189;
              add_chlist_to_pcl(v187, v188, v189, v49, 255, v36, v208, v157);
              v155 = v207;
              v156 = v200;
              goto LABEL_100;
            case 0x20u:
              get_sub_channels(v26, v36, &v208, v200, &v207, v201, &v206, v30, v52, v203, v68);
              v165 = v69 & 1;
              v76 = v187;
              v197 = v69;
              v74 = v189;
              add_chlist_to_pcl(v187, v188, v189, v49, 255, v200, v207, v165);
              v155 = v208;
              v159 = v187;
              v160 = v188;
              v161 = v189;
              v162 = v49;
              v158 = v197 & 1;
              v156 = v36;
              goto LABEL_114;
            case 0x21u:
              get_sub_channels(v26, v36, &v208, v200, &v207, v201, &v206, v30, v52, v203, v68);
              v141 = v69 & 1;
              v76 = v187;
              v142 = v69;
              v74 = v189;
              add_chlist_to_pcl(v187, v188, v189, v49, 255, v36, v208, v141);
              add_chlist_to_pcl(v187, v188, v189, v49, 235, v200, v207, v142 & 1);
              v119 = v206;
              v125 = v201;
              v120 = v142 & 1;
              v121 = v187;
              v122 = v188;
              v123 = v189;
              v124 = v49;
              goto LABEL_84;
            case 0x22u:
              get_sub_channels(v26, v36, &v208, v200, &v207, v201, &v206, v30, v52, v203, v68);
              v117 = v69 & 1;
              v76 = v187;
              v118 = v69;
              v74 = v189;
              add_chlist_to_pcl(v187, v188, v189, v49, 255, v200, v207, v117);
              add_chlist_to_pcl(v187, v188, v189, v49, 235, v201, v206, v118 & 1);
              v119 = v208;
              v120 = v118 & 1;
              v121 = v187;
              v122 = v188;
              v123 = v189;
              v124 = v49;
              v125 = v36;
LABEL_84:
              add_chlist_to_pcl(v121, v122, v123, v124, 215, v125, v119, v120);
              v98 = v76;
              v99 = v188;
              v100 = v74;
              v101 = v49;
              v102 = 195;
              goto LABEL_116;
            case 0x23u:
              get_sub_channels(v26, v36, &v208, v200, &v207, v201, &v206, v30, v52, v203, v68);
              v103 = v69 & 1;
              v76 = v187;
              v74 = v189;
              add_chlist_to_pcl(v187, v188, v189, v49, 255, v36, v208, v103);
              goto LABEL_62;
            case 0x24u:
              v74 = v189;
              v104 = v52;
              v76 = v187;
              add_sbs_chlist_to_pcl(
                v26,
                v187,
                v188,
                v189,
                v49,
                (is_6ghz_conc_mode_supported ^ 1) & 1,
                v30,
                v104,
                v203,
                (_BYTE)v68,
                5,
                v205,
                v204);
              if ( (policy_mgr_2ghz_connection_present(v25) & 1) != 0 && (v204[0] & 1) != 0
                || (policy_mgr_sbs_24_shared_with_low_5(v25) & 1) == 0 )
              {
                break;
              }
              goto LABEL_115;
            case 0x25u:
            case 0x26u:
              v74 = v189;
              if ( v198 == 37 )
                v78 = 6;
              else
                v78 = 7;
              v79 = v52;
              v76 = v187;
              add_sbs_chlist_to_pcl(
                v26,
                v187,
                v188,
                v189,
                v49,
                (is_6ghz_conc_mode_supported ^ 1) & 1,
                v30,
                v79,
                v203,
                (_BYTE)v68,
                v78,
                v205,
                v204);
              if ( (policy_mgr_2ghz_connection_present(v25) & 1) != 0 && (v205[0] & 1) != 0
                || (policy_mgr_sbs_24_shared_with_high_5(v25) & 1) == 0 )
              {
                break;
              }
              goto LABEL_115;
            case 0x27u:
              get_sub_channels(v26, v36, &v208, v200, &v207, v201, &v206, v30, v52, v203, v68);
              v184 = v69 & 1;
              v76 = v187;
              v74 = v189;
              add_chlist_to_pcl(v187, v188, v189, v49, 255, v36, v208, v184);
              v95 = v206;
              v98 = v187;
              v99 = v188;
              v100 = v189;
              v101 = v49;
              v102 = 235;
              v96 = v201;
              goto LABEL_117;
            case 0x28u:
              get_sub_channels(v26, v36, &v208, v200, &v207, v201, &v206, v30, v52, v203, v68);
              v153 = v69 & 1;
              v76 = v187;
              v154 = v69;
              v74 = v189;
              add_chlist_to_pcl(v187, v188, v189, v49, 255, v36, v208, v153);
              v155 = v206;
              v156 = v201;
LABEL_100:
              v158 = v154 & 1;
              v159 = v76;
              v160 = v188;
              v161 = v74;
              v162 = v49;
LABEL_114:
              add_chlist_to_pcl(v159, v160, v161, v162, 235, v156, v155, v158);
LABEL_115:
              v98 = v76;
              v99 = v188;
              v100 = v74;
              v101 = v49;
              v102 = 215;
              goto LABEL_116;
            case 0x29u:
              v71 = v199;
              v72 = v26;
              v73 = 3;
              v83 = 1;
LABEL_108:
              v76 = v187;
              v74 = v189;
              v84 = 0;
              v150 = v188;
              v148 = v187;
              goto LABEL_109;
            case 0x2Au:
            case 0x31u:
              v74 = v189;
              v91 = v52;
              v76 = v187;
              add_sbs_chlist_to_pcl(
                v26,
                v187,
                v188,
                v189,
                v49,
                (is_6ghz_conc_mode_supported ^ 1) & 1,
                v30,
                v91,
                v203,
                (_BYTE)v68,
                8,
                v205,
                v204);
              if ( v198 != 49 )
                break;
              goto LABEL_62;
            case 0x2Bu:
            case 0x32u:
              v74 = v189;
              v77 = v52;
              v76 = v187;
              add_sbs_chlist_to_pcl(
                v26,
                v187,
                v188,
                v189,
                v49,
                (is_6ghz_conc_mode_supported ^ 1) & 1,
                v30,
                v77,
                v203,
                (_BYTE)v68,
                9,
                v205,
                v204);
              if ( v198 != 50 )
                break;
LABEL_62:
              v98 = v76;
              v99 = v188;
              v100 = v74;
              v101 = v49;
              v102 = 235;
LABEL_116:
              v96 = v202;
              v95 = v53;
LABEL_117:
              v97 = 0;
LABEL_118:
              add_chlist_to_pcl(v98, v99, v100, v101, v102, v96, v95, v97);
              break;
            case 0x2Cu:
              get_sub_channels(v26, v36, &v208, v200, &v207, v201, &v206, v30, v52, v203, v68);
              v92 = v69 & 1;
              v76 = v187;
              v93 = v69;
              v74 = v189;
              add_chlist_to_pcl(v187, v188, v189, v49, 255, v36, v208, v92);
              add_chlist_to_pcl(v187, v188, v189, v49, 235, v201, v206, v93 & 1);
              policy_mgr_get_connection_channels(v26, v199, 3, 1, 0, v187, v188, v189, v49);
              goto LABEL_68;
            case 0x2Du:
              v74 = v189;
              v105 = v52;
              v76 = v187;
              policy_mgr_add_5g_to_pcl(v26, v187, v188, v189, v49, 0, v30, v105, v203, (_BYTE)v68);
LABEL_68:
              v85 = v76;
              v86 = v188;
LABEL_95:
              v87 = v74;
              v88 = v49;
              v89 = 255;
LABEL_96:
              policy_mgr_add_24g_to_pcl(v85, v86, v87, v88, v89, v202, v53);
              break;
            case 0x2Eu:
              get_sub_channels(v26, v36, &v208, v200, &v207, v201, &v206, v30, v52, v203, v68);
              v149 = v69 & 1;
              v76 = v187;
              v74 = v189;
              add_chlist_to_pcl(v187, v188, v189, v49, 235, v201, v206, v149);
              v71 = v199;
              v72 = v26;
              v73 = 3;
              v83 = 1;
              v84 = 0;
LABEL_92:
              v148 = v76;
LABEL_93:
              v150 = v188;
LABEL_109:
              policy_mgr_get_connection_channels(v72, v71, v73, v83, v84, v148, v150, v74, v49);
              break;
            case 0x2Fu:
            case 0x30u:
              v74 = v189;
              v75 = v52;
              v76 = v187;
              add_sbs_chlist_to_pcl(
                v26,
                v187,
                v188,
                v189,
                v49,
                (is_6ghz_conc_mode_supported ^ 1) & 1,
                v30,
                v75,
                v203,
                (_BYTE)v68,
                10,
                v205,
                v204);
              break;
            default:
              qdf_trace_msg(
                0x4Fu,
                2u,
                "%s: unknown pcl value %d",
                v60,
                v61,
                v62,
                v63,
                v64,
                v65,
                v66,
                v67,
                "policy_mgr_get_channel_list",
                v198);
              v76 = v187;
              v70 = v188;
              v74 = v189;
              break;
          }
          v166 = pcl_type_to_string(v198);
          v167 = device_mode_to_string(v199);
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: pcl %s: mode %s",
            v168,
            v169,
            v170,
            v171,
            v172,
            v173,
            v174,
            v175,
            "policy_mgr_get_channel_list",
            v166,
            v167);
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: pcl len %d and weight list sz %d",
            v176,
            v177,
            v178,
            v179,
            v180,
            v181,
            v182,
            v183,
            "policy_mgr_get_channel_list",
            *v49,
            v74);
          policy_mgr_set_weight_of_disabled_inactive_channels_to_zero(v26, v76, (__int64)v49, v70);
          v34 = v202;
          v33 = 0;
        }
LABEL_120:
        v37 = v201;
        goto LABEL_121;
      }
    }
    else
    {
      v33 = 2;
      v34 = v29;
    }
    v35 = v28;
    v36 = v31;
    goto LABEL_120;
  }
  v23 = "%s: pcl is invalid";
LABEL_9:
  qdf_trace_msg(0x4Fu, 2u, v23, v15, v16, v17, v18, v19, v20, v21, v22, "policy_mgr_get_channel_list");
  result = 16;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
