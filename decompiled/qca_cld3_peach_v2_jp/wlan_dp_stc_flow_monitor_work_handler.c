unsigned __int64 __fastcall wlan_dp_stc_flow_monitor_work_handler(__int64 **a1, __int64 a2)
{
  __int64 *v3; // x26
  __int64 *v4; // x25
  __int64 v5; // x21
  unsigned __int64 result; // x0
  __int64 v7; // x1
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 *v16; // x8
  int v17; // w11
  _QWORD **v18; // x28
  int v19; // w10
  unsigned __int64 v20; // x8
  char v21; // w2
  int v22; // w9
  unsigned __int8 v23; // w11
  __int64 v24; // x4
  unsigned __int64 v25; // x3
  unsigned __int64 v26; // x3
  int v27; // w3
  __int64 v28; // x5
  __int64 v29; // x6
  __int16 v30; // w7
  _QWORD **v31; // x2
  __int64 v32; // x5
  int v33; // w6
  int v34; // w7
  __int16 v35; // w4
  int v36; // w6
  _QWORD **v37; // x4
  int *v38; // x4
  int v39; // w5
  int v40; // t1
  __int64 v41; // x12
  char v42; // w20
  _QWORD **v43; // x21
  __int64 v45; // x23
  __int64 v46; // x8
  unsigned int *v47; // x9
  __int64 *v48; // x26
  unsigned int v49; // w8
  unsigned int *v50; // x20
  int v51; // w8
  int v52; // w8
  int v53; // w8
  int v54; // w25
  unsigned int v55; // w9
  unsigned int v56; // w9
  __int64 v57; // x10
  int v58; // w3
  unsigned int v59; // w4
  unsigned int v60; // w10
  __int64 v61; // x9
  unsigned int *v62; // x8
  __int64 v63; // x9
  int v64; // w11
  char v65; // w12
  char v66; // w10
  __int16 v67; // w11
  unsigned __int16 v68; // w0
  unsigned __int16 v69; // w26
  __int16 v70; // w0
  unsigned __int16 v71; // w26
  __int16 v72; // w0
  unsigned __int16 v73; // w26
  __int16 v74; // w0
  __int64 v75; // x0
  __int64 v76; // x1
  unsigned int v77; // w28
  _WORD *v78; // x26
  __int64 v79; // x0
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  unsigned int v88; // w8
  __int64 v89; // x8
  __int64 v90; // x8
  unsigned int v96; // w8
  unsigned int v99; // w9
  unsigned int v102; // w9
  unsigned int v105; // w9
  __int64 v106; // x0
  __int64 v107; // x3
  char v108; // w8
  __int64 v109; // x21
  __int64 v110; // x27
  int v111; // w8
  __int64 v112; // x27
  int v113; // t1
  int v114; // w8
  int v115; // w9
  __int64 (__fastcall *v116)(__int64, __int64, __int64); // x9
  __int64 v117; // x0
  __int64 v118; // x2
  int *v119; // x20
  __int64 (__fastcall *v120)(__int64, __int64, __int64); // x9
  __int64 v121; // x0
  __int64 v122; // x2
  int v123; // w8
  int v124; // w8
  __int64 v125; // x8
  int v126; // w9
  __int64 *v127; // x8
  unsigned int v128; // w10
  int v129; // w2
  __int64 (__fastcall *v130)(__int64, __int64, __int64); // x10
  __int64 v131; // x0
  __int64 v132; // x2
  int v134; // w9
  __int64 v135; // x25
  __int64 v136; // x26
  __int64 v137; // x24
  unsigned int v138; // w28
  unsigned int *v139; // x20
  unsigned int v140; // w8
  unsigned int v141; // w9
  __int64 v142; // x8
  int v143; // w9
  unsigned int *v144; // x24
  unsigned __int16 v145; // w0
  unsigned __int16 v146; // w23
  __int16 v147; // w0
  unsigned __int16 v148; // w23
  __int16 v149; // w0
  unsigned __int16 v150; // w23
  __int16 v151; // w0
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  __int64 v160; // x0
  __int64 v161; // x1
  unsigned int v163; // w9
  int v164; // w9
  unsigned __int64 v167; // x9
  unsigned __int64 v170; // x10
  unsigned __int64 v173; // x10
  unsigned __int64 i; // x27
  __int64 *v175; // x21
  __int64 v177; // x8
  _BYTE *v178; // x8
  __int64 *v179; // x8
  __int64 v180; // x9
  _BYTE *v181; // x8
  __int64 *v182; // x24
  __int64 *v183; // x25
  __int64 v184; // x23
  double v185; // d0
  double v186; // d1
  double v187; // d2
  double v188; // d3
  double v189; // d4
  double v190; // d5
  double v191; // d6
  double v192; // d7
  void (__fastcall *v193)(__int64, __int128 *, __int64); // x8
  __int16 v194; // w24
  int v195; // w23
  __int64 *v196; // x20
  __int64 v197; // x9
  char v198; // w8
  __int64 v199; // x24
  unsigned __int64 v200; // x23
  __int64 *v201; // x20
  int v202; // w8
  __int64 *v203; // x21
  __int64 v204; // x23
  int v205; // w9
  __int64 (__fastcall *v206)(__int64, __int128 *, __int64); // x8
  unsigned __int64 v207; // x8
  unsigned __int64 v208; // x8
  unsigned __int64 v209; // x25
  unsigned __int64 v210; // x8
  unsigned __int64 v211; // x20
  unsigned __int64 v212; // x9
  unsigned __int64 v213; // x9
  __int64 v214; // x8
  __int64 v215; // x9
  __int64 *v216; // x21
  __int64 v217; // x23
  int v218; // w9
  __int64 (__fastcall *v219)(__int64, __int128 *, __int64); // x8
  unsigned int v221; // w8
  __int64 v222; // x21
  _QWORD **v223; // x26
  double v224; // d0
  double v225; // d1
  double v226; // d2
  double v227; // d3
  double v228; // d4
  double v229; // d5
  double v230; // d6
  double v231; // d7
  unsigned __int64 v232; // x28
  __int64 *v233; // x9
  __int64 v234; // x8
  __int64 v235; // x20
  __int64 v236; // x24
  __int64 v237; // x12
  __int64 v238; // x11
  __int64 *v239; // x11
  __int64 *v240; // x12
  __int64 v241; // x10
  __int64 v242; // x13
  __int64 v243; // x10
  __int64 *v244; // x8
  __int64 v245; // x8
  __int64 v246; // x0
  __int64 v247; // x8
  unsigned int (*v248)(void); // x8
  __int64 v249; // x25
  __int64 *v250; // x8
  __int64 v251; // x8
  __int64 v252; // x8
  unsigned __int64 v253; // x8
  unsigned __int64 v254; // x8
  unsigned __int64 v255; // x8
  int v256; // w8
  __int64 *v257; // x20
  unsigned int v258; // w8
  unsigned int v259; // w8
  int v260; // w24
  __int64 (__fastcall *v261)(__int64, __int128 *); // x8
  __int64 v262; // x0
  double v263; // d0
  double v264; // d1
  double v265; // d2
  double v266; // d3
  double v267; // d4
  double v268; // d5
  double v269; // d6
  double v270; // d7
  unsigned __int64 v273; // x9
  unsigned __int64 v276; // x8
  unsigned __int64 v279; // x8
  __int64 v280; // [xsp+0h] [xbp-290h]
  __int64 *v281; // [xsp+18h] [xbp-278h]
  _WORD *v282; // [xsp+28h] [xbp-268h]
  _DWORD *v283; // [xsp+38h] [xbp-258h]
  int v284; // [xsp+38h] [xbp-258h]
  __int64 *v285; // [xsp+40h] [xbp-250h]
  __int64 v286; // [xsp+48h] [xbp-248h]
  _QWORD **v287; // [xsp+48h] [xbp-248h]
  unsigned __int64 v288; // [xsp+50h] [xbp-240h]
  _WORD v289[2]; // [xsp+5Ch] [xbp-234h] BYREF
  _QWORD v290[16]; // [xsp+60h] [xbp-230h] BYREF
  _BYTE v291[112]; // [xsp+E0h] [xbp-1B0h] BYREF
  _QWORD v292[2]; // [xsp+150h] [xbp-140h]
  _BYTE v293[32]; // [xsp+160h] [xbp-130h] BYREF
  __int128 v294; // [xsp+180h] [xbp-110h] BYREF
  __int64 v295; // [xsp+190h] [xbp-100h]
  __int64 v296; // [xsp+198h] [xbp-F8h]
  __int64 v297; // [xsp+1A0h] [xbp-F0h]
  __int64 v298; // [xsp+1A8h] [xbp-E8h]
  __int64 v299; // [xsp+1B0h] [xbp-E0h]
  __int64 v300; // [xsp+1B8h] [xbp-D8h]
  __int64 v301; // [xsp+1C0h] [xbp-D0h]
  __int64 v302; // [xsp+1C8h] [xbp-C8h]
  __int64 v303; // [xsp+1D0h] [xbp-C0h]
  __int64 v304; // [xsp+1D8h] [xbp-B8h]
  __int64 v305; // [xsp+1E0h] [xbp-B0h]
  __int64 v306; // [xsp+1E8h] [xbp-A8h]
  __int64 v307; // [xsp+1F0h] [xbp-A0h]
  __int64 v308; // [xsp+1F8h] [xbp-98h]
  __int64 v309; // [xsp+200h] [xbp-90h]
  __int64 v310; // [xsp+208h] [xbp-88h]
  __int64 v311; // [xsp+210h] [xbp-80h]
  __int64 v312; // [xsp+218h] [xbp-78h]
  __int64 v313; // [xsp+220h] [xbp-70h]
  __int64 v314; // [xsp+228h] [xbp-68h]
  __int64 v315; // [xsp+230h] [xbp-60h]
  __int64 v316; // [xsp+238h] [xbp-58h]
  __int64 v317; // [xsp+240h] [xbp-50h]
  __int64 v318; // [xsp+248h] [xbp-48h]
  __int64 v319; // [xsp+250h] [xbp-40h]
  __int64 v320; // [xsp+258h] [xbp-38h]
  __int64 v321; // [xsp+260h] [xbp-30h]
  __int64 v322; // [xsp+268h] [xbp-28h]
  __int64 v323; // [xsp+270h] [xbp-20h]
  __int64 v324; // [xsp+278h] [xbp-18h]
  __int64 v325; // [xsp+280h] [xbp-10h]

  v325 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v4 = a1[803];
  v5 = (*a1)[185];
  result = sched_clock(a1, a2);
  v16 = a1[800];
  v288 = result;
  v285 = v4;
  if ( *(_DWORD *)v16 == 128 )
    goto LABEL_84;
  v17 = *((_DWORD *)v16 + 1);
  if ( !*(_WORD *)(v5 + 32) )
    goto LABEL_84;
  v18 = a1 + 804;
  v19 = 32 - *((_DWORD *)v16 + 3);
  v20 = 0;
  v21 = 0;
  v22 = 0;
  v23 = 96 - v17;
  result = 2;
  v7 = 3;
  while ( v20 <= 0x7F && (unsigned __int8)v19 | v23 )
  {
    v24 = *(_QWORD *)v3[185] + 336LL * (unsigned __int8)v22;
    if ( *(_BYTE *)(v24 + 40) )
    {
      if ( !*(_BYTE *)(v24 + 322) && !*(_BYTE *)(v24 + 323) && *(__int16 *)(v24 + 36) != -1 )
      {
        v25 = v288 - *(_QWORD *)(v24 + 248);
        if ( v25 >= 0xB2D05E00 )
        {
          v26 = 1000000000LL * *(_QWORD *)(v24 + 280) / v25;
          if ( v26 >= 2 )
          {
            if ( v26 >= 0xF )
              v27 = 56;
            else
              v27 = 24;
            v28 = (*a1)[369];
            if ( v28 )
            {
              v29 = 0;
              v30 = 0;
              while ( !*(_BYTE *)(v28 + v29 + 50)
                   || *(_BYTE *)(v28 + v29 + 162)
                   || *(_BYTE *)(v28 + v29 + 163)
                   || *(_QWORD *)(v28 + v29 + 168) != *(_QWORD *)(v24 + 136) )
              {
                v29 += 192;
                ++v30;
                if ( v29 == 49152 )
                  goto LABEL_25;
              }
              if ( v23 )
              {
                v31 = &v18[3 * v20];
                v32 = v28 + v29;
                v33 = *(_DWORD *)(v24 + 240);
                LODWORD(v32) = *(_DWORD *)(v32 + 104);
                --v23;
                *((_WORD *)v31 + 4) = v30;
                v34 = *((_DWORD *)v31 + 1);
                *((_DWORD *)v31 + 3) = v32;
                *((_DWORD *)v31 + 4) = v33;
                *((_WORD *)v31 + 5) = v22;
                *((_DWORD *)v31 + 1) = v34 | 7;
                v35 = *(_WORD *)(v24 + 36);
                *((_DWORD *)v31 + 5) = 3;
                goto LABEL_28;
              }
              v23 = 0;
            }
            else
            {
LABEL_25:
              if ( (_BYTE)v19 )
              {
                if ( *(_BYTE *)(v24 + 41) )
                {
                  v31 = &v18[3 * v20];
                  LOBYTE(v19) = v19 - 1;
                  v36 = *((_DWORD *)v31 + 1);
                  *((_DWORD *)v31 + 4) = *(_DWORD *)(v24 + 240);
                  *((_WORD *)v31 + 5) = v22;
                  *((_DWORD *)v31 + 1) = v36 | 5;
                  v35 = *(_WORD *)(v24 + 36);
                  *((_DWORD *)v31 + 5) = 2;
LABEL_28:
                  *(_WORD *)v31 = v35;
                  v21 = 1;
                }
              }
              else
              {
                LOBYTE(v19) = 0;
              }
            }
            v37 = &v18[3 * v20];
            v40 = *((_DWORD *)v37 + 1);
            v38 = (int *)v37 + 1;
            v39 = v40;
            if ( (v40 & 1) != 0 )
            {
              ++v20;
              *v38 = v39 | v27;
            }
          }
        }
      }
    }
    if ( ++v22 >= (unsigned int)*(unsigned __int16 *)(v5 + 32) )
      break;
  }
  if ( (v21 & 1) != 0 )
  {
    v41 = 0;
    v42 = 0;
    v281 = v3;
    do
    {
      v43 = &v18[3 * v41];
      if ( (*((_BYTE *)v43 + 4) & 1) != 0 )
      {
        _X24 = (unsigned int *)a1[800];
        v45 = 0;
        v46 = 128;
        while ( 1 )
        {
          v47 = &_X24[v45];
          if ( !_X24[v45 + 4] )
            break;
          --v46;
          v45 += 468;
          if ( !v46 )
            goto LABEL_77;
        }
        if ( v47 != (unsigned int *)-16LL )
        {
          v48 = *a1;
          memset(v293, 0, sizeof(v293));
          *(_QWORD *)((char *)v292 + 5) = 0;
          v292[0] = 0;
          memset(v291, 0, sizeof(v291));
          memset(v290, 0, 125);
          v323 = 0;
          v324 = 0;
          v321 = 0;
          v322 = 0;
          v319 = 0;
          v320 = 0;
          v317 = 0;
          v318 = 0;
          v315 = 0;
          v316 = 0;
          v313 = 0;
          v314 = 0;
          v311 = 0;
          v312 = 0;
          v309 = 0;
          v310 = 0;
          v307 = 0;
          v308 = 0;
          v305 = 0;
          v306 = 0;
          v303 = 0;
          v304 = 0;
          v301 = 0;
          v302 = 0;
          v299 = 0;
          v300 = 0;
          v297 = 0;
          v298 = 0;
          v295 = 0;
          v296 = 0;
          v294 = 0u;
          v289[0] = 0;
          __asm { PRFM            #0x11, [X24] }
          do
            v96 = __ldxr(_X24);
          while ( __stxr(v96 + 1, _X24) );
          v49 = *((_DWORD *)v43 + 5);
          v286 = v41;
          v283 = v47 + 4;
          _X24[v45 + 5] = v49;
          switch ( v49 )
          {
            case 3u:
              _X8 = _X24 + 1;
              __asm { PRFM            #0x11, [X8] }
              do
                v105 = __ldxr(_X8);
              while ( __stxr(v105 + 1, _X8) );
              v8 = scnprintf(v293, 32, "BiDi");
              break;
            case 2u:
              _X8 = _X24 + 3;
              __asm { PRFM            #0x11, [X8] }
              do
                v102 = __ldxr(_X8);
              while ( __stxr(v102 + 1, _X8) );
              v8 = scnprintf(v293, 32, "Rx-Only");
              break;
            case 1u:
              _X8 = _X24 + 2;
              __asm { PRFM            #0x11, [X8] }
              do
                v99 = __ldxr(_X8);
              while ( __stxr(v99 + 1, _X8) );
              v8 = scnprintf(v293, 32, "Tx-Only");
              break;
          }
          v50 = &_X24[v45];
          v55 = _X24[v45 + 8];
          *((_WORD *)v50 + 23) = *(_WORD *)v43;
          v51 = (4 * *((_DWORD *)v43 + 1)) & 0x20 | v55;
          v50[8] = v51;
          v52 = (4 * *((_DWORD *)v43 + 1)) & 0x40 | v51;
          v50[8] = v52;
          v53 = (4 * *((_DWORD *)v43 + 1)) & 0x80 | v52;
          v50[8] = v53;
          v54 = *((_DWORD *)v43 + 1);
          LOBYTE(v55) = v54;
          if ( (v54 & 2) != 0 )
          {
            v56 = *((unsigned __int8 *)v43 + 8);
            v57 = v48[369];
            v50[8] = v53 | 1;
            v58 = *((unsigned __int16 *)v43 + 4);
            *((_WORD *)v50 + 24) = v58;
            v59 = *((_DWORD *)v43 + 3);
            v50[13] = v59;
            v8 = scnprintf(
                   v290,
                   125,
                   "tx: flow_id %hu mdata 0x%x add_ts %llu",
                   v58,
                   v59,
                   *(_QWORD *)(v57 + 192LL * v56 + 136));
            v55 = *((_DWORD *)v43 + 1);
          }
          if ( (v55 & 4) != 0 )
          {
            v60 = *((unsigned __int8 *)v43 + 10);
            v61 = *(_QWORD *)v48[185];
            v50[8] |= 2u;
            v62 = &_X24[v45];
            v63 = v61 + 336LL * v60;
            *((_WORD *)v62 + 25) = *((_WORD *)v43 + 5);
            v62[14] = *((_DWORD *)v43 + 4);
            v64 = *(unsigned __int8 *)(v63 + 128);
            v62[49] = *(_DWORD *)(v63 + 120);
            if ( v64 == 17 )
              v65 = 0;
            else
              v65 = -22;
            v62[53] = *(_DWORD *)(v63 + 104);
            *((_WORD *)v62 + 114) = *(_WORD *)(v63 + 126);
            if ( v64 == 6 )
              v66 = 1;
            else
              v66 = v65;
            v67 = *(_WORD *)(v63 + 124);
            *((_BYTE *)v62 + 232) = v66;
            v62[59] = 0;
            *((_WORD *)v62 + 115) = v67;
            *((_QWORD *)v62 + 8) = *(_QWORD *)(v63 + 136);
            v282 = v291;
            scnprintf(v291, 125, "rx: flow_id %hu mdata 0x%x num_pkt:%llu add_ts %llu", v8);
          }
          else
          {
            v282 = v289;
          }
          scnprintf(&v294, 256, "0x%x", _X24[v45 + 49]);
          v69 = v68;
          scnprintf((char *)&v294 + v68, 256 - v68, " 0x%x", _X24[v45 + 53]);
          v71 = v70 + v69;
          scnprintf((char *)&v294 + v71, 256 - v71, " %u", LOWORD(_X24[v45 + 57]));
          v73 = v72 + v71;
          scnprintf((char *)&v294 + v73, 256 - v73, " %u", HIWORD(_X24[v45 + 57]));
          scnprintf(
            (char *)&v294 + (unsigned __int16)(v74 + v73),
            256 - (unsigned __int16)(v74 + v73),
            " %u",
            LOBYTE(_X24[v45 + 58]));
          v77 = v50[8];
          if ( (v54 & 2) != 0 )
            v78 = v290;
          else
            v78 = v289;
          v79 = sched_clock(v75, v76);
          LODWORD(v280) = v77;
          result = qdf_trace_msg(
                     0x45u,
                     5u,
                     "%s: STC: Sample %s flow (tuple: %s) %s %s flags:0x%x cur_ts %llu",
                     v80,
                     v81,
                     v82,
                     v83,
                     v84,
                     v85,
                     v86,
                     v87,
                     "wlan_dp_move_candidate_to_sample_table",
                     v293,
                     &v294,
                     v78,
                     v282,
                     v280,
                     v79);
          *v283 = 1;
          *((_DWORD *)v43 + 1) = 0;
          v88 = v50[8];
          if ( (v88 & 1) != 0 )
          {
            v89 = v281[369] + 192LL * LOBYTE(_X24[v45 + 12]);
            *(_QWORD *)(v89 + 176) = 30000000000LL;
            *(_BYTE *)(v89 + 162) = 1;
            v88 = v50[8];
          }
          v4 = v285;
          v41 = v286;
          v42 = 1;
          v18 = a1 + 804;
          if ( (v88 & 2) != 0 )
          {
            v90 = *(_QWORD *)v281[185] + 336LL * BYTE2(_X24[v45 + 12]);
            *(_QWORD *)(v90 + 328) = 30000000000LL;
            *(_BYTE *)(v90 + 322) = 1;
          }
          goto LABEL_35;
        }
LABEL_77:
        v106 = printk(
                 &unk_9BB309,
                 "0",
                 "wlan_dp_stc_flow_monitor_work_handler",
                 "../vendor/qcom/opensource/wlan/qcacld-3.0/components/dp/core/src/wlan_dp_stc.c");
        result = dump_stack(v106);
        if ( (v42 & 1) == 0 )
          goto LABEL_84;
        goto LABEL_78;
      }
LABEL_35:
      ++v41;
    }
    while ( v41 != 128 );
    if ( (v42 & 1) == 0 )
      goto LABEL_84;
LABEL_78:
    if ( *((_DWORD *)a1 + 62) <= 1u )
    {
      v107 = *((_DWORD *)a1 + 56) == 1 ? 5LL : 1LL;
      result = hrtimer_start_range_ns(a1 + 20, 600000000, 0, v107);
      v108 = *((_BYTE *)a1 + 148);
      *((_DWORD *)a1 + 62) = 2;
      if ( (v108 & 4) != 0 )
        result = qdf_trace_msg(
                   0x45u,
                   5u,
                   "%s: STC: Sampling timer started!",
                   v8,
                   v9,
                   v10,
                   v11,
                   v12,
                   v13,
                   v14,
                   v15,
                   "wlan_dp_stc_flow_monitor_work_handler");
    }
  }
LABEL_84:
  v109 = 0;
  v287 = a1 + 32;
  while ( 2 )
  {
    v110 = (__int64)&a1[800][234 * v109];
    v113 = *(_DWORD *)(v110 + 16);
    v112 = v110 + 16;
    v111 = v113;
    if ( !v113 )
      goto LABEL_87;
    if ( v111 == 6 )
      result = wlan_dp_stc_remove_sampling_table_entry(a1, v112);
    v114 = *(_DWORD *)(v112 + 16);
    if ( (v114 & 4) != 0 )
    {
      v115 = *(_DWORD *)(v112 + 20);
      if ( (v115 & 2) == 0 )
      {
        *(_DWORD *)(v112 + 20) = v115 | 2;
        v116 = (__int64 (__fastcall *)(__int64, __int64, __int64))(*a1)[91];
        if ( v116 )
        {
          v117 = **a1;
          if ( (*((_DWORD *)a1 + 37) & 1) != 0 )
            v118 = 9;
          else
            v118 = 1;
          if ( *((_DWORD *)v116 - 1) != 1575026608 )
            __break(0x8229u);
          result = v116(v117, v112 + 176, v118);
          v114 = *(_DWORD *)(v112 + 16);
        }
        if ( (v114 & 0xC0) == 0 )
          *(_QWORD *)(v112 + 8) = v288;
      }
    }
    if ( *(_BYTE *)(v112 + 1864) != 2 )
    {
      if ( (v114 & 8) != 0 )
      {
        v119 = (int *)(v112 + 20);
        if ( (*(_BYTE *)(v112 + 20) & 4) == 0 )
          goto LABEL_108;
      }
LABEL_120:
      v125 = *(_QWORD *)(v112 + 8);
      if ( !v125 )
        goto LABEL_123;
LABEL_121:
      if ( v288 - v125 >= 0x2540BE401LL )
        result = wlan_dp_stc_remove_sampling_table_entry(a1, v112);
      goto LABEL_123;
    }
    if ( (v114 & 0x10) == 0 )
      goto LABEL_120;
    v119 = (int *)(v112 + 20);
    if ( (*(_BYTE *)(v112 + 20) & 8) != 0 )
      goto LABEL_120;
LABEL_108:
    v120 = (__int64 (__fastcall *)(__int64, __int64, __int64))(*a1)[91];
    if ( v120 )
    {
      v121 = **a1;
      if ( (*((_DWORD *)a1 + 37) & 1) != 0 )
        v122 = 10;
      else
        v122 = 2;
      if ( *((_DWORD *)v120 - 1) != 1575026608 )
        __break(0x8229u);
      result = v120(v121, v112 + 176, v122);
      v114 = *(_DWORD *)(v112 + 16);
    }
    if ( (v114 & 0x80) == 0 )
    {
      v123 = *(_DWORD *)(v112 + 20) | 4;
LABEL_119:
      *(_DWORD *)(v112 + 20) = v123;
      *(_QWORD *)(v112 + 8) = v288;
      goto LABEL_120;
    }
    v124 = *(_DWORD *)(v112 + 20);
    if ( *(_BYTE *)(v112 + 1864) == 2 )
    {
      v123 = v124 | 8;
      goto LABEL_119;
    }
    *v119 = v124 | 4;
    v125 = *(_QWORD *)(v112 + 8);
    if ( v125 )
      goto LABEL_121;
LABEL_123:
    if ( *(_DWORD *)v112 == 8 )
    {
      v126 = *(_DWORD *)(v112 + 20);
      v127 = *a1;
      if ( (v126 & 1) == 0 )
      {
        if ( *((_BYTE *)a1 + 9) )
        {
          v128 = *(_DWORD *)(v112 + 16);
          v129 = (v128 >> 2) & 1;
          if ( *(_BYTE *)(v112 + 1864) == 2 )
          {
            if ( (v128 & 0x10) == 0 )
              goto LABEL_131;
LABEL_130:
            v129 |= 2u;
          }
          else if ( (v128 & 8) != 0 )
          {
            goto LABEL_130;
          }
LABEL_131:
          v130 = (__int64 (__fastcall *)(__int64, __int64, __int64))v127[92];
          if ( v130 )
          {
            v131 = *v127;
            v132 = v129 & 0xFFFFFFF7 | (8 * ((*((_DWORD *)a1 + 37) >> 1) & 1));
            if ( *((_DWORD *)v130 - 1) != 1575026608 )
              __break(0x822Au);
            result = v130(v131, v112 + 176, v132);
            v126 = *(_DWORD *)(v112 + 20);
          }
        }
        *(_DWORD *)(v112 + 20) = v126 | 1;
        v127 = *a1;
      }
      _X23 = (unsigned int *)a1[803];
      v323 = 0;
      v324 = 0;
      v321 = 0;
      v322 = 0;
      v319 = 0;
      v320 = 0;
      v317 = 0;
      v318 = 0;
      v315 = 0;
      v316 = 0;
      v313 = 0;
      v314 = 0;
      v311 = 0;
      v312 = 0;
      v309 = 0;
      v310 = 0;
      v307 = 0;
      v308 = 0;
      v305 = 0;
      v306 = 0;
      v303 = 0;
      v304 = 0;
      v301 = 0;
      v302 = 0;
      v299 = 0;
      v300 = 0;
      v297 = 0;
      v298 = 0;
      v295 = 0;
      v296 = 0;
      v294 = 0u;
      if ( *_X23 == 256 )
      {
        result = qdf_trace_msg(
                   0x45u,
                   5u,
                   "%s: STC: No space available in classified flow table",
                   v8,
                   v9,
                   v10,
                   v11,
                   v12,
                   v13,
                   v14,
                   v15,
                   "wlan_dp_stc_move_to_classified_table");
      }
      else
      {
        v134 = *(_DWORD *)(v112 + 16);
        if ( (v134 & 1) != 0 )
        {
          v135 = v127[369] + 192LL * *(unsigned __int8 *)(v112 + 32);
          *(_WORD *)(v135 + 162) = 256;
          if ( (*(_DWORD *)(v112 + 16) & 2) == 0 )
            goto LABEL_141;
LABEL_139:
          v136 = *(_QWORD *)v127[185] + 336LL * *(unsigned __int8 *)(v112 + 34);
          *(_WORD *)(v136 + 322) = 256;
        }
        else
        {
          v135 = 0;
          if ( (v134 & 2) != 0 )
            goto LABEL_139;
LABEL_141:
          v136 = 0;
        }
        if ( (unsigned int)*(unsigned __int8 *)(v112 + 28) - 7 > 0xFFFFFFFD )
        {
          result = wlan_dp_stc_remove_sampling_table_entry(a1, v112);
        }
        else
        {
          v137 = 0;
          v138 = 0;
          while ( 1 )
          {
            v139 = &_X23[v137];
            if ( !_X23[v137 + 25] )
              break;
            v137 += 32;
            ++v138;
            if ( v137 == 0x2000 )
              goto LABEL_86;
          }
          v139[25] = 2;
          qdf_mem_copy(v139 + 7, (const void *)(v112 + 180), 0x30u);
          v140 = *(unsigned __int8 *)(v112 + 28);
          v141 = v140 - 1;
          v139[24] = v140;
          v142 = 30000000000LL;
          if ( v141 <= 2 )
          {
            _X8 = (unsigned __int64 *)&_X23[v137 + 20];
            __asm { PRFM            #0x11, [X8] }
            do
              v167 = __ldxr(_X8);
            while ( __stxr(v167 | 4, _X8) );
            v142 = 7000000000LL;
          }
          __asm { PRFM            #0x11, [X23] }
          do
            v163 = __ldxr(_X23);
          while ( __stxr(v163 + 1, _X23) );
          v164 = *(_DWORD *)(v112 + 16);
          if ( (v164 & 1) != 0 )
          {
            HIWORD(_X23[v137 + 2]) = *(_WORD *)(v112 + 32);
            _X9 = (unsigned __int64 *)&_X23[v137 + 20];
            __asm { PRFM            #0x11, [X9] }
            do
              v170 = __ldxr(_X9);
            while ( __stxr(v170 | 1, _X9) );
            *(_QWORD *)(v135 + 176) = v142;
            *(_BYTE *)(v135 + 163) = 2;
            *(_BYTE *)(v135 + 160) = v138;
            *(_BYTE *)(v135 + 184) = *(_BYTE *)(v112 + 29);
            v164 = *(_DWORD *)(v112 + 16);
          }
          if ( (v164 & 2) == 0 )
            goto LABEL_158;
          LOWORD(_X23[v137 + 3]) = *(_WORD *)(v112 + 34);
          _X9 = (unsigned __int64 *)&_X23[v137 + 20];
          __asm { PRFM            #0x11, [X9] }
          do
            v173 = __ldxr(_X9);
          while ( __stxr(v173 | 2, _X9) );
          v143 = *(unsigned __int16 *)(v136 + 36);
          *(_QWORD *)(v136 + 328) = v142;
          *(_BYTE *)(v136 + 323) = 2;
          *(_WORD *)(v136 + 324) = v138;
          if ( v143 == 0xFFFF )
          {
LABEL_158:
            LOWORD(v143) = *(_WORD *)(v112 + 30);
            v284 = 0xFFFF;
          }
          else
          {
            v284 = v143;
          }
          v144 = &_X23[v137];
          *((_WORD *)v144 + 7) = v143;
          scnprintf(&v294, 256, "0x%x", *(_DWORD *)(v112 + 180));
          v146 = v145;
          scnprintf((char *)&v294 + v145, 256 - v145, " 0x%x", *(_DWORD *)(v112 + 196));
          v148 = v147 + v146;
          scnprintf((char *)&v294 + v148, 256 - v148, " %u", *(unsigned __int16 *)(v112 + 212));
          v150 = v149 + v148;
          scnprintf((char *)&v294 + v150, 256 - v150, " %u", *(unsigned __int16 *)(v112 + 214));
          v152 = scnprintf(
                   (char *)&v294 + (unsigned __int16)(v151 + v150),
                   256 - (unsigned __int16)(v151 + v150),
                   " %u",
                   *(unsigned __int8 *)(v112 + 216));
          LODWORD(v280) = v284;
          v160 = qdf_trace_msg(
                   0x45u,
                   5u,
                   "%s: STC: Move flow (%s) to classified flow %d for peer %hu [PEER_ID: s_entry %hu, rx_flow %hu]",
                   v152,
                   v153,
                   v154,
                   v155,
                   v156,
                   v157,
                   v158,
                   v159,
                   "wlan_dp_stc_move_to_classified_table",
                   &v294,
                   v138,
                   *((unsigned __int16 *)v144 + 7),
                   *(unsigned __int16 *)(v112 + 30),
                   v280);
          *((_BYTE *)v139 + 8) = 1;
          *((_QWORD *)v144 + 16) = sched_clock(v160, v161);
          result = wlan_dp_stc_remove_sampling_table_entry(a1, v112);
          if ( *((unsigned __int16 *)v144 + 7) >= 0x41uLL )
LABEL_321:
            __break(0x5512u);
          v7 = (__int64)&v287[12 * *((unsigned __int16 *)v144 + 7)];
          if ( *(_BYTE *)(v7 + 6) )
            result = wlan_dp_stc_inc_traffic_type(a1);
        }
      }
LABEL_86:
      v4 = v285;
    }
LABEL_87:
    if ( ++v109 != 128 )
      continue;
    break;
  }
  if ( *(_DWORD *)v4 )
  {
    for ( i = 0; i != 4096; i += 16LL )
    {
      v175 = &v4[i];
      if ( HIDWORD(v4[i + 12]) == 2 )
      {
        if ( (v175[11] & 1) != 0 || (v175[11] & 2) != 0 || (v175[11] & 4) != 0 )
        {
          _X20 = (unsigned int *)a1[803];
          if ( (v175[11] & 4) != 0 )
          {
            v179 = &v4[i];
            if ( (v4[i + 10] & 2) != 0 )
            {
              v180 = *(_QWORD *)(*a1)[185] + 336LL * *((unsigned __int8 *)v179 + 12);
              *(_BYTE *)(v180 + 323) = 0;
              *(_WORD *)(v180 + 324) = 0;
            }
            if ( (v179[10] & 1) != 0 )
            {
              v181 = (_BYTE *)((*a1)[369] + 192LL * BYTE2(v4[i + 1]));
              v181[163] = 0;
              v181[160] = 0;
              v181[184] = 0;
            }
          }
          else
          {
            if ( (v175[11] & 1) != 0 && (v4[i + 10] & 2) != 0 )
            {
              v177 = *(_QWORD *)(*a1)[185] + 336LL * BYTE4(v4[i + 1]);
              *(_BYTE *)(v177 + 323) = 0;
              *(_WORD *)(v177 + 324) = 0;
            }
            if ( (v175[11] & 2) != 0 && (v4[i + 10] & 1) != 0 )
            {
              v178 = (_BYTE *)((*a1)[369] + 192LL * BYTE2(v4[i + 1]));
              v178[163] = 0;
              v178[160] = 0;
              v178[184] = 0;
            }
            if ( HIWORD(v4[i + 1]) >= 0x41uLL )
              goto LABEL_321;
            if ( BYTE6(v287[12 * HIWORD(v4[i + 1])]) && *((_BYTE *)v175 + 8) )
              wlan_dp_stc_dec_traffic_type(a1);
          }
          v182 = *a1;
          v183 = &v4[i];
          v184 = **a1;
          v298 = 0;
          v299 = 0;
          v296 = 0;
          v297 = 0;
          v295 = 0;
          v294 = 0u;
          qdf_mem_copy(&v294, (char *)v183 + 28, 0x30u);
          v193 = (void (__fastcall *)(__int64, __int128 *, __int64))v182[93];
          LOBYTE(v299) = *((_DWORD *)v183 + 24);
          HIDWORD(v299) = 2;
          if ( v193 )
          {
            if ( *((_DWORD *)v193 - 1) != 1770822738 )
              __break(0x8228u);
            v193(v184, &v294, 8);
          }
          v4 = v285;
          if ( (*((_BYTE *)a1 + 148) & 4) != 0 )
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: STC: Purge flow c_id %u del_flags 0x%lx for peer %u vdev %u",
              v185,
              v186,
              v187,
              v188,
              v189,
              v190,
              v191,
              v192,
              "wlan_dp_stc_purge_classified_flow",
              LOWORD(v285[i + 2]),
              v175[11],
              HIWORD(v285[i + 1]),
              BYTE1(v285[i + 1]));
          v194 = v285[i + 2];
          result = (unsigned __int64)qdf_mem_set(v175 + 1, 0x80u, 0);
          LOWORD(v285[i + 2]) = v194;
          *((_DWORD *)v175 + 25) = 0;
          __asm { PRFM            #0x11, [X20] }
          do
            v221 = __ldxr(_X20);
          while ( __stxr(v221 - 1, _X20) );
        }
        v195 = *((unsigned __int8 *)v175 + 8);
        v196 = *a1;
        result = sched_clock(result, v7);
        v197 = v4[i + 10];
        v198 = v197;
        if ( v195 )
        {
          v199 = v4[i + 10];
          if ( (v197 & 4) != 0 )
            v200 = 5000000000LL;
          else
            v200 = 20000000000LL;
          if ( (v197 & 1) != 0 )
          {
            v209 = *(_QWORD *)(v196[369] + 192LL * BYTE2(v4[i + 1]) + 144);
            result = sched_clock(result, v7);
            v210 = result - v209;
            if ( result <= v209 )
            {
              v4 = v285;
            }
            else
            {
              v4 = v285;
              if ( v210 < v200 )
                continue;
            }
          }
          if ( (v199 & 2) == 0
            || (v211 = *(_QWORD *)(*(_QWORD *)v196[185] + 336LL * BYTE4(v4[i + 1]) + 256),
                result = sched_clock(result, v7),
                result <= v211)
            || result - v211 >= v200 )
          {
            v201 = &v4[i];
            *((_BYTE *)v175 + 8) = 0;
            v202 = v4[i + 14];
            v201[13] = result;
            *((_DWORD *)v201 + 28) = v202 + 1;
            v203 = *a1;
            v204 = **a1;
            v298 = 0;
            v299 = 0;
            v296 = 0;
            v297 = 0;
            v295 = 0;
            v294 = 0u;
            result = (unsigned __int64)qdf_mem_copy(&v294, (char *)&v4[i + 3] + 4, 0x30u);
            v205 = v4[i + 12];
            v206 = (__int64 (__fastcall *)(__int64, __int128 *, __int64))v203[93];
            HIDWORD(v299) = 0;
            LOBYTE(v299) = v205;
            if ( v206 )
            {
              if ( *((_DWORD *)v206 - 1) != 1770822738 )
                __break(0x8228u);
              result = v206(v204, &v294, 8);
            }
            if ( *((unsigned __int16 *)v201 + 7) >= 0x41uLL )
              goto LABEL_321;
            v7 = (__int64)&v287[12 * *((unsigned __int16 *)v201 + 7)];
            if ( *(_BYTE *)(v7 + 6) )
              result = wlan_dp_stc_dec_traffic_type(a1);
          }
        }
        else if ( (v197 & 1) != 0
               && (v212 = *(_QWORD *)(v196[369] + 192LL * BYTE2(v4[i + 1]) + 144),
                   _CF = result >= v212,
                   v213 = result - v212,
                   v213 != 0 && _CF)
               && v213 < 0x1DCD6500
               || (v198 & 2) != 0
               && (v207 = *(_QWORD *)(*(_QWORD *)v196[185] + 336LL * BYTE4(v4[i + 1]) + 256),
                   _CF = result >= v207,
                   v208 = result - v207,
                   v208 != 0 && _CF)
               && v208 < 0x1DCD6500 )
        {
          v214 = v4[i + 13];
          v215 = v4[i + 15];
          *((_BYTE *)v175 + 8) = 1;
          v4[i + 15] = result - v214 + v215;
          v216 = *a1;
          v217 = **a1;
          v298 = 0;
          v299 = 0;
          v296 = 0;
          v297 = 0;
          v295 = 0;
          v294 = 0u;
          result = (unsigned __int64)qdf_mem_copy(&v294, (char *)&v4[i + 3] + 4, 0x30u);
          v218 = v4[i + 12];
          v219 = (__int64 (__fastcall *)(__int64, __int128 *, __int64))v216[93];
          HIDWORD(v299) = 1;
          LOBYTE(v299) = v218;
          if ( v219 )
          {
            if ( *((_DWORD *)v219 - 1) != 1770822738 )
              __break(0x8228u);
            result = v219(v217, &v294, 8);
          }
          if ( HIWORD(v4[i + 1]) >= 0x41uLL )
            goto LABEL_321;
          v7 = (__int64)&v287[12 * HIWORD(v4[i + 1])];
          if ( *(_BYTE *)(v7 + 6) )
            result = wlan_dp_stc_inc_traffic_type(a1);
        }
      }
    }
  }
  if ( *((_BYTE *)a1 + 255) != 1 )
    goto LABEL_320;
  v222 = 0;
  while ( 2 )
  {
    v223 = &v287[12 * v222];
    if ( !*((_BYTE *)v223 + 6) )
      goto LABEL_241;
    result = sched_clock(result, v7);
    if ( *((_BYTE *)v223 + 6) && ((unsigned int)v223[10] & 4) != 0 && result - (unsigned __int64)v223[2] > 0xB2D05E00 )
    {
      v223[2] = nullptr;
      _X8 = (unsigned __int64 *)(v223 + 10);
      __asm { PRFM            #0x11, [X8] }
      do
        v273 = __ldxr(_X8);
      while ( __stxr(v273 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
      *((_DWORD *)v223 + 22) = 1;
    }
    v232 = v288 - (_QWORD)v223[6];
    if ( v232 < 0x3B9ACA00 )
      goto LABEL_292;
    v233 = a1[803];
    v234 = 0;
    v235 = 0;
    v236 = 0;
    v223[6] = (_QWORD *)v288;
    do
    {
      if ( HIDWORD(v233[v234 + 12]) == 2 && HIWORD(v233[v234 + 1]) == *((unsigned __int16 *)v223 + 5) )
      {
        v239 = &v233[v234];
        v240 = *a1;
        if ( (v233[v234 + 10] & 1) != 0 )
        {
          v242 = *((unsigned int *)v239 + 5);
          v243 = *(_QWORD *)(v240[369] + 192LL * *((unsigned __int8 *)v239 + 10) + 152);
          *((_DWORD *)v239 + 5) = v243;
          v241 = v243 - v242;
          v240 = *a1;
          if ( (v239[10] & 2) == 0 )
          {
LABEL_258:
            v238 = 0;
            goto LABEL_250;
          }
        }
        else
        {
          v241 = 0;
          if ( (v239[10] & 2) == 0 )
            goto LABEL_258;
        }
        v237 = *(_QWORD *)(*(_QWORD *)v240[185] + 336LL * BYTE4(v233[v234 + 1]) + 280);
        v238 = v237 - LODWORD(v233[v234 + 3]);
        LODWORD(v233[v234 + 3]) = v237;
LABEL_250:
        v236 += v241;
        v235 += v238;
      }
      v234 += 16;
    }
    while ( v234 != 4096 );
    v244 = *a1;
    v295 = 0;
    v294 = 0u;
    v245 = *v244;
    if ( !v245 || (v246 = *(_QWORD *)(v245 + 2808)) == 0 || !*(_QWORD *)v246 )
    {
      qdf_trace_msg(
        0x89u,
        8u,
        "%s: Invalid Instance:",
        v224,
        v225,
        v226,
        v227,
        v228,
        v229,
        v230,
        v231,
        "cdp_txrx_get_peer_param");
LABEL_269:
      v249 = 0;
      goto LABEL_270;
    }
    v247 = *(_QWORD *)(*(_QWORD *)v246 + 8LL);
    if ( !v247 )
      goto LABEL_269;
    v248 = *(unsigned int (**)(void))(v247 + 120);
    if ( !v248 )
      goto LABEL_269;
    if ( *((_DWORD *)v248 - 1) != 1144888733 )
      __break(0x8228u);
    if ( v248() )
      goto LABEL_269;
    v249 = *((_QWORD *)&v294 + 1) - (_QWORD)v223[3];
    v223[3] = *((_QWORD **)&v294 + 1);
LABEL_270:
    v250 = *a1;
    v295 = 0;
    v294 = 0u;
    v251 = *v250;
    if ( !v251 || (result = *(_QWORD *)(v251 + 2808)) == 0 || !*(_QWORD *)result )
    {
      result = qdf_trace_msg(
                 0x89u,
                 8u,
                 "%s: Invalid Instance:",
                 v224,
                 v225,
                 v226,
                 v227,
                 v228,
                 v229,
                 v230,
                 v231,
                 "cdp_txrx_get_peer_param");
      goto LABEL_280;
    }
    v252 = *(_QWORD *)(*(_QWORD *)result + 8LL);
    if ( v252 )
    {
      v252 = *(_QWORD *)(v252 + 120);
      if ( v252 )
      {
        if ( *(_DWORD *)(v252 - 4) != 1144888733 )
          __break(0x8228u);
        result = ((__int64 (*)(void))v252)();
        if ( !(_DWORD)result )
        {
          v252 = *((_QWORD *)&v294 + 1) - (_QWORD)v223[4];
          v223[4] = *((_QWORD **)&v294 + 1);
          goto LABEL_281;
        }
LABEL_280:
        v252 = 0;
      }
    }
LABEL_281:
    v253 = v252 + v249;
    _CF = v253 >= v235 + v236;
    v254 = v253 - (v235 + v236);
    if ( _CF )
    {
      v255 = 1000000000 * v254 / v232;
      if ( wlan_dp_stc_set_bk_tput_prev_bk_tput_active == v255 > 0x6590 )
      {
        if ( !wlan_dp_stc_set_bk_tput_hysterisis_period )
          goto LABEL_292;
        wlan_dp_stc_set_bk_tput_prev_bk_tput_active = v255 > 0x6590;
        if ( (unsigned __int8)++wlan_dp_stc_set_bk_tput_hysterisis_period < 2u )
          goto LABEL_292;
        wlan_dp_stc_set_bk_tput_hysterisis_period = 0;
        if ( v255 >= 0x6591 )
        {
          _X9 = (unsigned __int64 *)(v223 + 10);
          __asm { PRFM            #0x11, [X9] }
          do
            v276 = __ldxr(_X9);
          while ( __stlxr(v276 | 2, _X9) );
          __dmb(0xBu);
          if ( (((unsigned int)v276 >> 1) & 1) != 0 )
            goto LABEL_292;
        }
        else
        {
          _X9 = (unsigned __int64 *)(v223 + 10);
          __asm { PRFM            #0x11, [X9] }
          do
            v279 = __ldxr(_X9);
          while ( __stlxr(v279 & 0xFFFFFFFFFFFFFFFDLL, _X9) );
          __dmb(0xBu);
          if ( (((unsigned int)v279 >> 1) & 1) == 0 )
            goto LABEL_292;
        }
        *((_DWORD *)v223 + 22) = 1;
      }
      else
      {
        wlan_dp_stc_set_bk_tput_prev_bk_tput_active = v255 > 0x6590;
        wlan_dp_stc_set_bk_tput_hysterisis_period = 1;
      }
    }
LABEL_292:
    v256 = *((unsigned __int8 *)v223 + 6);
    v257 = *a1;
    HIDWORD(v294) = 0;
    *(_QWORD *)((char *)&v294 + 4) = 0;
    if ( !v256 || *((_BYTE *)v223 + 7) )
    {
      *((_DWORD *)v223 + 22) = 0;
    }
    else if ( *((_DWORD *)v223 + 22) )
    {
      *((_DWORD *)v223 + 22) = 0;
      v258 = ((unsigned int)v223[10] >> 1) & 2;
      if ( *((_DWORD *)v223 + 14) )
        ++v258;
      v259 = v258 & 0xFFFFFFFB | (4 * (((unsigned int)v223[10] >> 1) & 1));
      if ( *((_DWORD *)v223 + 15) )
        v259 |= 0x10000u;
      if ( *((_DWORD *)v223 + 16) )
        v259 |= 0x20000u;
      if ( *((_DWORD *)v223 + 17) )
        v259 |= 0x40000u;
      if ( *((_DWORD *)v223 + 18) )
        v259 |= 0x80000u;
      if ( *((_DWORD *)v223 + 19) )
        v260 = v259 | 0x100000;
      else
        v260 = v259;
      LODWORD(v294) = *((unsigned __int8 *)v223 + 8);
      qdf_mem_copy((char *)&v294 + 4, v223, 6u);
      HIDWORD(v294) = v260;
      v261 = (__int64 (__fastcall *)(__int64, __int128 *))v257[103];
      v262 = *v257;
      if ( *((_DWORD *)v261 - 1) != -288160835 )
        __break(0x8228u);
      result = v261(v262, &v294);
      if ( (_DWORD)result )
        result = qdf_trace_msg(
                   0x45u,
                   2u,
                   "%s: STC: Active traffic map ind failed for peer %d",
                   v263,
                   v264,
                   v265,
                   v266,
                   v267,
                   v268,
                   v269,
                   v270,
                   "wlan_dp_stc_send_active_traffic_map_ind",
                   (unsigned int)v222);
    }
LABEL_241:
    if ( ++v222 != 64 )
      continue;
    break;
  }
LABEL_320:
  _ReadStatusReg(SP_EL0);
  return result;
}
