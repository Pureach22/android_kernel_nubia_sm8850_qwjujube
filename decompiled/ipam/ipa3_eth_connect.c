__int64 __fastcall ipa3_eth_connect(__int64 a1, unsigned int a2)
{
  int ep_mapping; // w0
  unsigned int v5; // w21
  unsigned int is_vlan_mode; // w0
  unsigned int prot; // w0
  unsigned int v8; // w0
  __int64 v9; // x23
  unsigned int v10; // w0
  _BOOL4 v11; // w26
  int v12; // w8
  int v13; // w10
  bool v14; // w24
  int v15; // w8
  __int64 v16; // x9
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x25
  __int64 v21; // x27
  int v22; // w9
  __int64 v23; // x9
  int v24; // w24
  __int64 v25; // x10
  __int64 v26; // x1
  int v27; // w8
  __int64 v28; // x0
  __int64 v29; // x8
  char v30; // w10
  __int64 v31; // x8
  __int64 v32; // x1
  int v33; // w24
  int v34; // w24
  __int64 v35; // x9
  __int64 v36; // x27
  __int64 v37; // x10
  __int64 v38; // x9
  int v39; // w8
  __int64 v40; // x0
  __int64 v41; // x8
  char v42; // w10
  __int64 v43; // x8
  __int64 v44; // x1
  unsigned int v45; // w8
  int *v46; // x10
  int v47; // w12
  unsigned __int64 v48; // x9
  int v49; // w10
  __int64 v50; // x11
  char v51; // w8
  int v52; // w27
  int v53; // w8
  __int64 v54; // x9
  __int64 v55; // x10
  __int64 v56; // x1
  int v57; // w8
  __int64 v58; // x0
  __int64 v59; // x10
  char v60; // w9
  __int64 v61; // x10
  __int64 v62; // x1
  int *v63; // x8
  unsigned int v64; // w24
  int v65; // w26
  int v66; // w25
  int v67; // w24
  int v68; // w0
  int v69; // w8
  unsigned int v70; // w9
  __int64 v71; // x2
  __int64 v72; // x0
  __int64 v73; // x24
  __int64 v74; // x0
  __int64 v75; // x2
  __int64 v76; // x0
  unsigned __int64 v77; // x9
  __int64 *v78; // x8
  __int64 v79; // x0
  char v80; // w8
  unsigned int v81; // w12
  char v82; // w9
  unsigned __int64 v83; // x13
  int v84; // w0
  __int64 v85; // x8
  __int64 v86; // x0
  __int64 v87; // x0
  __int64 v88; // x8
  __int64 v89; // x0
  __int64 v90; // x0
  __int64 result; // x0
  __int64 v92; // x8
  __int64 v93; // x0
  __int64 v94; // x0
  unsigned int v95; // w19
  __int64 v96; // x8
  __int64 v97; // x0
  __int64 v98; // x0
  __int64 v99; // x8
  __int64 v100; // x0
  __int64 v101; // x0
  int v102; // w28
  int reg_base; // w25
  int v104; // w8
  __int64 v105; // x2
  __int64 v106; // x0
  __int64 v107; // x2
  __int64 v108; // x0
  __int64 v109; // x0
  int v110; // w8
  __int64 v111; // x2
  __int64 v112; // x0
  __int64 v113; // x8
  __int64 v114; // x0
  __int64 v115; // x0
  __int64 v116; // x2
  __int64 v117; // x0
  __int64 v118; // x24
  int v120; // w8
  unsigned int v121; // w0
  unsigned int started; // w0
  __int64 v123; // x9
  int v124; // w24
  unsigned int v125; // w10
  __int64 v126; // x8
  __int64 v127; // x10
  unsigned int *v128; // x8
  __int64 v129; // x4
  unsigned int inited; // w0
  unsigned int v131; // w9
  unsigned __int64 v132; // x10
  __int64 v133; // x8
  _BOOL8 v134; // x25
  char *v135; // x10
  char *v136; // x9
  char v137; // w12
  int v138; // w8
  int v139; // w11
  unsigned int v140; // w0
  __int64 v141; // x8
  __int64 v142; // x0
  __int64 v143; // x0
  unsigned int v144; // w24
  __int64 v145; // x8
  __int64 v146; // x0
  __int64 v147; // x0
  __int64 v148; // x8
  __int64 v149; // x0
  __int64 v150; // x0
  __int64 v151; // x0
  __int64 v152; // x8
  __int64 v153; // x0
  __int64 v154; // x0
  __int64 v155; // x8
  unsigned __int64 v156; // x9
  __int64 v157; // x10
  int v158; // w11
  __int64 v159; // x8
  __int64 v160; // x0
  __int64 v161; // x0
  __int64 v162; // x8
  __int64 v163; // x0
  __int64 v164; // x0
  __int64 v165; // x8
  __int64 v166; // x0
  __int64 v167; // x0
  __int64 v168; // x8
  __int64 v169; // x0
  __int64 v170; // x0
  __int64 v171; // x8
  __int64 v172; // x0
  __int64 v173; // x0
  __int64 v174; // x0
  int v175; // w0
  __int64 v176; // x8
  __int64 v177; // x0
  __int64 v178; // x0
  __int64 v179; // x8
  __int64 v180; // x0
  __int64 v181; // x0
  __int64 v182; // x8
  __int64 v183; // x0
  __int64 v184; // x0
  __int64 v185; // x8
  __int64 v186; // x0
  __int64 v187; // x0
  __int64 v188; // x8
  __int64 v189; // x0
  __int64 v190; // x0
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
  __int64 v203; // x8
  __int64 v204; // x0
  __int64 v205; // x0
  unsigned int v206; // w9
  __int64 v207; // x8
  __int64 v208; // x0
  __int64 v209; // x0
  __int64 v210; // x8
  __int64 v211; // x0
  __int64 v212; // x0
  __int64 v213; // x8
  __int64 v214; // x0
  __int64 v215; // x0
  __int64 v216; // x8
  __int64 v217; // x0
  __int64 v218; // x0
  __int64 v219; // x8
  __int64 v220; // x0
  __int64 v221; // x0
  __int64 v222; // x8
  __int64 v223; // x0
  __int64 v224; // x0
  __int64 v225; // x8
  __int64 v226; // x0
  __int64 v227; // x0
  __int64 v228; // x0
  __int64 v229; // x8
  __int64 v230; // x0
  __int64 v231; // x8
  __int64 v232; // x0
  __int64 v233; // x0
  __int64 v234; // x8
  __int64 v235; // x0
  bool v236; // [xsp+Ch] [xbp-144h]
  __int64 v237; // [xsp+10h] [xbp-140h]
  unsigned int v238; // [xsp+18h] [xbp-138h] BYREF
  int v239; // [xsp+1Ch] [xbp-134h] BYREF
  __int64 v240; // [xsp+20h] [xbp-130h] BYREF
  unsigned int v241; // [xsp+28h] [xbp-128h] BYREF
  _BYTE v242[4]; // [xsp+2Ch] [xbp-124h] BYREF
  int v243; // [xsp+30h] [xbp-120h] BYREF
  unsigned __int64 v244; // [xsp+34h] [xbp-11Ch]
  _BYTE v245[12]; // [xsp+3Ch] [xbp-114h] BYREF
  int v246; // [xsp+48h] [xbp-108h] BYREF
  __int64 v247; // [xsp+4Ch] [xbp-104h]
  int v248; // [xsp+54h] [xbp-FCh]
  __int64 v249; // [xsp+58h] [xbp-F8h]
  __int64 v250; // [xsp+60h] [xbp-F0h]
  __int64 v251; // [xsp+68h] [xbp-E8h]
  __int64 v252; // [xsp+70h] [xbp-E0h]
  __int64 v253; // [xsp+78h] [xbp-D8h]
  __int64 v254; // [xsp+80h] [xbp-D0h]
  __int64 v255; // [xsp+88h] [xbp-C8h]
  __int64 v256; // [xsp+90h] [xbp-C0h]
  __int64 v257; // [xsp+98h] [xbp-B8h]
  __int64 v258; // [xsp+A0h] [xbp-B0h]
  __int64 (__fastcall *v259)(); // [xsp+A8h] [xbp-A8h]
  __int64 v260; // [xsp+B0h] [xbp-A0h]
  __int64 v261; // [xsp+B8h] [xbp-98h]
  const char *v262; // [xsp+C0h] [xbp-90h] BYREF
  char *v263; // [xsp+C8h] [xbp-88h]
  __int64 v264; // [xsp+D0h] [xbp-80h]
  __int64 v265; // [xsp+D8h] [xbp-78h]
  __int64 v266; // [xsp+E0h] [xbp-70h]
  __int64 v267; // [xsp+E8h] [xbp-68h]
  __int64 v268; // [xsp+F0h] [xbp-60h]
  __int64 v269; // [xsp+F8h] [xbp-58h]
  __int64 v270; // [xsp+100h] [xbp-50h]
  __int64 v271; // [xsp+108h] [xbp-48h]
  __int64 v272; // [xsp+110h] [xbp-40h]
  __int64 v273; // [xsp+118h] [xbp-38h]
  __int64 (__fastcall *v274)(); // [xsp+120h] [xbp-30h]
  __int64 v275; // [xsp+128h] [xbp-28h]
  __int64 v276; // [xsp+130h] [xbp-20h]
  __int64 v277; // [xsp+138h] [xbp-18h]
  __int64 v278; // [xsp+140h] [xbp-10h]

  v278 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v242[0] = 0;
  v241 = 0;
  v240 = 0;
  v239 = 0;
  ep_mapping = ipa_get_ep_mapping(a2);
  if ( ep_mapping == -1 || (v5 = ep_mapping, ep_mapping >= 31) )
  {
    printk(&unk_3FDEC5, "ipa3_eth_connect");
    v88 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_209;
    v89 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v89 )
    {
      ipc_log_string(v89, "ipa %s:%d undefined client_type\n", "ipa3_eth_connect", 916);
      v88 = ipa3_ctx;
    }
    v90 = *(_QWORD *)(v88 + 34160);
    if ( v90 )
    {
      ipc_log_string(v90, "ipa %s:%d undefined client_type\n", "ipa3_eth_connect", 916);
      result = 4294967282LL;
    }
    else
    {
LABEL_209:
      result = 4294967282LL;
    }
    goto LABEL_338;
  }
  if ( (*(_BYTE *)(a1 + 24) & 1) == 0 )
  {
    printk(&unk_3D854C, "ipa3_eth_connect");
    v92 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v93 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v93 )
      {
        ipc_log_string(v93, "ipa %s:%d transfer ring not valid!\n", "ipa3_eth_connect", 922);
        v92 = ipa3_ctx;
      }
      v94 = *(_QWORD *)(v92 + 34160);
      if ( v94 )
      {
        ipc_log_string(v94, "ipa %s:%d transfer ring not valid!\n", "ipa3_eth_connect", 922);
        result = 4294967274LL;
        goto LABEL_338;
      }
    }
