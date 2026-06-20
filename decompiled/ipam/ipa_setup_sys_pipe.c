__int64 __fastcall ipa_setup_sys_pipe(__int64 a1, unsigned int *a2)
{
  unsigned int *v2; // x20
  unsigned int v4; // w3
  signed int ep_mapping; // w0
  unsigned int v6; // w27
  __int64 v7; // x22
  __int64 v8; // x22
  int v9; // t1
  unsigned int v10; // w24
  unsigned int v11; // w0
  __int64 v12; // x19
  unsigned int v13; // w23
  const char *v14; // x8
  void *v15; // x0
  unsigned int v16; // w23
  int v17; // w10
  unsigned int v18; // w8
  __int64 (__fastcall *v19)(); // x25
  __int64 v20; // x9
  __int64 v21; // x8
  __int64 v22; // x0
  int v23; // w3
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x8
  unsigned int v27; // w8
  __int64 v28; // x9
  __int64 v29; // x9
  int v30; // t1
  __int64 v31; // x8
  unsigned int v32; // w0
  int v33; // w1
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x8
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x8
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x9
  __int64 v53; // x8
  unsigned __int64 v54; // x8
  int v55; // w8
  __int64 v56; // x25
  int v57; // w4
  __int64 v58; // x8
  __int64 v59; // x8
  int v60; // w22
  int v61; // w8
  int v62; // w9
  unsigned int v63; // w0
  __int64 v64; // x8
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x8
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x0
  unsigned int v72; // w10
  unsigned int v73; // w8
  __int64 v74; // x8
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x9
  char v78; // w9
  _DWORD *v79; // x9
  bool v80; // cc
  void *v81; // x8
  __int64 v82; // x0
  __int64 v83; // x0
  unsigned int v84; // w8
  unsigned int v85; // w8
  __int64 v86; // x8
  __int64 v87; // x8
  __int64 v88; // x0
  __int64 v89; // x0
  __int64 v90; // x8
  __int64 v91; // x0
  __int64 v92; // x0
  __int64 v93; // x8
  __int64 v94; // x0
  __int64 v95; // x0
  __int64 v96; // x0
  __int64 v97; // x0
  __int64 v98; // x9
  unsigned int v99; // w8
  __int64 v100; // x8
  __int64 v101; // x0
  __int64 v102; // x0
  __int64 v103; // x8
  __int64 v104; // x0
  __int64 v105; // x0
  unsigned int v106; // w0
  __int64 v107; // x8
  __int64 v108; // x8
  __int64 v109; // x8
  __int64 v110; // x9
  __int64 v111; // x8
  __int64 v112; // x8
  __int64 v113; // x8
  int v114; // w11
  int v115; // w19
  char v116; // w0
  int v117; // w9
  int v118; // w10
  __int64 v119; // x9
  __int64 v120; // x8
  __int64 v121; // x0
  __int64 v122; // x0
  int v123; // w12
  __int64 v124; // x8
  __int64 v125; // x0
  __int64 v126; // x0
  __int64 v127; // x8
  __int64 v128; // x0
  __int64 v129; // x0
  __int64 v130; // x0
  __int64 v131; // x0
  _QWORD *v132; // x8
  __int64 v133; // x8
  __int64 v134; // x23
  int v135; // w19
  _QWORD *v136; // x0
  _QWORD *v137; // x2
  _QWORD *v138; // x1
  __int64 v139; // x8
  __int64 v140; // x0
  __int64 v141; // x0
  __int64 v142; // x8
  __int64 v143; // x0
  __int64 v144; // x0
  __int64 v145; // x8
  __int64 v146; // x0
  __int64 v147; // x0
  __int64 v148; // x0
  __int64 v149; // x0
  __int64 v150; // x0
  __int64 v151; // x0
  __int64 v152; // x8
  __int64 v153; // x9
  __int64 v154; // x0
  __int64 v155; // x8
  __int64 v156; // x0
  __int64 v157; // x10
  __int64 v158; // x9
  __int64 v159; // x8
  int v160; // w10
  __int64 v161; // x0
  __int64 v162; // x0
  int v163; // w8
  int pool_size; // w0
  __int64 v165; // x8
  __int64 v166; // x0
  __int64 v167; // x0
  unsigned int v168; // w8
  int v169; // w8
  __int64 v170; // x23
  unsigned int v171; // w20
  unsigned int v172; // w19
  unsigned int v173; // w24
  int v174; // w22
  _QWORD *v175; // x0
  _QWORD *v176; // x25
  __int64 (__fastcall *v177)(__int64, __int64); // x8
  __int64 v178; // x0
  __int64 v179; // x0
  __int64 v180; // x0
  __int64 v181; // x26
  __int64 v182; // x27
  const char **v183; // x28
  char v184; // w0
  char v185; // w20
  __int64 v186; // x0
  __int64 *v187; // x8
  int v188; // w9
  int v189; // w0
  const char *v190; // x0
  const char *v191; // x2
  __int64 v192; // x8
  __int64 v193; // x0
  __int64 v194; // x0
  int v195; // w0
  __int64 v196; // x8
  __int64 v197; // x8
  __int64 v198; // x8
  __int64 v199; // x8
  __int64 v200; // x8
  __int64 v201; // x8
  __int64 v202; // x8
  __int64 v203; // x8
  __int64 v204; // x8
  __int64 v205; // x8
  __int64 v206; // x8
  __int64 v207; // x8
  __int64 v208; // x8
  __int64 v209; // x8
  __int64 v210; // x8
  __int64 v211; // x8
  __int64 v212; // x8
  __int64 *v213; // x23
  __int64 v214; // x0
  __int64 v215; // x25
  const char **v216; // x26
  char v217; // w0
  __int64 v218; // x0
  __int64 v219; // x2
  __int64 *v220; // x1
  __int64 v221; // x8
  __int64 v222; // x0
  unsigned int v223; // w23
  int v224; // w10
  const char *v225; // x0
  const char *v226; // x2
  __int64 v227; // x8
  __int64 v228; // x0
  __int64 v229; // x0
  __int64 v230; // x8
  __int64 v231; // x0
  __int64 v232; // x0
  const void **v233; // x19
  __int64 v234; // x8
  __int64 v235; // x0
  __int64 v236; // x0
  char v238; // w9
  unsigned int v239; // w10
  __int64 v240; // x8
  int v241; // w10
  __int64 v242; // x0
  __int64 v243; // x0
  unsigned int v244; // w0
  __int64 started; // x0
  __int64 v246; // x8
  __int64 v247; // x0
  int v248; // w8
  const char *v249; // x20
  char *v250; // x1
  __int64 v251; // x8
  const char *v252; // x8
  __int64 v253; // x8
  __int64 v254; // x0
  __int64 v255; // x0
  __int64 v256; // x8
  __int64 v257; // x0
  __int64 v258; // x0
  unsigned int v259; // w8
  __int64 v260; // x0
  __int64 v261; // x8
  __int64 v262; // x0
  __int64 v263; // x8
  __int64 v264; // x0
  __int64 v265; // x0
  unsigned int v266; // w8
  __int64 v267; // x0
  __int64 v268; // x0
  __int64 v269; // x8
  const char *v270; // x8
  __int64 v272; // x8
  __int64 v273; // x0
  __int64 v274; // x0
  int v275; // w23
  __int64 v276; // x8
  __int64 v277; // x0
  __int64 v278; // x0
  __int64 v279; // x8
  __int64 v280; // x0
  __int64 v281; // x0
  const void **v282; // x19
  __int64 v283; // x8
  __int64 v284; // x0
  __int64 v285; // x0
  void (__fastcall *v286)(_QWORD); // x8
  __int64 v287; // x0
  int v288; // w24
  __int64 v289; // x8
  __int64 v290; // x0
  __int64 v291; // x0
  __int64 v292; // x8
  __int64 v293; // x0
  __int64 v294; // x0
  unsigned int v296; // w9
  __int64 v297; // x8
  __int64 v298; // x0
  __int64 v299; // x0
  unsigned __int64 v302; // x10
  unsigned __int64 v309; // x12
  char v310; // [xsp+8h] [xbp-498h]
  unsigned int *v311; // [xsp+20h] [xbp-480h]
  __int64 v312; // [xsp+28h] [xbp-478h]
  unsigned int v313; // [xsp+30h] [xbp-470h]
  __int64 v314; // [xsp+38h] [xbp-468h]
  _QWORD dest[24]; // [xsp+40h] [xbp-460h] BYREF
  int v316; // [xsp+104h] [xbp-39Ch] BYREF
  __int64 v317; // [xsp+108h] [xbp-398h] BYREF
  _QWORD s[4]; // [xsp+110h] [xbp-390h] BYREF
  _QWORD v319[110]; // [xsp+130h] [xbp-370h] BYREF

  v2 = a2;
  v319[108] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v317 = 0;
  memset(s, 0, sizeof(s));
  v316 = 0;
  memset(dest, 0, sizeof(dest));
  if ( !a1 || !a2 )
  {
    printk(&unk_3F1F11, "ipa_setup_sys_pipe");
    v39 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_74;
    v40 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v40 )
    {
      ipc_log_string(
        v40,
        "ipa %s:%d NULL args: sys_in(%p) and/or clnt_hdl(%p)\n",
        "ipa_setup_sys_pipe",
        1488,
        (const void *)a1,
        v2);
      v39 = ipa3_ctx;
    }
    v41 = *(_QWORD *)(v39 + 34160);
    if ( !v41 )
      goto LABEL_74;
    ipc_log_string(
      v41,
      "ipa %s:%d NULL args: sys_in(%p) and/or clnt_hdl(%p)\n",
      "ipa_setup_sys_pipe",
      1488,
      (const void *)a1,
      v2);
    v16 = -22;
    goto LABEL_475;
  }
  v4 = *(_DWORD *)(a1 + 192);
  if ( v4 > 0x85 || !*(_DWORD *)(a1 + 196) )
  {
    printk(&unk_3EEDCB, "ipa_setup_sys_pipe");
    v34 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_74;
    v35 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v35 )
    {
      ipc_log_string(
        v35,
        "ipa %s:%d bad parm client:%d fifo_sz:%d\n",
        "ipa_setup_sys_pipe",
        1494,
        *(_DWORD *)(a1 + 192),
        *(_DWORD *)(a1 + 196));
      v34 = ipa3_ctx;
    }
    v36 = *(_QWORD *)(v34 + 34160);
    if ( !v36 )
      goto LABEL_74;
    ipc_log_string(
      v36,
      "ipa %s:%d bad parm client:%d fifo_sz:%d\n",
      "ipa_setup_sys_pipe",
      1494,
      *(_DWORD *)(a1 + 192),
      *(_DWORD *)(a1 + 196));
    v16 = -22;
    goto LABEL_475;
  }
  ep_mapping = ipa_get_ep_mapping(v4);
  if ( ep_mapping == -1 )
  {
    printk(&unk_3AC96C, "ipa_setup_sys_pipe");
    v42 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_74;
    v43 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v43 )
    {
      ipc_log_string(v43, "ipa %s:%d Invalid client.\n", "ipa_setup_sys_pipe", 1499);
      v42 = ipa3_ctx;
    }
    v44 = *(_QWORD *)(v42 + 34160);
    if ( !v44 )
      goto LABEL_74;
    ipc_log_string(v44, "ipa %s:%d Invalid client.\n", "ipa_setup_sys_pipe", 1499);
    v16 = -22;
