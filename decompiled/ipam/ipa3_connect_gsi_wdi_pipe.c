__int64 __fastcall ipa3_connect_gsi_wdi_pipe(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  unsigned int ep_mapping; // w0
  unsigned int v6; // w21
  __int64 v7; // x26
  __int64 v8; // x26
  int v9; // t1
  __int64 v10; // x8
  const char *v11; // x8
  long double v12; // q0
  long double v13; // q1
  long double v14; // q2
  long double v15; // q3
  float v16; // s4
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  unsigned int v20; // w10
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x8
  int v39; // w9
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  int v52; // w4
  __int64 v53; // x8
  unsigned int v54; // w9
  __int64 v55; // x22
  __int64 v56; // x8
  __int64 v57; // x0
  __int64 v58; // x0
  long double v59; // q0
  long double v60; // q1
  long double v61; // q2
  long double v62; // q3
  float v63; // s4
  int v64; // w4
  __int64 v65; // x10
  __int64 v66; // x8
  __int64 v67; // x23
  __int64 v68; // x0
  __int64 v69; // x0
  long double v70; // q0
  long double v71; // q1
  long double v72; // q2
  long double v73; // q3
  float v74; // s4
  char v75; // w1
  __int64 v76; // x9
  __int64 v77; // x2
  __int64 v78; // x8
  __int64 v79; // x0
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v82; // x0
  long double v83; // q0
  long double v84; // q1
  long double v85; // q2
  long double v86; // q3
  float v87; // s4
  int v88; // w4
  __int64 v89; // x10
  __int64 v90; // x8
  __int64 v91; // x23
  __int64 v92; // x0
  __int64 v93; // x0
  long double v94; // q0
  long double v95; // q1
  long double v96; // q2
  long double v97; // q3
  float v98; // s4
  char v99; // w1
  __int64 v100; // x8
  long double v101; // q0
  long double v102; // q1
  long double v103; // q2
  long double v104; // q3
  float v105; // s4
  char v106; // w1
  __int64 v107; // x8
  __int64 v108; // x2
  char v109; // w8
  unsigned int v110; // w9
  __int64 v111; // x8
  __int64 v112; // x0
  __int64 v113; // x0
  __int64 v114; // x8
  __int64 v115; // x0
  __int64 v116; // x0
  unsigned int v117; // w22
  int v119; // w8
  _QWORD *v120; // x8
  __int64 v121; // x0
  __int64 v122; // x0
  __int64 v123; // x0
  __int64 v124; // x0
  unsigned int v125; // w0
  __int64 v126; // x8
  unsigned int v127; // w22
  __int64 v128; // x0
  __int64 v129; // x0
  __int64 v130; // x8
  const char *v131; // x8
  __int64 v133; // x0
  __int64 v134; // x0
  __int64 v135; // x0
  __int64 v136; // x0
  __int64 v137; // x0
  __int64 v138; // x0
  __int64 v139; // x0
  __int64 v140; // x0
  __int64 v141; // x0
  __int64 v142; // x0
  __int64 v143; // x0
  __int64 v144; // x0
  __int64 v145; // x8
  __int64 v146; // x0
  __int64 v147; // x0
  __int64 v148; // x8
  __int64 v149; // x0
  __int64 v150; // x0
  int v151; // w0
  long double v152; // q0
  long double v153; // q1
  long double v154; // q2
  long double v155; // q3
  float v156; // s4
  unsigned int v157; // w9
  int v158; // w8
  bool v159; // zf
  __int64 v160; // x9
  __int64 v161; // x10
  __int64 v162; // x11
  __int64 v163; // x12
  __int64 v164; // x8
  __int64 v165; // x0
  __int64 v166; // x0
  __int64 v167; // x8
  __int64 v168; // x0
  __int64 v169; // x0
  __int64 v170; // x8
  __int64 v171; // x0
  __int64 v172; // x0
  __int64 v173; // x8
  __int64 v174; // x0
  __int64 v175; // x0
  __int64 v176; // x8
  __int64 v177; // x0
  __int64 v178; // x0
  __int64 v179; // x8
  __int64 v180; // x0
  __int64 v181; // x0
  __int64 v182; // x8
  __int64 v183; // x0
  __int64 v184; // x0
  int v185; // w22
  __int64 v186; // x8
  __int64 v187; // x0
  __int64 v188; // x0
  __int64 v189; // x10
  unsigned __int8 v190; // w23
  __int64 v191; // x8
  __int64 v192; // x0
  __int64 v193; // x0
  __int64 v194; // x8
  __int64 v195; // x0
  __int64 v196; // x0
  __int64 v197; // x8
  __int64 v198; // x0
  __int64 v199; // x0
  __int64 v200; // x8
  __int64 v201; // x0
  __int64 v202; // x0
  __int64 v203; // x0
  __int64 v204; // x0
  unsigned int v205; // w8
  __int64 v206; // x8
  __int64 v207; // x0
  __int64 v208; // x0
  __int64 v209; // x22
  __int64 v210; // x0
  __int64 v211; // x0
  char v212; // w0
  unsigned int v213; // w8
  __int64 v214; // x2
  __int64 v215; // x8
  __int64 v216; // x0
  __int64 v217; // x0
  __int64 v218; // x8
  __int64 v219; // x0
  __int64 v220; // x0
  unsigned int v221; // w23
  __int64 v222; // x28
  __int64 v223; // x0
  __int64 v224; // x8
  __int64 v225; // x0
  __int64 v226; // x0
  __int64 v227; // x22
  __int64 v228; // x8
  __int64 v229; // x0
  __int64 v230; // x0
  int v231; // w8
  int v232; // w9
  __int64 v233; // x8
  __int64 v234; // x0
  __int64 v235; // x0
  _QWORD *v236; // x8
  int v237; // w9
  __int64 v238; // x0
  __int64 v239; // x0
  __int64 v240; // x0
  __int64 v241; // x0
  __int64 v242; // x0
  __int64 v243; // x0
  __int64 v244; // x0
  __int64 v245; // x0
  __int64 v246; // x0
  __int64 v247; // x0
  __int64 v248; // x0
  __int64 v249; // x0
  int v250; // w10
  __int64 v251; // x0
  __int64 v252; // x0
  __int64 v253; // x0
  __int64 v254; // x8
  __int64 v255; // x0
  __int64 v256; // x0
  __int64 v257; // x8
  __int64 v258; // x0
  __int64 v259; // x0
  unsigned int v260; // w8
  signed int v261; // w22
  __int64 v262; // x0
  __int64 v263; // x8
  __int64 v264; // x0
  unsigned int v265; // w10
  _BOOL4 v267; // w10
  __int64 v268; // x11
  __int64 v269; // x0
  __int64 *v270; // x8
  unsigned __int64 v271; // x28
  __int64 v272; // x23
  __int64 v273; // x8
  unsigned __int64 v274; // x8
  bool v275; // cc
  __int64 v276; // x0
  __int64 is_msm_device; // x0
  char v278; // w0
  int v279; // w8
  char v280; // w9
  __int64 v281; // x0
  unsigned int v282; // w0
  __int64 v283; // x9
  __int64 v284; // x8
  unsigned int v285; // w8
  __int64 v286; // x8
  const char *v287; // x8
  __int64 v288; // x0
  __int64 v289; // x0
  __int64 v290; // x8
  __int64 v291; // x0
  __int64 v292; // x0
  int v293; // w0
  __int64 v294; // x8
  int v295; // w19
  __int64 v296; // x0
  __int64 v297; // x0
  __int64 v298; // x0
  __int64 v299; // x0
  __int64 v300; // x0
  __int64 v301; // x0
  __int64 v302; // x8
  __int64 v303; // x0
  __int64 v304; // x0
  int v305; // [xsp+Ch] [xbp-144h]
  unsigned __int64 v306; // [xsp+10h] [xbp-140h] BYREF
  char *v307; // [xsp+18h] [xbp-138h]
  __int64 v308; // [xsp+20h] [xbp-130h]
  __int64 v309; // [xsp+28h] [xbp-128h] BYREF
  __int64 v310; // [xsp+30h] [xbp-120h] BYREF
  __int64 v311; // [xsp+38h] [xbp-118h] BYREF
  __int64 v312; // [xsp+40h] [xbp-110h] BYREF
  __int64 v313; // [xsp+48h] [xbp-108h]
  __int64 v314; // [xsp+50h] [xbp-100h]
  __int64 v315; // [xsp+58h] [xbp-F8h]
  __int64 v316; // [xsp+60h] [xbp-F0h]
  __int64 v317; // [xsp+68h] [xbp-E8h]
  __int64 v318; // [xsp+70h] [xbp-E0h]
  __int64 v319; // [xsp+78h] [xbp-D8h]
  __int64 v320; // [xsp+80h] [xbp-D0h]
  __int64 v321; // [xsp+88h] [xbp-C8h]
  __int64 v322; // [xsp+90h] [xbp-C0h]
  __int64 v323; // [xsp+98h] [xbp-B8h]
  __int64 (__fastcall *v324)(); // [xsp+A0h] [xbp-B0h]
  __int64 v325; // [xsp+A8h] [xbp-A8h]
  __int64 v326; // [xsp+B0h] [xbp-A0h]
  __int64 v327; // [xsp+B8h] [xbp-98h]
  __int64 v328; // [xsp+C0h] [xbp-90h] BYREF
  __int64 v329; // [xsp+C8h] [xbp-88h]
  __int64 v330; // [xsp+D0h] [xbp-80h]
  __int64 v331; // [xsp+D8h] [xbp-78h]
  __int64 v332; // [xsp+E0h] [xbp-70h]
  __int64 v333; // [xsp+E8h] [xbp-68h]
  __int64 v334; // [xsp+F0h] [xbp-60h]
  const void *v335; // [xsp+F8h] [xbp-58h]
  __int64 v336; // [xsp+100h] [xbp-50h]
  __int64 v337; // [xsp+108h] [xbp-48h]
  __int64 v338; // [xsp+110h] [xbp-40h]
  __int64 v339; // [xsp+118h] [xbp-38h]
  __int64 (__fastcall *v340)(); // [xsp+120h] [xbp-30h]
  __int64 v341; // [xsp+128h] [xbp-28h]
  __int64 v342; // [xsp+130h] [xbp-20h]
  __int16 v343; // [xsp+13Ch] [xbp-14h] BYREF
  __int64 v344; // [xsp+140h] [xbp-10h]

  v344 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned int *)(a1 + 192);
  v343 = 0;
  v341 = 0;
  v342 = 0;
  v339 = 0;
  v340 = nullptr;
  v337 = 0;
  v338 = 0;
  v335 = nullptr;
  v336 = 0;
  v333 = 0;
  v334 = 0;
  v331 = 0;
  v332 = 0;
  v329 = 0;
  v330 = 0;
  v328 = 0;
  v326 = 0;
  v327 = 0;
  v324 = nullptr;
  v325 = 0;
  v322 = 0;
  v323 = 0;
  v320 = 0;
  v321 = 0;
  v318 = 0;
  v319 = 0;
  v316 = 0;
  v317 = 0;
  v314 = 0;
  v315 = 0;
  v312 = 0;
  v313 = 0;
  v310 = 0;
  v311 = 0;
  v309 = 0;
  ep_mapping = ipa_get_ep_mapping(v4);
  if ( ep_mapping == -1 )
  {
    printk(&unk_3F4B4C, "ipa3_connect_gsi_wdi_pipe");
    v145 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v146 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v146 )
      {
        ipc_log_string(v146, "ipa %s:%d fail to alloc EP.\n", "ipa3_connect_gsi_wdi_pipe", 1239);
        v145 = ipa3_ctx;
      }
      v147 = *(_QWORD *)(v145 + 34160);
      if ( v147 )
      {
        ipc_log_string(v147, "ipa %s:%d fail to alloc EP.\n", "ipa3_connect_gsi_wdi_pipe", 1239);
LABEL_218:
        v127 = -14;
LABEL_177:
        _ReadStatusReg(SP_EL0);
        return v127;
      }
    }