LABEL_220:
    result = 4294967274LL;
    goto LABEL_338;
  }
  if ( **(_DWORD **)(a1 + 160) == 4 && *(_DWORD *)(a1 + 88) != 2048 )
  {
    printk(&unk_3B4E59, "ipa3_eth_connect");
    v162 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v163 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v163 )
      {
        ipc_log_string(
          v163,
          "ipa %s:%d fix buffer size %u not valid for NTN, use 2K\n",
          "ipa3_eth_connect",
          929,
          *(_DWORD *)(a1 + 88));
        v162 = ipa3_ctx;
      }
      v164 = *(_QWORD *)(v162 + 34160);
      if ( v164 )
      {
        ipc_log_string(
          v164,
          "ipa %s:%d fix buffer size %u not valid for NTN, use 2K\n",
          "ipa3_eth_connect",
          929,
          *(_DWORD *)(a1 + 88));
        result = 4294967274LL;
        goto LABEL_338;
      }
    }
    goto LABEL_220;
  }
  is_vlan_mode = ipa_is_vlan_mode(0, v242);
  if ( is_vlan_mode )
  {
    v95 = is_vlan_mode;
    printk(&unk_3D29BC, "ipa3_eth_connect");
    v96 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_183;
    v97 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v97 )
    {
      ipc_log_string(v97, "ipa %s:%d Could not determine IPA VLAN mode\n", "ipa3_eth_connect", 960);
      v96 = ipa3_ctx;
    }
    v98 = *(_QWORD *)(v96 + 34160);
    if ( !v98 )
      goto LABEL_183;
    ipc_log_string(v98, "ipa %s:%d Could not determine IPA VLAN mode\n", "ipa3_eth_connect", 960);
  }
  else
  {
    v238 = 0;
    prot = ipa3_eth_get_prot(a1, &v238);
    if ( !prot )
    {
      v8 = ipa3_smmu_map_eth_pipes(a1, a2, 1);
      if ( !v8 )
      {
        if ( v5 >= 0x25 )
          goto LABEL_357;
        v9 = ipa3_ctx + 480LL * v5;
        memset((void *)(v9 + 168), 0, 0x1D8u);
        v263 = "ipa_eth_i.c";
        v264 = 0x1000003D3LL;
        v262 = "ipa3_eth_connect";
        ipa3_inc_client_enable_clks();
        *(_DWORD *)(v9 + 168) = 1;
        *(_DWORD *)(v9 + 172) = a2;
        v10 = ipa3_disable_data_path(v5);
        if ( v10 )
        {
          v144 = v10;
          printk(&unk_3EF093, "ipa3_eth_connect");
          v145 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v146 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v146 )
            {
              ipc_log_string(
                v146,
                "ipa %s:%d disable data path failed res=%d clnt=%d.\n",
                "ipa3_eth_connect",
                985,
                v144,
                v5);
              v145 = ipa3_ctx;
            }
            v147 = *(_QWORD *)(v145 + 34160);
            if ( v147 )
              ipc_log_string(
                v147,
                "ipa %s:%d disable data path failed res=%d clnt=%d.\n",
                "ipa3_eth_connect",
                985,
                v144,
                v5);
          }
          goto LABEL_337;
        }
        v11 = (a2 & 1) == 0 && a2 < 0x86;
        *(_DWORD *)(v9 + 312) = v11;
        v12 = v242[0];
        *(_DWORD *)(v9 + 400) = 0;
        if ( v12 )
          v13 = 18;
        else
          v13 = 14;
        v14 = a2 > 0x85 || (a2 & 1) == 0;
        *(_DWORD *)(v9 + 324) = v13;
        if ( v14 )
        {
          *(_QWORD *)(v9 + 544) = *(_QWORD *)(a1 + 96);
          *(_QWORD *)(v9 + 536) = *(_QWORD *)(a1 + 104);
          if ( !v12 )
            goto LABEL_25;
          v15 = 0;
          *(_QWORD *)(v9 + 328) = 0xE00000001LL;
          v16 = 188;
        }
        else
        {
          *(_DWORD *)(v9 + 416) = 2;
          v16 = 260;
          *(_QWORD *)(v9 + 408) = 0x400000001LL;
          v15 = 1;
          *(_DWORD *)(v9 + 424) = 1;
        }
        *(_DWORD *)(v9 + 168 + v16) = v15;
LABEL_25:
        if ( (unsigned int)ipa3_cfg_ep(v5, v9 + 312) )
        {
          printk(&unk_3BB0CE, "ipa3_eth_connect");
          v148 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v149 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v149 )
            {
              ipc_log_string(v149, "ipa %s:%d fail to setup rx pipe cfg\n", "ipa3_eth_connect", 1010);
              v148 = ipa3_ctx;
            }
            v150 = *(_QWORD *)(v148 + 34160);
            if ( v150 )
              ipc_log_string(v150, "ipa %s:%d fail to setup rx pipe cfg\n", "ipa3_eth_connect", 1010);
            v144 = 0;
          }
          else
          {
            v144 = 0;
          }
          goto LABEL_337;
        }
        if ( v11 )
          ipa3_install_dflt_flt_rules(v5);
        v17 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v18 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v18 )
          {
            ipc_log_string(v18, "ipa %s:%d client %d (ep: %d) connected\n", "ipa3_eth_connect", 1016, a2, v5);
            v17 = ipa3_ctx;
          }
          v19 = *(_QWORD *)(v17 + 34160);
          if ( v19 )
            ipc_log_string(v19, "ipa %s:%d client %d (ep: %d) connected\n", "ipa3_eth_connect", 1016, a2, v5);
        }
        v20 = v238;
        v236 = v14;
        v237 = v238;
        switch ( v238 )
        {
          case 1u:
            if ( (*(_BYTE *)(a1 + 24) & 1) == 0 )
            {
              v228 = printk(&unk_3D2A1F, "ipa_eth_setup_aqc_gsi_channel");
              v231 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v232 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v232 )
                {
                  ipc_log_string(v232, "ipa %s:%d RTK transfer ring invalid\n", "ipa_eth_setup_aqc_gsi_channel", 611);
                  v231 = ipa3_ctx;
                }
                v228 = *(_QWORD *)(v231 + 34160);
                if ( v228 )
                  v228 = ipc_log_string(
                           v228,
                           "ipa %s:%d RTK transfer ring invalid\n",
                           "ipa_eth_setup_aqc_gsi_channel",
                           611);
              }
              goto LABEL_349;
            }
            v34 = *(_DWORD *)(a1 + 48);
            v266 = 32;
            v267 = 0;
            v268 = 0;
            v269 = 0;
            v271 = 0;
            v272 = 0;
            v275 = 0;
            v276 = 0;
            v277 = 0;
            v262 = (_BYTE *)&unk_8;
            v270 = 0;
            v35 = *(_QWORD *)(a1 + 112);
            *(_DWORD *)((char *)&v266 + 2) = (unsigned __int8)(((unsigned __int64)(13743895350LL * v34) >> 41)
                                                             + (13743895350LL * v34 < 0));
            v273 = 1;
            v274 = ipa_eth_gsi_evt_ring_err_cb;
            v36 = v35 | 0x10000000000LL;
            v37 = *(_QWORD *)(a1 + 136);
            LODWORD(v263) = 16;
            HIDWORD(v263) = v34;
            v38 = *(_QWORD *)(a1 + 32);
            v268 = v37 + v36;
            v264 = v38;
            v265 = 0;
            if ( (unsigned int)gsi_alloc_evt_ring(&v262, *(_QWORD *)(ipa3_ctx + 43296), v9 + 184) )
            {
              printk(&unk_3E0EF0, "ipa_eth_setup_aqc_gsi_channel");
              v188 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v189 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v189 )
                {
                  ipc_log_string(v189, "ipa %s:%d fail to alloc RX event ring\n", "ipa_eth_setup_aqc_gsi_channel", 640);
                  v188 = ipa3_ctx;
                }
                v190 = *(_QWORD *)(v188 + 34160);
                if ( v190 )
                  ipc_log_string(v190, "ipa %s:%d fail to alloc RX event ring\n", "ipa_eth_setup_aqc_gsi_channel", 640);
              }
            }
            *(_DWORD *)(v9 + 192) = HIDWORD(v263);
            *(_QWORD *)(v9 + 200) = v264;
            v39 = *(_DWORD *)(a1 + 16);
            v260 = 0;
            v261 = 0;
            v258 = 0;
            v259 = nullptr;
            v256 = 0;
            v257 = 0;
            v254 = 0;
            v255 = 0;
            v252 = 0;
            v253 = 0;
            v250 = 0;
            v251 = 0;
            v248 = 0;
            v249 = 0;
            v246 = 8;
            v247 = v39 != 0;
            v40 = ((__int64 (__fastcall *)(_QWORD))ipa_get_gsi_ep_info)(*(unsigned int *)(v9 + 172));
            if ( v40 )
            {
              BYTE4(v247) = *(_DWORD *)(v40 + 4);
              v41 = *(_QWORD *)(v9 + 184);
              LODWORD(v250) = 16;
              v255 = 1;
              LOBYTE(v253) = 0;
              v249 = v41;
              HIDWORD(v256) = *(_DWORD *)(v40 + 20);
              v42 = *(_BYTE *)(v40 + 24);
              LOBYTE(v256) = 1;
              v259 = ipa_eth_gsi_chan_err_cb;
              v43 = *(_QWORD *)(a1 + 32);
              v44 = *(_QWORD *)(ipa3_ctx + 43296);
              HIDWORD(v250) = v34;
              LOBYTE(v257) = v42;
              v252 = v43;
              v20 = v237;
              v33 = gsi_alloc_channel(&v246, v44, v9 + 176);
              if ( v33 )
              {
LABEL_55:
                gsi_dealloc_evt_ring(*(_QWORD *)(v9 + 184));
                goto LABEL_56;
              }
              *(_DWORD *)(v9 + 216) = HIDWORD(v250);
              *(_QWORD *)(v9 + 224) = v252;
              v45 = 2031616 - (__clz(*(_DWORD *)(a1 + 88)) << 16);
              if ( *(_DWORD *)(a1 + 16) == 1 )
              {
                v46 = *(int **)(a1 + 80);
                v47 = *((unsigned __int8 *)v46 + 4);
                v48 = *(_QWORD *)(a1 + 120) + v36;
                v49 = *v46;
                v50 = HIDWORD(v48) & 0x1FF;
                v45 |= v47;
              }
              else
              {
                v49 = 0;
                LODWORD(v48) = 0;
                LODWORD(v50) = 0;
              }
              v151 = *(_QWORD *)(v9 + 176);
              v243 = v49;
              v244 = __PAIR64__(v48, v45);
              *(_DWORD *)v245 = v50;
              *(_QWORD *)&v245[4] = 0;
              v33 = gsi_write_channel_scratch(v151, &v243);
              if ( !v33 )
                goto LABEL_57;
              printk(&unk_3D2A46, "ipa_eth_setup_aqc_gsi_channel");
              v152 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v153 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v153 )
                {
                  ipc_log_string(
                    v153,
                    "ipa %s:%d failed to write evt ring scratch\n",
                    "ipa_eth_setup_aqc_gsi_channel",
                    710);
                  v152 = ipa3_ctx;
                }
                v154 = *(_QWORD *)(v152 + 34160);
                if ( v154 )
                  ipc_log_string(
                    v154,
                    "ipa %s:%d failed to write evt ring scratch\n",
                    "ipa_eth_setup_aqc_gsi_channel",
                    710);
              }
