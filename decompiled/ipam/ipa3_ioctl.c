__int64 __fastcall ipa3_ioctl(__int64 a1, int a2, __int64 a3)
{
  void *v5; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int v9; // w20
  __int64 v10; // x22
  unsigned __int8 *v11; // x0
  unsigned __int8 *v12; // x24
  unsigned int v13; // w20
  __int64 v14; // x2
  __int64 result; // x0
  unsigned int is_vlan_mode; // w0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  int v20; // w0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  unsigned int v25; // w0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x1
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x8
  __int64 v42; // x0
  __int64 v43; // x8
  __int64 v44; // x0
  const char *v45; // x4
  __int64 v46; // x0
  const char *v47; // x4
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v50; // x8
  __int64 v51; // x0
  __int64 v52; // x8
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x8
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x8
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x8
  __int64 v62; // x0
  __int64 v63; // x8
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x8
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x8
  __int64 v70; // x0
  __int64 v71; // x0
  unsigned int v72; // w20
  __int64 v73; // x21
  int v74; // w0
  __int64 v75; // x8
  __int64 v76; // x0
  __int64 v77; // x8
  __int64 v78; // x0
  int inited; // w0
  unsigned int v80; // w20
  __int64 v81; // x21
  unsigned int v82; // w20
  __int64 v83; // x22
  __int64 v84; // x20
  unsigned __int8 *v85; // x21
  __int64 v86; // x2
  unsigned int v87; // w20
  bool v88; // zf
  __int64 v89; // x8
  __int64 v90; // x0
  _QWORD *v91; // x1
  __int64 v92; // x0
  __int64 v93; // x2
  unsigned int v94; // w20
  __int64 v95; // x22
  unsigned int v96; // w20
  __int64 v97; // x22
  int v98; // w0
  unsigned int v99; // w20
  unsigned int v100; // w20
  __int64 v101; // x22
  unsigned int v102; // w20
  __int64 v103; // x22
  int v104; // w0
  unsigned int v105; // w20
  unsigned int v106; // w20
  __int64 v107; // x22
  int v108; // w0
  unsigned int v109; // w20
  int v110; // w20
  unsigned int v111; // w20
  __int64 v112; // x0
  unsigned __int8 *v113; // x1
  unsigned __int8 *v114; // x1
  __int64 v115; // x0
  int v116; // w8
  unsigned int v117; // w20
  __int64 v118; // x8
  unsigned int v119; // w20
  int v120; // w8
  __int64 *v121; // x1
  __int64 v122; // x0
  __int64 v123; // x2
  __int64 v124; // x0
  __int64 v125; // x19
  __int64 v126; // x8
  __int64 v127; // x0
  __int64 v128; // x0
  __int64 v129; // x20
  __int64 v130; // x0
  __int64 v131; // x21
  __int64 v132; // x8
  __int64 v133; // x0
  __int64 v134; // x0
  __int64 v135; // x8
  __int64 v136; // x0
  __int64 v137; // x8
  __int64 v138; // x0
  __int64 v139; // x8
  char v140; // w0
  __int64 v141; // x8
  __int64 v142; // x0
  __int64 v143; // x8
  __int64 v144; // x0
  __int64 v145; // x8
  __int64 v146; // x8
  __int64 v147; // x0
  __int64 v148; // x8
  __int64 v149; // x8
  __int64 v150; // x0
  __int64 v151; // x8
  __int64 v152; // x0
  __int64 v153; // x8
  __int64 v154; // x0
  __int64 v155; // x8
  __int64 v156; // x0
  __int64 v157; // x8
  __int64 v158; // x8
  __int64 v159; // x0
  __int64 v160; // x8
  __int64 v161; // x8
  __int64 v162; // x0
  __int64 v163; // x8
  __int64 v164; // x0
  __int64 v165; // x0
  __int64 v166; // x8
  __int64 v167; // x0
  __int64 v168; // x0
  __int64 v169; // x8
  __int64 v170; // x0
  __int64 v171; // x0
  __int64 v172; // x8
  __int64 v173; // x0
  __int64 v174; // x0
  __int64 v175; // x8
  __int64 v176; // x0
  __int64 v177; // x0
  __int64 v178; // x8
  __int64 v179; // x0
  __int64 v180; // x0
  __int64 v181; // x8
  __int64 v182; // x0
  __int64 v183; // x0
  __int64 v184; // x8
  __int64 v185; // x0
  __int64 v186; // x0
  __int64 v187; // x8
  __int64 v188; // x0
  __int64 v189; // x0
  __int64 v190; // x8
  __int64 v191; // x0
  __int64 v192; // x0
  __int64 v193; // x8
  __int64 v194; // x0
  __int64 v195; // x0
  __int64 v196; // x8
  __int64 v197; // x0
  __int64 v198; // x0
  __int64 v199; // x8
  __int64 v200; // x0
  __int64 v201; // x0
  __int64 v202; // x8
  __int64 v203; // x0
  __int64 v204; // x0
  __int64 v205; // x8
  __int64 v206; // x0
  __int64 v207; // x0
  __int64 v208; // x8
  __int64 v209; // x0
  __int64 v210; // x0
  __int64 v211; // x8
  __int64 v212; // x0
  __int64 v213; // x0
  __int64 v214; // x8
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
  __int64 v227; // x8
  __int64 v228; // x0
  __int64 v229; // [xsp+8h] [xbp-4F8h] BYREF
  __int64 v230; // [xsp+10h] [xbp-4F0h]
  __int64 v231; // [xsp+18h] [xbp-4E8h]
  __int64 v232; // [xsp+20h] [xbp-4E0h]
  _BYTE v233[4]; // [xsp+28h] [xbp-4D8h] BYREF
  _BYTE v234[4]; // [xsp+2Ch] [xbp-4D4h] BYREF
  int v235[2]; // [xsp+30h] [xbp-4D0h] BYREF
  __int64 v236; // [xsp+38h] [xbp-4C8h]
  __int64 v237; // [xsp+40h] [xbp-4C0h] BYREF
  _QWORD v238[2]; // [xsp+48h] [xbp-4B8h] BYREF
  _WORD v239[2]; // [xsp+5Ch] [xbp-4A4h] BYREF
  __int64 v240; // [xsp+60h] [xbp-4A0h] BYREF
  _QWORD v241[2]; // [xsp+68h] [xbp-498h] BYREF
  _QWORD v242[4]; // [xsp+78h] [xbp-488h] BYREF
  __int64 v243; // [xsp+98h] [xbp-468h] BYREF
  __int64 v244; // [xsp+A0h] [xbp-460h]
  _QWORD v245[2]; // [xsp+A8h] [xbp-458h] BYREF
  char v246[4]; // [xsp+B8h] [xbp-448h] BYREF
  _DWORD v247[85]; // [xsp+BCh] [xbp-444h] BYREF
  __int64 v248; // [xsp+210h] [xbp-2F0h] BYREF
  __int64 v249; // [xsp+218h] [xbp-2E8h]
  __int64 v250; // [xsp+220h] [xbp-2E0h]
  __int64 v251; // [xsp+228h] [xbp-2D8h]
  __int64 v252; // [xsp+230h] [xbp-2D0h]
  __int64 v253; // [xsp+238h] [xbp-2C8h]
  __int64 v254; // [xsp+240h] [xbp-2C0h] BYREF
  __int64 v255; // [xsp+248h] [xbp-2B8h]
  __int64 v256; // [xsp+250h] [xbp-2B0h]
  __int64 v257; // [xsp+258h] [xbp-2A8h]
  __int64 v258; // [xsp+260h] [xbp-2A0h]
  __int64 v259; // [xsp+268h] [xbp-298h]
  __int64 v260; // [xsp+270h] [xbp-290h]
  __int64 v261; // [xsp+278h] [xbp-288h]
  __int64 v262; // [xsp+280h] [xbp-280h]
  __int64 v263; // [xsp+288h] [xbp-278h]
  int v264; // [xsp+290h] [xbp-270h]
  _QWORD v265[3]; // [xsp+298h] [xbp-268h] BYREF
  __int64 v266; // [xsp+2B0h] [xbp-250h]
  __int64 v267; // [xsp+2B8h] [xbp-248h] BYREF
  int v268; // [xsp+2C0h] [xbp-240h]
  _QWORD v269[3]; // [xsp+2C8h] [xbp-238h] BYREF
  __int64 v270; // [xsp+2E0h] [xbp-220h]
  __int64 v271; // [xsp+2E8h] [xbp-218h]
  __int64 v272; // [xsp+2F0h] [xbp-210h]
  _DWORD s[128]; // [xsp+2F8h] [xbp-208h] BYREF
  __int64 v274; // [xsp+4F8h] [xbp-8h]

  v274 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = memset(s, 0, sizeof(s));
  v246[0] = 0;
  v6 = ipa3_ctx;
  v245[0] = 0;
  v245[1] = 0;
  v272 = 0;
  v271 = 0;
  v270 = 0;
  memset(v269, 0, sizeof(v269));
  v243 = 0;
  v244 = 0;
  memset(v242, 0, sizeof(v242));
  v241[0] = 0;
  v241[1] = 0;
  v240 = 0;
  v239[0] = 0;
  v238[0] = 0;
  v238[1] = 0;
  v237 = 0;
  v268 = 0;
  v267 = 0;
  v266 = 0;
  memset(v265, 0, sizeof(v265));
  v264 = 0;
  v263 = 0;
  v262 = 0;
  v261 = 0;
  v260 = 0;
  v259 = 0;
  v258 = 0;
  v257 = 0;
  v256 = 0;
  v255 = 0;
  v254 = 0;
  v253 = 0;
  v252 = 0;
  v251 = 0;
  v250 = 0;
  v249 = 0;
  v248 = 0;
  *(_QWORD *)v235 = 0;
  v236 = 0;
  v234[0] = 0;
  v233[0] = 0;
  v231 = 0;
  v232 = 0;
  v229 = 0;
  v230 = 0;
  if ( ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d cmd=%x nr=%d\n", "ipa3_ioctl", 2867, a2, (unsigned __int8)a2);
      v6 = ipa3_ctx;
    }
    v5 = *(void **)(v6 + 34160);
    if ( v5 )
      v5 = (void *)ipc_log_string(v5, "ipa %s:%d cmd=%x nr=%d\n", "ipa3_ioctl", 2867, a2, (unsigned __int8)a2);
  }
  if ( (a2 & 0xFF00) == 0xCF00 )
  {
    if ( (ipa_is_ready(v5) & 1) == 0 )
    {
      printk(&unk_3E2EF0, "ipa3_ioctl");
      v26 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v27 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v27 )
        {
          ipc_log_string(v27, "ipa %s:%d IPA not ready, waiting for init completion\n", "ipa3_ioctl", 2873);
          v26 = ipa3_ctx;
        }
        v28 = *(_QWORD *)(v26 + 34160);
        if ( v28 )
        {
          ipc_log_string(v28, "ipa %s:%d IPA not ready, waiting for init completion\n", "ipa3_ioctl", 2873);
          v26 = ipa3_ctx;
        }
      }
      wait_for_completion(v26 + 43656);
    }
    v8 = ipa3_inc_client_enable_clks_no_log();
    if ( a2 <= -1072902327 )
    {
      if ( a2 > -1073426610 )
      {
        switch ( a2 )
        {
          case -1073164544:
            if ( inline_copy_from_user((int)s, a3, 4u) )
              goto LABEL_524;
            v9 = BYTE1(s[0]);
            v10 = 308LL * BYTE1(s[0]);
            v11 = (unsigned __int8 *)memdup_user(a3, v10 + 4);
            if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_367;
            if ( v11[1] == v9 )
            {
              v12 = v11;
              v13 = -14;
              if ( (unsigned int)ipa3_add_hdr_usr() )
                goto LABEL_436;
              _check_object_size(v12, v10 + 4, 1);
              v14 = v10 + 4;
              goto LABEL_333;
            }
            v12 = v11;
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_428, "ipa3_ioctl") )
            {
              printk(&unk_3A8F59, "ipa3_ioctl");
              v193 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            else
            {
              v193 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            v194 = *(_QWORD *)(v193 + 34152);
            if ( v194 )
            {
              ipc_log_string(v194, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3073, v12[1], v9);
              v193 = ipa3_ctx;
            }
            v195 = *(_QWORD *)(v193 + 34160);
            if ( v195 )
            {
              ipc_log_string(v195, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3073, v12[1], v9);
              goto LABEL_653;
            }
            goto LABEL_534;
          case -1073164543:
            if ( inline_copy_from_user((int)s, a3, 4u) )
              goto LABEL_524;
            v109 = BYTE1(s[0]);
            v73 = (8LL * BYTE1(s[0])) | 4;
            v11 = (unsigned __int8 *)memdup_user(a3, v73);
            if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_367;
            if ( v11[1] == v109 )
            {
              v12 = v11;
              v74 = ipa3_del_hdr_by_user();
              goto LABEL_431;
            }
            v12 = v11;
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_429, "ipa3_ioctl") )
            {
              printk(&unk_3A8F59, "ipa3_ioctl");
              v202 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            else
            {
              v202 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            v203 = *(_QWORD *)(v202 + 34152);
            if ( v203 )
            {
              ipc_log_string(v203, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3109, v12[1], v109);
              v202 = ipa3_ctx;
            }
            v204 = *(_QWORD *)(v202 + 34160);
            if ( v204 )
            {
              ipc_log_string(v204, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3109, v12[1], v109);
              goto LABEL_653;
            }
            goto LABEL_534;
          case -1073164542:
            if ( inline_copy_from_user((int)s, a3, 0x2Cu) )
              goto LABEL_524;
            v106 = LOBYTE(s[10]);
            v107 = 180LL * LOBYTE(s[10]);
            v11 = (unsigned __int8 *)memdup_user(a3, v107 + 44);
            if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_367;
            if ( v11[40] == v106 )
            {
              v12 = v11;
              v108 = ipa3_add_rt_rule_usr();
              goto LABEL_322;
            }
            v12 = v11;
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_430, "ipa3_ioctl") )
            {
              printk(&unk_3A8F59, "ipa3_ioctl");
              v199 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            else
            {
              v199 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            v200 = *(_QWORD *)(v199 + 34152);
            if ( v200 )
            {
              ipc_log_string(v200, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3146, v12[40], v106);
              v199 = ipa3_ctx;
            }
            v201 = *(_QWORD *)(v199 + 34160);
            if ( v201 )
            {
              ipc_log_string(v201, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3146, v12[40], v106);
              goto LABEL_653;
            }
            goto LABEL_534;
          case -1073164541:
            if ( inline_copy_from_user((int)s, a3, 0xCu) )
              goto LABEL_524;
            v111 = LOBYTE(s[2]);
            v97 = 8LL * LOBYTE(s[2]);
            v11 = (unsigned __int8 *)memdup_user(a3, v97 + 12);
            if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_367;
            if ( v11[8] == v111 )
            {
              v12 = v11;
              v98 = ipa3_del_rt_rule();
              goto LABEL_331;
            }
            v12 = v11;
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_435, "ipa3_ioctl") )
            {
              printk(&unk_3A8F59, "ipa3_ioctl");
              v208 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            else
            {
              v208 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            v209 = *(_QWORD *)(v208 + 34152);
            if ( v209 )
            {
              ipc_log_string(v209, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3296, v12[8], v111);
              v208 = ipa3_ctx;
            }
            v210 = *(_QWORD *)(v208 + 34160);
            if ( v210 )
            {
              ipc_log_string(v210, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3296, v12[8], v111);
              goto LABEL_653;
            }
            goto LABEL_534;
          case -1073164540:
            if ( inline_copy_from_user((int)s, a3, 0x10u) )
              goto LABEL_524;
            v100 = BYTE1(s[3]);
            v101 = 372LL * BYTE1(s[3]);
            v11 = (unsigned __int8 *)memdup_user(a3, v101 + 16);
            if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_367;
            if ( v11[13] == v100 )
            {
              v12 = v11;
              v13 = -14;
              if ( (unsigned int)ipa3_add_flt_rule_usr() )
                goto LABEL_436;
              _check_object_size(v12, v101 + 16, 1);
              v14 = v101 + 16;
              goto LABEL_333;
            }
            v12 = v11;
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_436, "ipa3_ioctl") )
            {
              printk(&unk_3A8F59, "ipa3_ioctl");
              v187 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            else
            {
              v187 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            v188 = *(_QWORD *)(v187 + 34152);
            if ( v188 )
            {
              ipc_log_string(v188, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3332, v12[13], v100);
              v187 = ipa3_ctx;
            }
            v189 = *(_QWORD *)(v187 + 34160);
            if ( v189 )
            {
              ipc_log_string(v189, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3332, v12[13], v100);
              goto LABEL_653;
            }
            goto LABEL_534;
          case -1073164539:
            if ( inline_copy_from_user((int)s, a3, 0xCu) )
              goto LABEL_524;
            v96 = LOBYTE(s[2]);
            v97 = 8LL * LOBYTE(s[2]);
            v11 = (unsigned __int8 *)memdup_user(a3, v97 + 12);
            if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_367;
            if ( v11[8] == v96 )
            {
              v12 = v11;
              v98 = ipa3_del_flt_rule();
LABEL_331:
              v13 = -14;
              if ( !v98 )
              {
                _check_object_size(v12, v97 + 12, 1);
                v14 = v97 + 12;
                goto LABEL_333;
              }
              goto LABEL_436;
            }
            v12 = v11;
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_438, "ipa3_ioctl") )
            {
              printk(&unk_3A8F59, "ipa3_ioctl");
              v184 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            else
            {
              v184 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            v185 = *(_QWORD *)(v184 + 34152);
            if ( v185 )
            {
              ipc_log_string(v185, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3408, v12[8], v96);
              v184 = ipa3_ctx;
            }
            v186 = *(_QWORD *)(v184 + 34160);
            if ( v186 )
            {
              ipc_log_string(v186, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3408, v12[8], v96);
              goto LABEL_653;
            }
            goto LABEL_534;
          case -1073164538:
          case -1073164537:
          case -1073164536:
          case -1073164535:
          case -1073164534:
          case -1073164533:
          case -1073164532:
          case -1073164530:
          case -1073164524:
          case -1073164523:
          case -1073164516:
          case -1073164511:
          case -1073164488:
          case -1073164487:
          case -1073164485:
          case -1073164484:
          case -1073164483:
          case -1073164482:
          case -1073164481:
          case -1073164480:
          case -1073164479:
          case -1073164478:
          case -1073164470:
          case -1073164469:
          case -1073164468:
          case -1073164467:
          case -1073164466:
          case -1073164465:
          case -1073164464:
          case -1073164463:
          case -1073164462:
          case -1073164461:
          case -1073164460:
          case -1073164459:
          case -1073164458:
          case -1073164457:
          case -1073164456:
          case -1073164455:
          case -1073164454:
          case -1073164453:
          case -1073164452:
          case -1073164451:
          case -1073164450:
          case -1073164449:
            goto LABEL_143;
          case -1073164531:
            if ( inline_copy_from_user((int)s, a3, 0x28u) )
              goto LABEL_524;
            v13 = -14;
            if ( !(unsigned int)ipa3_get_rt_tbl(s) )
              goto LABEL_343;
            goto LABEL_364;
          case -1073164529:
            if ( inline_copy_from_user((int)s, a3, 0x128u) )
              goto LABEL_524;
            v13 = -14;
            if ( (unsigned int)ipa3_copy_hdr(s) )
              goto LABEL_364;
            v91 = s;
            v92 = a3;
            v93 = 296;
            goto LABEL_358;
          case -1073164528:
            if ( inline_copy_from_user((int)s, a3, 0x30u) )
              goto LABEL_524;
            if ( (unsigned int)((__int64 (__fastcall *)(_DWORD *))ipa3_query_intf)(s) )
              goto LABEL_326;
            v121 = (__int64 *)s;
            v122 = a3;
            v123 = 48;
            goto LABEL_444;
          case -1073164527:
            if ( inline_copy_from_user((int)s, a3, 0x24u) )
              goto LABEL_524;
            v99 = s[8];
            if ( s[8] > 0x23u )
              goto LABEL_524;
            v81 = 200LL * s[8];
            v11 = (unsigned __int8 *)memdup_user(a3, v81 + 36);
            if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_367;
            if ( *((_DWORD *)v11 + 8) == v99 )
            {
              v12 = v11;
              if ( !(unsigned int)ipa3_query_intf_tx_props() )
                goto LABEL_349;
              goto LABEL_283;
            }
            v12 = v11;
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_440, "ipa3_ioctl") )
            {
              printk(&unk_3A8F59, "ipa3_ioctl");
              v219 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            else
            {
              v219 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            v220 = *(_QWORD *)(v219 + 34152);
            if ( v220 )
            {
              ipc_log_string(v220, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3577, *((_DWORD *)v12 + 8), v99);
              v219 = ipa3_ctx;
            }
            v221 = *(_QWORD *)(v219 + 34160);
            if ( v221 )
            {
              ipc_log_string(v221, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3577, *((unsigned int *)v12 + 8), v99);
              goto LABEL_653;
            }
            goto LABEL_534;
          case -1073164526:
            if ( inline_copy_from_user((int)s, a3, 0x24u) )
              goto LABEL_524;
            v117 = s[8];
            if ( s[8] > 0x23u )
              goto LABEL_524;
            v81 = 164LL * s[8];
            v11 = (unsigned __int8 *)memdup_user(a3, v81 + 36);
            if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_367;
            if ( *((_DWORD *)v11 + 8) == v117 )
            {
              v12 = v11;
              if ( (unsigned int)((__int64 (*)(void))ipa3_query_intf_rx_props)() )
                goto LABEL_283;
              goto LABEL_349;
            }
            v12 = v11;
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_441, "ipa3_ioctl") )
            {
              printk(&unk_3A8F59, "ipa3_ioctl");
              v222 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            else
            {
              v222 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            v223 = *(_QWORD *)(v222 + 34152);
            if ( v223 )
            {
              ipc_log_string(v223, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3618, *((_DWORD *)v12 + 8), v117);
              v222 = ipa3_ctx;
            }
            v224 = *(_QWORD *)(v222 + 34160);
            if ( v224 )
            {
              ipc_log_string(
                v224,
                "ipa %s:%d current %d pre %d\n",
                "ipa3_ioctl",
                3618,
                *((unsigned int *)v12 + 8),
                v117);
              goto LABEL_653;
            }
            goto LABEL_534;
          case -1073164525:
            if ( inline_copy_from_user((int)s, a3, 0x24u) )
              goto LABEL_524;
            v13 = -14;
            if ( (unsigned int)ipa_get_hdr(s) )
              goto LABEL_364;
            v91 = s;
            v92 = a3;
            v93 = 36;
            goto LABEL_358;
          case -1073164522:
            if ( inline_copy_from_user((int)v269, a3, 0x30u) )
              goto LABEL_524;
            HIBYTE(v270) = 0;
            v13 = -14;
            if ( (unsigned int)ipa3_allocate_nat_device(v269) )
              goto LABEL_364;
            v91 = v269;
            v92 = a3;
            v93 = 48;
            goto LABEL_358;
          case -1073164521:
            v13 = -14;
            if ( inline_copy_from_user((int)v242, a3, 0x20u) )
              goto LABEL_364;
            inited = ipa3_nat_init_cmd(v242);
            goto LABEL_338;
          case -1073164520:
            if ( inline_copy_from_user((int)s, a3, 4u) )
              goto LABEL_524;
            v87 = LOBYTE(s[0]);
            v11 = (unsigned __int8 *)memdup_user(a3, 12LL * LOBYTE(s[0]) + 4);
            if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_367;
            if ( *v11 == v87 )
            {
              v12 = v11;
              v88 = (unsigned int)((__int64 (*)(void))ipa3_table_dma_cmd)() == 0;
              goto LABEL_352;
            }
            v12 = v11;
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_425, "ipa3_ioctl") )
            {
              printk(&unk_3A8F59, "ipa3_ioctl");
              v178 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            else
            {
              v178 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            v179 = *(_QWORD *)(v178 + 34152);
            if ( v179 )
            {
              ipc_log_string(v179, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 2992, *v12, v87);
              v178 = ipa3_ctx;
            }
            v180 = *(_QWORD *)(v178 + 34160);
            if ( v180 )
            {
              ipc_log_string(v180, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 2992, *v12, v87);
              goto LABEL_653;
            }
            goto LABEL_534;
          case -1073164519:
            v13 = -14;
            if ( inline_copy_from_user((int)v241, a3, 0x10u) )
              goto LABEL_364;
            inited = ipa3_ipv6ct_init_cmd(v241);
            goto LABEL_338;
          case -1073164518:
            v13 = -14;
            if ( inline_copy_from_user((int)&v240, a3, 8u) )
              goto LABEL_364;
            inited = ipa3_nat_del_cmd(&v240);
            goto LABEL_338;
          case -1073164517:
            if ( inline_copy_from_user((int)s, a3, 4u) )
              goto LABEL_524;
            v84 = HIWORD(s[0]);
            v11 = (unsigned __int8 *)memdup_user(a3, HIWORD(s[0]) + 4LL);
            if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_367;
            if ( *((unsigned __int16 *)v11 + 1) == (_DWORD)v84 )
            {
              v85 = v11;
              v12 = v11;
              if ( (unsigned int)ipa3_pull_msg() != *((unsigned __int16 *)v11 + 1) )
                goto LABEL_283;
              _check_object_size(v85, v84 + 4, 1);
              v86 = v84 + 4;
              goto LABEL_350;
            }
            v12 = v11;
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_443, "ipa3_ioctl") )
            {
              printk(&unk_3A8F59, "ipa3_ioctl");
              v175 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            else
            {
              v175 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            v176 = *(_QWORD *)(v175 + 34152);
            if ( v176 )
            {
              ipc_log_string(
                v176,
                "ipa %s:%d current %d pre %d\n",
                "ipa3_ioctl",
                3693,
                *((unsigned __int16 *)v12 + 1),
                v84);
              v175 = ipa3_ctx;
            }
            v177 = *(_QWORD *)(v175 + 34160);
            if ( v177 )
            {
              ipc_log_string(
                v177,
                "ipa %s:%d current %d pre %d\n",
                "ipa3_ioctl",
                3693,
                *((unsigned __int16 *)v12 + 1),
                (unsigned int)v84);
              goto LABEL_653;
            }
            goto LABEL_534;
          case -1073164515:
            printk(&unk_3F70A5, "ipa3_ioctl");
            v153 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_484;
            v154 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v154 )
            {
              ipc_log_string(v154, "ipa %s:%d using obselete command: IPA_IOC_RM_ADD_DEPENDENCY", "ipa3_ioctl", 3711);
              v153 = ipa3_ctx;
            }
            v29 = *(_QWORD *)(v153 + 34160);
            if ( !v29 )
              goto LABEL_507;
            ipc_log_string(v29, "ipa %s:%d using obselete command: IPA_IOC_RM_ADD_DEPENDENCY", "ipa3_ioctl", 3711);
            goto LABEL_484;
          case -1073164514:
            printk(&unk_3E5A52, "ipa3_ioctl");
            v151 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_484;
            v152 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v152 )
            {
              ipc_log_string(v152, "ipa %s:%d using obselete command: IPA_IOC_RM_DEL_DEPENDENCY", "ipa3_ioctl", 3717);
              v151 = ipa3_ctx;
            }
            v29 = *(_QWORD *)(v151 + 34160);
            if ( v29 )
            {
              ipc_log_string(v29, "ipa %s:%d using obselete command: IPA_IOC_RM_DEL_DEPENDENCY", "ipa3_ioctl", 3717);
LABEL_484:
              v29 = 0;
              v13 = -22;
            }
            else
            {
LABEL_507:
              v13 = -22;
            }
            goto LABEL_526;
          case -1073164513:
            memset(v247, 0, sizeof(v247));
            if ( inline_copy_from_user((int)v247, a3, 0x154u) )
            {
              v13 = -14;
              v29 = 0;
              goto LABEL_526;
            }
            v13 = -14;
            if ( !(unsigned int)((__int64 (__fastcall *)(_QWORD, _DWORD *, _DWORD *))ipahal_flt_generate_equation)(
                                  v247[0],
                                  &v247[1],
                                  &v247[39]) )
            {
              if ( inline_copy_to_user(a3, v247, 340) )
                v13 = -14;
              else
                v13 = 0;
            }
            goto LABEL_364;
          case -1073164512:
            if ( inline_copy_from_user((int)s, a3, 0x24u) )
              goto LABEL_524;
            v80 = s[8];
            if ( s[8] > 0x23u )
              goto LABEL_524;
            v81 = 216LL * s[8];
            v11 = (unsigned __int8 *)memdup_user(a3, v81 + 36);
            if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_367;
            if ( *((_DWORD *)v11 + 8) == v80 )
            {
              v12 = v11;
              if ( (unsigned int)ipa3_query_intf_ext_props() )
              {
LABEL_283:
                v13 = -1;
              }
              else
              {
LABEL_349:
                _check_object_size(v12, v81 + 36, 1);
                v86 = v81 + 36;
LABEL_350:
                v115 = a3;
                v114 = v12;
LABEL_351:
                v88 = inline_copy_to_user(v115, v114, v86) == 0;
LABEL_352:
                if ( v88 )
                  v13 = 0;
                else
                  v13 = -14;
              }
              goto LABEL_436;
            }
            v12 = v11;
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_442, "ipa3_ioctl") )
            {
              printk(&unk_3A8F59, "ipa3_ioctl");
              v216 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            else
            {
              v216 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            v217 = *(_QWORD *)(v216 + 34152);
            if ( v217 )
            {
              ipc_log_string(v217, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3659, *((_DWORD *)v12 + 8), v80);
              v216 = ipa3_ctx;
            }
            v218 = *(_QWORD *)(v216 + 34160);
            if ( v218 )
            {
              ipc_log_string(v218, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3659, *((unsigned int *)v12 + 8), v80);
              goto LABEL_653;
            }
            goto LABEL_534;
          case -1073164510:
            if ( inline_copy_from_user((int)s, a3, 0x28u) )
              goto LABEL_524;
            v13 = -14;
            if ( (unsigned int)ipa3_query_rt_index(s) )
              goto LABEL_364;
LABEL_343:
            v91 = s;
            v92 = a3;
            v93 = 40;
            goto LABEL_358;
          case -1073164509:
            if ( inline_copy_from_user((int)s, a3, 8u) )
              goto LABEL_524;
            v13 = -14;
            if ( (unsigned int)((__int64 (__fastcall *)(_DWORD *))ipa3_write_qmap_id)(s) )
              goto LABEL_364;
            v91 = s;
            v92 = a3;
            v93 = 8;
LABEL_358:
            v118 = inline_copy_to_user(v92, v91, v93);
            v29 = 0;
            if ( v118 )
              v13 = -14;
            else
              v13 = 0;
            goto LABEL_526;
          case -1073164508:
            if ( inline_copy_from_user((int)s, a3, 0xCu) )
              goto LABEL_524;
            v105 = LOBYTE(s[2]);
            v103 = 368LL * LOBYTE(s[2]);
            v11 = (unsigned __int8 *)memdup_user(a3, v103 | 0xC);
            if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_367;
            if ( v11[8] == v105 )
            {
              v12 = v11;
              v104 = ipa3_mdfy_flt_rule();
              goto LABEL_299;
            }
            v12 = v11;
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_439, "ipa3_ioctl") )
            {
              printk(&unk_3A8F59, "ipa3_ioctl");
              v196 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            else
            {
              v196 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            v197 = *(_QWORD *)(v196 + 34152);
            if ( v197 )
            {
              ipc_log_string(v197, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3444, v12[8], v105);
              v196 = ipa3_ctx;
            }
            v198 = *(_QWORD *)(v196 + 34160);
            if ( v198 )
            {
              ipc_log_string(v198, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3444, v12[8], v105);
              goto LABEL_653;
            }
            goto LABEL_534;
          case -1073164507:
            v13 = ipa3_send_wan_msg(a3, 15, 1);
            if ( !v13 )
              goto LABEL_364;
            printk(&unk_3B1967, "ipa3_ioctl");
            v161 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_364;
            v162 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v162 )
            {
              ipc_log_string(v162, "ipa %s:%d ipa3_send_wan_msg failed: %d\n", "ipa3_ioctl", 3783, v13);
              v161 = ipa3_ctx;
            }
            v29 = *(_QWORD *)(v161 + 34160);
            if ( !v29 )
              goto LABEL_526;
            ipc_log_string(v29, "ipa %s:%d ipa3_send_wan_msg failed: %d\n", "ipa3_ioctl", 3783, v13);
            goto LABEL_500;
          case -1073164506:
            v13 = ipa3_send_wan_msg(a3, 16, 1);
            if ( !v13 )
              goto LABEL_364;
            printk(&unk_3B1967, "ipa3_ioctl");
            v89 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_364;
            v90 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v90 )
            {
              ipc_log_string(v90, "ipa %s:%d ipa3_send_wan_msg failed: %d\n", "ipa3_ioctl", 3790, v13);
              v89 = ipa3_ctx;
            }
            v29 = *(_QWORD *)(v89 + 34160);
            if ( !v29 )
              goto LABEL_526;
            ipc_log_string(v29, "ipa %s:%d ipa3_send_wan_msg failed: %d\n", "ipa3_ioctl", 3790, v13);
            goto LABEL_500;
          case -1073164505:
            v13 = ipa3_send_wan_msg(a3, 17, 0);
            if ( !v13 )
              goto LABEL_364;
            printk(&unk_3B1967, "ipa3_ioctl");
            v77 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_364;
            v78 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v78 )
            {
              ipc_log_string(v78, "ipa %s:%d ipa3_send_wan_msg failed: %d\n", "ipa3_ioctl", 3797, v13);
              v77 = ipa3_ctx;
            }
            v29 = *(_QWORD *)(v77 + 34160);
            if ( !v29 )
              goto LABEL_526;
            ipc_log_string(v29, "ipa %s:%d ipa3_send_wan_msg failed: %d\n", "ipa3_ioctl", 3797, v13);