LABEL_219:
    v127 = -14;
    goto LABEL_177;
  }
  v6 = ep_mapping;
  if ( ep_mapping < 0x25 )
  {
    v7 = ipa3_ctx + 480LL * (int)ep_mapping;
    v9 = *(_DWORD *)(v7 + 168);
    v8 = v7 + 168;
    if ( !v9 )
    {
      v10 = *(unsigned int *)(a1 + 192);
      v307 = "ipa_uc_wdi.c";
      v308 = 1250;
      if ( (unsigned int)v10 <= 0x85 )
        v11 = ipa_clients_strings[v10];
      else
        v11 = "Invalid Client";
      v306 = (unsigned __int64)v11;
      ipa3_inc_client_enable_clks();
      memset((void *)(ipa3_ctx + 480LL * (int)v6 + 168), 0, 0x1E0u);
      v17 = ipa3_ctx;
      v312 = 0;
      v313 = 0;
      v314 = 0;
      v315 = 0;
      v316 = 0;
      v317 = 0;
      v318 = 0;
      v319 = 0;
      v320 = 0;
      v321 = 0;
      v322 = 0;
      v323 = 0;
      v324 = nullptr;
      v325 = 0;
      v326 = 0;
      v327 = 0;
      v328 = 0;
      v329 = 0;
      v330 = 0;
      v331 = 0;
      v332 = 0;
      v333 = 0;
      v334 = 0;
      v335 = nullptr;
      v336 = 0;
      v337 = 0;
      v338 = 0;
      v339 = 0;
      v340 = nullptr;
      v341 = 0;
      v342 = 0;
      if ( ipa3_ctx )
      {
        v18 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v18 )
        {
          ipc_log_string(
            v18,
            "ipa %s:%d client=%d ep=%d\n",
            "ipa3_connect_gsi_wdi_pipe",
            1257,
            *(_DWORD *)(a1 + 192),
            v6);
          v17 = ipa3_ctx;
        }
        v19 = *(_QWORD *)(v17 + 34160);
        if ( v19 )
          ipc_log_string(
            v19,
            "ipa %s:%d client=%d ep=%d\n",
            "ipa3_connect_gsi_wdi_pipe",
            1257,
            *(_DWORD *)(a1 + 192),
            v6);
      }
      v20 = *(_DWORD *)(a1 + 192);
      v21 = ipa3_ctx;
      if ( v20 <= 0x85 && (v20 & 1) != 0 )
      {
        if ( *(_BYTE *)(a1 + 344) )
        {
          if ( ipa3_ctx )
          {
            v22 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v22 )
            {
              ipc_log_string(
                v22,
                "ipa %s:%d comp_ring_size=%d\n",
                "ipa3_connect_gsi_wdi_pipe",
                1262,
                *(_DWORD *)(a1 + 272));
              v21 = ipa3_ctx;
            }
            v23 = *(_QWORD *)(v21 + 34160);
            if ( v23 )
            {
              ipc_log_string(
                v23,
                "ipa %s:%d comp_ring_size=%d\n",
                "ipa3_connect_gsi_wdi_pipe",
                1262,
                *(_DWORD *)(a1 + 272));
              v21 = ipa3_ctx;
            }
            if ( v21 )
            {
              v24 = *(_QWORD *)(v21 + 34152);
              if ( v24 )
              {
                ipc_log_string(
                  v24,
                  "ipa %s:%d ce_ring_size=%d\n",
                  "ipa3_connect_gsi_wdi_pipe",
                  1263,
                  *(_DWORD *)(a1 + 304));
                v21 = ipa3_ctx;
              }
              v25 = *(_QWORD *)(v21 + 34160);
              if ( v25 )
              {
                ipc_log_string(
                  v25,
                  "ipa %s:%d ce_ring_size=%d\n",
                  "ipa3_connect_gsi_wdi_pipe",
                  1263,
                  *(_DWORD *)(a1 + 304));
                v21 = ipa3_ctx;
              }
              if ( v21 )
              {
                v26 = *(_QWORD *)(v21 + 34152);
                if ( v26 )
                {
                  ipc_log_string(
                    v26,
                    "ipa %s:%d ce_ring_doorbell_pa=0x%pa\n",
                    "ipa3_connect_gsi_wdi_pipe",
                    1265,
                    (const void *)(a1 + 296));
                  v21 = ipa3_ctx;
                }
                v27 = *(_QWORD *)(v21 + 34160);
                if ( v27 )
                {
                  ipc_log_string(
                    v27,
                    "ipa %s:%d ce_ring_doorbell_pa=0x%pa\n",
                    "ipa3_connect_gsi_wdi_pipe",
                    1265,
                    (const void *)(a1 + 296));
                  v21 = ipa3_ctx;
                }
                if ( v21 )
                {
                  v28 = *(_QWORD *)(v21 + 34152);
                  if ( v28 )
                  {
                    ipc_log_string(
                      v28,
                      "ipa %s:%d num_tx_buffers=%d\n",
                      "ipa3_connect_gsi_wdi_pipe",
                      1267,
                      *(_DWORD *)(a1 + 308));
                    v21 = ipa3_ctx;
                  }
                  v29 = *(_QWORD *)(v21 + 34160);
                  if ( v29 )
                    ipc_log_string(
                      v29,
                      "ipa %s:%d num_tx_buffers=%d\n",
                      "ipa3_connect_gsi_wdi_pipe",
                      1267,
                      *(_DWORD *)(a1 + 308));
                }
              }
            }
          }
        }
        else if ( ipa3_ctx )
        {
          v133 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v133 )
          {
            ipc_log_string(
              v133,
              "ipa %s:%d comp_ring_base_pa=0x%pa\n",
              "ipa3_connect_gsi_wdi_pipe",
              1270,
              (const void *)(a1 + 256));
            v21 = ipa3_ctx;
          }
          v134 = *(_QWORD *)(v21 + 34160);
          if ( v134 )
          {
            ipc_log_string(
              v134,
              "ipa %s:%d comp_ring_base_pa=0x%pa\n",
              "ipa3_connect_gsi_wdi_pipe",
              1270,
              (const void *)(a1 + 256));
            v21 = ipa3_ctx;
          }
          if ( v21 )
          {
            v135 = *(_QWORD *)(v21 + 34152);
            if ( v135 )
            {
              ipc_log_string(
                v135,
                "ipa %s:%d comp_ring_size=%d\n",
                "ipa3_connect_gsi_wdi_pipe",
                1271,
                *(_DWORD *)(a1 + 264));
              v21 = ipa3_ctx;
            }
            v136 = *(_QWORD *)(v21 + 34160);
            if ( v136 )
            {
              ipc_log_string(
                v136,
                "ipa %s:%d comp_ring_size=%d\n",
                "ipa3_connect_gsi_wdi_pipe",
                1271,
                *(_DWORD *)(a1 + 264));
              v21 = ipa3_ctx;
            }
            if ( v21 )
            {
              v137 = *(_QWORD *)(v21 + 34152);
              if ( v137 )
              {
                ipc_log_string(
                  v137,
                  "ipa %s:%d ce_ring_base_pa=0x%pa\n",
                  "ipa3_connect_gsi_wdi_pipe",
                  1273,
                  (const void *)(a1 + 272));
                v21 = ipa3_ctx;
              }
              v138 = *(_QWORD *)(v21 + 34160);
              if ( v138 )
              {
                ipc_log_string(
                  v138,
                  "ipa %s:%d ce_ring_base_pa=0x%pa\n",
                  "ipa3_connect_gsi_wdi_pipe",
                  1273,
                  (const void *)(a1 + 272));
                v21 = ipa3_ctx;
              }
              if ( v21 )
              {
                v139 = *(_QWORD *)(v21 + 34152);
                if ( v139 )
                {
                  ipc_log_string(
                    v139,
                    "ipa %s:%d ce_ring_size=%d\n",
                    "ipa3_connect_gsi_wdi_pipe",
                    1274,
                    *(_DWORD *)(a1 + 288));
                  v21 = ipa3_ctx;
                }
                v140 = *(_QWORD *)(v21 + 34160);
                if ( v140 )
                {
                  ipc_log_string(
                    v140,
                    "ipa %s:%d ce_ring_size=%d\n",
                    "ipa3_connect_gsi_wdi_pipe",
                    1274,
                    *(_DWORD *)(a1 + 288));
                  v21 = ipa3_ctx;
                }
                if ( v21 )
                {
                  v141 = *(_QWORD *)(v21 + 34152);
                  if ( v141 )
                  {
                    ipc_log_string(
                      v141,
                      "ipa %s:%d ce_ring_doorbell_pa=0x%pa\n",
                      "ipa3_connect_gsi_wdi_pipe",
                      1276,
                      (const void *)(a1 + 280));
                    v21 = ipa3_ctx;
                  }
                  v142 = *(_QWORD *)(v21 + 34160);
                  if ( v142 )
                  {
                    ipc_log_string(
                      v142,
                      "ipa %s:%d ce_ring_doorbell_pa=0x%pa\n",
                      "ipa3_connect_gsi_wdi_pipe",
                      1276,
                      (const void *)(a1 + 280));
                    v21 = ipa3_ctx;
                  }
                  if ( v21 )
                  {
                    v143 = *(_QWORD *)(v21 + 34152);
                    if ( v143 )
                    {
                      ipc_log_string(
                        v143,
                        "ipa %s:%d num_tx_buffers=%d\n",
                        "ipa3_connect_gsi_wdi_pipe",
                        1277,
                        *(_DWORD *)(a1 + 292));
                      v21 = ipa3_ctx;
                    }
                    v144 = *(_QWORD *)(v21 + 34160);
                    if ( v144 )
                      ipc_log_string(
                        v144,
                        "ipa %s:%d num_tx_buffers=%d\n",
                        "ipa3_connect_gsi_wdi_pipe",
                        1277,
                        *(_DWORD *)(a1 + 292));
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        if ( *(_BYTE *)(a1 + 344) )
        {
          if ( ipa3_ctx )
          {
            v30 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v30 )
            {
              ipc_log_string(
                v30,
                "ipa %s:%d rx_ring_size=%d\n",
                "ipa3_connect_gsi_wdi_pipe",
                1282,
                *(_DWORD *)(a1 + 272));
              v21 = ipa3_ctx;
            }
            v31 = *(_QWORD *)(v21 + 34160);
            if ( v31 )
            {
              ipc_log_string(
                v31,
                "ipa %s:%d rx_ring_size=%d\n",
                "ipa3_connect_gsi_wdi_pipe",
                1282,
                *(_DWORD *)(a1 + 272));
              v21 = ipa3_ctx;
            }
            if ( v21 )
            {
              v32 = *(_QWORD *)(v21 + 34152);
              if ( v32 )
              {
                ipc_log_string(
                  v32,
                  "ipa %s:%d rx_ring_rp_pa=0x%pa\n",
                  "ipa3_connect_gsi_wdi_pipe",
                  1284,
                  (const void *)(a1 + 280));
                v21 = ipa3_ctx;
              }
              v33 = *(_QWORD *)(v21 + 34160);
              if ( v33 )
              {
                ipc_log_string(
                  v33,
                  "ipa %s:%d rx_ring_rp_pa=0x%pa\n",
                  "ipa3_connect_gsi_wdi_pipe",
                  1284,
                  (const void *)(a1 + 280));
                v21 = ipa3_ctx;
              }
              if ( v21 )
              {
                v34 = *(_QWORD *)(v21 + 34152);
                if ( v34 )
                {
                  ipc_log_string(
                    v34,
                    "ipa %s:%d rx_comp_ring_size=%d\n",
                    "ipa3_connect_gsi_wdi_pipe",
                    1286,
                    *(_DWORD *)(a1 + 312));
                  v21 = ipa3_ctx;
                }
                v35 = *(_QWORD *)(v21 + 34160);
                if ( v35 )
                {
                  ipc_log_string(
                    v35,
                    "ipa %s:%d rx_comp_ring_size=%d\n",
                    "ipa3_connect_gsi_wdi_pipe",
                    1286,
                    *(_DWORD *)(a1 + 312));
                  v21 = ipa3_ctx;
                }
                if ( v21 )
                {
                  v36 = *(_QWORD *)(v21 + 34152);
                  if ( v36 )
                  {
                    ipc_log_string(
                      v36,
                      "ipa %s:%d rx_comp_ring_wp_pa=0x%pa\n",
                      "ipa3_connect_gsi_wdi_pipe",
                      1288,
                      (const void *)(a1 + 304));
                    v21 = ipa3_ctx;
                  }
                  v37 = *(_QWORD *)(v21 + 34160);
                  if ( v37 )
                  {
                    ipc_log_string(
                      v37,
                      "ipa %s:%d rx_comp_ring_wp_pa=0x%pa\n",
                      "ipa3_connect_gsi_wdi_pipe",
                      1288,
                      (const void *)(a1 + 304));
                    v21 = ipa3_ctx;
                  }
                }
              }
            }
          }
          v38 = v21 + 40960;
          *(_QWORD *)(v38 + 3928) = *(_QWORD *)(a1 + 280);
          *(_DWORD *)(v38 + 3936) = *(_DWORD *)(a1 + 272);
          *(_QWORD *)(v38 + 3952) = *(_QWORD *)(a1 + 304);
          v39 = *(_DWORD *)(a1 + 312);
        }
        else
        {
          if ( ipa3_ctx )
          {
            v40 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v40 )
            {
              ipc_log_string(
                v40,
                "ipa %s:%d rx_ring_base_pa=0x%pa\n",
                "ipa3_connect_gsi_wdi_pipe",
                1299,
                (const void *)(a1 + 256));
              v21 = ipa3_ctx;
            }
            v41 = *(_QWORD *)(v21 + 34160);
            if ( v41 )
            {
              ipc_log_string(
                v41,
                "ipa %s:%d rx_ring_base_pa=0x%pa\n",
                "ipa3_connect_gsi_wdi_pipe",
                1299,
                (const void *)(a1 + 256));
              v21 = ipa3_ctx;
            }
            if ( v21 )
            {
              v42 = *(_QWORD *)(v21 + 34152);
              if ( v42 )
              {
                ipc_log_string(
                  v42,
                  "ipa %s:%d rx_ring_size=%d\n",
                  "ipa3_connect_gsi_wdi_pipe",
                  1301,
                  *(_DWORD *)(a1 + 264));
                v21 = ipa3_ctx;
              }
              v43 = *(_QWORD *)(v21 + 34160);
              if ( v43 )
              {
                ipc_log_string(
                  v43,
                  "ipa %s:%d rx_ring_size=%d\n",
                  "ipa3_connect_gsi_wdi_pipe",
                  1301,
                  *(_DWORD *)(a1 + 264));
                v21 = ipa3_ctx;
              }
              if ( v21 )
              {
                v44 = *(_QWORD *)(v21 + 34152);
                if ( v44 )
                {
                  ipc_log_string(
                    v44,
                    "ipa %s:%d rx_ring_rp_pa=0x%pa\n",
                    "ipa3_connect_gsi_wdi_pipe",
                    1303,
                    (const void *)(a1 + 272));
                  v21 = ipa3_ctx;
                }
                v45 = *(_QWORD *)(v21 + 34160);
                if ( v45 )
                {
                  ipc_log_string(
                    v45,
                    "ipa %s:%d rx_ring_rp_pa=0x%pa\n",
                    "ipa3_connect_gsi_wdi_pipe",
                    1303,
                    (const void *)(a1 + 272));
                  v21 = ipa3_ctx;
                }
                if ( v21 )
                {
                  v46 = *(_QWORD *)(v21 + 34152);
                  if ( v46 )
                  {
                    ipc_log_string(
                      v46,
                      "ipa %s:%d rx_comp_ring_base_pa=0x%pa\n",
                      "ipa3_connect_gsi_wdi_pipe",
                      1305,
                      (const void *)(a1 + 280));
                    v21 = ipa3_ctx;
                  }
                  v47 = *(_QWORD *)(v21 + 34160);
                  if ( v47 )
                  {
                    ipc_log_string(
                      v47,
                      "ipa %s:%d rx_comp_ring_base_pa=0x%pa\n",
                      "ipa3_connect_gsi_wdi_pipe",
                      1305,
                      (const void *)(a1 + 280));
                    v21 = ipa3_ctx;
                  }
                  if ( v21 )
                  {
                    v48 = *(_QWORD *)(v21 + 34152);
                    if ( v48 )
                    {
                      ipc_log_string(
                        v48,
                        "ipa %s:%d rx_comp_ring_size=%d\n",
                        "ipa3_connect_gsi_wdi_pipe",
                        1307,
                        *(_DWORD *)(a1 + 296));
                      v21 = ipa3_ctx;
                    }
                    v49 = *(_QWORD *)(v21 + 34160);
                    if ( v49 )
                    {
                      ipc_log_string(
                        v49,
                        "ipa %s:%d rx_comp_ring_size=%d\n",
                        "ipa3_connect_gsi_wdi_pipe",
                        1307,
                        *(_DWORD *)(a1 + 296));
                      v21 = ipa3_ctx;
                    }
                    if ( v21 )
                    {
                      v50 = *(_QWORD *)(v21 + 34152);
                      if ( v50 )
                      {
                        ipc_log_string(
                          v50,
                          "ipa %s:%d rx_comp_ring_wp_pa=0x%pa\n",
                          "ipa3_connect_gsi_wdi_pipe",
                          1309,
                          (const void *)(a1 + 288));
                        v21 = ipa3_ctx;
                      }
                      v51 = *(_QWORD *)(v21 + 34160);
                      if ( v51 )
                      {
                        ipc_log_string(
                          v51,
                          "ipa %s:%d rx_comp_ring_wp_pa=0x%pa\n",
                          "ipa3_connect_gsi_wdi_pipe",
                          1309,
                          (const void *)(a1 + 288));
                        v21 = ipa3_ctx;
                      }
                    }
                  }
                }
              }
            }
          }
          v38 = v21 + 40960;
          *(_QWORD *)(v38 + 3920) = *(_QWORD *)(a1 + 256);
          *(_QWORD *)(v38 + 3928) = *(_QWORD *)(a1 + 272);
          *(_DWORD *)(v38 + 3936) = *(_DWORD *)(a1 + 264);
          *(_QWORD *)(v38 + 3944) = *(_QWORD *)(a1 + 280);
          *(_QWORD *)(v38 + 3952) = *(_QWORD *)(a1 + 288);
          v39 = *(_DWORD *)(a1 + 296);
        }
        *(_DWORD *)(v38 + 3960) = v39;
      }
      v52 = *(unsigned __int8 *)(a1 + 344);
      v53 = 264;
      v54 = *(_DWORD *)(a1 + 192);
      if ( *(_BYTE *)(a1 + 344) )
        v53 = 272;
      v55 = *(unsigned int *)(a1 + v53);
      v56 = ipa3_ctx;
      if ( v54 <= 0x85 && (v54 & 1) != 0 )
      {
        if ( ipa3_ctx )
        {
          v57 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v57 )
          {
            ipc_log_string(
              v57,
              "ipa %s:%d TX ring smmu_en=%d ring_size=%d %d\n",
              "ipa3_connect_gsi_wdi_pipe",
              1330,
              v52,
              *(_DWORD *)(a1 + 272),
              *(_DWORD *)(a1 + 264));
            v56 = ipa3_ctx;
            v52 = *(unsigned __int8 *)(a1 + 344);
          }
          v58 = *(_QWORD *)(v56 + 34160);
          if ( v58 )
          {
            ipc_log_string(
              v58,
              "ipa %s:%d TX ring smmu_en=%d ring_size=%d %d\n",
              "ipa3_connect_gsi_wdi_pipe",
              1330,
              v52,
              *(_DWORD *)(a1 + 272),
              *(_DWORD *)(a1 + 264));
            LOBYTE(v52) = *(_BYTE *)(a1 + 344);
          }
        }
        if ( (unsigned int)ipa_create_gsi_smmu_mapping(
                             8u,
                             v52 & 1,
                             *(_QWORD *)(a1 + 256),
                             a1 + 256,
                             v55,
                             v12,
                             v13,
                             v14,
                             v15,
                             v16,
                             0,
                             &v311) )
        {
          printk(&unk_3B2D50, "ipa3_connect_gsi_wdi_pipe");
          v167 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v168 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v168 )
            {
              ipc_log_string(v168, "ipa %s:%d fail to create gsi mapping TX ring.\n", "ipa3_connect_gsi_wdi_pipe", 1338);
              v167 = ipa3_ctx;
            }
            v169 = *(_QWORD *)(v167 + 34160);
            if ( v169 )
            {
              ipc_log_string(v169, "ipa %s:%d fail to create gsi mapping TX ring.\n", "ipa3_connect_gsi_wdi_pipe", 1338);
              goto LABEL_254;
            }
          }
          goto LABEL_255;
        }
        v64 = *(unsigned __int8 *)(a1 + 344);
        v65 = 304;
        v335 = nullptr;
        HIDWORD(v331) = v55;
        if ( !v64 )
          v65 = 288;
        v66 = ipa3_ctx;
        v333 = v311;
        v67 = *(unsigned int *)(a1 + v65);
        if ( ipa3_ctx )
        {
          v68 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v68 )
          {
            ipc_log_string(
              v68,
              "ipa %s:%d CE ring smmu_en=%d ring_size=%d %d\n",
              "ipa3_connect_gsi_wdi_pipe",
              1351,
              v64,
              *(_DWORD *)(a1 + 304),
              *(_DWORD *)(a1 + 288));
            v66 = ipa3_ctx;
            v64 = *(unsigned __int8 *)(a1 + 344);
          }
          v69 = *(_QWORD *)(v66 + 34160);
          if ( v69 )
          {
            ipc_log_string(
              v69,
              "ipa %s:%d CE ring smmu_en=%d ring_size=%d %d\n",
              "ipa3_connect_gsi_wdi_pipe",
              1351,
              v64,
              *(_DWORD *)(a1 + 304),
              *(_DWORD *)(a1 + 288));
            LOBYTE(v64) = *(_BYTE *)(a1 + 344);
          }
        }
        if ( (unsigned int)ipa_create_gsi_smmu_mapping(
                             9u,
                             v64 & 1,
                             *(_QWORD *)(a1 + 272),
                             a1 + 280,
                             v67,
                             v59,
                             v60,
                             v61,
                             v62,
                             v63,
                             0,
                             &v311) )
        {
          printk(&unk_3C7A85, "ipa3_connect_gsi_wdi_pipe");
          v173 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v174 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v174 )
            {
              ipc_log_string(v174, "ipa %s:%d fail to create gsi mapping CE ring.\n", "ipa3_connect_gsi_wdi_pipe", 1361);
              v173 = ipa3_ctx;
            }
            v175 = *(_QWORD *)(v173 + 34160);
            if ( v175 )
            {
              ipc_log_string(v175, "ipa %s:%d fail to create gsi mapping CE ring.\n", "ipa3_connect_gsi_wdi_pipe", 1361);
              goto LABEL_254;
            }
          }
          goto LABEL_255;
        }
        v75 = *(_BYTE *)(a1 + 344);
        v76 = 280;
        if ( v75 )
          v76 = 296;
        v314 = v311;
        v315 = 0;
        v77 = *(_QWORD *)(a1 + v76);
        HIDWORD(v313) = v67;
        if ( (unsigned int)ipa_create_gsi_smmu_mapping(0xAu, v75, v77, 0, 4, v70, v71, v72, v73, v74, 0, &v311) )
        {
          printk(&unk_3BBB71, "ipa3_connect_gsi_wdi_pipe");
          v78 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v79 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v79 )
            {
              ipc_log_string(v79, "ipa %s:%d fail to create gsi mapping CE DB.\n", "ipa3_connect_gsi_wdi_pipe", 1377);
              v78 = ipa3_ctx;
            }
            v80 = *(_QWORD *)(v78 + 34160);
            if ( v80 )
            {
              ipc_log_string(v80, "ipa %s:%d fail to create gsi mapping CE DB.\n", "ipa3_connect_gsi_wdi_pipe", 1377);
LABEL_254:
              v127 = -12;
              goto LABEL_173;
            }
          }
          goto LABEL_255;
        }
      }
      else
      {
        if ( ipa3_ctx )
        {
          v81 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v81 )
          {
            ipc_log_string(
              v81,
              "ipa %s:%d RX ring smmu_en=%d ring_size=%d %d\n",
              "ipa3_connect_gsi_wdi_pipe",
              1388,
              v52,
              *(_DWORD *)(a1 + 272),
              *(_DWORD *)(a1 + 264));
            v56 = ipa3_ctx;
            v52 = *(unsigned __int8 *)(a1 + 344);
          }
          v82 = *(_QWORD *)(v56 + 34160);
          if ( v82 )
          {
            ipc_log_string(
              v82,
              "ipa %s:%d RX ring smmu_en=%d ring_size=%d %d\n",
              "ipa3_connect_gsi_wdi_pipe",
              1388,
              v52,
              *(_DWORD *)(a1 + 272),
              *(_DWORD *)(a1 + 264));
            LOBYTE(v52) = *(_BYTE *)(a1 + 344);
          }
        }
        if ( (unsigned int)ipa_create_gsi_smmu_mapping(
                             0,
                             v52 & 1,
                             *(_QWORD *)(a1 + 256),
                             a1 + 256,
                             v55,
                             v12,
                             v13,
                             v14,
                             v15,
                             v16,
                             0,
                             &v311) )
        {
          printk(&unk_3B2D81, "ipa3_connect_gsi_wdi_pipe");
          v164 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v165 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v165 )
            {
              ipc_log_string(v165, "ipa %s:%d fail to create gsi RX ring.\n", "ipa3_connect_gsi_wdi_pipe", 1396);
              v164 = ipa3_ctx;
            }
            v166 = *(_QWORD *)(v164 + 34160);
            if ( v166 )
            {
              ipc_log_string(v166, "ipa %s:%d fail to create gsi RX ring.\n", "ipa3_connect_gsi_wdi_pipe", 1396);
              goto LABEL_254;
            }
          }