LABEL_244:
              gsi_dealloc_channel(*(_QWORD *)(v9 + 176));
              *(_QWORD *)(v9 + 176) = -1;
              goto LABEL_55;
            }
            printk(&unk_3CC819, "ipa_eth_setup_aqc_gsi_channel");
            v191 = ipa3_ctx;
            v20 = v237;
            if ( ipa3_ctx )
            {
              v192 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v192 )
              {
                ipc_log_string(
                  v192,
                  "ipa %s:%d Failed getting GSI EP info for client=%d\n",
                  "ipa_eth_setup_aqc_gsi_channel",
                  658,
                  *(_DWORD *)(v9 + 172));
                v191 = ipa3_ctx;
              }
              v193 = *(_QWORD *)(v191 + 34160);
              if ( v193 )
              {
                ipc_log_string(
                  v193,
                  "ipa %s:%d Failed getting GSI EP info for client=%d\n",
                  "ipa_eth_setup_aqc_gsi_channel",
                  658,
                  *(unsigned int *)(v9 + 172));
LABEL_283:
                v33 = -22;
                goto LABEL_55;
              }
            }
            break;
          case 0xAu:
            v51 = *(_BYTE *)(a1 + 24);
            v276 = 0;
            v277 = 0;
            v274 = nullptr;
            v275 = 0;
            v272 = 0;
            v273 = 0;
            v270 = 0;
            v271 = 0;
            v268 = 0;
            v269 = 0;
            v266 = 0;
            v267 = 0;
            v264 = 0;
            v265 = 0;
            v262 = nullptr;
            v263 = nullptr;
            if ( (v51 & 1) == 0 )
            {
              v233 = printk(&unk_3DB600, "ipa_eth_setup_ntn_gsi_channel");
              v234 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v235 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v235 )
                {
                  ipc_log_string(v235, "ipa %s:%d NTN transfer ring invalid\n", "ipa_eth_setup_ntn_gsi_channel", 736);
                  v234 = ipa3_ctx;
                }
                v233 = *(_QWORD *)(v234 + 34160);
                if ( v233 )
                  v233 = ipc_log_string(
                           v233,
                           "ipa %s:%d NTN transfer ring invalid\n",
                           "ipa_eth_setup_ntn_gsi_channel",
                           736);
              }
              ((void (__fastcall *)(__int64))ipa_assert)(v233);
              goto LABEL_262;
            }
            v52 = *(_DWORD *)(a1 + 48);
            v53 = *(unsigned __int8 *)(*(_QWORD *)(a1 + 160) + 40LL);
            v266 = 32;
            v267 = 0;
            v273 = 1;
            v268 = 0;
            v269 = 0;
            v274 = ipa_eth_gsi_evt_ring_err_cb;
            v275 = 0;
            v271 = 0;
            v272 = 0;
            v276 = 0;
            v277 = 0;
            v262 = (_BYTE *)&unk_D;
            *(_DWORD *)((char *)&v266 + 2) = (unsigned __int8)(((unsigned __int64)(13743895350LL * v52) >> 41)
                                                             + (13743895350LL * v52 < 0));
            v55 = *(_QWORD *)(a1 + 112);
            v54 = *(_QWORD *)(a1 + 120);
            v270 = 0;
            if ( !v53 )
              v55 |= 0x10000000000uLL;
            v268 = v54 + v55;
            LODWORD(v263) = 16;
            HIDWORD(v263) = v52;
            v56 = *(_QWORD *)(ipa3_ctx + 43296);
            v264 = *(_QWORD *)(a1 + 32);
            v265 = 0;
            if ( (unsigned int)gsi_alloc_evt_ring(&v262, v56, v9 + 184) )
            {
              printk(&unk_3E0EF0, "ipa_eth_setup_ntn_gsi_channel");
              v194 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v195 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v195 )
                {
                  ipc_log_string(v195, "ipa %s:%d fail to alloc RX event ring\n", "ipa_eth_setup_ntn_gsi_channel", 770);
                  v194 = ipa3_ctx;
                }
                v196 = *(_QWORD *)(v194 + 34160);
                if ( v196 )
                  ipc_log_string(v196, "ipa %s:%d fail to alloc RX event ring\n", "ipa_eth_setup_ntn_gsi_channel", 770);
              }
            }
            *(_DWORD *)(v9 + 192) = HIDWORD(v263);
            *(_QWORD *)(v9 + 200) = v264;
            v57 = *(_DWORD *)(a1 + 16);
            v260 = 0;
            v261 = 0;
            v258 = 0;
            v259 = nullptr;
            v256 = 0;
            v257 = 0;
            v254 = 0;
            v255 = 0;
            v252 = 0;
            v253 = 0;
            v250 = 0;
            v251 = 0;
            v248 = 0;
            v249 = 0;
            v246 = 13;
            v247 = v57 != 0;
            v58 = ((__int64 (__fastcall *)(_QWORD))ipa_get_gsi_ep_info)(*(unsigned int *)(v9 + 172));
            if ( v58 )
            {
              BYTE4(v247) = *(_DWORD *)(v58 + 4);
              v59 = *(_QWORD *)(v9 + 184);
              LODWORD(v250) = 16;
              v255 = 1;
              LOBYTE(v253) = 1;
              v249 = v59;
              HIDWORD(v256) = *(_DWORD *)(v58 + 20);
              v60 = *(_BYTE *)(v58 + 24);
              LOBYTE(v256) = 1;
              v259 = ipa_eth_gsi_chan_err_cb;
              v61 = *(_QWORD *)(a1 + 32);
              v62 = *(_QWORD *)(ipa3_ctx + 43296);
              HIDWORD(v250) = v52;
              LOBYTE(v257) = v60;
              v252 = v61;
              v33 = gsi_alloc_channel(&v246, v62, v9 + 176);
              if ( v33 )
                goto LABEL_55;
              *(_DWORD *)(v9 + 216) = HIDWORD(v250);
              *(_QWORD *)(v9 + 224) = v252;
              v77 = (3840 - (__clz(*(_DWORD *)(a1 + 88)) << 8)) & 0xF00;
              if ( *(_BYTE *)(a1 + 52) == 1 )
                v78 = (__int64 *)(a1 + 56);
              else
                v78 = *(__int64 **)(a1 + 80);
              v155 = *v78;
              v156 = BYTE4(v155) | v77;
              if ( !*(_DWORD *)(a1 + 16) )
              {
                v157 = *(unsigned __int16 *)(a1 + 128);
                v158 = v52 + 15;
                if ( v52 >= 0 )
                  v158 = v52;
                if ( *(_WORD *)(a1 + 128) && v158 >> 4 > (int)v157 )
                  v156 |= v157 << 32;
                else
                  v156 |= 0x2000000000uLL;
              }
              v174 = *(_QWORD *)(v9 + 176);
              v243 = v155;
              v244 = v156;
              memset(v245, 0, sizeof(v245));
              v175 = gsi_write_channel_scratch(v174, &v243);
              v33 = 0;
              if ( !v175 )
                goto LABEL_57;
              v33 = v175;
              printk(&unk_3D2A46, "ipa_eth_setup_ntn_gsi_channel");
              v176 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v177 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v177 )
                {
                  ipc_log_string(
                    v177,
                    "ipa %s:%d failed to write evt ring scratch\n",
                    "ipa_eth_setup_ntn_gsi_channel",
                    849);
                  v176 = ipa3_ctx;
                }
                v178 = *(_QWORD *)(v176 + 34160);
                if ( v178 )
                  ipc_log_string(
                    v178,
                    "ipa %s:%d failed to write evt ring scratch\n",
                    "ipa_eth_setup_ntn_gsi_channel",
                    849);
              }
              goto LABEL_244;
            }
            printk(&unk_3CC819, "ipa_eth_setup_ntn_gsi_channel");
            v197 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v198 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v198 )
              {
                ipc_log_string(
                  v198,
                  "ipa %s:%d Failed getting GSI EP info for client=%d\n",
                  "ipa_eth_setup_ntn_gsi_channel",
                  789,
                  *(_DWORD *)(v9 + 172));
                v197 = ipa3_ctx;
              }
              v199 = *(_QWORD *)(v197 + 34160);
              if ( v199 )
              {
                ipc_log_string(
                  v199,
                  "ipa %s:%d Failed getting GSI EP info for client=%d\n",
                  "ipa_eth_setup_ntn_gsi_channel",
                  789,
                  *(unsigned int *)(v9 + 172));
                goto LABEL_283;
              }
            }
            break;
          case 9u:
            if ( (*(_BYTE *)(a1 + 24) & 1) != 0 )
            {
              v21 = *(_QWORD *)(a1 + 112);
              v22 = *(_DWORD *)(a1 + 16);
              v262 = (_BYTE *)&_ksymtab_ipa3_add_rt_rule_after;
              v265 = 0;
              v266 = 0;
              v267 = 0;
              v268 = 0;
              v269 = 0;
              v270 = 0;
              v271 = 0;
              v272 = 0;
              v273 = 0;
              v274 = nullptr;
              v275 = 0;
              v276 = 0;
              v277 = 0;
              LODWORD(v263) = 32;
              if ( !v22 )
              {
                LOWORD(v266) = 32;
                BYTE2(v266) = 0x80;
              }
              v23 = *(_QWORD *)(a1 + 128);
              v274 = ipa_eth_gsi_evt_ring_err_cb;
              v275 = 0;
              LOBYTE(v273) = 1;
              v24 = *(_DWORD *)(a1 + 48);
              v25 = *(_QWORD *)(a1 + 32);
              v26 = *(_QWORD *)(ipa3_ctx + 43296);
              v268 = v23 + (v21 | 0x10000000000LL);
              HIDWORD(v263) = v24;
              v264 = v25;
              if ( !(unsigned int)gsi_alloc_evt_ring(&v262, v26, v9 + 184) )
              {
                *(_DWORD *)(v9 + 192) = HIDWORD(v263);
                *(_QWORD *)(v9 + 200) = v264;
                v27 = *(_DWORD *)(a1 + 16);
                v260 = 0;
                v261 = 0;
                v258 = 0;
                v259 = nullptr;
                v256 = 0;
                v257 = 0;
                v254 = 0;
                v255 = 0;
                v252 = 0;
                v253 = 0;
                v250 = 0;
                v251 = 0;
                v248 = 0;
                v249 = 0;
                v246 = 12;
                v247 = v27 != 0;
                v28 = ((__int64 (__fastcall *)(_QWORD))ipa_get_gsi_ep_info)(*(unsigned int *)(v9 + 172));
                if ( !v28 )
                {
                  printk(&unk_3CC819, "ipa_eth_setup_rtk_gsi_channel");
                  v200 = ipa3_ctx;
                  if ( !ipa3_ctx )
                    goto LABEL_308;
                  v201 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v201 )
                  {
                    ipc_log_string(
                      v201,
                      "ipa %s:%d Failed getting GSI EP info for client=%d\n",
                      "ipa_eth_setup_rtk_gsi_channel",
                      368,
                      *(_DWORD *)(v9 + 172));
                    v200 = ipa3_ctx;
                  }
                  v202 = *(_QWORD *)(v200 + 34160);
                  if ( v202 )
                  {
                    ipc_log_string(
                      v202,
                      "ipa %s:%d Failed getting GSI EP info for client=%d\n",
                      "ipa_eth_setup_rtk_gsi_channel",
                      368,
                      *(_DWORD *)(v9 + 172));
                    v33 = -22;
                  }
                  else
                  {
LABEL_308:
                    v33 = -22;
                  }
                  goto LABEL_42;
                }
                BYTE4(v247) = *(_DWORD *)(v28 + 4);
                v29 = *(_QWORD *)(v9 + 184);
                LODWORD(v250) = 32;
                v255 = 1;
                LOBYTE(v253) = 1;
                v249 = v29;
                HIDWORD(v256) = *(_DWORD *)(v28 + 20);
                v30 = *(_BYTE *)(v28 + 24);
                LOBYTE(v256) = 1;
                v259 = ipa_eth_gsi_chan_err_cb;
                v31 = *(_QWORD *)(a1 + 32);
                v32 = *(_QWORD *)(ipa3_ctx + 43296);
                HIDWORD(v250) = v24;
                LOBYTE(v257) = v30;
                v252 = v31;
                v33 = gsi_alloc_channel(&v246, v32, v9 + 176);
                if ( v33 )
                {
LABEL_42:
                  gsi_dealloc_evt_ring(*(_QWORD *)(v9 + 184));
                  v20 = v237;
LABEL_56:
                  *(_QWORD *)(v9 + 184) = -1;
                  goto LABEL_57;
                }
                v79 = *(_QWORD *)(v9 + 176);
                *(_DWORD *)(v9 + 216) = HIDWORD(v250);
                *(_QWORD *)(v9 + 224) = v252;
                v80 = *(_BYTE *)(a1 + 124);
                v81 = __clz(*(_DWORD *)(a1 + 88));
                if ( v80 )
                  v82 = 18;
                else
                  v82 = 16;
                v83 = **(_QWORD **)(a1 + 80);
                if ( *(_DWORD *)(a1 + 16) != 1 )
                  v80 = v82;
                memset(v245, 0, sizeof(v245));
                v243 = v21;
                LODWORD(v244) = ((v21 | 0x10000000000uLL) >> 32) & 0x1FF
                              | ((v80 & 0x1F) << 9)
                              | (245760 - (v81 << 14)) & 0x3C000
                              | (v83 >> 8) & 0xFF000000;
                HIDWORD(v244) = v83;
                v84 = gsi_write_channel_scratch(v79, &v243);
                v20 = v237;
                if ( v84 )
                {
                  v33 = v84;
                  printk(&unk_3D2A46, "ipa_eth_setup_rtk_gsi_channel");
                  v85 = ipa3_ctx;
                  if ( ipa3_ctx )
                  {
                    v86 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v86 )
                    {
                      ipc_log_string(
                        v86,
                        "ipa %s:%d failed to write evt ring scratch\n",
                        "ipa_eth_setup_rtk_gsi_channel",
                        426);
                      v85 = ipa3_ctx;
                    }
                    v87 = *(_QWORD *)(v85 + 34160);
                    if ( v87 )
                      ipc_log_string(
                        v87,
                        "ipa %s:%d failed to write evt ring scratch\n",
                        "ipa_eth_setup_rtk_gsi_channel",
                        426);
                  }
                  gsi_dealloc_channel(*(_QWORD *)(v9 + 176));
                  *(_QWORD *)(v9 + 176) = -1;
                  goto LABEL_42;
                }