LABEL_500:
            v29 = 0;
            goto LABEL_526;
          case -1073164504:
            if ( inline_copy_from_user((int)s, a3, 4u) )
              goto LABEL_524;
            v72 = BYTE1(s[0]);
            v73 = (48LL * BYTE1(s[0])) | 4;
            v11 = (unsigned __int8 *)memdup_user(a3, v73);
            if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_367;
            if ( v11[1] == v72 )
            {
              v12 = v11;
              v74 = ipa3_add_hdr_proc_ctx();
              goto LABEL_431;
            }
            v12 = v11;
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_450, "ipa3_ioctl") )
            {
              printk(&unk_3A8F59, "ipa3_ioctl");
              v169 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            else
            {
              v169 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            v170 = *(_QWORD *)(v169 + 34152);
            if ( v170 )
            {
              ipc_log_string(v170, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3823, v12[1], v72);
              v169 = ipa3_ctx;
            }
            v171 = *(_QWORD *)(v169 + 34160);
            if ( v171 )
            {
              ipc_log_string(v171, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3823, v12[1], v72);
              goto LABEL_653;
            }
            goto LABEL_534;
          case -1073164503:
            if ( inline_copy_from_user((int)s, a3, 4u) )
              goto LABEL_524;
            v119 = BYTE1(s[0]);
            v73 = (8LL * BYTE1(s[0])) | 4;
            v11 = (unsigned __int8 *)memdup_user(a3, v73);
            if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_367;
            if ( v11[1] == v119 )
            {
              v12 = v11;
              v74 = ipa3_del_hdr_proc_ctx_by_user();
LABEL_431:
              v13 = -14;
              if ( !v74 )
              {
                _check_object_size(v12, v73, 1);
                v112 = a3;
                v113 = v12;
                v14 = v73;
                goto LABEL_433;
              }
              goto LABEL_436;
            }
            v12 = v11;
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_451, "ipa3_ioctl") )
            {
              printk(&unk_3A8F59, "ipa3_ioctl");
              v211 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            else
            {
              v211 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            v212 = *(_QWORD *)(v211 + 34152);
            if ( v212 )
            {
              ipc_log_string(v212, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3859, v12[1], v119);
              v211 = ipa3_ctx;
            }
            v213 = *(_QWORD *)(v211 + 34160);
            if ( v213 )
            {
              ipc_log_string(v213, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3859, v12[1], v119);
              goto LABEL_653;
            }
            goto LABEL_534;
          case -1073164502:
            if ( inline_copy_from_user((int)s, a3, 0xCu) )
              goto LABEL_524;
            v102 = LOBYTE(s[2]);
            v103 = 176LL * LOBYTE(s[2]);
            v11 = (unsigned __int8 *)memdup_user(a3, v103 | 0xC);
            if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_367;
            if ( v11[8] == v102 )
            {
              v12 = v11;
              v104 = ipa3_mdfy_rt_rule();
LABEL_299:
              v13 = -14;
              if ( !v104 )
              {
                _check_object_size(v12, v103 | 0xC, 1);
                v14 = v103 | 0xC;
                goto LABEL_333;
              }
              goto LABEL_436;
            }
            v12 = v11;
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_434, "ipa3_ioctl") )
            {
              printk(&unk_3A8F59, "ipa3_ioctl");
              v190 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            else
            {
              v190 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            v191 = *(_QWORD *)(v190 + 34152);
            if ( v191 )
            {
              ipc_log_string(v191, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3261, v12[8], v102);
              v190 = ipa3_ctx;
            }
            v192 = *(_QWORD *)(v190 + 34160);
            if ( v192 )
            {
              ipc_log_string(v192, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3261, v12[8], v102);
              goto LABEL_653;
            }
            goto LABEL_534;
          case -1073164501:
            if ( inline_copy_from_user((int)s, a3, 0x30u) )
              goto LABEL_524;
            v94 = LOBYTE(s[10]);
            v95 = 180LL * LOBYTE(s[10]);
            v11 = (unsigned __int8 *)memdup_user(a3, v95 + 48);
            if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_367;
            if ( v11[40] == v94 )
            {
              v12 = v11;
              v13 = -14;
              if ( (unsigned int)ipa3_add_rt_rule_after() )
                goto LABEL_436;
              _check_object_size(v12, v95 + 48, 1);
              v14 = v95 + 48;
              goto LABEL_333;
            }
            v12 = v11;
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_433, "ipa3_ioctl") )
            {
              printk(&unk_3A8F59, "ipa3_ioctl");
              v181 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            else
            {
              v181 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            v182 = *(_QWORD *)(v181 + 34152);
            if ( v182 )
            {
              ipc_log_string(v182, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3223, v12[40], v94);
              v181 = ipa3_ctx;
            }
            v183 = *(_QWORD *)(v181 + 34160);
            if ( v183 )
            {
              ipc_log_string(v183, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3223, v12[40], v94);
              goto LABEL_653;
            }
            goto LABEL_534;
          case -1073164500:
            if ( inline_copy_from_user((int)s, a3, 0x14u) )
              goto LABEL_524;
            v82 = LOBYTE(s[3]);
            v83 = 372LL * LOBYTE(s[3]);
            v11 = (unsigned __int8 *)memdup_user(a3, v83 + 20);
            if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
              goto LABEL_367;
            if ( v11[12] == v82 )
            {
              v12 = v11;
              v13 = -14;
              if ( (unsigned int)ipa3_add_flt_rule_after() )
                goto LABEL_436;
              _check_object_size(v12, v83 + 20, 1);
              v14 = v83 + 20;
              goto LABEL_333;
            }
            v12 = v11;
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_437, "ipa3_ioctl") )
            {
              printk(&unk_3A8F59, "ipa3_ioctl");
              v172 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            else
            {
              v172 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            v173 = *(_QWORD *)(v172 + 34152);
            if ( v173 )
            {
              ipc_log_string(v173, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3371, v12[12], v82);
              v172 = ipa3_ctx;
            }
            v174 = *(_QWORD *)(v172 + 34160);
            if ( v174 )
            {
              ipc_log_string(v174, "ipa %s:%d current %d pre %d\n", "ipa3_ioctl", 3371, v12[12], v82);
LABEL_653:
              v13 = -14;
              goto LABEL_436;
            }
            goto LABEL_534;
          case -1073164499:
            v29 = kmemdup_noprof(ipa3_ctx + 32240, 4, 3264);
            if ( !v29 )
              goto LABEL_703;
            v114 = (unsigned __int8 *)v29;
            v115 = a3;
            v86 = 4;
            v12 = v114;
            goto LABEL_351;
          case -1073164498:
            if ( inline_copy_from_user((int)s, a3, 0x2Cu) )
              goto LABEL_524;
            v110 = LOBYTE(s[10]);
            v107 = 184LL * LOBYTE(s[10]);
            v11 = (unsigned __int8 *)memdup_user(a3, v107 + 44);
            if ( (unsigned __int64)v11 >= 0xFFFFFFFFFFFFF001LL )
            {
LABEL_367:
              v12 = v11;
              v13 = (unsigned int)v11;
            }
            else if ( v11[40] == v110 )
            {
              v12 = v11;
              v108 = ipa3_add_rt_rule_ext();
LABEL_322:
              v13 = -14;
              if ( !v108 )
              {
                _check_object_size(v12, v107 + 44, 1);
                v14 = v107 + 44;
LABEL_333:
                v112 = a3;
                v113 = v12;
LABEL_433:
                if ( inline_copy_to_user(v112, v113, v14) )
                  v13 = -14;
                else
                  v13 = 0;
              }
            }
            else
            {
              v12 = v11;
              printk(&unk_3EBAD9, "ipa3_ioctl");
              v205 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v206 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v206 )
                {
                  ipc_log_string(
                    v206,
                    "ipa %s:%d  prevent memory corruption(%d not match %d)\n",
                    "ipa3_ioctl",
                    3185,
                    v12[40],
                    v110);
                  v205 = ipa3_ctx;
                }
                v207 = *(_QWORD *)(v205 + 34160);
                if ( v207 )
                  ipc_log_string(
                    v207,
                    "ipa %s:%d  prevent memory corruption(%d not match %d)\n",
                    "ipa3_ioctl",
                    3185,
                    v12[40],
                    v110);
              }
              v13 = -22;
            }
            goto LABEL_436;
          case -1073164497:
            v36 = a3;
            v37 = 26;
            goto LABEL_369;
          case -1073164496:
            v36 = a3;
            v37 = 27;
            goto LABEL_369;
          case -1073164495:
            v36 = a3;
            v37 = 28;
            goto LABEL_369;
          case -1073164494:
            v36 = a3;
            v37 = 29;
            goto LABEL_369;
          case -1073164493:
            v13 = -14;
            if ( inline_copy_from_user((int)v238, a3, 0x10u) )
              goto LABEL_364;
            inited = ipa3_nat_mdfy_pdn(v238);
            goto LABEL_338;
          case -1073164492:
            if ( inline_copy_from_user((int)&v243, a3, 0x10u) || (unsigned int)ipa3_allocate_nat_table(&v243) )
              goto LABEL_524;
            goto LABEL_380;
          case -1073164491:
            if ( inline_copy_from_user((int)&v243, a3, 0x10u) || (unsigned int)ipa3_allocate_ipv6ct_table(&v243) )
              goto LABEL_524;