LABEL_255:
          v127 = -12;
          goto LABEL_173;
        }
        v88 = *(unsigned __int8 *)(a1 + 344);
        v89 = 312;
        v335 = nullptr;
        HIDWORD(v331) = v55;
        if ( !v88 )
          v89 = 296;
        v90 = ipa3_ctx;
        v333 = v311;
        v91 = *(unsigned int *)(a1 + v89);
        if ( ipa3_ctx )
        {
          v92 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v92 )
          {
            ipc_log_string(
              v92,
              "ipa %s:%d RX ring smmu_en=%d comp_ring_size=%d %d\n",
              "ipa3_connect_gsi_wdi_pipe",
              1409,
              v88,
              *(_DWORD *)(a1 + 312),
              *(_DWORD *)(a1 + 296));
            v90 = ipa3_ctx;
            v88 = *(unsigned __int8 *)(a1 + 344);
          }
          v93 = *(_QWORD *)(v90 + 34160);
          if ( v93 )
          {
            ipc_log_string(
              v93,
              "ipa %s:%d RX ring smmu_en=%d comp_ring_size=%d %d\n",
              "ipa3_connect_gsi_wdi_pipe",
              1409,
              v88,
              *(_DWORD *)(a1 + 312),
              *(_DWORD *)(a1 + 296));
            LOBYTE(v88) = *(_BYTE *)(a1 + 344);
          }
        }
        if ( (unsigned int)ipa_create_gsi_smmu_mapping(
                             2u,
                             v88 & 1,
                             *(_QWORD *)(a1 + 280),
                             a1 + 288,
                             v91,
                             v83,
                             v84,
                             v85,
                             v86,
                             v87,
                             0,
                             &v311) )
        {
          printk(&unk_3EFAC9, "ipa3_connect_gsi_wdi_pipe");
          v170 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v171 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v171 )
            {
              ipc_log_string(v171, "ipa %s:%d fail to create gsi RX comp_ring.\n", "ipa3_connect_gsi_wdi_pipe", 1418);
              v170 = ipa3_ctx;
            }
            v172 = *(_QWORD *)(v170 + 34160);
            if ( v172 )
            {
              ipc_log_string(v172, "ipa %s:%d fail to create gsi RX comp_ring.\n", "ipa3_connect_gsi_wdi_pipe", 1418);
              goto LABEL_254;
            }
          }
          goto LABEL_255;
        }
        v99 = *(_BYTE *)(a1 + 344);
        v100 = 272;
        if ( v99 )
          v100 = 280;
        v314 = v311;
        if ( (unsigned int)ipa_create_gsi_smmu_mapping(
                             1u,
                             v99,
                             *(_QWORD *)(a1 + v100),
                             0,
                             4,
                             v94,
                             v95,
                             v96,
                             v97,
                             v98,
                             0,
                             &v310) )
        {
          printk(&unk_3EFAF7, "ipa3_connect_gsi_wdi_pipe");
          v176 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v177 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v177 )
            {
              ipc_log_string(v177, "ipa %s:%d fail to create gsi RX rng RP\n", "ipa3_connect_gsi_wdi_pipe", 1432);
              v176 = ipa3_ctx;
            }
            v178 = *(_QWORD *)(v176 + 34160);
            if ( v178 )
            {
              ipc_log_string(v178, "ipa %s:%d fail to create gsi RX rng RP\n", "ipa3_connect_gsi_wdi_pipe", 1432);
              goto LABEL_254;
            }
          }
          goto LABEL_255;
        }
        v106 = *(_BYTE *)(a1 + 344);
        v107 = 288;
        if ( v106 )
          v107 = 304;
        v315 = 0;
        v108 = *(_QWORD *)(a1 + v107);
        HIDWORD(v313) = v91;
        if ( (unsigned int)ipa_create_gsi_smmu_mapping(3u, v106, v108, 0, 4, v101, v102, v103, v104, v105, 0, &v311) )
        {
          printk(&unk_3ECD2A, "ipa3_connect_gsi_wdi_pipe");
          v179 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v180 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v180 )
            {
              ipc_log_string(v180, "ipa %s:%d fail to create gsi RX comp_rng WP\n", "ipa3_connect_gsi_wdi_pipe", 1449);
              v179 = ipa3_ctx;
            }
            v181 = *(_QWORD *)(v179 + 34160);
            if ( v181 )
            {
              ipc_log_string(v181, "ipa %s:%d fail to create gsi RX comp_rng WP\n", "ipa3_connect_gsi_wdi_pipe", 1449);
              goto LABEL_254;
            }
          }
          goto LABEL_255;
        }
      }
      v321 = v311;
      *(_DWORD *)v8 = 1;
      *(_DWORD *)(v8 + 4) = *(_DWORD *)(a1 + 192);
      *(_BYTE *)(v8 + 405) = *(_BYTE *)(a1 + 217);
      v109 = *(_BYTE *)(a1 + 216);
      *(_BYTE *)(v8 + 404) = v109;
      *(_QWORD *)(v8 + 376) = *(_QWORD *)(a1 + 208);
      *(_QWORD *)(v8 + 368) = *(_QWORD *)(a1 + 200);
      v110 = *(_DWORD *)(a1 + 192);
      if ( v110 <= 0x85 && (v110 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 112) = 0x100000001LL;
        *(_QWORD *)(a1 + 96) = 0x400000001LL;
        *(_DWORD *)(a1 + 104) = 2;
        v109 = *(_BYTE *)(v8 + 404);
      }
      if ( (v109 & 1) != 0 )
      {
        v111 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v112 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v112 )
          {
            ipc_log_string(v112, "ipa %s:%d Skipping endpoint configuration.\n", "ipa3_connect_gsi_wdi_pipe", 1478);
            v111 = ipa3_ctx;
          }
          v113 = *(_QWORD *)(v111 + 34160);
          if ( v113 )
            ipc_log_string(v113, "ipa %s:%d Skipping endpoint configuration.\n", "ipa3_connect_gsi_wdi_pipe", 1478);
        }
      }
      else
      {
        if ( (unsigned int)ipa3_cfg_ep(v6, a1) )
        {
          printk(&unk_3D5322, "ipa3_connect_gsi_wdi_pipe");
          v182 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v183 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v183 )
            {
              ipc_log_string(v183, "ipa %s:%d fail to configure EP.\n", "ipa3_connect_gsi_wdi_pipe", 1473);
              v182 = ipa3_ctx;
            }
            v184 = *(_QWORD *)(v182 + 34160);
            if ( v184 )
              ipc_log_string(v184, "ipa %s:%d fail to configure EP.\n", "ipa3_connect_gsi_wdi_pipe", 1473);
          }
          goto LABEL_267;
        }
        v114 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v115 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v115 )
          {
            ipc_log_string(v115, "ipa %s:%d ep configuration successful\n", "ipa3_connect_gsi_wdi_pipe", 1476);
            v114 = ipa3_ctx;
          }
          v116 = *(_QWORD *)(v114 + 34160);
          if ( v116 )
            ipc_log_string(v116, "ipa %s:%d ep configuration successful\n", "ipa3_connect_gsi_wdi_pipe", 1476);
        }
      }
      v117 = *(_DWORD *)(a1 + 192);
      v312 = 0x100000004LL;
      LOWORD(v316) = 32;
      if ( (v117 & 1) != 0 || v117 >= 0x86 )
        v119 = 16;
      else
        v119 = 8;
      LODWORD(v313) = v119;
      v120 = (_QWORD *)ipa3_ctx;
      LOBYTE(v323) = 1;
      v324 = ipa_gsi_evt_ring_err_cb_0;
      v325 = 0;
      BYTE2(v316) = 1;
      if ( ipa3_ctx )
      {
        v121 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v121 )
        {
          ipc_log_string(v121, "ipa %s:%d GSI evt ring len: %d\n", "ipa3_wdi2_gsi_alloc_evt_ring", 1126, HIDWORD(v313));
          v120 = (_QWORD *)ipa3_ctx;
        }
        v122 = v120[4270];
        if ( v122 )
        {
          ipc_log_string(v122, "ipa %s:%d GSI evt ring len: %d\n", "ipa3_wdi2_gsi_alloc_evt_ring", 1126, HIDWORD(v313));
          v120 = (_QWORD *)ipa3_ctx;
        }
        if ( v120 )
        {
          v123 = v120[4269];
          if ( v123 )
          {
            ipc_log_string(
              v123,
              "ipa %s:%d client=%d moderation threshold cycles=%u cnt=%u\n",
              "ipa3_wdi2_gsi_alloc_evt_ring",
              1130,
              v117,
              (unsigned __int16)v316,
              BYTE2(v316));
            v120 = (_QWORD *)ipa3_ctx;
          }
          v124 = v120[4270];
          if ( v124 )
          {
            ipc_log_string(
              v124,
              "ipa %s:%d client=%d moderation threshold cycles=%u cnt=%u\n",
              "ipa3_wdi2_gsi_alloc_evt_ring",
              1130,
              v117,
              (unsigned __int16)v316,
              BYTE2(v316));
            v120 = (_QWORD *)ipa3_ctx;
          }
        }
      }
      v125 = gsi_alloc_evt_ring(&v312, v120[5412], v8 + 16);
      v126 = ipa3_ctx;
      v127 = v125;
      if ( ipa3_ctx )
      {
        v128 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v128 )
        {
          ipc_log_string(v128, "ipa %s:%d gsi_alloc_evt_ring result: %d\n", "ipa3_wdi2_gsi_alloc_evt_ring", 1135, v127);
          v126 = ipa3_ctx;
        }
        v129 = *(_QWORD *)(v126 + 34160);
        if ( v129 )
          ipc_log_string(v129, "ipa %s:%d gsi_alloc_evt_ring result: %d\n", "ipa3_wdi2_gsi_alloc_evt_ring", 1135, v127);
      }
      if ( v127 )
        goto LABEL_172;
      v151 = gsi_write_evt_ring_scratch(*(_QWORD *)(v8 + 16), 8);
      if ( v151 )
      {
        v185 = v151;
        printk(&unk_3EA20C, "ipa3_wdi2_gsi_alloc_evt_ring");
        v186 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v187 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v187 )
          {
            ipc_log_string(
              v187,
              "ipa %s:%d Error writing WDI event ring scratch: %d\n",
              "ipa3_wdi2_gsi_alloc_evt_ring",
              1148,
              v185);
            v186 = ipa3_ctx;
          }
          v188 = *(_QWORD *)(v186 + 34160);
          if ( v188 )
            ipc_log_string(
              v188,
              "ipa %s:%d Error writing WDI event ring scratch: %d\n",
              "ipa3_wdi2_gsi_alloc_evt_ring",
              1148,
              v185);
        }
        gsi_dealloc_evt_ring(*(_QWORD *)(v8 + 16));
        goto LABEL_267;
      }
      v157 = *(_DWORD *)(a1 + 192);
      v158 = *(unsigned __int8 *)(a1 + 344);
      if ( v157 <= 0x85 && (v157 & 1) != 0 )
      {
        v159 = v158 == 0;
        v160 = 280;
        v161 = 296;
        v162 = 297;
        v163 = 313;
      }
      else
      {
        v159 = v158 == 0;
        v160 = 288;
        v161 = 304;
        v162 = 321;
        v163 = 337;
      }
      if ( v159 )
      {
        v189 = v162;
      }
      else
      {
        v160 = v161;
        v189 = v163;
      }
      v190 = *(_BYTE *)(a1 + v189);
      v321 = *(_QWORD *)(a1 + v160);
      if ( (v158 & 1) != 0 )
      {
        v191 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v192 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v192 )
          {
            ipc_log_string(v192, "ipa %s:%d smmu enabled\n", "ipa3_connect_gsi_wdi_pipe", 1515);
            v191 = ipa3_ctx;
          }
          v193 = *(_QWORD *)(v191 + 34160);
          if ( v193 )
            ipc_log_string(v193, "ipa %s:%d smmu enabled\n", "ipa3_connect_gsi_wdi_pipe", 1515);
        }
        v194 = ipa3_ctx;
        if ( (v190 & 1) != 0 )
        {
          if ( ipa3_ctx )
          {
            v195 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v195 )
            {
              ipc_log_string(v195, "ipa %s:%d is_evt_rn_db_pcie_addr is PCIE addr\n", "ipa3_connect_gsi_wdi_pipe", 1517);
              v194 = ipa3_ctx;
            }
            v196 = *(_QWORD *)(v194 + 34160);
            if ( v196 )
              ipc_log_string(v196, "ipa %s:%d is_evt_rn_db_pcie_addr is PCIE addr\n", "ipa3_connect_gsi_wdi_pipe", 1517);
          }
        }
        else if ( ipa3_ctx )
        {
          v203 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v203 )
          {
            ipc_log_string(v203, "ipa %s:%d is_evt_rn_db_pcie_addr is DDR addr\n", "ipa3_connect_gsi_wdi_pipe", 1519);
            v194 = ipa3_ctx;
          }
          v204 = *(_QWORD *)(v194 + 34160);
          if ( v204 )
            ipc_log_string(v204, "ipa %s:%d is_evt_rn_db_pcie_addr is DDR addr\n", "ipa3_connect_gsi_wdi_pipe", 1519);
        }
        v205 = *(_DWORD *)(a1 + 192);
        if ( v205 <= 0x85 && (v205 & 1) != 0 )
        {
          if ( (unsigned int)ipa_create_gsi_smmu_mapping(0xAu, 1, v321, 0, 4, v152, v153, v154, v155, v156, 0, &v311) )
          {
            printk(&unk_3C4BDE, "ipa3_connect_gsi_wdi_pipe");
            v206 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v207 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v207 )
              {
                ipc_log_string(v207, "ipa %s:%d failed to get smmu mapping\n", "ipa3_connect_gsi_wdi_pipe", 1525);
                v206 = ipa3_ctx;
              }
              v208 = *(_QWORD *)(v206 + 34160);
              if ( v208 )
                ipc_log_string(v208, "ipa %s:%d failed to get smmu mapping\n", "ipa3_connect_gsi_wdi_pipe", 1525);
            }