LABEL_57:
                if ( !v33 )
                {
                  if ( (unsigned int)gsi_query_channel_db_addr(*(_QWORD *)(v9 + 176), &v241, (char *)&v240 + 4) )
                  {
                    printk(&unk_3C9AA8, "ipa3_eth_connect");
                    v159 = ipa3_ctx;
                    if ( ipa3_ctx )
                    {
                      v160 = *(_QWORD *)(ipa3_ctx + 34152);
                      if ( v160 )
                      {
                        ipc_log_string(v160, "ipa %s:%d failed to query gsi rx db addr\n", "ipa3_eth_connect", 1040);
                        v159 = ipa3_ctx;
                      }
                      v161 = *(_QWORD *)(v159 + 34160);
                      if ( v161 )
                      {
                        ipc_log_string(v161, "ipa %s:%d failed to query gsi rx db addr\n", "ipa3_eth_connect", 1040);
LABEL_255:
                        v144 = -14;
LABEL_337:
                        ipa3_smmu_map_eth_pipes(a1, a2, 0);
                        v262 = "ipa3_eth_connect";
                        v263 = "ipa_eth_i.c";
                        v264 = 0x10000050BLL;
                        ipa3_dec_client_disable_clks();
                        result = v144;
                        goto LABEL_338;
                      }
LABEL_336:
                      v144 = -14;
                      goto LABEL_337;
                    }
                    goto LABEL_256;
                  }
                  v63 = (int *)(ipa3_ctx + 28640);
                  if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x15u )
                  {
                    switch ( (_DWORD)v20 )
                    {
                      case 0xA:
                        if ( !(unsigned int)gsi_query_msi_addr(*(_QWORD *)(v9 + 176), a1 + 144) )
                        {
                          *(_DWORD *)(a1 + 152) = 0;
                          if ( v236 )
                            goto LABEL_142;
                          if ( arm64_use_ng_mappings )
                            v71 = 0x68000000000F13LL;
                          else
                            v71 = 0x68000000000713LL;
                          v72 = ioremap_prot(*(_QWORD *)(a1 + 144), 4, v71);
                          if ( !v72 )
                          {
                            printk(&unk_3B7FAF, "ipa3_eth_connect");
                            v222 = ipa3_ctx;
                            if ( ipa3_ctx )
                            {
                              v223 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v223 )
                              {
                                ipc_log_string(v223, "ipa %s:%d ioremap failed\n", "ipa3_eth_connect", 1101);
                                v222 = ipa3_ctx;
                              }
                              v224 = *(_QWORD *)(v222 + 34160);
                              if ( v224 )
                              {
                                ipc_log_string(v224, "ipa %s:%d ioremap failed\n", "ipa3_eth_connect", 1101);
                                goto LABEL_255;
                              }
                            }
                            goto LABEL_336;
                          }
                          v73 = v72;
                          v74 = 0;
                          goto LABEL_141;
                        }
                        break;
                      case 9:
                        if ( !(unsigned int)gsi_query_msi_addr(*(_QWORD *)(v9 + 176), a1 + 144) )
                        {
                          if ( v236 )
                            goto LABEL_142;
                          if ( arm64_use_ng_mappings )
                            v75 = 0x68000000000F13LL;
                          else
                            v75 = 0x68000000000713LL;
                          v76 = ioremap_prot(*(_QWORD *)(a1 + 144), 4, v75);
                          if ( !v76 )
                          {
                            printk(&unk_3B7FAF, "ipa3_eth_connect");
                            v225 = ipa3_ctx;
                            if ( ipa3_ctx )
                            {
                              v226 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v226 )
                              {
                                ipc_log_string(v226, "ipa %s:%d ioremap failed\n", "ipa3_eth_connect", 1081);
                                v225 = ipa3_ctx;
                              }
                              v227 = *(_QWORD *)(v225 + 34160);
                              if ( v227 )
                              {
                                ipc_log_string(v227, "ipa %s:%d ioremap failed\n", "ipa3_eth_connect", 1081);
                                goto LABEL_255;
                              }
                            }
                            goto LABEL_336;
                          }
                          v73 = v76;
                          v74 = 4059;
                          goto LABEL_141;
                        }
                        break;
                      case 1:
                        if ( v11 )
                        {
                          if ( (unsigned int)gsi_query_msi_addr(*(_QWORD *)(v9 + 176), a1 + 144) )
                            goto LABEL_336;
                          goto LABEL_142;
                        }
                        v109 = v241;
                        v110 = arm64_use_ng_mappings;
                        *(_DWORD *)(a1 + 152) = 0;
                        *(_QWORD *)(a1 + 144) = v109;
                        if ( v110 )
                          v111 = 0x68000000000F13LL;
                        else
                          v111 = 0x68000000000713LL;
                        v112 = ioremap_prot(v109, 4, v111);
                        if ( !v112 )
                        {
                          printk(&unk_3B7FAF, "ipa3_eth_connect");
                          v219 = ipa3_ctx;
                          if ( ipa3_ctx )
                          {
                            v220 = *(_QWORD *)(ipa3_ctx + 34152);
                            if ( v220 )
                            {
                              ipc_log_string(v220, "ipa %s:%d ioremap failed\n", "ipa3_eth_connect", 1060);
                              v219 = ipa3_ctx;
                            }
                            v221 = *(_QWORD *)(v219 + 34160);
                            if ( v221 )
                            {
                              ipc_log_string(v221, "ipa %s:%d ioremap failed\n", "ipa3_eth_connect", 1060);
                              goto LABEL_255;
                            }
                          }
                          goto LABEL_336;
                        }
                        v73 = v112;
                        v74 = (unsigned int)(*(_DWORD *)(v9 + 216) + *(_DWORD *)(v9 + 224));