LABEL_380:
            if ( !v244 )
              goto LABEL_62;
            v121 = &v243;
            v122 = a3;
            v123 = 16;
            goto LABEL_444;
          case -1073164490:
            v13 = -14;
            if ( inline_copy_from_user((int)v239, a3, 2u) )
              goto LABEL_364;
            inited = ipa3_del_nat_table(v239);
            goto LABEL_338;
          case -1073164489:
            v13 = -14;
            if ( inline_copy_from_user((int)v239, a3, 2u) )
              goto LABEL_364;
            inited = ipa3_del_ipv6ct_table(v239);
LABEL_338:
            v116 = inited;
            v29 = 0;
            if ( v116 )
              v13 = -14;
            else
              v13 = 0;
            goto LABEL_526;
          case -1073164486:
            if ( inline_copy_from_user((int)&v237, a3, 8u) )
              goto LABEL_524;
            is_vlan_mode = ipa_is_vlan_mode((unsigned int)v237, v246);
            if ( is_vlan_mode )
              goto LABEL_418;
            v121 = &v237;
            v122 = a3;
            v123 = 8;
            HIDWORD(v237) = (unsigned __int8)v246[0];
LABEL_444:
            v139 = inline_copy_to_user(v122, v121, v123);
            v29 = 0;
            if ( v139 )
              v13 = -14;
            else
              v13 = 0;
            goto LABEL_526;
          case -1073164477:
            is_vlan_mode = ipa3_ioctl_add_rt_rule_v2(a3);
            goto LABEL_418;
          case -1073164476:
            is_vlan_mode = ipa3_ioctl_add_rt_rule_ext_v2(a3);
            goto LABEL_418;
          case -1073164475:
            is_vlan_mode = ipa3_ioctl_add_rt_rule_after_v2(a3);
            goto LABEL_418;
          case -1073164474:
            is_vlan_mode = ipa3_ioctl_mdfy_rt_rule_v2(a3);
            goto LABEL_418;
          case -1073164473:
            is_vlan_mode = ipa3_ioctl_add_flt_rule_v2(a3);
            goto LABEL_418;
          case -1073164472:
            is_vlan_mode = ipa3_ioctl_add_flt_rule_after_v2(a3);
            goto LABEL_418;
          case -1073164471:
            is_vlan_mode = ipa3_ioctl_mdfy_flt_rule_v2(a3);
            goto LABEL_418;
          case -1073164448:
            if ( !inline_copy_from_user((int)v245, a3, 0x10u) )
            {
              is_vlan_mode = ipa3_set_evict_policy(v245);
              goto LABEL_418;
            }
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs, "ipa3_ioctl") )
            {
              printk(&unk_3F47D5, "ipa3_ioctl");
              v75 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_524;
            }
            else
            {
              v75 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_524;
            }
            v76 = *(_QWORD *)(v75 + 34152);
            if ( v76 )
            {
              ipc_log_string(v76, "ipa %s:%d copy_from_user fails\n", "ipa3_ioctl", 2885);
              v75 = ipa3_ctx;
            }
            v29 = *(_QWORD *)(v75 + 34160);
            if ( v29 )
            {
              ipc_log_string(v29, "ipa %s:%d copy_from_user fails\n", "ipa3_ioctl", 2885);
              goto LABEL_524;
            }
            break;
          default:
            if ( a2 != -1073426609 )
              goto LABEL_143;
            is_vlan_mode = ipa3_app_clk_vote((unsigned int)a3);
            goto LABEL_418;
        }
        goto LABEL_525;
      }
      switch ( a2 )
      {
        case -2147168479:
          is_vlan_mode = ipa_get_ep_mapping((unsigned int)a3);
          break;
        case -1073557683:
          if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x10u )
          {
            printk(&unk_3F173F, "ipa3_ioctl");
            v146 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v147 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v147 )
              {
                ipc_log_string(
                  v147,
                  "ipa %s:%d FNR stats not supported on IPA ver %d",
                  "ipa3_ioctl",
                  4051,
                  *(_DWORD *)(ipa3_ctx + 32240));
                v146 = ipa3_ctx;
              }
              v148 = v146 + 32240;
              v29 = *(_QWORD *)(v148 + 1920);
              if ( !v29 )
                goto LABEL_525;
              ipc_log_string(
                v29,
                "ipa %s:%d FNR stats not supported on IPA ver %d",
                "ipa3_ioctl",
                4051,
                *(_DWORD *)v148);
            }
            goto LABEL_524;
          }
          is_vlan_mode = ipa3_ioctl_fnr_counter_set(a3);
          break;
        case -1073426613:
          if ( *(_DWORD *)(ipa3_ctx + 32240) > 0x10u )
          {
            if ( (a3 & 0x80000000) != 0 )
            {
              printk(&unk_3E5A90, "ipa3_ioctl");
              v149 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v150 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v150 )
                {
                  ipc_log_string(v150, "ipa %s:%d IPA_FNR_COUNTER_DEALLOC failed: hdl %d\n", "ipa3_ioctl", 4031, a3);
                  v149 = ipa3_ctx;
                }
                v29 = *(_QWORD *)(v149 + 34160);
                if ( !v29 )
                {
                  v13 = -1;
                  goto LABEL_526;
                }
                ipc_log_string(v29, "ipa %s:%d IPA_FNR_COUNTER_DEALLOC failed: hdl %d\n", "ipa3_ioctl", 4031, a3);
              }