LABEL_475:
    ++*(_DWORD *)(ipa3_ctx + 32904);
    goto LABEL_476;
  }
  v6 = ep_mapping;
  if ( (unsigned int)ep_mapping >= 0x25 )
    goto LABEL_519;
  v7 = ipa3_ctx + 480LL * ep_mapping;
  v314 = ep_mapping;
  v9 = *(_DWORD *)(v7 + 168);
  v8 = v7 + 168;
  if ( v9 == 1 )
  {
    printk(&unk_3B202E, "ipa_setup_sys_pipe");
    v45 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v46 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v46 )
      {
        ipc_log_string(v46, "ipa %s:%d EP %d already allocated.\n", "ipa_setup_sys_pipe", 1505, v6);
        v45 = ipa3_ctx;
      }
      v47 = *(_QWORD *)(v45 + 34160);
      if ( v47 )
      {
        ipc_log_string(v47, "ipa %s:%d EP %d already allocated.\n", "ipa_setup_sys_pipe", 1505, v6);
        v16 = -22;
        goto LABEL_475;
      }
    }
LABEL_74:
    v16 = -22;
    goto LABEL_475;
  }
  *v2 = 0;
  v10 = ipa_get_ep_mapping(95);
  v11 = ipa_get_ep_mapping(127);
  v12 = *(unsigned int *)(a1 + 192);
  v13 = v11;
  if ( ((unsigned int)v12 | 0x20) == 0x7F )
  {
    memcpy(dest, (const void *)a1, sizeof(dest));
    v319[1] = "ipa_dp.c";
    v319[2] = 1517;
LABEL_10:
    v14 = ipa_clients_strings[v12];
    goto LABEL_11;
  }
  v319[1] = "ipa_dp.c";
  v319[2] = 1517;
  if ( (unsigned int)v12 <= 0x85 )
    goto LABEL_10;
  v14 = "Invalid Client";
LABEL_11:
  v319[0] = v14;
  ipa3_inc_client_enable_clks();
  memset((void *)v8, 0, 0x1D8u);
  v15 = *(void **)(v8 + 472);
  v311 = v2;
  if ( v15 )
  {
    memset(v15, 0, 0x658u);
LABEL_13:
    v16 = -22;
    goto LABEL_14;
  }
  memset(v319, 0, 32);
  v22 = _kmalloc_cache_noprof(__ratelimit, 3520, 1952);
  *(_QWORD *)(v8 + 472) = v22;
  if ( !v22 )
  {
    printk(&unk_3EEDF6, "ipa_setup_sys_pipe");
    v297 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v298 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v298 )
      {
        ipc_log_string(
          v298,
          "ipa %s:%d failed to sys ctx for client %d\n",
          "ipa_setup_sys_pipe",
          1527,
          *(_DWORD *)(a1 + 192));
        v297 = ipa3_ctx;
      }
      v299 = *(_QWORD *)(v297 + 34160);
      if ( v299 )
        ipc_log_string(
          v299,
          "ipa %s:%d failed to sys ctx for client %d\n",
          "ipa_setup_sys_pipe",
          1527,
          *(_DWORD *)(a1 + 192));
    }
    v16 = -12;
    goto LABEL_471;
  }
  v23 = *(_DWORD *)(a1 + 192);
  *(_QWORD *)(v22 + 1624) = v8;
  snprintf((char *)s, 0x20u, "ipawq%d", v23);
  *(_QWORD *)(*(_QWORD *)(v8 + 472) + 1752LL) = alloc_workqueue((const char *)s, 74, 1);
  if ( !*(_QWORD *)(*(_QWORD *)(v8 + 472) + 1752LL) )
  {
    printk(&unk_3DB2C4, "ipa_setup_sys_pipe");
    v67 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v68 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v68 )
      {
        ipc_log_string(
          v68,
          "ipa %s:%d failed to create wq for client %d\n",
          "ipa_setup_sys_pipe",
          1540,
          *(_DWORD *)(a1 + 192));
        v67 = ipa3_ctx;
      }
      v69 = *(_QWORD *)(v67 + 34160);
      if ( v69 )
        ipc_log_string(
          v69,
          "ipa %s:%d failed to create wq for client %d\n",
          "ipa_setup_sys_pipe",
          1540,
          *(_DWORD *)(a1 + 192));
    }
    v16 = -14;
    goto LABEL_470;
  }
  snprintf((char *)s, 0x20u, "iparepwq%d", *(_DWORD *)(a1 + 192));
  *(_QWORD *)(*(_QWORD *)(v8 + 472) + 1760LL) = alloc_workqueue((const char *)s, 90, 1);
  if ( !*(_QWORD *)(*(_QWORD *)(v8 + 472) + 1760LL) )
  {
    printk(&unk_3A67ED, "ipa_setup_sys_pipe");
    v74 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v75 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v75 )
      {
        ipc_log_string(
          v75,
          "ipa %s:%d failed to create rep wq for client %d\n",
          "ipa_setup_sys_pipe",
          1552,
          *(_DWORD *)(a1 + 192));
        v74 = ipa3_ctx;
      }
      v76 = *(_QWORD *)(v74 + 34160);
      if ( v76 )
        ipc_log_string(
          v76,
          "ipa %s:%d failed to create rep wq for client %d\n",
          "ipa_setup_sys_pipe",
          1552,
          *(_DWORD *)(a1 + 192));
    }
    v16 = -14;
    goto LABEL_469;
  }
  snprintf((char *)s, 0x20u, "ipafreepagewq%d", *(_DWORD *)(a1 + 192));
  v24 = *(_QWORD *)(v8 + 472);
  *(_QWORD *)(v24 + 1632) = v24 + 1632;
  *(_QWORD *)(v24 + 1640) = v24 + 1632;
  v25 = *(_QWORD *)(v8 + 472);
  *(_QWORD *)(v25 + 1648) = v25 + 1648;
  *(_QWORD *)(v25 + 1656) = v25 + 1648;
  v26 = *(_QWORD *)(v8 + 472);
  *(_QWORD *)(v26 + 1664) = v26 + 1664;
  *(_QWORD *)(v26 + 1672) = v26 + 1664;
  *(_DWORD *)(*(_QWORD *)(v8 + 472) + 1680LL) = 0;
  *(_DWORD *)(*(_QWORD *)(v8 + 472) + 1684LL) = 0;
  hrtimer_init(*(_QWORD *)(v8 + 472) + 1688LL, 1, 1);
  *(_QWORD *)(*(_QWORD *)(v8 + 472) + 1728LL) = ipa3_ring_doorbell_timer_fn;
  v27 = *(_DWORD *)(a1 + 192);
  if ( v27 != 35 || v10 == -1 )
  {
    if ( v27 != 33 || v13 == -1 )
      goto LABEL_44;
    if ( v13 > 0x23 )
      goto LABEL_519;
    v28 = ipa3_ctx + 480LL * v13;
  }
  else
  {
    if ( v10 > 0x23 )
      goto LABEL_519;
    v28 = ipa3_ctx + 480LL * v10;
  }
  v30 = *(_DWORD *)(v28 + 168);
  v29 = v28 + 168;
  if ( v30 == 1 )
  {
    *(_DWORD *)(*(_QWORD *)(v8 + 472) + 1776LL) = *(_DWORD *)(*(_QWORD *)(v29 + 472) + 1776LL);
    goto LABEL_13;
  }
LABEL_44:
  v16 = -22;
  if ( v27 <= 0x85 && (v27 & 1) != 0 )
  {
    *(_QWORD *)(*(_QWORD *)(v8 + 472) + 1792LL) = alloc_workqueue((const char *)s, 90, 1);
    if ( !*(_QWORD *)(*(_QWORD *)(v8 + 472) + 1792LL) )
    {
      printk(&unk_3DB320, "ipa_setup_sys_pipe");
      v87 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v88 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v88 )
        {
          ipc_log_string(
            v88,
            "ipa %s:%d failed to create freepage wq for client %d\n",
            "ipa_setup_sys_pipe",
            1586,
            *(_DWORD *)(a1 + 192));
          v87 = ipa3_ctx;
        }
        v89 = *(_QWORD *)(v87 + 34160);
        if ( v89 )
          ipc_log_string(
            v89,
            "ipa %s:%d failed to create freepage wq for client %d\n",
            "ipa_setup_sys_pipe",
            1586,
            *(_DWORD *)(a1 + 192));
      }
      v16 = -14;
      goto LABEL_468;
    }
    v319[0] = ipa_clients_strings[*(unsigned int *)(a1 + 192)];
    v319[1] = ipa_pm_sys_pipe_cb;
    v31 = *(_QWORD *)(v8 + 472);
    LODWORD(v319[3]) = 1;
    v319[2] = v31;
    v32 = ipa_pm_register(v319, *(_QWORD *)(v8 + 472) + 1776LL);
    if ( v32 )
    {
      v16 = v32;
      printk(&unk_3C6B8B, "ipa_setup_sys_pipe");
      v90 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v91 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v91 )
        {
          ipc_log_string(v91, "ipa %s:%d failed to create IPA PM client %d\n", "ipa_setup_sys_pipe", 1598, v16);
          v90 = ipa3_ctx;
        }
        v92 = *(_QWORD *)(v90 + 34160);
        if ( v92 )
          ipc_log_string(v92, "ipa %s:%d failed to create IPA PM client %d\n", "ipa_setup_sys_pipe", 1598, v16);
      }
      goto LABEL_466;
    }
    v33 = *(_DWORD *)(a1 + 192);
    if ( (unsigned int)(v33 - 33) <= 0x3E && ((1LL << ((unsigned __int8)v33 - 33)) & 0x4000000000000005LL) != 0
      || (unsigned int)(v33 - 105) <= 0x16 && ((1 << (v33 - 105)) & 0x410001) != 0 )
    {
      v63 = ipa_pm_associate_ipa_cons_to_client(*(unsigned int *)(*(_QWORD *)(v8 + 472) + 1776LL));
      if ( v63 )
      {
        v16 = v63;
        printk(&unk_3C6BBA, "ipa_setup_sys_pipe");
        v93 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v94 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v94 )
          {
            ipc_log_string(v94, "ipa %s:%d failed to associate\n", "ipa_setup_sys_pipe", 1606);
            v93 = ipa3_ctx;
          }
          v95 = *(_QWORD *)(v93 + 34160);
          if ( v95 )
            ipc_log_string(v95, "ipa %s:%d failed to associate\n", "ipa_setup_sys_pipe", 1606);
        }
        goto LABEL_465;
      }
    }
    v16 = ((__int64 (__fastcall *)(_QWORD, __int64))ipa_pm_set_throughput)(
            *(unsigned int *)(*(_QWORD *)(v8 + 472) + 1776LL),
            700);
    if ( v16 )
    {
      printk(&unk_3E3931, "ipa_setup_sys_pipe");
      v64 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v65 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v65 )
        {
          ipc_log_string(v65, "ipa %s:%d failed to set profile IPA PM client\n", "ipa_setup_sys_pipe", 1614);
          v64 = ipa3_ctx;
        }
        v66 = *(_QWORD *)(v64 + 34160);
        if ( v66 )
          ipc_log_string(v66, "ipa %s:%d failed to set profile IPA PM client\n", "ipa_setup_sys_pipe", 1614);
      }
      goto LABEL_465;
    }
  }