LABEL_141:
                        writel(v74, v73);
                        iounmap(v73);
                        goto LABEL_142;
                      default:
                        printk(&unk_3B2232, "ipa3_eth_connect");
                        v213 = ipa3_ctx;
                        if ( ipa3_ctx )
                        {
                          v214 = *(_QWORD *)(ipa3_ctx + 34152);
                          if ( v214 )
                          {
                            ipc_log_string(v214, "ipa %s:%d unknown protocol %d\n", "ipa3_eth_connect", 1112, v20);
                            v213 = ipa3_ctx;
                          }
                          v215 = *(_QWORD *)(v213 + 34160);
                          if ( v215 )
                            ipc_log_string(v215, "ipa %s:%d unknown protocol %d\n", "ipa3_eth_connect", 1112, v20);
                        }
LABEL_142:
                        gsi_query_evt_ring_db_addr(*(_QWORD *)(v9 + 184), &v240, &v239);
                        v113 = ipa3_ctx;
                        if ( ipa3_ctx )
                        {
                          v114 = *(_QWORD *)(ipa3_ctx + 34152);
                          if ( v114 )
                          {
                            ipc_log_string(
                              v114,
                              "ipa %s:%d evt_ring_hdl %lu, db_addr_low %u db_addr_high %u\n",
                              "ipa3_eth_connect",
                              1174,
                              *(_QWORD *)(v9 + 184),
                              v240,
                              v239);
                            v113 = ipa3_ctx;
                          }
                          v115 = *(_QWORD *)(v113 + 34160);
                          if ( v115 )
                            ipc_log_string(
                              v115,
                              "ipa %s:%d evt_ring_hdl %lu, db_addr_low %u db_addr_high %u\n",
                              "ipa3_eth_connect",
                              1174,
                              *(_QWORD *)(v9 + 184),
                              v240,
                              v239);
                        }
                        if ( arm64_use_ng_mappings )
                          v116 = 0x68000000000F13LL;
                        else
                          v116 = 0x68000000000713LL;
                        v117 = ioremap_prot((unsigned int)v240, 4, v116);
                        if ( v117 )
                        {
                          v118 = v117;
                          if ( (_DWORD)v20 == 9 && *(_DWORD *)(ipa3_ctx + 32240) > 0x14u )
                            v120 = 32;
                          else
                            v120 = 16;
                          writel((unsigned int)(*(_DWORD *)(v9 + 192) + *(_DWORD *)(v9 + 200) + v120), v117);
                          iounmap(v118);
                          v121 = ipa3_enable_data_path(v5);
                          if ( v121 )
                          {
                            v144 = v121;
                            printk(&unk_3D29EB, "ipa3_eth_connect");
                            v168 = ipa3_ctx;
                            if ( ipa3_ctx )
                            {
                              v169 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v169 )
                              {
                                ipc_log_string(
                                  v169,
                                  "ipa %s:%d enable data path failed res=%d clnt=%d\n",
                                  "ipa3_eth_connect",
                                  1205,
                                  v144,
                                  v5);
                                v168 = ipa3_ctx;
                              }
                              v170 = *(_QWORD *)(v168 + 34160);
                              if ( v170 )
                                ipc_log_string(
                                  v170,
                                  "ipa %s:%d enable data path failed res=%d clnt=%d\n",
                                  "ipa3_eth_connect",
                                  1205,
                                  v144,
                                  v5);
                            }
                            goto LABEL_337;
                          }
                          started = gsi_start_channel(*(_QWORD *)(v9 + 176));
                          if ( started )
                          {
                            v144 = started;
                            printk(&unk_3DB57A, "ipa3_eth_connect");
                            v171 = ipa3_ctx;
                            if ( ipa3_ctx )
                            {
                              v172 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v172 )
                              {
                                ipc_log_string(
                                  v172,
                                  "ipa %s:%d failed to start gsi tx channel\n",
                                  "ipa3_eth_connect",
                                  1212);
                                v171 = ipa3_ctx;
                              }
                              v173 = *(_QWORD *)(v171 + 34160);
                              if ( v173 )
                                ipc_log_string(
                                  v173,
                                  "ipa %s:%d failed to start gsi tx channel\n",
                                  "ipa3_eth_connect",
                                  1212);
                            }
                            goto LABEL_320;
                          }
                          v123 = ipa3_ctx;
                          v124 = *(_DWORD *)(a1 + 16);
                          v125 = *(_DWORD *)(ipa3_ctx + 32240);
                          if ( v125 >= 0x11 && v125 != 23 )
                          {
                            v126 = 2LL * (v124 == 0);
                            v127 = 14 * v20;
                            *(_BYTE *)(ipa3_ctx + v126 + v127 + 45237) = *(_QWORD *)(v9 + 176);
                            *(_BYTE *)(ipa3_ctx + v126 + v127 + 45236) = *(_DWORD *)(a1 + 16);
                            ipa3_uc_debug_stats_alloc(
                              *(_QWORD *)(ipa3_ctx + 45232 + 14 * v20),
                              *(unsigned int *)(ipa3_ctx + 45232 + 14 * v20 + 8)
                            | ((unsigned __int64)*(unsigned __int16 *)(ipa3_ctx + 45232 + 14 * v20 + 12) << 32));
                            v123 = ipa3_ctx;
                            v125 = *(_DWORD *)(ipa3_ctx + 32240);
                          }
                          v128 = *(unsigned int **)(a1 + 160);
                          v129 = 0;
                          if ( v125 == 17 && (_DWORD)v20 == 1 )
                          {
                            if ( *v128 > 5 || *((unsigned __int8 *)v128 + 4) > 2uLL )
                              goto LABEL_357;
                            if ( !*(_BYTE *)(v123 + 208LL * *v128 + 104LL * *((unsigned __int8 *)v128 + 4) + 48880) )
                            {
                              inited = ipa3_eth_uc_init_peripheral(1, *(_QWORD *)(a1 + 112) | 0x10000000000LL);
                              if ( inited )
                              {
                                v144 = inited;
                                printk(&unk_3CC8A0, "ipa3_eth_connect");
                                v216 = ipa3_ctx;
                                if ( ipa3_ctx )
                                {
                                  v217 = *(_QWORD *)(ipa3_ctx + 34152);
                                  if ( v217 )
                                  {
                                    ipc_log_string(
                                      v217,
                                      "ipa %s:%d failed to init peripheral from uc\n",
                                      "ipa3_eth_connect",
                                      1244);
                                    v216 = ipa3_ctx;
                                  }
                                  v218 = *(_QWORD *)(v216 + 34160);
                                  if ( v218 )
                                    ipc_log_string(
                                      v218,
                                      "ipa %s:%d failed to init peripheral from uc\n",
                                      "ipa3_eth_connect",
                                      1244);
                                }
LABEL_319:
                                ipa_stop_gsi_channel(*(unsigned int *)(v9 + 176));
LABEL_320:
                                ipa3_disable_data_path(v5);
                                goto LABEL_337;
                              }
                              v128 = *(unsigned int **)(a1 + 160);
                            }
                            v129 = *(unsigned __int8 *)(a1 + 128);
                          }
                          v131 = *v128;
                          if ( *v128 < 6 )
                          {
                            v132 = *((unsigned __int8 *)v128 + 4);
                            if ( v132 <= 2 )
                            {
                              v133 = ipa3_ctx;
                              v134 = v124 == 0;
                              v135 = (char *)(ipa3_ctx + 208LL * v131 + 104LL * (unsigned int)v132 + 48880);
                              v136 = &v135[20 * v134];
                              if ( (v136[20] & 1) == 0 )
                              {
                                v137 = *v135;
                                v138 = *(_DWORD *)(v9 + 176);
                                v139 = *(unsigned __int8 *)(a1 + 168);
                                *((_DWORD *)v136 + 1) = a2;
                                *((_DWORD *)v136 + 2) = v5;
                                v136[20] = 1;
                                *v135 = v137 + 1;
                                *((_DWORD *)v136 + 3) = v139;
                                *((_DWORD *)v136 + 4) = v138;
                                v133 = ipa3_ctx;
                              }
                              if ( *(_DWORD *)(v133 + 32240) != 17 && (_DWORD)v237 != 9
                                || (v140 = ipa3_eth_config_uc(
                                             1,
                                             v237,
                                             *(_DWORD *)(a1 + 16) == 0,
                                             *(unsigned __int8 *)(v9 + 176),
                                             v129)) == 0 )
                              {
                                v262 = "ipa3_eth_connect";
                                v263 = "ipa_eth_i.c";
                                v264 = 0x1000004F2LL;
                                ipa3_dec_client_disable_clks();
                                result = 0;
                                goto LABEL_338;
                              }
                              v144 = v140;
                              printk(&unk_3C3E43, "ipa3_eth_connect");
                              v203 = ipa3_ctx;
                              if ( ipa3_ctx )
                              {
                                v204 = *(_QWORD *)(ipa3_ctx + 34152);
                                if ( v204 )
                                {
                                  ipc_log_string(v204, "ipa %s:%d failed to config uc\n", "ipa3_eth_connect", 1261);
                                  v203 = ipa3_ctx;
                                }
                                v205 = *(_QWORD *)(v203 + 34160);
                                if ( v205 )
                                {
                                  ipc_log_string(v205, "ipa %s:%d failed to config uc\n", "ipa3_eth_connect", 1261);
                                  v203 = ipa3_ctx;
                                }
                              }
                              v206 = *(_DWORD *)(v203 + 32240);
                              if ( v206 >= 0x11 && v206 != 23 )
                              {
                                *(_BYTE *)(v203 + 14 * v237 + 2 * v134 + 45237) = -1;
                                *(_BYTE *)(ipa3_ctx + 14 * v237 + 2 * v134 + 45236) = *(_DWORD *)(a1 + 16);
                                ipa3_uc_debug_stats_alloc(
                                  *(_QWORD *)(ipa3_ctx + 45232 + 14 * v237),
                                  *(unsigned int *)(ipa3_ctx + 45232 + 14 * v237 + 8)
                                | ((unsigned __int64)*(unsigned __int16 *)(ipa3_ctx + 45232 + 14 * v237 + 12) << 32));
                              }
                              goto LABEL_319;
                            }
                          }