LABEL_326:
              v29 = 0;
              v13 = -1;
LABEL_526:
              v29 = kfree(v29);
LABEL_527:
              _ipa3_dec_client_disable_clks(v29);
              result = (int)v13;
              goto LABEL_528;
            }
            ((void (__fastcall *)(_QWORD))ipa3_counter_remove_hdl)((unsigned int)a3);
LABEL_62:
            v13 = 0;
            v29 = 0;
            goto LABEL_526;
          }
          printk(&unk_3F173F, "ipa3_ioctl");
          v143 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v144 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v144 )
            {
              ipc_log_string(
                v144,
                "ipa %s:%d FNR stats not supported on IPA ver %d",
                "ipa3_ioctl",
                4024,
                *(_DWORD *)(ipa3_ctx + 32240));
              v143 = ipa3_ctx;
            }
            v145 = v143 + 32240;
            v29 = *(_QWORD *)(v145 + 1920);
            if ( !v29 )
              goto LABEL_525;
            ipc_log_string(v29, "ipa %s:%d FNR stats not supported on IPA ver %d", "ipa3_ioctl", 4024, *(_DWORD *)v145);
          }
LABEL_524:
          v29 = 0;
LABEL_525:
          v13 = -14;
          goto LABEL_526;
        default:
          goto LABEL_143;
      }
