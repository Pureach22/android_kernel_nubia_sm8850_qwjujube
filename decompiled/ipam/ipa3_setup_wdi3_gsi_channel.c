__int64 __fastcall ipa3_setup_wdi3_gsi_channel(char a1, __int64 a2, __int64 a3, unsigned int a4, __int64 a5)
{
  int v10; // w0
  long double v11; // q0
  long double v12; // q1
  long double v13; // q2
  long double v14; // q3
  float v15; // s4
  __int64 v16; // x8
  int v17; // w10
  unsigned int v18; // w9
  bool v19; // cf
  unsigned int v20; // w9
  _DWORD *v21; // x9
  int v22; // w9
  int v23; // w24
  unsigned int v24; // w0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  unsigned __int64 v28; // x10
  __int64 v29; // x2
  __int64 v30; // x3
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x1
  unsigned __int64 v38; // x9
  int v39; // w8
  __int64 v40; // x0
  __int64 v41; // x0
  long double v42; // q0
  long double v43; // q1
  long double v44; // q2
  long double v45; // q3
  float v46; // s4
  __int64 v47; // x8
  char v48; // w9
  unsigned int *v49; // x24
  unsigned int v50; // w10
  int v51; // w9
  char v52; // w10
  int v53; // w27
  unsigned int v54; // w0
  __int64 v55; // x8
  __int64 v56; // x0
  __int64 v57; // x0
  unsigned __int64 v58; // x10
  __int64 v59; // x8
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x2
  __int64 v63; // x3
  __int64 v64; // x8
  __int64 v65; // x0
  __int64 v66; // x0
  int v67; // w0
  unsigned int v68; // w21
  __int64 result; // x0
  unsigned __int64 v70; // x9
  __int64 v71; // x0
  int v72; // w0
  long double v73; // q0
  long double v74; // q1
  long double v75; // q2
  long double v76; // q3
  float v77; // s4
  __int64 v78; // x8
  __int64 v79; // x0
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v82; // x0
  __int64 v83; // x0
  __int64 v84; // x0
  __int64 v85; // x0
  __int64 v86; // x8
  __int64 v87; // x0
  __int64 v88; // x0
  unsigned int v89; // w0
  unsigned __int64 *v90; // x27
  __int64 v91; // x8
  __int64 v92; // x0
  __int64 v93; // x0
  __int64 v94; // x8
  __int64 v95; // x0
  __int64 v96; // x0
  __int64 v97; // x8
  __int64 v98; // x0
  __int64 v99; // x0
  __int64 v100; // x8
  __int64 v101; // x0
  __int64 v102; // x0
  __int64 v103; // x0
  __int64 v104; // x8
  __int64 v105; // x0
  __int64 v106; // x0
  unsigned __int64 v107; // x1
  int v108; // w8
  int v109; // w8
  unsigned __int64 v110; // x2
  unsigned int v111; // w9
  bool v112; // zf
  __int64 v113; // x8
  __int64 v114; // x0
  __int64 v115; // x0
  __int64 gsi_smmu_mapping; // x0
  long double v117; // q0
  long double v118; // q1
  long double v119; // q2
  long double v120; // q3
  float v121; // s4
  __int64 v122; // x27
  unsigned __int16 *v123; // x8
  __int64 v124; // x28
  __int64 v125; // x0
  __int64 v126; // x0
  __int64 v127; // x8
  __int64 v128; // x0
  __int64 v129; // x8
  __int64 v130; // x0
  __int64 v131; // x0
  unsigned int v132; // w0
  __int64 v133; // x8
  __int64 v134; // x0
  __int64 v135; // x0
  __int64 v136; // x2
  __int64 v137; // x8
  __int64 v138; // x0
  __int64 v139; // x0
  __int64 v140; // x0
  unsigned __int64 v141; // x24
  unsigned __int64 v142; // x26
  __int64 v143; // x2
  __int64 v144; // x8
  __int64 v145; // x0
  __int64 v146; // x0
  __int64 v147; // x8
  __int64 v148; // x0
  __int64 v149; // x0
  __int64 v150; // x8
  __int64 v151; // x0
  __int64 v152; // x0
  __int64 v153; // x3
  __int64 v154; // x8
  __int64 v155; // x0
  __int64 v156; // x0
  __int64 v157; // x0
  int v158; // w21
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
  __int64 v174; // x8
  __int64 v175; // x0
  __int64 v176; // x0
  _DWORD v177[2]; // [xsp+8h] [xbp-128h] BYREF
  __int64 v178; // [xsp+10h] [xbp-120h]
  __int64 v179; // [xsp+18h] [xbp-118h]
  unsigned __int64 v180; // [xsp+20h] [xbp-110h] BYREF
  __int64 v181; // [xsp+28h] [xbp-108h] BYREF
  __int64 v182; // [xsp+30h] [xbp-100h]
  __int64 v183; // [xsp+38h] [xbp-F8h]
  __int64 v184; // [xsp+40h] [xbp-F0h]
  __int64 v185; // [xsp+48h] [xbp-E8h]
  unsigned __int64 v186; // [xsp+50h] [xbp-E0h]
  __int64 v187; // [xsp+58h] [xbp-D8h]
  __int64 v188; // [xsp+60h] [xbp-D0h]
  __int64 v189; // [xsp+68h] [xbp-C8h]
  __int64 v190; // [xsp+70h] [xbp-C0h]
  __int64 v191; // [xsp+78h] [xbp-B8h]
  __int64 v192; // [xsp+80h] [xbp-B0h]
  __int64 (__fastcall *v193)(); // [xsp+88h] [xbp-A8h]
  __int64 v194; // [xsp+90h] [xbp-A0h]
  __int64 v195; // [xsp+98h] [xbp-98h]
  __int64 v196; // [xsp+A0h] [xbp-90h] BYREF
  __int64 v197; // [xsp+A8h] [xbp-88h]
  unsigned __int64 v198; // [xsp+B0h] [xbp-80h]
  __int64 v199; // [xsp+B8h] [xbp-78h]
  __int64 v200; // [xsp+C0h] [xbp-70h]
  __int64 v201; // [xsp+C8h] [xbp-68h]
  __int64 v202; // [xsp+D0h] [xbp-60h]
  __int64 v203; // [xsp+D8h] [xbp-58h]
  __int64 v204; // [xsp+E0h] [xbp-50h]
  __int64 v205; // [xsp+E8h] [xbp-48h]
  __int64 v206; // [xsp+F0h] [xbp-40h]
  __int64 v207; // [xsp+F8h] [xbp-38h]
  __int64 (__fastcall *v208)(); // [xsp+100h] [xbp-30h]
  __int64 v209; // [xsp+108h] [xbp-28h]
  __int64 v210; // [xsp+110h] [xbp-20h]
  __int64 v211; // [xsp+118h] [xbp-18h]
  __int64 v212; // [xsp+120h] [xbp-10h]

  v212 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v210 = 0;
  v211 = 0;
  v208 = nullptr;
  v209 = 0;
  v206 = 0;
  v207 = 0;
  v204 = 0;
  v205 = 0;
  v202 = 0;
  v203 = 0;
  v200 = 0;
  v201 = 0;
  v198 = 0;
  v199 = 0;
  v196 = 0;
  v197 = 0;
  v194 = 0;
  v195 = 0;
  v192 = 0;
  v193 = nullptr;
  v190 = 0;
  v191 = 0;
  v188 = 0;
  v189 = 0;
  v186 = 0;
  v187 = 0;
  v184 = 0;
  v185 = 0;
  v182 = 0;
  v183 = 0;
  v180 = 0;
  v181 = 0;
  if ( a2 && a3 && a5 )
  {
    v210 = 0;
    v211 = 0;
    v208 = nullptr;
    v209 = 0;
    v206 = 0;
    v207 = 0;
    v204 = 0;
    v205 = 0;
    v202 = 0;
    v203 = 0;
    v200 = 0;
    v201 = 0;
    v198 = 0;
    v199 = 0;
    v196 = 0;
    v197 = 0;
    v181 = 0;
    v182 = 0;
    v183 = 0;
    v184 = 0;
    v185 = 0;
    v186 = 0;
    v187 = 0;
    v188 = 0;
    v189 = 0;
    v190 = 0;
    v191 = 0;
    v192 = 0;
    v193 = nullptr;
    v194 = 0;
    v195 = 0;
    v10 = ((__int64 (*)(void))ipa_get_wdi_version)();
    v16 = ipa3_ctx;
    if ( v10 == 3 )
      v17 = 15;
    else
      v17 = 6;
    v18 = *(_DWORD *)(ipa3_ctx + 32240);
    LODWORD(v181) = v17;
    LODWORD(v196) = v17;
    v19 = v18 >= 0x13;
    v20 = (unsigned __int8)(a4 - 1);
    if ( v19 )
    {
      HIDWORD(v196) = 0;
      if ( v20 < 4 )
      {
        v21 = &unk_401828;
LABEL_13:
        v22 = v21[(char)(a4 - 1)];
        goto LABEL_15;
      }
    }
    else
    {
      HIDWORD(v196) = 1;
      if ( v20 <= 3 )
      {
        v21 = &unk_401838;
        goto LABEL_13;
      }
    }
    v22 = 8;
LABEL_15:
    LODWORD(v197) = v22;
    if ( a1 )
    {
      v23 = *(_DWORD *)(a3 + 256);
      if ( (unsigned __int8)(a4 - 1) > 1u )
      {
        v29 = *(_QWORD *)(a2 + 232);
        v30 = a3 + 240;
        if ( (unsigned __int8)a4 == 3 )
        {
          if ( (unsigned int)ipa_create_gsi_smmu_mapping(
                               2u,
                               1,
                               v29,
                               v30,
                               v23,
                               v11,
                               v12,
                               v13,
                               v14,
                               v15,
                               0,
                               (__int64 *)&v180) )
          {
            printk(&unk_3C4BDE, "ipa3_setup_wdi3_gsi_channel");
            v34 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v35 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v35 )
              {
                ipc_log_string(v35, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 150);
                v34 = ipa3_ctx;
              }
              v36 = *(_QWORD *)(v34 + 34160);
              if ( v36 )
              {
                ipc_log_string(v36, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 150);
                goto LABEL_289;
              }
            }
            goto LABEL_290;
          }
        }
        else if ( (unsigned __int8)a4 == 4 )
        {
          if ( (unsigned int)ipa_create_gsi_smmu_mapping(
                               0x11u,
                               1,
                               v29,
                               v30,
                               v23,
                               v11,
                               v12,
                               v13,
                               v14,
                               v15,
                               0,
                               (__int64 *)&v180) )
          {
            printk(&unk_3C4BDE, "ipa3_setup_wdi3_gsi_channel");
            v31 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v32 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v32 )
              {
                ipc_log_string(v32, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 141);
                v31 = ipa3_ctx;
              }
              v33 = *(_QWORD *)(v31 + 34160);
              if ( v33 )
              {
                ipc_log_string(v33, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 141);
                goto LABEL_289;
              }
            }
LABEL_290:
            result = 4294967282LL;
            goto LABEL_272;
          }
        }
        else if ( (unsigned int)ipa_create_gsi_smmu_mapping(
                                  6u,
                                  1,
                                  v29,
                                  v30,
                                  v23,
                                  v11,
                                  v12,
                                  v13,
                                  v14,
                                  v15,
                                  0,
                                  (__int64 *)&v180) )
        {
          printk(&unk_3C4BDE, "ipa3_setup_wdi3_gsi_channel");
          v165 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v166 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v166 )
            {
              ipc_log_string(v166, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 159);
              v165 = ipa3_ctx;
            }
            v167 = *(_QWORD *)(v165 + 34160);
            if ( v167 )
            {
              ipc_log_string(v167, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 159);
              goto LABEL_289;
            }
          }
          goto LABEL_290;
        }
      }
      else
      {
        if ( (unsigned __int8)a4 == 1 )
          v24 = 9;
        else
          v24 = 13;
        if ( (unsigned int)ipa_create_gsi_smmu_mapping(
                             v24,
                             1,
                             *(_QWORD *)(a2 + 232),
                             a3 + 240,
                             v23,
                             v11,
                             v12,
                             v13,
                             v14,
                             v15,
                             0,
                             (__int64 *)&v180) )
        {
          printk(&unk_3C4BDE, "ipa3_setup_wdi3_gsi_channel");
          v25 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v26 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v26 )
            {
              ipc_log_string(v26, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 132);
              v25 = ipa3_ctx;
            }
            v27 = *(_QWORD *)(v25 + 34160);
            if ( v27 )
            {
              ipc_log_string(v27, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 132);
LABEL_289:
              result = 4294967282LL;
              goto LABEL_272;
            }
          }
          goto LABEL_290;
        }
      }
      v16 = ipa3_ctx;
      HIDWORD(v197) = v23;
      v198 = v180;
    }
    else
    {
      v28 = *(_QWORD *)(a2 + 232);
      HIDWORD(v197) = *(_DWORD *)(a2 + 240);
      v198 = v28;
    }
    BYTE2(v200) = 1;
    LOBYTE(v207) = 1;
    v37 = *(_QWORD *)(v16 + 43296);
    LOWORD(v200) = 32;
    v208 = ipa3_wdi3_gsi_evt_ring_err_cb;
    v209 = 0;
    if ( (unsigned int)gsi_alloc_evt_ring(&v196, v37, a5 + 16) )
    {
      printk(&unk_3E0EF0, "ipa3_setup_wdi3_gsi_channel");
      v100 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_243;
      v101 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v101 )
      {
        ipc_log_string(v101, "ipa %s:%d fail to alloc RX event ring\n", "ipa3_setup_wdi3_gsi_channel", 175);
        v100 = ipa3_ctx;
      }
      v102 = *(_QWORD *)(v100 + 34160);
      if ( v102 )
      {
        ipc_log_string(v102, "ipa %s:%d fail to alloc RX event ring\n", "ipa3_setup_wdi3_gsi_channel", 175);
        v68 = -14;
      }
      else
      {
LABEL_243:
        v68 = -14;
      }
      goto LABEL_85;
    }
    v38 = v198;
    *(_DWORD *)(a5 + 24) = HIDWORD(v197);
    *(_QWORD *)(a5 + 32) = v38;
    if ( (unsigned __int8)(a4 - 1) > 3u )
      v39 = 1;
    else
      v39 = dword_401818[(unsigned __int8)(a4 - 1)];
    v40 = *(unsigned int *)(a5 + 4);
    HIDWORD(v181) = v39;
    v41 = ((__int64 (__fastcall *)(__int64))ipa_get_gsi_ep_info)(v40);
    if ( !v41 )
    {
      printk(&unk_3CC819, "ipa3_setup_wdi3_gsi_channel");
      v113 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_244;
      v114 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v114 )
      {
        ipc_log_string(
          v114,
          "ipa %s:%d Failed getting GSI EP info for client=%d\n",
          "ipa3_setup_wdi3_gsi_channel",
          194,
          *(_DWORD *)(a5 + 4));
        v113 = ipa3_ctx;
      }
      v115 = *(_QWORD *)(v113 + 34160);
      if ( v115 )
      {
        ipc_log_string(
          v115,
          "ipa %s:%d Failed getting GSI EP info for client=%d\n",
          "ipa3_setup_wdi3_gsi_channel",
          194,
          *(_DWORD *)(a5 + 4));
        v67 = -22;
      }
      else
      {
LABEL_244:
        v67 = -22;
      }
      goto LABEL_84;
    }
    v47 = ipa3_ctx;
    v48 = *(_DWORD *)(v41 + 4);
    v49 = (unsigned int *)v41;
    LOBYTE(v187) = 0;
    v50 = *(_DWORD *)(ipa3_ctx + 32240);
    LOBYTE(v182) = v48;
    v183 = *(_QWORD *)(a5 + 16);
    if ( v50 < 0x13 )
    {
      v51 = 16;
    }
    else if ( (unsigned __int8)a4 <= 4u && ((1 << a4) & 0x16) != 0 || (_DWORD)v181 == 15 )
    {
      v51 = 32;
    }
    else
    {
      v51 = 64;
    }
    LODWORD(v184) = v51;
    v189 = 1;
    HIDWORD(v190) = *(_DWORD *)(v41 + 20);
    v52 = *(_BYTE *)(v41 + 24);
    LOBYTE(v190) = 1;
    LOBYTE(v191) = v52;
    v193 = ipa3_wdi3_gsi_chan_err_cb;
    if ( a1 )
    {
      v53 = *(_DWORD *)(a3 + 216);
      if ( (unsigned __int8)(a4 - 1) > 1u )
      {
        if ( (unsigned __int8)a4 == 4 )
        {
          if ( (unsigned int)ipa_create_gsi_smmu_mapping(
                               0x10u,
                               1,
                               *(_QWORD *)(a2 + 200),
                               a3 + 200,
                               v53,
                               v42,
                               v43,
                               v44,
                               v45,
                               v46,
                               0,
                               (__int64 *)&v180) )
          {
            printk(&unk_3C4BDE, "ipa3_setup_wdi3_gsi_channel");
            v59 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v60 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v60 )
              {
                ipc_log_string(v60, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 250);
                v59 = ipa3_ctx;
              }
              v61 = *(_QWORD *)(v59 + 34160);
              if ( v61 )
              {
                ipc_log_string(v61, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 250);
                goto LABEL_296;
              }
            }
LABEL_297:
            v67 = -14;
            goto LABEL_84;
          }
        }
        else
        {
          v62 = *(_QWORD *)(a2 + 200);
          v63 = a3 + 200;
          if ( (unsigned __int8)a4 == 3 )
          {
            if ( (unsigned int)ipa_create_gsi_smmu_mapping(
                                 0,
                                 1,
                                 v62,
                                 v63,
                                 v53,
                                 v42,
                                 v43,
                                 v44,
                                 v45,
                                 v46,
                                 0,
                                 (__int64 *)&v180) )
            {
              printk(&unk_3C4BDE, "ipa3_setup_wdi3_gsi_channel");
              v64 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v65 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v65 )
                {
                  ipc_log_string(v65, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 260);
                  v64 = ipa3_ctx;
                }
                v66 = *(_QWORD *)(v64 + 34160);
                if ( v66 )
                {
                  ipc_log_string(v66, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 260);
                  goto LABEL_296;
                }
              }
              goto LABEL_297;
            }
          }
          else if ( (unsigned int)ipa_create_gsi_smmu_mapping(
                                    4u,
                                    1,
                                    v62,
                                    v63,
                                    v53,
                                    v42,
                                    v43,
                                    v44,
                                    v45,
                                    v46,
                                    0,
                                    (__int64 *)&v180) )
          {
            printk(&unk_3C4BDE, "ipa3_setup_wdi3_gsi_channel");
            v168 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v169 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v169 )
              {
                ipc_log_string(v169, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 270);
                v168 = ipa3_ctx;
              }
              v170 = *(_QWORD *)(v168 + 34160);
              if ( v170 )
              {
                ipc_log_string(v170, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 270);
                goto LABEL_296;
              }
            }
            goto LABEL_297;
          }
        }
      }
      else
      {
        if ( (unsigned __int8)a4 == 1 )
          v54 = 8;
        else
          v54 = 12;
        if ( (unsigned int)ipa_create_gsi_smmu_mapping(
                             v54,
                             1,
                             *(_QWORD *)(a2 + 200),
                             a3 + 200,
                             v53,
                             v42,
                             v43,
                             v44,
                             v45,
                             v46,
                             0,
                             (__int64 *)&v180) )
        {
          printk(&unk_3C4BDE, "ipa3_setup_wdi3_gsi_channel");
          v55 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v56 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v56 )
            {
              ipc_log_string(v56, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 240);
              v55 = ipa3_ctx;
            }
            v57 = *(_QWORD *)(v55 + 34160);
            if ( v57 )
            {
              ipc_log_string(v57, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 240);
LABEL_296:
              v67 = -14;
              goto LABEL_84;
            }
          }
          goto LABEL_297;
        }
      }
      v47 = ipa3_ctx;
      HIDWORD(v184) = v53;
      v186 = v180;
    }
    else
    {
      v58 = *(_QWORD *)(a2 + 200);
      HIDWORD(v184) = *(unsigned __int16 *)(a2 + 208);
      v186 = v58;
    }
    v67 = gsi_alloc_channel(&v181, *(_QWORD *)(v47 + 43296), a5 + 8);
    if ( v67 )
    {
LABEL_84:
      v68 = v67;
      gsi_dealloc_evt_ring(*(_QWORD *)(a5 + 16));
      *(_QWORD *)(a5 + 16) = -1;
LABEL_85:
      ((void (__fastcall *)(_QWORD))ipa3_release_wdi3_gsi_smmu_mappings)(a4);
      result = v68;
      goto LABEL_272;
    }
    v70 = v186;
    v71 = *(_QWORD *)(a5 + 16);
    *(_DWORD *)(a5 + 48) = HIDWORD(v184);
    *(_QWORD *)(a5 + 56) = v70;
    v72 = gsi_write_evt_ring_scratch(v71, 1);
    if ( v72 )
    {
      v158 = v72;
      printk(&unk_3D2A46, "ipa3_setup_wdi3_gsi_channel");
      v159 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v160 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v160 )
        {
          ipc_log_string(v160, "ipa %s:%d failed to write evt ring scratch\n", "ipa3_setup_wdi3_gsi_channel", 294);
          v159 = ipa3_ctx;
        }
        v161 = *(_QWORD *)(v159 + 34160);
        if ( v161 )
          ipc_log_string(v161, "ipa %s:%d failed to write evt ring scratch\n", "ipa3_setup_wdi3_gsi_channel", 294);
      }
      goto LABEL_311;
    }
    v78 = ipa3_ctx;
    if ( a1 )
    {
      if ( ipa3_ctx )
      {
        v79 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v79 )
        {
          ipc_log_string(v79, "ipa %s:%d smmu enabled\n", "ipa3_setup_wdi3_gsi_channel", 309);
          v78 = ipa3_ctx;
        }
        v80 = *(_QWORD *)(v78 + 34160);
        if ( v80 )
          ipc_log_string(v80, "ipa %s:%d smmu enabled\n", "ipa3_setup_wdi3_gsi_channel", 309);
      }
      if ( *(_BYTE *)(a3 + 272) == 1 )
      {
        if ( !ipa3_ctx )
          goto LABEL_114;
        v81 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( v81 )
          ipc_log_string(v81, "ipa %s:%d is_evt_rn_db_pcie_addr is PCIE addr\n", "ipa3_setup_wdi3_gsi_channel", 311);
      }
      else
      {
        if ( !ipa3_ctx )
          goto LABEL_114;
        v85 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( v85 )
          ipc_log_string(v85, "ipa %s:%d is_evt_rn_db_pcie_addr is DDR addr\n", "ipa3_setup_wdi3_gsi_channel", 313);
      }
      v86 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v87 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( !v87
          || (ipc_log_string(v87, "ipa %s:%d LSB 0x%x\n", "ipa3_setup_wdi3_gsi_channel", 315, *(_DWORD *)(a3 + 264)),
              (v86 = ipa3_ctx) != 0) )
        {
          v88 = *(_QWORD *)(v86 + 34160);
          if ( v88 )
            ipc_log_string(v88, "ipa %s:%d MSB 0x%x\n", "ipa3_setup_wdi3_gsi_channel", 317, *(_DWORD *)(a3 + 268));
        }
      }