LABEL_14:
  v17 = *(unsigned __int8 *)(ipa3_ctx + 45392);
  *(_DWORD *)(*(_QWORD *)(v8 + 472) + 664LL) = 0;
  v18 = *(_DWORD *)(a1 + 192);
  if ( v17 )
    v19 = (__int64 (__fastcall *)())&ipa3_aux_napi_poll_tx_complete;
  else
    v19 = ipa3_aux_napi_tx_complete;
  if ( v18 <= 0x85 && (v18 & 1) == 0 )
  {
    tasklet_init(*(_QWORD *)(v8 + 472) + 672LL, ipa3_tasklet_write_done);
    v18 = *(_DWORD *)(a1 + 192);
  }
  if ( v18 == 105 )
  {
    tasklet_init(*(_QWORD *)(v8 + 472) + 672LL, ipa3_tasklet_rx_notify);
    v18 = *(_DWORD *)(a1 + 192);
  }
  if ( v18 <= 0x85 && (v18 & 1) == 0 )
  {
    v20 = ipa3_ctx;
    if ( *(_BYTE *)(ipa3_ctx + 45391) != 1 )
    {
LABEL_82:
      v18 = *(_DWORD *)(a1 + 192);
      goto LABEL_83;
    }
    if ( (unsigned __int8)v18 == 120 || (unsigned __int8)v18 == 34 )
    {
      v37 = *(_QWORD *)(a1 + 200);
      v21 = *(_QWORD *)(v8 + 472);
      _X9 = (unsigned __int64 *)(v21 + 736);
      __asm { PRFM            #0x11, [X9] }
      do
        v302 = __ldxr(_X9);
      while ( __stxr(v302 | 0x20, _X9) );
    }
    else
    {
      if ( (unsigned __int8)v18 != 32 )
      {
        *(_BYTE *)(*(_QWORD *)(v8 + 472) + 1584LL) = 0;
        *(_BYTE *)(*(_QWORD *)(v8 + 472) + 1585LL) = 0;
        goto LABEL_76;
      }
      v21 = *(_QWORD *)(v8 + 472);
      _X11 = (unsigned __int64 *)(v21 + 736);
      __asm { PRFM            #0x11, [X11] }
      do
        v309 = __ldxr(_X11);
      while ( __stxr(v309 | 0x20, _X11) );
      v37 = v20 + 45440;
    }
    netif_napi_add_weight(v37, v21 + 720, v19, 64);
    v38 = ipa3_ctx + 45056;
    *(_BYTE *)(*(_QWORD *)(v8 + 472) + 1585LL) = *(_BYTE *)(ipa3_ctx + 45391);
    *(_BYTE *)(*(_QWORD *)(v8 + 472) + 1584LL) = *(_BYTE *)(v38 + 336);
LABEL_76:
    v48 = *(_QWORD *)(v8 + 472);
    if ( *(_BYTE *)(v48 + 1585) == 1 )
    {
      napi_enable(v48 + 720);
      v49 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v50 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v50 )
        {
          ipc_log_string(
            v50,
            "ipa %s:%d napi_enable on producer client %d completed",
            "ipa_setup_sys_pipe",
            1676,
            *(_DWORD *)(a1 + 192));
          v49 = ipa3_ctx;
        }
        v51 = *(_QWORD *)(v49 + 34160);
        if ( v51 )
          ipc_log_string(
            v51,
            "ipa %s:%d napi_enable on producer client %d completed",
            "ipa_setup_sys_pipe",
            1676,
            *(_DWORD *)(a1 + 192));
      }
    }
    goto LABEL_82;
  }
LABEL_83:
  v52 = *(_QWORD *)(v8 + 472);
  if ( v18 == 121 )
  {
    netif_napi_add_weight(*(_QWORD *)(a1 + 200), v52 + 1152, ipa3_rmnet_ll_rx_poll, 64);
    napi_enable(*(_QWORD *)(v8 + 472) + 1152LL);
    v18 = *(_DWORD *)(a1 + 192);
    v52 = *(_QWORD *)(v8 + 472);
  }
  *(_DWORD *)(v8 + 4) = v18;
  *(_BYTE *)(v52 + 1608) = *(_BYTE *)(a1 + 248);
  *(_DWORD *)(*(_QWORD *)(v8 + 472) + 1592LL) = *(_DWORD *)(a1 + 236);
  *(_DWORD *)(*(_QWORD *)(v8 + 472) + 1596LL) = *(_DWORD *)(a1 + 240);
  v53 = *(unsigned int *)(a1 + 244);
  *(_DWORD *)(*(_QWORD *)(v8 + 472) + 1600LL) = v53;
  if ( *(_BYTE *)(a1 + 248) == 1 )
  {
    v54 = v53 - 1;
    if ( v54 >= 0x1000 )
      v55 = 64 - __clz(v54 >> 12);
    else
      v55 = 0;
  }
  else
  {
    v55 = 3;
  }
  v312 = v8;
  *(_DWORD *)(*(_QWORD *)(v8 + 472) + 1604LL) = v55;
  v56 = *(_QWORD *)(v8 + 472);
  *(_BYTE *)(v8 + 404) = *(_BYTE *)(a1 + 216);
  v57 = *(_DWORD *)(a1 + 192);
  if ( v57 <= 45 )
  {
    if ( v57 != 34 )
    {
      if ( v57 != 36 )
      {
        if ( v57 != 44 )
          goto LABEL_100;
LABEL_193:
        *(_DWORD *)(v56 + 120) = 1;
        goto LABEL_194;
      }
LABEL_98:
      *(_DWORD *)(v56 + 120) = 0;
      *(_BYTE *)(v56 + 124) = 0;
      goto LABEL_194;
    }
LABEL_99:
    v58 = ipa3_ctx;
    *(_DWORD *)(v56 + 120) = 0;
    LODWORD(v58) = *(_DWORD *)(v58 + 32240);
    *(_QWORD *)(v56 + 192) = 0xFFFFFFFE00000LL;
    *(_BYTE *)(v56 + 124) = (unsigned int)v58 < 0x15;
    *(_QWORD *)(v56 + 200) = v56 + 200;
    *(_QWORD *)(v56 + 208) = v56 + 200;
    *(_QWORD *)(v56 + 216) = ipa3_send_nop_desc;
    *(_DWORD *)(v56 + 8) = 0;
    *(_BYTE *)(*(_QWORD *)(v56 + 1624) + 352LL) = 1;
    *(_BYTE *)(*(_QWORD *)(v56 + 1624) + 353LL) = ipa_get_ep_mapping(53);
    *(_BYTE *)(*(_QWORD *)(v56 + 1624) + 355LL) = 1;
    goto LABEL_194;
  }
  switch ( v57 )
  {
    case '.':
      goto LABEL_193;
    case 'x':
      goto LABEL_99;
    case 'h':
      goto LABEL_98;
  }
