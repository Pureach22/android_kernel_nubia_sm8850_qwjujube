__int64 __fastcall ipa_connect_wdi_pipe(__int64 a1, _DWORD *a2)
{
  __int64 result; // x0
  unsigned int v4; // w9
  __int64 v5; // x10
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int ep_mapping; // w0
  __int64 v11; // x9
  char v12; // b26
  unsigned int v13; // w20
  __int64 v14; // x21
  _DWORD *v15; // x21
  int v16; // t1
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  unsigned int v25; // w11
  int v26; // w11
  int v27; // w10
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  int v36; // w11
  int v37; // w10
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x8
  int v47; // w9
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  long double v61; // q0
  long double v62; // q1
  long double v63; // q2
  long double v64; // q3
  float v65; // s4
  int v66; // w4
  __int64 v67; // x8
  __int64 v68; // x12
  unsigned int v69; // w10
  _BYTE *v70; // x9
  _DWORD *v71; // x23
  __int64 v72; // x24
  __int64 v73; // x0
  __int64 v74; // x0
  long double v75; // q0
  long double v76; // q1
  long double v77; // q2
  long double v78; // q3
  float v79; // s4
  unsigned __int64 v80; // x5
  __int64 v81; // x8
  __int64 v82; // x0
  __int64 v83; // x0
  int v84; // w4
  __int64 v85; // x9
  unsigned int v86; // w24
  __int64 v87; // x0
  __int64 v88; // x0
  __int64 v89; // x0
  __int64 v90; // x0
  long double v91; // q0
  long double v92; // q1
  long double v93; // q2
  long double v94; // q3
  float v95; // s4
  unsigned __int64 v96; // x5
  __int64 v97; // x8
  __int64 v98; // x0
  __int64 v99; // x0
  char v100; // w1
  __int64 v101; // x8
  long double v102; // q0
  long double v103; // q1
  long double v104; // q2
  long double v105; // q3
  float v106; // s4
  unsigned __int64 v107; // x5
  __int64 v108; // x8
  __int64 v109; // x0
  __int64 v110; // x0
  int v111; // w4
  __int64 v112; // x9
  unsigned int v113; // w24
  __int64 v114; // x0
  __int64 v115; // x0
  __int64 v116; // x0
  __int64 v117; // x0
  __int64 v118; // x0
  __int64 v119; // x0
  __int64 v120; // x0
  __int64 v121; // x0
  __int64 v122; // x0
  __int64 v123; // x0
  __int64 v124; // x0
  __int64 v125; // x0
  __int64 v126; // x0
  __int64 v127; // x0
  __int64 v128; // x0
  __int64 v129; // x0
  long double v130; // q0
  long double v131; // q1
  long double v132; // q2
  long double v133; // q3
  float v134; // s4
  __int64 v135; // x8
  char v136; // w1
  __int64 v137; // x0
  __int64 v138; // x1
  __int64 v139; // x2
  __int64 v140; // x8
  __int64 v141; // x0
  __int64 v142; // x0
  long double v143; // q0
  long double v144; // q1
  long double v145; // q2
  long double v146; // q3
  float v147; // s4
  unsigned __int64 v148; // x25
  __int64 v149; // x9
  int v150; // w4
  __int64 v151; // x8
  __int64 v152; // x24
  __int64 v153; // x0
  __int64 v154; // x0
  long double v155; // q0
  long double v156; // q1
  long double v157; // q2
  long double v158; // q3
  float v159; // s4
  int v160; // w8
  __int64 v161; // x8
  char v162; // w1
  __int64 v163; // x8
  __int64 v164; // x0
  __int64 v165; // x0
  const char *v166; // x4
  const char *v167; // x4
  unsigned __int64 *v168; // x9
  __int64 v169; // x10
  __int64 v170; // x9
  __int64 v171; // x8
  __int64 v172; // x0
  __int64 v173; // x0
  __int64 v174; // x8
  long double v175; // q0
  long double v176; // q1
  long double v177; // q2
  long double v178; // q3
  float v179; // s4
  int v180; // w4
  int v181; // w5
  __int64 v182; // x8
  __int64 v183; // x0
  __int64 v184; // x0
  char v185; // w1
  __int64 v186; // x8
  unsigned __int64 v187; // x5
  __int64 v188; // x0
  __int64 v189; // x11
  unsigned int v190; // w23
  __int64 v191; // x8
  long double v192; // q0
  long double v193; // q1
  long double v194; // q2
  long double v195; // q3
  float v196; // s4
  int v197; // w4
  int v198; // w5
  __int64 v199; // x8
  __int64 v200; // x0
  __int64 v201; // x0
  char v202; // w1
  __int64 v203; // x8
  unsigned __int64 v204; // x5
  __int64 v205; // x8
  __int64 v206; // x0
  int v207; // w25
  int reg_base; // w24
  unsigned int v209; // w0
  unsigned int v210; // w8
  unsigned __int8 v211; // w9
  unsigned int v212; // w1
  unsigned int v213; // w21
  __int64 v214; // x9
  __int64 v215; // x8
  unsigned int v216; // w8
  __int64 v217; // x8
  __int64 v218; // x0
  __int64 v219; // x0
  __int64 v220; // x8
  __int64 v221; // x0
  __int64 v222; // x0
  unsigned int v223; // w8
  __int64 v224; // x0
  __int64 v225; // x0
  __int64 v226; // x8
  __int64 v227; // x0
  __int64 v228; // x8
  __int64 v229; // x0
  __int64 v230; // x8
  __int64 v231; // x0
  __int64 v232; // x8
  __int64 v233; // x0
  __int64 v234; // x0
  __int64 v235; // x8
  __int64 v236; // x0
  __int64 v237; // x0
  __int64 v238; // x8
  __int64 v239; // x0
  __int64 v240; // x0
  __int64 v241; // x8
  __int64 v242; // x0
  __int64 v243; // x0
  __int64 v244; // x8
  __int64 v245; // x0
  __int64 v246; // x0
  __int64 v247; // x8
  __int64 v248; // x0
  __int64 v249; // x0
  __int64 v250; // x8
  __int64 v251; // x0
  __int64 v252; // x0
  __int64 v253; // x8
  __int64 v254; // x0
  __int64 v255; // x0
  __int64 v256; // x8
  __int64 v257; // x0
  __int64 v258; // x0
  __int64 v259; // x8
  __int64 v260; // x0
  __int64 v261; // x0
  __int64 v262; // x8
  __int64 v263; // x0
  __int64 v264; // x0
  __int64 v265; // x8
  __int64 v266; // x0
  __int64 v267; // x0
  __int64 v268; // x8
  __int64 v269; // x0
  __int64 v270; // x0
  __int64 v271; // x8
  __int64 v272; // x0
  __int64 v273; // x0
  __int64 v274; // x8
  __int64 v275; // x0
  __int64 v276; // x0
  __int64 v277; // x8
  __int64 v278; // x0
  __int64 v279; // x0
  unsigned __int64 v280; // [xsp+18h] [xbp-38h] BYREF
  unsigned __int64 v281; // [xsp+20h] [xbp-30h] BYREF
  __int16 v282; // [xsp+2Ch] [xbp-24h] BYREF
  __int64 v283; // [xsp+30h] [xbp-20h]
  __int64 v284; // [xsp+38h] [xbp-18h] BYREF
  __int64 v285; // [xsp+40h] [xbp-10h]
  __int64 v286; // [xsp+48h] [xbp-8h]

  v286 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v284 = 0;
  v285 = 0;
  v283 = 0;
  v282 = 0;
  v280 = 0;
  v281 = 0;
  if ( *(_BYTE *)(ipa3_ctx + 51102) == 1 )
  {
    result = ipa_pm_wrapper_connect_wdi_pipe(a1);
LABEL_338:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( !a1 || !a2 || (v4 = *(_DWORD *)(a1 + 192), v4 >= 0x86) )
  {
    printk(&unk_3D8F29, "ipa_connect_wdi_pipe");
    v18 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        ipc_log_string(v19, "ipa %s:%d bad parm. in=%pK out=%pK\n", "ipa_connect_wdi_pipe", 1775, (const void *)a1, a2);
        v18 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v18 + 34160);
      if ( v20 )
        ipc_log_string(v20, "ipa %s:%d bad parm. in=%pK out=%pK\n", "ipa_connect_wdi_pipe", 1775, (const void *)a1, a2);
    }
    if ( a1 )
    {
      printk(&unk_3B8B46, "ipa_connect_wdi_pipe");
      v238 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v239 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v239 )
        {
          ipc_log_string(v239, "ipa %s:%d client = %d\n", "ipa_connect_wdi_pipe", 1777, *(_DWORD *)(a1 + 192));
          v238 = ipa3_ctx;
        }
        v240 = *(_QWORD *)(v238 + 34160);
        if ( v240 )
        {
          ipc_log_string(v240, "ipa %s:%d client = %d\n", "ipa_connect_wdi_pipe", 1777, *(_DWORD *)(a1 + 192));
          result = 4294967274LL;
          goto LABEL_338;
        }
      }
    }
    goto LABEL_30;
  }
  if ( (*(_BYTE *)(a1 + 344) & 1) == 0 )
  {
    v5 = *(_QWORD *)(a1 + 256) & 7LL;
    if ( (v4 & 1) != 0 )
    {
      if ( v5 || (*(_BYTE *)(a1 + 272) & 7) != 0 )
      {
        printk(&unk_3E6F8B, "ipa_connect_wdi_pipe");
        v171 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v172 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v172 )
          {
            ipc_log_string(v172, "ipa %s:%d alignment failure on TX\n", "ipa_connect_wdi_pipe", 1787);
            v171 = ipa3_ctx;
          }
          v173 = *(_QWORD *)(v171 + 34160);
          if ( v173 )
          {
            ipc_log_string(v173, "ipa %s:%d alignment failure on TX\n", "ipa_connect_wdi_pipe", 1787);
            goto LABEL_251;
          }
        }
LABEL_30:
        result = 4294967274LL;
        goto LABEL_338;
      }
    }
    else if ( v5 )
    {
      printk(&unk_3CD5C7, "ipa_connect_wdi_pipe");
      v6 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v7 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v7 )
        {
          ipc_log_string(v7, "ipa %s:%d alignment failure on RX\n", "ipa_connect_wdi_pipe", 1793);
          v6 = ipa3_ctx;
        }
        v8 = *(_QWORD *)(v6 + 34160);
        if ( v8 )
        {
          ipc_log_string(v8, "ipa %s:%d alignment failure on RX\n", "ipa_connect_wdi_pipe", 1793);
LABEL_251:
          result = 4294967274LL;
          goto LABEL_338;
        }
      }
      goto LABEL_30;
    }
  }
  if ( *(_BYTE *)(ipa3_ctx + 32265) == 1 && (unsigned int)ipa_get_wdi_version() == 1 )
  {
    result = ipa3_connect_gsi_wdi_pipe(a1, (__int64)a2);
    goto LABEL_338;
  }
  result = ipa3_uc_state_check();
  if ( (_DWORD)result )
    goto LABEL_338;
  ep_mapping = ipa_get_ep_mapping(*(unsigned int *)(a1 + 192));
  if ( ep_mapping == -1 )
  {
    printk(&unk_3F4B4C, "ipa_connect_wdi_pipe");
    v228 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_337;
    v229 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v229 )
    {
      ipc_log_string(v229, "ipa %s:%d fail to alloc EP.\n", "ipa_connect_wdi_pipe", 1808);
      v228 = ipa3_ctx;
    }
    result = *(_QWORD *)(v228 + 34160);
    if ( !result )
      goto LABEL_338;
    ipc_log_string(result, "ipa %s:%d fail to alloc EP.\n", "ipa_connect_wdi_pipe", 1808);
    goto LABEL_349;
  }
  v13 = ep_mapping;
  if ( ep_mapping < 0x25 )
  {
    v14 = ipa3_ctx + 480LL * (int)ep_mapping;
    v16 = *(_DWORD *)(v14 + 168);
    v15 = (_DWORD *)(v14 + 168);
    if ( !v16 )
    {
      memset(v15, 0, 0x1E0u);
      ipa3_inc_client_enable_clks();
      v21 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v22 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v22 )
        {
          ipc_log_string(v22, "ipa %s:%d client=%d ep=%d\n", "ipa_connect_wdi_pipe", 1822, *(_DWORD *)(a1 + 192), v13);
          v21 = ipa3_ctx;
        }
        v23 = *(_QWORD *)(v21 + 34160);
        if ( v23 )
          ipc_log_string(v23, "ipa %s:%d client=%d ep=%d\n", "ipa_connect_wdi_pipe", 1822, *(_DWORD *)(a1 + 192), v13);
      }
      v24 = ipa3_ctx;
      v25 = *(_DWORD *)(a1 + 192);
      if ( v25 <= 0x85 && (v25 & 1) != 0 )
      {
        v26 = *(unsigned __int8 *)(a1 + 344);
        if ( *(_BYTE *)(ipa3_ctx + 32263) )
          v27 = 36;
        else
          v27 = 24;
        LODWORD(v285) = v27;
        if ( v26 == 1 )
        {
          if ( ipa3_ctx )
          {
            v28 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v28 )
            {
              ipc_log_string(v28, "ipa %s:%d comp_ring_size=%d\n", "ipa_connect_wdi_pipe", 1830, *(_DWORD *)(a1 + 272));
              v24 = ipa3_ctx;
            }
            v29 = *(_QWORD *)(v24 + 34160);
            if ( v29 )
            {
              ipc_log_string(v29, "ipa %s:%d comp_ring_size=%d\n", "ipa_connect_wdi_pipe", 1830, *(_DWORD *)(a1 + 272));
              v24 = ipa3_ctx;
            }
            if ( v24 )
            {
              v30 = *(_QWORD *)(v24 + 34152);
              if ( v30 )
              {
                ipc_log_string(v30, "ipa %s:%d ce_ring_size=%d\n", "ipa_connect_wdi_pipe", 1831, *(_DWORD *)(a1 + 304));
                v24 = ipa3_ctx;
              }
              v31 = *(_QWORD *)(v24 + 34160);
              if ( v31 )
              {
                ipc_log_string(v31, "ipa %s:%d ce_ring_size=%d\n", "ipa_connect_wdi_pipe", 1831, *(_DWORD *)(a1 + 304));
                v24 = ipa3_ctx;
              }
              if ( v24 )
              {
                v32 = *(_QWORD *)(v24 + 34152);
                if ( v32 )
                {
                  ipc_log_string(
                    v32,
                    "ipa %s:%d ce_ring_doorbell_pa=0x%pa\n",
                    "ipa_connect_wdi_pipe",
                    1833,
                    (const void *)(a1 + 296));
                  v24 = ipa3_ctx;
                }
                v33 = *(_QWORD *)(v24 + 34160);
                if ( v33 )
                {
                  ipc_log_string(
                    v33,
                    "ipa %s:%d ce_ring_doorbell_pa=0x%pa\n",
                    "ipa_connect_wdi_pipe",
                    1833,
                    (const void *)(a1 + 296));
                  v24 = ipa3_ctx;
                }
                if ( v24 )
                {
                  v34 = *(_QWORD *)(v24 + 34152);
                  if ( v34 )
                  {
                    ipc_log_string(
                      v34,
                      "ipa %s:%d num_tx_buffers=%d\n",
                      "ipa_connect_wdi_pipe",
                      1835,
                      *(_DWORD *)(a1 + 308));
                    v24 = ipa3_ctx;
                  }
                  v35 = *(_QWORD *)(v24 + 34160);
                  if ( v35 )
                    ipc_log_string(
                      v35,
                      "ipa %s:%d num_tx_buffers=%d\n",
                      "ipa_connect_wdi_pipe",
                      1835,
                      *(_DWORD *)(a1 + 308));
                }
              }
            }
          }
        }
        else if ( ipa3_ctx )
        {
          v116 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v116 )
          {
            ipc_log_string(
              v116,
              "ipa %s:%d comp_ring_base_pa=0x%pa\n",
              "ipa_connect_wdi_pipe",
              1838,
              (const void *)(a1 + 256));
            v24 = ipa3_ctx;
          }
          v117 = *(_QWORD *)(v24 + 34160);
          if ( v117 )
          {
            ipc_log_string(
              v117,
              "ipa %s:%d comp_ring_base_pa=0x%pa\n",
              "ipa_connect_wdi_pipe",
              1838,
              (const void *)(a1 + 256));
            v24 = ipa3_ctx;
          }
          if ( v24 )
          {
            v118 = *(_QWORD *)(v24 + 34152);
            if ( v118 )
            {
              ipc_log_string(v118, "ipa %s:%d comp_ring_size=%d\n", "ipa_connect_wdi_pipe", 1839, *(_DWORD *)(a1 + 264));
              v24 = ipa3_ctx;
            }
            v119 = *(_QWORD *)(v24 + 34160);
            if ( v119 )
            {
              ipc_log_string(v119, "ipa %s:%d comp_ring_size=%d\n", "ipa_connect_wdi_pipe", 1839, *(_DWORD *)(a1 + 264));
              v24 = ipa3_ctx;
            }
            if ( v24 )
            {
              v120 = *(_QWORD *)(v24 + 34152);
              if ( v120 )
              {
                ipc_log_string(
                  v120,
                  "ipa %s:%d ce_ring_base_pa=0x%pa\n",
                  "ipa_connect_wdi_pipe",
                  1841,
                  (const void *)(a1 + 272));
                v24 = ipa3_ctx;
              }
              v121 = *(_QWORD *)(v24 + 34160);
              if ( v121 )
              {
                ipc_log_string(
                  v121,
                  "ipa %s:%d ce_ring_base_pa=0x%pa\n",
                  "ipa_connect_wdi_pipe",
                  1841,
                  (const void *)(a1 + 272));
                v24 = ipa3_ctx;
              }
              if ( v24 )
              {
                v122 = *(_QWORD *)(v24 + 34152);
                if ( v122 )
                {
                  ipc_log_string(
                    v122,
                    "ipa %s:%d ce_ring_size=%d\n",
                    "ipa_connect_wdi_pipe",
                    1842,
                    *(_DWORD *)(a1 + 288));
                  v24 = ipa3_ctx;
                }
                v123 = *(_QWORD *)(v24 + 34160);
                if ( v123 )
                {
                  ipc_log_string(
                    v123,
                    "ipa %s:%d ce_ring_size=%d\n",
                    "ipa_connect_wdi_pipe",
                    1842,
                    *(_DWORD *)(a1 + 288));
                  v24 = ipa3_ctx;
                }
                if ( v24 )
                {
                  v124 = *(_QWORD *)(v24 + 34152);
                  if ( v124 )
                  {
                    ipc_log_string(
                      v124,
                      "ipa %s:%d ce_ring_doorbell_pa=0x%pa\n",
                      "ipa_connect_wdi_pipe",
                      1844,
                      (const void *)(a1 + 280));
                    v24 = ipa3_ctx;
                  }
                  v125 = *(_QWORD *)(v24 + 34160);
                  if ( v125 )
                  {
                    ipc_log_string(
                      v125,
                      "ipa %s:%d ce_ring_doorbell_pa=0x%pa\n",
                      "ipa_connect_wdi_pipe",
                      1844,
                      (const void *)(a1 + 280));
                    v24 = ipa3_ctx;
                  }
                  if ( v24 )
                  {
                    v126 = *(_QWORD *)(v24 + 34152);
                    if ( v126 )
                    {
                      ipc_log_string(
                        v126,
                        "ipa %s:%d num_tx_buffers=%d\n",
                        "ipa_connect_wdi_pipe",
                        1845,
                        *(_DWORD *)(a1 + 292));
                      v24 = ipa3_ctx;
                    }
                    v127 = *(_QWORD *)(v24 + 34160);
                    if ( v127 )
                      ipc_log_string(
                        v127,
                        "ipa %s:%d num_tx_buffers=%d\n",
                        "ipa_connect_wdi_pipe",
                        1845,
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
        v36 = *(unsigned __int8 *)(a1 + 344);
        if ( *(_BYTE *)(ipa3_ctx + 32263) )
          v37 = 41;
        else
          v37 = 13;
        LODWORD(v285) = v37;
        if ( v36 == 1 )
        {
          if ( ipa3_ctx )
          {
            v38 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v38 )
            {
              ipc_log_string(v38, "ipa %s:%d rx_ring_size=%d\n", "ipa_connect_wdi_pipe", 1854, *(_DWORD *)(a1 + 272));
              v24 = ipa3_ctx;
            }
            v39 = *(_QWORD *)(v24 + 34160);
            if ( v39 )
            {
              ipc_log_string(v39, "ipa %s:%d rx_ring_size=%d\n", "ipa_connect_wdi_pipe", 1854, *(_DWORD *)(a1 + 272));
              v24 = ipa3_ctx;
            }
            if ( v24 )
            {
              v40 = *(_QWORD *)(v24 + 34152);
              if ( v40 )
              {
                ipc_log_string(
                  v40,
                  "ipa %s:%d rx_ring_rp_pa=0x%pa\n",
                  "ipa_connect_wdi_pipe",
                  1856,
                  (const void *)(a1 + 280));
                v24 = ipa3_ctx;
              }
              v41 = *(_QWORD *)(v24 + 34160);
              if ( v41 )
              {
                ipc_log_string(
                  v41,
                  "ipa %s:%d rx_ring_rp_pa=0x%pa\n",
                  "ipa_connect_wdi_pipe",
                  1856,
                  (const void *)(a1 + 280));
                v24 = ipa3_ctx;
              }
              if ( v24 )
              {
                v42 = *(_QWORD *)(v24 + 34152);
                if ( v42 )
                {
                  ipc_log_string(
                    v42,
                    "ipa %s:%d rx_comp_ring_size=%d\n",
                    "ipa_connect_wdi_pipe",
                    1858,
                    *(_DWORD *)(a1 + 312));
                  v24 = ipa3_ctx;
                }
                v43 = *(_QWORD *)(v24 + 34160);
                if ( v43 )
                {
                  ipc_log_string(
                    v43,
                    "ipa %s:%d rx_comp_ring_size=%d\n",
                    "ipa_connect_wdi_pipe",
                    1858,
                    *(_DWORD *)(a1 + 312));
                  v24 = ipa3_ctx;
                }
                if ( v24 )
                {
                  v44 = *(_QWORD *)(v24 + 34152);
                  if ( v44 )
                  {
                    ipc_log_string(
                      v44,
                      "ipa %s:%d rx_comp_ring_wp_pa=0x%pa\n",
                      "ipa_connect_wdi_pipe",
                      1860,
                      (const void *)(a1 + 304));
                    v24 = ipa3_ctx;
                  }
                  v45 = *(_QWORD *)(v24 + 34160);
                  if ( v45 )
                  {
                    ipc_log_string(
                      v45,
                      "ipa %s:%d rx_comp_ring_wp_pa=0x%pa\n",
                      "ipa_connect_wdi_pipe",
                      1860,
                      (const void *)(a1 + 304));
                    v24 = ipa3_ctx;
                  }
                }
              }
            }
          }
          v46 = v24 + 0x8000;
          *(_QWORD *)(v46 + 2032) = *(_QWORD *)(a1 + 280);
          *(_DWORD *)(v46 + 2040) = *(_DWORD *)(a1 + 272);
          *(_QWORD *)(v46 + 2056) = *(_QWORD *)(a1 + 304);
          v47 = *(_DWORD *)(a1 + 312);
        }
        else
        {
          if ( ipa3_ctx )
          {
            v48 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v48 )
            {
              ipc_log_string(
                v48,
                "ipa %s:%d rx_ring_base_pa=0x%pa\n",
                "ipa_connect_wdi_pipe",
                1871,
                (const void *)(a1 + 256));
              v24 = ipa3_ctx;
            }
            v49 = *(_QWORD *)(v24 + 34160);
            if ( v49 )
            {
              ipc_log_string(
                v49,
                "ipa %s:%d rx_ring_base_pa=0x%pa\n",
                "ipa_connect_wdi_pipe",
                1871,
                (const void *)(a1 + 256));
              v24 = ipa3_ctx;
            }
            if ( v24 )
            {
              v50 = *(_QWORD *)(v24 + 34152);
              if ( v50 )
              {
                ipc_log_string(v50, "ipa %s:%d rx_ring_size=%d\n", "ipa_connect_wdi_pipe", 1873, *(_DWORD *)(a1 + 264));
                v24 = ipa3_ctx;
              }
              v51 = *(_QWORD *)(v24 + 34160);
              if ( v51 )
              {
                ipc_log_string(v51, "ipa %s:%d rx_ring_size=%d\n", "ipa_connect_wdi_pipe", 1873, *(_DWORD *)(a1 + 264));
                v24 = ipa3_ctx;
              }
              if ( v24 )
              {
                v52 = *(_QWORD *)(v24 + 34152);
                if ( v52 )
                {
                  ipc_log_string(
                    v52,
                    "ipa %s:%d rx_ring_rp_pa=0x%pa\n",
                    "ipa_connect_wdi_pipe",
                    1875,
                    (const void *)(a1 + 272));
                  v24 = ipa3_ctx;
                }
                v53 = *(_QWORD *)(v24 + 34160);
                if ( v53 )
                {
                  ipc_log_string(
                    v53,
                    "ipa %s:%d rx_ring_rp_pa=0x%pa\n",
                    "ipa_connect_wdi_pipe",
                    1875,
                    (const void *)(a1 + 272));
                  v24 = ipa3_ctx;
                }
                if ( v24 )
                {
                  v54 = *(_QWORD *)(v24 + 34152);
                  if ( v54 )
                  {
                    ipc_log_string(
                      v54,
                      "ipa %s:%d rx_comp_ring_base_pa=0x%pa\n",
                      "ipa_connect_wdi_pipe",
                      1877,
                      (const void *)(a1 + 280));
                    v24 = ipa3_ctx;
                  }
                  v55 = *(_QWORD *)(v24 + 34160);
                  if ( v55 )
                  {
                    ipc_log_string(
                      v55,
                      "ipa %s:%d rx_comp_ring_base_pa=0x%pa\n",
                      "ipa_connect_wdi_pipe",
                      1877,
                      (const void *)(a1 + 280));
                    v24 = ipa3_ctx;
                  }
                  if ( v24 )
                  {
                    v56 = *(_QWORD *)(v24 + 34152);
                    if ( v56 )
                    {
                      ipc_log_string(
                        v56,
                        "ipa %s:%d rx_comp_ring_size=%d\n",
                        "ipa_connect_wdi_pipe",
                        1879,
                        *(_DWORD *)(a1 + 296));
                      v24 = ipa3_ctx;
                    }
                    v57 = *(_QWORD *)(v24 + 34160);
                    if ( v57 )
                    {
                      ipc_log_string(
                        v57,
                        "ipa %s:%d rx_comp_ring_size=%d\n",
                        "ipa_connect_wdi_pipe",
                        1879,
                        *(_DWORD *)(a1 + 296));
                      v24 = ipa3_ctx;
                    }
                    if ( v24 )
                    {
                      v58 = *(_QWORD *)(v24 + 34152);
                      if ( v58 )
                      {
                        ipc_log_string(
                          v58,
                          "ipa %s:%d rx_comp_ring_wp_pa=0x%pa\n",
                          "ipa_connect_wdi_pipe",
                          1881,
                          (const void *)(a1 + 288));
                        v24 = ipa3_ctx;
                      }
                      v59 = *(_QWORD *)(v24 + 34160);
                      if ( v59 )
                      {
                        ipc_log_string(
                          v59,
                          "ipa %s:%d rx_comp_ring_wp_pa=0x%pa\n",
                          "ipa_connect_wdi_pipe",
                          1881,
                          (const void *)(a1 + 288));
                        v24 = ipa3_ctx;
                      }
                    }
                  }
                }
              }
            }
          }
          v46 = v24 + 0x8000;
          *(_QWORD *)(v46 + 2024) = *(_QWORD *)(a1 + 256);
          *(_QWORD *)(v46 + 2032) = *(_QWORD *)(a1 + 272);
          *(_DWORD *)(v46 + 2040) = *(_DWORD *)(a1 + 264);
          *(_QWORD *)(v46 + 2048) = *(_QWORD *)(a1 + 280);
          *(_QWORD *)(v46 + 2056) = *(_QWORD *)(a1 + 288);
          v47 = *(_DWORD *)(a1 + 296);
        }
        *(_DWORD *)(v46 + 2064) = v47;
      }
      v60 = dma_alloc_attrs(*(_QWORD *)(ipa3_ctx + 34224), (unsigned int)v285, &v284, 3264, 0);
      v283 = v60;
      if ( !v60 )
      {
        printk(&unk_3A6C3A, "ipa_connect_wdi_pipe");
        v232 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v233 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v233 )
          {
            ipc_log_string(v233, "ipa %s:%d fail to get DMA memory.\n", "ipa_connect_wdi_pipe", 1900);
            v232 = ipa3_ctx;
          }
          v234 = *(_QWORD *)(v232 + 34160);
          if ( v234 )
            ipc_log_string(v234, "ipa %s:%d fail to get DMA memory.\n", "ipa_connect_wdi_pipe", 1900);
        }
        v213 = -12;
        goto LABEL_303;
      }
      v66 = *(unsigned __int8 *)(a1 + 344);
      v67 = ipa3_ctx;
      v68 = 272;
      v69 = *(_DWORD *)(a1 + 192);
      v71 = (_DWORD *)v60;
      if ( !*(_BYTE *)(a1 + 344) )
        v68 = 264;
      v70 = (_BYTE *)(ipa3_ctx + 32263);
      v72 = *(unsigned int *)(a1 + v68);
      if ( v69 <= 0x85 && (v69 & 1) != 0 )
      {
        if ( *v70 )
        {
          if ( ipa3_ctx )
          {
            v73 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v73 )
            {
              ipc_log_string(
                v73,
                "ipa %s:%d TX_2 ring smmu_en=%d ring_size=%d %d\n",
                "ipa_connect_wdi_pipe",
                1914,
                v66,
                *(_DWORD *)(a1 + 272),
                *(_DWORD *)(a1 + 264));
              v67 = ipa3_ctx;
              v66 = *(unsigned __int8 *)(a1 + 344);
            }
            v74 = *(_QWORD *)(v67 + 34160);
            if ( v74 )
            {
              ipc_log_string(
                v74,
                "ipa %s:%d TX_2 ring smmu_en=%d ring_size=%d %d\n",
                "ipa_connect_wdi_pipe",
                1914,
                v66,
                *(_DWORD *)(a1 + 272),
                *(_DWORD *)(a1 + 264));
              LOBYTE(v66) = *(_BYTE *)(a1 + 344);
            }
          }
          if ( (unsigned int)ipa_create_uc_smmu_mapping(
                               8u,
                               v66 & 1,
                               *(_QWORD *)(a1 + 256),
                               a1 + 256,
                               v72,
                               v61,
                               v62,
                               v63,
                               v64,
                               v65,
                               0,
                               &v281) )
          {
            printk(&unk_3DEE05, "ipa_connect_wdi_pipe");
            v247 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_427;
            v248 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v248 )
            {
              ipc_log_string(v248, "ipa %s:%d fail to create uc mapping TX ring.\n", "ipa_connect_wdi_pipe", 1922);
              v247 = ipa3_ctx;
            }
            v249 = *(_QWORD *)(v247 + 34160);
            if ( !v249 )
              goto LABEL_427;
            ipc_log_string(v249, "ipa %s:%d fail to create uc mapping TX ring.\n", "ipa_connect_wdi_pipe", 1922);
          }
          else
          {
            v80 = v281;
            *((_WORD *)v71 + 4) = v72;
            *(_QWORD *)v71 = v80;
            v81 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v82 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v82 )
              {
                ipc_log_string(
                  v82,
                  "ipa %s:%d TX_2 comp_ring_base_pa_hi=0x%08x :0x%08x\n",
                  "ipa_connect_wdi_pipe",
                  1932,
                  HIDWORD(v80),
                  v80);
                v81 = ipa3_ctx;
              }
              v83 = *(_QWORD *)(v81 + 34160);
              if ( v83 )
              {
                ipc_log_string(
                  v83,
                  "ipa %s:%d TX_2 comp_ring_base_pa_hi=0x%08x :0x%08x\n",
                  "ipa_connect_wdi_pipe",
                  1932,
                  v71[1],
                  *v71);
                v81 = ipa3_ctx;
              }
              v84 = *(unsigned __int8 *)(a1 + 344);
              v85 = 288;
              if ( *(_BYTE *)(a1 + 344) )
                v85 = 304;
              v86 = *(_DWORD *)(a1 + v85);
              if ( v81 )
              {
                v87 = *(_QWORD *)(v81 + 34152);
                if ( v87 )
                {
                  ipc_log_string(
                    v87,
                    "ipa %s:%d TX_2 CE ring smmu_en=%d ring_size=%d %d\n",
                    "ipa_connect_wdi_pipe",
                    1939,
                    v84,
                    *(_DWORD *)(a1 + 304),
                    *(_DWORD *)(a1 + 288));
                  v81 = ipa3_ctx;
                  v84 = *(unsigned __int8 *)(a1 + 344);
                }
                v88 = *(_QWORD *)(v81 + 34160);
                if ( v88 )
                {
                  ipc_log_string(
                    v88,
                    "ipa %s:%d TX_2 CE ring smmu_en=%d ring_size=%d %d\n",
                    "ipa_connect_wdi_pipe",
                    1939,
                    v84,
                    *(_DWORD *)(a1 + 304),
                    *(_DWORD *)(a1 + 288));
                  LOBYTE(v84) = *(_BYTE *)(a1 + 344);
                }
              }
            }
            else
            {
              LOBYTE(v84) = *(_BYTE *)(a1 + 344);
              v174 = 288;
              if ( (_BYTE)v84 )
                v174 = 304;
              v86 = *(_DWORD *)(a1 + v174);
            }
            if ( !(unsigned int)ipa_create_uc_smmu_mapping(
                                  9u,
                                  v84 & 1,
                                  *(_QWORD *)(a1 + 272),
                                  a1 + 280,
                                  v86,
                                  v75,
                                  v76,
                                  v77,
                                  v78,
                                  v79,
                                  0,
                                  &v281) )
            {
              v181 = v281;
              v180 = HIDWORD(v281);
              v182 = ipa3_ctx;
              *((_WORD *)v71 + 10) = v86;
              v71[3] = v181;
              v71[4] = v180;
              if ( v182 )
              {
                v183 = *(_QWORD *)(v182 + 34152);
                if ( v183 )
                {
                  ipc_log_string(
                    v183,
                    "ipa %s:%d TX_2 ce_ring_base_pa_hi=0x%08x :0x%08x\n",
                    "ipa_connect_wdi_pipe",
                    1958,
                    v180,
                    v181);
                  v182 = ipa3_ctx;
                }
                v184 = *(_QWORD *)(v182 + 34160);
                if ( v184 )
                  ipc_log_string(
                    v184,
                    "ipa %s:%d TX_2 ce_ring_base_pa_hi=0x%08x :0x%08x\n",
                    "ipa_connect_wdi_pipe",
                    1958,
                    v71[4],
                    v71[3]);
              }
              v185 = *(_BYTE *)(a1 + 344);
              v186 = 280;
              if ( v185 )
                v186 = 296;
              v280 = *(_QWORD *)(a1 + v186);
              v137 = ipa_create_uc_smmu_mapping(0xAu, v185, v280, 0, 4, v175, v176, v177, v178, v179, 0, &v281);
              if ( !(_DWORD)v137 )
              {
                v187 = v281;
                v163 = ipa3_ctx;
                *((_QWORD *)v71 + 3) = v281;
                if ( v163 )
                {
                  v188 = *(_QWORD *)(v163 + 34152);
                  if ( v188 )
                  {
                    ipc_log_string(
                      v188,
                      "ipa %s:%d TX_2 ce_ring_doorbell_pa_hi=0x%08x :0x%08x\n",
                      "ipa_connect_wdi_pipe",
                      1978,
                      HIDWORD(v187),
                      v187);
                    v163 = ipa3_ctx;
                  }
                  v137 = *(_QWORD *)(v163 + 34160);
                  if ( v137 )
                  {
                    v137 = ipc_log_string(
                             v137,
                             "ipa %s:%d TX_2 ce_ring_doorbell_pa_hi=0x%08x :0x%08x\n",
                             "ipa_connect_wdi_pipe",
                             1978,
                             v71[7],
                             v71[6]);
                    v163 = ipa3_ctx;
                  }
                }
                v170 = 34;
                v169 = 8;
LABEL_270:
                if ( *(_BYTE *)(a1 + 344) )
                  v189 = 308;
                else
                  v189 = 292;
                LOWORD(v71[v169]) = *(_DWORD *)(a1 + v189);
                *((_BYTE *)v71 + v170) = v13;
                v190 = 18;
                goto LABEL_293;
              }
              printk(&unk_3DBF9E, "ipa_connect_wdi_pipe");
              v271 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v272 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v272 )
                {
                  ipc_log_string(v272, "ipa %s:%d fail to create uc mapping CE DB.\n", "ipa_connect_wdi_pipe", 1969);
                  v271 = ipa3_ctx;
                }
                v273 = *(_QWORD *)(v271 + 34160);
                if ( v273 )
                {
                  ipc_log_string(v273, "ipa %s:%d fail to create uc mapping CE DB.\n", "ipa_connect_wdi_pipe", 1969);
                  goto LABEL_426;
                }
              }