LABEL_114:
      if ( (unsigned __int8)(a4 - 1) > 1u )
      {
        if ( (unsigned __int8)a4 == 4 )
        {
          v90 = &v180;
          if ( (unsigned int)ipa_create_gsi_smmu_mapping(
                               0x12u,
                               1,
                               *(_QWORD *)(a3 + 264),
                               0,
                               4,
                               v73,
                               v74,
                               v75,
                               v76,
                               v77,
                               1,
                               (__int64 *)&v180) )
          {
            printk(&unk_3C4BDE, "ipa3_setup_wdi3_gsi_channel");
            v94 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v95 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v95 )
              {
                ipc_log_string(v95, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 339);
                v94 = ipa3_ctx;
              }
              v96 = *(_QWORD *)(v94 + 34160);
              if ( v96 )
                ipc_log_string(v96, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 339);
            }
            goto LABEL_310;
          }
        }
        else
        {
          v143 = *(_QWORD *)(a3 + 264);
          if ( (unsigned __int8)a4 == 3 )
          {
            v90 = &v180;
            if ( (unsigned int)ipa_create_gsi_smmu_mapping(
                                 3u,
                                 1,
                                 v143,
                                 0,
                                 4,
                                 v73,
                                 v74,
                                 v75,
                                 v76,
                                 v77,
                                 1,
                                 (__int64 *)&v180) )
            {
              printk(&unk_3C4BDE, "ipa3_setup_wdi3_gsi_channel");
              v144 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v145 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v145 )
                {
                  ipc_log_string(v145, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 348);
                  v144 = ipa3_ctx;
                }
                v146 = *(_QWORD *)(v144 + 34160);
                if ( v146 )
                  ipc_log_string(v146, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 348);
              }
              goto LABEL_310;
            }
          }
          else
          {
            v90 = &v180;
            if ( (unsigned int)ipa_create_gsi_smmu_mapping(
                                 7u,
                                 1,
                                 v143,
                                 0,
                                 4,
                                 v73,
                                 v74,
                                 v75,
                                 v76,
                                 v77,
                                 1,
                                 (__int64 *)&v180) )
            {
              printk(&unk_3C4BDE, "ipa3_setup_wdi3_gsi_channel");
              v150 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v151 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v151 )
                {
                  ipc_log_string(v151, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 357);
                  v150 = ipa3_ctx;
                }
                v152 = *(_QWORD *)(v150 + 34160);
                if ( v152 )
                  ipc_log_string(v152, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 357);
              }
              goto LABEL_310;
            }
          }
        }
      }
      else
      {
        if ( (unsigned __int8)a4 == 1 )
          v89 = 10;
        else
          v89 = 14;
        v90 = &v180;
        if ( (unsigned int)ipa_create_gsi_smmu_mapping(
                             v89,
                             1,
                             *(_QWORD *)(a3 + 264),
                             0,
                             4,
                             v73,
                             v74,
                             v75,
                             v76,
                             v77,
                             1,
                             (__int64 *)&v180) )
        {
          printk(&unk_3C4BDE, "ipa3_setup_wdi3_gsi_channel");
          v91 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v92 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v92 )
            {
              ipc_log_string(v92, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 330);
              v91 = ipa3_ctx;
            }
            v93 = *(_QWORD *)(v91 + 34160);
            if ( v93 )
              ipc_log_string(v93, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 330);
          }