LABEL_418:
      v13 = is_vlan_mode;
      v29 = 0;
      goto LABEL_526;
    }
    if ( a2 > -1065037992 )
    {
      if ( a2 > 1074056968 )
      {
        if ( a2 > 1074056979 )
        {
          if ( a2 > 1074057053 )
          {
            if ( a2 == 1074057054 )
            {
              is_vlan_mode = ipa3_set_nat_conn_track_exc_rt_tbl((unsigned int)a3, 0);
              goto LABEL_418;
            }
            if ( a2 == 1074057055 )
            {
              is_vlan_mode = ipa3_set_nat_conn_track_exc_rt_tbl((unsigned int)a3, 1);
              goto LABEL_418;
            }
          }
          else
          {
            if ( a2 == 1074056980 )
            {
              is_vlan_mode = ipa3_put_hdr((unsigned int)a3);
              goto LABEL_418;
            }
            if ( a2 == 1074056981 )
            {
              is_vlan_mode = ipa3_cfg_filter((unsigned int)a3);
              goto LABEL_418;
            }
          }
        }
        else
        {
          if ( a2 <= 1074056970 )
          {
            if ( a2 == 1074056969 )
              is_vlan_mode = ipa3_reset_rt((unsigned int)a3, 0);
            else
              is_vlan_mode = ipa3_commit_flt((unsigned int)a3);
            goto LABEL_418;
          }
          if ( a2 == 1074056971 )
          {
            is_vlan_mode = ipa3_reset_flt((unsigned int)a3, 0);
            goto LABEL_418;
          }
          if ( a2 == 1074056974 )
          {
            is_vlan_mode = ipa_put_rt_tbl((unsigned int)a3);
            goto LABEL_418;
          }
        }
        goto LABEL_143;
      }
      if ( a2 > 52998 )
      {
        if ( a2 > 53048 )
        {
          if ( a2 == 53049 )
          {
            v50 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v51 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v51 )
              {
                ipc_log_string(v51, "ipa %s:%d Got IPA_IOC_QUERY_WLAN_CLIENT\n", "ipa3_ioctl", 3963);
                v50 = ipa3_ctx;
              }
              v8 = *(_QWORD *)(v50 + 34160);
              if ( v8 )
                v8 = ipc_log_string(v8, "ipa %s:%d Got IPA_IOC_QUERY_WLAN_CLIENT\n", "ipa3_ioctl", 3963);
            }
            is_vlan_mode = ipa3_resend_wlan_msg(v8);
            goto LABEL_418;
          }
          if ( a2 == 1074056968 )
          {
            is_vlan_mode = ipa3_commit_rt((unsigned int)a3);
            goto LABEL_418;
          }
        }
        else
        {
          if ( a2 == 52999 )
          {
            is_vlan_mode = ((__int64 (__fastcall *)(_QWORD))ipa3_reset_hdr)(0);
            goto LABEL_418;
          }
          if ( a2 == 53048 )
          {
            v21 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v22 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v22 )
              {
                ipc_log_string(v22, "ipa %s:%d Got IPA_IOC_CLEANUP\n", "ipa3_ioctl", 3950);
                v21 = ipa3_ctx;
              }
              v23 = *(_QWORD *)(v21 + 34160);
              if ( v23 )
                ipc_log_string(v23, "ipa %s:%d Got IPA_IOC_CLEANUP\n", "ipa3_ioctl", 3950);
            }
            ((void (__fastcall *)(__int64))ipa3_reset_hdr)(1);
            v240 = 0;
            v24 = ipa3_nat_del_cmd(&v240);
            if ( *(_DWORD *)(ipa3_ctx + 32256) == 2 )
              v25 = ipa3_clean_mhip_dl_rule(v24);
            else
              v25 = ipa3_clean_modem_rule(v24);
            v13 = v25;
            ipa3_counter_id_remove_all();
            v29 = 0;
            goto LABEL_526;
          }
        }
        goto LABEL_143;
      }
      if ( a2 != -1065037991 )
      {
        if ( a2 != -1060581551 )
        {
          if ( a2 == 52998 )
          {
            is_vlan_mode = ipa3_commit_hdr(v8);
            goto LABEL_418;
          }
          goto LABEL_143;
        }
        v69 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v70 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v70 )
          {
            ipc_log_string(v70, "ipa %s:%d Got IPA_IOC_SET_MAC_FLT\n", "ipa3_ioctl", 4093);
            v69 = ipa3_ctx;
          }
          v71 = *(_QWORD *)(v69 + 34160);
          if ( v71 )
            ipc_log_string(v71, "ipa %s:%d Got IPA_IOC_SET_MAC_FLT\n", "ipa3_ioctl", 4093);
        }
        v20 = ipa3_send_mac_flt_list(a3);
        goto LABEL_370;
      }
      v63 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v64 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v64 )
        {
          ipc_log_string(v64, "ipa %s:%d Got IPA_IOC_DEL_EoGRE_MAPPING\n", "ipa3_ioctl", 4220);
          v63 = ipa3_ctx;
        }
        v65 = *(_QWORD *)(v63 + 34160);
        if ( v65 )
          ipc_log_string(v65, "ipa %s:%d Got IPA_IOC_DEL_EoGRE_MAPPING\n", "ipa3_ioctl", 4220);
      }
      v264 = 0;
      v263 = 0;
      v262 = 0;
      v261 = 0;
      v260 = 0;
      v259 = 0;
      v258 = 0;
      v257 = 0;
      v256 = 0;
      v255 = 0;
      v254 = 0;
      v253 = 0;
      v252 = 0;
      v251 = 0;
      v250 = 0;
      v249 = 0;
      v248 = 0;
      is_vlan_mode = ipa3_check_eogre(&v248, v234, v233);
      if ( is_vlan_mode )
        goto LABEL_418;
      if ( v234[0] == 1 )
      {
        is_vlan_mode = ipa3_add_dscp_vlan_pcp_map(&v254);
        if ( is_vlan_mode )
          goto LABEL_418;
      }
      if ( v233[0] == 1 )
      {
        is_vlan_mode = ipa3_send_eogre_info(53, &v248);
        if ( is_vlan_mode )
          goto LABEL_418;
      }
      v13 = 0;
    }
    else
    {
      if ( a2 <= -1071591617 )
      {
        if ( a2 <= -1072640167 )
        {
          if ( a2 <= -1072640172 )
          {
            if ( a2 == -1072902326 )
            {
              if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x10u )
              {
                printk(&unk_3F173F, "ipa3_ioctl");
                v155 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v156 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v156 )
                  {
                    ipc_log_string(
                      v156,
                      "ipa %s:%d FNR stats not supported on IPA ver %d",
                      "ipa3_ioctl",
                      4014,
                      *(_DWORD *)(ipa3_ctx + 32240));
                    v155 = ipa3_ctx;
                  }
                  v157 = v155 + 32240;
                  v29 = *(_QWORD *)(v157 + 1920);
                  if ( !v29 )
                    goto LABEL_525;
                  ipc_log_string(
                    v29,
                    "ipa %s:%d FNR stats not supported on IPA ver %d",
                    "ipa3_ioctl",
                    4014,
                    *(_DWORD *)v157);
                }
                goto LABEL_524;
              }
              is_vlan_mode = ipa3_ioctl_fnr_counter_alloc(a3);
              goto LABEL_418;
            }
            if ( a2 == -1072902322 )
            {
              is_vlan_mode = proc_sram_info_rqst(a3);
              goto LABEL_418;
            }
            goto LABEL_143;
          }
          if ( a2 == -1072640171 )
          {
            v55 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v56 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v56 )
              {
                ipc_log_string(v56, "ipa %s:%d Got IPA_IOC_SET_SW_FLT\n", "ipa3_ioctl", 4101);
                v55 = ipa3_ctx;
              }
              v57 = *(_QWORD *)(v55 + 34160);
              if ( v57 )
                ipc_log_string(v57, "ipa %s:%d Got IPA_IOC_SET_SW_FLT\n", "ipa3_ioctl", 4101);
            }
            v20 = ipa3_send_sw_flt_list(a3);
          }
          else
          {
            if ( a2 != -1072640169 )
              goto LABEL_143;
            v33 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v34 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v34 )
              {
                ipc_log_string(v34, "ipa %s:%d Got IPA_IOC_SET_PKT_THRESHOLD\n", "ipa3_ioctl", 4178);
                v33 = ipa3_ctx;
              }
              v35 = *(_QWORD *)(v33 + 34160);
              if ( v35 )
                ipc_log_string(v35, "ipa %s:%d Got IPA_IOC_SET_PKT_THRESHOLD\n", "ipa3_ioctl", 4178);
            }
            v20 = ipa3_send_pkt_threshold(a3);
          }