LABEL_427:
              v213 = -12;
              goto LABEL_302;
            }
            printk(&unk_3E445C, "ipa_connect_wdi_pipe");
            v262 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_427;
            v263 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v263 )
            {
              ipc_log_string(v263, "ipa %s:%d fail to create uc mapping CE ring.\n", "ipa_connect_wdi_pipe", 1948);
              v262 = ipa3_ctx;
            }
            v264 = *(_QWORD *)(v262 + 34160);
            if ( !v264 )
              goto LABEL_427;
            ipc_log_string(v264, "ipa %s:%d fail to create uc mapping CE ring.\n", "ipa_connect_wdi_pipe", 1948);
          }
        }
        else
        {
          if ( ipa3_ctx )
          {
            v141 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v141 )
            {
              ipc_log_string(
                v141,
                "ipa %s:%d TX ring smmu_en=%d ring_size=%d %d\n",
                "ipa_connect_wdi_pipe",
                1992,
                v66,
                *(_DWORD *)(a1 + 272),
                *(_DWORD *)(a1 + 264));
              v67 = ipa3_ctx;
              v66 = *(unsigned __int8 *)(a1 + 344);
            }
            v142 = *(_QWORD *)(v67 + 34160);
            if ( v142 )
            {
              ipc_log_string(
                v142,
                "ipa %s:%d TX ring smmu_en=%d ring_size=%d %d\n",
                "ipa_connect_wdi_pipe",
                1992,
                v66,
                *(_DWORD *)(a1 + 272),
                *(_DWORD *)(a1 + 264));
              LOBYTE(v66) = *(_BYTE *)(a1 + 344);
            }
          }
          if ( (unsigned int)ipa_create_uc_smmu_mapping(
                               8u,
                               v66 & 1,
                               *(_QWORD *)(a1 + 256),
                               a1 + 256,
                               v72,
                               v61,
                               v62,
                               v63,
                               v64,
                               v65,
                               0,
                               &v281) )
          {
            printk(&unk_3DEE05, "ipa_connect_wdi_pipe");
            v250 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_427;
            v251 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v251 )
            {
              ipc_log_string(v251, "ipa %s:%d fail to create uc mapping TX ring.\n", "ipa_connect_wdi_pipe", 2000);
              v250 = ipa3_ctx;
            }
            v252 = *(_QWORD *)(v250 + 34160);
            if ( !v252 )
              goto LABEL_427;
            ipc_log_string(v252, "ipa %s:%d fail to create uc mapping TX ring.\n", "ipa_connect_wdi_pipe", 2000);
          }
          else
          {
            v148 = v281;
            *((_WORD *)v71 + 2) = v72;
            v149 = 304;
            *v71 = v148;
            v150 = *(unsigned __int8 *)(a1 + 344);
            if ( !*(_BYTE *)(a1 + 344) )
              v149 = 288;
            v151 = ipa3_ctx;
            v152 = *(unsigned int *)(a1 + v149);
            if ( ipa3_ctx )
            {
              v153 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v153 )
              {
                ipc_log_string(
                  v153,
                  "ipa %s:%d TX CE ring smmu_en=%d ring_size=%d %d 0x%lx\n",
                  "ipa_connect_wdi_pipe",
                  2012,
                  v150,
                  *(_DWORD *)(a1 + 304),
                  *(_DWORD *)(a1 + 288),
                  v148);
                v151 = ipa3_ctx;
                v150 = *(unsigned __int8 *)(a1 + 344);
              }
              v154 = *(_QWORD *)(v151 + 34160);
              if ( v154 )
              {
                ipc_log_string(
                  v154,
                  "ipa %s:%d TX CE ring smmu_en=%d ring_size=%d %d 0x%lx\n",
                  "ipa_connect_wdi_pipe",
                  2012,
                  v150,
                  *(_DWORD *)(a1 + 304),
                  *(_DWORD *)(a1 + 288),
                  v148);
                LOBYTE(v150) = *(_BYTE *)(a1 + 344);
              }
            }
            if ( (unsigned int)ipa_create_uc_smmu_mapping(
                                 9u,
                                 v150 & 1,
                                 *(_QWORD *)(a1 + 272),
                                 a1 + 280,
                                 v152,
                                 v143,
                                 v144,
                                 v145,
                                 v146,
                                 v147,
                                 0,
                                 &v281) )
            {
              printk(&unk_3E445C, "ipa_connect_wdi_pipe");
              v259 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_427;
              v260 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v260 )
              {
                ipc_log_string(v260, "ipa %s:%d fail to create uc mapping CE ring.\n", "ipa_connect_wdi_pipe", 2020);
                v259 = ipa3_ctx;
              }
              v261 = *(_QWORD *)(v259 + 34160);
              if ( !v261 )
                goto LABEL_427;
              ipc_log_string(v261, "ipa %s:%d fail to create uc mapping CE ring.\n", "ipa_connect_wdi_pipe", 2020);
            }
            else
            {
              v160 = v281;
              *((_WORD *)v71 + 6) = v152;
              v71[2] = v160;
              v161 = 280;
              v162 = *(_BYTE *)(a1 + 344);
              if ( v162 )
                v161 = 296;
              v280 = *(_QWORD *)(a1 + v161);
              v137 = ipa_create_uc_smmu_mapping(0xAu, v162, v280, 0, 4, v155, v156, v157, v158, v159, 0, &v281);
              if ( !(_DWORD)v137 )
              {
                v163 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v164 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v164 )
                  {
                    ipc_log_string(
                      v164,
                      "ipa %s:%d CE doorbell pa: 0x%pa va:0x%lx\n",
                      "ipa_connect_wdi_pipe",
                      2040,
                      &v280,
                      v281);
                    v163 = ipa3_ctx;
                  }
                  v137 = *(_QWORD *)(v163 + 34160);
                  if ( v137 )
                  {
                    v137 = ipc_log_string(
                             v137,
                             "ipa %s:%d CE doorbell pa: 0x%pa va:0x%lx\n",
                             "ipa_connect_wdi_pipe",
                             2040,
                             &v280,
                             v281);
                    v163 = ipa3_ctx;
                  }
                  if ( v163 )
                  {
                    v165 = *(_QWORD *)(v163 + 34152);
                    if ( v165 )
                    {
                      if ( *(_BYTE *)(v163 + 44853) )
                        v166 = "Yes";
                      else
                        v166 = "No";
                      ipc_log_string(v165, "ipa %s:%d Is wdi_over_pcie ? (%s)\n", "ipa_connect_wdi_pipe", 2042, v166);
                      v163 = ipa3_ctx;
                    }
                    v137 = *(_QWORD *)(v163 + 34160);
                    if ( v137 )
                    {
                      if ( *(_BYTE *)(v163 + 44853) )
                        v167 = "Yes";
                      else
                        v167 = "No";
                      v137 = ipc_log_string(
                               v137,
                               "ipa %s:%d Is wdi_over_pcie ? (%s)\n",
                               "ipa_connect_wdi_pipe",
                               2042,
                               v167);
                      v163 = ipa3_ctx;
                    }
                  }
                }
                v168 = &v281;
                if ( *(_BYTE *)(v163 + 44853) )
                  v168 = &v280;
                v169 = 5;
                v71[4] = *v168;
                v170 = 22;
                goto LABEL_270;
              }
              printk(&unk_3DBF9E, "ipa_connect_wdi_pipe");
              v268 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_427;
              v269 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v269 )
              {
                ipc_log_string(v269, "ipa %s:%d fail to create uc mapping CE DB.\n", "ipa_connect_wdi_pipe", 2035);
                v268 = ipa3_ctx;
              }
              v270 = *(_QWORD *)(v268 + 34160);
              if ( !v270 )
                goto LABEL_427;
              ipc_log_string(v270, "ipa %s:%d fail to create uc mapping CE DB.\n", "ipa_connect_wdi_pipe", 2035);
            }
          }
        }