LABEL_310:
          v158 = -14;
          goto LABEL_311;
        }
      }
LABEL_150:
      v107 = *v90;
      v108 = *(_DWORD *)(ipa3_ctx + 32256);
      if ( a1 && !v108 )
      {
        v109 = *(unsigned __int8 *)(a3 + 272);
        if ( v109 == 1 )
          v107 = *(_QWORD *)(a3 + 264);
        v110 = HIDWORD(v107);
        goto LABEL_155;
      }
      v110 = HIDWORD(v107);
      if ( a1 )
      {
        if ( !v108 )
        {
          LOBYTE(v109) = *(_BYTE *)(a3 + 272);
LABEL_155:
          v111 = v110 | 0x100;
          v112 = (v109 & 1) == 0;
          goto LABEL_156;
        }
      }
      else if ( !v108 )
      {
        v111 = HIDWORD(v107) | 0x100;
        v112 = *(_BYTE *)(a2 + 256) == 0;
LABEL_156:
        if ( v112 )
          v110 = (unsigned int)v110;
        else
          v110 = v111;
      }
      gsi_smmu_mapping = gsi_wdi3_write_evt_ring_db(*(_QWORD *)(a5 + 16), v107, v110);
      if ( *(_BYTE *)(ipa3_ctx + 32267) )
        v122 = 1;
      else
        v122 = 8;
      if ( (unsigned __int8)a4 == 5 || (unsigned __int8)a4 == 3 )
      {
        v123 = (unsigned __int16 *)(a3 + 276);
        if ( !a1 )
          v123 = (unsigned __int16 *)(a2 + 260);
        v124 = *v123;
        gsi_smmu_mapping = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(60, 0, *v49);
        v122 |= ((_DWORD)gsi_smmu_mapping << 14) & 0xFFFF0000 | (unsigned __int64)(v124 << 32);
      }
      if ( a1 )
      {
        if ( ipa3_ctx )
        {
          v125 = *(_QWORD *)(ipa3_ctx + 34160);
          if ( v125 )
            ipc_log_string(v125, "ipa %s:%d smmu eabled\n", "ipa3_setup_wdi3_gsi_channel", 435);
        }
        if ( *(_BYTE *)(a3 + 232) == 1 )
        {
          if ( ipa3_ctx )
          {
            v126 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v126 )
              ipc_log_string(
                v126,
                "ipa %s:%d is_txr_rn_db_pcie_addr is PCIE addr\n",
                "ipa3_setup_wdi3_gsi_channel",
                437);
LABEL_194:
            v129 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v130 = *(_QWORD *)(ipa3_ctx + 34160);
              if ( !v130
                || (ipc_log_string(
                      v130,
                      "ipa %s:%d LSB 0x%x\n",
                      "ipa3_setup_wdi3_gsi_channel",
                      441,
                      *(_DWORD *)(a3 + 224)),
                    (v129 = ipa3_ctx) != 0) )
              {
                v131 = *(_QWORD *)(v129 + 34160);
                if ( v131 )
                  ipc_log_string(
                    v131,
                    "ipa %s:%d MSB 0x%x\n",
                    "ipa3_setup_wdi3_gsi_channel",
                    443,
                    *(_DWORD *)(a3 + 228));
              }
            }
          }
        }
        else if ( ipa3_ctx )
        {
          v128 = *(_QWORD *)(ipa3_ctx + 34160);
          if ( v128 )
            ipc_log_string(v128, "ipa %s:%d is_txr_rn_db_pcie_addr is DDR addr\n", "ipa3_setup_wdi3_gsi_channel", 439);
          goto LABEL_194;
        }
        if ( (unsigned __int8)(a4 - 1) > 1u )
        {
          v136 = *(_QWORD *)(a3 + 224);
          if ( (unsigned __int8)a4 == 4 )
          {
            gsi_smmu_mapping = ipa_create_gsi_smmu_mapping(
                                 0x13u,
                                 1,
                                 v136,
                                 0,
                                 4,
                                 v117,
                                 v118,
                                 v119,
                                 v120,
                                 v121,
                                 1,
                                 (__int64 *)&v180);
            if ( (_DWORD)gsi_smmu_mapping )
            {
              printk(&unk_3C4BDE, "ipa3_setup_wdi3_gsi_channel");
              v137 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v138 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v138 )
                {
                  ipc_log_string(v138, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 470);
                  v137 = ipa3_ctx;
                }
                v139 = *(_QWORD *)(v137 + 34160);
                if ( v139 )
                  ipc_log_string(v139, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 470);
              }
              goto LABEL_310;
            }
          }
          else if ( (unsigned __int8)a4 == 3 )
          {
            gsi_smmu_mapping = ipa_create_gsi_smmu_mapping(
                                 1u,
                                 1,
                                 v136,
                                 0,
                                 4,
                                 v117,
                                 v118,
                                 v119,
                                 v120,
                                 v121,
                                 1,
                                 (__int64 *)&v180);
            if ( (_DWORD)gsi_smmu_mapping )
            {
              printk(&unk_3C4BDE, "ipa3_setup_wdi3_gsi_channel");
              v147 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v148 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v148 )
                {
                  ipc_log_string(v148, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 481);
                  v147 = ipa3_ctx;
                }
                v149 = *(_QWORD *)(v147 + 34160);
                if ( v149 )
                  ipc_log_string(v149, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 481);
              }
              goto LABEL_310;
            }
          }
          else
          {
            gsi_smmu_mapping = ipa_create_gsi_smmu_mapping(
                                 5u,
                                 1,
                                 v136,
                                 0,
                                 4,
                                 v117,
                                 v118,
                                 v119,
                                 v120,
                                 v121,
                                 1,
                                 (__int64 *)&v180);
            if ( (_DWORD)gsi_smmu_mapping )
            {
              printk(&unk_3C4BDE, "ipa3_setup_wdi3_gsi_channel");
              v174 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v175 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v175 )
                {
                  ipc_log_string(v175, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 492);
                  v174 = ipa3_ctx;
                }
                v176 = *(_QWORD *)(v174 + 34160);
                if ( v176 )
                  ipc_log_string(v176, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 492);
              }
              goto LABEL_310;
            }
          }
        }
        else
        {
          if ( (unsigned __int8)a4 == 1 )
            v132 = 11;
          else
            v132 = 15;
          gsi_smmu_mapping = ipa_create_gsi_smmu_mapping(
                               v132,
                               1,
                               *(_QWORD *)(a3 + 224),
                               0,
                               4,
                               v117,
                               v118,
                               v119,
                               v120,
                               v121,
                               1,
                               (__int64 *)&v180);
          if ( (_DWORD)gsi_smmu_mapping )
          {
            printk(&unk_3C4BDE, "ipa3_setup_wdi3_gsi_channel");
            v133 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v134 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v134 )
              {
                ipc_log_string(v134, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 458);
                v133 = ipa3_ctx;
              }
              v135 = *(_QWORD *)(v133 + 34160);
              if ( v135 )
                ipc_log_string(v135, "ipa %s:%d failed to get smmu mapping\n", "ipa3_setup_wdi3_gsi_channel", 458);
            }
            goto LABEL_310;
          }
        }
        v141 = v180;
        if ( *(_DWORD *)(ipa3_ctx + 32256) )
        {
          v142 = HIDWORD(v180);
        }
        else
        {
          if ( *(_BYTE *)(a3 + 232) == 1 )
            v141 = *(_QWORD *)(a3 + 224);
          if ( *(_BYTE *)(a3 + 232) )
            LODWORD(v142) = HIDWORD(v141) | 0x100;
          else
            LODWORD(v142) = HIDWORD(v141);
        }