LABEL_100:
  v59 = ipa3_ctx;
  v60 = *(unsigned __int8 *)(ipa3_ctx + 43344);
  if ( (unsigned int)v57 <= 0x85 && (v57 & 1) == 0 )
  {
    if ( *(_BYTE *)(*(_QWORD *)(v56 + 1624) + 404LL) == 1 )
    {
      *(_DWORD *)(v56 + 120) = 2;
      *(_BYTE *)(v56 + 124) = 1;
      *(_DWORD *)(v56 + 4) = 0;
    }
    else
    {
      *(_DWORD *)(v56 + 120) = 0;
      *(_BYTE *)(v56 + 124) = 1;
      *(_QWORD *)(v56 + 192) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v56 + 200) = v56 + 200;
      *(_QWORD *)(v56 + 208) = v56 + 200;
      *(_QWORD *)(v56 + 216) = ipa3_send_nop_desc;
      *(_DWORD *)(v56 + 8) = 0;
    }
    goto LABEL_194;
  }
  switch ( v57 )
  {
    case 11:
    case 13:
    case 15:
    case 17:
    case 119:
      if ( ipa3_ctx )
      {
        v70 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v70 )
        {
          ipc_log_string(v70, "ipa %s:%d assigning policy to client:%d", "ipa3_assign_policy", 5981, v57);
          v59 = ipa3_ctx;
        }
        v71 = *(_QWORD *)(v59 + 34160);
        if ( v71 )
          ipc_log_string(
            v71,
            "ipa %s:%d assigning policy to client:%d",
            "ipa3_assign_policy",
            5981,
            *(_DWORD *)(a1 + 192));
      }
      *(_DWORD *)(v56 + 120) = 2;
      *(_QWORD *)(v56 + 192) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v56 + 200) = v56 + 200;
      *(_QWORD *)(v56 + 208) = v56 + 200;
      *(_QWORD *)(v56 + 216) = ipa3_wq_handle_rx;
      *(_QWORD *)(v56 + 16) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v56 + 24) = v56 + 24;
      *(_QWORD *)(v56 + 32) = v56 + 24;
      *(_QWORD *)(v56 + 40) = ipa3_switch_to_intr_rx_work_func;
      init_timer_key(v56 + 48, &delayed_work_timer_fn, 0x200000, 0, 0);
      *(_QWORD *)(v56 + 224) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v56 + 232) = v56 + 232;
      *(_QWORD *)(v56 + 240) = v56 + 232;
      *(_QWORD *)(v56 + 248) = ipa3_replenish_rx_work_func;
      init_timer_key(v56 + 256, &delayed_work_timer_fn, 0x200000, 0, 0);
      *(_DWORD *)(v56 + 4) = 0;
      *(_DWORD *)(v56 + 160) = 2048;
      v72 = *(_DWORD *)(a1 + 196);
      *(_QWORD *)(v56 + 360) = ipa3_replenish_wlan_rx_cache;
      *(_QWORD *)(v56 + 128) = 0;
      *(_QWORD *)(v56 + 136) = ipa3_get_skb_ipa_rx;
      *(_QWORD *)(v56 + 144) = ipa_free_skb_rx;
      *(_QWORD *)(v56 + 152) = ipa3_free_rx_wrapper;
      v73 = (v72 >> 3) - 1;
      if ( v73 >= 0x64 )
        v73 = 100;
      *(_DWORD *)(v56 + 164) = v73;
      *(_DWORD *)(a1 + 96) = 0;
      goto LABEL_194;
    case 33:
    case 35:
    case 95:
    case 105:
    case 121:
    case 127:
      *(_BYTE *)(*(_QWORD *)(v56 + 1624) + 352LL) = 1;
      *(_DWORD *)(v56 + 120) = 2;
      *(_QWORD *)(v56 + 192) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v56 + 200) = v56 + 200;
      *(_QWORD *)(v56 + 208) = v56 + 200;
      *(_QWORD *)(v56 + 216) = ipa3_wq_handle_rx;
      *(_QWORD *)(v56 + 16) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v56 + 24) = v56 + 24;
      *(_QWORD *)(v56 + 32) = v56 + 24;
      *(_QWORD *)(v56 + 40) = ipa3_switch_to_intr_rx_work_func;
      init_timer_key(v56 + 48, &delayed_work_timer_fn, 0x200000, 0, 0);
      *(_QWORD *)(v56 + 224) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v56 + 232) = v56 + 232;
      *(_QWORD *)(v56 + 240) = v56 + 232;
      *(_QWORD *)(v56 + 248) = ipa3_replenish_rx_work_func;
      init_timer_key(v56 + 256, &delayed_work_timer_fn, 0x200000, 0, 0);
      *(_DWORD *)(v56 + 4) = 0;
      *(_DWORD *)(v56 + 160) = 7744;
      *(_QWORD *)(v56 + 136) = ipa3_get_skb_ipa_rx;
      *(_QWORD *)(v56 + 144) = ipa_free_skb_rx;
      v61 = *(_DWORD *)(a1 + 192);
      if ( ((v61 - 95) & 0xFFFFFFDF) != 0 )
        v62 = 4;
      else
        v62 = 5;
      *(_DWORD *)(a1 + 100) = v62;
      if ( v61 > 104 )
      {
        if ( v61 == 105 )
        {
          *(_QWORD *)(v56 + 328) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v56 + 336) = v56 + 336;
          *(_QWORD *)(v56 + 344) = v56 + 336;
          v152 = *(_QWORD *)(v56 + 1624);
          *(_QWORD *)(v56 + 352) = ipa3_wq_repl_rx;
          *(_BYTE *)(v152 + 352) = 0;
          *(_QWORD *)(v56 + 128) = ipa3_low_lat_rx_pyld_hdlr;
          *(_DWORD *)(v56 + 160) = 128;
          v153 = ipa3_ctx;
          *(_QWORD *)(v56 + 360) = &ipa3_fast_replenish_rx_cache;
          *(_QWORD *)(v56 + 152) = ipa3_free_rx_wrapper;
          *(_DWORD *)(v56 + 164) = *(_DWORD *)(v153 + 43256);
          goto LABEL_194;
        }
        if ( v61 == 121 )
          goto LABEL_147;
        if ( v61 != 127 )
          goto LABEL_194;
      }
      else if ( v61 != 33 )
      {
        if ( v61 != 35 && v61 != 95 )
          goto LABEL_194;
LABEL_147:
        v78 = *(_BYTE *)(a1 + 248);
        *(_DWORD *)(a1 + 96) = 1;
        if ( (v78 & 1) == 0 )
          *(_DWORD *)(a1 + 108) = 500;
        v79 = (_DWORD *)(ipa3_ctx + 43256);
        if ( *(_BYTE *)(ipa3_ctx + 45386) == 1 )
        {
          if ( v61 != 121 && !*(_QWORD *)(a1 + 224) )
            goto LABEL_152;
        }
        else if ( v61 != 121 )
        {
LABEL_152:
          *(_QWORD *)(v56 + 328) = 0xFFFFFFFE00000LL;
          *(_QWORD *)(v56 + 336) = v56 + 336;
          *(_QWORD *)(v56 + 344) = v56 + 336;
          *(_QWORD *)(v56 + 352) = ipa3_wq_repl_rx;
          *(_QWORD *)(v56 + 128) = ipa3_wan_rx_pyld_hdlr;
          *(_QWORD *)(v56 + 152) = ipa3_free_rx_wrapper;
          v80 = nr_cpu_ids > 1u;
          *(_DWORD *)(v56 + 164) = *v79;
          v81 = &ipa3_fast_replenish_rx_cache;
          if ( !v80 )
            v81 = &ipa3_replenish_rx_cache;
          *(_QWORD *)(v56 + 360) = v81;
          if ( *(_QWORD *)(a1 + 224) && *(_BYTE *)(a1 + 232) == 1 )
            *(_QWORD *)(v56 + 360) = &ipa3_replenish_rx_cache_recycle;
          goto LABEL_180;
        }
        *(_QWORD *)(v56 + 328) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(v56 + 336) = v56 + 336;
        *(_QWORD *)(v56 + 344) = v56 + 336;
        *(_QWORD *)(v56 + 128) = ipa3_wan_rx_pyld_hdlr;
        *(_QWORD *)(v56 + 152) = ipa3_recycle_rx_page_wrapper;
        *(_QWORD *)(v56 + 352) = ipa3_wq_page_repl;
        *(_QWORD *)(v56 + 360) = ipa3_replenish_rx_page_recycle;
        *(_DWORD *)(v56 + 164) = *v79;
LABEL_180:
        *(_BYTE *)(a1 + 120) = 1;
        if ( v60 )
        {
          ipa3_set_aggr_limit(a1, v56);
        }
        else
        {
          *(_DWORD *)(a1 + 112) = 0;
          *(_DWORD *)(a1 + 104) = 6;
        }
        goto LABEL_194;
      }
      *(_QWORD *)(v56 + 328) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v56 + 336) = v56 + 336;
      *(_QWORD *)(v56 + 344) = v56 + 336;
      *(_QWORD *)(v56 + 128) = ipa3_lan_rx_pyld_hdlr;
      *(_QWORD *)(v56 + 352) = ipa3_wq_repl_rx;
      *(_QWORD *)(v56 + 360) = &ipa3_replenish_rx_cache_recycle;
      v77 = ipa3_ctx;
      *(_QWORD *)(v56 + 152) = ipa3_recycle_rx_wrapper;
      *(_DWORD *)(v56 + 164) = *(_DWORD *)(v77 + 43260);
      LODWORD(v77) = *(_DWORD *)(a1 + 192);
      *(_DWORD *)(a1 + 96) = 1;
      *(_QWORD *)(a1 + 104) = 0x1F400000006LL;
      *(_DWORD *)(a1 + 112) = 0;
      if ( (_DWORD)v77 == 127 )
      {
        *(_BYTE *)(a1 + 123) = 1;
        *(_DWORD *)(a1 + 116) = 1;
      }
LABEL_194:
      v8 = v312;
      *(_DWORD *)v312 = 1;
      v98 = *(_QWORD *)(v312 + 472);
      *(_QWORD *)(v312 + 376) = *(_QWORD *)(a1 + 208);
      *(_QWORD *)(v98 + 384) = *(_QWORD *)(a1 + 224);
      *(_QWORD *)(v312 + 368) = *(_QWORD *)(a1 + 200);
      *(_BYTE *)(v312 + 405) = *(_BYTE *)(a1 + 217);
      *(_DWORD *)(v312 + 384) = (*(_DWORD *)(a1 + 196) >> 3) - 1;
      if ( *(_BYTE *)(v312 + 352) == 1 )
      {
        v99 = *(_DWORD *)(v312 + 4);
        if ( v99 <= 0x85 && (v99 & 1) != 0 && !*(_QWORD *)(*(_QWORD *)(v312 + 472) + 1768LL) )
        {
          *(_QWORD *)(*(_QWORD *)(v312 + 472) + 1768LL) = _kmalloc_cache_noprof(dma_alloc_attrs, 3520, 2888);
          if ( !*(_QWORD *)(*(_QWORD *)(v312 + 472) + 1768LL) )
            goto LABEL_459;
        }
      }
      if ( (*(_BYTE *)(v312 + 404) & 1) != 0 )
      {
        v100 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v101 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v101 )
          {
            ipc_log_string(v101, "ipa %s:%d skipping ep %d configuration\n", "ipa_setup_sys_pipe", 1732, v6);
            v100 = ipa3_ctx;
          }
          v102 = *(_QWORD *)(v100 + 34160);
          if ( v102 )
            ipc_log_string(v102, "ipa %s:%d skipping ep %d configuration\n", "ipa_setup_sys_pipe", 1732, v6);
        }
      }
      else
      {
        if ( (unsigned int)ipa3_cfg_ep(v6, a1) )
        {
          printk(&unk_3D5322, "ipa_setup_sys_pipe");
          v124 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v125 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v125 )
            {
              ipc_log_string(v125, "ipa %s:%d fail to configure EP.\n", "ipa_setup_sys_pipe", 1723);
              v124 = ipa3_ctx;
            }
            v126 = *(_QWORD *)(v124 + 34160);
            if ( v126 )
              ipc_log_string(v126, "ipa %s:%d fail to configure EP.\n", "ipa_setup_sys_pipe", 1723);
          }
          goto LABEL_459;
        }
        if ( (unsigned int)ipa3_cfg_ep_status(v6, v312 + 352) )
        {
          printk(&unk_3A6426, "ipa_setup_sys_pipe");
          v127 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v128 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v128 )
            {
              ipc_log_string(v128, "ipa %s:%d fail to configure status of EP.\n", "ipa_setup_sys_pipe", 1727);
              v127 = ipa3_ctx;
            }
            v129 = *(_QWORD *)(v127 + 34160);
            if ( v129 )
              ipc_log_string(v129, "ipa %s:%d fail to configure status of EP.\n", "ipa_setup_sys_pipe", 1727);
          }
          goto LABEL_459;
        }
        v103 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v104 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v104 )
          {
            ipc_log_string(v104, "ipa %s:%d ep %d configuration successful\n", "ipa_setup_sys_pipe", 1730, v6);
            v103 = ipa3_ctx;
          }
          v105 = *(_QWORD *)(v103 + 34160);
          if ( v105 )
            ipc_log_string(v105, "ipa %s:%d ep %d configuration successful\n", "ipa_setup_sys_pipe", 1730, v6);
        }
      }
      v106 = ((__int64 (__fastcall *)(__int64, __int64))ipa_gsi_setup_channel)(a1, v312);
      if ( v106 )
      {
        v16 = v106;
        printk(&unk_3DB29B, "ipa_setup_sys_pipe");
        v120 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v121 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v121 )
          {
            ipc_log_string(v121, "ipa %s:%d Failed to setup GSI channel\n", "ipa_setup_sys_pipe", 1737);
            v120 = ipa3_ctx;
          }
          v122 = *(_QWORD *)(v120 + 34160);
          if ( v122 )
            ipc_log_string(v122, "ipa %s:%d Failed to setup GSI channel\n", "ipa_setup_sys_pipe", 1737);
        }
        goto LABEL_459;
      }
      *v2 = v6;
      if ( v6 == 36 )
        goto LABEL_519;
      *(_QWORD *)(*(_QWORD *)(v312 + 472) + 1944LL) = *(_QWORD *)(ipa3_ctx + 480LL * (int)v6 + 640);
      if ( *(_UNKNOWN **)(*(_QWORD *)(v312 + 472) + 360LL) == &ipa3_fast_replenish_rx_cache )
      {
        *(_QWORD *)(*(_QWORD *)(v312 + 472) + 368LL) = _kmalloc_cache_noprof(
                                                         of_property_read_variable_u32_array,
                                                         3520,
                                                         24);
        v107 = *(_QWORD *)(*(_QWORD *)(v312 + 472) + 368LL);
        if ( !v107 )
        {
          printk(&unk_3AF70E, "ipa_setup_sys_pipe");
          v139 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v140 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v140 )
            {
              ipc_log_string(
                v140,
                "ipa %s:%d failed to alloc repl for client %d\n",
                "ipa_setup_sys_pipe",
                1748,
                *(_DWORD *)(a1 + 192));
              v139 = ipa3_ctx;
            }
            v141 = *(_QWORD *)(v139 + 34160);
            if ( v141 )
            {
              ipc_log_string(
                v141,
                "ipa %s:%d failed to alloc repl for client %d\n",
                "ipa_setup_sys_pipe",
                1748,
                *(unsigned int *)(a1 + 192));
LABEL_280:
              v16 = -12;
LABEL_459:
              if ( *(_DWORD *)(a1 + 192) == 121 )
              {
                napi_disable(*(_QWORD *)(v8 + 472) + 1152LL);
                v265 = _netif_napi_del(*(_QWORD *)(v8 + 472) + 1152LL);
                synchronize_net(v265);
              }
              if ( *(_BYTE *)(ipa3_ctx + 45391) == 1 )
              {
                v266 = *(_DWORD *)(a1 + 192);
                if ( v266 <= 0x85 && (v266 & 1) == 0 )
                {
                  v267 = _netif_napi_del(*(_QWORD *)(v8 + 472) + 720LL);
                  synchronize_net(v267);
                }
              }
LABEL_465:
              ((void (__fastcall *)(_QWORD))ipa_pm_deregister)(*(unsigned int *)(*(_QWORD *)(v8 + 472) + 1776LL));
LABEL_466:
              v268 = *(_QWORD *)(*(_QWORD *)(v8 + 472) + 1792LL);
              if ( v268 )
                destroy_workqueue(v268);
LABEL_468:
              destroy_workqueue(*(_QWORD *)(*(_QWORD *)(v8 + 472) + 1760LL));
LABEL_469:
              destroy_workqueue(*(_QWORD *)(*(_QWORD *)(v8 + 472) + 1752LL));
LABEL_470:
              kfree(*(_QWORD *)(v8 + 472));
              memset((void *)(ipa3_ctx + 480LL * (int)v314 + 168), 0, 0x1E0u);
LABEL_471:
              v269 = *(unsigned int *)(a1 + 192);
              v319[1] = "ipa_dp.c";
              v319[2] = 1990;
              if ( (unsigned int)v269 <= 0x85 )
                v270 = ipa_clients_strings[v269];
              else
                v270 = "Invalid Client";
              v319[0] = v270;
              ipa3_dec_client_disable_clks();
              *v2 = -1;
              goto LABEL_475;
            }
          }