LABEL_426:
        v213 = -12;
        goto LABEL_302;
      }
      if ( *v70 )
      {
        if ( ipa3_ctx )
        {
          v89 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v89 )
          {
            ipc_log_string(
              v89,
              "ipa %s:%d RX_2 ring smmu_en=%d ring_size=%d %d\n",
              "ipa_connect_wdi_pipe",
              2068,
              v66,
              *(_DWORD *)(a1 + 272),
              *(_DWORD *)(a1 + 264));
            v67 = ipa3_ctx;
            v66 = *(unsigned __int8 *)(a1 + 344);
          }
          v90 = *(_QWORD *)(v67 + 34160);
          if ( v90 )
          {
            ipc_log_string(
              v90,
              "ipa %s:%d RX_2 ring smmu_en=%d ring_size=%d %d\n",
              "ipa_connect_wdi_pipe",
              2068,
              v66,
              *(_DWORD *)(a1 + 272),
              *(_DWORD *)(a1 + 264));
            LOBYTE(v66) = *(_BYTE *)(a1 + 344);
          }
        }
        if ( (unsigned int)ipa_create_uc_smmu_mapping(
                             0,
                             v66 & 1,
                             *(_QWORD *)(a1 + 256),
                             a1 + 256,
                             v72,
                             v61,
                             v62,
                             v63,
                             v64,
                             v65,
                             0,
                             &v281) )
        {
          printk(&unk_3BE881, "ipa_connect_wdi_pipe");
          v241 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_427;
          v242 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v242 )
          {
            ipc_log_string(v242, "ipa %s:%d fail to create uc RX_2 ring.\n", "ipa_connect_wdi_pipe", 2076);
            v241 = ipa3_ctx;
          }
          v243 = *(_QWORD *)(v241 + 34160);
          if ( !v243 )
            goto LABEL_427;
          ipc_log_string(v243, "ipa %s:%d fail to create uc RX_2 ring.\n", "ipa_connect_wdi_pipe", 2076);
          goto LABEL_426;
        }
        v96 = v281;
        v71[2] = v72;
        *(_QWORD *)v71 = v96;
        v97 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v98 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v98 )
          {
            ipc_log_string(
              v98,
              "ipa %s:%d RX_2 rx_ring_base_pa_hi=0x%08x:0x%08x\n",
              "ipa_connect_wdi_pipe",
              2086,
              HIDWORD(v96),
              v96);
            v97 = ipa3_ctx;
          }
          v99 = *(_QWORD *)(v97 + 34160);
          if ( v99 )
            ipc_log_string(
              v99,
              "ipa %s:%d RX_2 rx_ring_base_pa_hi=0x%08x:0x%08x\n",
              "ipa_connect_wdi_pipe",
              2086,
              v71[1],
              *v71);
        }
        v100 = *(_BYTE *)(a1 + 344);
        v101 = 272;
        if ( v100 )
          v101 = 280;
        v280 = *(_QWORD *)(a1 + v101);
        if ( (unsigned int)ipa_create_uc_smmu_mapping(1u, v100, v280, 0, 4, v91, v92, v93, v94, v95, 0, &v281) )
        {
          printk(&unk_3A777C, "ipa_connect_wdi_pipe");
          v253 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_427;
          v254 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v254 )
          {
            ipc_log_string(v254, "ipa %s:%d fail to create uc RX_2 rng RP\n", "ipa_connect_wdi_pipe", 2097);
            v253 = ipa3_ctx;
          }
          v255 = *(_QWORD *)(v253 + 34160);
          if ( !v255 )
            goto LABEL_427;
          ipc_log_string(v255, "ipa %s:%d fail to create uc RX_2 rng RP\n", "ipa_connect_wdi_pipe", 2097);
          goto LABEL_426;
        }
        v107 = v281;
        v108 = ipa3_ctx;
        *(_QWORD *)(v71 + 3) = v281;
        if ( v108 )
        {
          v109 = *(_QWORD *)(v108 + 34152);
          if ( v109 )
          {
            ipc_log_string(
              v109,
              "ipa %s:%d RX_2 rx_ring_rp_pa_hi=0x%08x :0x%08x\n",
              "ipa_connect_wdi_pipe",
              2106,
              HIDWORD(v107),
              v107);
            v108 = ipa3_ctx;
          }
          v110 = *(_QWORD *)(v108 + 34160);
          if ( v110 )
          {
            ipc_log_string(
              v110,
              "ipa %s:%d RX_2 rx_ring_rp_pa_hi=0x%08x :0x%08x\n",
              "ipa_connect_wdi_pipe",
              2106,
              v71[4],
              v71[3]);
            v108 = ipa3_ctx;
          }
          v111 = *(unsigned __int8 *)(a1 + 344);
          v112 = 296;
          if ( *(_BYTE *)(a1 + 344) )
            v112 = 312;
          v113 = *(_DWORD *)(a1 + v112);
          if ( v108 )
          {
            v114 = *(_QWORD *)(v108 + 34152);
            if ( v114 )
            {
              ipc_log_string(
                v114,
                "ipa %s:%d RX_2 ring smmu_en=%d comp_ring_size=%d %d\n",
                "ipa_connect_wdi_pipe",
                2113,
                v111,
                *(_DWORD *)(a1 + 312),
                *(_DWORD *)(a1 + 296));
              v108 = ipa3_ctx;
              v111 = *(unsigned __int8 *)(a1 + 344);
            }
            v115 = *(_QWORD *)(v108 + 34160);
            if ( v115 )
            {
              ipc_log_string(
                v115,
                "ipa %s:%d RX_2 ring smmu_en=%d comp_ring_size=%d %d\n",
                "ipa_connect_wdi_pipe",
                2113,
                v111,
                *(_DWORD *)(a1 + 312),
                *(_DWORD *)(a1 + 296));
              LOBYTE(v111) = *(_BYTE *)(a1 + 344);
            }
          }
        }
        else
        {
          LOBYTE(v111) = *(_BYTE *)(a1 + 344);
          v191 = 296;
          if ( (_BYTE)v111 )
            v191 = 312;
          v113 = *(_DWORD *)(a1 + v191);
        }
        if ( (unsigned int)ipa_create_uc_smmu_mapping(
                             2u,
                             v111 & 1,
                             *(_QWORD *)(a1 + 280),
                             a1 + 288,
                             v113,
                             v102,
                             v103,
                             v104,
                             v105,
                             v106,
                             0,
                             &v281) )
        {
          printk(&unk_3D062A, "ipa_connect_wdi_pipe");
          v265 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_427;
          v266 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v266 )
          {
            ipc_log_string(v266, "ipa %s:%d fail to create uc RX_2 comp_ring.\n", "ipa_connect_wdi_pipe", 2121);
            v265 = ipa3_ctx;
          }
          v267 = *(_QWORD *)(v265 + 34160);
          if ( !v267 )
            goto LABEL_427;
          ipc_log_string(v267, "ipa %s:%d fail to create uc RX_2 comp_ring.\n", "ipa_connect_wdi_pipe", 2121);
          goto LABEL_426;
        }
        v198 = v281;
        v197 = HIDWORD(v281);
        v199 = ipa3_ctx;
        v71[7] = v113;
        v71[5] = v198;
        v71[6] = v197;
        if ( v199 )
        {
          v200 = *(_QWORD *)(v199 + 34152);
          if ( v200 )
          {
            ipc_log_string(
              v200,
              "ipa %s:%d RX_2 rx_comp_ring_base_pa_hi=0x%08x:0x%08x\n",
              "ipa_connect_wdi_pipe",
              2131,
              v197,
              v198);
            v199 = ipa3_ctx;
          }
          v201 = *(_QWORD *)(v199 + 34160);
          if ( v201 )
            ipc_log_string(
              v201,
              "ipa %s:%d RX_2 rx_comp_ring_base_pa_hi=0x%08x:0x%08x\n",
              "ipa_connect_wdi_pipe",
              2131,
              v71[6],
              v71[5]);
        }
        v202 = *(_BYTE *)(a1 + 344);
        v203 = 288;
        if ( v202 )
          v203 = 304;
        v280 = *(_QWORD *)(a1 + v203);
        v137 = ipa_create_uc_smmu_mapping(3u, v202, v280, 0, 4, v192, v193, v194, v195, v196, 0, &v281);
        if ( (_DWORD)v137 )
        {
          printk(&unk_3BBBF0, "ipa_connect_wdi_pipe");
          v274 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v275 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v275 )
            {
              ipc_log_string(v275, "ipa %s:%d fail to create uc RX_2 comp_rng WP\n", "ipa_connect_wdi_pipe", 2144);
              v274 = ipa3_ctx;
            }
            v276 = *(_QWORD *)(v274 + 34160);
            if ( v276 )
            {
              ipc_log_string(v276, "ipa %s:%d fail to create uc RX_2 comp_rng WP\n", "ipa_connect_wdi_pipe", 2144);
              goto LABEL_426;
            }
          }
          goto LABEL_427;
        }
        v204 = v281;
        v205 = ipa3_ctx;
        *((_QWORD *)v71 + 4) = v281;
        if ( v205 )
        {
          v206 = *(_QWORD *)(v205 + 34152);
          if ( v206 )
          {
            ipc_log_string(
              v206,
              "ipa %s:%d RX_2 rx_comp_ring_wp_pa_hi=0x%08x:0x%08x\n",
              "ipa_connect_wdi_pipe",
              2153,
              HIDWORD(v204),
              v204);
            v205 = ipa3_ctx;
          }
          v137 = *(_QWORD *)(v205 + 34160);
          if ( v137 )
            v137 = ipc_log_string(
                     v137,
                     "ipa %s:%d RX_2 rx_comp_ring_wp_pa_hi=0x%08x:0x%08x\n",
                     "ipa_connect_wdi_pipe",
                     2153,
                     v71[9],
                     v71[8]);
        }
        v140 = 10;
      }
      else
      {
        if ( ipa3_ctx )
        {
          v128 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v128 )
          {
            ipc_log_string(
              v128,
              "ipa %s:%d RX ring smmu_en=%d ring_size=%d %d\n",
              "ipa_connect_wdi_pipe",
              2163,
              v66,
              *(_DWORD *)(a1 + 272),
              *(_DWORD *)(a1 + 264));
            v67 = ipa3_ctx;
            v66 = *(unsigned __int8 *)(a1 + 344);
          }
          v129 = *(_QWORD *)(v67 + 34160);
          if ( v129 )
          {
            ipc_log_string(
              v129,
              "ipa %s:%d RX ring smmu_en=%d ring_size=%d %d\n",
              "ipa_connect_wdi_pipe",
              2163,
              v66,
              *(_DWORD *)(a1 + 272),
              *(_DWORD *)(a1 + 264));
            LOBYTE(v66) = *(_BYTE *)(a1 + 344);
          }
        }
        if ( (unsigned int)ipa_create_uc_smmu_mapping(
                             0,
                             v66 & 1,
                             *(_QWORD *)(a1 + 256),
                             a1 + 256,
                             v72,
                             v61,
                             v62,
                             v63,
                             v64,
                             v65,
                             0,
                             &v281) )
        {
          printk(&unk_3AA6DD, "ipa_connect_wdi_pipe");
          v244 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_427;
          v245 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v245 )
          {
            ipc_log_string(v245, "ipa %s:%d fail to create uc mapping RX ring.\n", "ipa_connect_wdi_pipe", 2171);
            v244 = ipa3_ctx;
          }
          v246 = *(_QWORD *)(v244 + 34160);
          if ( !v246 )
            goto LABEL_427;
          ipc_log_string(v246, "ipa %s:%d fail to create uc mapping RX ring.\n", "ipa_connect_wdi_pipe", 2171);
          goto LABEL_426;
        }
        *v71 = v281;
        v71[1] = v72;
        v135 = 272;
        v136 = *(_BYTE *)(a1 + 344);
        if ( v136 )
          v135 = 280;
        v280 = *(_QWORD *)(a1 + v135);
        v137 = ipa_create_uc_smmu_mapping(1u, v136, v280, 0, 4, v130, v131, v132, v133, v134, 0, &v281);
        if ( (_DWORD)v137 )
        {
          printk(&unk_3E6FE5, "ipa_connect_wdi_pipe");
          v256 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_427;
          v257 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v257 )
          {
            ipc_log_string(v257, "ipa %s:%d fail to create uc mapping RX rng RP\n", "ipa_connect_wdi_pipe", 2187);
            v256 = ipa3_ctx;
          }
          v258 = *(_QWORD *)(v256 + 34160);
          if ( !v258 )
            goto LABEL_427;
          ipc_log_string(v258, "ipa %s:%d fail to create uc mapping RX rng RP\n", "ipa_connect_wdi_pipe", 2187);
          goto LABEL_426;
        }
        v71[2] = v281;
        v140 = 3;
      }
      LOBYTE(v71[v140]) = v13;
      v190 = 16;
      v163 = ipa3_ctx;