LABEL_370:
          v120 = v20;
          v29 = 0;
          if ( v120 )
            v13 = -14;
          else
            v13 = 0;
          goto LABEL_526;
        }
        if ( (unsigned int)(a2 + 1072640164) >= 2 )
        {
          if ( a2 == -1072640166 )
          {
            v66 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v67 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v67 )
              {
                ipc_log_string(v67, "ipa %s:%d Got IPA_IOC_SET_IPPT_SW_FLT\n", "ipa3_ioctl", 4109);
                v66 = ipa3_ctx;
              }
              v68 = *(_QWORD *)(v66 + 34160);
              if ( v68 )
                ipc_log_string(v68, "ipa %s:%d Got IPA_IOC_SET_IPPT_SW_FLT\n", "ipa3_ioctl", 4109);
            }
            v20 = ipa3_send_ippt_sw_flt_list(a3);
            goto LABEL_370;
          }
          if ( a2 == -1072115892 )
          {
            if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x10u )
            {
              printk(&unk_3F173F, "ipa3_ioctl");
              v158 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v159 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v159 )
                {
                  ipc_log_string(
                    v159,
                    "ipa %s:%d FNR stats not supported on IPA ver %d",
                    "ipa3_ioctl",
                    4041,
                    *(_DWORD *)(ipa3_ctx + 32240));
                  v158 = ipa3_ctx;
                }
                v160 = v158 + 32240;
                v29 = *(_QWORD *)(v160 + 1920);
                if ( !v29 )
                  goto LABEL_525;
                ipc_log_string(
                  v29,
                  "ipa %s:%d FNR stats not supported on IPA ver %d",
                  "ipa3_ioctl",
                  4041,
                  *(_DWORD *)v160);
              }
              goto LABEL_524;
            }
            is_vlan_mode = ipa3_ioctl_fnr_counter_query(a3);
            goto LABEL_418;
          }