LABEL_281:
          v16 = -12;
          goto LABEL_459;
        }
        *(_DWORD *)(v107 + 20) = 0;
        *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v312 + 472) + 368LL) + 16LL) = *(_DWORD *)(*(_QWORD *)(v312 + 472) + 164LL)
                                                                         + 1;
        **(_QWORD **)(*(_QWORD *)(v312 + 472) + 368LL) = _kmalloc_noprof(
                                                           8LL
                                                         * *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(v312 + 472) + 368LL)
                                                                           + 16LL),
                                                           3520);
        v108 = *(_QWORD *)(*(_QWORD *)(v312 + 472) + 368LL);
        if ( *(_QWORD *)v108 )
        {
          *(_DWORD *)(v108 + 8) = 0;
          *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v312 + 472) + 368LL) + 12LL) = 0;
          ipa3_wq_repl_rx(*(_QWORD *)(v312 + 472) + 328LL);
        }
        else
        {
          printk(&unk_3A6869, "ipa_setup_sys_pipe");
          v142 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v143 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v143 )
            {
              ipc_log_string(v143, "ipa %s:%d ep=%d fail to alloc repl cache\n", "ipa_setup_sys_pipe", 1758, v6);
              v142 = ipa3_ctx;
            }
            v144 = *(_QWORD *)(v142 + 34160);
            if ( v144 )
              ipc_log_string(v144, "ipa %s:%d ep=%d fail to alloc repl cache\n", "ipa_setup_sys_pipe", 1758, v6);
          }
          *(_QWORD *)(*(_QWORD *)(v312 + 472) + 360LL) = &ipa3_replenish_rx_cache;
          *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v312 + 472) + 368LL) + 16LL) = 0;
        }
      }
      v109 = *(_QWORD *)(v312 + 472);
      if ( *(__int64 (__fastcall **)(_QWORD))(v109 + 360) != ipa3_replenish_rx_page_recycle )
        goto LABEL_323;
      if ( *(_BYTE *)(ipa3_ctx + 51104) == 1 && *(_DWORD *)(a1 + 192) == 35 && v10 != -1 )
      {
        if ( v10 <= 0x23 )
        {
          if ( *(_DWORD *)(ipa3_ctx + 168 + 480LL * (int)v10) == 1 )
          {
            v110 = ipa3_ctx + 168 + 480LL * (int)v10;
            *(_BYTE *)(v109 + 1609) = 1;
            v111 = *(_QWORD *)(v110 + 472);
            *(_QWORD *)(*(_QWORD *)(v312 + 472) + 1944LL) = v111;
            *(_QWORD *)(*(_QWORD *)(v312 + 472) + 368LL) = *(_QWORD *)(v111 + 368);
            *(_QWORD *)(*(_QWORD *)(v312 + 472) + 1784LL) = *(_QWORD *)(*(_QWORD *)(v110 + 472) + 1784LL);
            goto LABEL_323;
          }
          goto LABEL_225;
        }
LABEL_519:
        __break(0x5512u);
LABEL_520:
        __break(1u);
      }
LABEL_225:
      if ( !*(_QWORD *)(v109 + 1784) )
      {
        *(_QWORD *)(*(_QWORD *)(v312 + 472) + 1784LL) = _kmalloc_cache_noprof(
                                                          of_property_read_variable_u32_array,
                                                          3520,
                                                          24);
        v112 = *(_QWORD *)(*(_QWORD *)(v312 + 472) + 1784LL);
        if ( v112 )
        {
          *(_DWORD *)(v112 + 20) = 0;
          v113 = ipa3_ctx;
          v114 = *(_DWORD *)(a1 + 192);
          if ( *(_BYTE *)(ipa3_ctx + 51104) == 1 && v114 == 95 )
          {
            v115 = *(_DWORD *)(*(_QWORD *)(v312 + 472) + 164LL);
            v116 = rmnet_mem_config_query(1);
            v113 = ipa3_ctx;
            v117 = (v116 & 1) + *(_DWORD *)(ipa3_ctx + 48780) - 1;
            v118 = v117 + v117 * v115;
            v119 = *(_QWORD *)(v312 + 472);
          }
          else
          {
            v119 = *(_QWORD *)(v312 + 472);
            v123 = *(_DWORD *)(v119 + 164);
            if ( v114 == 121 )
              v118 = *(_DWORD *)(ipa3_ctx + 48788) + *(_DWORD *)(ipa3_ctx + 48788) * v123;
            else
              v118 = 2 * v123 + 2;
          }
          *(_DWORD *)(*(_QWORD *)(v119 + 1784) + 16LL) = v118;
          if ( v113 )
          {
            v130 = *(_QWORD *)(v113 + 34152);
            if ( v130 )
            {
              ipc_log_string(
                v130,
                "ipa %s:%d Page repl capacity for client:%d, value:%d\n",
                "ipa_setup_sys_pipe",
                1802,
                *(_DWORD *)(a1 + 192),
                *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v312 + 472) + 1784LL) + 16LL));
              v113 = ipa3_ctx;
            }
            v131 = *(_QWORD *)(v113 + 34160);
            if ( v131 )
              ipc_log_string(
                v131,
                "ipa %s:%d Page repl capacity for client:%d, value:%d\n",
                "ipa_setup_sys_pipe",
                1802,
                *(_DWORD *)(a1 + 192),
                *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v312 + 472) + 1784LL) + 16LL));
          }
          v132 = *(_QWORD **)(*(_QWORD *)(v312 + 472) + 1784LL);
          *v132 = v132;
          v132[1] = v132;
          *(_QWORD *)(*(_QWORD *)(v312 + 472) + 1800LL) = 0xFFFFFFFE00000LL;
          v133 = *(_QWORD *)(v312 + 472);
          *(_QWORD *)(v133 + 1808) = v133 + 1808;
          *(_QWORD *)(v133 + 1816) = v133 + 1808;
          *(_QWORD *)(*(_QWORD *)(v312 + 472) + 1824LL) = ipa3_schd_freepage_work;
          init_timer_key(*(_QWORD *)(v312 + 472) + 1832LL, &delayed_work_timer_fn, 0x200000, 0, 0);
          tasklet_init(*(_QWORD *)(v312 + 472) + 1904LL, ipa3_tasklet_find_freepage);
          v134 = *(_QWORD *)(v312 + 472);
          if ( *(_DWORD *)(*(_QWORD *)(v134 + 1784) + 16LL) )
          {
            v135 = 0;
            while ( 1 )
            {
              v136 = (_QWORD *)ipa3_alloc_rx_pkt_page(0, v134);
              if ( !v136 )
                break;
              *v136 = v136;
              v136[1] = v136;
              v136[10] = v134;
              v137 = *(_QWORD **)(v134 + 1784);
              v138 = (_QWORD *)v137[1];
              if ( v136 == v137 || v136 == v138 || (_QWORD *)*v138 != v137 )
              {
                _list_add_valid_or_report(v136, v138);
              }
              else
              {
                v137[1] = v136;
                *v136 = v137;
                v136[1] = v138;
                *v138 = v136;
              }
              if ( (unsigned int)++v135 >= *(_DWORD *)(*(_QWORD *)(v134 + 1784) + 16LL) )
                goto LABEL_301;
            }
            v154 = printk(&unk_3E3A54, "ipa3_replenish_rx_page_cache");
            v155 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v156 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v156 )
              {
                ipc_log_string(v156, "ipa %s:%d ipa3_alloc_rx_pkt_page fails\n", "ipa3_replenish_rx_page_cache", 2846);
                v155 = ipa3_ctx;
              }
              v154 = *(_QWORD *)(v155 + 34160);
              if ( v154 )
                v154 = ipc_log_string(
                         v154,
                         "ipa %s:%d ipa3_alloc_rx_pkt_page fails\n",
                         "ipa3_replenish_rx_page_cache",
                         2846);
            }
            ((void (__fastcall *)(__int64))ipa_assert)(v154);
          }
LABEL_301:
          *(_DWORD *)(*(_QWORD *)(v134 + 1944) + 1612LL) = 1;
          goto LABEL_302;
        }
        printk(&unk_3AF70E, "ipa_setup_sys_pipe");
        v145 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v146 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v146 )
          {
            ipc_log_string(
              v146,
              "ipa %s:%d failed to alloc repl for client %d\n",
              "ipa_setup_sys_pipe",
              1780,
              *(_DWORD *)(a1 + 192));
            v145 = ipa3_ctx;
          }
          v147 = *(_QWORD *)(v145 + 34160);
          if ( v147 )
          {
            ipc_log_string(
              v147,
              "ipa %s:%d failed to alloc repl for client %d\n",
              "ipa_setup_sys_pipe",
              1780,
              *(unsigned int *)(a1 + 192));
            goto LABEL_280;
          }
        }
        goto LABEL_281;
      }
      *(_DWORD *)(v109 + 1616) = 0;
      ipa3_tasklet_find_freepage(*(_QWORD *)(v312 + 472));
