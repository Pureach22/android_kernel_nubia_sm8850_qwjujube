__int64 __fastcall dp_wfds_work(
        _QWORD **a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 *v10; // x20
  __int64 v11; // x21
  int v12; // w8
  _QWORD **v13; // x26
  _QWORD *v14; // x23
  __int64 v15; // x28
  __int64 v16; // x24
  __int64 v17; // x25
  _QWORD *v18; // x20
  _QWORD *v19; // x0
  _QWORD *v20; // x8
  __int64 v21; // x10
  __int64 v22; // x27
  char v23; // w9
  __int64 v24; // x0
  __int64 v25; // x2
  __int64 v26; // x8
  __int64 v27; // x20
  __int64 v28; // x0
  __int64 v29; // x1
  _QWORD *v30; // x8
  __int64 v31; // x9
  __int64 v32; // x23
  _DWORD *v33; // x0
  int v34; // w8
  unsigned __int8 v35; // w26
  _DWORD *v36; // x25
  unsigned __int16 direct_link_ce_dest_srng_buffers; // w0
  unsigned int v38; // w8
  unsigned __int16 v39; // w24
  __int64 v40; // x20
  __int64 v41; // x1
  __int64 v42; // x0
  __int64 v43; // x2
  __int64 v44; // x27
  __int64 v45; // x24
  _DWORD *v46; // x8
  __int64 v47; // x28
  __int64 v48; // x20
  _QWORD *v49; // x27
  __int64 v50; // x1
  __int64 v51; // x0
  __int64 v52; // x2
  __int64 v53; // x21
  _QWORD **v54; // x8
  unsigned int v55; // w0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int v64; // w24
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x0
  __int64 v74; // x2
  __int64 v75; // x8
  __int64 v76; // x20
  __int64 v77; // x0
  __int64 v78; // x1
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  char v87; // w9
  int v88; // w8
  int v89; // w9
  int v90; // w10
  __int64 v91; // x2
  unsigned __int16 v92; // w9
  __int64 v93; // x0
  _QWORD *v94; // x24
  __int64 v95; // x20
  __int64 v96; // x0
  __int64 v97; // x1
  __int64 v98; // x2
  __int16 v99; // w8
  unsigned __int16 v100; // w9
  __int64 v101; // x0
  __int64 v102; // x24
  __int64 v103; // x0
  __int64 v104; // x1
  __int64 v105; // x2
  __int16 v106; // w8
  unsigned __int16 v107; // w9
  __int64 v108; // x0
  __int64 v109; // x24
  __int64 v110; // x0
  __int64 v111; // x1
  __int64 v112; // x24
  int v113; // w10
  int v114; // w11
  __int64 v115; // x2
  bool v116; // zf
  __int16 v117; // w9
  int v118; // w8
  unsigned __int16 v119; // w8
  char v120; // w9
  __int64 v121; // x10
  __int64 v122; // x0
  __int64 v123; // x0
  __int64 v124; // x1
  _QWORD *v125; // x12
  __int64 v126; // x11
  __int64 v127; // x10
  _QWORD *v128; // x9
  __int64 v129; // x10
  __int64 v130; // x9
  _QWORD *v131; // x8
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  __int64 v140; // x2
  __int64 v141; // x3
  char v142; // w8
  __int64 v143; // x0
  __int64 v144; // x20
  __int64 v145; // x0
  __int64 v146; // x1
  __int64 v147; // x0
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  __int64 v156; // x2
  __int64 v157; // x0
  __int64 v158; // x20
  __int64 v159; // x0
  __int64 v160; // x3
  __int64 v161; // x1
  int v162; // w4
  double v163; // d0
  double v164; // d1
  double v165; // d2
  double v166; // d3
  double v167; // d4
  double v168; // d5
  double v169; // d6
  double v170; // d7
  int v171; // w4
  unsigned int v172; // w24
  double v173; // d0
  double v174; // d1
  double v175; // d2
  double v176; // d3
  double v177; // d4
  double v178; // d5
  double v179; // d6
  double v180; // d7
  double v181; // d0
  double v182; // d1
  double v183; // d2
  double v184; // d3
  double v185; // d4
  double v186; // d5
  double v187; // d6
  double v188; // d7
  __int64 result; // x0
  __int64 v190; // [xsp+0h] [xbp-180h]
  __int64 v191; // [xsp+10h] [xbp-170h]
  __int64 v192; // [xsp+18h] [xbp-168h]
  _QWORD *v193; // [xsp+20h] [xbp-160h]
  _DWORD *v194; // [xsp+20h] [xbp-160h]
  _QWORD *v195; // [xsp+20h] [xbp-160h]
  __int64 v196; // [xsp+20h] [xbp-160h]
  unsigned __int16 v197; // [xsp+2Ch] [xbp-154h] BYREF
  __int64 v198; // [xsp+30h] [xbp-150h] BYREF
  _QWORD *v199; // [xsp+38h] [xbp-148h] BYREF
  __int64 v200; // [xsp+40h] [xbp-140h] BYREF
  __int64 v201; // [xsp+48h] [xbp-138h]
  __int64 v202; // [xsp+50h] [xbp-130h]
  __int64 v203; // [xsp+58h] [xbp-128h]
  __int64 v204; // [xsp+60h] [xbp-120h]
  _QWORD *v205; // [xsp+68h] [xbp-118h]
  __int64 v206; // [xsp+70h] [xbp-110h]
  __int64 v207; // [xsp+78h] [xbp-108h]
  __int64 v208; // [xsp+80h] [xbp-100h]
  _QWORD v209[2]; // [xsp+88h] [xbp-F8h] BYREF
  __int64 v210; // [xsp+98h] [xbp-E8h]
  __int64 v211; // [xsp+A0h] [xbp-E0h]
  __int64 v212; // [xsp+A8h] [xbp-D8h]
  __int64 v213; // [xsp+B0h] [xbp-D0h]
  __int64 v214; // [xsp+B8h] [xbp-C8h]
  __int64 v215; // [xsp+C0h] [xbp-C0h]
  __int64 v216; // [xsp+C8h] [xbp-B8h]
  __int64 v217; // [xsp+D0h] [xbp-B0h]
  __int64 v218; // [xsp+D8h] [xbp-A8h]
  __int64 v219; // [xsp+E0h] [xbp-A0h] BYREF
  __int64 v220; // [xsp+E8h] [xbp-98h]
  __int64 v221; // [xsp+F0h] [xbp-90h]
  __int64 v222; // [xsp+F8h] [xbp-88h]
  __int64 v223; // [xsp+100h] [xbp-80h]
  __int64 v224; // [xsp+108h] [xbp-78h]
  __int64 v225; // [xsp+110h] [xbp-70h]
  __int64 v226; // [xsp+118h] [xbp-68h]
  __int64 v227; // [xsp+120h] [xbp-60h]
  _QWORD *v228; // [xsp+128h] [xbp-58h]
  __int64 v229; // [xsp+130h] [xbp-50h]
  __int64 v230; // [xsp+138h] [xbp-48h]
  __int64 v231; // [xsp+140h] [xbp-40h]
  __int64 v232; // [xsp+148h] [xbp-38h]
  __int64 v233; // [xsp+150h] [xbp-30h]
  _QWORD *v234; // [xsp+158h] [xbp-28h]
  __int64 v235; // [xsp+160h] [xbp-20h]
  __int64 v236; // [xsp+168h] [xbp-18h]
  __int64 v237; // [xsp+170h] [xbp-10h]

  v237 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x45u, 8u, "%s: entry", a2, a3, a4, a5, a6, a7, a8, a9, "dp_wfds_work");
  qdf_spinlock_acquire((__int64)(a1 + 8));
  v10 = (__int64 *)(a1 + 10);
  v11 = (__int64)a1[10];
  if ( (_QWORD **)v11 != a1 + 10 && v11 )
  {
    do
    {
      qdf_list_remove_node((__int64)v10, (_QWORD *)v11);
      qdf_spinlock_release((__int64)(a1 + 8));
      v12 = *(_DWORD *)(v11 + 16);
      switch ( v12 )
      {
        case 2:
          v54 = (_QWORD **)*a1;
          LODWORD(v219) = 0;
          v55 = wlan_qmi_wfds_ipcc_map_n_cfg_msg(**v54, &v219);
          if ( v55 )
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: IPCC map n cfg message send failed %d",
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              "dp_wfds_ipcc_map_n_cfg_msg",
              v55);
          else
            *((_DWORD *)a1 + 26) = 4;
          break;
        case 1:
          if ( a1 )
          {
            v30 = (_QWORD *)**a1;
            if ( *v30 )
            {
              v31 = *(_QWORD *)(*v30 + 2808LL);
              if ( v31 )
              {
                v192 = *(_QWORD *)(v31 + 64);
                if ( v192 )
                {
                  v32 = v30[2];
                  if ( v32 )
                  {
                    v33 = (_DWORD *)_qdf_mem_malloc(0x4008u, "dp_wfds_req_mem_msg", 283);
                    if ( v33 )
                    {
                      v34 = *((_DWORD *)a1 + 27);
                      v190 = v11;
                      v191 = (__int64)v33;
                      *v33 = v34;
                      if ( v34 )
                      {
                        v35 = 0;
                        v194 = v33 + 2;
                        v36 = v33 + 1026;
                        do
                        {
                          if ( v35 == 2 )
                          {
                            v219 = 0;
                            LODWORD(v209[0]) = 0;
                            direct_link_ce_dest_srng_buffers = hif_get_direct_link_ce_dest_srng_buffers(v192);
                            v38 = 0x1000u / LODWORD(v209[0]);
                            *(_DWORD *)(v191 + 4108) = direct_link_ce_dest_srng_buffers;
                            *(_WORD *)(v191 + 4104) = v38;
                            if ( direct_link_ce_dest_srng_buffers )
                            {
                              v39 = direct_link_ce_dest_srng_buffers;
                              v40 = 8LL * direct_link_ce_dest_srng_buffers - 8;
                              while ( v39 <= 0xFFu )
                              {
                                *(_QWORD *)((char *)v36 + v40 + 8) = *(_QWORD *)(v219 + v40);
                                if ( (*((_BYTE *)a1 + 244) & 1) == 0 )
                                {
                                  v42 = *(_QWORD *)(v32 + 40);
                                  v43 = *(_QWORD *)(v219 + v40);
                                  if ( *(_BYTE *)(v32 + 608) == 1 && *(_QWORD *)(v32 + 616) )
                                  {
                                    v44 = *(_QWORD *)(v32 + 40);
                                    v41 = iommu_iova_to_phys(*(_QWORD *)(v32 + 616), *(_QWORD *)(v219 + v40));
                                    v42 = v44;
                                    v43 = *(_QWORD *)(v219 + v40);
                                  }
                                  else
                                  {
                                    v41 = *(_QWORD *)(v219 + v40);
                                  }
                                  pld_audio_smmu_map(v42, v41, v43, LODWORD(v209[0]));
                                }
                                v40 -= 8;
                                if ( v40 == -8 )
                                  goto LABEL_25;
                              }
                              goto LABEL_136;
                            }
LABEL_25:
                            _qdf_mem_free(v219);
                          }
                          else
                          {
                            if ( v35 > 7u )
                              goto LABEL_136;
                            v45 = (__int64)&a1[14][5 * v35];
                            v46 = &v194[512 * (unsigned __int64)v35];
                            v47 = *(unsigned __int16 *)(v45 + 2);
                            *(_WORD *)v46 = *(_WORD *)v45;
                            v46[1] = v47;
                            if ( (_DWORD)v47 )
                            {
                              v48 = 24LL * (unsigned int)v47 - 8;
                              v49 = &v194[512 * (unsigned __int64)v35 + 2 * v47];
                              while ( (unsigned int)v47 <= 0xFF )
                              {
                                *v49 = *(_QWORD *)(*(_QWORD *)(v45 + 8) + v48);
                                if ( (*((_BYTE *)a1 + 244) & 1) == 0 )
                                {
                                  v51 = *(_QWORD *)(v32 + 40);
                                  v52 = *(_QWORD *)(*(_QWORD *)(v45 + 8) + v48);
                                  if ( *(_BYTE *)(v32 + 608) == 1 && *(_QWORD *)(v32 + 616) )
                                  {
                                    v53 = *(_QWORD *)(v32 + 40);
                                    v50 = iommu_iova_to_phys(*(_QWORD *)(v32 + 616), v52);
                                    v51 = v53;
                                    v52 = *(_QWORD *)(*(_QWORD *)(v45 + 8) + v48);
                                  }
                                  else
                                  {
                                    v50 = *(_QWORD *)(*(_QWORD *)(v45 + 8) + v48);
                                  }
                                  pld_audio_smmu_map(v51, v50, v52, *(_QWORD *)(v45 + 24));
                                }
                                v48 -= 24;
                                --v49;
                                if ( v48 == -8 )
                                  goto LABEL_26;
                              }
LABEL_136:
                              __break(0x5512u);
                            }
                          }
LABEL_26:
                          ++v35;
                        }
                        while ( *((_DWORD *)a1 + 27) > (unsigned int)v35 );
                      }
                      v64 = wlan_qmi_wfds_send_req_mem_msg(*(_QWORD *)**a1, v191);
                      _qdf_mem_free(v191);
                      if ( v64 )
                        qdf_trace_msg(
                          0x45u,
                          2u,
                          "%s: Memory request message send failed %d",
                          v65,
                          v66,
                          v67,
                          v68,
                          v69,
                          v70,
                          v71,
                          v72,
                          "dp_wfds_req_mem_msg",
                          v64);
                      else
                        *((_DWORD *)a1 + 26) = 3;
                      v11 = v190;
                      v10 = (__int64 *)(a1 + 10);
                    }
                  }
                }
              }
            }
          }
          break;
        case 0:
          v13 = (_QWORD **)*a1;
          v14 = (_QWORD *)**a1;
          if ( *v14 )
            v15 = *(_QWORD *)(*v14 + 2808LL);
          else
            v15 = 0;
          v207 = 0;
          v208 = 0;
          v205 = nullptr;
          v206 = 0;
          v203 = 0;
          v204 = 0;
          v201 = 0;
          v202 = 0;
          v200 = 0;
          v235 = 0;
          v236 = 0;
          v233 = 0;
          v234 = nullptr;
          v231 = 0;
          v232 = 0;
          v229 = 0;
          v230 = 0;
          v227 = 0;
          v228 = nullptr;
          v225 = 0;
          v226 = 0;
          v223 = 0;
          v224 = 0;
          v221 = 0;
          v222 = 0;
          v219 = 0;
          v220 = 0;
          v217 = 0;
          v218 = 0;
          v215 = 0;
          v216 = 0;
          v213 = 0;
          v214 = 0;
          v211 = 0;
          v212 = 0;
          v209[1] = 0;
          v210 = 0;
          v209[0] = 0;
          v198 = 0;
          v199 = nullptr;
          v197 = 0;
          if ( v15 )
          {
            v16 = *(_QWORD *)(v15 + 64);
            if ( v16 )
            {
              v17 = v14[2];
              if ( v17 )
              {
                v18 = *(_QWORD **)(v16 + 2560);
                if ( v18 )
                {
                  hal_get_meminfo(*(__int64 **)(v16 + 2560), (__int64)&v200);
                  v19 = (_QWORD *)_qdf_mem_malloc(0x150u, "dp_wfds_send_config_msg", 70);
                  if ( v19 )
                  {
                    v20 = v205;
                    v21 = v201;
                    v22 = (__int64)v19;
                    v19[26] = v207;
                    v19[24] = v20;
                    v19[25] = 948;
                    v19[27] = 216;
                    v19[29] = v21;
                    a1[16] = v20;
                    v23 = *((_BYTE *)a1 + 244);
                    *((_WORD *)a1 + 68) = v19[25];
                    a1[18] = (_QWORD *)v19[26];
                    *((_WORD *)a1 + 76) = v19[27];
                    if ( (v23 & 1) == 0 )
                    {
                      v24 = *(_QWORD *)(v17 + 40);
                      v25 = *(_QWORD *)(v22 + 192);
                      if ( *(_BYTE *)(v17 + 608) == 1 && (v26 = *(_QWORD *)(v17 + 616)) != 0 )
                      {
                        v193 = v18;
                        v27 = *(_QWORD *)(v17 + 40);
                        v28 = iommu_iova_to_phys(v26, v25);
                        v25 = *(_QWORD *)(v22 + 192);
                        v29 = v28;
                        v24 = v27;
                        v18 = v193;
                      }
                      else
                      {
                        v29 = *(_QWORD *)(v22 + 192);
                      }
                      pld_audio_smmu_map(v24, v29, v25, *(_QWORD *)(v22 + 200));
                      if ( (*((_BYTE *)a1 + 244) & 1) == 0 )
                      {
                        v73 = *(_QWORD *)(v17 + 40);
                        v74 = *(_QWORD *)(v22 + 208);
                        if ( *(_BYTE *)(v17 + 608) == 1 && (v75 = *(_QWORD *)(v17 + 616)) != 0 )
                        {
                          v195 = v18;
                          v76 = *(_QWORD *)(v17 + 40);
                          v77 = iommu_iova_to_phys(v75, v74);
                          v74 = *(_QWORD *)(v22 + 208);
                          v78 = v77;
                          v73 = v76;
                          v18 = v195;
                        }
                        else
                        {
                          v78 = *(_QWORD *)(v22 + 208);
                        }
                        pld_audio_smmu_map(v73, v78, v74, *(_QWORD *)(v22 + 216));
                      }
                    }
                    *(_DWORD *)v22 = 3;
                    if ( (unsigned int)hif_get_direct_link_ce_srng_info(v16) )
                    {
                      qdf_trace_msg(
                        0x45u,
                        2u,
                        "%s: Direct Link CE srng info get failed",
                        v79,
                        v80,
                        v81,
                        v82,
                        v83,
                        v84,
                        v85,
                        v86,
                        "dp_wfds_send_config_msg");
                      _qdf_mem_free(v22);
                    }
                    else
                    {
                      *(_BYTE *)(v22 + 8) = v219;
                      v87 = v220;
                      *(_DWORD *)(v22 + 12) = BYTE1(v219);
                      v88 = BYTE1(v220);
                      *(_BYTE *)(v22 + 16) = v87;
                      v89 = HIDWORD(v220);
                      v90 = v221;
                      *(_DWORD *)(v22 + 20) = v88;
                      *(_DWORD *)(v22 + 24) = v89;
                      *(_DWORD *)(v22 + 28) = v90;
                      v91 = v222;
                      v92 = 4 * v90 * v89;
                      *(_QWORD *)(v22 + 32) = v222;
                      *(_QWORD *)(v22 + 40) = v223;
                      *(_QWORD *)(v22 + 48) = v224;
                      LOBYTE(v88) = *((_BYTE *)a1 + 244);
                      a1[20] = (_QWORD *)v91;
                      *((_WORD *)a1 + 92) = v92;
                      if ( (v88 & 1) == 0 )
                      {
                        v93 = *(_QWORD *)(v17 + 40);
                        if ( *(_BYTE *)(v17 + 608) == 1 && *(_QWORD *)(v17 + 616) )
                        {
                          v94 = v18;
                          v95 = *(_QWORD *)(v17 + 40);
                          v96 = iommu_iova_to_phys(*(_QWORD *)(v17 + 616), v91);
                          v91 = v222;
                          v92 = *((_WORD *)a1 + 92);
                          v97 = v96;
                          v93 = v95;
                          v18 = v94;
                        }
                        else
                        {
                          v97 = v91;
                        }
                        pld_audio_smmu_map(v93, v97, v91, v92);
                      }
                      *(_BYTE *)(v22 + 56) = v225;
                      *(_DWORD *)(v22 + 60) = BYTE1(v225);
                      *(_BYTE *)(v22 + 64) = v226;
                      *(_DWORD *)(v22 + 68) = BYTE1(v226);
                      *(_DWORD *)(v22 + 72) = HIDWORD(v226);
                      *(_DWORD *)(v22 + 76) = v227;
                      *(_QWORD *)(v22 + 80) = v228;
                      *(_QWORD *)(v22 + 88) = v229;
                      *(_QWORD *)(v22 + 96) = v230;
                      v98 = (__int64)v228;
                      v99 = WORD2(v226) * v227;
                      a1[21] = v228;
                      v100 = 4 * v99;
                      LOBYTE(v99) = *((_BYTE *)a1 + 244);
                      *((_WORD *)a1 + 93) = v100;
                      if ( (v99 & 1) == 0 )
                      {
                        v101 = *(_QWORD *)(v17 + 40);
                        if ( *(_BYTE *)(v17 + 608) == 1 && *(_QWORD *)(v17 + 616) )
                        {
                          v102 = *(_QWORD *)(v17 + 40);
                          v103 = iommu_iova_to_phys(*(_QWORD *)(v17 + 616), v98);
                          v98 = (__int64)v228;
                          v100 = *((_WORD *)a1 + 93);
                          v104 = v103;
                          v101 = v102;
                        }
                        else
                        {
                          v104 = v98;
                        }
                        pld_audio_smmu_map(v101, v104, v98, v100);
                      }
                      *(_BYTE *)(v22 + 104) = v231;
                      *(_DWORD *)(v22 + 108) = BYTE1(v231);
                      *(_BYTE *)(v22 + 112) = v232;
                      *(_DWORD *)(v22 + 116) = BYTE1(v232);
                      *(_DWORD *)(v22 + 120) = HIDWORD(v232);
                      *(_DWORD *)(v22 + 124) = v233;
                      *(_QWORD *)(v22 + 128) = v234;
                      *(_QWORD *)(v22 + 136) = v235;
                      *(_QWORD *)(v22 + 144) = v236;
                      v105 = (__int64)v234;
                      v106 = WORD2(v232) * v233;
                      a1[22] = v234;
                      v107 = 4 * v106;
                      LOBYTE(v106) = *((_BYTE *)a1 + 244);
                      *((_WORD *)a1 + 94) = v107;
                      if ( (v106 & 1) == 0 )
                      {
                        v108 = *(_QWORD *)(v17 + 40);
                        if ( *(_BYTE *)(v17 + 608) == 1 && *(_QWORD *)(v17 + 616) )
                        {
                          v109 = *(_QWORD *)(v17 + 40);
                          v110 = iommu_iova_to_phys(*(_QWORD *)(v17 + 616), v105);
                          v105 = (__int64)v234;
                          v107 = *((_WORD *)a1 + 94);
                          v111 = v110;
                          v108 = v109;
                        }
                        else
                        {
                          v111 = v105;
                        }
                        pld_audio_smmu_map(v108, v111, v105, v107);
                      }
                      v112 = *v13[2];
                      hal_get_srng_params((__int64)v18, v112, (__int64)v209);
                      v113 = HIDWORD(v215);
                      v114 = v210;
                      v115 = v209[0];
                      v116 = (_DWORD)v215 == 0;
                      v117 = WORD2(v215) * v210;
                      *(_BYTE *)(v22 + 152) = BYTE4(v214);
                      v118 = !v116;
                      *(_DWORD *)(v22 + 160) = v114;
                      *(_DWORD *)(v22 + 164) = v113;
                      *(_DWORD *)(v22 + 156) = v118;
                      *(_QWORD *)(v22 + 168) = v115;
                      v119 = 4 * v117;
                      v120 = *((_BYTE *)a1 + 244);
                      a1[24] = (_QWORD *)v115;
                      *((_WORD *)a1 + 100) = v119;
                      if ( (v120 & 1) == 0 )
                      {
                        v121 = *(_QWORD *)(v17 + 40);
                        if ( *(_BYTE *)(v17 + 608) == 1 && (v122 = *(_QWORD *)(v17 + 616)) != 0 )
                        {
                          v196 = *(_QWORD *)(v17 + 40);
                          v123 = iommu_iova_to_phys(v122, v115);
                          v121 = v196;
                          v115 = v209[0];
                          v124 = v123;
                          v119 = *((_WORD *)a1 + 100);
                        }
                        else
                        {
                          v124 = v115;
                        }
                        pld_audio_smmu_map(v121, v124, v115, v119);
                      }
                      if ( *(_DWORD *)(v112 + 116) )
                      {
                        v125 = v18;
                        v126 = 128;
                        v127 = 9252;
                        v128 = v18 + 9253;
                      }
                      else if ( (*(_DWORD *)(v112 + 76) & 0x80000000) != 0 )
                      {
                        v128 = v18 + 9255;
                        v126 = 144;
                        v125 = v18;
                        v127 = 9254;
                      }
                      else
                      {
                        v125 = v18;
                        v126 = 144;
                        v127 = 2;
                        v128 = (_QWORD *)(*v18 + 728LL);
                      }
                      *(_QWORD *)(v22 + 176) = *v128 + *(_QWORD *)(v112 + v126) - v125[v127];
                      if ( *(_DWORD *)(v112 + 116) )
                      {
                        if ( (*(_DWORD *)(v112 + 76) & 0x80000000) != 0 )
                        {
                          v131 = v18 + 9255;
                          v129 = 144;
                          v130 = 9254;
                        }
                        else
                        {
                          v129 = 144;
                          v130 = 2;
                          v131 = (_QWORD *)(*v18 + 728LL);
                        }
                      }
                      else
                      {
                        v131 = v18 + 9253;
                        v129 = 128;
                        v130 = 9252;
                      }
                      *(_QWORD *)(v22 + 184) = *v131 + *(_QWORD *)(v112 + v129) - v18[v130];
                      *(_DWORD *)(v22 + 224) = *(unsigned __int16 *)(v15 + 1138);
                      *(_DWORD *)(v22 + 228) = (unsigned __int8)(*(_DWORD *)(v15 + 20060) + 1);
                      *(_DWORD *)(v22 + 240) = pld_get_pci_slot(*(_QWORD *)(v17 + 40));
                      *(_DWORD *)(v22 + 244) = *((_DWORD *)v13 + 2);
                      pld_get_fw_lpass_shared_mem(*(_QWORD *)(v17 + 40), (__int64)&v199, (__int64)&v198);
                      v140 = (__int64)v199;
                      if ( v199 )
                      {
                        v141 = v198;
                        v142 = *((_BYTE *)a1 + 244);
                        a1[29] = v199;
                        *((_DWORD *)a1 + 60) = v141;
                        if ( (v142 & 1) == 0 )
                        {
                          v143 = *(_QWORD *)(v17 + 40);
                          if ( *(_BYTE *)(v17 + 608) == 1 && *(_QWORD *)(v17 + 616) )
                          {
                            v144 = *(_QWORD *)(v17 + 40);
                            v145 = iommu_iova_to_phys(*(_QWORD *)(v17 + 616), v140);
                            v141 = v198;
                            v140 = (__int64)v199;
                            v146 = v145;
                            v143 = v144;
                          }
                          else
                          {
                            v146 = v140;
                          }
                          pld_audio_smmu_map(v143, v146, v140, v141);
                          v140 = (__int64)v199;
                        }
                        *(_QWORD *)(v22 + 304) = v140;
                        *(_BYTE *)(v22 + 296) = 1;
                        *(_BYTE *)(v22 + 312) = 1;
                        *(_DWORD *)(v22 + 316) = 4;
                        *(_BYTE *)(v22 + 272) = 1;
                        *(_QWORD *)(v22 + 280) = v140 + 4;
                        *(_BYTE *)(v22 + 288) = 1;
                        *(_DWORD *)(v22 + 292) = 4;
                      }
                      else
                      {
                        qdf_trace_msg(
                          0x45u,
                          2u,
                          "%s: Unable to get fw_lpass shared memory info",
                          v132,
                          v133,
                          v134,
                          v135,
                          v136,
                          v137,
                          v138,
                          v139,
                          "dp_wfds_send_config_msg");
                      }
                      *((_DWORD *)a1 + 56) = 4;
                      v147 = _qdf_mem_alloc_consistent(
                               v17,
                               *(_QWORD *)(v17 + 40),
                               4,
                               (__int64)(a1 + 27),
                               "dp_wfds_send_config_msg",
                               202);
                      a1[26] = (_QWORD *)v147;
                      if ( v147 )
                      {
                        *(_BYTE *)(v22 + 248) = 1;
                        v156 = (__int64)a1[27];
                        *(_BYTE *)(v22 + 264) = 1;
                        *(_DWORD *)(v22 + 268) = 4;
                        *(_QWORD *)(v22 + 256) = v156;
                        if ( (*((_BYTE *)a1 + 244) & 1) == 0 )
                        {
                          v157 = *(_QWORD *)(v17 + 40);
                          if ( *(_BYTE *)(v17 + 608) == 1 && *(_QWORD *)(v17 + 616) )
                          {
                            v158 = *(_QWORD *)(v17 + 40);
                            v159 = iommu_iova_to_phys(*(_QWORD *)(v17 + 616), v156);
                            v156 = *(_QWORD *)(v22 + 256);
                            v160 = *(unsigned int *)(v22 + 268);
                            v161 = v159;
                            v157 = v158;
                          }
                          else
                          {
                            v160 = 4;
                            v161 = v156;
                          }
                          pld_audio_smmu_map(v157, v161, v156, v160);
                        }
                      }
                      else
                      {
                        qdf_trace_msg(
                          0x45u,
                          2u,
                          "%s: Unable to allocate apss_lpass shared memory",
                          v148,
                          v149,
                          v150,
                          v151,
                          v152,
                          v153,
                          v154,
                          v155,
                          "dp_wfds_send_config_msg");
                      }
                      v162 = *(_DWORD *)(v17 + 592);
                      if ( v162 == 6 )
                      {
                        *(_BYTE *)(v22 + 320) = 1;
                        *(_DWORD *)(v22 + 324) = 1;
                      }
                      else if ( v162 )
                      {
                        qdf_trace_msg(
                          0x45u,
                          2u,
                          "%s: Direct link not supported for %d bus type",
                          v148,
                          v149,
                          v150,
                          v151,
                          v152,
                          v153,
                          v154,
                          v155,
                          "dp_wfds_send_config_msg");
                      }
                      else
                      {
                        *(_DWORD *)(v22 + 324) = 0;
                        *(_BYTE *)(v22 + 320) = 1;
                      }
                      if ( (unsigned int)pld_get_direct_link_sid(*(_QWORD *)(v17 + 40), (__int64)&v197) )
                      {
                        qdf_trace_msg(
                          0x45u,
                          2u,
                          "%s: Unable to get LPASS SID value",
                          v163,
                          v164,
                          v165,
                          v166,
                          v167,
                          v168,
                          v169,
                          v170,
                          "dp_wfds_send_config_msg");
                      }
                      else
                      {
                        v171 = v197;
                        *(_BYTE *)(v22 + 328) = 1;
                        *(_DWORD *)(v22 + 332) = v171;
                        qdf_trace_msg(
                          0x45u,
                          5u,
                          "%s: Direct link LPASS SID value:%u",
                          v163,
                          v164,
                          v165,
                          v166,
                          v167,
                          v168,
                          v169,
                          v170,
                          "dp_wfds_send_config_msg");
                      }
                      v172 = wlan_qmi_wfds_send_config_msg(*v14, v22);
                      _qdf_mem_free(v22);
                      if ( v172 )
                        qdf_trace_msg(
                          0x45u,
                          2u,
                          "%s: Configuration message send failed %d",
                          v173,
                          v174,
                          v175,
                          v176,
                          v177,
                          v178,
                          v179,
                          v180,
                          "dp_wfds_send_config_msg",
                          v172);
                      else
                        *((_DWORD *)a1 + 26) = 2;
                    }
                  }
                }
              }
            }
          }
          v10 = (__int64 *)(a1 + 10);
          break;
      }
      _qdf_mem_free(v11);
      qdf_spinlock_acquire((__int64)(a1 + 8));
      v11 = *v10;
    }
    while ( (__int64 *)*v10 != v10 && v11 );
  }
  qdf_spinlock_release((__int64)(a1 + 8));
  result = qdf_trace_msg(0x45u, 8u, "%s: exit", v181, v182, v183, v184, v185, v186, v187, v188, "dp_wfds_work");
  _ReadStatusReg(SP_EL0);
  return result;
}