LABEL_293:
      v207 = *(_DWORD *)(v163 + 28640);
      reg_base = ipahal_get_reg_base(v137, v138, v139);
      *(_QWORD *)a2 = reg_base
                    + (unsigned int)((__int64 (__fastcall *)(__int64, __int64, _QWORD))ipahal_get_reg_mn_ofst)(
                                      66,
                                      1,
                                      v190)
                    + v207;
      *v15 = 1;
      v15[1] = *(_DWORD *)(a1 + 192);
      *((_BYTE *)v15 + 405) = *(_BYTE *)(a1 + 217);
      v209 = ipa3_disable_data_path(v13);
      if ( v209 )
      {
        v213 = v209;
        printk(&unk_3EF093, "ipa_connect_wdi_pipe");
        v235 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v236 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v236 )
          {
            ipc_log_string(
              v236,
              "ipa %s:%d disable data path failed res=%d clnt=%d.\n",
              "ipa_connect_wdi_pipe",
              2207,
              v213,
              v13);
            v235 = ipa3_ctx;
          }
          v237 = *(_QWORD *)(v235 + 34160);
          if ( v237 )
            ipc_log_string(
              v237,
              "ipa %s:%d disable data path failed res=%d clnt=%d.\n",
              "ipa_connect_wdi_pipe",
              2207,
              v213,
              v13);
        }
        goto LABEL_302;
      }
      v210 = *(_DWORD *)(a1 + 192);
      v211 = v210 & 1;
      if ( v210 <= 0x85 && (v210 & 1) == 0 )
      {
        v282 = 256;
        ipa_cfg_ep_ctrl(v13, &v282);
        v210 = *(_DWORD *)(a1 + 192);
        v211 = v210 & 1;
      }
      if ( ((v210 < 0x86) & v211) != 0 )
        v212 = 96;
      else
        v212 = 97;
      if ( (unsigned int)ipa3_uc_send_cmd((unsigned int)v284, v212, 0x60u, 0, 2500) )
      {
        v213 = -14;
LABEL_302:
        ipa_release_uc_smmu_mappings(*(unsigned int *)(a1 + 192));
        dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34224), (unsigned int)v285, v283, v284, 0);