LABEL_357:
                          __break(0x5512u);
                        }
                        printk(&unk_3B7FAF, "ipa3_eth_connect");
                        v165 = ipa3_ctx;
                        if ( ipa3_ctx )
                        {
                          v166 = *(_QWORD *)(ipa3_ctx + 34152);
                          if ( v166 )
                          {
                            ipc_log_string(v166, "ipa %s:%d ioremap failed\n", "ipa3_eth_connect", 1178);
                            v165 = ipa3_ctx;
                          }
                          v167 = *(_QWORD *)(v165 + 34160);
                          if ( v167 )
                          {
                            ipc_log_string(v167, "ipa %s:%d ioremap failed\n", "ipa3_eth_connect", 1178);
                            goto LABEL_255;
                          }
                        }
                        goto LABEL_336;
                    }
LABEL_256:
                    v144 = -14;
                    goto LABEL_337;
                  }
                  if ( v11 )
                  {
                    if ( (_DWORD)v20 == 9 )
                    {
                      v65 = 1;
                      v64 = 20;
                    }
                    else
                    {
                      if ( (_DWORD)v20 != 1 )
                      {
LABEL_124:
                        if ( arm64_use_ng_mappings )
                          v105 = 0x68000000000F13LL;
                        else
                          v105 = 0x68000000000713LL;
                        v106 = ioremap_prot(v241, 4, v105);
                        if ( !v106 )
                        {
                          printk(&unk_3B7FAF, "ipa3_eth_connect");
                          v207 = ipa3_ctx;
                          if ( ipa3_ctx )
                          {
                            v208 = *(_QWORD *)(ipa3_ctx + 34152);
                            if ( v208 )
                            {
                              ipc_log_string(v208, "ipa %s:%d ioremap failed\n", "ipa3_eth_connect", 1135);
                              v207 = ipa3_ctx;
                            }
                            v209 = *(_QWORD *)(v207 + 34160);
                            if ( v209 )
                            {
                              ipc_log_string(v209, "ipa %s:%d ioremap failed\n", "ipa3_eth_connect", 1135);
                              goto LABEL_255;
                            }
                          }
                          goto LABEL_336;
                        }
                        v73 = v106;
                        v74 = *(unsigned int *)(v9 + 224);
                        goto LABEL_141;
                      }
                      v64 = 0;
                      v65 = 1668246893;
                    }
                    v102 = *v63;
                    reg_base = ipahal_get_reg_base();
                    v104 = reg_base
                         + ((__int64 (__fastcall *)(__int64, __int64, _QWORD))ipahal_get_reg_mn_ofst)(66, 1, v64);
                    v20 = v237;
                    *(_DWORD *)(a1 + 152) = v65;
                    *(_QWORD *)(a1 + 144) = (unsigned int)(v104 + v102);
                    goto LABEL_124;
                  }
                  if ( (_DWORD)v20 == 1 )
                  {
                    v70 = v241;
                    v69 = 0;
                  }
                  else
                  {
                    if ( (_DWORD)v20 != 9 )
                    {
LABEL_131:
                      if ( arm64_use_ng_mappings )
                        v107 = 0x68000000000F13LL;
                      else
                        v107 = 0x68000000000713LL;
                      v108 = ioremap_prot(v241, 4, v107);
                      if ( !v108 )
                      {
                        printk(&unk_3B7FAF, "ipa3_eth_connect");
                        v210 = ipa3_ctx;
                        if ( ipa3_ctx )
                        {
                          v211 = *(_QWORD *)(ipa3_ctx + 34152);
                          if ( v211 )
                          {
                            ipc_log_string(v211, "ipa %s:%d ioremap failed\n", "ipa3_eth_connect", 1159);
                            v210 = ipa3_ctx;
                          }
                          v212 = *(_QWORD *)(v210 + 34160);
                          if ( v212 )
                          {
                            ipc_log_string(v212, "ipa %s:%d ioremap failed\n", "ipa3_eth_connect", 1159);
                            goto LABEL_255;
                          }
                        }
                        goto LABEL_336;
                      }
                      v73 = v108;
                      v74 = (unsigned int)(*(_DWORD *)(v9 + 216) + *(_DWORD *)(v9 + 224));
                      goto LABEL_141;
                    }
                    v66 = *v63;
                    v67 = ipahal_get_reg_base();
                    v68 = ((__int64 (__fastcall *)(__int64, __int64, __int64))ipahal_get_reg_mn_ofst)(66, 1, 21);
                    v69 = 2;
                    v70 = v67 + v68 + v66;
                    v20 = v237;
                  }
                  *(_DWORD *)(a1 + 152) = v69;
                  *(_QWORD *)(a1 + 144) = v70;
                  goto LABEL_131;
                }
