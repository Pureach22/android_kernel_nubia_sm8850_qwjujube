void __fastcall reg_compute_pdev_current_chan_list(
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
  __int64 v9; // x28
  __int64 v10; // x11
  unsigned int v11; // w8
  const char *v12; // x2
  const char *v13; // x3
  __int64 v14; // x21
  __int64 v15; // x20
  __int64 v16; // x24
  __int64 v17; // x20
  __int64 v18; // x22
  __int64 v19; // x25
  unsigned int v20; // w8
  __int64 v21; // x20
  __int64 v22; // x22
  __int64 v23; // x25
  unsigned int v24; // w8
  __int64 v25; // x21
  __int64 v26; // x20
  __int64 v27; // x24
  const char *v28; // x2
  const char *v29; // x3
  unsigned int v30; // w8
  __int64 v31; // x20
  __int64 v32; // x22
  __int64 v33; // x25
  __int64 v34; // x2
  __int64 v35; // x22
  __int64 v36; // x19
  __int64 v37; // x21
  __int64 v38; // x23
  __int64 v39; // x24
  __int64 v40; // x25
  int *v41; // x20
  __int64 v42; // x26
  __int64 v43; // x27
  const void *v44; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int16 v53; // w9
  _DWORD *v54; // x10
  __int64 v55; // x0
  int v56; // w9
  __int16 v57; // w8
  _WORD *v58; // x9
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x9
  _DWORD *v68; // x28
  char is_chan_disabled; // w0
  int *v70; // x28
  char v71; // w0
  int v72; // w8
  __int64 v73; // x0
  int v74; // w8
  _DWORD *v75; // x9
  __int64 pdev_obj; // x25
  _WORD *v77; // x0
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  _WORD *v86; // x28
  __int64 v87; // x0
  __int64 chan_enum_for_freq; // x0
  unsigned int v89; // w25
  const char *v90; // x25
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  int *v99; // x8
  int v100; // w9
  int *v101; // x8
  int v102; // w9
  unsigned __int8 v103; // w25
  int v104; // w27
  unsigned int v105; // w9
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  __int64 v114; // x4
  __int64 i; // x8
  __int64 v116; // x10
  unsigned int v117; // w12
  unsigned int v118; // w13
  unsigned int v119; // w9
  unsigned int v120; // w11
  __int64 v121; // x8
  unsigned __int16 *v122; // x10
  unsigned int v123; // w14
  int v124; // w15
  unsigned int v125; // w16
  unsigned __int16 v126; // w13
  __int64 v127; // x10
  unsigned __int16 *v128; // x13
  unsigned int v129; // w14
  int v130; // w15
  unsigned int v131; // w16
  unsigned __int16 v132; // w11
  unsigned int v133; // w14
  int v134; // w15
  int *v135; // x13
  __int64 v136; // x11
  unsigned int v137; // w16
  int *v138; // x17
  unsigned int v139; // w0
  int v140; // w1
  unsigned int v141; // w2
  unsigned __int16 v142; // w12
  __int64 v143; // x12
  unsigned int v144; // w16
  unsigned __int16 v145; // w9
  unsigned __int64 v146; // x9
  int *v147; // x14
  int v148; // w16
  bool v149; // w16
  int v152; // w19
  __int64 v153; // x8
  _DWORD *v154; // x9
  int v155; // w10
  int v156; // w11
  int v157; // w8
  int v158; // w9
  int v159; // w10
  int v160; // w8
  int v161; // w9
  int v162; // w8
  int v163; // w9
  int v164; // w8
  int v165; // w9
  int v166; // w8
  int v167; // w9
  int v168; // w10
  int v169; // w8
  __int64 v170; // x8
  __int64 v171; // x9
  int v172; // w10
  __int64 j; // x8
  __int64 v174; // x9
  int v175; // w10
  __int64 v176; // [xsp+8h] [xbp-98h]
  __int64 v177; // [xsp+10h] [xbp-90h]
  __int64 v178; // [xsp+18h] [xbp-88h]
  __int64 v179; // [xsp+20h] [xbp-80h]
  __int64 v180; // [xsp+28h] [xbp-78h]
  __int64 v181; // [xsp+30h] [xbp-70h]
  unsigned int v182; // [xsp+40h] [xbp-60h]
  unsigned int v183; // [xsp+48h] [xbp-58h]
  __int64 v184; // [xsp+50h] [xbp-50h]
  __int64 v185; // [xsp+58h] [xbp-48h]
  __int64 v186; // [xsp+60h] [xbp-40h]
  __int64 v187; // [xsp+68h] [xbp-38h]
  __int64 v188; // [xsp+70h] [xbp-30h] BYREF
  __int64 v189; // [xsp+78h] [xbp-28h]
  __int64 v190; // [xsp+80h] [xbp-20h]
  __int64 v191; // [xsp+88h] [xbp-18h]
  int v192; // [xsp+90h] [xbp-10h]
  int v193; // [xsp+94h] [xbp-Ch] BYREF
  __int64 v194; // [xsp+98h] [xbp-8h]

  v9 = a1;
  v10 = a1 + 56692;
  v194 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v187 = a1 + 56692;
  if ( *(_BYTE *)(a1 + 11016) != 1 )
    goto LABEL_50;
  v11 = *(_DWORD *)(a1 + 58208);
  if ( v11 >= 2 )
  {
    v12 = "%s: invalid 6G AP or client power type";
    v13 = "reg_append_mas_chan_list_for_6g";
LABEL_49:
    qdf_trace_msg(0x51u, 8u, v12, a2, a3, a4, a5, a6, a7, a8, a9, v13);
    v10 = v187;
LABEL_50:
    v184 = v9;
    if ( *(_BYTE *)(v9 + 11016) == 1 )
    {
      v34 = 0;
      v35 = 37004;
      v36 = 36950;
      v37 = 37064;
      v38 = 37062;
      v39 = 37060;
      v176 = v9 + 36940;
      do
      {
        v40 = 0;
        v41 = (int *)&unk_AD22C0;
        v182 = 0;
        v177 = v39;
        v178 = v38;
        v179 = v37;
        v180 = v36;
        v186 = v176 + 268 * v34;
        v181 = v35;
        v185 = v34;
        do
        {
          v42 = v40 + 1;
          v43 = *(_QWORD *)(v10 + 36);
          v192 = 0;
          v190 = 0;
          v191 = 0;
          v188 = 0;
          v189 = 0;
          v44 = (const void *)((__int64 (__fastcall *)(_QWORD, __int64))reg_get_reg_maschan_lst_frm_6g_pwr_mode)(
                                (unsigned int)(v40 + 1),
                                v9);
          if ( v40 == 1 || !v44 )
          {
LABEL_54:
            v10 = v187;
            goto LABEL_55;
          }
          qdf_mem_copy(&v188, v44, 0x24u);
          if ( (unsigned int)v188 < *(_DWORD *)(v187 + 52) || (unsigned int)v188 > *(_DWORD *)(v187 + 56) )
          {
            LODWORD(v189) = 0;
            HIDWORD(v189) |= 1u;
          }
          if ( v186 )
          {
            v53 = WORD2(v191);
            v54 = (_DWORD *)(v9 + v35);
            *(_BYTE *)(v9 + v39) = BYTE3(v191);
            v55 = (unsigned int)v189;
            *(_WORD *)(v9 + v38) = v53;
            v56 = HIDWORD(v189);
            *(_DWORD *)(v9 + v37) = v190;
            v57 = WORD2(v190);
            *v54 = v56;
            v58 = (_WORD *)(v9 + v36);
            v54[39] = v55;
            LOWORD(v54) = HIWORD(v190);
            *v58 = v57;
            v58[13] = (_WORD)v54;
            if ( (reg_is_state_allowed(v55) & 1) != 0 )
              goto LABEL_66;
          }
          else
          {
            qdf_trace_msg(
              0x51u,
              8u,
              "%s: chan_info is NULL",
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              "copy_enh_chan_info_from_reg_chan");
            if ( (reg_is_state_allowed((unsigned int)v189) & 1) != 0 )
              goto LABEL_66;
          }
          if ( (v189 & 0x100000000LL) != 0 && (v191 & 0x100) == 0 && (v191 & 0x10000) == 0 )
            goto LABEL_54;
LABEL_66:
          v67 = v187;
          if ( (unsigned int)v42 <= 0xC && ((1 << v42) & 0x1890) != 0 )
          {
            if ( (*(_BYTE *)(v187 + 68) & 1) == 0 )
            {
              v68 = (_DWORD *)(v184 + v35);
              is_chan_disabled = reg_is_chan_disabled(
                                   *(unsigned int *)(v184 + v35),
                                   *(unsigned int *)(v184 + v35 + 156));
              v67 = v187;
              if ( (is_chan_disabled & 1) == 0 )
              {
                *v68 |= 2u;
                v68[39] = 2;
              }
            }
            if ( *(_BYTE *)(v67 + 764) == 1 && *(_BYTE *)(v67 + 765) == 1 )
            {
              v70 = (int *)(v184 + v35);
              v71 = reg_is_chan_disabled(*(unsigned int *)(v184 + v35), *(unsigned int *)(v184 + v35 + 156));
              v67 = v187;
              if ( (v71 & 1) == 0 )
              {
                v72 = *v70;
                v70[39] = 0;
                *v70 = v72 | 2;
              }
            }
          }
          v73 = *(_QWORD *)(v67 + 36);
          v9 = v184;
          if ( v73 )
          {
            if ( (reg_is_indoor_ap_detected(v73) & 1) != 0 )
            {
              if ( v40 == 9 )
              {
                v74 = *(_DWORD *)(v186 + 228);
                *(_DWORD *)(v186 + 100) |= *(_DWORD *)(v186 + 72);
                v75 = (_DWORD *)(v186 + 256);
LABEL_81:
                *v75 |= v74;
              }
            }
            else if ( (unsigned int)(v40 - 9) <= 2 )
            {
              v75 = (_DWORD *)(v184 + v35);
              v74 = 1;
              goto LABEL_81;
            }
          }
          if ( v186 && v43 )
          {
            pdev_obj = reg_get_pdev_obj(v43);
            v77 = (_WORD *)_qdf_mem_malloc(4u, "reg_dis_6g_chan_in_super_chan_list", 696);
            if ( v77 )
            {
              v86 = v77;
              qdf_mem_set(v77, 4u, 0);
              if ( (reg_get_keep_6ghz_sta_cli_connection(v43) & 1) != 0 )
                reg_get_active_6ghz_freq_range_with_fcc_set(pdev_obj, v86);
              if ( *v86 && v86[1] )
              {
                v87 = ((__int64 (*)(void))reg_get_chan_enum_for_freq)();
                v183 = (unsigned __int16)reg_convert_enum_to_6g_idx(v87);
                chan_enum_for_freq = reg_get_chan_enum_for_freq((unsigned __int16)v86[1]);
                v89 = (unsigned __int16)reg_convert_enum_to_6g_idx(chan_enum_for_freq);
              }
              else
              {
                v89 = 102;
                v183 = 102;
              }
              _qdf_mem_free((__int64)v86);
              if ( (reg_is_6ghz_band_set(v43) & 1) == 0
                && (v183 > 0x65 || v89 > 0x65 || v183 > (unsigned int)v185 || v89 < (unsigned int)v185) )
              {
                v99 = (int *)(v184 + v35);
                v100 = *(_DWORD *)(v184 + v35);
                v99[39] = 0;
                *v99 = v100 | 1;
              }
            }
            if ( *(_QWORD *)(v43 + 80) )
            {
              if ( (_BYTE)v185 )
              {
                v9 = v184;
                if ( (unsigned __int8)v185 == 59 && (reg_is_upper_6g_edge_ch_disabled() & 1) != 0 )
                {
LABEL_111:
                  v101 = (int *)(v9 + v35);
                  v102 = *(_DWORD *)(v9 + v35);
                  v101[39] = 0;
                  *v101 = v102 | 1;
                }
              }
              else
              {
                v9 = v184;
                if ( (reg_is_lower_6g_edge_ch_supp() & 1) == 0 )
                  goto LABEL_111;
              }
            }
            else
            {
              qdf_trace_msg(
                0x51u,
                8u,
                "%s: psoc is NULL",
                v78,
                v79,
                v80,
                v81,
                v82,
                v83,
                v84,
                v85,
                "reg_dis_6g_edge_chan_in_enh_chan");
              v9 = v184;
            }
          }
          else
          {
            if ( v43 )
              v90 = "%s: chan_info is NULL";
            else
              v90 = "%s: pdev is NULL";
            qdf_trace_msg(0x51u, 8u, v90, v59, v60, v61, v62, v63, v64, v65, v66, "reg_dis_6g_chan_in_super_chan_list");
            qdf_trace_msg(0x51u, 8u, v90, v91, v92, v93, v94, v95, v96, v97, v98, "reg_dis_6g_edge_chan_in_enh_chan");
          }
          v103 = v190;
          v104 = *v41;
          v193 = 0;
          reg_get_cur_6g_client_type(*(_QWORD *)(v187 + 36), &v193);
          if ( v104 != v193
            || (*(_WORD *)(v9 + v35) & 0x4001) != 0
            || (reg_is_state_allowed(*(unsigned int *)(v9 + v35 + 156)) & 1) == 0 )
          {
            v10 = v187;
            goto LABEL_126;
          }
          v10 = v187;
          if ( !v182 || v182 < v103 && (*(_BYTE *)(v187 + 68) & 1) != 0 )
          {
LABEL_124:
            v182 = v103;
            *(_DWORD *)(v186 + 4) = v42;
            goto LABEL_126;
          }
          v105 = *(_DWORD *)(v186 + 4);
          if ( v105 > 0xC || ((1 << v105) & 0x1890) == 0 )
            goto LABEL_128;
          if ( (unsigned int)v42 > 0xC || ((1 << v42) & 0x1890) == 0 )
            goto LABEL_124;
          if ( ((1 << v105) & 0x1890) == 0 )
          {
LABEL_128:
            if ( (unsigned int)v42 <= 0xC && ((1 << v42) & 0x1890) != 0 )
              goto LABEL_126;
          }
          if ( v182 < v103 )
            goto LABEL_124;
LABEL_126:
          *(_WORD *)v186 |= 1 << v42;
LABEL_55:
          v35 += 4;
          v41 += 3;
          v36 += 2;
          v37 += 8;
          v38 += 8;
          v39 += 8;
          v40 = v42;
        }
        while ( v42 != 12 );
        v34 = v185 + 1;
        v35 = v181 + 268;
        v36 = v180 + 268;
        v37 = v179 + 268;
        v38 = v178 + 268;
        v39 = v177 + 268;
      }
      while ( v185 != 59 );
    }
    qdf_mem_copy((void *)v9, (const void *)(v9 + 7344), 0xE58u);
    v114 = v187;
    for ( i = 0; i != 2160; i += 36 )
    {
      v116 = v9 + i;
      if ( *(_DWORD *)(v9 + i + 1544) == 1 && *(_DWORD *)(v116 + 1520) )
      {
        *(_DWORD *)(v116 + 1520) = 2;
        *(_DWORD *)(v9 + i + 1524) |= 2u;
      }
    }
    v118 = *(_DWORD *)(v187 + 44);
    v117 = *(_DWORD *)(v187 + 48);
    v120 = *(_DWORD *)(v187 + 52);
    v119 = *(_DWORD *)(v187 + 56);
    v121 = 0;
    v122 = (unsigned __int16 *)(v9 + 22);
    while ( 1 )
    {
      v123 = *(v122 - 1);
      v124 = *(_DWORD *)(v122 - 11);
      if ( v124 - (v123 >> 1) >= v118 )
        break;
      ++v121;
      v122 += 18;
      if ( v121 == 102 )
        goto LABEL_145;
    }
    v125 = *v122;
    if ( v124 - (v125 >> 1) < v118 )
    {
      v126 = 2 * (v124 - v118);
      if ( v125 >= 0x15 )
        v126 = *v122;
      if ( v126 <= v123 )
        v126 = *(v122 - 1);
      *v122 = v126;
    }
LABEL_145:
    v127 = 0;
    v128 = (unsigned __int16 *)(v9 + 22);
    while ( 1 )
    {
      v129 = *(v128 - 1);
      v130 = *(_DWORD *)(v128 - 11);
      if ( v130 - (v129 >> 1) >= v120 )
        break;
      ++v127;
      v128 += 18;
      if ( v127 == 102 )
        goto LABEL_155;
    }
    v131 = *v128;
    if ( v130 - (v131 >> 1) < v120 )
    {
      v132 = 2 * (v130 - v120);
      if ( v131 >= 0x15 )
        v132 = *v128;
      if ( v132 <= v129 )
        v132 = *(v128 - 1);
      *v128 = v132;
    }
LABEL_155:
    v133 = *(unsigned __int16 *)(v9 + 3656);
    v134 = *(_DWORD *)(v9 + 3636);
    v135 = (int *)(v9 + 3636);
    v136 = 101;
    v137 = v134 + (v133 >> 1);
    if ( v137 <= v117 )
    {
      v138 = (int *)(v9 + 3636);
      v139 = *(unsigned __int16 *)(v9 + 3656);
      v140 = *(_DWORD *)(v9 + 3636);
LABEL_160:
      v141 = *((unsigned __int16 *)v138 + 11);
      if ( v140 + (v141 >> 1) > v117 )
      {
        v142 = 2 * (v117 - v140);
        if ( v141 >= 0x15 )
          v142 = *((_WORD *)v138 + 11);
        if ( v142 <= v139 )
          v142 = v139;
        *((_WORD *)v138 + 11) = v142;
        v133 = *(unsigned __int16 *)(v9 + 3656);
        v134 = *(_DWORD *)(v9 + 3636);
        v137 = v134 + (v133 >> 1);
      }
    }
    else
    {
      while ( v136 )
      {
        v138 = (int *)(v9 + 36LL * (unsigned int)--v136);
        v139 = *((unsigned __int16 *)v138 + 10);
        v140 = *v138;
        if ( *v138 + (v139 >> 1) <= v117 )
          goto LABEL_160;
      }
      LODWORD(v136) = 102;
    }
    v143 = 101;
    if ( v137 <= v119 )
    {
LABEL_170:
      v144 = *((unsigned __int16 *)v135 + 11);
      if ( v134 + (v144 >> 1) > v119 )
      {
        v145 = 2 * (v119 - v134);
        if ( v144 >= 0x15 )
          v145 = *((_WORD *)v135 + 11);
        if ( v145 <= v133 )
          v145 = v133;
        *((_WORD *)v135 + 11) = v145;
      }
    }
    else
    {
      while ( v143 )
      {
        v135 = (int *)(v9 + 36LL * (unsigned int)--v143);
        v133 = *((unsigned __int16 *)v135 + 10);
        v134 = *v135;
        if ( *v135 + (v133 >> 1) <= v119 )
          goto LABEL_170;
      }
      LODWORD(v143) = 102;
    }
    v146 = 0;
    v147 = (int *)(v9 + 12);
    while ( (unsigned int)v121 > v146 )
    {
      if ( (unsigned int)v127 <= v146 )
      {
        v149 = 0;
LABEL_190:
        if ( v146 <= (unsigned int)v143 && (_DWORD)v143 != 102 )
          goto LABEL_179;
LABEL_195:
        if ( v149 )
          goto LABEL_179;
      }
      v148 = *v147 | 1;
      *(v147 - 1) = 0;
      *v147 = v148;
LABEL_179:
      ++v146;
      v147 += 9;
      if ( v146 == 102 )
      {
        v152 = *(_DWORD *)(v187 + 64);
        if ( v152 )
        {
          if ( (v152 & 2) == 0 )
          {
            qdf_trace_msg(
              0x51u,
              8u,
              "%s: disabling 5G",
              v106,
              v107,
              v108,
              v109,
              v110,
              v111,
              v112,
              v113,
              "reg_modify_chan_list_for_band");
            v114 = v187;
            v153 = 0;
            do
            {
              v154 = (_DWORD *)(v9 + v153);
              v153 += 72;
              v155 = v154[129];
              v156 = v154[138];
              v154[128] = 0;
              v154[137] = 0;
              v154[129] = v155 | 1;
              v154[138] = v156 | 1;
            }
            while ( v153 != 1008 );
          }
          if ( (v152 & 1) == 0 )
          {
            qdf_trace_msg(
              0x51u,
              8u,
              "%s: disabling 2G",
              v106,
              v107,
              v108,
              v109,
              v110,
              v111,
              v112,
              v113,
              "reg_modify_chan_list_for_band");
            v157 = *(_DWORD *)(v9 + 12);
            v158 = *(_DWORD *)(v9 + 48);
            v159 = *(_DWORD *)(v9 + 300);
            v114 = v187;
            *(_DWORD *)(v9 + 260) = 0;
            *(_DWORD *)(v9 + 296) = 0;
            *(_DWORD *)(v9 + 8) = 0;
            *(_DWORD *)(v9 + 12) = v157 | 1;
            v160 = *(_DWORD *)(v9 + 84);
            *(_DWORD *)(v9 + 44) = 0;
            *(_DWORD *)(v9 + 48) = v158 | 1;
            v161 = *(_DWORD *)(v9 + 120);
            *(_DWORD *)(v9 + 332) = 0;
            *(_DWORD *)(v9 + 80) = 0;
            *(_DWORD *)(v9 + 84) = v160 | 1;
            v162 = v161 | 1;
            v163 = *(_DWORD *)(v9 + 156);
            *(_DWORD *)(v9 + 116) = 0;
            *(_DWORD *)(v9 + 120) = v162;
            v164 = v163 | 1;
            v165 = *(_DWORD *)(v9 + 264);
            *(_DWORD *)(v9 + 368) = 0;
            *(_DWORD *)(v9 + 152) = 0;
            *(_DWORD *)(v9 + 156) = v164;
            v166 = *(_DWORD *)(v9 + 192);
            *(_DWORD *)(v9 + 404) = 0;
            *(_DWORD *)(v9 + 264) = v165 | 1;
            *(_DWORD *)(v9 + 300) = v159 | 1;
            v167 = *(_DWORD *)(v9 + 336);
            v168 = *(_DWORD *)(v9 + 228);
            *(_DWORD *)(v9 + 188) = 0;
            *(_DWORD *)(v9 + 192) = v166 | 1;
            *(_DWORD *)(v9 + 440) = 0;
            *(_DWORD *)(v9 + 336) = v167 | 1;
            v169 = *(_DWORD *)(v9 + 372);
            *(_DWORD *)(v9 + 224) = 0;
            *(_DWORD *)(v9 + 228) = v168 | 1;
            *(_DWORD *)(v9 + 476) = 0;
            *(_DWORD *)(v9 + 372) = v169 | 1;
            *(_DWORD *)(v9 + 408) |= 1u;
            *(_DWORD *)(v9 + 444) |= 1u;
            *(_DWORD *)(v9 + 480) |= 1u;
          }
          if ( (v152 & 4) == 0 )
          {
            reg_modify_chan_list_for_band_6G(v9, v9);
            v114 = v187;
          }
        }
        if ( (*(_BYTE *)(v114 + 60) & 1) == 0 )
        {
          for ( j = 0; j != 3672; j += 36 )
          {
            v174 = v9 + j;
            v175 = *(_DWORD *)(v9 + j + 12);
            if ( (v175 & 8) != 0 )
            {
              *(_DWORD *)(v174 + 8) = 0;
              *(_DWORD *)(v174 + 12) = v175 | 1;
            }
          }
        }
        v170 = 0;
        while ( 1 )
        {
          v171 = v9 + v170;
          if ( *(_BYTE *)(v9 + v170 + 25) == 1 )
          {
            v172 = *(_DWORD *)(v171 + 12) | 1;
            *(_DWORD *)(v171 + 8) = 0;
            *(_DWORD *)(v171 + 12) = v172;
          }
          v170 += 36;
          if ( v170 == 3672 )
            JUMPOUT(0x1F3FA8);
        }
      }
    }
    v149 = (_DWORD)v136 != 102 && v146 <= (unsigned int)v136;
    if ( (unsigned int)v127 <= v146 )
      goto LABEL_190;
    goto LABEL_195;
  }
  if ( *(_BYTE *)(a1 + 56760) == 1 )
  {
    if ( *(_BYTE *)(a1 + 57894) )
    {
      v14 = 60;
      v15 = 2160LL * v11 + 19660;
      v16 = a1;
      do
      {
        if ( !*(_DWORD *)(v16 + 8864) || (*(_BYTE *)(v16 + 8868) & 1) != 0 )
        {
          qdf_mem_copy((void *)(v16 + 8856), (const void *)(v16 + v15), 0x24u);
          v10 = v187;
          *(_DWORD *)(v16 + 8888) = 0;
        }
        --v14;
        v16 += 36;
      }
      while ( v14 );
    }
    else
    {
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: No LPI reg rules",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "reg_append_mas_chan_list_for_6g_lpi");
      v10 = v187;
    }
    if ( *(_BYTE *)(v10 + 1204) )
    {
      v20 = *(_DWORD *)(v10 + 1516);
      if ( v20 > 2 )
        goto LABEL_215;
      v21 = 0;
      v22 = v9 + 2160LL * v20 + 28300;
      do
      {
        v23 = v9 + v21;
        if ( !*(_DWORD *)(v9 + v21 + 8864) || (*(_BYTE *)(v23 + 8868) & 1) != 0 )
        {
          qdf_mem_copy((void *)(v9 + 8856 + v21), (const void *)(v22 + v21), 0x24u);
          v10 = v187;
          *(_DWORD *)(v23 + 8888) = 2;
        }
        v21 += 36;
      }
      while ( v21 != 2160 );
LABEL_40:
      if ( !*(_BYTE *)(v10 + 1203) )
      {
        v12 = "%s: No SP reg rules";
        v13 = "reg_append_mas_chan_list_for_6g_sp";
        goto LABEL_49;
      }
      v30 = *(_DWORD *)(v10 + 1516);
      if ( v30 <= 2 )
      {
        v31 = 0;
        v32 = v9 + 2160LL * v30 + 23980;
        do
        {
          v33 = v9 + v31;
          if ( !*(_DWORD *)(v9 + v31 + 8864) || (*(_BYTE *)(v33 + 8868) & 1) != 0 )
          {
            qdf_mem_copy((void *)(v9 + 8856 + v31), (const void *)(v32 + v31), 0x24u);
            v10 = v187;
            *(_DWORD *)(v33 + 8888) = 1;
          }
          v31 += 36;
        }
        while ( v31 != 2160 );
        goto LABEL_50;
      }
LABEL_215:
      __break(0x5512u);
      JUMPOUT(0x1F4ABC);
    }
    v28 = "%s: No VLP reg rules";
    v29 = "reg_append_mas_chan_list_for_6g_vlp";
  }
  else
  {
    if ( *(_BYTE *)(a1 + 57896) )
    {
      v17 = 0;
      v18 = a1 + 2160LL * v11 + 28300;
      do
      {
        v19 = v9 + v17;
        if ( !*(_DWORD *)(v9 + v17 + 8864) || (*(_BYTE *)(v19 + 8868) & 1) != 0 )
        {
          qdf_mem_copy((void *)(v9 + 8856 + v17), (const void *)(v18 + v17), 0x24u);
          v10 = v187;
          *(_DWORD *)(v19 + 8888) = 2;
        }
        v17 += 36;
      }
      while ( v17 != 2160 );
    }
    else
    {
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: No VLP reg rules",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "reg_append_mas_chan_list_for_6g_vlp");
      v10 = v187;
    }
    if ( *(_BYTE *)(v10 + 1202) )
    {
      v24 = *(_DWORD *)(v10 + 1516);
      if ( v24 > 2 )
        goto LABEL_215;
      v25 = 60;
      v26 = 2160LL * v24 + 19660;
      v27 = v9;
      do
      {
        if ( !*(_DWORD *)(v27 + 8864) || (*(_BYTE *)(v27 + 8868) & 1) != 0 )
        {
          qdf_mem_copy((void *)(v27 + 8856), (const void *)(v27 + v26), 0x24u);
          v10 = v187;
          *(_DWORD *)(v27 + 8888) = 0;
        }
        --v25;
        v27 += 36;
      }
      while ( v25 );
      goto LABEL_40;
    }
    v28 = "%s: No LPI reg rules";
    v29 = "reg_append_mas_chan_list_for_6g_lpi";
  }
  qdf_trace_msg(0x51u, 8u, v28, a2, a3, a4, a5, a6, a7, a8, a9, v29);
  v10 = v187;
  goto LABEL_40;
}
