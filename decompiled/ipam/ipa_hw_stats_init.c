__int64 ipa_hw_stats_init()
{
  _BYTE *v0; // x0
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 ep_mapping; // x0
  unsigned int v4; // w20
  int ep_bit; // w0
  __int64 v6; // x0
  unsigned int v7; // w20
  int v8; // w0
  __int64 v9; // x0
  unsigned int v10; // w20
  int v11; // w0
  __int64 v12; // x0
  unsigned int v13; // w20
  int v14; // w0
  __int64 v15; // x10
  __int64 v16; // x0
  unsigned int v17; // w20
  int v18; // w0
  __int64 v19; // x0
  unsigned int v20; // w20
  __int64 v21; // x10
  __int64 v22; // x0
  unsigned int v23; // w20
  int v24; // w0
  __int64 v25; // x0
  unsigned int v26; // w20
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  unsigned int v30; // w8
  __int64 v31; // x0
  unsigned int v32; // w20
  int v33; // w0
  __int64 v34; // x0
  unsigned int v35; // w20
  unsigned int v36; // w0
  unsigned int v37; // w20
  __int64 v38; // x0
  unsigned int v39; // w21
  int v40; // w0
  unsigned int v41; // w8
  __int64 v42; // x0
  unsigned int v43; // w20
  int v44; // w0
  __int64 v45; // x10
  __int64 v46; // x0
  unsigned int v47; // w20
  int v48; // w0
  __int64 v49; // x10
  __int64 v50; // x0
  unsigned int v51; // w20
  int v52; // w0
  __int64 v53; // x21
  __int64 v54; // x23
  __int64 v55; // x24
  __int64 v56; // x9
  __int64 v57; // x0
  __int64 v58; // x0
  unsigned int v59; // w20
  int v60; // w0
  __int64 v61; // x0
  unsigned int v62; // w20
  unsigned int v63; // w0
  unsigned int v64; // w20
  __int64 v65; // x0
  unsigned int v66; // w21
  int v67; // w0
  __int64 v68; // x21
  __int64 v69; // x23
  __int64 v70; // x9
  __int64 v71; // x0
  __int64 v72; // x0
  unsigned int v73; // w20
  int v74; // w0
  __int64 v75; // x0
  unsigned int v76; // w20
  int v77; // w0
  __int64 v78; // x0
  unsigned int v79; // w20
  int v80; // w0
  __int64 v81; // x0
  unsigned int v82; // w20
  int v83; // w0
  __int64 v84; // x0
  unsigned int v85; // w20
  int v86; // w0
  __int64 v87; // x0
  unsigned int v88; // w20
  unsigned int v89; // w0
  unsigned int v90; // w20
  __int64 v91; // x0
  unsigned int v92; // w21
  int v93; // w0
  __int64 v94; // x21
  __int64 v95; // x23
  __int64 v96; // x9
  __int64 v97; // x0
  int ep_bit_n_idx; // w0
  __int64 v99; // x0
  unsigned int v100; // w20
  int v101; // w0
  __int64 v102; // x0
  unsigned int v103; // w20
  int v104; // w0
  __int64 v105; // x0
  unsigned int v106; // w20
  int v107; // w0
  __int64 v108; // x0
  unsigned int v109; // w20
  int v110; // w0
  __int64 v111; // x0
  unsigned int v112; // w20
  unsigned int v113; // w0
  unsigned int v114; // w20
  __int64 v115; // x0
  unsigned int v116; // w21
  int v117; // w0
  __int64 v118; // x9
  __int64 v119; // x0
  __int64 v120; // x0
  unsigned int v121; // w20
  int v122; // w0
  __int64 v123; // x0
  unsigned int v124; // w20
  int v125; // w0
  __int64 v126; // x0
  unsigned int v127; // w20
  int v128; // w0
  __int64 v129; // x0
  unsigned int v130; // w20
  int v131; // w0
  __int64 v132; // x0
  unsigned int v133; // w20
  unsigned int v134; // w0
  unsigned int v135; // w20
  __int64 v136; // x0
  unsigned int v137; // w21
  int v138; // w0
  __int64 v139; // x23
  __int64 v140; // x21
  __int64 v141; // x9
  __int64 v142; // x0
  __int64 v143; // x0
  unsigned int v144; // w20
  int v145; // w0
  __int64 v146; // x0
  unsigned int v147; // w20
  unsigned int v148; // w0
  unsigned int v149; // w20
  __int64 v150; // x0
  unsigned int v151; // w21
  int v152; // w0
  __int64 v153; // x23
  __int64 v154; // x21
  __int64 v155; // x9
  __int64 v156; // x0
  __int64 v157; // x0
  unsigned int v158; // w20
  int v159; // w0
  __int64 v160; // x0
  unsigned int v161; // w20
  unsigned int v162; // w0
  unsigned int v163; // w20
  __int64 v164; // x0
  unsigned int v165; // w21
  int v166; // w0
  __int64 v167; // x23
  __int64 v168; // x21
  __int64 v169; // x9
  __int64 v170; // x0
  __int64 v171; // x0
  unsigned int v172; // w20
  int v173; // w0
  __int64 v174; // x0
  unsigned int v175; // w20
  unsigned int v176; // w0
  unsigned int v177; // w20
  __int64 v178; // x0
  unsigned int v179; // w21
  int v180; // w0
  __int64 v181; // x23
  __int64 v182; // x21
  __int64 v183; // x9
  __int64 v184; // x0
  __int64 v185; // x0
  unsigned int v186; // w20
  int v187; // w0
  unsigned int inited; // w0
  __int64 result; // x0
  unsigned int v190; // w20
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
  __int64 v206; // x8
  __int64 v207; // x0
  __int64 v208; // x0
  __int64 v209; // x8
  __int64 v210; // x0
  __int64 v211; // x0
  __int64 v212; // x8
  __int64 v213; // x0
  __int64 v214; // x0
  __int64 v215; // x8
  __int64 v216; // x0
  __int64 v217; // x0
  __int64 v218; // x8
  __int64 v219; // x0
  __int64 v220; // x0
  unsigned int ep_reg_idx; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v222; // [xsp+8h] [xbp-8h]

  v222 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(ipa3_ctx + 32240) < 0xEu )
    goto LABEL_270;
  ep_reg_idx = 0;
  v0 = (_BYTE *)_kmalloc_large_noprof(64984, 3520);
  v1 = ipa3_ctx;
  *(_QWORD *)(ipa3_ctx + 43800) = v0;
  if ( !v0 )
  {
    printk(&unk_3DDBC8, "ipa_hw_stats_init");
    v27 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v28 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v28 )
      {
        ipc_log_string(v28, "ipa %s:%d mem allocated failed!\n", "ipa_hw_stats_init", 45);
        v27 = ipa3_ctx;
      }
      v29 = *(_QWORD *)(v27 + 34160);
      if ( v29 )
        ipc_log_string(v29, "ipa %s:%d mem allocated failed!\n", "ipa_hw_stats_init", 45);
    }
    goto LABEL_326;
  }
  *v0 = 1;
  if ( *(_DWORD *)(v1 + 32240) != 21 )
  {
    v2 = _kmalloc_cache_noprof(scnprintf, 3520, 296);
    if ( v2 )
    {
      if ( *(_DWORD *)(ipa3_ctx + 32256) == 2 )
      {
        ep_mapping = ipa_get_ep_mapping(96);
        if ( (_DWORD)ep_mapping == -1 )
        {
          ep_bit = 0;
        }
        else
        {
          v4 = ep_mapping;
          ep_reg_idx = ipahal_get_ep_reg_idx(ep_mapping);
          ep_bit = ipahal_get_ep_bit(v4);
        }
        if ( ep_reg_idx >= 2 )
          goto LABEL_319;
        *(_DWORD *)(v2 + 4LL * ep_reg_idx) = ep_bit;
        v9 = ipa_get_ep_mapping(18);
        if ( (_DWORD)v9 == -1 )
        {
          v11 = 0;
        }
        else
        {
          v10 = v9;
          ep_reg_idx = ipahal_get_ep_reg_idx(v9);
          v11 = ipahal_get_ep_bit(v10);
        }
        if ( ep_reg_idx > 1 )
          goto LABEL_319;
        v15 = ipa3_ctx;
        *(_DWORD *)(v2 + 4LL * ep_reg_idx) |= v11;
        if ( *(_BYTE *)(v15 + 32266) == 1 )
        {
          v16 = ipa_get_ep_mapping(12);
          if ( (_DWORD)v16 == -1 )
          {
            v18 = 0;
          }
          else
          {
            v17 = v16;
            ep_reg_idx = ipahal_get_ep_reg_idx(v16);
            v18 = ipahal_get_ep_bit(v17);
          }
          v30 = ep_reg_idx;
          if ( ep_reg_idx >= 2 )
            goto LABEL_319;
        }
        else
        {
          v19 = ipa_get_ep_mapping(10);
          if ( (_DWORD)v19 == -1 )
          {
            v18 = 0;
          }
          else
          {
            v20 = v19;
            ep_reg_idx = ipahal_get_ep_reg_idx(v19);
            v18 = ipahal_get_ep_bit(v20);
          }
          v30 = ep_reg_idx;
          if ( ep_reg_idx > 1 )
            goto LABEL_319;
        }
        *(_DWORD *)(v2 + 4LL * v30) |= v18;
        v31 = ipa_get_ep_mapping(86);
        if ( (_DWORD)v31 == -1 )
        {
          v33 = 0;
        }
        else
        {
          v32 = v31;
          ep_reg_idx = ipahal_get_ep_reg_idx(v31);
          v33 = ipahal_get_ep_bit(v32);
        }
        if ( ep_reg_idx > 1 )
          goto LABEL_319;
        *(_DWORD *)(v2 + 4LL * ep_reg_idx) |= v33;
        v34 = ipa_get_ep_mapping(96);
        if ( (_DWORD)v34 != -1 )
        {
          v35 = v34;
          ep_reg_idx = ipahal_get_ep_reg_idx(v34);
          if ( (unsigned int)ipahal_get_ep_bit(v35) )
          {
            v36 = ipa_get_ep_mapping(96);
            if ( v36 == -1 )
            {
              printk(&unk_3AC96C, "ipa_hw_stats_init");
              v206 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v207 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v207 )
                {
                  ipc_log_string(v207, "ipa %s:%d Invalid client.\n", "ipa_hw_stats_init", 96);
                  v206 = ipa3_ctx;
                }
                v208 = *(_QWORD *)(v206 + 34160);
                if ( v208 )
                  ipc_log_string(v208, "ipa %s:%d Invalid client.\n", "ipa_hw_stats_init", 96);
              }
              goto LABEL_317;
            }
            v37 = v36;
            v38 = ipa_get_ep_mapping(19);
            if ( (_DWORD)v38 == -1 )
            {
              v40 = 0;
            }
            else
            {
              v39 = v38;
              ep_reg_idx = ipahal_get_ep_reg_idx(v38);
              v40 = ipahal_get_ep_bit(v39);
            }
            if ( v37 > 0x23 || ep_reg_idx > 1 )
              goto LABEL_319;
            v53 = 8LL * v37;
            if ( (v53 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
              goto LABEL_320;
            v54 = v2 + 8;
            v55 = v2 + 8 + 8LL * v37;
            v56 = ipa3_ctx;
            *(_DWORD *)(v55 + 4LL * ep_reg_idx) = v40;
            if ( *(_BYTE *)(v56 + 32266) == 1 )
              v57 = 13;
            else
              v57 = 11;
            v58 = ipa_get_ep_mapping(v57);
            if ( (_DWORD)v58 == -1 )
            {
              v60 = 0;
            }
            else
            {
              v59 = v58;
              ep_reg_idx = ipahal_get_ep_reg_idx(v58);
              v60 = ipahal_get_ep_bit(v59);
            }
            goto LABEL_169;
          }
        }
      }
      else
      {
        v6 = ipa_get_ep_mapping(52);
        if ( (_DWORD)v6 == -1 )
        {
          v8 = 0;
        }
        else
        {
          v7 = v6;
          ep_reg_idx = ipahal_get_ep_reg_idx(v6);
          v8 = ipahal_get_ep_bit(v7);
        }
        if ( ep_reg_idx > 1 )
          goto LABEL_319;
        *(_DWORD *)(v2 + 4LL * ep_reg_idx) = v8;
        v12 = ipa_get_ep_mapping(18);
        if ( (_DWORD)v12 == -1 )
        {
          v14 = 0;
        }
        else
        {
          v13 = v12;
          ep_reg_idx = ipahal_get_ep_reg_idx(v12);
          v14 = ipahal_get_ep_bit(v13);
        }
        if ( ep_reg_idx > 1 )
          goto LABEL_319;
        v21 = ipa3_ctx;
        *(_DWORD *)(v2 + 4LL * ep_reg_idx) |= v14;
        if ( *(_BYTE *)(v21 + 32266) == 1 )
        {
          v22 = ipa_get_ep_mapping(12);
          if ( (_DWORD)v22 == -1 )
          {
            v24 = 0;
          }
          else
          {
            v23 = v22;
            ep_reg_idx = ipahal_get_ep_reg_idx(v22);
            v24 = ipahal_get_ep_bit(v23);
          }
          v41 = ep_reg_idx;
          if ( ep_reg_idx >= 2 )
            goto LABEL_319;
        }
        else
        {
          v25 = ipa_get_ep_mapping(10);
          if ( (_DWORD)v25 == -1 )
          {
            v24 = 0;
          }
          else
          {
            v26 = v25;
            ep_reg_idx = ipahal_get_ep_reg_idx(v25);
            v24 = ipahal_get_ep_bit(v26);
          }
          v41 = ep_reg_idx;
          if ( ep_reg_idx > 1 )
            goto LABEL_319;
        }
        *(_DWORD *)(v2 + 4LL * v41) |= v24;
        v42 = ipa_get_ep_mapping(86);
        if ( (_DWORD)v42 == -1 )
        {
          v44 = 0;
        }
        else
        {
          v43 = v42;
          ep_reg_idx = ipahal_get_ep_reg_idx(v42);
          v44 = ipahal_get_ep_bit(v43);
        }
        if ( ep_reg_idx > 1 )
          goto LABEL_319;
        v45 = ipa3_ctx;
        *(_DWORD *)(v2 + 4LL * ep_reg_idx) |= v44;
        if ( *(_DWORD *)(v45 + 32240) >= 0x11u )
        {
          v46 = ipa_get_ep_mapping(74);
          if ( (_DWORD)v46 == -1 )
          {
            v48 = 0;
          }
          else
          {
            v47 = v46;
            ep_reg_idx = ipahal_get_ep_reg_idx(v46);
            v48 = ipahal_get_ep_bit(v47);
          }
          if ( ep_reg_idx > 1 )
            goto LABEL_319;
          v49 = ipa3_ctx;
          *(_DWORD *)(v2 + 4LL * ep_reg_idx) |= v48;
          if ( *(_DWORD *)(v49 + 32240) >= 0x16u )
          {
            v50 = ipa_get_ep_mapping(122);
            if ( (_DWORD)v50 == -1 )
            {
              v52 = 0;
            }
            else
            {
              v51 = v50;
              ep_reg_idx = ipahal_get_ep_reg_idx(v50);
              v52 = ipahal_get_ep_bit(v51);
            }
            if ( ep_reg_idx > 1 )
              goto LABEL_319;
            *(_DWORD *)(v2 + 4LL * ep_reg_idx) |= v52;
          }
        }
        v61 = ipa_get_ep_mapping(52);
        if ( (_DWORD)v61 != -1 )
        {
          v62 = v61;
          ep_reg_idx = ipahal_get_ep_reg_idx(v61);
          if ( (unsigned int)ipahal_get_ep_bit(v62) )
          {
            v63 = ipa_get_ep_mapping(52);
            if ( v63 == -1 )
            {
              printk(&unk_3AC96C, "ipa_hw_stats_init");
              v209 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v210 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v210 )
                {
                  ipc_log_string(v210, "ipa %s:%d Invalid client.\n", "ipa_hw_stats_init", 181);
                  v209 = ipa3_ctx;
                }
                v211 = *(_QWORD *)(v209 + 34160);
                if ( v211 )
                  ipc_log_string(v211, "ipa %s:%d Invalid client.\n", "ipa_hw_stats_init", 181);
              }
              goto LABEL_317;
            }
            v64 = v63;
            v65 = ipa_get_ep_mapping(19);
            if ( (_DWORD)v65 == -1 )
            {
              v67 = 0;
            }
            else
            {
              v66 = v65;
              ep_reg_idx = ipahal_get_ep_reg_idx(v65);
              v67 = ipahal_get_ep_bit(v66);
            }
            if ( v64 > 0x23 || ep_reg_idx > 1 )
              goto LABEL_319;
            v68 = 8LL * v64;
            if ( (v68 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
              goto LABEL_320;
            v69 = v2 + 8 + 8LL * v64;
            v70 = ipa3_ctx;
            *(_DWORD *)(v69 + 4LL * ep_reg_idx) = v67;
            v71 = *(_BYTE *)(v70 + 32266) == 1 ? 13LL : 11LL;
            v72 = ipa_get_ep_mapping(v71);
            if ( (_DWORD)v72 == -1 )
            {
              v74 = 0;
            }
            else
            {
              v73 = v72;
              ep_reg_idx = ipahal_get_ep_reg_idx(v72);
              v74 = ipahal_get_ep_bit(v73);
            }
            if ( ep_reg_idx > 1 )
              goto LABEL_319;
            if ( (v68 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
              goto LABEL_320;
            *(_DWORD *)(v69 + 4LL * ep_reg_idx) |= v74;
            v75 = ipa_get_ep_mapping(87);
            if ( (_DWORD)v75 == -1 )
            {
              v77 = 0;
            }
            else
            {
              v76 = v75;
              ep_reg_idx = ipahal_get_ep_reg_idx(v75);
              v77 = ipahal_get_ep_bit(v76);
            }
            if ( ep_reg_idx > 1 )
              goto LABEL_319;
            if ( (v68 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
              goto LABEL_320;
            *(_DWORD *)(v69 + 4LL * ep_reg_idx) |= v77;
            v78 = ipa_get_ep_mapping(89);
            if ( (_DWORD)v78 == -1 )
            {
              v80 = 0;
            }
            else
            {
              v79 = v78;
              ep_reg_idx = ipahal_get_ep_reg_idx(v78);
              v80 = ipahal_get_ep_bit(v79);
            }
            if ( ep_reg_idx > 1 )
              goto LABEL_319;
            if ( (v68 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
              goto LABEL_320;
            *(_DWORD *)(v69 + 4LL * ep_reg_idx) |= v80;
            v81 = ipa_get_ep_mapping(91);
            if ( (_DWORD)v81 == -1 )
            {
              v83 = 0;
            }
            else
            {
              v82 = v81;
              ep_reg_idx = ipahal_get_ep_reg_idx(v81);
              v83 = ipahal_get_ep_bit(v82);
            }
            if ( ep_reg_idx > 1 )
              goto LABEL_319;
            if ( (v68 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
              goto LABEL_320;
            *(_DWORD *)(v69 + 4LL * ep_reg_idx) |= v83;
            v84 = ipa_get_ep_mapping(93);
            if ( (_DWORD)v84 == -1 )
            {
              v86 = 0;
            }
            else
            {
              v85 = v84;
              ep_reg_idx = ipahal_get_ep_reg_idx(v84);
              v86 = ipahal_get_ep_bit(v85);
            }
            if ( ep_reg_idx > 1 )
              goto LABEL_319;
            if ( (v68 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
              goto LABEL_320;
            *(_DWORD *)(v69 + 4LL * ep_reg_idx) |= v86;
          }
        }
        v87 = ipa_get_ep_mapping(74);
        if ( (_DWORD)v87 != -1 )
        {
          v88 = v87;
          ep_reg_idx = ipahal_get_ep_reg_idx(v87);
          if ( (unsigned int)ipahal_get_ep_bit(v88) )
          {
            if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x11u )
            {
              v89 = ipa_get_ep_mapping(74);
              if ( v89 == -1 )
              {
                printk(&unk_3AC96C, "ipa_hw_stats_init");
                v212 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v213 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v213 )
                  {
                    ipc_log_string(v213, "ipa %s:%d Invalid client.\n", "ipa_hw_stats_init", 229);
                    v212 = ipa3_ctx;
                  }
                  v214 = *(_QWORD *)(v212 + 34160);
                  if ( v214 )
                    ipc_log_string(v214, "ipa %s:%d Invalid client.\n", "ipa_hw_stats_init", 229);
                }
                goto LABEL_317;
              }
              v90 = v89;
              v91 = ipa_get_ep_mapping(19);
              if ( (_DWORD)v91 == -1 )
              {
                v93 = 0;
              }
              else
              {
                v92 = v91;
                ep_reg_idx = ipahal_get_ep_reg_idx(v91);
                v93 = ipahal_get_ep_bit(v92);
              }
              if ( v90 > 0x23 || ep_reg_idx > 1 )
                goto LABEL_319;
              v94 = 8LL * v90;
              if ( (v94 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
                goto LABEL_320;
              v95 = v2 + 8 + 8LL * v90;
              v96 = ipa3_ctx;
              *(_DWORD *)(v95 + 4LL * ep_reg_idx) = v93;
              v97 = *(_BYTE *)(v96 + 32266) == 1 ? 13LL : 11LL;
              ep_bit_n_idx = ipa_hw_stats_get_ep_bit_n_idx(v97, &ep_reg_idx);
              if ( ep_reg_idx > 1 )
                goto LABEL_319;
              if ( (v94 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
                goto LABEL_320;
              *(_DWORD *)(v95 + 4LL * ep_reg_idx) |= ep_bit_n_idx;
              v99 = ipa_get_ep_mapping(87);
              if ( (_DWORD)v99 == -1 )
              {
                v101 = 0;
              }
              else
              {
                v100 = v99;
                ep_reg_idx = ipahal_get_ep_reg_idx(v99);
                v101 = ipahal_get_ep_bit(v100);
              }
              if ( ep_reg_idx > 1 )
                goto LABEL_319;
              if ( (v94 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
                goto LABEL_320;
              *(_DWORD *)(v95 + 4LL * ep_reg_idx) |= v101;
              v102 = ipa_get_ep_mapping(89);
              if ( (_DWORD)v102 == -1 )
              {
                v104 = 0;
              }
              else
              {
                v103 = v102;
                ep_reg_idx = ipahal_get_ep_reg_idx(v102);
                v104 = ipahal_get_ep_bit(v103);
              }
              if ( ep_reg_idx > 1 )
                goto LABEL_319;
              if ( (v94 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
                goto LABEL_320;
              *(_DWORD *)(v95 + 4LL * ep_reg_idx) |= v104;
              v105 = ipa_get_ep_mapping(91);
              if ( (_DWORD)v105 == -1 )
              {
                v107 = 0;
              }
              else
              {
                v106 = v105;
                ep_reg_idx = ipahal_get_ep_reg_idx(v105);
                v107 = ipahal_get_ep_bit(v106);
              }
              if ( ep_reg_idx > 1 )
                goto LABEL_319;
              if ( (v94 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
                goto LABEL_320;
              *(_DWORD *)(v95 + 4LL * ep_reg_idx) |= v107;
              v108 = ipa_get_ep_mapping(93);
              if ( (_DWORD)v108 == -1 )
              {
                v110 = 0;
              }
              else
              {
                v109 = v108;
                ep_reg_idx = ipahal_get_ep_reg_idx(v108);
                v110 = ipahal_get_ep_bit(v109);
              }
              if ( ep_reg_idx > 1 )
                goto LABEL_319;
              if ( (v94 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
                goto LABEL_320;
              *(_DWORD *)(v95 + 4LL * ep_reg_idx) |= v110;
            }
          }
        }
        v111 = ipa_get_ep_mapping(122);
        if ( (_DWORD)v111 != -1 )
        {
          v112 = v111;
          ep_reg_idx = ipahal_get_ep_reg_idx(v111);
          if ( (unsigned int)ipahal_get_ep_bit(v112) )
          {
            if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x15u )
            {
              v113 = ipa_get_ep_mapping(122);
              if ( v113 == -1 )
              {
                printk(&unk_3AC96C, "ipa_hw_stats_init");
                v215 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v216 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v216 )
                  {
                    ipc_log_string(v216, "ipa %s:%d Invalid client.\n", "ipa_hw_stats_init", 276);
                    v215 = ipa3_ctx;
                  }
                  v217 = *(_QWORD *)(v215 + 34160);
                  if ( v217 )
                    ipc_log_string(v217, "ipa %s:%d Invalid client.\n", "ipa_hw_stats_init", 276);
                }
                goto LABEL_317;
              }
              v114 = v113;
              v115 = ipa_get_ep_mapping(19);
              if ( (_DWORD)v115 == -1 )
              {
                v117 = 0;
              }
              else
              {
                v116 = v115;
                ep_reg_idx = ipahal_get_ep_reg_idx(v115);
                v117 = ipahal_get_ep_bit(v116);
              }
              if ( v114 > 0x23 || ep_reg_idx > 1 )
                goto LABEL_319;
              v53 = 8LL * v114;
              if ( (v53 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
                goto LABEL_320;
              v54 = v2 + 8;
              v55 = v2 + 8 + 8LL * v114;
              v118 = ipa3_ctx;
              *(_DWORD *)(v55 + 4LL * ep_reg_idx) = v117;
              if ( *(_BYTE *)(v118 + 32266) == 1 )
                v119 = 13;
              else
                v119 = 11;
              v60 = ipa_hw_stats_get_ep_bit_n_idx(v119, &ep_reg_idx);
LABEL_169:
              if ( ep_reg_idx > 1 )
                goto LABEL_319;
              if ( (v53 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
                goto LABEL_320;
              *(_DWORD *)(v55 + 4LL * ep_reg_idx) |= v60;
              v120 = ipa_get_ep_mapping(87);
              if ( (_DWORD)v120 == -1 )
              {
                v122 = 0;
              }
              else
              {
                v121 = v120;
                ep_reg_idx = ipahal_get_ep_reg_idx(v120);
                v122 = ipahal_get_ep_bit(v121);
              }
              if ( ep_reg_idx > 1 )
                goto LABEL_319;
              if ( (v53 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
                goto LABEL_320;
              *(_DWORD *)(v55 + 4LL * ep_reg_idx) |= v122;
              v123 = ipa_get_ep_mapping(89);
              if ( (_DWORD)v123 == -1 )
              {
                v125 = 0;
              }
              else
              {
                v124 = v123;
                ep_reg_idx = ipahal_get_ep_reg_idx(v123);
                v125 = ipahal_get_ep_bit(v124);
              }
              if ( ep_reg_idx > 1 )
                goto LABEL_319;
              if ( (v53 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
                goto LABEL_320;
              *(_DWORD *)(v55 + 4LL * ep_reg_idx) |= v125;
              v126 = ipa_get_ep_mapping(91);
              if ( (_DWORD)v126 == -1 )
              {
                v128 = 0;
              }
              else
              {
                v127 = v126;
                ep_reg_idx = ipahal_get_ep_reg_idx(v126);
                v128 = ipahal_get_ep_bit(v127);
              }
              if ( ep_reg_idx > 1 )
                goto LABEL_319;
              if ( (v53 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
                goto LABEL_320;
              *(_DWORD *)(v55 + 4LL * ep_reg_idx) |= v128;
              v129 = ipa_get_ep_mapping(93);
              if ( (_DWORD)v129 == -1 )
              {
                v131 = 0;
              }
              else
              {
                v130 = v129;
                ep_reg_idx = ipahal_get_ep_reg_idx(v129);
                v131 = ipahal_get_ep_bit(v130);
              }
              if ( ep_reg_idx > 1 )
                goto LABEL_319;
              if ( (v53 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
                goto LABEL_320;
              *(_DWORD *)(v54 + v53 + 4LL * ep_reg_idx) |= v131;
            }
          }
        }
      }
      v132 = ipa_get_ep_mapping(18);
      if ( (_DWORD)v132 != -1 )
      {
        v133 = v132;
        ep_reg_idx = ipahal_get_ep_reg_idx(v132);
        if ( (unsigned int)ipahal_get_ep_bit(v133) )
        {
          v134 = ipa_get_ep_mapping(18);
          if ( v134 == -1 )
          {
            printk(&unk_3AC96C, "ipa_hw_stats_init");
            v194 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v195 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v195 )
              {
                ipc_log_string(v195, "ipa %s:%d Invalid client.\n", "ipa_hw_stats_init", 323);
                v194 = ipa3_ctx;
              }
              v196 = *(_QWORD *)(v194 + 34160);
              if ( v196 )
                ipc_log_string(v196, "ipa %s:%d Invalid client.\n", "ipa_hw_stats_init", 323);
            }
            goto LABEL_317;
          }
          v135 = v134;
          v136 = ipa_get_ep_mapping(53);
          if ( (_DWORD)v136 == -1 )
          {
            v138 = 0;
          }
          else
          {
            v137 = v136;
            ep_reg_idx = ipahal_get_ep_reg_idx(v136);
            v138 = ipahal_get_ep_bit(v137);
          }
          if ( v135 > 0x23 || ep_reg_idx > 1 )
            goto LABEL_319;
          v139 = 8LL * v135;
          if ( (v139 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
            goto LABEL_320;
          v140 = v2 + 8 + 8LL * v135;
          v141 = ipa3_ctx;
          *(_DWORD *)(v140 + 4LL * ep_reg_idx) = v138;
          if ( *(_DWORD *)(v141 + 32256) == 2 )
          {
            v142 = 97;
          }
          else
          {
            if ( *(_DWORD *)(v141 + 32240) < 0x11u )
              goto LABEL_211;
            v142 = 75;
          }
          v143 = ipa_get_ep_mapping(v142);
          if ( (_DWORD)v143 == -1 )
          {
            v145 = 0;
          }
          else
          {
            v144 = v143;
            ep_reg_idx = ipahal_get_ep_reg_idx(v143);
            v145 = ipahal_get_ep_bit(v144);
          }
          if ( ep_reg_idx > 1 )
            goto LABEL_319;
          if ( (v139 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
            goto LABEL_320;
          *(_DWORD *)(v140 + 4LL * ep_reg_idx) |= v145;
        }
      }
LABEL_211:
      v146 = ipa_get_ep_mapping(10);
      if ( (_DWORD)v146 != -1 )
      {
        v147 = v146;
        ep_reg_idx = ipahal_get_ep_reg_idx(v146);
        if ( (unsigned int)ipahal_get_ep_bit(v147) )
        {
          v148 = ipa_get_ep_mapping(10);
          if ( v148 == -1 )
          {
            printk(&unk_3AC96C, "ipa_hw_stats_init");
            v197 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v198 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v198 )
              {
                ipc_log_string(v198, "ipa %s:%d Invalid client.\n", "ipa_hw_stats_init", 352);
                v197 = ipa3_ctx;
              }
              v199 = *(_QWORD *)(v197 + 34160);
              if ( v199 )
                ipc_log_string(v199, "ipa %s:%d Invalid client.\n", "ipa_hw_stats_init", 352);
            }
            goto LABEL_317;
          }
          v149 = v148;
          v150 = ipa_get_ep_mapping(53);
          if ( (_DWORD)v150 == -1 )
          {
            v152 = 0;
          }
          else
          {
            v151 = v150;
            ep_reg_idx = ipahal_get_ep_reg_idx(v150);
            v152 = ipahal_get_ep_bit(v151);
          }
          if ( v149 > 0x23 || ep_reg_idx > 1 )
            goto LABEL_319;
          v153 = 8LL * v149;
          if ( (v153 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
            goto LABEL_320;
          v154 = v2 + 8 + 8LL * v149;
          v155 = ipa3_ctx;
          *(_DWORD *)(v154 + 4LL * ep_reg_idx) = v152;
          if ( *(_DWORD *)(v155 + 32256) == 2 )
          {
            v156 = 97;
          }
          else
          {
            if ( *(_DWORD *)(v155 + 32240) < 0x11u )
              goto LABEL_230;
            v156 = 75;
          }
          v157 = ipa_get_ep_mapping(v156);
          if ( (_DWORD)v157 == -1 )
          {
            v159 = 0;
          }
          else
          {
            v158 = v157;
            ep_reg_idx = ipahal_get_ep_reg_idx(v157);
            v159 = ipahal_get_ep_bit(v158);
          }
          if ( ep_reg_idx > 1 )
            goto LABEL_319;
          if ( (v153 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
            goto LABEL_320;
          *(_DWORD *)(v154 + 4LL * ep_reg_idx) |= v159;
        }
      }
LABEL_230:
      v160 = ipa_get_ep_mapping(12);
      if ( (_DWORD)v160 != -1 )
      {
        v161 = v160;
        ep_reg_idx = ipahal_get_ep_reg_idx(v160);
        if ( (unsigned int)ipahal_get_ep_bit(v161) )
        {
          v162 = ipa_get_ep_mapping(12);
          if ( v162 == -1 )
          {
            printk(&unk_3AC96C, "ipa_hw_stats_init");
            v200 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v201 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v201 )
              {
                ipc_log_string(v201, "ipa %s:%d Invalid client.\n", "ipa_hw_stats_init", 381);
                v200 = ipa3_ctx;
              }
              v202 = *(_QWORD *)(v200 + 34160);
              if ( v202 )
                ipc_log_string(v202, "ipa %s:%d Invalid client.\n", "ipa_hw_stats_init", 381);
            }
            goto LABEL_317;
          }
          v163 = v162;
          v164 = ipa_get_ep_mapping(53);
          if ( (_DWORD)v164 == -1 )
          {
            v166 = 0;
          }
          else
          {
            v165 = v164;
            ep_reg_idx = ipahal_get_ep_reg_idx(v164);
            v166 = ipahal_get_ep_bit(v165);
          }
          if ( v163 > 0x23 || ep_reg_idx > 1 )
            goto LABEL_319;
          v167 = 8LL * v163;
          if ( (v167 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
            goto LABEL_320;
          v168 = v2 + 8 + 8LL * v163;
          v169 = ipa3_ctx;
          *(_DWORD *)(v168 + 4LL * ep_reg_idx) = v166;
          if ( *(_DWORD *)(v169 + 32256) == 2 )
          {
            v170 = 97;
LABEL_243:
            v171 = ipa_get_ep_mapping(v170);
            if ( (_DWORD)v171 == -1 )
            {
              v173 = 0;
            }
            else
            {
              v172 = v171;
              ep_reg_idx = ipahal_get_ep_reg_idx(v171);
              v173 = ipahal_get_ep_bit(v172);
            }
            if ( ep_reg_idx > 1 )
              goto LABEL_319;
            if ( (v167 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
              goto LABEL_320;
            *(_DWORD *)(v168 + 4LL * ep_reg_idx) |= v173;
            goto LABEL_249;
          }
          if ( *(_DWORD *)(v169 + 32240) >= 0x11u )
          {
            v170 = 75;
            goto LABEL_243;
          }
        }
      }
LABEL_249:
      v174 = ipa_get_ep_mapping(86);
      if ( (_DWORD)v174 == -1 )
        goto LABEL_268;
      v175 = v174;
      ep_reg_idx = ipahal_get_ep_reg_idx(v174);
      if ( !(unsigned int)ipahal_get_ep_bit(v175) )
        goto LABEL_268;
      v176 = ipa_get_ep_mapping(86);
      if ( v176 != -1 )
      {
        v177 = v176;
        v178 = ipa_get_ep_mapping(53);
        if ( (_DWORD)v178 == -1 )
        {
          v180 = 0;
        }
        else
        {
          v179 = v178;
          ep_reg_idx = ipahal_get_ep_reg_idx(v178);
          v180 = ipahal_get_ep_bit(v179);
        }
        if ( v177 > 0x23 || ep_reg_idx > 1 )
          goto LABEL_319;
        v181 = 8LL * v177;
        if ( (v181 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
          goto LABEL_320;
        v182 = v2 + 8 + 8LL * v177;
        v183 = ipa3_ctx;
        *(_DWORD *)(v182 + 4LL * ep_reg_idx) = v180;
        if ( *(_DWORD *)(v183 + 32256) == 2 )
        {
          v184 = 97;
          goto LABEL_262;
        }
        if ( *(_DWORD *)(v183 + 32240) >= 0x11u )
        {
          v184 = 75;
LABEL_262:
          v185 = ipa_get_ep_mapping(v184);
          if ( (_DWORD)v185 == -1 )
          {
            v187 = 0;
          }
          else
          {
            v186 = v185;
            ep_reg_idx = ipahal_get_ep_reg_idx(v185);
            v187 = ipahal_get_ep_bit(v186);
          }
          if ( ep_reg_idx <= 1 )
          {
            if ( (v181 | (4 * (unsigned __int64)ep_reg_idx)) > 0x11F )
              goto LABEL_320;
            *(_DWORD *)(v182 + 4LL * ep_reg_idx) |= v187;
            goto LABEL_268;
          }
LABEL_319:
          __break(0x5512u);
LABEL_320:
          __break(1u);
        }
LABEL_268:
        inited = ipa_init_teth_stats(v2);
        if ( !inited )
        {
          *(_BYTE *)(*(_QWORD *)(ipa3_ctx + 43800) + 64976LL) = 1;
          kfree(v2);
          goto LABEL_270;
        }
        v190 = inited;
        printk(&unk_3FE08C, "ipa_hw_stats_init");
        v191 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v192 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v192 )
          {
            ipc_log_string(v192, "ipa %s:%d init teth stats fails\n", "ipa_hw_stats_init", 437);
            v191 = ipa3_ctx;
          }
          v193 = *(_QWORD *)(v191 + 34160);
          if ( v193 )
            ipc_log_string(v193, "ipa %s:%d init teth stats fails\n", "ipa_hw_stats_init", 437);
        }
LABEL_318:
        kfree(v2);
        kfree(*(_QWORD *)(ipa3_ctx + 43800));
        result = v190;
        *(_QWORD *)(ipa3_ctx + 43800) = 0;
        goto LABEL_271;
      }
      printk(&unk_3AC96C, "ipa_hw_stats_init");
      v203 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v204 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v204 )
        {
          ipc_log_string(v204, "ipa %s:%d Invalid client.\n", "ipa_hw_stats_init", 410);
          v203 = ipa3_ctx;
        }
        v205 = *(_QWORD *)(v203 + 34160);
        if ( v205 )
          ipc_log_string(v205, "ipa %s:%d Invalid client.\n", "ipa_hw_stats_init", 410);
      }
LABEL_317:
      v190 = -22;
      goto LABEL_318;
    }
    printk(&unk_3DDBC8, "ipa_hw_stats_init");
    v218 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v219 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v219 )
      {
        ipc_log_string(v219, "ipa %s:%d mem allocated failed!\n", "ipa_hw_stats_init", 58);
        v218 = ipa3_ctx;
      }
      v220 = *(_QWORD *)(v218 + 34160);
      if ( v220 )
        ipc_log_string(v220, "ipa %s:%d mem allocated failed!\n", "ipa_hw_stats_init", 58);
    }
LABEL_326:
    result = 4294967284LL;
    goto LABEL_271;
  }
LABEL_270:
  result = 0;
LABEL_271:
  _ReadStatusReg(SP_EL0);
  return result;
}