LABEL_250:
                printk(&unk_3C3E15, "ipa3_eth_connect");
                v182 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v183 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v183 )
                  {
                    ipc_log_string(v183, "ipa %s:%d fail to setup eth gsi rx channel\n", "ipa3_eth_connect", 1033);
                    v182 = ipa3_ctx;
                  }
                  v184 = *(_QWORD *)(v182 + 34160);
                  if ( v184 )
                  {
                    ipc_log_string(v184, "ipa %s:%d fail to setup eth gsi rx channel\n", "ipa3_eth_connect", 1033);
                    goto LABEL_255;
                  }
                  goto LABEL_336;
                }
                goto LABEL_256;
              }
              printk(&unk_3E0EF0, "ipa_eth_setup_rtk_gsi_channel");
              v185 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v20 = v237;
                v186 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v186 )
                {
                  ipc_log_string(v186, "ipa %s:%d fail to alloc RX event ring\n", "ipa_eth_setup_rtk_gsi_channel", 350);
                  v185 = ipa3_ctx;
                }
                v187 = *(_QWORD *)(v185 + 34160);
                if ( v187 )
                  ipc_log_string(v187, "ipa %s:%d fail to alloc RX event ring\n", "ipa_eth_setup_rtk_gsi_channel", 350);
LABEL_262:
                v33 = -14;
                goto LABEL_57;
              }