LABEL_302:
      *(_QWORD *)(*(_QWORD *)(v312 + 472) + 368LL) = _kmalloc_cache_noprof(
                                                       of_property_read_variable_u32_array,
                                                       3520,
                                                       24);
      v157 = *(_QWORD *)(v312 + 472);
      v158 = *(_QWORD *)(v157 + 368);
      if ( !v158 )
      {
        printk(&unk_3AF70E, "ipa_setup_sys_pipe");
        v227 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v228 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v228 )
          {
            ipc_log_string(
              v228,
              "ipa %s:%d failed to alloc repl for client %d\n",
              "ipa_setup_sys_pipe",
              1817,
              *(_DWORD *)(a1 + 192));
            v227 = ipa3_ctx;
          }
          v229 = *(_QWORD *)(v227 + 34160);
          if ( v229 )
            ipc_log_string(
              v229,
              "ipa %s:%d failed to alloc repl for client %d\n",
              "ipa_setup_sys_pipe",
              1817,
              *(_DWORD *)(a1 + 192));
        }
        v16 = -12;
        goto LABEL_456;
      }
      v159 = ipa3_ctx;
      if ( *(_BYTE *)(ipa3_ctx + 51104) == 1 && *(_DWORD *)(a1 + 192) == 95 )
        v160 = *(_DWORD *)(ipa3_ctx + 48784) + *(_DWORD *)(ipa3_ctx + 48784) * *(_DWORD *)(v157 + 164);
      else
        v160 = *(_DWORD *)(v157 + 164) + 1;
      *(_DWORD *)(v158 + 16) = v160;
      if ( v159 )
      {
        v161 = *(_QWORD *)(v159 + 34152);
        if ( v161 )
        {
          ipc_log_string(
            v161,
            "ipa %s:%d Repl capacity for client:%d, value:%d\n",
            "ipa_setup_sys_pipe",
            1829,
            *(_DWORD *)(a1 + 192),
            *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v312 + 472) + 368LL) + 16LL));
          v159 = ipa3_ctx;
        }
        v162 = *(_QWORD *)(v159 + 34160);
        if ( v162 )
          ipc_log_string(
            v162,
            "ipa %s:%d Repl capacity for client:%d, value:%d\n",
            "ipa_setup_sys_pipe",
            1829,
            *(_DWORD *)(a1 + 192),
            *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v312 + 472) + 368LL) + 16LL));
      }
      v163 = *(_DWORD *)(a1 + 192);
      if ( v163 == 95 || v163 == 35 )
      {
        pool_size = rmnet_mem_get_pool_size(*(unsigned int *)(*(_QWORD *)(v312 + 472) + 1604LL));
        if ( pool_size <= 0 )
          pool_size = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v312 + 472) + 368LL) + 16LL) >> 1;
        v165 = ipa3_ctx;
        *(_DWORD *)(ipa3_ctx + 48792) = pool_size;
        if ( v165 )
        {
          v166 = *(_QWORD *)(v165 + 34152);
          if ( v166 )
          {
            ipc_log_string(
              v166,
              "ipa %s:%d Temp pool capacity for client:%d, value:%u\n",
              "ipa_setup_sys_pipe",
              1839,
              *(_DWORD *)(a1 + 192),
              *(_DWORD *)(v165 + 48792));
            v165 = ipa3_ctx;
          }
          v167 = *(_QWORD *)(v165 + 34160);
          if ( v167 )
            ipc_log_string(
              v167,
              "ipa %s:%d Temp pool capacity for client:%d, value:%u\n",
              "ipa_setup_sys_pipe",
              1839,
              *(_DWORD *)(a1 + 192),
              *(_DWORD *)(v165 + 48792));
        }
        rmnet_mem_register_notifier(&ipa3_rmnet_mem_blk);
      }
      *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v312 + 472) + 368LL) + 20LL) = 0;
      **(_QWORD **)(*(_QWORD *)(v312 + 472) + 368LL) = _kmalloc_noprof(
                                                         8LL
                                                       * *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(v312 + 472) + 368LL)
                                                                         + 16LL),
                                                         3520);
      *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v312 + 472) + 368LL) + 8LL) = 0;
      *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v312 + 472) + 368LL) + 12LL) = 0;
      ipa3_wq_page_repl(*(_QWORD *)(v312 + 472) + 328LL);
LABEL_323:
      v168 = *(_DWORD *)(a1 + 192);
      v313 = v6;
      if ( v168 > 0x85 || (v168 & 1) == 0 )
        goto LABEL_363;
      v169 = (unsigned __int8)*(_DWORD *)(a1 + 192);
      if ( v169 != 35 && v169 != 95 && v169 != 121 )
      {
        v170 = *(_QWORD *)(v312 + 472);
LABEL_331:
        v171 = *(_DWORD *)v170;
        v172 = *(_DWORD *)(v170 + 164);
        if ( v172 - *(_DWORD *)v170 >= 0x14 )
        {
          memset(v319, 0, 0x360u);
          if ( v172 <= v171 )
          {
            v173 = 0;
            v174 = v171;
LABEL_358:
            v195 = gsi_queue_xfer(*(_QWORD *)(*(_QWORD *)(v170 + 1624) + 8LL), v173, v319, 1);
            if ( v195 )
            {
              v275 = v195;
              printk(&unk_3D5757, "ipa3_first_replenish_rx_cache");
              v276 = ipa3_ctx;
              v8 = v312;
              if ( ipa3_ctx )
              {
                v277 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v277 )
                {
                  ipc_log_string(
                    v277,
                    "ipa %s:%d failed to provide buffer: %d\n",
                    "ipa3_first_replenish_rx_cache",
                    3487,
                    v275);
                  v276 = ipa3_ctx;
                }
                v278 = *(_QWORD *)(v276 + 34160);
                if ( v278 )
                  ipc_log_string(
                    v278,
                    "ipa %s:%d failed to provide buffer: %d\n",
                    "ipa3_first_replenish_rx_cache",
                    3487,
                    v275);
              }
              __break(0x800u);
              goto LABEL_361;
            }
            *(_DWORD *)v170 = v174;
          }
          else
          {
            v173 = 0;
            _ReadStatusReg(SP_EL0);
            while ( 1 )
            {
              v174 = v171;
              v175 = (_QWORD *)kmem_cache_alloc_noprof(*(_QWORD *)(ipa3_ctx + 29448), 10496);
              v176 = v175;
              if ( !v175 )
                break;
              v175[6] = 0xFFFFFFFE00000LL;
              v175[7] = v175 + 7;
              v175[8] = v175 + 7;
              v175[9] = ipa3_wq_rx_avail;
              v175[10] = v170;
              v177 = *(__int64 (__fastcall **)(__int64, __int64))(v170 + 136);
              v178 = *(unsigned int *)(v170 + 160);
              if ( *((_DWORD *)v177 - 1) != 993109518 )
                __break(0x8228u);
              v179 = v177(v178, 10240);
              v176[2] = v179;
              if ( !v179 )
              {
                printk(&unk_3CC773, "ipa3_first_replenish_rx_cache");
                v279 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v280 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v280 )
                  {
                    ipc_log_string(v280, "ipa %s:%d failed to alloc skb\n", "ipa3_first_replenish_rx_cache", 3428);
                    v279 = ipa3_ctx;
                  }
                  v281 = *(_QWORD *)(v279 + 34160);
                  if ( v281 )
                    ipc_log_string(v281, "ipa %s:%d failed to alloc skb\n", "ipa3_first_replenish_rx_cache", 3428);
                }
                goto LABEL_503;
              }
              v180 = skb_put(v179, *(unsigned int *)(v170 + 160));
              v181 = *(unsigned int *)(v170 + 160);
              v182 = v180;
              v183 = *(const char ***)(ipa3_ctx + 34216);
              v184 = is_vmalloc_addr(v180);
              v185 = v184;
              if ( (v184 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
              {
                dma_map_single_attrs___already_done = 1;
                v190 = (const char *)dev_driver_string(v183);
                v191 = v183[14];
                if ( !v191 )
                  v191 = *v183;
                _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v190, v191);
                __break(0x800u);
                if ( (v185 & 1) != 0 )
                {
LABEL_494:
                  v176[3] = -1;
                  v282 = (const void **)(v176 + 3);
LABEL_495:
                  printk(&unk_3D288A, "ipa3_first_replenish_rx_cache");
                  v283 = ipa3_ctx;
                  if ( ipa3_ctx )
                  {
                    v284 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v284 )
                    {
                      ipc_log_string(
                        v284,
                        "ipa %s:%d dma_map_single failure %pK for %pK\n",
                        "ipa3_first_replenish_rx_cache",
                        3437,
                        *v282,
                        (const void *)v182);
                      v283 = ipa3_ctx;
                    }
                    v285 = *(_QWORD *)(v283 + 34160);
                    if ( v285 )
                      ipc_log_string(
                        v285,
                        "ipa %s:%d dma_map_single failure %pK for %pK\n",
                        "ipa3_first_replenish_rx_cache",
                        3437,
                        *v282,
                        (const void *)v182);
                  }
                  v286 = *(void (__fastcall **)(_QWORD))(v170 + 144);
                  v287 = v176[2];
                  if ( *((_DWORD *)v286 - 1) != 303786302 )
                    __break(0x8228u);
                  v286(v287);
                  v6 = v313;
LABEL_503:
                  kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29448), v176);
                  goto LABEL_504;
                }
              }
              else if ( (v184 & 1) != 0 )
              {
                goto LABEL_494;
              }
              v186 = dma_map_page_attrs(
                       v183,
                       ((unsigned __int64)((v182 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                       v182 & 0xFFF,
                       v181,
                       2,
                       0);
              v176[3] = v186;
              if ( v186 == -1 )
              {
                v282 = (const void **)(v176 + 3);
                goto LABEL_495;
              }
              if ( v173 > 0x23 )
                goto LABEL_520;
              v6 = v313;
              v187 = &v319[3 * v173++];
              *v187 = v186;
              v188 = *(_DWORD *)(v170 + 160);
              *((_WORD *)v187 + 5) = 1792;
              *((_DWORD *)v187 + 3) = 0;
              *((_WORD *)v187 + 4) = v188;
              v187[2] = (__int64)v176;
              if ( v173 == 36 )
              {
                v189 = gsi_queue_xfer(*(_QWORD *)(*(_QWORD *)(v170 + 1624) + 8LL), 36, v319, 0);
                v173 = 0;
                if ( v189 )
                {
                  v288 = v189;
                  printk(&unk_3D5757, "ipa3_first_replenish_rx_cache");
                  v289 = ipa3_ctx;
                  ++v174;
                  if ( ipa3_ctx )
                  {
                    v290 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v290 )
                    {
                      ipc_log_string(
                        v290,
                        "ipa %s:%d failed to provide buffer: %d\n",
                        "ipa3_first_replenish_rx_cache",
                        3459,
                        v288);
                      v289 = ipa3_ctx;
                    }
                    v291 = *(_QWORD *)(v289 + 34160);
                    if ( v291 )
                      ipc_log_string(
                        v291,
                        "ipa %s:%d failed to provide buffer: %d\n",
                        "ipa3_first_replenish_rx_cache",
                        3459,
                        v288);
                  }
                  __break(0x800u);
                  v173 = 36;
                  goto LABEL_358;
                }
              }
              v171 = v174 + 1;
              if ( (unsigned int)(v174 + 1) >= *(_DWORD *)(v170 + 164) )
              {
                ++v174;
                goto LABEL_358;
              }
            }
            printk(&unk_3FDD40, "ipa3_first_replenish_rx_cache");
            v192 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v193 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v193 )
              {
                ipc_log_string(v193, "ipa %s:%d failed to alloc cache\n", "ipa3_first_replenish_rx_cache", 3419);
                v192 = ipa3_ctx;
              }
              v194 = *(_QWORD *)(v192 + 34160);
              if ( v194 )
                ipc_log_string(v194, "ipa %s:%d failed to alloc cache\n", "ipa3_first_replenish_rx_cache", 3419);
            }
LABEL_504:
            if ( v174 > 19 )
              goto LABEL_358;
            queue_delayed_work_on(32, *(_QWORD *)(v170 + 1752), v170 + 224, 1);
          }
          v8 = v312;
        }
LABEL_361:
        v2 = v311;
        goto LABEL_362;
      }
      v170 = *(_QWORD *)(v312 + 472);
      if ( *(_BYTE *)(ipa3_ctx + 45386) != 1 )
        goto LABEL_331;
      ipa3_replenish_rx_page_recycle(*(_QWORD *)(v312 + 472));