LABEL_303:
        ipa3_dec_client_disable_clks();
        result = v213;
        goto LABEL_338;
      }
      *((_BYTE *)v15 + 404) = *(_BYTE *)(a1 + 216);
      *((_QWORD *)v15 + 47) = *(_QWORD *)(a1 + 208);
      *((_QWORD *)v15 + 46) = *(_QWORD *)(a1 + 200);
      v214 = *(_QWORD *)(a1 + 352);
      v215 = ipa3_ctx;
      if ( v214 )
      {
        *(_QWORD *)(ipa3_ctx + 43176) = v214;
      }
      else if ( ipa3_ctx )
      {
        v224 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v224 )
        {
          ipc_log_string(v224, "ipa %s:%d in->wdi_notify is null\n", "ipa_connect_wdi_pipe", 2236);
          v215 = ipa3_ctx;
        }
        v225 = *(_QWORD *)(v215 + 34160);
        if ( v225 )
          ipc_log_string(v225, "ipa %s:%d in->wdi_notify is null\n", "ipa_connect_wdi_pipe", 2236);
      }
      v216 = *(_DWORD *)(a1 + 192);
      if ( v216 <= 0x85 && (v216 & 1) != 0 )
      {
        *(_QWORD *)(a1 + 112) = 0x100000001LL;
        *(_QWORD *)(a1 + 96) = 0x400000001LL;
        *(_DWORD *)(a1 + 104) = 2;
      }
      if ( (v15[101] & 1) != 0 )
      {
        v217 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v218 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v218 )
          {
            ipc_log_string(v218, "ipa %s:%d Skipping endpoint configuration.\n", "ipa_connect_wdi_pipe", 2254);
            v217 = ipa3_ctx;
          }
          v219 = *(_QWORD *)(v217 + 34160);
          if ( v219 )
            ipc_log_string(v219, "ipa %s:%d Skipping endpoint configuration.\n", "ipa_connect_wdi_pipe", 2254);
        }
      }
      else
      {
        if ( (unsigned int)ipa3_cfg_ep(v13, a1) )
        {
          printk(&unk_3D5322, "ipa_connect_wdi_pipe");
          v277 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v278 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v278 )
            {
              ipc_log_string(v278, "ipa %s:%d fail to configure EP.\n", "ipa_connect_wdi_pipe", 2249);
              v277 = ipa3_ctx;
            }
            v279 = *(_QWORD *)(v277 + 34160);
            if ( v279 )
            {
              ipc_log_string(v279, "ipa %s:%d fail to configure EP.\n", "ipa_connect_wdi_pipe", 2249);
              v277 = ipa3_ctx;
            }
          }
          memset((void *)(v277 + 480LL * (int)v13 + 168), 0, 0x1E0u);
          v213 = 0;
          goto LABEL_302;
        }
        v220 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v221 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v221 )
          {
            ipc_log_string(v221, "ipa %s:%d ep configuration successful\n", "ipa_connect_wdi_pipe", 2252);
            v220 = ipa3_ctx;
          }
          v222 = *(_QWORD *)(v220 + 34160);
          if ( v222 )
            ipc_log_string(v222, "ipa %s:%d ep configuration successful\n", "ipa_connect_wdi_pipe", 2252);
        }
      }
      ipa3_enable_data_path(v13);
      a2[2] = v13;
      if ( (v15[101] & 1) == 0 )
      {
        v223 = *(_DWORD *)(a1 + 192);
        if ( v223 <= 0x85 && (v223 & 1) == 0 )
          ipa3_install_dflt_flt_rules(v13);
      }
      if ( (*((_BYTE *)v15 + 405) & 1) == 0 )
        ipa3_dec_client_disable_clks();
      dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34224), (unsigned int)v285, v283, v284, 0);
      v15[112] |= 1u;
      v226 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v227 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v227 )
        {
          ipc_log_string(
            v227,
            "ipa %s:%d client %d (ep: %d) connected\n",
            "ipa_connect_wdi_pipe",
            2269,
            *(_DWORD *)(a1 + 192),
            v13);
          v226 = ipa3_ctx;
        }
        result = *(_QWORD *)(v226 + 34160);
        if ( !result )
          goto LABEL_338;
        ipc_log_string(
          result,
          "ipa %s:%d client %d (ep: %d) connected\n",
          "ipa_connect_wdi_pipe",
          2269,
          *(_DWORD *)(a1 + 192),
          v13);
      }
LABEL_337:
      result = 0;
      goto LABEL_338;
    }
    printk(&unk_3F4B6B, "ipa_connect_wdi_pipe");
    v230 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_337;
    v231 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v231 )
    {
      ipc_log_string(v231, "ipa %s:%d EP already allocated.\n", "ipa_connect_wdi_pipe", 1815);
      v230 = ipa3_ctx;
    }
    result = *(_QWORD *)(v230 + 34160);
    if ( !result )
      goto LABEL_338;
    ipc_log_string(result, "ipa %s:%d EP already allocated.\n", "ipa_connect_wdi_pipe", 1815);
LABEL_349:
    result = 0;
    goto LABEL_338;
  }
  __break(0x5512u);
  *(_BYTE *)(v11 + 3022) = v12;
  return ((__int64 (*)(void))ipa_pm_wrapper_connect_wdi_pipe)();
}
