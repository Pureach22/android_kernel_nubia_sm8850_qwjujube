_QWORD *__fastcall cm_get_curr_candidate_entry(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *result; // x0
  __int64 v13; // x21
  __int64 cmpt_obj; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x20
  _QWORD *v24; // x1
  __int64 v25; // x20
  __int64 v26; // x8
  __int64 v27; // x19
  _QWORD *v28; // x0
  _QWORD *v29; // x21
  void *v30; // x8
  __int64 v31; // x0
  size_t v32; // x0
  void *v33; // x0
  __int64 v34; // x23
  __int64 v35; // x24
  __int64 v36; // x8
  __int64 v37; // x9
  bool v38; // zf
  __int64 v39; // x8
  __int64 v40; // x10
  __int64 v41; // x11
  __int64 v42; // x9
  __int64 v43; // x8
  __int64 v44; // x10
  __int64 v45; // x8
  __int64 v46; // x8
  __int64 v47; // x11
  __int64 v48; // x8
  __int64 v49; // x10
  __int64 v50; // x8
  __int64 v51; // x11
  __int64 v52; // x8
  __int64 v53; // x10
  __int64 v54; // x8
  __int64 v55; // x11
  __int64 v56; // x8
  __int64 v57; // x10
  __int64 v58; // x8
  __int64 v59; // x11
  __int64 v60; // x8
  __int64 v61; // x10
  __int64 v62; // x8
  __int64 v63; // x11
  __int64 v64; // x8
  __int64 v65; // x10
  __int64 v66; // x8
  __int64 v67; // x11
  __int64 v68; // x8
  __int64 v69; // x10
  __int64 v70; // x8
  __int64 v71; // x11
  __int64 v72; // x8
  __int64 v73; // x10
  __int64 v74; // x8
  __int64 v75; // x11
  __int64 v76; // x8
  __int64 v77; // x10
  __int64 v78; // x8
  __int64 v79; // x11
  __int64 v80; // x8
  __int64 v81; // x10
  __int64 v82; // x8
  __int64 v83; // x11
  __int64 v84; // x8
  __int64 v85; // x10
  __int64 v86; // x8
  __int64 v87; // x11
  __int64 v88; // x8
  __int64 v89; // x10
  __int64 v90; // x8
  __int64 v91; // x11
  __int64 v92; // x8
  __int64 v93; // x10
  __int64 v94; // x8
  __int64 v95; // x11
  __int64 v96; // x8
  __int64 v97; // x10
  __int64 v98; // x8
  __int64 v99; // x11
  __int64 v100; // x8
  __int64 v101; // x10
  __int64 v102; // x8
  __int64 v103; // x11
  __int64 v104; // x8
  __int64 v105; // x10
  __int64 v106; // x8
  __int64 v107; // x11
  __int64 v108; // x8
  __int64 v109; // x10
  __int64 v110; // x8
  __int64 v111; // x11
  __int64 v112; // x8
  __int64 v113; // x10
  __int64 v114; // x8
  __int64 v115; // x11
  __int64 v116; // x8
  __int64 v117; // x10
  __int64 v118; // x8
  __int64 v119; // x11
  __int64 v120; // x8
  __int64 v121; // x10
  __int64 v122; // x8
  __int64 v123; // x11
  __int64 v124; // x8
  __int64 v125; // x10
  __int64 v126; // x8
  __int64 v127; // x11
  __int64 v128; // x8
  __int64 v129; // x10
  __int64 v130; // x8
  __int64 v131; // x11
  __int64 v132; // x8
  __int64 v133; // x10
  __int64 v134; // x8
  __int64 v135; // x11
  __int64 v136; // x8
  __int64 v137; // x10
  __int64 v138; // x8
  __int64 v139; // x11
  __int64 v140; // x8
  __int64 v141; // x10
  __int64 v142; // x8
  __int64 v143; // x11
  __int64 v144; // x8
  __int64 v145; // x10
  __int64 v146; // x8
  __int64 v147; // x11
  __int64 v148; // x8
  __int64 v149; // x10
  __int64 v150; // x8
  __int64 v151; // x11
  __int64 v152; // x8
  __int64 v153; // x10
  __int64 v154; // x8
  __int64 v155; // x11
  __int64 v156; // x8
  __int64 v157; // x10
  __int64 v158; // x8
  __int64 v159; // x9
  __int64 v160; // x10
  __int64 v161; // x8
  __int64 v162; // x9
  __int64 v163; // x8
  __int64 v164; // x8
  _QWORD *v165; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v166[2]; // [xsp+10h] [xbp-10h] BYREF

  result = nullptr;
  v166[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v165 = nullptr;
  v166[0] = 0;
  if ( (a2 & 0xF000000) != 0xC000000 )
    goto LABEL_12;
  if ( !a1 )
  {
    v25 = jiffies;
    if ( cm_get_cm_ctx_fl___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s:%u: vdev is NULL",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "cm_get_curr_candidate_entry",
        1940);
      result = nullptr;
      cm_get_cm_ctx_fl___last_ticks = v25;
      goto LABEL_12;
    }
    goto LABEL_11;
  }
  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) != 0 )
  {
LABEL_11:
    result = nullptr;
    goto LABEL_12;
  }
  v13 = a1;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1);
  if ( cmpt_obj )
  {
    v23 = *(_QWORD *)(cmpt_obj + 496);
    if ( v23 )
    {
      qdf_mutex_acquire(v23 + 120);
      qdf_list_peek_front((_QWORD *)(v23 + 96), v166);
      v24 = (_QWORD *)v166[0];
      if ( !v166[0] )
        goto LABEL_160;
      while ( 1 )
      {
        qdf_list_peek_next((_QWORD *)(v23 + 96), v24, &v165);
        if ( *(_DWORD *)(v166[0] + 16LL) == a2 )
          break;
        v24 = v165;
        v165 = nullptr;
        v166[0] = v24;
        if ( !v24 )
          goto LABEL_160;
      }
      v26 = *(_QWORD *)(v166[0] + 864LL);
      if ( !v26 )
        goto LABEL_160;
      v27 = *(_QWORD *)(v26 + 24);
      if ( !v27 )
        goto LABEL_160;
      v28 = qdf_mem_malloc_atomic_fl(0x6C8u, (__int64)"util_scan_copy_cache_entry", 0x364u);
      if ( !v28 )
        goto LABEL_160;
      v29 = v28;
      qdf_mem_copy(v28, (const void *)v27, 0x6C8u);
      if ( *(_QWORD *)(v27 + 1192) )
      {
        v30 = qdf_mem_malloc_atomic_fl(*(unsigned int *)(v27 + 1184), (__int64)"util_scan_copy_cache_entry", 0x36Du);
        v31 = (__int64)v29;
        v29[149] = v30;
        if ( !v30 )
        {
LABEL_159:
          _qdf_mem_free(v31);
LABEL_160:
          v29 = nullptr;
LABEL_161:
          qdf_mutex_release(v23 + 120);
          result = v29;
          goto LABEL_12;
        }
        qdf_mem_copy(v30, *(const void **)(v27 + 1192), *(unsigned int *)(v27 + 1184));
        *((_DWORD *)v29 + 296) = *(_DWORD *)(v27 + 1184);
      }
      if ( *(_QWORD *)(v27 + 1712) )
      {
        v32 = *(unsigned int *)(v27 + 1704);
        if ( (_DWORD)v32 )
        {
          v33 = qdf_mem_malloc_atomic_fl(v32, (__int64)"util_scan_copy_beacon_data", 0x2D2u);
          v29[214] = v33;
          if ( v33 )
          {
            qdf_mem_copy(v33, *(const void **)(v27 + 1712), *(unsigned int *)(v27 + 1704));
            v34 = v29[214];
            *((_DWORD *)v29 + 426) = *(_DWORD *)(v27 + 1704);
            v35 = *(_QWORD *)(v27 + 1712);
            memcpy(v29 + 150, (const void *)(v27 + 1200), 0x1F8u);
            v36 = v29[150];
            v37 = v29[151];
            v38 = v36 == 0;
            v39 = v34 + v36 - v35;
            v40 = v29[152];
            v41 = v34 + v37 - v35;
            if ( v38 )
              v39 = 0;
            v38 = v37 == 0;
            v42 = v29[153];
            v29[150] = v39;
            v43 = v40 - v35;
            if ( v38 )
              v41 = 0;
            v38 = v40 == 0;
            v44 = v29[154];
            v45 = v34 + v43;
            v29[151] = v41;
            if ( v38 )
              v45 = 0;
            v29[152] = v45;
            if ( v42 )
              v46 = v34 + v42 - v35;
            else
              v46 = 0;
            v47 = v29[155];
            v29[153] = v46;
            v48 = v34 + v44 - v35;
            if ( !v44 )
              v48 = 0;
            v49 = v29[156];
            v29[154] = v48;
            v50 = v34 + v47 - v35;
            if ( !v47 )
              v50 = 0;
            v51 = v29[157];
            v29[155] = v50;
            v52 = v34 + v49 - v35;
            if ( !v49 )
              v52 = 0;
            v53 = v29[158];
            v29[156] = v52;
            v54 = v34 + v51 - v35;
            if ( !v51 )
              v54 = 0;
            v55 = v29[194];
            v29[157] = v54;
            v56 = v34 + v53 - v35;
            if ( !v53 )
              v56 = 0;
            v57 = v29[159];
            v29[158] = v56;
            v58 = v34 + v55 - v35;
            if ( !v55 )
              v58 = 0;
            v59 = v29[160];
            v29[194] = v58;
            v60 = v34 + v57 - v35;
            if ( !v57 )
              v60 = 0;
            v61 = v29[161];
            v29[159] = v60;
            v62 = v34 + v59 - v35;
            if ( !v59 )
              v62 = 0;
            v63 = v29[162];
            v29[160] = v62;
            v64 = v34 + v61 - v35;
            if ( !v61 )
              v64 = 0;
            v65 = v29[163];
            v29[161] = v64;
            v66 = v34 + v63 - v35;
            if ( !v63 )
              v66 = 0;
            v67 = v29[164];
            v29[162] = v66;
            v68 = v34 + v65 - v35;
            if ( !v65 )
              v68 = 0;
            v69 = v29[165];
            v29[163] = v68;
            v70 = v34 + v67 - v35;
            if ( !v67 )
              v70 = 0;
            v71 = v29[166];
            v29[164] = v70;
            v72 = v34 + v69 - v35;
            if ( !v69 )
              v72 = 0;
            v73 = v29[167];
            v29[165] = v72;
            v74 = v34 + v71 - v35;
            if ( !v71 )
              v74 = 0;
            v75 = v29[168];
            v29[166] = v74;
            v76 = v34 + v73 - v35;
            if ( !v73 )
              v76 = 0;
            v77 = v29[169];
            v29[167] = v76;
            v78 = v34 + v75 - v35;
            if ( !v75 )
              v78 = 0;
            v79 = v29[170];
            v29[168] = v78;
            v80 = v34 + v77 - v35;
            if ( !v77 )
              v80 = 0;
            v81 = v29[171];
            v29[169] = v80;
            v82 = v34 + v79 - v35;
            if ( !v79 )
              v82 = 0;
            v83 = v29[172];
            v29[170] = v82;
            v84 = v34 + v81 - v35;
            if ( !v81 )
              v84 = 0;
            v85 = v29[173];
            v29[171] = v84;
            v86 = v34 + v83 - v35;
            if ( !v83 )
              v86 = 0;
            v87 = v29[174];
            v29[172] = v86;
            v88 = v34 + v85 - v35;
            if ( !v85 )
              v88 = 0;
            v89 = v29[175];
            v29[173] = v88;
            v90 = v34 + v87 - v35;
            if ( !v87 )
              v90 = 0;
            v91 = v29[176];
            v29[174] = v90;
            v92 = v34 + v89 - v35;
            if ( !v89 )
              v92 = 0;
            v93 = v29[177];
            v29[175] = v92;
            v94 = v34 + v91 - v35;
            if ( !v91 )
              v94 = 0;
            v95 = v29[178];
            v29[176] = v94;
            v96 = v34 + v93 - v35;
            if ( !v93 )
              v96 = 0;
            v97 = v29[179];
            v29[177] = v96;
            v98 = v34 + v95 - v35;
            if ( !v95 )
              v98 = 0;
            v99 = v29[180];
            v29[178] = v98;
            v100 = v34 + v97 - v35;
            if ( !v97 )
              v100 = 0;
            v101 = v29[181];
            v29[179] = v100;
            v102 = v34 + v99 - v35;
            if ( !v99 )
              v102 = 0;
            v103 = v29[190];
            v29[180] = v102;
            v104 = v34 + v101 - v35;
            if ( !v101 )
              v104 = 0;
            v105 = v29[182];
            v29[181] = v104;
            v106 = v34 + v103 - v35;
            if ( !v103 )
              v106 = 0;
            v107 = v29[183];
            v29[190] = v106;
            v108 = v34 + v105 - v35;
            if ( !v105 )
              v108 = 0;
            v109 = v29[184];
            v29[182] = v108;
            v110 = v34 + v107 - v35;
            if ( !v107 )
              v110 = 0;
            v111 = v29[185];
            v29[183] = v110;
            v112 = v34 + v109 - v35;
            if ( !v109 )
              v112 = 0;
            v113 = v29[186];
            v29[184] = v112;
            v114 = v34 + v111 - v35;
            if ( !v111 )
              v114 = 0;
            v115 = v29[187];
            v29[185] = v114;
            v116 = v34 + v113 - v35;
            if ( !v113 )
              v116 = 0;
            v117 = v29[188];
            v29[186] = v116;
            v118 = v34 + v115 - v35;
            if ( !v115 )
              v118 = 0;
            v119 = v29[189];
            v29[187] = v118;
            v120 = v34 + v117 - v35;
            if ( !v117 )
              v120 = 0;
            v121 = v29[191];
            v29[188] = v120;
            v122 = v34 + v119 - v35;
            if ( !v119 )
              v122 = 0;
            v123 = v29[192];
            v29[189] = v122;
            v124 = v34 + v121 - v35;
            if ( !v121 )
              v124 = 0;
            v125 = v29[193];
            v29[191] = v124;
            v126 = v34 + v123 - v35;
            if ( !v123 )
              v126 = 0;
            v127 = v29[195];
            v29[192] = v126;
            v128 = v34 + v125 - v35;
            if ( !v125 )
              v128 = 0;
            v129 = v29[196];
            v29[193] = v128;
            v130 = v34 + v127 - v35;
            if ( !v127 )
              v130 = 0;
            v131 = v29[197];
            v29[195] = v130;
            v132 = v34 + v129 - v35;
            if ( !v129 )
              v132 = 0;
            v133 = v29[198];
            v29[196] = v132;
            v134 = v34 + v131 - v35;
            if ( !v131 )
              v134 = 0;
            v135 = v29[199];
            v29[197] = v134;
            v136 = v34 + v133 - v35;
            if ( !v133 )
              v136 = 0;
            v137 = v29[200];
            v29[198] = v136;
            v138 = v34 + v135 - v35;
            if ( !v135 )
              v138 = 0;
            v139 = v29[201];
            v29[199] = v138;
            v140 = v34 + v137 - v35;
            if ( !v137 )
              v140 = 0;
            v141 = v29[202];
            v29[200] = v140;
            v142 = v34 + v139 - v35;
            if ( !v139 )
              v142 = 0;
            v143 = v29[203];
            v29[201] = v142;
            v144 = v34 + v141 - v35;
            if ( !v141 )
              v144 = 0;
            v145 = v29[204];
            v29[202] = v144;
            v146 = v34 + v143 - v35;
            if ( !v143 )
              v146 = 0;
            v147 = v29[205];
            v29[203] = v146;
            v148 = v34 + v145 - v35;
            if ( !v145 )
              v148 = 0;
            v149 = v29[206];
            v29[204] = v148;
            v150 = v34 + v147 - v35;
            if ( !v147 )
              v150 = 0;
            v151 = v29[207];
            v29[205] = v150;
            v152 = v34 + v149 - v35;
            if ( !v149 )
              v152 = 0;
            v153 = v29[208];
            v29[206] = v152;
            v154 = v34 + v151 - v35;
            v38 = v151 == 0;
            v155 = v29[209];
            if ( v38 )
              v154 = 0;
            v29[207] = v154;
            v156 = v34 + v153 - v35;
            v38 = v153 == 0;
            v157 = v29[210];
            if ( v38 )
              v156 = 0;
            v29[208] = v156;
            if ( v155 )
              v158 = v34 + v155 - v35;
            else
              v158 = 0;
            v38 = v157 == 0;
            v159 = v34 + v157 - v35;
            v160 = v29[211];
            v29[209] = v158;
            if ( v38 )
              v161 = 0;
            else
              v161 = v159;
            v162 = v29[212];
            v29[210] = v161;
            v163 = v34 + v160 - v35;
            if ( !v160 )
              v163 = 0;
            v29[211] = v163;
            if ( v162 )
              v164 = v34 + v162 - v35;
            else
              v164 = 0;
            v29[212] = v164;
            goto LABEL_161;
          }
        }
      }
      v31 = (__int64)v29;
      if ( v29[149] )
      {
        _qdf_mem_free(v29[149]);
        v31 = (__int64)v29;
      }
      if ( *(_QWORD *)(v31 + 1712) )
      {
        _qdf_mem_free(*(_QWORD *)(v31 + 1712));
        v31 = (__int64)v29;
      }
      goto LABEL_159;
    }
  }
  qdf_trace_msg(
    0x68u,
    2u,
    "%s:%u: vdev %d cm_ctx is NULL",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "cm_get_curr_candidate_entry",
    1940,
    *(unsigned __int8 *)(v13 + 104));
  result = nullptr;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