LABEL_362:
      v196 = *(_QWORD *)(v8 + 472);
      *(_QWORD *)(v196 + 392) = v196 + 392;
      *(_QWORD *)(v196 + 400) = v196 + 392;
      v197 = *(_QWORD *)(v8 + 472);
      *(_QWORD *)(v197 + 408) = v197 + 408;
      *(_QWORD *)(v197 + 416) = v197 + 408;
      v198 = *(_QWORD *)(v8 + 472);
      *(_QWORD *)(v198 + 424) = v198 + 424;
      *(_QWORD *)(v198 + 432) = v198 + 424;
      v199 = *(_QWORD *)(v8 + 472);
      *(_QWORD *)(v199 + 440) = v199 + 440;
      *(_QWORD *)(v199 + 448) = v199 + 440;
      v200 = *(_QWORD *)(v8 + 472);
      *(_QWORD *)(v200 + 456) = v200 + 456;
      *(_QWORD *)(v200 + 464) = v200 + 456;
      v201 = *(_QWORD *)(v8 + 472);
      *(_QWORD *)(v201 + 472) = v201 + 472;
      *(_QWORD *)(v201 + 480) = v201 + 472;
      v202 = *(_QWORD *)(v8 + 472);
      *(_QWORD *)(v202 + 488) = v202 + 488;
      *(_QWORD *)(v202 + 496) = v202 + 488;
      v203 = *(_QWORD *)(v8 + 472);
      *(_QWORD *)(v203 + 504) = v203 + 504;
      *(_QWORD *)(v203 + 512) = v203 + 504;
      v204 = *(_QWORD *)(v8 + 472);
      *(_QWORD *)(v204 + 520) = v204 + 520;
      *(_QWORD *)(v204 + 528) = v204 + 520;
      v205 = *(_QWORD *)(v8 + 472);
      *(_QWORD *)(v205 + 536) = v205 + 536;
      *(_QWORD *)(v205 + 544) = v205 + 536;
      v206 = *(_QWORD *)(v8 + 472);
      *(_QWORD *)(v206 + 552) = v206 + 552;
      *(_QWORD *)(v206 + 560) = v206 + 552;
      v207 = *(_QWORD *)(v8 + 472);
      *(_QWORD *)(v207 + 568) = v207 + 568;
      *(_QWORD *)(v207 + 576) = v207 + 568;
      v208 = *(_QWORD *)(v8 + 472);
      *(_QWORD *)(v208 + 584) = v208 + 584;
      *(_QWORD *)(v208 + 592) = v208 + 584;
      v209 = *(_QWORD *)(v8 + 472);
      *(_QWORD *)(v209 + 600) = v209 + 600;
      *(_QWORD *)(v209 + 608) = v209 + 600;
      v210 = *(_QWORD *)(v8 + 472);
      *(_QWORD *)(v210 + 616) = v210 + 616;
      *(_QWORD *)(v210 + 624) = v210 + 616;
      v211 = *(_QWORD *)(v8 + 472);
      *(_QWORD *)(v211 + 632) = v211 + 632;
      *(_QWORD *)(v211 + 640) = v211 + 632;
      v212 = *(_QWORD *)(v8 + 472);
      *(_QWORD *)(v212 + 648) = v212 + 648;
      *(_QWORD *)(v212 + 656) = v212 + 648;
      v168 = *(_DWORD *)(a1 + 192);
LABEL_363:
      if ( v168 <= 0x11 && ((1 << v168) & 0x2A800) != 0 || v168 == 119 )
      {
        if ( *(_DWORD *)(ipa3_ctx + 34616) <= 0x63u )
        {
          _ReadStatusReg(SP_EL0);
          while ( 1 )
          {
            v213 = (__int64 *)kmem_cache_alloc_noprof(*(_QWORD *)(ipa3_ctx + 29448), 10496);
            if ( !v213 )
              goto LABEL_404;
            *v213 = (__int64)v213;
            v213[1] = (__int64)v213;
            v213[6] = 0xFFFFFFFE00000LL;
            v213[7] = (__int64)(v213 + 7);
            v213[8] = (__int64)(v213 + 7);
            v213[9] = (__int64)ipa3_wq_rx_avail;
            v214 = _netdev_alloc_skb(0, 2048, 10240);
            v213[2] = v214;
            if ( !v214 )
              break;
            v215 = skb_put(v214, 2048);
            v216 = *(const char ***)(ipa3_ctx + 34216);
            v217 = is_vmalloc_addr(v215);
            if ( (v217 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
            {
              v310 = v217;
              dma_map_single_attrs___already_done = 1;
              v225 = (const char *)dev_driver_string(v216);
              v226 = v216[14];
              if ( !v226 )
                v226 = *v216;
              _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v225, v226);
              __break(0x800u);
              if ( (v310 & 1) != 0 )
              {
LABEL_396:
                v213[3] = -1;
                v233 = (const void **)(v213 + 3);
                goto LABEL_397;
              }
            }
            else if ( (v217 & 1) != 0 )
            {
              goto LABEL_396;
            }
            v218 = dma_map_page_attrs(
                     v216,
                     ((unsigned __int64)((v215 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
                     v215 & 0xFFF,
                     2048,
                     2,
                     0);
            v213[3] = v218;
            if ( v218 == -1 )
            {
              v233 = (const void **)(v213 + 3);
LABEL_397:
              printk(&unk_3D288A, "ipa3_alloc_wlan_rx_common_cache");
              v234 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v235 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v235 )
                {
                  ipc_log_string(
                    v235,
                    "ipa %s:%d dma_map_single failure %pK for %pK\n",
                    "ipa3_alloc_wlan_rx_common_cache",
                    3362,
                    *v233,
                    (const void *)v215);
                  v234 = ipa3_ctx;
                }
                v236 = *(_QWORD *)(v234 + 34160);
                if ( v236 )
                  ipc_log_string(
                    v236,
                    "ipa %s:%d dma_map_single failure %pK for %pK\n",
                    "ipa3_alloc_wlan_rx_common_cache",
                    3362,
                    *v233,
                    (const void *)v215);
              }
              dev_kfree_skb_any_reason(v213[2], 2);
LABEL_403:
              kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29448), v213);
              goto LABEL_404;
            }
            raw_spin_lock_bh(ipa3_ctx + 34608);
            v219 = ipa3_ctx + 34632;
            v220 = *(__int64 **)(ipa3_ctx + 34640);
            if ( v213 == (__int64 *)(ipa3_ctx + 34632) || v213 == v220 || *v220 != v219 )
            {
              _list_add_valid_or_report(v213, v220);
            }
            else
            {
              *(_QWORD *)(ipa3_ctx + 34640) = v213;
              *v213 = v219;
              v213[1] = (__int64)v220;
              *v220 = (__int64)v213;
            }
            v221 = ipa3_ctx;
            v222 = ipa3_ctx + 34608;
            v223 = *(_DWORD *)(ipa3_ctx + 34616) + 1;
            v224 = *(_DWORD *)(ipa3_ctx + 34620) + 1;
            *(_DWORD *)(ipa3_ctx + 34616) = v223;
            *(_DWORD *)(v221 + 34620) = v224;
            raw_spin_unlock_bh(v222);
            if ( v223 >= 0x64 )
              goto LABEL_404;
          }
          printk(&unk_3CC773, "ipa3_alloc_wlan_rx_common_cache");
          v230 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v231 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v231 )
            {
              ipc_log_string(v231, "ipa %s:%d failed to alloc skb\n", "ipa3_alloc_wlan_rx_common_cache", 3354);
              v230 = ipa3_ctx;
            }
            v232 = *(_QWORD *)(v230 + 34160);
            if ( v232 )
              ipc_log_string(v232, "ipa %s:%d failed to alloc skb\n", "ipa3_alloc_wlan_rx_common_cache", 3354);
          }
          goto LABEL_403;
        }
LABEL_404:
        _X8 = (unsigned int *)(ipa3_ctx + 34648);
        __asm { PRFM            #0x11, [X8] }
        do
          v296 = __ldxr(_X8);
        while ( __stxr(v296 + 1, _X8) );
        v2 = v311;
        v8 = v312;
        v6 = v313;
      }
      v238 = *(_BYTE *)(v8 + 404);
      *(_BYTE *)(ipa3_ctx + v314 + 17448) = v238;
      if ( (v238 & 1) == 0 )
      {
        v239 = *(_DWORD *)(a1 + 192);
        if ( v239 <= 0x85 && (v239 & 1) == 0 )
        {
          v240 = ipa3_ctx;
          if ( *(_BYTE *)(ipa3_ctx + 32262) == 1
            && ((v241 = (unsigned __int8)*(_DWORD *)(a1 + 192), v241 == 120) || v241 == 34) )
          {
            if ( ipa3_ctx )
            {
              v242 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v242 )
              {
                ipc_log_string(v242, "ipa %s:%d modem cfg emb pipe flt\n", "ipa_setup_sys_pipe", 1882);
                v240 = ipa3_ctx;
              }
              v243 = *(_QWORD *)(v240 + 34160);
              if ( v243 )
                ipc_log_string(v243, "ipa %s:%d modem cfg emb pipe flt\n", "ipa_setup_sys_pipe", 1882);
            }
          }
          else
          {
            ipa3_install_dflt_flt_rules(v6);
          }
        }
      }
      v244 = ipa3_enable_data_path(v6);
      if ( v244 )
      {
        v16 = v244;
        printk(&unk_3AC989, "ipa_setup_sys_pipe");
        v253 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v254 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v254 )
          {
            ipc_log_string(
              v254,
              "ipa %s:%d enable data path failed res=%d ep=%d.\n",
              "ipa_setup_sys_pipe",
              1890,
              v16,
              v6);
            v253 = ipa3_ctx;
          }
          v255 = *(_QWORD *)(v253 + 34160);
          if ( v255 )
            ipc_log_string(
              v255,
              "ipa %s:%d enable data path failed res=%d ep=%d.\n",
              "ipa_setup_sys_pipe",
              1890,
              v16,
              v6);
        }
        goto LABEL_449;
      }
      started = gsi_start_channel(*(_QWORD *)(v8 + 8));
      if ( (_DWORD)started )
      {
        v16 = started;
        printk(&unk_3A6895, "ipa_setup_sys_pipe");
        v256 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v257 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v257 )
          {
            ipc_log_string(
              v257,
              "ipa %s:%d gsi_start_channel failed res=%d ep=%d.\n",
              "ipa_setup_sys_pipe",
              1897,
              v16,
              v6);
            v256 = ipa3_ctx;
          }
          v258 = *(_QWORD *)(v256 + 34160);
          if ( v258 )
            ipc_log_string(
              v258,
              "ipa %s:%d gsi_start_channel failed res=%d ep=%d.\n",
              "ipa_setup_sys_pipe",
              1897,
              v16,
              v6);
        }
        ipa3_disable_data_path(v6);
LABEL_449:
        v259 = *(_DWORD *)(v8 + 4);
        v260 = *(_QWORD *)(v8 + 472);
        if ( v259 <= 0x85 && (v259 & 1) != 0 && (*(_BYTE *)(v260 + 1609) & 1) == 0 )
        {
          ipa3_cleanup_rx();
          v260 = *(_QWORD *)(v8 + 472);
        }
        *(_QWORD *)(v260 + 360) = &ipa3_replenish_rx_cache;
        v261 = *(_QWORD *)(v8 + 472);
        v262 = *(_QWORD *)(v261 + 368);
        if ( v262 && (*(_BYTE *)(v261 + 1609) & 1) == 0 )
        {
          kfree(v262);
          *(_QWORD *)(*(_QWORD *)(v8 + 472) + 368LL) = 0;
        }