LABEL_143:
          _ipa3_dec_client_disable_clks(v8);
          result = -25;
          goto LABEL_528;
        }
        v43 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v44 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v44 )
          {
            if ( a2 == -1072640164 )
              v45 = "IPA_IOC_ADD_MACSEC_MAPPING";
            else
              v45 = "IPA_IOC_DEL_MACSEC_MAPPING";
            ipc_log_string(v44, "ipa %s:%d Got %s\n", "ipa3_ioctl", 4257, v45);
            v43 = ipa3_ctx;
          }
          v46 = *(_QWORD *)(v43 + 34160);
          if ( v46 )
          {
            if ( a2 == -1072640164 )
              v47 = "IPA_IOC_ADD_MACSEC_MAPPING";
            else
              v47 = "IPA_IOC_DEL_MACSEC_MAPPING";
            ipc_log_string(v46, "ipa %s:%d Got %s\n", "ipa3_ioctl", 4257, v47);
          }
        }
        if ( inline_copy_from_user((int)v235, a3, 0x10u) )
        {
          if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_493, "ipa3_ioctl") )
          {
            printk(&unk_3B7695, "ipa3_ioctl");
            v48 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_524;
          }
          else
          {
            v48 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_524;
          }
          v49 = *(_QWORD *)(v48 + 34152);
          if ( v49 )
          {
            ipc_log_string(v49, "ipa %s:%d copy_from_user for ipa_ioc_macsec_info fails\n", "ipa3_ioctl", 4260);
            v48 = ipa3_ctx;
          }
          v29 = *(_QWORD *)(v48 + 34160);
          if ( !v29 )
            goto LABEL_525;
          ipc_log_string(v29, "ipa %s:%d copy_from_user for ipa_ioc_macsec_info fails\n", "ipa3_ioctl", 4260);
          goto LABEL_524;
        }
        if ( (_DWORD)v236 != 64 )
        {
          if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_496, "ipa3_ioctl") )
          {
            printk(&unk_3A296E, "ipa3_ioctl");
            v135 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_524;
          }
          else
          {
            v135 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_524;
          }
          v136 = *(_QWORD *)(v135 + 34152);
          if ( v136 )
          {
            ipc_log_string(v136, "ipa %s:%d data size missmatch\n", "ipa3_ioctl", 4267);
            v135 = ipa3_ctx;
          }
          v29 = *(_QWORD *)(v135 + 34160);
          if ( !v29 )
            goto LABEL_525;
          ipc_log_string(v29, "ipa %s:%d data size missmatch\n", "ipa3_ioctl", 4267);
          goto LABEL_524;
        }
        v124 = _kmalloc_cache_noprof(ipc_log_string, 3520, 64);
        v125 = v124;
        if ( v124 )
        {
          if ( !inline_copy_from_user(v124, v235[0], 0x40u) )
          {
            if ( a2 == -1072640164 )
              v140 = 55;
            else
              v140 = 56;
            ipa3_send_macsec_info(v140, v125);
            goto LABEL_62;
          }
          if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_503, "ipa3_ioctl") )
          {
            printk(&unk_3CBAFB, "ipa3_ioctl");
            v126 = ipa3_ctx;
            if ( ipa3_ctx )
              goto LABEL_389;
          }
          else
          {
            v126 = ipa3_ctx;
            if ( ipa3_ctx )
            {
LABEL_389:
              v127 = *(_QWORD *)(v126 + 34152);
              if ( v127 )
              {
                ipc_log_string(v127, "ipa %s:%d copy_from_user for ipa_macsec_map fails\n", "ipa3_ioctl", 4281);
                v126 = ipa3_ctx;
              }
              v128 = *(_QWORD *)(v126 + 34160);
              if ( v128 )
                ipc_log_string(v128, "ipa %s:%d copy_from_user for ipa_macsec_map fails\n", "ipa3_ioctl", 4281);
            }
          }
          kfree(v125);
          goto LABEL_524;
        }
        printk(&unk_3CF11A, "ipa3_ioctl");
        v225 = ipa3_ctx;
        if ( !ipa3_ctx )
        {
LABEL_702:
          v29 = 0;
          v13 = -12;
          goto LABEL_526;
        }
        v226 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v226 )
        {
          ipc_log_string(v226, "ipa %s:%d macsec_map memory allocation failed !\n", "ipa3_ioctl", 4274);
          v225 = ipa3_ctx;
        }
        v29 = *(_QWORD *)(v225 + 34160);
        if ( v29 )
        {
          ipc_log_string(v29, "ipa %s:%d macsec_map memory allocation failed !\n", "ipa3_ioctl", 4274);
          goto LABEL_702;
        }