LABEL_267:
            v127 = -14;
LABEL_172:
            memset((void *)(ipa3_ctx + 480LL * (int)v6 + 168), 0, 0x1E0u);
LABEL_173:
            ipa_release_ap_smmu_mappings(*(unsigned int *)(a1 + 192));
            v130 = *(unsigned int *)(a1 + 192);
            v307 = "ipa_uc_wdi.c";
            v308 = 1740;
            if ( (unsigned int)v130 <= 0x85 )
              v131 = ipa_clients_strings[v130];
            else
              v131 = "Invalid Client";
            v306 = (unsigned __int64)v131;
            ipa3_dec_client_disable_clks();
            goto LABEL_177;
          }
        }
        else if ( (unsigned int)ipa_create_gsi_smmu_mapping(3u, 1, v321, 0, 4, v152, v153, v154, v155, v156, 0, &v311) )
        {
          printk(&unk_3C4BDE, "ipa3_connect_gsi_wdi_pipe");
          v254 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v255 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v255 )
            {
              ipc_log_string(v255, "ipa %s:%d failed to get smmu mapping\n", "ipa3_connect_gsi_wdi_pipe", 1534);
              v254 = ipa3_ctx;
            }
            v256 = *(_QWORD *)(v254 + 34160);
            if ( v256 )
              ipc_log_string(v256, "ipa %s:%d failed to get smmu mapping\n", "ipa3_connect_gsi_wdi_pipe", 1534);
          }
          goto LABEL_267;
        }
        v209 = v311;
      }
      else
      {
        v197 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v198 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v198 )
          {
            ipc_log_string(v198, "ipa %s:%d smmu disabled\n", "ipa3_connect_gsi_wdi_pipe", 1506);
            v197 = ipa3_ctx;
          }
          v199 = *(_QWORD *)(v197 + 34160);
          if ( v199 )
            ipc_log_string(v199, "ipa %s:%d smmu disabled\n", "ipa3_connect_gsi_wdi_pipe", 1506);
        }
        v200 = ipa3_ctx;
        if ( (v190 & 1) != 0 )
        {
          if ( ipa3_ctx )
          {
            v201 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v201 )
            {
              ipc_log_string(v201, "ipa %s:%d is_evt_rn_db_pcie_addr is PCIE addr\n", "ipa3_connect_gsi_wdi_pipe", 1508);
              v200 = ipa3_ctx;
            }
            v202 = *(_QWORD *)(v200 + 34160);
            if ( v202 )
              ipc_log_string(v202, "ipa %s:%d is_evt_rn_db_pcie_addr is PCIE addr\n", "ipa3_connect_gsi_wdi_pipe", 1508);
          }
        }
        else if ( ipa3_ctx )
        {
          v210 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v210 )
          {
            ipc_log_string(v210, "ipa %s:%d is_evt_rn_db_pcie_addr is DDR addr\n", "ipa3_connect_gsi_wdi_pipe", 1510);
            v200 = ipa3_ctx;
          }
          v211 = *(_QWORD *)(v200 + 34160);
          if ( v211 )
            ipc_log_string(v211, "ipa %s:%d is_evt_rn_db_pcie_addr is DDR addr\n", "ipa3_connect_gsi_wdi_pipe", 1510);
        }
        v209 = v321;
      }
      if ( (((__int64 (*)(void))ipa3_is_msm_device)() & 1) == 0 && (*(_BYTE *)(a1 + 344) & v190 & 1) != 0 )
        v209 = v321;
      v212 = ((__int64 (*)(void))ipa3_is_msm_device)();
      v213 = HIDWORD(v209) | 0x100;
      if ( (v190 & 1) == 0 )
        v213 = HIDWORD(v209);
      if ( (v212 & 1) != 0 )
        v214 = HIDWORD(v209);
      else
        v214 = v213;
      gsi_wdi3_write_evt_ring_db(*(_QWORD *)(v8 + 16), (unsigned int)v209, v214);
      *(_DWORD *)(v8 + 24) = HIDWORD(v313);
      *(_QWORD *)(v8 + 32) = v314;
      *(_QWORD *)(v8 + 40) = v315;
      printk(&unk_3CD56D, "ipa3_connect_gsi_wdi_pipe");
      v215 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v216 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v216 )
        {
          ipc_log_string(v216, "ipa %s:%d evt ring len: %d\n", "ipa3_connect_gsi_wdi_pipe", 1581, *(_DWORD *)(v8 + 24));
          v215 = ipa3_ctx;
        }
        v217 = *(_QWORD *)(v215 + 34160);
        if ( v217 )
          ipc_log_string(v217, "ipa %s:%d evt ring len: %d\n", "ipa3_connect_gsi_wdi_pipe", 1581, *(_DWORD *)(v8 + 24));
      }
      printk(&unk_3A447C, "ipa3_connect_gsi_wdi_pipe");
      v218 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v219 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v219 )
        {
          ipc_log_string(v219, "ipa %s:%d element size: %d\n", "ipa3_connect_gsi_wdi_pipe", 1582, v313);
          v218 = ipa3_ctx;
        }
        v220 = *(_QWORD *)(v218 + 34160);
        if ( v220 )
          ipc_log_string(v220, "ipa %s:%d element size: %d\n", "ipa3_connect_gsi_wdi_pipe", 1582, v313);
      }
      v221 = *(_DWORD *)(a1 + 192);
      v222 = *(_QWORD *)(v8 + 16);
      v223 = ((__int64 (__fastcall *)(_QWORD))ipa_get_gsi_ep_info)(v221);
      if ( v223 )
      {
        v227 = v223;
        if ( v221 > 0x85 || (v221 & 1) != 0 )
        {
          printk(&unk_3EFC5B, "ipa3_wdi2_gsi_alloc_channel_ring");
          v233 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v234 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v234 )
            {
              ipc_log_string(v234, "ipa %s:%d Client is CONS", "ipa3_wdi2_gsi_alloc_channel_ring", 1178);
              v233 = ipa3_ctx;
            }
            v235 = *(_QWORD *)(v233 + 34160);
            if ( v235 )
              ipc_log_string(v235, "ipa %s:%d Client is CONS", "ipa3_wdi2_gsi_alloc_channel_ring", 1178);
          }
          v232 = 0;
          v231 = 8;
        }
        else
        {
          printk(&unk_3F8C96, "ipa3_wdi2_gsi_alloc_channel_ring");
          v228 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v229 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v229 )
            {
              ipc_log_string(v229, "ipa %s:%d Client is PROD\n", "ipa3_wdi2_gsi_alloc_channel_ring", 1174);
              v228 = ipa3_ctx;
            }
            v230 = *(_QWORD *)(v228 + 34160);
            if ( v230 )
              ipc_log_string(v230, "ipa %s:%d Client is PROD\n", "ipa3_wdi2_gsi_alloc_channel_ring", 1174);
          }
          v231 = 16;
          v232 = 1;
        }
        LODWORD(v331) = v231;
        v236 = (_QWORD *)ipa3_ctx;
        LODWORD(v328) = 4;
        HIDWORD(v328) = v232;
        v237 = *(_DWORD *)(v227 + 4);
        v330 = v222;
        LOBYTE(v329) = v237;
        if ( !ipa3_ctx )
          goto LABEL_385;
        v238 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v238 )
        {
          ipc_log_string(v238, "ipa %s:%d ch_id: %d\n", "ipa3_wdi2_gsi_alloc_channel_ring", 1187, (unsigned __int8)v237);
          v236 = (_QWORD *)ipa3_ctx;
        }
        v239 = v236[4270];
        if ( v239 )
        {
          ipc_log_string(v239, "ipa %s:%d ch_id: %d\n", "ipa3_wdi2_gsi_alloc_channel_ring", 1187, (unsigned __int8)v329);
          v236 = (_QWORD *)ipa3_ctx;
        }
        if ( !v236 )
          goto LABEL_385;
        v240 = v236[4269];
        if ( v240 )
        {
          ipc_log_string(v240, "ipa %s:%d evt_ring_hdl: %ld\n", "ipa3_wdi2_gsi_alloc_channel_ring", 1188, v330);
          v236 = (_QWORD *)ipa3_ctx;
        }
        v241 = v236[4270];
        if ( v241 )
        {
          ipc_log_string(v241, "ipa %s:%d evt_ring_hdl: %ld\n", "ipa3_wdi2_gsi_alloc_channel_ring", 1188, v330);
          v236 = (_QWORD *)ipa3_ctx;
        }
        if ( !v236 )
          goto LABEL_385;
        v242 = v236[4269];
        if ( v242 )
        {
          ipc_log_string(v242, "ipa %s:%d re_size: %d\n", "ipa3_wdi2_gsi_alloc_channel_ring", 1189, v331);
          v236 = (_QWORD *)ipa3_ctx;
        }
        v243 = v236[4270];
        if ( v243 )
        {
          ipc_log_string(v243, "ipa %s:%d re_size: %d\n", "ipa3_wdi2_gsi_alloc_channel_ring", 1189, v331);
          v236 = (_QWORD *)ipa3_ctx;
        }
        if ( !v236 )
          goto LABEL_385;
        v244 = v236[4269];
        if ( v244 )
        {
          ipc_log_string(v244, "ipa %s:%d Config GSI xfer cb func", "ipa3_wdi2_gsi_alloc_channel_ring", 1190);
          v236 = (_QWORD *)ipa3_ctx;
        }
        v245 = v236[4270];
        if ( v245 )
        {
          ipc_log_string(v245, "ipa %s:%d Config GSI xfer cb func", "ipa3_wdi2_gsi_alloc_channel_ring", 1190);
          v236 = (_QWORD *)ipa3_ctx;
        }
        if ( v236 )
        {
          v246 = v236[4269];
          if ( v246 )
          {
            ipc_log_string(
              v246,
              "ipa %s:%d GSI channel ring len: %d\n",
              "ipa3_wdi2_gsi_alloc_channel_ring",
              1191,
              HIDWORD(v331));
            v236 = (_QWORD *)ipa3_ctx;
          }
          v247 = v236[4270];
          if ( v247 )
          {
            ipc_log_string(
              v247,
              "ipa %s:%d GSI channel ring len: %d\n",
              "ipa3_wdi2_gsi_alloc_channel_ring",
              1191,
              HIDWORD(v331));
            v236 = (_QWORD *)ipa3_ctx;
          }
          v339 = 0;
          if ( v236 )
          {
            v248 = v236[4269];
            if ( v248 )
            {
              ipc_log_string(
                v248,
                "ipa %s:%d channel ring  base vaddr = 0x%pa\n",
                "ipa3_wdi2_gsi_alloc_channel_ring",
                1195,
                v335);
              v236 = (_QWORD *)ipa3_ctx;
            }
            v249 = v236[4270];
            if ( v249 )
            {
              ipc_log_string(
                v249,
                "ipa %s:%d channel ring  base vaddr = 0x%pa\n",
                "ipa3_wdi2_gsi_alloc_channel_ring",
                1195,
                v335);
              v236 = (_QWORD *)ipa3_ctx;
            }
          }
        }
        else
        {
LABEL_385:
          v236 = nullptr;
          v339 = 0;
        }
        v336 = 1;
        v250 = *(_DWORD *)(v227 + 20);
        LOBYTE(v337) = 1;
        HIDWORD(v337) = v250;
        v340 = ipa_gsi_chan_err_cb_0;
        if ( v236 )
        {
          v251 = v236[4269];
          if ( v251 )
          {
            ipc_log_string(v251, "ipa %s:%d Allocating GSI channel\n", "ipa3_wdi2_gsi_alloc_channel_ring", 1203);
            v236 = (_QWORD *)ipa3_ctx;
          }
          v252 = v236[4270];
          if ( v252 )
          {
            ipc_log_string(v252, "ipa %s:%d Allocating GSI channel\n", "ipa3_wdi2_gsi_alloc_channel_ring", 1203);
            v236 = (_QWORD *)ipa3_ctx;
          }
        }
        v127 = gsi_alloc_channel(&v328, v236[5412], v8 + 8);
        if ( !v127 )
        {
          v257 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v258 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v258 )
            {
              ipc_log_string(
                v258,
                "ipa %s:%d gsi_chan_hdl: %ld\n",
                "ipa3_wdi2_gsi_alloc_channel_ring",
                1210,
                *(_QWORD *)(v8 + 8));
              v257 = ipa3_ctx;
            }
            v259 = *(_QWORD *)(v257 + 34160);
            if ( v259 )
              ipc_log_string(
                v259,
                "ipa %s:%d gsi_chan_hdl: %ld\n",
                "ipa3_wdi2_gsi_alloc_channel_ring",
                1210,
                *(_QWORD *)(v8 + 8));
          }
          v260 = *(_DWORD *)(a1 + 192);
          if ( v260 <= 0x85 && (v260 & 1) == 0 )
          {
            v343 = 256;
            ipa_cfg_ep_ctrl(v6, &v343);
          }
          *(_DWORD *)(v8 + 48) = HIDWORD(v331);
          *(_QWORD *)(v8 + 56) = v333;
          *(_QWORD *)(v8 + 64) = v335;
          v261 = *(_DWORD *)(v8 + 24) / (unsigned int)v313;
          v262 = printk(&unk_3EFB21, "ipa3_connect_gsi_wdi_pipe");
          v263 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v264 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v264 )
            {
              ipc_log_string(
                v264,
                "ipa %s:%d UPDATE_RI_MODERATION_THRESHOLD: %d\n",
                "ipa3_connect_gsi_wdi_pipe",
                1602,
                v261);
              v263 = ipa3_ctx;
            }
            v262 = *(_QWORD *)(v263 + 34160);
            if ( v262 )
            {
              v262 = ipc_log_string(
                       v262,
                       "ipa %s:%d UPDATE_RI_MODERATION_THRESHOLD: %d\n",
                       "ipa3_connect_gsi_wdi_pipe",
                       1602,
                       v261);
              v263 = ipa3_ctx;
            }
          }
          v265 = *(_DWORD *)(a1 + 192);
          v267 = (v265 & 1) == 0 && v265 < 0x86;
          if ( *(_DWORD *)(v263 + 32240) > 0x11u )
          {
            if ( v267 )
            {
              LODWORD(v271) = v310;
              LODWORD(v272) = HIDWORD(v310) & 0xFFFFF;
              v273 = ((unsigned int)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(60, 0, v6) << 14)
                   & 0xFFFF0000
                   | 0xFFFF00000000LL;
            }
            else
            {
              LODWORD(v271) = 0;
              LODWORD(v272) = 0;
              v273 = 0;
            }
            v275 = v261 < 8;
            v274 = v273 & 0xFFFFFFFFFFE0LL;
          }
          else
          {
            if ( v267 )
            {
              v268 = 320;
              if ( *(_BYTE *)(a1 + 344) )
                v268 = 336;
              v305 = *(unsigned __int8 *)(a1 + v268);
              if ( (*(_BYTE *)(a1 + 344) & 1) != 0 )
              {
                if ( v263 )
                {
                  v269 = *(_QWORD *)(v263 + 34152);
                  if ( v269 )
                  {
                    ipc_log_string(v269, "ipa %s:%d smmu eabled\n", "ipa3_connect_gsi_wdi_pipe", 1617);
                    v263 = ipa3_ctx;
                  }
                  v262 = *(_QWORD *)(v263 + 34160);
                  if ( v262 )
                    v262 = ipc_log_string(v262, "ipa %s:%d smmu eabled\n", "ipa3_connect_gsi_wdi_pipe", 1617);
                }
                v270 = &v310;
              }
              else
              {
                if ( v263 )
                {
                  v276 = *(_QWORD *)(v263 + 34152);
                  if ( v276 )
                  {
                    ipc_log_string(v276, "ipa %s:%d smmu disabled\n", "ipa3_connect_gsi_wdi_pipe", 1610);
                    v263 = ipa3_ctx;
                  }
                  v262 = *(_QWORD *)(v263 + 34160);
                  if ( v262 )
                    v262 = ipc_log_string(v262, "ipa %s:%d smmu disabled\n", "ipa3_connect_gsi_wdi_pipe", 1610);
                }
                v270 = (__int64 *)(a1 + 272);
              }
              v271 = *v270;
              is_msm_device = ipa3_is_msm_device(v262);
              if ( (is_msm_device & 1) == 0 && v305 && (*(_BYTE *)(a1 + 344) & 1) != 0 )
                v271 = *(_QWORD *)(a1 + 280);
              v272 = HIDWORD(v271) & 0xFFFFF;
              v278 = ipa3_is_msm_device(is_msm_device);
              v279 = HIDWORD(v271) & 0xFFEFF | 0x100;
              if ( !v305 )
                v279 = HIDWORD(v271) & 0xFFFFF;
              if ( (v278 & 1) == 0 )
                LODWORD(v272) = v279;
              v274 = ((unsigned __int64)(unsigned __int16)((unsigned __int64)((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(
                                                                               60,
                                                                               0,
                                                                               v6) >> 2) << 32)
                   | 0xFFFF0000;
            }
            else
            {
              LODWORD(v271) = 0;
              LODWORD(v272) = 0;
              v274 = 0;
            }
            v275 = v261 < 8;
          }
          if ( v275 )
            v280 = v261;
          else
            v280 = 8;
          v281 = *(_QWORD *)(v8 + 8);
          v306 = __PAIR64__(v272, v271);
          v307 = (char *)(v274 | v280 & 0x1F);
          v308 = 0;
          v282 = gsi_write_channel_scratch(v281, &v306);
          if ( !v282 )
          {
            v283 = *(_QWORD *)(a1 + 352);
            v284 = ipa3_ctx;
            if ( v283 )
            {
              *(_QWORD *)(ipa3_ctx + 43176) = v283;
            }
            else if ( ipa3_ctx )
            {
              v288 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v288 )
              {
                ipc_log_string(v288, "ipa %s:%d in->wdi_notify is null\n", "ipa3_connect_gsi_wdi_pipe", 1705);
                v284 = ipa3_ctx;
              }
              v289 = *(_QWORD *)(v284 + 34160);
              if ( v289 )
                ipc_log_string(v289, "ipa %s:%d in->wdi_notify is null\n", "ipa3_connect_gsi_wdi_pipe", 1705);
            }
            ipa3_enable_data_path(v6);
            if ( (*(_BYTE *)(v8 + 404) & 1) == 0 )
            {
              v285 = *(_DWORD *)(a1 + 192);
              if ( v285 <= 0x85 && (v285 & 1) == 0 )
                ipa3_install_dflt_flt_rules(v6);
            }
            if ( (*(_BYTE *)(v8 + 405) & 1) == 0 )
            {
              v286 = *(unsigned int *)(a1 + 192);
              v307 = "ipa_uc_wdi.c";
              v308 = 1713;
              if ( (unsigned int)v286 <= 0x85 )
                v287 = ipa_clients_strings[v286];
              else
                v287 = "Invalid Client";
              v306 = (unsigned __int64)v287;
              ipa3_dec_client_disable_clks();
            }
            v290 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v291 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v291 )
              {
                ipc_log_string(v291, "ipa %s:%d GSI connected.\n", "ipa3_connect_gsi_wdi_pipe", 1715);
                v290 = ipa3_ctx;
              }
              v292 = *(_QWORD *)(v290 + 34160);
              if ( v292 )
                ipc_log_string(v292, "ipa %s:%d GSI connected.\n", "ipa3_connect_gsi_wdi_pipe", 1715);
            }
            v293 = gsi_query_channel_db_addr(*(_QWORD *)(v8 + 8), (char *)&v309 + 4, &v309);
            *(_QWORD *)a2 = HIDWORD(v309);
            v294 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v295 = v293;
              v296 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v296 )
              {
                ipc_log_string(v296, "ipa %s:%d GSI query result: %d\n", "ipa3_connect_gsi_wdi_pipe", 1720, v295);
                v294 = ipa3_ctx;
              }
              v297 = *(_QWORD *)(v294 + 34160);
              if ( v297 )
              {
                ipc_log_string(v297, "ipa %s:%d GSI query result: %d\n", "ipa3_connect_gsi_wdi_pipe", 1720, v295);
                v294 = ipa3_ctx;
              }
              if ( v294 )
              {
                v298 = *(_QWORD *)(v294 + 34152);
                if ( v298 )
                {
                  ipc_log_string(v298, "ipa %s:%d GSI lsb addr: %d\n", "ipa3_connect_gsi_wdi_pipe", 1721, HIDWORD(v309));
                  v294 = ipa3_ctx;
                }
                v299 = *(_QWORD *)(v294 + 34160);
                if ( v299 )
                {
                  ipc_log_string(v299, "ipa %s:%d GSI lsb addr: %d\n", "ipa3_connect_gsi_wdi_pipe", 1721, HIDWORD(v309));
                  v294 = ipa3_ctx;
                }
                if ( v294 )
                {
                  v300 = *(_QWORD *)(v294 + 34152);
                  if ( v300 )
                  {
                    ipc_log_string(v300, "ipa %s:%d GSI msb addr: %d\n", "ipa3_connect_gsi_wdi_pipe", 1722, v309);
                    v294 = ipa3_ctx;
                  }
                  v301 = *(_QWORD *)(v294 + 34160);
                  if ( v301 )
                    ipc_log_string(v301, "ipa %s:%d GSI msb addr: %d\n", "ipa3_connect_gsi_wdi_pipe", 1722, v309);
                }
              }
            }
            v127 = 0;
            *(_DWORD *)(v8 + 452) |= 1u;
            *(_DWORD *)(a2 + 8) = v6;
            goto LABEL_177;
          }
          v127 = v282;
          printk(&unk_3EFB51, "ipa3_connect_gsi_wdi_pipe");
          v302 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v303 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v303 )
            {
              ipc_log_string(
                v303,
                "ipa %s:%d gsi_write_channel_scratch failed %d\n",
                "ipa3_connect_gsi_wdi_pipe",
                1697,
                v127);
              v302 = ipa3_ctx;
            }
            v304 = *(_QWORD *)(v302 + 34160);
            if ( v304 )
              ipc_log_string(
                v304,
                "ipa %s:%d gsi_write_channel_scratch failed %d\n",
                "ipa3_connect_gsi_wdi_pipe",
                1697,
                v127);
          }
          gsi_dealloc_channel(*(_QWORD *)(v8 + 8));
        }
      }
      else
      {
        printk(&unk_3CC819, "ipa3_wdi2_gsi_alloc_channel_ring");
        v224 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v225 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v225 )
          {
            ipc_log_string(
              v225,
              "ipa %s:%d Failed getting GSI EP info for client=%d\n",
              "ipa3_wdi2_gsi_alloc_channel_ring",
              1169,
              v221);
            v224 = ipa3_ctx;
          }
          v226 = *(_QWORD *)(v224 + 34160);
          if ( v226 )
            ipc_log_string(
              v226,
              "ipa %s:%d Failed getting GSI EP info for client=%d\n",
              "ipa3_wdi2_gsi_alloc_channel_ring",
              1169,
              v221);
        }
        v127 = -1;
      }
      v253 = *(_QWORD *)(v8 + 16);
      if ( v253 != -1 )
      {
        gsi_dealloc_evt_ring(v253);
        *(_QWORD *)(v8 + 16) = -1;
      }
      goto LABEL_172;
    }
    printk(&unk_3F4B6B, "ipa3_connect_gsi_wdi_pipe");
    v148 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v149 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v149 )
      {
        ipc_log_string(v149, "ipa %s:%d EP already allocated.\n", "ipa3_connect_gsi_wdi_pipe", 1246);
        v148 = ipa3_ctx;
      }
      v150 = *(_QWORD *)(v148 + 34160);
      if ( v150 )
      {
        ipc_log_string(v150, "ipa %s:%d EP already allocated.\n", "ipa3_connect_gsi_wdi_pipe", 1246);
        goto LABEL_218;
      }
    }
    goto LABEL_219;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))ipa_release_ap_smmu_mappings)();
}