LABEL_259:
        if ( (unsigned int)ipa_get_wdi_version(gsi_smmu_mapping) == 3 )
        {
          if ( (unsigned __int8)a4 != 3 )
          {
            if ( a1 )
            {
              v153 = *(unsigned __int8 *)(a3 + 408);
              if ( (unsigned int)v153 >= 0x40 )
              {
                printk(&unk_3A7ADC, "ipa3_setup_wdi3_gsi_channel");
                v154 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v155 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v155 )
                  {
                    ipc_log_string(
                      v155,
                      "ipa %s:%d Incorrect bank id value %d Exceeding the 6bit range\n",
                      "ipa3_setup_wdi3_gsi_channel",
                      566,
                      *(unsigned __int8 *)(a3 + 408));
                    v154 = ipa3_ctx;
                  }
                  v156 = *(_QWORD *)(v154 + 34160);
                  if ( v156 )
                  {
                    ipc_log_string(
                      v156,
                      "ipa %s:%d Incorrect bank id value %d Exceeding the 6bit range\n",
                      "ipa3_setup_wdi3_gsi_channel",
                      566,
                      *(unsigned __int8 *)(a3 + 408));
LABEL_303:
                    v158 = 0;
LABEL_311:
                    gsi_dealloc_channel(*(_QWORD *)(a5 + 8));
                    v67 = v158;
                    *(_QWORD *)(a5 + 8) = -1;
                    goto LABEL_84;
                  }
                }
                goto LABEL_304;
              }
            }
            else
            {
              v153 = *(unsigned __int8 *)(a2 + 392);
              if ( (unsigned int)v153 >= 0x40 )
              {
                printk(&unk_3A7ADC, "ipa3_setup_wdi3_gsi_channel");
                v171 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v172 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v172 )
                  {
                    ipc_log_string(
                      v172,
                      "ipa %s:%d Incorrect bank id value %d Exceeding the 6bit range\n",
                      "ipa3_setup_wdi3_gsi_channel",
                      573,
                      *(unsigned __int8 *)(a2 + 392));
                    v171 = ipa3_ctx;
                  }
                  v173 = *(_QWORD *)(v171 + 34160);
                  if ( v173 )
                  {
                    ipc_log_string(
                      v173,
                      "ipa %s:%d Incorrect bank id value %d Exceeding the 6bit range\n",
                      "ipa3_setup_wdi3_gsi_channel",
                      573,
                      *(unsigned __int8 *)(a2 + 392));
                    goto LABEL_303;
                  }
                }