LABEL_703:
        v13 = -12;
        goto LABEL_526;
      }
      if ( a2 <= -1070805189 )
      {
        if ( a2 <= -1071591599 )
        {
          if ( a2 == -1071591616 )
          {
            v52 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v53 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v53 )
              {
                ipc_log_string(v53, "ipa %s:%d Got IPA_IOC_GSB_CONNECT\n", "ipa3_ioctl", 3968);
                v52 = ipa3_ctx;
              }
              v54 = *(_QWORD *)(v52 + 34160);
              if ( v54 )
                ipc_log_string(v54, "ipa %s:%d Got IPA_IOC_GSB_CONNECT\n", "ipa3_ioctl", 3968);
            }
            v20 = ipa3_send_gsb_msg(a3, 35);
          }
          else
          {
            if ( a2 != -1071591615 )
              goto LABEL_143;
            v17 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v18 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v18 )
              {
                ipc_log_string(v18, "ipa %s:%d Got IPA_IOC_GSB_DISCONNECT\n", "ipa3_ioctl", 3976);
                v17 = ipa3_ctx;
              }
              v19 = *(_QWORD *)(v17 + 34160);
              if ( v19 )
                ipc_log_string(v19, "ipa %s:%d Got IPA_IOC_GSB_DISCONNECT\n", "ipa3_ioctl", 3976);
            }
            v20 = ipa3_send_gsb_msg(a3, 36);
          }
          goto LABEL_370;
        }
        if ( a2 != -1071591598 )
        {
          if ( a2 != -1070805189 )
            goto LABEL_143;
          v36 = a3;
          v37 = 32;
          goto LABEL_369;
        }
        v58 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v59 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v59 )
          {
            ipc_log_string(v59, "ipa %s:%d Got IPA_IOC_GET_EP_INFO\n", "ipa3_ioctl", 4117);
            v58 = ipa3_ctx;
          }
          v60 = *(_QWORD *)(v58 + 34160);
          if ( v60 )
            ipc_log_string(v60, "ipa %s:%d Got IPA_IOC_GET_EP_INFO\n", "ipa3_ioctl", 4117);
        }
        if ( inline_copy_from_user((int)&v229, a3, 0x20u) )
        {
          if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_465, "ipa3_ioctl") )
          {
            printk(&unk_3F47D5, "ipa3_ioctl");
            v61 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_524;
          }
          else
          {
            v61 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_524;
          }
          v62 = *(_QWORD *)(v61 + 34152);
          if ( v62 )
          {
            ipc_log_string(v62, "ipa %s:%d copy_from_user fails\n", "ipa3_ioctl", 4121);
            v61 = ipa3_ctx;
          }
          v29 = *(_QWORD *)(v61 + 34160);
          if ( !v29 )
            goto LABEL_525;
          ipc_log_string(v29, "ipa %s:%d copy_from_user fails\n", "ipa3_ioctl", 4121);
          goto LABEL_524;
        }
        if ( (unsigned __int8)v230 != 2 )
        {
          if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_466, "ipa3_ioctl") )
          {
            printk(&unk_3AC08D, "ipa3_ioctl");
            v137 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_524;
          }
          else
          {
            v137 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_524;
          }
          v138 = *(_QWORD *)(v137 + 34152);
          if ( v138 )
          {
            ipc_log_string(v138, "ipa %s:%d unexpected max_ep_pairs %d\n", "ipa3_ioctl", 4128, (unsigned __int8)v230);
            v137 = ipa3_ctx;
          }
          v29 = *(_QWORD *)(v137 + 34160);
          if ( !v29 )
            goto LABEL_525;
          ipc_log_string(v29, "ipa %s:%d unexpected max_ep_pairs %d\n", "ipa3_ioctl", 4128, (unsigned __int8)v230);
          goto LABEL_524;
        }
        if ( HIDWORD(v229) != 32 )
        {
          if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_469, "ipa3_ioctl") )
          {
            printk(&unk_3CBAD3, "ipa3_ioctl");
            v141 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_524;
          }
          else
          {
            v141 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_524;
          }
          v142 = *(_QWORD *)(v141 + 34152);
          if ( v142 )
          {
            ipc_log_string(v142, "ipa %s:%d unexpected ep_pair_size %d\n", "ipa3_ioctl", 4136, (unsigned __int8)v230);
            v141 = ipa3_ctx;
          }
          v29 = *(_QWORD *)(v141 + 34160);
          if ( !v29 )
            goto LABEL_525;
          ipc_log_string(v29, "ipa %s:%d unexpected ep_pair_size %d\n", "ipa3_ioctl", 4136, (unsigned __int8)v230);
          goto LABEL_524;
        }
        v129 = v231;
        if ( !v231 )
        {
          if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_472, "ipa3_ioctl") )
          {
            printk(&unk_3DDB8B, "ipa3_ioctl");
            v214 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_524;
          }
          else
          {
            v214 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_524;
          }
          v215 = *(_QWORD *)(v214 + 34152);
          if ( v215 )
          {
            ipc_log_string(v215, "ipa %s:%d unexpected NULL info\n", "ipa3_ioctl", 4143);
            v214 = ipa3_ctx;
          }
          v29 = *(_QWORD *)(v214 + 34160);
          if ( !v29 )
            goto LABEL_525;
          ipc_log_string(v29, "ipa %s:%d unexpected NULL info\n", "ipa3_ioctl", 4143);
          goto LABEL_524;
        }
        v130 = _kmalloc_noprof(HIDWORD(v229), 3520);
        if ( !v130 )
        {
          if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_477, "ipa3_ioctl") )
          {
            printk(&unk_3CF0FF, "ipa3_ioctl");
            v227 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_702;
          }
          else
          {
            v227 = ipa3_ctx;
            if ( !ipa3_ctx )
              goto LABEL_702;
          }
          v228 = *(_QWORD *)(v227 + 34152);
          if ( v228 )
          {
            ipc_log_string(v228, "ipa %s:%d kzalloc fails\n", "ipa3_ioctl", 4150);
            v227 = ipa3_ctx;
          }
          v29 = *(_QWORD *)(v227 + 34160);
          if ( v29 )
          {
            ipc_log_string(v29, "ipa %s:%d kzalloc fails\n", "ipa3_ioctl", 4150);
            goto LABEL_702;
          }
          goto LABEL_703;
        }
        v12 = (unsigned __int8 *)v130;
        if ( (ipa3_get_ep_info(&v229) & 0x80000000) != 0 )
        {
          printk(&unk_3EE4EF, "ipa3_ioctl");
          v166 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v167 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v167 )
            {
              ipc_log_string(v167, "ipa %s:%d ipa3_get_ep_info failed\n", "ipa3_ioctl", 4157);
              v166 = ipa3_ctx;
            }
            v168 = *(_QWORD *)(v166 + 34160);
            if ( v168 )
              ipc_log_string(v168, "ipa %s:%d ipa3_get_ep_info failed\n", "ipa3_ioctl", 4157);
          }
          goto LABEL_534;
        }
        v131 = HIDWORD(v229);
        if ( v229 < 0 )
        {
          __break(0x800u);
        }
        else
        {
          _check_object_size(v12, HIDWORD(v229), 1);
          if ( !inline_copy_to_user(v129, v12, v131) )
          {
            if ( !inline_copy_to_user(a3, &v229, 32) )
            {
              v13 = 0;
              goto LABEL_436;
            }
            if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_485, "ipa3_ioctl") )
            {
              printk(&unk_3F1771, "ipa3_ioctl");
              v163 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            else
            {
              v163 = ipa3_ctx;
              if ( !ipa3_ctx )
                goto LABEL_534;
            }
            v164 = *(_QWORD *)(v163 + 34152);
            if ( v164 )
            {
              ipc_log_string(v164, "ipa %s:%d copy_to_user fails\n", "ipa3_ioctl", 4171);
              v163 = ipa3_ctx;
            }
            v165 = *(_QWORD *)(v163 + 34160);
            if ( v165 )
              ipc_log_string(v165, "ipa %s:%d copy_to_user fails\n", "ipa3_ioctl", 4171);
            goto LABEL_534;
          }
        }
        if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_482, "ipa3_ioctl") )
        {
          printk(&unk_3F1771, "ipa3_ioctl");
          v132 = ipa3_ctx;
          if ( ipa3_ctx )
            goto LABEL_405;
        }
        else
        {
          v132 = ipa3_ctx;
          if ( ipa3_ctx )
          {
LABEL_405:
            v133 = *(_QWORD *)(v132 + 34152);
            if ( v133 )
            {
              ipc_log_string(v133, "ipa %s:%d copy_to_user fails\n", "ipa3_ioctl", 4164);
              v132 = ipa3_ctx;
            }
            v134 = *(_QWORD *)(v132 + 34160);
            if ( v134 )
              ipc_log_string(v134, "ipa %s:%d copy_to_user fails\n", "ipa3_ioctl", 4164);
          }
        }
LABEL_534:
        v13 = -14;
LABEL_436:
        v29 = (__int64)v12;
        if ( (unsigned __int64)v12 > 0xFFFFFFFFFFFFF000LL )
          goto LABEL_527;
        goto LABEL_526;
      }
      if ( a2 <= -1069494449 )
      {
        if ( a2 != -1070805188 )
        {
          if ( a2 == -1070805182 )
          {
            v30 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v31 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v31 )
              {
                ipc_log_string(v31, "ipa %s:%d Got IPA_IOCTL_WIGIG_FST_SWITCH\n", "ipa3_ioctl", 4059);
                v30 = ipa3_ctx;
              }
              v32 = *(_QWORD *)(v30 + 34160);
              if ( v32 )
                ipc_log_string(v32, "ipa %s:%d Got IPA_IOCTL_WIGIG_FST_SWITCH\n", "ipa3_ioctl", 4059);
            }
            if ( inline_copy_from_user((int)v265, a3, 0x2Cu) )
              goto LABEL_524;
            HIBYTE(v266) = 0;
            is_vlan_mode = ipa_wigig_send_msg(41, v265, &v267, 134, v268 != 0);
            goto LABEL_418;
          }
          goto LABEL_143;
        }
        v36 = a3;
        v37 = 33;
LABEL_369:
        v20 = ipa3_send_vlan_l2tp_msg(v36, v37);
        goto LABEL_370;
      }
      if ( a2 == -1069494448 )
      {
        v20 = ipa3_send_pdn_config_msg(a3);
        goto LABEL_370;
      }
      if ( a2 != -1065037992 )
        goto LABEL_143;
      v38 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v39 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v39 )
        {
          ipc_log_string(v39, "ipa %s:%d Got IPA_IOC_ADD_EoGRE_MAPPING\n", "ipa3_ioctl", 4184);
          v38 = ipa3_ctx;
        }
        v40 = *(_QWORD *)(v38 + 34160);
        if ( v40 )
          ipc_log_string(v40, "ipa %s:%d Got IPA_IOC_ADD_EoGRE_MAPPING\n", "ipa3_ioctl", 4184);
      }
      if ( inline_copy_from_user((int)&v248, a3, 0x84u) )
      {
        if ( (unsigned int)__ratelimit(&ipa3_ioctl__rs_488, "ipa3_ioctl") )
        {
          printk(&unk_3F47D5, "ipa3_ioctl");
          v41 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_524;
        }
        else
        {
          v41 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_524;
        }
        v42 = *(_QWORD *)(v41 + 34152);
        if ( v42 )
        {
          ipc_log_string(v42, "ipa %s:%d copy_from_user fails\n", "ipa3_ioctl", 4189);
          v41 = ipa3_ctx;
        }
        v29 = *(_QWORD *)(v41 + 34160);
        if ( !v29 )
          goto LABEL_525;
        ipc_log_string(v29, "ipa %s:%d copy_from_user fails\n", "ipa3_ioctl", 4189);
        goto LABEL_524;
      }
      v13 = ipa3_check_eogre(&v248, v234, v233);
      *(_BYTE *)(ipa3_ctx + 51240) = v13 == 0;
      if ( !v13 && (v234[0] != 1 || (v13 = ipa3_add_dscp_vlan_pcp_map(&v254)) == 0) )
      {
        if ( v233[0] != 1 )
          goto LABEL_62;
        v13 = ipa3_send_eogre_info(52, &v248);
        if ( !v13 )
        {
LABEL_364:
          v29 = 0;
          goto LABEL_526;
        }
      }
    }
    v29 = 0;
    *(_BYTE *)(ipa3_ctx + 51240) = 0;
    goto LABEL_526;
  }
  result = -25;
LABEL_528:
  _ReadStatusReg(SP_EL0);
  return result;
}
