__int64 __fastcall target_if_direct_buf_rx_module_register(
        __int64 a1,
        unsigned __int8 a2,
        _QWORD *a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v13; // w21
  const char *v15; // x2
  unsigned int v16; // w26
  __int64 comp_private_obj; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x23
  __int64 v29; // x9
  __int64 v30; // x8
  __int64 v31; // x27
  unsigned int v32; // w24
  __int64 v33; // x25
  char v34; // w8
  __int64 v35; // x9
  char v36; // w20
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x8
  unsigned int *v46; // x22
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x0
  __int64 *v82; // x0
  __int64 *v83; // x26
  __int64 v84; // x0
  unsigned int v85; // w25
  unsigned int entrysize; // w28
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  __int64 v111; // x8
  __int64 v112; // x9
  unsigned int v113; // w8
  __int64 v114; // x4
  __int64 v115; // x5
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  const char *v124; // x2
  const char *v125; // x2
  __int64 v126; // x9
  char v127; // w11
  int v128; // w10
  _DWORD *v129; // x12
  unsigned int v130; // w28
  __int64 v131; // x0
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  __int64 v156; // x8
  __int64 v157; // x9
  unsigned __int64 v158; // x9
  unsigned __int64 v159; // x8
  __int64 v160; // x0
  double v161; // d0
  double v162; // d1
  double v163; // d2
  double v164; // d3
  double v165; // d4
  double v166; // d5
  double v167; // d6
  double v168; // d7
  _QWORD *v169; // x8
  __int64 v170; // x11
  __int64 v171; // x10
  _QWORD *v172; // x9
  const char *v173; // x2
  _QWORD *v174; // x8
  __int64 v175; // x11
  __int64 v176; // x10
  _QWORD *v177; // x9
  double v178; // d0
  double v179; // d1
  double v180; // d2
  double v181; // d3
  double v182; // d4
  double v183; // d5
  double v184; // d6
  double v185; // d7
  _QWORD *v186; // x26
  __int64 pdev_wmi_handle; // x0
  __int64 v188; // x8
  __int64 v189; // x9
  unsigned __int64 v190; // x6
  int v191; // w5
  double v192; // d0
  double v193; // d1
  double v194; // d2
  double v195; // d3
  double v196; // d4
  double v197; // d5
  double v198; // d6
  double v199; // d7
  const char *v200; // x2
  double v201; // d0
  double v202; // d1
  double v203; // d2
  double v204; // d3
  double v205; // d4
  double v206; // d5
  double v207; // d6
  double v208; // d7
  const char *v209; // x2
  __int64 v210; // [xsp+0h] [xbp-F0h]
  __int64 v211; // [xsp+8h] [xbp-E8h]
  __int64 v212; // [xsp+10h] [xbp-E0h]
  __int64 v213; // [xsp+18h] [xbp-D8h]
  __int64 v214; // [xsp+20h] [xbp-D0h]
  __int64 v215; // [xsp+28h] [xbp-C8h]
  __int64 v216; // [xsp+30h] [xbp-C0h]
  unsigned int *v217; // [xsp+40h] [xbp-B0h]
  __int64 v218; // [xsp+48h] [xbp-A8h]
  unsigned int v219; // [xsp+50h] [xbp-A0h]
  __int64 v220; // [xsp+50h] [xbp-A0h]
  unsigned int v221; // [xsp+58h] [xbp-98h]
  __int64 v222; // [xsp+58h] [xbp-98h]
  _DWORD *v223; // [xsp+60h] [xbp-90h]
  __int64 v224; // [xsp+68h] [xbp-88h]
  __int64 v225; // [xsp+70h] [xbp-80h]
  __int64 v227; // [xsp+80h] [xbp-70h] BYREF
  unsigned __int64 v228; // [xsp+88h] [xbp-68h] BYREF
  unsigned __int64 v229; // [xsp+90h] [xbp-60h]
  __int64 v230; // [xsp+98h] [xbp-58h]
  __int64 v231; // [xsp+A0h] [xbp-50h]
  __int64 v232; // [xsp+A8h] [xbp-48h]
  __int64 v233; // [xsp+B0h] [xbp-40h]
  __int64 v234; // [xsp+B8h] [xbp-38h]
  __int64 v235; // [xsp+C0h] [xbp-30h]
  __int64 v236; // [xsp+C8h] [xbp-28h]
  __int64 v237; // [xsp+D0h] [xbp-20h]
  __int64 v238; // [xsp+D8h] [xbp-18h]
  __int64 v239; // [xsp+E0h] [xbp-10h]

  v239 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v15 = "%s: pdev context passed is null";
    goto LABEL_7;
  }
  if ( !a4 )
  {
    v15 = "%s: Response handler is null";
    goto LABEL_7;
  }
  v13 = a2;
  if ( a2 < 4u )
  {
    comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 8u);
    if ( comp_private_obj )
    {
      v28 = comp_private_obj;
      qdf_trace_msg(
        0x5Bu,
        8u,
        "%s: Dbr pdev obj %pK",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "target_if_direct_buf_rx_module_register",
        comp_private_obj);
      v29 = *(_QWORD *)(v28 + 8);
      if ( v29 )
      {
        v30 = a2;
        if ( *(_BYTE *)(v29 + 112LL * a2 + 49) != 1 )
        {
          qdf_trace_msg(
            0x5Bu,
            2u,
            "%s: Module %d not supported in target",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "target_if_direct_buf_rx_module_register",
            v13);
          v16 = 11;
          goto LABEL_8;
        }
        v31 = 0;
        v32 = 0;
        v33 = 112 * v30;
        v34 = 1;
        v224 = v33;
        v225 = a1;
        while ( 1 )
        {
          v35 = *(_QWORD *)(v28 + 8) + v33 + 56 * v31;
          v36 = v34;
          *(_QWORD *)(v35 + 40) = a4;
          *(_QWORD *)(v35 + 8) = *a3;
          qdf_trace_msg(
            0x5Bu,
            8u,
            "%s: Init DBR ring for module %d, srng %d",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "target_if_init_dbr_ring",
            v13,
            v32);
          v45 = *(_QWORD *)(v28 + 8) + v33;
          v46 = (unsigned int *)(v45 + 56 * v31);
          if ( v46 )
            break;
          qdf_trace_msg(
            0x5Bu,
            2u,
            "%s: dir buf rx module param is null",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "target_if_init_dbr_ring");
          v16 = 16;
LABEL_56:
          qdf_trace_msg(
            0x5Bu,
            2u,
            "%s: init dbr ring fail, srng_id %d, status %d",
            v116,
            v117,
            v118,
            v119,
            v120,
            v121,
            v122,
            v123,
            "target_if_direct_buf_rx_module_register",
            v32,
            v16);
LABEL_57:
          v34 = 0;
          v31 = 1;
          v32 = 1;
          if ( (v36 & 1) == 0 )
            goto LABEL_8;
        }
        qdf_trace_msg(
          0x5Bu,
          8u,
          "%s: mod_param %pK",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "target_if_init_dbr_ring",
          v45 + 56 * v31);
        *v46 = v13;
        *((_BYTE *)v46 + 4) = v31;
        *((_BYTE *)v46 + 5) = v31;
        qdf_trace_msg(0x5Bu, 8u, "%s: Init DBR srng", v47, v48, v49, v50, v51, v52, v53, v54, "target_if_dbr_init_srng");
        v55 = _qdf_mem_malloc(0xCu, "target_if_dbr_init_srng", 1588);
        *((_QWORD *)v46 + 2) = v55;
        if ( !v55 )
        {
          v16 = 2;
LABEL_55:
          qdf_trace_msg(
            0x5Bu,
            2u,
            "%s: DBR ring init failed %d",
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            "target_if_init_dbr_ring",
            v16);
          goto LABEL_56;
        }
        v64 = _qdf_mem_malloc(0x48u, "target_if_dbr_init_srng", 1595);
        *((_QWORD *)v46 + 3) = v64;
        if ( !v64 )
        {
          v16 = 2;
LABEL_54:
          _qdf_mem_free(*((_QWORD *)v46 + 2));
          goto LABEL_55;
        }
        v227 = 0;
        v228 = 0;
        v237 = 0;
        v238 = 0;
        v235 = 0;
        v236 = 0;
        v233 = 0;
        v234 = 0;
        v231 = 0;
        v232 = 0;
        v229 = 0;
        v230 = 0;
        qdf_trace_msg(0x5Bu, 8u, "%s: enter", v65, v66, v67, v68, v69, v70, v71, v72, "target_if_dbr_init_ring");
        v81 = *(_QWORD *)(v225 + 80);
        if ( v81 )
        {
          v82 = (__int64 *)wlan_objmgr_psoc_get_comp_private_obj(v81, 8u);
          if ( v82 )
          {
            v83 = v82;
            v84 = *v82;
            if ( v84 && v83[1] )
            {
              v85 = hal_srng_max_entries(v84, 20);
              entrysize = hal_srng_get_entrysize(*v83, 20);
              v221 = v85;
              qdf_trace_msg(
                0x5Bu,
                8u,
                "%s: Max Entries = %d",
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                v93,
                v94,
                "target_if_dbr_init_ring",
                v85);
              v219 = entrysize;
              qdf_trace_msg(
                0x5Bu,
                8u,
                "%s: Entry Size = %d",
                v95,
                v96,
                v97,
                v98,
                v99,
                v100,
                v101,
                v102,
                "target_if_dbr_init_ring",
                entrysize);
              v111 = *(_QWORD *)(v225 + 80);
              if ( v111 )
              {
                v112 = *(_QWORD *)(v111 + 2800);
                if ( v112 )
                {
                  v113 = *(_DWORD *)(v112 + 836);
                  v114 = *v46;
                  v33 = v224;
                  if ( v113 )
                  {
                    v115 = *((unsigned __int8 *)v46 + 4);
LABEL_34:
                    v126 = *(_QWORD *)(v112 + 3312);
                    v127 = 0;
                    v128 = 0;
                    do
                    {
                      while ( 1 )
                      {
                        v129 = (_DWORD *)(v126 + 20LL * (unsigned __int8)v128);
                        if ( *v129 != (_DWORD)v115 || v129[1] != (_DWORD)v114 )
                          break;
                        ++v128;
                        **((_DWORD **)v46 + 2) = v129[2];
                        *(_DWORD *)(*((_QWORD *)v46 + 2) + 4LL) = v129[3];
                        *(_DWORD *)(*((_QWORD *)v46 + 2) + 8LL) = v129[4];
                        v127 = 1;
                        if ( v113 <= (unsigned __int8)v128 )
                          goto LABEL_41;
                      }
                      ++v128;
                    }
                    while ( v113 > (unsigned __int8)v128 );
                    if ( (v127 & 1) == 0 )
                      goto LABEL_50;
LABEL_41:
                    v217 = *((unsigned int **)v46 + 2);
                    v218 = *((_QWORD *)v46 + 3);
                    if ( *v217 >= v221 )
                      v130 = v221;
                    else
                      v130 = *v217;
                    qdf_trace_msg(
                      0x5Bu,
                      8u,
                      "%s: Num entries = %d",
                      v103,
                      v104,
                      v105,
                      v106,
                      v107,
                      v108,
                      v109,
                      v110,
                      "target_if_dbr_init_ring",
                      v130);
                    *(_DWORD *)v218 = v130;
                    v131 = _qdf_mem_malloc(32LL * v130, "target_if_dbr_init_ring", 1511);
                    *((_QWORD *)v46 + 4) = v131;
                    if ( v131 )
                    {
                      v220 = v130 * v219 + 7;
                      *(_DWORD *)(v218 + 4) = v220;
                      qdf_trace_msg(
                        0x5Bu,
                        8u,
                        "%s: dbr_psoc_obj %pK",
                        v132,
                        v133,
                        v134,
                        v135,
                        v136,
                        v137,
                        v138,
                        v139,
                        "target_if_dbr_init_ring",
                        v83);
                      *(_QWORD *)(v218 + 16) = _qdf_mem_alloc_consistent(
                                                 v83[1],
                                                 *(_QWORD *)(v83[1] + 40),
                                                 v220,
                                                 (__int64)&v227,
                                                 "target_if_dbr_init_ring",
                                                 1520);
                      qdf_trace_msg(
                        0x5Bu,
                        8u,
                        "%s: vaddr aligned allocated",
                        v140,
                        v141,
                        v142,
                        v143,
                        v144,
                        v145,
                        v146,
                        v147,
                        "target_if_dbr_init_ring");
                      v156 = v227;
                      v157 = *(_QWORD *)(v218 + 16);
                      *(_QWORD *)(v218 + 8) = v227;
                      if ( v157 )
                      {
                        v158 = (v157 + 7) & 0xFFFFFFFFFFFFFFF8LL;
                        v159 = (v156 + 7) & 0xFFFFFFFFFFFFFFF8LL;
                        *(_QWORD *)(v218 + 24) = v159;
                        *(_QWORD *)(v218 + 32) = v158;
                        v228 = v159;
                        v229 = v158;
                        LODWORD(v230) = v130;
                        v160 = hal_srng_setup(
                                 *v83,
                                 0x14u,
                                 *v46,
                                 *((unsigned __int8 *)v46 + 4),
                                 (__int64)&v228,
                                 0,
                                 v148,
                                 v149,
                                 v150,
                                 v151,
                                 v152,
                                 v153,
                                 v154,
                                 v155);
                        if ( v160 )
                        {
                          *(_QWORD *)(v218 + 56) = v160;
                          v169 = (_QWORD *)*v83;
                          if ( *(_DWORD *)(v160 + 116) )
                          {
                            if ( (*(_DWORD *)(v160 + 76) & 0x80000000) != 0 )
                            {
                              v172 = (_QWORD *)(*v83 + 74040);
                              v170 = 144;
                              v171 = 9254;
                            }
                            else
                            {
                              v170 = 144;
                              v171 = 2;
                              v172 = (_QWORD *)(*v169 + 728LL);
                            }
                          }
                          else
                          {
                            v172 = (_QWORD *)(*v83 + 74024);
                            v170 = 128;
                            v171 = 9252;
                          }
                          *(_QWORD *)(v218 + 48) = *v172 + *(_QWORD *)(v160 + v170) - v169[v171];
                          v174 = (_QWORD *)*v83;
                          if ( *(_DWORD *)(v160 + 116) )
                          {
                            v175 = 128;
                            v176 = 9252;
                            v177 = v174 + 9253;
                          }
                          else
                          {
                            v175 = 144;
                            if ( (*(_DWORD *)(v160 + 76) & 0x80000000) != 0 )
                            {
                              v177 = v174 + 9255;
                              v176 = 9254;
                            }
                            else
                            {
                              v176 = 2;
                              v177 = (_QWORD *)(*v174 + 728LL);
                            }
                          }
                          *(_QWORD *)(v218 + 40) = *v177 + *(_QWORD *)(v160 + v175) - v174[v176];
                          *(_DWORD *)(v218 + 64) = v217[1];
                          if ( !(unsigned int)target_if_dbr_fill_ring(v225, v46) )
                          {
                            *((_BYTE *)v46 + 48) = 1;
                            qdf_trace_msg(
                              0x5Bu,
                              8u,
                              "%s: enter",
                              v161,
                              v162,
                              v163,
                              v164,
                              v165,
                              v166,
                              v167,
                              v168,
                              "target_if_dbr_cfg_tgt");
                            if ( *(_QWORD *)(v225 + 80) )
                            {
                              v186 = *((_QWORD **)v46 + 3);
                              v223 = *((_DWORD **)v46 + 2);
                              pdev_wmi_handle = lmac_get_pdev_wmi_handle(
                                                  v225,
                                                  v178,
                                                  v179,
                                                  v180,
                                                  v181,
                                                  v182,
                                                  v183,
                                                  v184,
                                                  v185);
                              if ( pdev_wmi_handle )
                              {
                                v222 = pdev_wmi_handle;
                                qdf_trace_msg(
                                  0x5Bu,
                                  8u,
                                  "%s: Sending DBR Ring CFG to target",
                                  v178,
                                  v179,
                                  v180,
                                  v181,
                                  v182,
                                  v183,
                                  v184,
                                  v185,
                                  "target_if_dbr_cfg_tgt");
                                v188 = v186[5];
                                v189 = v186[6];
                                v190 = v186[3];
                                LODWORD(v228) = *((unsigned __int8 *)v46 + 4);
                                v191 = *v46;
                                v229 = v190;
                                v230 = v188;
                                HIDWORD(v228) = v191;
                                v231 = __ROR8__(v189, 32);
                                HIDWORD(v232) = *v223;
                                LODWORD(v232) = v223[1];
                                HIDWORD(v233) = v46[2];
                                LODWORD(v215) = HIDWORD(v233);
                                LODWORD(v214) = HIDWORD(v232);
                                LODWORD(v233) = v46[3];
                                LODWORD(v216) = v233;
                                LODWORD(v213) = HIDWORD(v189);
                                LODWORD(v212) = v189;
                                LODWORD(v211) = HIDWORD(v188);
                                LODWORD(v210) = v188;
                                qdf_trace_msg(
                                  0x5Bu,
                                  8u,
                                  "%s: pdev id %d mod id %d base addr lo %x\n"
                                  "base addr hi %x head idx addr lo %x\n"
                                  "head idx addr hi %x tail idx addr lo %x\n"
                                  "tail idx addr hi %x num ptr %d\n"
                                  "num resp %d event timeout %d\n",
                                  v192,
                                  v193,
                                  v194,
                                  v195,
                                  v196,
                                  v197,
                                  v198,
                                  v199,
                                  "target_if_dbr_cfg_tgt",
                                  v210,
                                  v211,
                                  v212,
                                  v213,
                                  v214,
                                  v215,
                                  v216);
                                v16 = wmi_unified_dbr_ring_cfg(v222, &v228);
                                if ( !v16 )
                                  goto LABEL_57;
                                goto LABEL_78;
                              }
                              v16 = 4;
                              v200 = "%s: WMI handle null. Can't send WMI CMD";
                            }
                            else
                            {
                              v16 = 16;
                              v200 = "%s: psoc is null";
                            }
                            qdf_trace_msg(
                              0x5Bu,
                              2u,
                              v200,
                              v178,
                              v179,
                              v180,
                              v181,
                              v182,
                              v183,
                              v184,
                              v185,
                              "target_if_dbr_cfg_tgt");
LABEL_78:
                            qdf_trace_msg(
                              0x5Bu,
                              2u,
                              "%s: DBR config to target failed %d",
                              v20,
                              v21,
                              v22,
                              v23,
                              v24,
                              v25,
                              v26,
                              v27,
                              "target_if_init_dbr_ring",
                              v16);
                            target_if_deinit_dbr_ring(
                              v225,
                              v28,
                              v13,
                              v31,
                              v201,
                              v202,
                              v203,
                              v204,
                              v205,
                              v206,
                              v207,
                              v208);
                            goto LABEL_56;
                          }
                          v173 = "%s: target if dbr fill ring failed";
                        }
                        else
                        {
                          v173 = "%s: srng setup failed";
                        }
                        qdf_trace_msg(
                          0x5Bu,
                          2u,
                          v173,
                          v161,
                          v162,
                          v163,
                          v164,
                          v165,
                          v166,
                          v167,
                          v168,
                          "target_if_dbr_init_ring");
                        _qdf_mem_free(*((_QWORD *)v46 + 4));
                        _qdf_mem_free_consistent(v83[1], *(_QWORD *)(v83[1] + 40), v220);
                      }
                      else
                      {
                        qdf_trace_msg(
                          0x5Bu,
                          2u,
                          "%s: dir buf rx vaddr alloc failed",
                          v148,
                          v149,
                          v150,
                          v151,
                          v152,
                          v153,
                          v154,
                          v155,
                          "target_if_dbr_init_ring");
                        _qdf_mem_free(*((_QWORD *)v46 + 4));
                      }
                    }
                    goto LABEL_53;
                  }
                  v113 = *(_DWORD *)(v112 + 964);
                  v115 = *((unsigned __int8 *)v46 + 4);
                  if ( v113 )
                    goto LABEL_34;
LABEL_50:
                  qdf_trace_msg(
                    0x5Bu,
                    2u,
                    "%s: No cap found for module %d in pdev %d",
                    v103,
                    v104,
                    v105,
                    v106,
                    v107,
                    v108,
                    v109,
                    v110,
                    "populate_dbr_cap_mod_param",
                    v114,
                    v115);
                  goto LABEL_51;
                }
                v125 = "%s: target_psoc_info is null";
              }
              else
              {
                v125 = "%s: psoc is null";
              }
              qdf_trace_msg(
                0x5Bu,
                2u,
                v125,
                v103,
                v104,
                v105,
                v106,
                v107,
                v108,
                v109,
                v110,
                "populate_dbr_cap_mod_param");
              v33 = v224;
LABEL_51:
              v124 = "%s: Module cap population failed";
              goto LABEL_52;
            }
            v124 = "%s: dir buf rx target attach failed";
          }
          else
          {
            v124 = "%s: dir buf rx psoc object is null";
          }
        }
        else
        {
          v124 = "%s: psoc is null";
        }
LABEL_52:
        qdf_trace_msg(0x5Bu, 2u, v124, v73, v74, v75, v76, v77, v78, v79, v80, "target_if_dbr_init_ring");
LABEL_53:
        qdf_trace_msg(
          0x5Bu,
          2u,
          "%s: DBR ring init failed",
          v132,
          v133,
          v134,
          v135,
          v136,
          v137,
          v138,
          v139,
          "target_if_dbr_init_srng");
        _qdf_mem_free(*((_QWORD *)v46 + 3));
        v16 = 16;
        goto LABEL_54;
      }
      v209 = "%s: dbr_pdev_obj->dbr_mod_param is NULL";
    }
    else
    {
      v209 = "%s: dir buf rx object is null";
    }
    qdf_trace_msg(0x5Bu, 2u, v209, v20, v21, v22, v23, v24, v25, v26, v27, "target_if_direct_buf_rx_module_register");
    v16 = 16;
    goto LABEL_8;
  }
  v15 = "%s: Invalid module id";
LABEL_7:
  qdf_trace_msg(0x5Bu, 2u, v15, a5, a6, a7, a8, a9, a10, a11, a12, "target_if_direct_buf_rx_module_register");
  v16 = 4;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v16;
}
