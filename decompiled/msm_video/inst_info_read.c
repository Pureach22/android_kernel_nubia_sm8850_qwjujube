__int64 __fastcall inst_info_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _QWORD *v4; // x5
  __int64 v5; // x8
  __int64 inst_ref; // x0
  __int64 v7; // x19
  __int64 v8; // x0
  __int64 v9; // x4
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x23
  __int64 v19; // x21
  unsigned int v20; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  char *v30; // x4
  __int64 v31; // x21
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x20
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x20
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x20
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // x20
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  __int64 v76; // x20
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x20
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // x20
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  __int64 v103; // x21
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  unsigned __int64 v112; // x24
  unsigned __int8 *v113; // x26
  char *v114; // x22
  __int64 v115; // x21
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  __int64 v124; // x21
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  unsigned int v133; // w0
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  __int64 v142; // x9
  unsigned int v143; // w22
  __int64 v144; // x3
  __int64 v145; // x21
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  unsigned int v154; // w0
  __int64 v156; // x20
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  __int64 v165; // x20
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  __int64 v174; // x20
  double v175; // d0
  double v176; // d1
  double v177; // d2
  double v178; // d3
  double v179; // d4
  double v180; // d5
  double v181; // d6
  double v182; // d7
  __int64 v183; // x20
  double v184; // d0
  double v185; // d1
  double v186; // d2
  double v187; // d3
  double v188; // d4
  double v189; // d5
  double v190; // d6
  double v191; // d7
  unsigned int v192; // w0
  __int64 v193; // x20
  unsigned __int64 StatusReg; // x20
  __int64 v195; // x21
  __int64 v196; // [xsp+0h] [xbp-20h]
  __int64 v197; // [xsp+0h] [xbp-20h]

  v4 = *(_QWORD **)(a1 + 32);
  if ( !v4 || !*v4 || (v5 = v4[1]) == 0 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_83566, "err ", 0xFFFFFFFFLL, "codec", "inst_info_read");
    return 0;
  }
  inst_ref = get_inst_ref(*v4, v5);
  if ( !inst_ref )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      printk(&unk_962AD, "high", 0xFFFFFFFFLL, "codec", "inst_info_read");
    return 0;
  }
  v7 = inst_ref;
  v8 = vzalloc_noprof(4096);
  if ( v8 )
  {
    while ( 1 )
    {
      v18 = v8 + 4096;
      v19 = v8;
      v20 = write_str(v8, 4096, "==============================\n", v10, v11, v12, v13, v14, v15, v16, v17);
      v196 = v19;
      v29 = v19 + v20;
      v30 = *(_DWORD *)(v7 + 308) == 1 ? "Encoder" : "Decoder";
      v31 = v29
          + (unsigned int)write_str(
                            v29,
                            4096LL - v20,
                            "INSTANCE: %pK (%s)\n",
                            v21,
                            v22,
                            v23,
                            v24,
                            v25,
                            v26,
                            v27,
                            v28,
                            v7,
                            v30,
                            v196);
      v40 = v31
          + (unsigned int)write_str(
                            v31,
                            v18 - v31,
                            "==============================\n",
                            v32,
                            v33,
                            v34,
                            v35,
                            v36,
                            v37,
                            v38,
                            v39);
      v49 = v40
          + (unsigned int)write_str(
                            v40,
                            v18 - v40,
                            "core: %pK\n",
                            v41,
                            v42,
                            v43,
                            v44,
                            v45,
                            v46,
                            v47,
                            v48,
                            *(_QWORD *)(v7 + 320));
      v58 = v49
          + (unsigned int)write_str(
                            v49,
                            v18 - v49,
                            "height: %d\n",
                            v50,
                            v51,
                            v52,
                            v53,
                            v54,
                            v55,
                            v56,
                            v57,
                            *(unsigned int *)(v7 + 604));
      v67 = v58
          + (unsigned int)write_str(
                            v58,
                            v18 - v58,
                            "width: %d\n",
                            v59,
                            v60,
                            v61,
                            v62,
                            v63,
                            v64,
                            v65,
                            v66,
                            *(unsigned int *)(v7 + 600));
      v76 = v67
          + (unsigned int)write_str(
                            v67,
                            v18 - v67,
                            "fps: %lld\n",
                            v68,
                            v69,
                            v70,
                            v71,
                            v72,
                            v73,
                            v74,
                            v75,
                            *(__int64 *)(v7 + 19472) >> 16);
      v85 = v76
          + (unsigned int)write_str(
                            v76,
                            v18 - v76,
                            "state: %d\n",
                            v77,
                            v78,
                            v79,
                            v80,
                            v81,
                            v82,
                            v83,
                            v84,
                            *(unsigned int *)(v7 + 160));
      v94 = v85
          + (unsigned int)write_str(
                            v85,
                            v18 - v85,
                            "secure: %d\n",
                            v86,
                            v87,
                            v88,
                            v89,
                            v90,
                            v91,
                            v92,
                            v93,
                            *(_QWORD *)(v7 + 21824) != 0);
      v103 = v94
           + (unsigned int)write_str(
                             v94,
                             v18 - v94,
                             "-----------Formats-------------\n",
                             v95,
                             v96,
                             v97,
                             v98,
                             v99,
                             v100,
                             v101,
                             v102);
      v112 = 0;
      v113 = (unsigned __int8 *)(v7 + 572);
      while ( 1 )
      {
        if ( v112 > 1 )
          goto LABEL_11;
        v114 = v112 ? "Capture" : "Output";
        v115 = v103
             + (unsigned int)write_str(
                               v103,
                               v18 - v103,
                               "capability: %s\n",
                               v104,
                               v105,
                               v106,
                               v107,
                               v108,
                               v109,
                               v110,
                               v111,
                               v114);
        v124 = v115
             + (unsigned int)write_str(
                               v115,
                               v18 - v115,
                               "planes : %d\n",
                               v116,
                               v117,
                               v118,
                               v119,
                               v120,
                               v121,
                               v122,
                               v123,
                               *v113);
        v133 = write_str(v124, v18 - v124, "type: %s\n", v125, v126, v127, v128, v129, v130, v131, v132, v114);
        v142 = *(_QWORD *)(v7 + 1840 + 8 * v112);
        v143 = v133;
        v144 = *(_QWORD *)(v142 + 232)
             ? (unsigned int)_bitmap_weight(*(_QWORD *)(v142 + 232), *(unsigned int *)(v142 + 240))
             : 0LL;
        v145 = v124
             + v143
             + (unsigned int)write_str(
                               v124 + v143,
                               v18 - (v124 + v143),
                               "count: %u\n",
                               v134,
                               v135,
                               v136,
                               v137,
                               v138,
                               v139,
                               v140,
                               v141,
                               v144);
        if ( *v113 )
        {
          v145 += (unsigned int)write_str(
                                  v145,
                                  v18 - v145,
                                  "size for plane %d: %u\n",
                                  v146,
                                  v147,
                                  v148,
                                  v149,
                                  v150,
                                  v151,
                                  v152,
                                  v153,
                                  0,
                                  *((unsigned int *)v113 - 40));
          if ( *v113 >= 2u )
          {
            v145 += (unsigned int)write_str(
                                    v145,
                                    v18 - v145,
                                    "size for plane %d: %u\n",
                                    v146,
                                    v147,
                                    v148,
                                    v149,
                                    v150,
                                    v151,
                                    v152,
                                    v153,
                                    1,
                                    *((unsigned int *)v113 - 35));
            if ( *v113 >= 3u )
            {
              v145 += (unsigned int)write_str(
                                      v145,
                                      v18 - v145,
                                      "size for plane %d: %u\n",
                                      v146,
                                      v147,
                                      v148,
                                      v149,
                                      v150,
                                      v151,
                                      v152,
                                      v153,
                                      2,
                                      *((unsigned int *)v113 - 30));
              if ( *v113 >= 4u )
              {
                v145 += (unsigned int)write_str(
                                        v145,
                                        v18 - v145,
                                        "size for plane %d: %u\n",
                                        v146,
                                        v147,
                                        v148,
                                        v149,
                                        v150,
                                        v151,
                                        v152,
                                        v153,
                                        3,
                                        *((unsigned int *)v113 - 25));
                if ( *v113 >= 5u )
                {
                  v145 += (unsigned int)write_str(
                                          v145,
                                          v18 - v145,
                                          "size for plane %d: %u\n",
                                          v146,
                                          v147,
                                          v148,
                                          v149,
                                          v150,
                                          v151,
                                          v152,
                                          v153,
                                          4,
                                          *((unsigned int *)v113 - 20));
                  if ( *v113 >= 6u )
                  {
                    v145 += (unsigned int)write_str(
                                            v145,
                                            v18 - v145,
                                            "size for plane %d: %u\n",
                                            v146,
                                            v147,
                                            v148,
                                            v149,
                                            v150,
                                            v151,
                                            v152,
                                            v153,
                                            5,
                                            *((unsigned int *)v113 - 15));
                    if ( *v113 >= 7u )
                    {
                      v145 += (unsigned int)write_str(
                                              v145,
                                              v18 - v145,
                                              "size for plane %d: %u\n",
                                              v146,
                                              v147,
                                              v148,
                                              v149,
                                              v150,
                                              v151,
                                              v152,
                                              v153,
                                              6,
                                              *((unsigned int *)v113 - 10));
                      if ( *v113 >= 8u )
                        break;
                    }
                  }
                }
              }
            }
          }
        }
LABEL_10:
        v103 = v145 + (unsigned int)write_str(v145, v18 - v145, "\n", v146, v147, v148, v149, v150, v151, v152, v153);
LABEL_11:
        ++v112;
        v113 += 208;
        if ( v112 == 5 )
        {
          v156 = v103
               + (unsigned int)write_str(
                                 v103,
                                 v18 - v103,
                                 "-------------------------------\n",
                                 v104,
                                 v105,
                                 v106,
                                 v107,
                                 v108,
                                 v109,
                                 v110,
                                 v111);
          v165 = v156
               + (unsigned int)write_str(
                                 v156,
                                 v18 - v156,
                                 "ETB Count: %d\n",
                                 v157,
                                 v158,
                                 v159,
                                 v160,
                                 v161,
                                 v162,
                                 v163,
                                 v164,
                                 *(_QWORD *)(v7 + 4232));
          v174 = v165
               + (unsigned int)write_str(
                                 v165,
                                 v18 - v165,
                                 "EBD Count: %d\n",
                                 v166,
                                 v167,
                                 v168,
                                 v169,
                                 v170,
                                 v171,
                                 v172,
                                 v173,
                                 *(_QWORD *)(v7 + 4256));
          v183 = v174
               + (unsigned int)write_str(
                                 v174,
                                 v18 - v174,
                                 "FTB Count: %d\n",
                                 v175,
                                 v176,
                                 v177,
                                 v178,
                                 v179,
                                 v180,
                                 v181,
                                 v182,
                                 *(_QWORD *)(v7 + 4240));
          v192 = write_str(
                   v183,
                   v18 - v183,
                   "FBD Count: %d\n",
                   v184,
                   v185,
                   v186,
                   v187,
                   v188,
                   v189,
                   v190,
                   v191,
                   *(_QWORD *)(v7 + 4248));
          v193 = simple_read_from_buffer(a2, a3, a4, v197, v183 + v192 - v197);
          vfree(v197);
          goto LABEL_39;
        }
      }
      v154 = write_str(
               v145,
               v18 - v145,
               "size for plane %d: %u\n",
               v146,
               v147,
               v148,
               v149,
               v150,
               v151,
               v152,
               v153,
               7,
               *((unsigned int *)v113 - 5));
      if ( *v113 <= 8u )
        break;
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v195 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &inst_info_read__alloc_tag;
      v8 = vzalloc_noprof(4096);
      *(_QWORD *)(StatusReg + 80) = v195;
      if ( !v8 )
        goto LABEL_36;
    }
    v145 += v154;
    goto LABEL_10;
  }
LABEL_36:
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_92E2A, "err ", v7 + 340, "inst_info_read", v9);
  v193 = -12;
LABEL_39:
  put_inst(v7);
  return v193;
}