LABEL_350:
              v20 = v237;
              v33 = -14;
              goto LABEL_57;
            }
            v228 = printk(&unk_3D2A1F, "ipa_eth_setup_rtk_gsi_channel");
            v229 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v230 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v230 )
              {
                ipc_log_string(v230, "ipa %s:%d RTK transfer ring invalid\n", "ipa_eth_setup_rtk_gsi_channel", 320);
                v229 = ipa3_ctx;
              }
              v228 = *(_QWORD *)(v229 + 34160);
              if ( v228 )
                v228 = ipc_log_string(
                         v228,
                         "ipa %s:%d RTK transfer ring invalid\n",
                         "ipa_eth_setup_rtk_gsi_channel",
                         320);
            }
LABEL_349:
            ((void (__fastcall *)(__int64))ipa_assert)(v228);
            goto LABEL_350;
          default:
            printk(&unk_3B2232, "ipa3_eth_connect");
            v179 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v180 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v180 )
              {
                ipc_log_string(v180, "ipa %s:%d unknown protocol %d\n", "ipa3_eth_connect", 1029, v20);
                v179 = ipa3_ctx;
              }
              v181 = *(_QWORD *)(v179 + 34160);
              if ( v181 )
                ipc_log_string(v181, "ipa %s:%d unknown protocol %d\n", "ipa3_eth_connect", 1029, v20);
            }
            goto LABEL_250;
        }
        v33 = -22;
        goto LABEL_55;
      }
      v95 = v8;
      printk(&unk_3EF070, "ipa3_eth_connect");
      v141 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v142 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v142 )
        {
          ipc_log_string(v142, "ipa %s:%d failed to map SMMU %d\n", "ipa3_eth_connect", 973, v95);
          v141 = ipa3_ctx;
        }
        v143 = *(_QWORD *)(v141 + 34160);
        if ( v143 )
        {
          ipc_log_string(v143, "ipa %s:%d failed to map SMMU %d\n", "ipa3_eth_connect", 973, v95);
          result = v95;
          goto LABEL_338;
        }
      }
LABEL_183:
      result = v95;
      goto LABEL_338;
    }
    v95 = prot;
    printk(&unk_3D5926, "ipa3_eth_connect");
    v99 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_183;
    v100 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v100 )
    {
      ipc_log_string(v100, "ipa %s:%d Could not determine protocol\n", "ipa3_eth_connect", 967);
      v99 = ipa3_ctx;
    }
    v101 = *(_QWORD *)(v99 + 34160);
    if ( !v101 )
      goto LABEL_183;
    ipc_log_string(v101, "ipa %s:%d Could not determine protocol\n", "ipa3_eth_connect", 967);
  }
  result = v95;
LABEL_338:
  _ReadStatusReg(SP_EL0);
  return result;
}
