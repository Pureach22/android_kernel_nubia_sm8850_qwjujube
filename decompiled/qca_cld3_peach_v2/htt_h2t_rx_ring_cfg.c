void __fastcall htt_h2t_rx_ring_cfg(_QWORD *a1, int a2, __int64 a3, int a4, unsigned int a5, int *a6)
{
  __int64 v12; // x8
  __int64 v13; // x0
  unsigned int mon_drop_thresh; // w24
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  char v33; // w0
  int v34; // w8
  bool v35; // zf
  int v36; // w9
  unsigned int v37; // w23
  const char *v38; // x2
  char txmon_hw_support; // w0
  int v40; // w8
  int v41; // w8
  int v42; // w9
  int *v43; // x25
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x8
  __int64 v53; // x8
  void (__fastcall *v54)(int *, int *); // x8
  const char *v55; // x2
  __int64 v56; // x28
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned int v65; // w27
  unsigned int v66; // w8
  int v67; // w9
  int v68; // w9
  int v69; // w10
  unsigned int *v70; // x27
  int v71; // w9
  __int64 v72; // x8
  __int64 v73; // x8
  void (__fastcall *v74)(int *, int *); // x8
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  const char *v83; // x2
  __int64 v84; // x8
  __int64 v85; // x8
  void (__fastcall *v86)(int *, int *); // x8
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  const char *v95; // x2
  __int64 v96; // x8
  __int64 v97; // x8
  void (__fastcall *v98)(int *, int *); // x8
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  const char *v107; // x2
  unsigned __int64 v108; // x9
  int v109; // w8
  __int64 v110; // x8
  int v111; // w8
  int v112; // w8
  int v113; // w8
  int v114; // w8
  int v115; // w8
  int v116; // w8
  int v117; // w8
  int v118; // w8
  int v119; // w8
  int v120; // w8
  int v121; // w8
  int v122; // w8
  int v123; // w8
  int v124; // w8
  int v125; // w8
  int v126; // w8
  int v127; // w8
  int v128; // w8
  unsigned __int64 v129; // x9
  int v130; // w8
  __int64 v131; // x8
  int v132; // w8
  int v133; // w8
  int v134; // w8
  int v135; // w8
  int v136; // w8
  int v137; // w8
  int v138; // w8
  int v139; // w8
  int v140; // w8
  __int64 v141; // x9
  int v142; // w8
  int v143; // w8
  unsigned int v144; // w8
  unsigned int v145; // w8
  unsigned int v146; // w8
  unsigned int v147; // w8
  unsigned int v148; // w8
  unsigned int v149; // w8
  int v150; // w8
  int v151; // w8
  int v152; // w8
  int v153; // w8
  int v154; // w8
  int v155; // w8
  int v156; // w8
  int v157; // w8
  int v158; // w8
  int v159; // w8
  int v160; // w8
  int v161; // w8
  int v162; // w8
  int v163; // w8
  int v164; // w8
  int v165; // w8
  int v166; // w8
  int v167; // w8
  int v168; // w8
  int v169; // w8
  __int64 v170; // x9
  int v171; // w8
  unsigned int v172; // w8
  int v173; // w9
  int v174; // w8
  int v175; // w8
  int v176; // w8
  int v177; // w8
  int v178; // w8
  int v179; // w8
  int v180; // w8
  int v181; // w8
  int v182; // w8
  int v183; // w8
  int v184; // w8
  int v185; // w8
  int v186; // w8
  int v187; // w8
  int v188; // w8
  int v189; // w8
  int v190; // w8
  int v191; // w8
  int v192; // w8
  int v193; // w8
  int v194; // w8
  int v195; // w8
  unsigned int *v196; // x8
  double v197; // d0
  double v198; // d1
  double v199; // d2
  double v200; // d3
  double v201; // d4
  double v202; // d5
  double v203; // d6
  double v204; // d7
  int v205; // w8
  int v206; // w8
  int v207; // w8
  void (*v208)(void); // x8
  double v209; // d0
  double v210; // d1
  double v211; // d2
  double v212; // d3
  double v213; // d4
  double v214; // d5
  double v215; // d6
  double v216; // d7
  __int64 v217; // x8
  __int64 v218; // x8
  void (__fastcall *v219)(int *, int *); // x8
  double v220; // d0
  double v221; // d1
  double v222; // d2
  double v223; // d3
  double v224; // d4
  double v225; // d5
  double v226; // d6
  double v227; // d7
  const char *v228; // x2
  __int64 v229; // x8
  __int64 v230; // x8
  void (__fastcall *v231)(int *, int *); // x8
  const char *v232; // x2
  __int64 v233; // x8
  __int64 v234; // x8
  void (__fastcall *v235)(int *, int *); // x8
  __int64 v236; // [xsp+0h] [xbp-80h]
  _QWORD v237[6]; // [xsp+20h] [xbp-60h] BYREF
  __int64 v238; // [xsp+50h] [xbp-30h]
  __int64 v239; // [xsp+58h] [xbp-28h]
  __int64 v240; // [xsp+60h] [xbp-20h]
  __int64 v241; // [xsp+68h] [xbp-18h]
  __int64 v242; // [xsp+70h] [xbp-10h]
  __int64 v243; // [xsp+78h] [xbp-8h]

  v243 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = a1[1];
  v241 = 0;
  v242 = 0;
  v239 = 0;
  v240 = 0;
  v238 = 0;
  v13 = *(_QWORD *)(v12 + 40);
  memset(v237, 0, sizeof(v237));
  mon_drop_thresh = wlan_cfg_get_mon_drop_thresh(v13);
  v15 = _qdf_nbuf_alloc(a1[7], 120, 8, 4, 1, "dp_htt_htc_msg_alloc", 87);
  if ( !v15 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: htt_msg alloc failed ring type %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "htt_h2t_rx_ring_cfg",
      (unsigned int)a4);
    JUMPOUT(0x50B540);
  }
  v24 = v15;
  hal_get_srng_params(a1[2], a3, v237);
  if ( a4 > 16 )
  {
    switch ( a4 )
    {
      case 17:
        v37 = 1;
        goto LABEL_20;
      case 18:
        txmon_hw_support = wlan_cfg_get_txmon_hw_support(*(_QWORD *)(a1[1] + 40LL));
        v34 = 4;
        v35 = (txmon_hw_support & 1) == 0;
        v36 = 12;
LABEL_17:
        if ( v35 )
          v37 = v34;
        else
          v37 = v36;
LABEL_20:
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: ring_type %d ring_id %d htt_ring_id %d",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "htt_h2t_rx_ring_cfg",
          (unsigned int)a4,
          BYTE4(v238),
          v37);
        if ( *(_DWORD *)(v24 + 116) )
        {
          v40 = 0;
        }
        else
        {
          v42 = *(_DWORD *)(v24 + 208);
          v41 = *(_DWORD *)(v24 + 212);
          if ( (unsigned int)(v41 - v42) > 0x6F )
            goto LABEL_25;
          v40 = v42 - v41;
        }
        if ( (unsigned int)pskb_expand_head(v24, 0, (unsigned int)(v40 + 112), 2080) )
        {
          dev_kfree_skb_any_reason(v24, 1);
LABEL_133:
          v38 = "%s: Failed to expand head for RX Ring Cfg msg";
          goto LABEL_134;
        }
LABEL_25:
        if ( skb_put(v24, 112) )
        {
          v43 = *(int **)(v24 + 224);
          skb_push(v24, 0);
          *v43 = 12;
          v52 = *(_QWORD *)(a1[1] + 20112LL);
          if ( v52 )
          {
            v53 = *(_QWORD *)(v52 + 416);
            if ( v53 )
            {
              v54 = *(void (__fastcall **)(int *, int *))(v53 + 832);
              if ( v54 )
              {
                if ( *((_DWORD *)v54 - 1) != -1743817702 )
                  __break(0x8228u);
                v54(v43, a6);
LABEL_35:
                v56 = a1[1];
                if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v56 + 40)) )
                {
                  if ( a2 )
                  {
                    __break(0x5512u);
                    JUMPOUT(0x50B580);
                  }
                  v65 = *(unsigned __int8 *)(*(_QWORD *)(v56 + 72) + 2LL);
                }
                else
                {
                  v65 = a2 + 1;
                  if ( v65 >= 0x100 )
                    printk(
                      &unk_94DB9D,
                      "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
                      1332,
                      "!((target_pdev_id) & ~((HTT_RX_RING_SELECTION_CFG_PDEV_ID_M) >> (HTT_RX_RING_SELECTION_CFG_PDEV_ID_S)))");
                }
                v66 = 0;
                v67 = (v65 << 8) | (v37 << 16) | *v43;
                *v43 = v67;
                v68 = ((_DWORD)v238 << 21) & 0x1000000 | v67;
                *v43 = v68;
                v69 = *a6;
                v43[1] = 0;
                v70 = (unsigned int *)(v43 + 1);
                v71 = (32 * v69) & 0x4000000 | v68;
                if ( mon_drop_thresh )
                  v71 |= 0x8000000u;
                *v43 = v71;
                if ( a5 >= 0x10000 )
                {
                  printk(
                    &unk_94DB9D,
                    "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
                    1356,
                    "!((ring_buf_size) & ~((HTT_RX_RING_SELECTION_CFG_RING_BUFFER_SIZE_M) >> (HTT_RX_RING_SELECTION_CFG_R"
                    "ING_BUFFER_SIZE_S)))");
                  v66 = *v70;
                }
                *v70 = v66 | a5;
                v72 = *(_QWORD *)(a1[1] + 20112LL);
                if ( v72 )
                {
                  v73 = *(_QWORD *)(v72 + 416);
                  if ( v73 )
                  {
                    v74 = *(void (__fastcall **)(int *, int *))(v73 + 848);
                    if ( v74 )
                    {
                      if ( *((_DWORD *)v74 - 1) != -1743817702 )
                        __break(0x8228u);
                      v74(v43 + 1, a6);
LABEL_53:
                      v84 = *(_QWORD *)(a1[1] + 20112LL);
                      if ( v84 )
                      {
                        v85 = *(_QWORD *)(v84 + 416);
                        if ( v85 )
                        {
                          v86 = *(void (__fastcall **)(int *, int *))(v85 + 840);
                          if ( v86 )
                          {
                            if ( *((_DWORD *)v86 - 1) != -1743817702 )
                              __break(0x8228u);
                            v86(v43 + 1, a6);
LABEL_62:
                            v96 = *(_QWORD *)(a1[1] + 20112LL);
                            if ( v96 )
                            {
                              v97 = *(_QWORD *)(v96 + 416);
                              if ( v97 )
                              {
                                v98 = *(void (__fastcall **)(int *, int *))(v97 + 1024);
                                if ( v98 )
                                {
                                  if ( *((_DWORD *)v98 - 1) != -1743817702 )
                                    __break(0x8228u);
                                  v98(v43 + 1, a6);
LABEL_71:
                                  v43[2] = 0;
                                  v108 = *(_QWORD *)a6;
                                  if ( (*(_QWORD *)a6 & 0x4000) != 0 )
                                  {
                                    v110 = HIDWORD(v108) & 1;
                                    v43[2] = v110;
                                    LODWORD(v110) = (*(_QWORD *)a6 >> 30) & 8 | v110;
                                    v43[2] = v110;
                                    LODWORD(v110) = (*(_QWORD *)a6 >> 28) & 0x40 | v110;
                                    v43[2] = v110;
                                    LODWORD(v110) = (*(_QWORD *)a6 >> 26) & 0x200 | v110;
                                    v43[2] = v110;
                                    LODWORD(v110) = *(int *)((char *)a6 + 3) & 0x1000 | v110;
                                    v43[2] = v110;
                                    LODWORD(v110) = (*(_QWORD *)a6 >> 22) & 0x8000 | v110;
                                    v43[2] = v110;
                                    LODWORD(v110) = (*(_QWORD *)a6 >> 20) & 0x40000 | v110;
                                    v43[2] = v110;
                                    LODWORD(v110) = (*(_QWORD *)a6 >> 18) & 0x200000 | v110;
                                    v43[2] = v110;
                                    LODWORD(v110) = *(int *)((char *)a6 + 2) & 0x1000000 | v110;
                                    v43[2] = v110;
                                    v109 = (*(_QWORD *)a6 >> 14) & 0x8000000 | v110;
                                    v43[2] = v109;
                                    v108 = *(_QWORD *)a6;
                                    if ( (*(_QWORD *)a6 & 0x8000) == 0 )
                                      goto LABEL_76;
                                  }
                                  else
                                  {
                                    v109 = 0;
                                    if ( (v108 & 0x8000) == 0 )
                                    {
LABEL_76:
                                      if ( (v108 & 0x10000) != 0 )
                                      {
                                        v120 = v109 | (v108 >> 46) & 4;
                                        v43[2] = v120;
                                        v121 = (*(_QWORD *)a6 >> 44) & 0x20 | v120;
                                        v43[2] = v121;
                                        v122 = (*(_QWORD *)a6 >> 42) & 0x100 | v121;
                                        v43[2] = v122;
                                        v123 = (*(_QWORD *)a6 >> 40) & 0x800 | v122;
                                        v43[2] = v123;
                                        v124 = (*(_QWORD *)a6 >> 38) & 0x4000 | v123;
                                        v43[2] = v124;
                                        v125 = (*(_QWORD *)a6 >> 36) & 0x20000 | v124;
                                        v43[2] = v125;
                                        v126 = (*(_QWORD *)a6 >> 34) & 0x100000 | v125;
                                        v43[2] = v126;
                                        v127 = a6[1] & 0x800000 | v126;
                                        v43[2] = v127;
                                        v128 = (*(_QWORD *)a6 >> 30) & 0x4000000 | v127;
                                        v43[2] = v128;
                                        v43[2] = (*(_QWORD *)a6 >> 28) & 0x20000000 | v128;
                                      }
                                      v43[3] = 0;
                                      v129 = *(_QWORD *)a6;
                                      if ( (*(_QWORD *)a6 & 0x4000) != 0 )
                                      {
                                        v131 = (v129 >> 42) & 1;
                                        v43[3] = v131;
                                        LODWORD(v131) = (*(_QWORD *)a6 >> 40) & 8 | v131;
                                        v43[3] = v131;
                                        LODWORD(v131) = (*(_QWORD *)a6 >> 38) & 0x40 | v131;
                                        v43[3] = v131;
                                        LODWORD(v131) = (*(_QWORD *)a6 >> 36) & 0x200 | v131;
                                        v43[3] = v131;
                                        LODWORD(v131) = (*(_QWORD *)a6 >> 34) & 0x1000 | v131;
                                        v43[3] = v131;
                                        v130 = a6[1] & 0x8000 | v131;
                                        v43[3] = v130;
                                        v129 = *(_QWORD *)a6;
                                        if ( (*(_QWORD *)a6 & 0x8000) == 0 )
                                          goto LABEL_83;
                                      }
                                      else
                                      {
                                        v130 = 0;
                                        if ( (v129 & 0x8000) == 0 )
                                        {
LABEL_83:
                                          if ( (v129 & 0x10000) != 0 )
                                          {
                                            v136 = v130 | HIBYTE(v129) & 4;
                                            v43[3] = v136;
                                            v137 = (*(_QWORD *)a6 >> 54) & 0x20 | v136;
                                            v43[3] = v137;
                                            v138 = (*(_QWORD *)a6 >> 52) & 0x100 | v137;
                                            v43[3] = v138;
                                            v139 = (*(_QWORD *)a6 >> 50) & 0x800 | v138;
                                            v43[3] = v139;
                                            v140 = *((_WORD *)a6 + 3) & 0x4000 | v139;
                                            v43[3] = v140;
                                            v43[3] = (*(_QWORD *)a6 >> 46) & 0x20000 | v140;
                                          }
                                          v43[4] = 0;
                                          v141 = *(_QWORD *)a6;
                                          if ( (*(_QWORD *)a6 & 0x4000) != 0 )
                                          {
                                            v143 = a6[2] & 1;
                                            v43[4] = v143;
                                            v144 = v143 & 0xFFFFFFF7 | (8 * (((unsigned int)a6[2] >> 1) & 1));
                                            v43[4] = v144;
                                            v145 = v144 & 0xFFFFFFBF | ((((unsigned int)a6[2] >> 2) & 1) << 6);
                                            v43[4] = v145;
                                            v146 = v145 & 0xFFFFFDFF | ((((unsigned int)a6[2] >> 3) & 1) << 9);
                                            v43[4] = v146;
                                            v147 = v146 & 0xFFFFEFFF | ((((unsigned int)a6[2] >> 4) & 1) << 12);
                                            v43[4] = v147;
                                            v148 = v147 & 0xFFFF7FFF | ((((unsigned int)a6[2] >> 5) & 1) << 15);
                                            v43[4] = v148;
                                            v149 = v148 & 0xFFFBFFFF | ((((unsigned int)a6[2] >> 6) & 1) << 18);
                                            v43[4] = v149;
                                            v150 = (a6[2] << 14) & 0x200000 | v149;
                                            v43[4] = v150;
                                            v151 = (a6[2] << 16) & 0x1000000 | v150;
                                            v43[4] = v151;
                                            v142 = (a6[2] << 18) & 0x8000000 | v151;
                                            v43[4] = v142;
                                            v141 = *(_QWORD *)a6;
                                            if ( (*(_QWORD *)a6 & 0x8000) == 0 )
                                              goto LABEL_90;
                                          }
                                          else
                                          {
                                            v142 = 0;
                                            if ( (v141 & 0x8000) == 0 )
                                            {
LABEL_90:
                                              if ( (v141 & 0x10000) != 0 )
                                              {
                                                v161 = ((unsigned int)a6[2] >> 14) & 4 | v142;
                                                v43[4] = v161;
                                                v162 = ((unsigned int)a6[2] >> 12) & 0x20 | v161;
                                                v43[4] = v162;
                                                v163 = ((unsigned int)a6[2] >> 10) & 0x100 | v162;
                                                v43[4] = v163;
                                                v164 = ((unsigned int)a6[2] >> 8) & 0x800 | v163;
                                                v43[4] = v164;
                                                v165 = ((unsigned int)a6[2] >> 6) & 0x4000 | v164;
                                                v43[4] = v165;
                                                v166 = ((unsigned int)a6[2] >> 4) & 0x20000 | v165;
                                                v43[4] = v166;
                                                v167 = ((unsigned int)a6[2] >> 2) & 0x100000 | v166;
                                                v43[4] = v167;
                                                v168 = v167 | a6[2] & 0x800000;
                                                v43[4] = v168;
                                                v169 = (4 * a6[2]) & 0x4000000 | v168;
                                                v43[4] = v169;
                                                v43[4] = (16 * a6[2]) & 0x20000000 | v169;
                                              }
                                              v43[5] = 0;
                                              v170 = *(_QWORD *)a6;
                                              if ( (*(_QWORD *)a6 & 0x4000) != 0 )
                                              {
                                                v172 = a6[2];
                                                v43[5] = (v172 >> 10) & 1;
                                                v173 = ((unsigned int)a6[2] >> 8) & 8 | (v172 >> 10) & 1;
                                                v43[5] = v173;
                                                v174 = ((unsigned int)a6[2] >> 6) & 0x40 | v173;
                                                v43[5] = v174;
                                                v175 = ((unsigned int)a6[2] >> 4) & 0x200 | v174;
                                                v43[5] = v175;
                                                v176 = ((unsigned int)a6[2] >> 2) & 0x1000 | v175;
                                                v43[5] = v176;
                                                v177 = v176 | a6[2] & 0x8000;
                                                v43[5] = v177;
                                                v178 = (*((_QWORD *)a6 + 1) >> 28) & 0x40000 | v177;
                                                v43[5] = v178;
                                                v179 = (*((_QWORD *)a6 + 1) >> 26) & 0x200000 | v178;
                                                v43[5] = v179;
                                                v171 = (*((_QWORD *)a6 + 1) >> 11) & 0x1000000 | v179;
                                                v43[5] = v171;
                                                v170 = *(_QWORD *)a6;
                                                if ( (*(_QWORD *)a6 & 0x8000) == 0 )
                                                  goto LABEL_97;
                                              }
                                              else
                                              {
                                                v171 = 0;
                                                if ( (v170 & 0x8000) == 0 )
                                                {
LABEL_97:
                                                  if ( (v170 & 0x10000) != 0 )
                                                  {
                                                    v188 = HIBYTE(a6[2]) & 4 | v171;
                                                    v43[5] = v188;
                                                    v189 = ((unsigned int)a6[2] >> 22) & 0x20 | v188;
                                                    v43[5] = v189;
                                                    v190 = ((unsigned int)a6[2] >> 20) & 0x100 | v189;
                                                    v43[5] = v190;
                                                    v191 = ((unsigned int)a6[2] >> 18) & 0x800 | v190;
                                                    v43[5] = v191;
                                                    v192 = HIWORD(a6[2]) & 0x4000 | v191;
                                                    v43[5] = v192;
                                                    v193 = v192 | ((unsigned int)a6[2] >> 31 << 17);
                                                    v43[5] = v193;
                                                    v194 = (*((_QWORD *)a6 + 1) >> 42) & 0x100000 | v193;
                                                    v43[5] = v194;
                                                    v195 = (*((_QWORD *)a6 + 1) >> 40) & 0x800000 | v194;
                                                    v43[5] = v195;
                                                    v43[5] = (*((_QWORD *)a6 + 1) >> 25) & 0x4000000 | v195;
                                                  }
                                                  v43[6] = 0;
                                                  v43[6] = *a6 & 0x3F
                                                         | ((((unsigned int)*a6 >> 6) & 0x7F) << 7)
                                                         | ((unsigned int)*a6 >> 7) & 0x40;
                                                  v196 = *(unsigned int **)(v24 + 224);
                                                  qdf_trace_msg(
                                                    0x45u,
                                                    5u,
                                                    "%s: config_data: [0x%x][0x%x][0x%x][0x%x][0x%x][0x%x][0x%x]",
                                                    v99,
                                                    v100,
                                                    v101,
                                                    v102,
                                                    v103,
                                                    v104,
                                                    v105,
                                                    v106,
                                                    "htt_h2t_rx_ring_cfg",
                                                    *v196,
                                                    v196[1],
                                                    v196[2],
                                                    v196[3],
                                                    v196[4],
                                                    v196[5],
                                                    v196[6]);
                                                  v43[7] = 0;
                                                  if ( (*((_BYTE *)a6 + 2) & 0x20) != 0 )
                                                  {
                                                    v205 = *((unsigned __int16 *)a6 + 23);
                                                    v43[7] = v205;
                                                    v43[7] = v205 | (*((unsigned __int16 *)a6 + 24) << 16);
                                                    v43[8] = 0;
                                                    v206 = *((unsigned __int16 *)a6 + 25);
                                                    v43[8] = v206;
                                                    v43[8] = v206 | (*((unsigned __int16 *)a6 + 26) << 16);
                                                    v43[9] = 0;
                                                    v207 = *((unsigned __int16 *)a6 + 27);
                                                    v43[9] = v207;
                                                    v43[9] = v207 | (*((unsigned __int16 *)a6 + 28) << 16);
                                                    v43[10] = 0;
                                                    v43[10] = *((unsigned __int16 *)a6 + 29);
                                                  }
                                                  v43[11] = 0;
                                                  LODWORD(v236) = *((unsigned __int16 *)a6 + 23);
                                                  qdf_trace_msg(
                                                    0x45u,
                                                    5u,
                                                    "%s: offset_valid %d, offset: mpdu_start %d, msdu_end %d, rx_pkt_head"
                                                    "er %d, rx_pkt %d",
                                                    v197,
                                                    v198,
                                                    v199,
                                                    v200,
                                                    v201,
                                                    v202,
                                                    v203,
                                                    v204,
                                                    "htt_h2t_rx_ring_cfg",
                                                    ((unsigned int)*a6 >> 21) & 1,
                                                    *((unsigned __int16 *)a6 + 26),
                                                    *((unsigned __int16 *)a6 + 27),
                                                    *((unsigned __int16 *)a6 + 24),
                                                    v236);
                                                  v208 = *(void (**)(void))(a1[1] + 1400LL);
                                                  if ( *((_DWORD *)v208 - 1) != 246617225 )
                                                    __break(0x8228u);
                                                  v208();
                                                  if ( mon_drop_thresh )
                                                  {
                                                    if ( mon_drop_thresh >= 0x400 )
                                                      printk(
                                                        &unk_94DB9D,
                                                        "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/dp_htt.c",
                                                        1959,
                                                        "!((mon_drop_th) & ~((HTT_RX_RING_SELECTION_CFG_RX_DROP_THRESHOLD"
                                                        "_M) >> (HTT_RX_RING_SELECTION_CFG_RX_DROP_THRESHOLD_S)))");
                                                    v43[11] |= mon_drop_thresh;
                                                  }
                                                  v217 = *(_QWORD *)(a1[1] + 20112LL);
                                                  if ( v217 )
                                                  {
                                                    v218 = *(_QWORD *)(v217 + 416);
                                                    if ( v218 )
                                                    {
                                                      v219 = *(void (__fastcall **)(int *, int *))(v218 + 872);
                                                      if ( v219 )
                                                      {
                                                        if ( *((_DWORD *)v219 - 1) != -1743817702 )
                                                          __break(0x8228u);
                                                        v219(v43 + 11, a6);
LABEL_116:
                                                        v43[16] = 0;
                                                        v229 = *(_QWORD *)(a1[1] + 20112LL);
                                                        if ( v229 )
                                                        {
                                                          v230 = *(_QWORD *)(v229 + 416);
                                                          if ( v230 )
                                                          {
                                                            v231 = *(void (__fastcall **)(int *, int *))(v230 + 864);
                                                            if ( v231 )
                                                            {
                                                              if ( *((_DWORD *)v231 - 1) != -1743817702 )
                                                                __break(0x8228u);
                                                              v231(v43 + 16, a6);
LABEL_125:
                                                              v43[20] = 0;
                                                              v233 = *(_QWORD *)(a1[1] + 20112LL);
                                                              if ( v233 )
                                                              {
                                                                v234 = *(_QWORD *)(v233 + 416);
                                                                if ( v234 )
                                                                {
                                                                  v235 = *(void (__fastcall **)(int *, int *))(v234 + 880);
                                                                  if ( v235 )
                                                                  {
                                                                    if ( *((_DWORD *)v235 - 1) != -1743817702 )
                                                                      __break(0x8228u);
                                                                    v235(v43 + 20, a6);
                                                                    JUMPOUT(0x50B330);
                                                                  }
                                                                }
                                                              }
                                                              JUMPOUT(0x50B328);
                                                            }
                                                          }
                                                          v232 = "%s: callback not registered";
                                                        }
                                                        else
                                                        {
                                                          v232 = "%s: mon soc is NULL";
                                                        }
                                                        qdf_trace_msg(
                                                          0x92u,
                                                          8u,
                                                          v232,
                                                          v220,
                                                          v221,
                                                          v222,
                                                          v223,
                                                          v224,
                                                          v225,
                                                          v226,
                                                          v227,
                                                          "dp_mon_rx_enable_pkt_tlv_offset");
                                                        goto LABEL_125;
                                                      }
                                                    }
                                                    v228 = "%s: callback not registered";
                                                  }
                                                  else
                                                  {
                                                    v228 = "%s: mon soc is NULL";
                                                  }
                                                  qdf_trace_msg(
                                                    0x92u,
                                                    8u,
                                                    v228,
                                                    v209,
                                                    v210,
                                                    v211,
                                                    v212,
                                                    v213,
                                                    v214,
                                                    v215,
                                                    v216,
                                                    "dp_mon_rx_enable_mpdu_logging");
                                                  goto LABEL_116;
                                                }
                                              }
                                              v180 = v171 | (*((unsigned __int16 *)a6 + 10) >> 9) & 2;
                                              v43[5] = v180;
                                              v181 = v180 | (*((unsigned __int16 *)a6 + 10) >> 7) & 0x10;
                                              v43[5] = v181;
                                              v182 = v181 | (*((unsigned __int16 *)a6 + 10) >> 5) & 0x80;
                                              v43[5] = v182;
                                              v183 = v182 | (*((unsigned __int16 *)a6 + 10) >> 3) & 0x400;
                                              v43[5] = v183;
                                              v184 = v183 | (*((unsigned __int16 *)a6 + 10) >> 1) & 0x2000;
                                              v43[5] = v184;
                                              v185 = (2 * *((unsigned __int16 *)a6 + 10)) & 0x10000 | v184;
                                              v43[5] = v185;
                                              v186 = v185 | (((*((unsigned __int16 *)a6 + 8) >> 14) & 1) << 19);
                                              v43[5] = v186;
                                              v187 = v186 | (*((unsigned __int16 *)a6 + 8) << 7) & 0x400000;
                                              v43[5] = v187;
                                              v171 = v187 | (((*((unsigned __int16 *)a6 + 8) >> 3) & 1) << 25);
                                              v43[5] = v171;
                                              v170 = *(_QWORD *)a6;
                                              goto LABEL_97;
                                            }
                                          }
                                          v152 = v142 | (2 * (a6[5] & 1));
                                          v43[4] = v152;
                                          v153 = v152 | (8 * *((unsigned __int16 *)a6 + 10)) & 0x10;
                                          v43[4] = v153;
                                          v154 = v153 | (32 * *((unsigned __int16 *)a6 + 10)) & 0x80;
                                          v43[4] = v154;
                                          v155 = v154 | (*((unsigned __int16 *)a6 + 10) << 7) & 0x400;
                                          v43[4] = v155;
                                          v156 = v155 | (*((unsigned __int16 *)a6 + 10) << 9) & 0x2000;
                                          v43[4] = v156;
                                          v157 = v156 | (((*((unsigned __int16 *)a6 + 10) >> 5) & 1) << 16);
                                          v43[4] = v157;
                                          v158 = v157 | (((*((unsigned __int16 *)a6 + 10) >> 6) & 1) << 19);
                                          v43[4] = v158;
                                          v159 = v158 | (((*((unsigned __int16 *)a6 + 10) >> 7) & 1) << 22);
                                          v43[4] = v159;
                                          v160 = v159 | ((HIBYTE(*((unsigned __int16 *)a6 + 10)) & 1) << 25);
                                          v43[4] = v160;
                                          v142 = v160 | (((*((unsigned __int16 *)a6 + 10) >> 9) & 1) << 28);
                                          v43[4] = v142;
                                          v141 = *(_QWORD *)a6;
                                          goto LABEL_90;
                                        }
                                      }
                                      v132 = v130 | (*((unsigned __int16 *)a6 + 9) >> 9) & 2;
                                      v43[3] = v132;
                                      v133 = v132 | (*((unsigned __int16 *)a6 + 9) >> 7) & 0x10;
                                      v43[3] = v133;
                                      v134 = v133 | (*((unsigned __int16 *)a6 + 9) >> 5) & 0x80;
                                      v43[3] = v134;
                                      v135 = v134 | (*((unsigned __int16 *)a6 + 9) >> 3) & 0x400;
                                      v43[3] = v135;
                                      v130 = v135 | (*((unsigned __int16 *)a6 + 9) >> 1) & 0x2000;
                                      v43[3] = v130;
                                      v129 = *(_QWORD *)a6;
                                      goto LABEL_83;
                                    }
                                  }
                                  v111 = v109 | (2 * (*((_WORD *)a6 + 9) & 1));
                                  v43[2] = v111;
                                  v112 = v111 | (8 * *((unsigned __int16 *)a6 + 9)) & 0x10;
                                  v43[2] = v112;
                                  v113 = v112 | (32 * *((unsigned __int16 *)a6 + 9)) & 0x80;
                                  v43[2] = v113;
                                  v114 = v113 | (*((unsigned __int16 *)a6 + 9) << 7) & 0x400;
                                  v43[2] = v114;
                                  v115 = v114 | (*((unsigned __int16 *)a6 + 9) << 9) & 0x2000;
                                  v43[2] = v115;
                                  v116 = v115 | (((*((unsigned __int16 *)a6 + 9) >> 5) & 1) << 16);
                                  v43[2] = v116;
                                  v117 = v116 | (((*((unsigned __int16 *)a6 + 9) >> 6) & 1) << 19);
                                  v43[2] = v117;
                                  v118 = v117 | (((*((unsigned __int16 *)a6 + 9) >> 7) & 1) << 22);
                                  v43[2] = v118;
                                  v119 = v118 | ((HIBYTE(*((unsigned __int16 *)a6 + 9)) & 1) << 25);
                                  v43[2] = v119;
                                  v109 = v119 | (((*((unsigned __int16 *)a6 + 9) >> 9) & 1) << 28);
                                  v43[2] = v109;
                                  v108 = *(_QWORD *)a6;
                                  goto LABEL_76;
                                }
                              }
                              v107 = "%s: callback not registered";
                            }
                            else
                            {
                              v107 = "%s: mon soc is NULL";
                            }
                            qdf_trace_msg(
                              0x92u,
                              8u,
                              v107,
                              v87,
                              v88,
                              v89,
                              v90,
                              v91,
                              v92,
                              v93,
                              v94,
                              "dp_mon_rx_mac_filter_set");
                            goto LABEL_71;
                          }
                        }
                        v95 = "%s: callback not registered";
                      }
                      else
                      {
                        v95 = "%s: mon soc is NULL";
                      }
                      qdf_trace_msg(0x92u, 8u, v95, v75, v76, v77, v78, v79, v80, v81, v82, "dp_mon_rx_hdr_length_set");
                      goto LABEL_62;
                    }
                  }
                  v83 = "%s: callback not registered";
                }
                else
                {
                  v83 = "%s: mon soc is NULL";
                }
                qdf_trace_msg(0x92u, 8u, v83, v57, v58, v59, v60, v61, v62, v63, v64, "dp_mon_rx_packet_length_set");
                goto LABEL_53;
              }
            }
            v55 = "%s: callback not registered";
          }
          else
          {
            v55 = "%s: mon soc is NULL";
          }
          qdf_trace_msg(0x92u, 8u, v55, v44, v45, v46, v47, v48, v49, v50, v51, "dp_rx_mon_enable");
          goto LABEL_35;
        }
        goto LABEL_133;
      case 19:
        v37 = 3;
        goto LABEL_20;
    }
  }
  else
  {
    switch ( a4 )
    {
      case 14:
        v37 = 0;
        goto LABEL_20;
      case 15:
        v37 = 7;
        goto LABEL_20;
      case 16:
        v33 = wlan_cfg_get_txmon_hw_support(*(_QWORD *)(a1[1] + 40LL));
        v34 = 2;
        v35 = (v33 & 1) == 0;
        v36 = 11;
        goto LABEL_17;
    }
  }
  v38 = "%s: Ring currently not supported";
LABEL_134:
  qdf_trace_msg(0x3Fu, 2u, v38, v25, v26, v27, v28, v29, v30, v31, v32, "htt_h2t_rx_ring_cfg");
  JUMPOUT(0x50B534);
}