LABEL_304:
                v158 = 0;
                goto LABEL_311;
              }
            }
            v122 |= v153 << 54;
          }
          v122 &= 0x3FC0FFFFFFFF001FuLL;
        }
        v157 = *(_QWORD *)(a5 + 8);
        v177[0] = v141;
        v177[1] = v142;
        v178 = v122;
        v179 = 0;
        result = gsi_write_channel_scratch(v157, v177);
        if ( !(_DWORD)result )
          goto LABEL_272;
        v158 = result;
        printk(&unk_3D2A46, "ipa3_setup_wdi3_gsi_channel");
        v162 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v163 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v163 )
          {
            ipc_log_string(v163, "ipa %s:%d failed to write evt ring scratch\n", "ipa3_setup_wdi3_gsi_channel", 588);
            v162 = ipa3_ctx;
          }
          v164 = *(_QWORD *)(v162 + 34160);
          if ( v164 )
            ipc_log_string(v164, "ipa %s:%d failed to write evt ring scratch\n", "ipa3_setup_wdi3_gsi_channel", 588);
        }
        goto LABEL_311;
      }
      if ( ipa3_ctx )
      {
        gsi_smmu_mapping = *(_QWORD *)(ipa3_ctx + 34160);
        if ( gsi_smmu_mapping )
          gsi_smmu_mapping = ((__int64 (*)(__int64, const char *, ...))ipc_log_string)(
                               gsi_smmu_mapping,
                               "ipa %s:%d smmu disabled\n",
                               "ipa3_setup_wdi3_gsi_channel",
                               425);
      }
      v127 = ipa3_ctx;
      if ( *(_BYTE *)(a2 + 224) == 1 )
      {
        if ( ipa3_ctx )
        {
          gsi_smmu_mapping = *(_QWORD *)(ipa3_ctx + 34160);
          if ( gsi_smmu_mapping )
            gsi_smmu_mapping = ((__int64 (*)(__int64, const char *, ...))ipc_log_string)(
                                 gsi_smmu_mapping,
                                 "ipa %s:%d is_txr_rn_db_pcie_addr is PCIE addr\n",
                                 "ipa3_setup_wdi3_gsi_channel",
                                 427);
LABEL_219:
          v127 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v140 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( !v140
              || (gsi_smmu_mapping = ((__int64 (*)(__int64, const char *, ...))ipc_log_string)(
                                       v140,
                                       "ipa %s:%d LSB 0x%x\n",
                                       "ipa3_setup_wdi3_gsi_channel",
                                       431,
                                       *(_DWORD *)(a2 + 216)),
                  (v127 = ipa3_ctx) != 0) )
            {
              gsi_smmu_mapping = *(_QWORD *)(v127 + 34160);
              if ( gsi_smmu_mapping )
              {
                gsi_smmu_mapping = ((__int64 (*)(__int64, const char *, ...))ipc_log_string)(
                                     gsi_smmu_mapping,
                                     "ipa %s:%d MSB 0x%x\n",
                                     "ipa3_setup_wdi3_gsi_channel",
                                     433,
                                     *(_DWORD *)(a2 + 220));
                v127 = ipa3_ctx;
              }
            }
          }
        }
      }
      else if ( ipa3_ctx )
      {
        gsi_smmu_mapping = *(_QWORD *)(ipa3_ctx + 34160);
        if ( gsi_smmu_mapping )
          gsi_smmu_mapping = ((__int64 (*)(__int64, const char *, ...))ipc_log_string)(
                               gsi_smmu_mapping,
                               "ipa %s:%d is_txr_rn_db_pcie_addr is DDR addr\n",
                               "ipa3_setup_wdi3_gsi_channel",
                               429);
        goto LABEL_219;
      }
      v141 = *(_QWORD *)(a2 + 216);
      v142 = HIDWORD(v141);
      if ( !*(_DWORD *)(v127 + 32256) && *(_BYTE *)(a2 + 224) )
        LODWORD(v142) = HIDWORD(v141) | 0x100;
      goto LABEL_259;
    }
    if ( ipa3_ctx )
    {
      v82 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v82 )
      {
        ipc_log_string(v82, "ipa %s:%d smmu disabled\n", "ipa3_setup_wdi3_gsi_channel", 299);
        v78 = ipa3_ctx;
      }
      v83 = *(_QWORD *)(v78 + 34160);
      if ( v83 )
        ipc_log_string(v83, "ipa %s:%d smmu disabled\n", "ipa3_setup_wdi3_gsi_channel", 299);
    }
    if ( *(_BYTE *)(a2 + 256) == 1 )
    {
      if ( ipa3_ctx )
      {
        v84 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( v84 )
          ipc_log_string(v84, "ipa %s:%d is_evt_rn_db_pcie_addr is PCIE addr\n", "ipa3_setup_wdi3_gsi_channel", 301);
LABEL_144:
        v104 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v105 = *(_QWORD *)(ipa3_ctx + 34160);
          if ( !v105
            || (ipc_log_string(v105, "ipa %s:%d LSB 0x%x\n", "ipa3_setup_wdi3_gsi_channel", 305, *(_DWORD *)(a2 + 248)),
                (v104 = ipa3_ctx) != 0) )
          {
            v106 = *(_QWORD *)(v104 + 34160);
            if ( v106 )
              ipc_log_string(v106, "ipa %s:%d MSB 0x%x\n", "ipa3_setup_wdi3_gsi_channel", 307, *(_DWORD *)(a2 + 252));
          }
        }
      }
    }
    else if ( ipa3_ctx )
    {
      v103 = *(_QWORD *)(ipa3_ctx + 34160);
      if ( v103 )
        ipc_log_string(v103, "ipa %s:%d is_evt_rn_db_pcie_addr is DDR addr\n", "ipa3_setup_wdi3_gsi_channel", 303);
      goto LABEL_144;
    }
    v90 = (unsigned __int64 *)(a2 + 248);
    goto LABEL_150;
  }
  printk(&unk_3DB00B, "ipa3_setup_wdi3_gsi_channel");
  v97 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_242;
  v98 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v98 )
  {
    ipc_log_string(v98, "ipa %s:%d invalid input\n", "ipa3_setup_wdi3_gsi_channel", 85);
    v97 = ipa3_ctx;
  }
  v99 = *(_QWORD *)(v97 + 34160);
  if ( v99 )
  {
    ipc_log_string(v99, "ipa %s:%d invalid input\n", "ipa3_setup_wdi3_gsi_channel", 85);
    result = 4294967274LL;
  }
  else
  {
LABEL_242:
    result = 4294967274LL;
  }
LABEL_272:
  _ReadStatusReg(SP_EL0);
  return result;
}