LABEL_456:
        v263 = *(_QWORD *)(v8 + 472);
        v264 = *(_QWORD *)(v263 + 1784);
        if ( v264 && (*(_BYTE *)(v263 + 1609) & 1) == 0 )
        {
          kfree(v264);
          *(_QWORD *)(*(_QWORD *)(v8 + 472) + 1784LL) = 0;
        }
        goto LABEL_459;
      }
      v246 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v247 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v247 )
        {
          ipc_log_string(
            v247,
            "ipa %s:%d client %d (ep: %d) connected sys=%pK\n",
            "ipa_setup_sys_pipe",
            1902,
            *(_DWORD *)(a1 + 192),
            v6,
            *(const void **)(v8 + 472));
          v246 = ipa3_ctx;
        }
        started = *(_QWORD *)(v246 + 34160);
        if ( started )
          started = ipc_log_string(
                      started,
                      "ipa %s:%d client %d (ep: %d) connected sys=%pK\n",
                      "ipa_setup_sys_pipe",
                      1902,
                      *(_DWORD *)(a1 + 192),
                      v6,
                      *(const void **)(v8 + 472));
      }
      v248 = *(_DWORD *)(a1 + 192);
      if ( v248 == 127 )
      {
        if ( (*(_BYTE *)(a1 + 248) & 1) == 0 )
        {
          *(_DWORD *)(a1 + 192) = 33;
          memcpy((void *)a1, dest, 0xC0u);
          v249 = "lan";
          v250 = (char *)&v317;
          *(_QWORD *)(a1 + 208) = ipa3_lan_rx_cb;
          goto LABEL_430;
        }
      }
      else
      {
        if ( v248 != 95 )
          goto LABEL_432;
        v316 = 0;
        started = ((__int64 (__fastcall *)(__int64, _QWORD, int *))ipahal_write_reg_n_fields)(129, 0, &v316);
        if ( (*(_BYTE *)(a1 + 248) & 1) == 0 )
        {
          *(_DWORD *)(a1 + 192) = 35;
          memcpy((void *)a1, dest, 0xC0u);
          v249 = (const char *)&unk_3C3B6C;
          v250 = (char *)&v317 + 4;
LABEL_430:
          started = ipa_setup_sys_pipe(a1, v250);
          if ( !(_DWORD)started )
            goto LABEL_431;
          v16 = started;
          printk(&unk_3F4FB8, "ipa_setup_sys_pipe");
          v272 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_482;
          v273 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v273 )
          {
            ipc_log_string(
              v273,
              "ipa %s:%d Failed to setup default %s coalescing pipe\n",
              "ipa_setup_sys_pipe",
              1940,
              v249);
            v272 = ipa3_ctx;
          }
          v274 = *(_QWORD *)(v272 + 34160);
          if ( v274 )
          {
            ipc_log_string(
              v274,
              "ipa %s:%d Failed to setup default %s coalescing pipe\n",
              "ipa_setup_sys_pipe",
              1940,
              v249);
            v2 = v311;
          }
          else
          {
LABEL_482:
            v2 = v311;
          }
          goto LABEL_449;
        }
      }
LABEL_431:
      ipa3_default_evict_register(started);
LABEL_432:
      if ( (*(_BYTE *)(v8 + 405) & 1) != 0 )
      {
        v16 = 0;
      }
      else
      {
        v319[1] = "ipa_dp.c";
        v319[2] = 1948;
        v251 = *(unsigned int *)(v8 + 4);
        if ( (unsigned int)v251 <= 0x85 )
          v252 = ipa_clients_strings[v251];
        else
          v252 = "Invalid Client";
        v319[0] = v252;
        ipa3_dec_client_disable_clks();
        v16 = 0;
      }
LABEL_476:
      _ReadStatusReg(SP_EL0);
      return v16;
    case 39:
    case 41:
      if ( ipa3_ctx )
      {
        v82 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v82 )
        {
          ipc_log_string(v82, "ipa %s:%d assigning policy to client:%d", "ipa3_assign_policy", 6003, v57);
          v59 = ipa3_ctx;
        }
        v83 = *(_QWORD *)(v59 + 34160);
        if ( v83 )
          ipc_log_string(
            v83,
            "ipa %s:%d assigning policy to client:%d",
            "ipa3_assign_policy",
            6003,
            *(_DWORD *)(a1 + 192));
      }
      *(_DWORD *)(v56 + 120) = 2;
      *(_QWORD *)(v56 + 192) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v56 + 200) = v56 + 200;
      *(_QWORD *)(v56 + 208) = v56 + 200;
      *(_QWORD *)(v56 + 216) = ipa3_wq_handle_rx;
      *(_QWORD *)(v56 + 16) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v56 + 24) = v56 + 24;
      *(_QWORD *)(v56 + 32) = v56 + 24;
      *(_QWORD *)(v56 + 40) = ipa3_switch_to_intr_rx_work_func;
      init_timer_key(v56 + 48, &delayed_work_timer_fn, 0x200000, 0, 0);
      *(_QWORD *)(v56 + 224) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v56 + 232) = v56 + 232;
      *(_QWORD *)(v56 + 240) = v56 + 232;
      *(_QWORD *)(v56 + 248) = ipa3_replenish_rx_work_func;
      init_timer_key(v56 + 256, &delayed_work_timer_fn, 0x200000, 0, 0);
      *(_DWORD *)(v56 + 4) = 0;
      v84 = *(_DWORD *)(a1 + 196);
      *(_QWORD *)(v56 + 128) = ipa3_odu_rx_pyld_hdlr;
      *(_QWORD *)(v56 + 136) = ipa3_get_skb_ipa_rx;
      v85 = (v84 >> 3) - 1;
      if ( v85 >= 0x40 )
        v85 = 64;
      *(_DWORD *)(v56 + 164) = v85;
      v86 = ipa3_ctx;
      *(_QWORD *)(v56 + 144) = ipa_free_skb_rx;
      LODWORD(v86) = *(_DWORD *)(v86 + 32240);
      *(_QWORD *)(v56 + 152) = ipa3_free_rx_wrapper;
      *(_QWORD *)(v56 + 360) = &ipa3_replenish_rx_cache;
      if ( (unsigned int)v86 >= 0xE )
      {
        *(_DWORD *)(v56 + 160) = 15936;
        *(_DWORD *)(a1 + 104) = 14;
      }
      else
      {
        *(_DWORD *)(v56 + 160) = 2048;
      }
      goto LABEL_194;
    case 45:
      if ( ipa3_ctx )
      {
        v96 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v96 )
        {
          ipc_log_string(v96, "ipa %s:%d assigning policy to client:%d", "ipa3_assign_policy", 6048, 45);
          v59 = ipa3_ctx;
        }
        v97 = *(_QWORD *)(v59 + 34160);
        if ( v97 )
          ipc_log_string(
            v97,
            "ipa %s:%d assigning policy to client:%d",
            "ipa3_assign_policy",
            6048,
            *(_DWORD *)(a1 + 192));
      }
      goto LABEL_193;
    case 47:
      if ( ipa3_ctx )
      {
        v150 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v150 )
        {
          ipc_log_string(v150, "ipa %s:%d assigning policy to client:%d", "ipa3_assign_policy", 6039, 47);
          v59 = ipa3_ctx;
        }
        v151 = *(_QWORD *)(v59 + 34160);
        if ( v151 )
          ipc_log_string(
            v151,
            "ipa %s:%d assigning policy to client:%d",
            "ipa3_assign_policy",
            6039,
            *(_DWORD *)(a1 + 192));
      }
      *(_DWORD *)(v56 + 120) = 2;
      *(_QWORD *)(v56 + 192) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v56 + 200) = v56 + 200;
      *(_QWORD *)(v56 + 208) = v56 + 200;
      *(_QWORD *)(v56 + 216) = ipa3_wq_handle_rx;
      *(_QWORD *)(v56 + 16) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v56 + 24) = v56 + 24;
      *(_QWORD *)(v56 + 32) = v56 + 24;
      *(_QWORD *)(v56 + 40) = ipa3_switch_to_intr_rx_work_func;
      init_timer_key(v56 + 48, &delayed_work_timer_fn, 0x200000, 0, 0);
      goto LABEL_194;
    case 83:
      if ( ipa3_ctx )
      {
        v148 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v148 )
        {
          ipc_log_string(v148, "ipa %s:%d assigning policy to ODL client:%d\n", "ipa3_assign_policy", 6053, 83);
          v59 = ipa3_ctx;
        }
        v149 = *(_QWORD *)(v59 + 34160);
        if ( v149 )
        {
          ipc_log_string(
            v149,
            "ipa %s:%d assigning policy to ODL client:%d\n",
            "ipa3_assign_policy",
            6053,
            *(_DWORD *)(a1 + 192));
          v59 = ipa3_ctx;
        }
      }
      *(_BYTE *)(*(_QWORD *)(v56 + 1624) + 352LL) = *(_DWORD *)(v59 + 32240) < 0x11u;
      *(_DWORD *)(v56 + 120) = 2;
      *(_QWORD *)(v56 + 192) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v56 + 200) = v56 + 200;
      *(_QWORD *)(v56 + 208) = v56 + 200;
      *(_QWORD *)(v56 + 216) = ipa3_wq_handle_rx;
      *(_QWORD *)(v56 + 16) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v56 + 24) = v56 + 24;
      *(_QWORD *)(v56 + 32) = v56 + 24;
      *(_QWORD *)(v56 + 40) = ipa3_switch_to_intr_rx_work_func;
      init_timer_key(v56 + 48, &delayed_work_timer_fn, 0x200000, 0, 0);
      *(_QWORD *)(v56 + 224) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v56 + 232) = v56 + 232;
      *(_QWORD *)(v56 + 240) = v56 + 232;
      *(_QWORD *)(v56 + 248) = ipa3_replenish_rx_work_func;
      init_timer_key(v56 + 256, &delayed_work_timer_fn, 0x200000, 0, 0);
      *(_DWORD *)(v56 + 4) = 0;
      *(_DWORD *)(v56 + 160) = 15936;
      *(_QWORD *)(v56 + 128) = ipa3_odl_dpl_rx_pyld_hdlr;
      *(_QWORD *)(v56 + 136) = ipa3_get_skb_ipa_rx;
      *(_QWORD *)(v56 + 144) = ipa_free_skb_rx;
      *(_QWORD *)(v56 + 152) = ipa3_recycle_rx_wrapper;
      *(_QWORD *)(v56 + 360) = &ipa3_replenish_rx_cache_recycle;
      *(_DWORD *)(v56 + 164) = (*(_DWORD *)(a1 + 196) >> 3) - 1;
      goto LABEL_194;
    default:
      _warn_printk("Need to install a RX pipe hdlr\n");
      __break(0x800u);
      printk(&unk_3EEDF6, "ipa_setup_sys_pipe");
      v292 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v293 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v293 )
        {
          ipc_log_string(
            v293,
            "ipa %s:%d failed to sys ctx for client %d\n",
            "ipa_setup_sys_pipe",
            1700,
            *(_DWORD *)(a1 + 192));
          v292 = ipa3_ctx;
        }
        v294 = *(_QWORD *)(v292 + 34160);
        if ( v294 )
          ipc_log_string(
            v294,
            "ipa %s:%d failed to sys ctx for client %d\n",
            "ipa_setup_sys_pipe",
            1700,
            *(_DWORD *)(a1 + 192));
        v8 = v312;
        v16 = -12;
      }
      else
      {
        v8 = v312;
        v16 = -12;
      }
      goto LABEL_459;
  }
}
