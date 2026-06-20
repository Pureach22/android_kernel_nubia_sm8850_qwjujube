__int64 __fastcall ipa_fltrt_generate_hw_rule_bdy_ip6(_WORD *a1, int *a2, _BYTE **a3, _WORD **a4)
{
  _BYTE *v8; // x1
  _WORD *v9; // x9
  int v10; // w8
  __int64 v11; // x8
  _BYTE *v12; // x0
  unsigned int v13; // w24
  int v14; // w8
  _BYTE *v15; // x23
  _BYTE *v16; // x23
  _WORD *v17; // x0
  int v18; // w8
  _WORD *v19; // x0
  char v20; // w8
  _BYTE *v21; // x0
  _BYTE *v22; // x0
  int v23; // w8
  _WORD *v24; // x1
  int v25; // w0
  _WORD *v26; // x1
  int v27; // w0
  _WORD *v28; // x1
  int v29; // w0
  _WORD *v30; // x1
  int v31; // w0
  _WORD *v32; // x1
  int v33; // w0
  _WORD *v34; // x1
  int v35; // w0
  _WORD *v36; // x1
  int v37; // w0
  _WORD *v38; // x0
  unsigned __int8 v39; // w25
  unsigned int v40; // w8
  __int64 v41; // x9
  _BYTE *v42; // x0
  int v43; // w8
  _WORD *v44; // x1
  int v45; // w0
  _WORD *v46; // x1
  int v47; // w0
  _WORD *v48; // x1
  int v49; // w0
  _WORD *v50; // x1
  int v51; // w0
  _WORD *v52; // x1
  int v53; // w0
  _WORD *v54; // x1
  int v55; // w0
  _WORD *v56; // x1
  int v57; // w0
  _WORD *v58; // x0
  unsigned __int8 v59; // w25
  unsigned int v60; // w8
  __int64 v61; // x9
  _QWORD *v62; // x0
  _DWORD *v63; // x0
  _WORD *v64; // x0
  int v65; // w8
  _WORD *v66; // x0
  _BYTE *v67; // x1
  _WORD *v68; // x0
  unsigned int v69; // w8
  _WORD *v70; // x0
  unsigned int v71; // w8
  _WORD *v72; // x0
  int v73; // w8
  unsigned int v74; // w8
  __int64 v75; // x9
  _BYTE *v76; // x1
  _WORD *v77; // x1
  int v78; // w0
  _WORD *v79; // x0
  unsigned int v80; // w8
  __int64 v81; // x9
  _BYTE *v82; // x1
  _WORD *v83; // x1
  int v84; // w0
  _WORD *v85; // x0
  unsigned int v86; // w8
  __int64 v87; // x9
  _BYTE *v88; // x1
  _WORD *v89; // x1
  int v90; // w0
  _WORD *v91; // x0
  int v92; // w8
  unsigned int v93; // w8
  __int64 v94; // x9
  _BYTE *v95; // x1
  _BYTE *v96; // x23
  _WORD *v97; // x1
  char v98; // w8
  unsigned int v99; // w9
  __int16 v100; // w9
  _BYTE *v101; // x1
  _BYTE *v102; // x23
  _WORD *v103; // x1
  char v104; // w0
  _WORD *v105; // x1
  char v106; // w0
  _WORD *v107; // x1
  char v108; // w0
  _WORD *v109; // x1
  char v110; // w0
  _WORD *v111; // x1
  char v112; // w0
  _WORD *v113; // x1
  char v114; // w0
  _WORD *v115; // x1
  char v116; // w0
  _WORD *v117; // x1
  char v118; // w0
  _WORD *v119; // x1
  char v120; // w0
  _WORD *v121; // x1
  char v122; // w0
  _WORD *v123; // x1
  char v124; // w0
  _WORD *v125; // x0
  int v126; // w8
  unsigned __int8 v127; // w23
  unsigned int v128; // w8
  __int64 v129; // x9
  _BYTE *v130; // x1
  _WORD *v131; // x1
  __int16 v132; // w0
  _WORD *v133; // x1
  __int16 v134; // w0
  _WORD *v135; // x0
  unsigned int v136; // w9
  __int16 v137; // w9
  _BYTE *v138; // x1
  _BYTE *v139; // x23
  _WORD *v140; // x1
  int v141; // w0
  _WORD *v142; // x0
  int v143; // w8
  char v144; // w0
  _BYTE *v145; // x23
  _WORD *v146; // x0
  char v147; // w8
  int v148; // w8
  unsigned int v149; // w9
  __int16 v150; // w9
  _BYTE *v151; // x1
  _BYTE *v152; // x23
  _WORD *v153; // x1
  char v154; // w0
  _WORD *v155; // x1
  char v156; // w0
  _WORD *v157; // x1
  char v158; // w0
  _WORD *v159; // x1
  char v160; // w0
  _WORD *v161; // x1
  char v162; // w0
  _WORD *v163; // x1
  char v164; // w0
  _WORD *v165; // x1
  char v166; // w0
  _WORD *v167; // x1
  char v168; // w0
  _WORD *v169; // x1
  char v170; // w0
  _WORD *v171; // x1
  char v172; // w0
  _WORD *v173; // x1
  char v174; // w0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v177; // x0
  __int64 v178; // x0
  __int64 v179; // x0
  __int64 v180; // x0
  int v181; // w9
  unsigned int v182; // w8
  __int64 v183; // x9
  _BYTE *v184; // x1
  _WORD *v185; // x0
  unsigned int v186; // w9
  __int16 v187; // w9
  _BYTE *v188; // x1
  _BYTE *v189; // x23
  _WORD *v190; // x1
  int v191; // w0
  _WORD *v192; // x0
  int v193; // w8
  char v194; // w0
  _BYTE *v195; // x23
  _WORD *v196; // x0
  unsigned int v197; // w8
  __int64 v198; // x9
  _BYTE *v199; // x1
  _WORD *v200; // x0
  int v201; // w8
  _DWORD *v202; // x1
  int v203; // w0
  _WORD *v204; // x0
  unsigned int v205; // w8
  __int64 v206; // x9
  _BYTE *v207; // x1
  _BYTE *v208; // x0
  int v209; // w8
  _WORD *v210; // x1
  int v211; // w0
  _WORD *v212; // x0
  _DWORD *v213; // x1
  _WORD *v214; // x1
  int v215; // w0
  _WORD *v216; // x0
  unsigned int v217; // w23
  __int64 result; // x0
  _BYTE *v219; // x1
  _BYTE *v220; // x0
  __int16 v221; // w8
  _WORD *v222; // x1
  __int16 v223; // w0
  _WORD *v224; // x0
  unsigned int v225; // w8
  __int64 v226; // x9
  _BYTE *v227; // x1
  _BYTE *v228; // x0
  __int16 v229; // w8
  _WORD *v230; // x1
  __int16 v231; // w0
  _WORD *v232; // x0
  unsigned int v233; // w8
  __int64 v234; // x9
  _BYTE *v235; // x1
  _BYTE *v236; // x0
  __int16 v237; // w8
  _WORD *v238; // x1
  __int16 v239; // w0
  _WORD *v240; // x0
  unsigned int v241; // w8
  __int64 v242; // x9
  _BYTE *v243; // x1
  _BYTE *v244; // x0
  __int16 v245; // w8
  _WORD *v246; // x1
  __int16 v247; // w0
  _WORD *v248; // x0
  unsigned int v249; // w8
  __int64 v250; // x9
  _BYTE *v251; // x1
  _BYTE *v252; // x23
  _WORD *v253; // x1
  __int16 v254; // w0
  _WORD *v255; // x0
  _DWORD *v256; // x1
  _WORD *v257; // x0
  int v258; // w8
  __int64 v259; // x0
  __int64 v260; // x0
  __int64 v261; // x0
  __int64 v262; // x0
  __int64 v263; // x0
  __int64 v264; // x0
  __int64 v265; // x0
  __int64 v266; // x0
  __int64 v267; // x0
  __int64 v268; // x0
  __int64 v269; // x0
  __int64 v270; // x0
  __int64 v271; // x0
  __int64 v272; // x0
  __int64 v273; // x0
  __int64 v274; // x0
  __int64 v275; // x0
  __int64 v276; // x0
  __int64 v277; // x0
  __int64 v278; // x0
  __int64 v279; // x0
  __int64 v280; // x0
  __int64 v281; // x0
  __int64 v282; // x0
  __int64 v283; // x0
  __int64 v284; // x0
  __int64 v285; // x0
  __int64 v286; // x0
  __int64 v287; // x0
  __int64 v288; // x0
  __int64 v289; // x0
  __int64 v290; // x0
  _WORD *v291; // x9
  unsigned __int8 v292[4]; // [xsp+0h] [xbp-20h] BYREF
  unsigned __int8 v293[4]; // [xsp+4h] [xbp-1Ch] BYREF
  _WORD *v294; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v295[2]; // [xsp+10h] [xbp-10h] BYREF

  v295[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *a3;
  v9 = *a4;
  v10 = *a2;
  v293[0] = 0;
  v294 = v9;
  v295[0] = v8;
  v292[0] = 0;
  if ( (v10 & 0x8000000) != 0 )
  {
    if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
      goto LABEL_237;
    v11 = LOBYTE(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 18]);
    if ( v11 == 255 )
    {
      printk(&unk_3D1887, "ipa_fltrt_generate_hw_rule_bdy_ip6");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipahal %s:%d is_pure_ack eq not supported\n",
          "ipa_fltrt_generate_hw_rule_bdy_ip6",
          1888);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipahal %s:%d is_pure_ack eq not supported\n",
          "ipa_fltrt_generate_hw_rule_bdy_ip6",
          1888);
      }
      goto LABEL_235;
    }
    *a1 |= 1LL << v11;
    v12 = ipa_write_8(0, v8);
    v10 = *a2;
    v8 = v12;
    v295[0] = v12;
  }
  if ( (v10 & 0x2000) != 0 )
  {
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_237;
    *a1 |= 1LL << BYTE1(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 16]);
    v8 = ipa_write_8(*((_BYTE *)a2 + 68), v8);
    v295[0] = v8;
  }
  if ( (a2[35] & 0x10) != 0 )
  {
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_237;
    v13 = 1;
    *a1 |= 1LL << HIBYTE(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 16]);
    v16 = ipa_write_8(134, v8);
    v17 = ipa_write_32(-16777216, v294);
    v18 = *((unsigned __int8 *)a2 + 68);
    v294 = v17;
    v19 = ipa_write_32(v18 << 24, v17);
    v20 = *((_BYTE *)a2 + 68);
    v294 = v19;
    v8 = ipa_write_8(v20, v16);
    v295[0] = v8;
    v14 = *a2;
    if ( (*a2 & 0x800) == 0 )
    {
LABEL_10:
      if ( (v14 & 4) == 0 )
        goto LABEL_11;
      goto LABEL_18;
    }
  }
  else
  {
    v13 = 0;
    v14 = *a2;
    if ( (*a2 & 0x800) == 0 )
      goto LABEL_10;
  }
  if ( *(_DWORD *)ipahal_ctx > 0x19u )
    goto LABEL_237;
  *a1 |= 1LL << BYTE2(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 16]);
  v21 = ipa_write_8(*((_BYTE *)a2 + 60), v8);
  v14 = *a2;
  v8 = v21;
  v295[0] = v21;
  if ( (v14 & 4) == 0 )
  {
LABEL_11:
    v15 = v8;
    if ( (v14 & 8) == 0 )
      goto LABEL_12;
LABEL_20:
    v39 = v292[0];
    if ( v292[0] >= 2u )
    {
      printk(&unk_3BFBF4, "ipa_fltrt_generate_hw_rule_bdy_ip6");
      if ( ipa3_get_ipc_logbuf() )
      {
        v177 = ipa3_get_ipc_logbuf();
        ipc_log_string(v177, "ipahal %s:%d ran out of meq128 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 1938);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v178 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v178, "ipahal %s:%d ran out of meq128 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 1938);
      }
      goto LABEL_235;
    }
    v40 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_237;
    v41 = *((int *)&ipa3_0_ofst_meq128 + v292[0]);
    if ( v41 + 152 * (unsigned __int64)v40 + 128 > 0xF6F )
      goto LABEL_238;
    *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v40 + 16] + v41);
    v42 = ipa_write_8(24, v15);
    v43 = a2[33];
    v15 = v42;
    v295[0] = v42;
    v44 = ipa_write_32(v43, v294);
    v45 = a2[32];
    v294 = v44;
    v46 = ipa_write_32(v45, v44);
    v47 = a2[29];
    v294 = v46;
    v48 = ipa_write_32(v47, v46);
    v49 = a2[28];
    v294 = v48;
    v50 = ipa_write_32(v49, v48);
    v51 = a2[31];
    v294 = v50;
    v52 = ipa_write_32(v51, v50);
    v53 = a2[30];
    v294 = v52;
    v54 = ipa_write_32(v53, v52);
    v55 = a2[27];
    v294 = v54;
    v56 = ipa_write_32(v55, v54);
    v57 = a2[26];
    v294 = v56;
    v58 = ipa_write_32(v57, v56);
    v14 = *a2;
    v294 = v58;
    v292[0] = v39 + 1;
    if ( (v14 & 0x10000) == 0 )
      goto LABEL_28;
    goto LABEL_24;
  }
LABEL_18:
  if ( *(_DWORD *)ipahal_ctx > 0x19u )
    goto LABEL_237;
  *a1 |= 1LL << BYTE3(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 16]);
  v22 = ipa_write_8(8, v8);
  v23 = a2[25];
  v15 = v22;
  v295[0] = v22;
  v24 = ipa_write_32(v23, v294);
  v25 = a2[24];
  v294 = v24;
  v26 = ipa_write_32(v25, v24);
  v27 = a2[21];
  v294 = v26;
  v28 = ipa_write_32(v27, v26);
  v29 = a2[20];
  v294 = v28;
  v30 = ipa_write_32(v29, v28);
  v31 = a2[23];
  v294 = v30;
  v32 = ipa_write_32(v31, v30);
  v33 = a2[22];
  v294 = v32;
  v34 = ipa_write_32(v33, v32);
  v35 = a2[19];
  v294 = v34;
  v36 = ipa_write_32(v35, v34);
  v37 = a2[18];
  v294 = v36;
  v38 = ipa_write_32(v37, v36);
  v14 = *a2;
  v294 = v38;
  v292[0] = 1;
  if ( (v14 & 8) != 0 )
    goto LABEL_20;
LABEL_12:
  if ( (v14 & 0x10000) == 0 )
    goto LABEL_28;
LABEL_24:
  v59 = v292[0];
  if ( v292[0] >= 2u )
  {
    printk(&unk_3BFBF4, "ipa_fltrt_generate_hw_rule_bdy_ip6");
    if ( ipa3_get_ipc_logbuf() )
    {
      v179 = ipa3_get_ipc_logbuf();
      ipc_log_string(v179, "ipahal %s:%d ran out of meq128 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 1958);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v180 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v180, "ipahal %s:%d ran out of meq128 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 1958);
    }
    goto LABEL_235;
  }
  v60 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx > 0x19u )
    goto LABEL_237;
  v61 = *((int *)&ipa3_0_ofst_meq128 + v292[0]);
  if ( v61 + 152 * (unsigned __int64)v60 + 128 > 0xF6F )
    goto LABEL_238;
  *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v60 + 16] + v61);
  v295[0] = ipa_write_8(0, v15);
  v62 = ipa_write_64(0, v294);
  v294 = ipa_write_64(0, v62);
  v63 = ipa_write_32(0, v294);
  v294 = ipa_write_32(*((unsigned __int8 *)a2 + 15) << 20, v63);
  v64 = ipa_write_32(0, v294);
  v65 = *((unsigned __int8 *)a2 + 14);
  v294 = v64;
  v66 = ipa_write_32(v65 << 20, v64);
  v14 = *a2;
  v294 = v66;
  v292[0] = v59 + 1;
LABEL_28:
  if ( (v14 & 0x601E0000) != 0 )
  {
    if ( (unsigned int)ipa_fltrt_generate_mac_hw_rule_bdy(a1, a2, v292, v295, &v294) )
      goto LABEL_235;
    v14 = *a2;
  }
  if ( (v14 & 0x200000) != 0 )
  {
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_237;
    v67 = (_BYTE *)v295[0];
    *a1 |= 1LL << BYTE5(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 16]);
    v295[0] = ipa_write_8(254, v67);
    v68 = ipa_write_16(0, v294);
    v69 = *((unsigned __int16 *)a2 + 28);
    v294 = v68;
    v294 = ipa_write_16(bswap32(v69) >> 16, v68);
    v70 = ipa_write_16(0, v294);
    v71 = *((unsigned __int16 *)a2 + 28);
    v294 = v70;
    v72 = ipa_write_16(bswap32(v71) >> 16, v70);
    v293[0] = 1;
    v294 = v72;
  }
  if ( (unsigned int)ipa_fltrt_generate_vlan_hw_rule_bdy(a1, a2, v293, v295, &v294) )
  {
LABEL_235:
    result = 0xFFFFFFFFLL;
    goto LABEL_236;
  }
  v73 = *a2;
  if ( (*a2 & 0x40) != 0 )
  {
    v74 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_237;
    v75 = *((int *)&ipa3_0_ihl_ofst_meq32 + v13);
    if ( v75 + 152 * (unsigned __int64)v74 + 128 > 0xF6F )
      goto LABEL_238;
    v76 = (_BYTE *)v295[0];
    *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v74 + 16] + v75);
    v295[0] = ipa_write_8(0, v76);
    v77 = ipa_write_32(255, v294);
    v78 = *((unsigned __int8 *)a2 + 12);
    v294 = v77;
    v79 = ipa_write_32(v78, v77);
    v73 = *a2;
    ++v13;
    v294 = v79;
  }
  if ( (v73 & 0x80) != 0 )
  {
    if ( v13 >= 2 )
    {
      printk(&unk_3FA19A, "ipa_fltrt_generate_hw_rule_bdy_ip6");
      if ( ipa3_get_ipc_logbuf() )
      {
        v267 = ipa3_get_ipc_logbuf();
        ipc_log_string(v267, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2018);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v268 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v268, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2018);
      }
      goto LABEL_235;
    }
    v80 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_237;
    v81 = *((int *)&ipa3_0_ihl_ofst_meq32 + v13);
    if ( v81 + 152 * (unsigned __int64)v80 + 128 > 0xF6F )
      goto LABEL_238;
    v82 = (_BYTE *)v295[0];
    *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v80 + 16] + v81);
    v295[0] = ipa_write_8(1, v82);
    v83 = ipa_write_32(255, v294);
    v84 = *((unsigned __int8 *)a2 + 13);
    v294 = v83;
    v85 = ipa_write_32(v84, v83);
    v73 = *a2;
    ++v13;
    v294 = v85;
  }
  if ( (v73 & 0x100) != 0 )
  {
    if ( v13 >= 2 )
    {
      printk(&unk_3FA19A, "ipa_fltrt_generate_hw_rule_bdy_ip6");
      if ( ipa3_get_ipc_logbuf() )
      {
        v269 = ipa3_get_ipc_logbuf();
        ipc_log_string(v269, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2033);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v270 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v270, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2033);
      }
      goto LABEL_235;
    }
    v86 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_237;
    v87 = *((int *)&ipa3_0_ihl_ofst_meq32 + v13);
    if ( v87 + 152 * (unsigned __int64)v86 + 128 > 0xF6F )
      goto LABEL_238;
    v88 = (_BYTE *)v295[0];
    *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v86 + 16] + v87);
    v295[0] = ipa_write_8(0, v88);
    v89 = ipa_write_32(-1, v294);
    v90 = a2[4];
    v294 = v89;
    v91 = ipa_write_32(v90, v89);
    v73 = *a2;
    ++v13;
    v294 = v91;
  }
  if ( (v73 & 0x400000) != 0 )
  {
    if ( v13 )
    {
      printk(&unk_3FA19A, "ipa_fltrt_generate_hw_rule_bdy_ip6");
      if ( ipa3_get_ipc_logbuf() )
      {
        v271 = ipa3_get_ipc_logbuf();
        ipc_log_string(v271, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2049);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v272 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v272, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2049);
      }
      goto LABEL_235;
    }
    v99 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_237;
    if ( 152 * (unsigned __int64)v99 + 135 > 0xF6F )
      goto LABEL_238;
    v100 = *a1 | (1LL << HIBYTE(ipahal_fltrt_objs[19 * v99 + 16]));
    *a1 = v100;
    if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
      goto LABEL_237;
    v101 = (_BYTE *)v295[0];
    *a1 = v100 | (1LL << LOBYTE(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 17]));
    v102 = ipa_write_8(8, v101);
    v103 = ipa_write_8(*((_BYTE *)a2 + 53), v294);
    v104 = *((_BYTE *)a2 + 52);
    v294 = v103;
    v105 = ipa_write_8(v104, v103);
    v106 = *((_BYTE *)a2 + 51);
    v294 = v105;
    v107 = ipa_write_8(v106, v105);
    v108 = *((_BYTE *)a2 + 50);
    v294 = v107;
    v109 = ipa_write_8(v108, v107);
    v110 = *((_BYTE *)a2 + 47);
    v294 = v109;
    v111 = ipa_write_8(v110, v109);
    v112 = *((_BYTE *)a2 + 46);
    v294 = v111;
    v113 = ipa_write_8(v112, v111);
    v114 = *((_BYTE *)a2 + 45);
    v294 = v113;
    v115 = ipa_write_8(v114, v113);
    v116 = *((_BYTE *)a2 + 44);
    v294 = v115;
    v294 = ipa_write_8(v116, v115);
    v295[0] = ipa_write_8(12, v102);
    v117 = ipa_write_16(0, v294);
    v118 = *((_BYTE *)a2 + 55);
    v294 = v117;
    v119 = ipa_write_8(v118, v117);
    v120 = *((_BYTE *)a2 + 54);
    v294 = v119;
    v294 = ipa_write_8(v120, v119);
    v121 = ipa_write_16(0, v294);
    v122 = *((_BYTE *)a2 + 49);
    v294 = v121;
    v123 = ipa_write_8(v122, v121);
    v124 = *((_BYTE *)a2 + 48);
    v294 = v123;
    v125 = ipa_write_8(v124, v123);
    v126 = *a2;
    v294 = v125;
    if ( (v126 & 0x80000000) == 0 )
    {
      v13 = 2;
      v92 = a2[35];
      if ( (v92 & 2) != 0 )
        goto LABEL_65;
      goto LABEL_52;
    }
LABEL_171:
    printk(&unk_3FA19A, "ipa_fltrt_generate_hw_rule_bdy_ip6");
    if ( ipa3_get_ipc_logbuf() )
    {
      v259 = ipa3_get_ipc_logbuf();
      ipc_log_string(v259, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2081);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v260 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v260, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2081);
    }
    goto LABEL_235;
  }
  if ( (v73 & 0x80000000) == 0 )
  {
    v92 = a2[35];
    if ( (v92 & 2) == 0 )
      goto LABEL_52;
LABEL_65:
    v127 = v293[0];
    if ( v293[0] >= 2u )
    {
      printk(&unk_3FA176, "ipa_fltrt_generate_hw_rule_bdy_ip6");
      if ( ipa3_get_ipc_logbuf() )
      {
        v273 = ipa3_get_ipc_logbuf();
        ipc_log_string(v273, "ipahal %s:%d ran out of meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2111);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v274 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v274, "ipahal %s:%d ran out of meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2111);
      }
      goto LABEL_235;
    }
    v128 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_237;
    v129 = *((int *)&ipa3_0_ofst_meq32 + v293[0]);
    if ( v129 + 152 * (unsigned __int64)v128 + 128 > 0xF6F )
      goto LABEL_238;
    v130 = (_BYTE *)v295[0];
    *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v128 + 16] + v129);
    v295[0] = ipa_write_8(76, v130);
    v131 = ipa_write_16(0, v294);
    v132 = *((_WORD *)a2 + 28);
    v294 = v131;
    v294 = ipa_write_16(v132, v131);
    v133 = ipa_write_16(0, v294);
    v134 = *((_WORD *)a2 + 28);
    v294 = v133;
    v135 = ipa_write_16(v134, v133);
    v92 = a2[35];
    v294 = v135;
    v293[0] = v127 + 1;
    if ( (v92 & 1) == 0 )
      goto LABEL_53;
    goto LABEL_69;
  }
  if ( v13 )
    goto LABEL_171;
  v149 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx > 0x19u )
    goto LABEL_237;
  if ( 152 * (unsigned __int64)v149 + 135 > 0xF6F )
    goto LABEL_238;
  v150 = *a1 | (1LL << HIBYTE(ipahal_fltrt_objs[19 * v149 + 16]));
  *a1 = v150;
  if ( *(_DWORD *)ipahal_ctx > 0x19u )
    goto LABEL_237;
  v151 = (_BYTE *)v295[0];
  *a1 = v150 | (1LL << LOBYTE(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 17]));
  v152 = ipa_write_8(24, v151);
  v153 = ipa_write_8(*((_BYTE *)a2 + 53), v294);
  v154 = *((_BYTE *)a2 + 52);
  v294 = v153;
  v155 = ipa_write_8(v154, v153);
  v156 = *((_BYTE *)a2 + 51);
  v294 = v155;
  v157 = ipa_write_8(v156, v155);
  v158 = *((_BYTE *)a2 + 50);
  v294 = v157;
  v159 = ipa_write_8(v158, v157);
  v160 = *((_BYTE *)a2 + 47);
  v294 = v159;
  v161 = ipa_write_8(v160, v159);
  v162 = *((_BYTE *)a2 + 46);
  v294 = v161;
  v163 = ipa_write_8(v162, v161);
  v164 = *((_BYTE *)a2 + 45);
  v294 = v163;
  v165 = ipa_write_8(v164, v163);
  v166 = *((_BYTE *)a2 + 44);
  v294 = v165;
  v294 = ipa_write_8(v166, v165);
  v295[0] = ipa_write_8(28, v152);
  v167 = ipa_write_16(0, v294);
  v168 = *((_BYTE *)a2 + 55);
  v294 = v167;
  v169 = ipa_write_8(v168, v167);
  v170 = *((_BYTE *)a2 + 54);
  v294 = v169;
  v294 = ipa_write_8(v170, v169);
  v171 = ipa_write_16(0, v294);
  v172 = *((_BYTE *)a2 + 49);
  v294 = v171;
  v173 = ipa_write_8(v172, v171);
  v174 = *((_BYTE *)a2 + 48);
  v294 = v173;
  v13 = 2;
  v294 = ipa_write_8(v174, v173);
  v92 = a2[35];
  if ( (v92 & 2) != 0 )
    goto LABEL_65;
LABEL_52:
  if ( (v92 & 1) == 0 )
  {
LABEL_53:
    if ( (v92 & 8) == 0 )
    {
LABEL_103:
      v148 = *a2;
      if ( (*a2 & 0x800000) == 0 )
        goto LABEL_108;
      if ( v13 < 2 )
      {
        v182 = *(_DWORD *)ipahal_ctx;
        if ( *(_DWORD *)ipahal_ctx > 0x19u )
          goto LABEL_237;
        v183 = *((int *)&ipa3_0_ihl_ofst_meq32 + v13);
        if ( v183 + 152 * (unsigned __int64)v182 + 128 > 0xF6F )
          goto LABEL_238;
        v184 = (_BYTE *)v295[0];
        *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v182 + 16] + v183);
        v295[0] = ipa_write_8(12, v184);
        v294 = ipa_write_32(0x20000, v294);
        v185 = ipa_write_32(0x20000, v294);
        v148 = *a2;
        ++v13;
        v294 = v185;
LABEL_108:
        if ( (v148 & 0x1000000) == 0 )
          goto LABEL_121;
        if ( !v13 )
        {
          v186 = *(_DWORD *)ipahal_ctx;
          if ( *(_DWORD *)ipahal_ctx > 0x19u )
            goto LABEL_237;
          if ( 152 * (unsigned __int64)v186 + 135 > 0xF6F )
            goto LABEL_238;
          v187 = *a1 | (1LL << HIBYTE(ipahal_fltrt_objs[19 * v186 + 16]));
          *a1 = v187;
          if ( *(_DWORD *)ipahal_ctx > 0x19u )
            goto LABEL_237;
          v188 = (_BYTE *)v295[0];
          *a1 = v187 | (1LL << LOBYTE(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 17]));
          if ( *((_WORD *)a2 + 28) == 2048 )
          {
            v189 = ipa_write_8(30, v188);
            v190 = ipa_write_32(16711680, v294);
            v294 = v190;
            v191 = 393216;
          }
          else
          {
            v189 = ipa_write_8(26, v188);
            v190 = ipa_write_32(65280, v294);
            v294 = v190;
            v191 = 1536;
          }
          v192 = ipa_write_32(v191, v190);
          v193 = *((unsigned __int16 *)a2 + 28);
          v294 = v192;
          if ( v193 == 2048 )
            v194 = 54;
          else
            v194 = 74;
          v195 = ipa_write_8(v194, v189);
          v294 = ipa_write_32(0x20000, v294);
          v196 = ipa_write_32(0x20000, v294);
          v148 = *a2;
          v294 = v196;
          v295[0] = v195;
          goto LABEL_120;
        }
LABEL_183:
        printk(&unk_3FA19A, "ipa_fltrt_generate_hw_rule_bdy_ip6");
        if ( ipa3_get_ipc_logbuf() )
        {
          v265 = ipa3_get_ipc_logbuf();
          ipc_log_string(v265, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2214);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v266 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v266, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2214);
        }
        goto LABEL_235;
      }
LABEL_179:
      printk(&unk_3FA19A, "ipa_fltrt_generate_hw_rule_bdy_ip6");
      if ( ipa3_get_ipc_logbuf() )
      {
        v263 = ipa3_get_ipc_logbuf();
        ipc_log_string(v263, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2198);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v264 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v264, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2198);
      }
      goto LABEL_235;
    }
    if ( v13 < 2 )
    {
      v93 = *(_DWORD *)ipahal_ctx;
      if ( *(_DWORD *)ipahal_ctx > 0x19u )
        goto LABEL_237;
      v94 = *((int *)&ipa3_0_ihl_ofst_meq32 + v13);
      if ( v94 + 152 * (unsigned __int64)v93 + 128 > 0xF6F )
        goto LABEL_238;
      v95 = (_BYTE *)v295[0];
      *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v93 + 16] + v94);
      if ( *((_WORD *)a2 + 28) == 2048 )
      {
        v96 = ipa_write_8(46, v95);
        v97 = ipa_write_32(16711680, v294);
        v98 = 16;
      }
      else
      {
        v96 = ipa_write_8(42, v95);
        v97 = ipa_write_32(65280, v294);
        v98 = 8;
      }
      v181 = *((unsigned __int8 *)a2 + 144);
      v294 = v97;
      ++v13;
      v294 = ipa_write_32(v181 << v98, v97);
      v295[0] = v96;
      goto LABEL_103;
    }
LABEL_175:
    printk(&unk_3FA19A, "ipa_fltrt_generate_hw_rule_bdy_ip6");
    if ( ipa3_get_ipc_logbuf() )
    {
      v261 = ipa3_get_ipc_logbuf();
      ipc_log_string(v261, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2164);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v262 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v262, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2164);
    }
    goto LABEL_235;
  }
LABEL_69:
  if ( v13 )
  {
    printk(&unk_3FA19A, "ipa_fltrt_generate_hw_rule_bdy_ip6");
    if ( ipa3_get_ipc_logbuf() )
    {
      v275 = ipa3_get_ipc_logbuf();
      ipc_log_string(v275, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2129);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v276 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v276, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2129);
    }
    goto LABEL_235;
  }
  v136 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx > 0x19u )
    goto LABEL_237;
  if ( 152 * (unsigned __int64)v136 + 135 > 0xF6F )
    goto LABEL_238;
  v137 = *a1 | (1LL << HIBYTE(ipahal_fltrt_objs[19 * v136 + 16]));
  *a1 = v137;
  if ( *(_DWORD *)ipahal_ctx > 0x19u )
    goto LABEL_237;
  v138 = (_BYTE *)v295[0];
  *a1 = v137 | (1LL << LOBYTE(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 17]));
  if ( *((_WORD *)a2 + 28) == 2048 )
  {
    v139 = ipa_write_8(46, v138);
    v140 = ipa_write_32(16711680, v294);
    v294 = v140;
    v141 = 393216;
  }
  else
  {
    v139 = ipa_write_8(42, v138);
    v140 = ipa_write_32(65280, v294);
    v294 = v140;
    v141 = 1536;
  }
  v142 = ipa_write_32(v141, v140);
  v143 = *((unsigned __int16 *)a2 + 28);
  v294 = v142;
  if ( v143 == 2048 )
    v144 = 70;
  else
    v144 = 90;
  v145 = ipa_write_8(v144, v139);
  v294 = ipa_write_32(0x20000, v294);
  v146 = ipa_write_32(0x20000, v294);
  v147 = *((_BYTE *)a2 + 140);
  v294 = v146;
  v295[0] = v145;
  if ( (v147 & 8) != 0 )
    goto LABEL_175;
  v148 = *a2;
  if ( (*a2 & 0x800000) != 0 )
    goto LABEL_179;
  if ( (v148 & 0x1000000) != 0 )
    goto LABEL_183;
LABEL_120:
  v13 = 2;
LABEL_121:
  if ( (v148 & 0x2000000) != 0 )
  {
    if ( v13 >= 2 )
    {
      printk(&unk_3FA19A, "ipa_fltrt_generate_hw_rule_bdy_ip6");
      if ( ipa3_get_ipc_logbuf() )
      {
        v277 = ipa3_get_ipc_logbuf();
        ipc_log_string(v277, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2249);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v278 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v278, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2249);
      }
      goto LABEL_235;
    }
    v197 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_237;
    v198 = *((int *)&ipa3_0_ihl_ofst_meq32 + v13);
    if ( v198 + 152 * (unsigned __int64)v197 + 128 > 0xF6F )
      goto LABEL_238;
    v199 = (_BYTE *)v295[0];
    *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v197 + 16] + v198);
    v295[0] = ipa_write_8(22, v199);
    v200 = ipa_write_32(-268435456, v294);
    v201 = *((unsigned __int8 *)a2 + 12);
    v202 = v200;
    v294 = v200;
    if ( v201 == 64 )
      v203 = 0x40000000;
    else
      v203 = 1610612736;
    v204 = ipa_write_32(v203, v202);
    v148 = *a2;
    ++v13;
    v294 = v204;
  }
  if ( (v148 & 0x4000000) != 0 )
  {
    if ( v13 >= 2 )
    {
      printk(&unk_3FA19A, "ipa_fltrt_generate_hw_rule_bdy_ip6");
      if ( ipa3_get_ipc_logbuf() )
      {
        v279 = ipa3_get_ipc_logbuf();
        ipc_log_string(v279, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2267);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v280 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v280, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2267);
      }
      goto LABEL_235;
    }
    v205 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_237;
    v206 = *((int *)&ipa3_0_ihl_ofst_meq32 + v13);
    if ( v206 + 152 * (unsigned __int64)v205 + 128 > 0xF6F )
      goto LABEL_238;
    v207 = (_BYTE *)v295[0];
    *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v205 + 16] + v206);
    v208 = ipa_write_8(38, v207);
    v209 = a2[19];
    v295[0] = v208;
    v210 = ipa_write_32(v209, v294);
    v211 = a2[18];
    v294 = v210;
    v212 = ipa_write_32(v211, v210);
    v148 = *a2;
    v294 = v212;
  }
  if ( (v148 & 0x4000) != 0 )
  {
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_237;
    v213 = v294;
    *a1 |= 1LL << BYTE1(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 17]);
    v214 = ipa_write_32(a2[7], v213);
    v215 = a2[6];
    v294 = v214;
    v216 = ipa_write_32(v215, v214);
    v148 = *a2;
    v294 = v216;
  }
  if ( (v148 & 0x200) != 0 )
  {
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_237;
    v217 = 1;
    v219 = (_BYTE *)v295[0];
    *a1 |= 1LL << BYTE2(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 17]);
    v220 = ipa_write_8(0, v219);
    v221 = *((_WORD *)a2 + 10);
    v295[0] = v220;
    v222 = ipa_write_16(v221, v294);
    v223 = *((_WORD *)a2 + 10);
    v294 = v222;
    v224 = ipa_write_16(v223, v222);
    v148 = *a2;
    v294 = v224;
    if ( (v148 & 0x400) == 0 )
    {
LABEL_139:
      if ( (v148 & 0x10) == 0 )
        goto LABEL_140;
LABEL_150:
      if ( v217 >= 2 )
      {
        printk(&unk_3DD3FE, "ipa_fltrt_generate_hw_rule_bdy_ip6");
        if ( ipa3_get_ipc_logbuf() )
        {
          v281 = ipa3_get_ipc_logbuf();
          ipc_log_string(v281, "ipahal %s:%d ran out of ihl_rng16 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2318);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v282 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v282, "ipahal %s:%d ran out of ihl_rng16 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2318);
        }
        goto LABEL_235;
      }
      if ( *((unsigned __int16 *)a2 + 3) < (unsigned int)*((unsigned __int16 *)a2 + 2) )
      {
        printk(&unk_3FA1C2, "ipa_fltrt_generate_hw_rule_bdy_ip6");
        if ( ipa3_get_ipc_logbuf() )
        {
          v285 = ipa3_get_ipc_logbuf();
          ipc_log_string(v285, "ipahal %s:%d bad src port range param\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2322);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v286 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v286, "ipahal %s:%d bad src port range param\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2322);
        }
        goto LABEL_235;
      }
      v233 = *(_DWORD *)ipahal_ctx;
      if ( *(_DWORD *)ipahal_ctx > 0x19u )
        goto LABEL_237;
      v234 = *((int *)&ipa3_0_ihl_ofst_rng16 + v217);
      if ( v234 + 152 * (unsigned __int64)v233 + 128 > 0xF6F )
        goto LABEL_238;
      v235 = (_BYTE *)v295[0];
      *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v233 + 16] + v234);
      v236 = ipa_write_8(0, v235);
      v237 = *((_WORD *)a2 + 3);
      v295[0] = v236;
      v238 = ipa_write_16(v237, v294);
      v239 = *((_WORD *)a2 + 2);
      v294 = v238;
      v240 = ipa_write_16(v239, v238);
      v148 = *a2;
      ++v217;
      v294 = v240;
      if ( (v148 & 0x20) == 0 )
        goto LABEL_141;
      goto LABEL_155;
    }
  }
  else
  {
    v217 = 0;
    if ( (v148 & 0x400) == 0 )
      goto LABEL_139;
  }
  v225 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx > 0x19u )
    goto LABEL_237;
  v226 = *((int *)&ipa3_0_ihl_ofst_rng16 + v217);
  if ( v226 + 152 * (unsigned __int64)v225 + 128 > 0xF6F )
    goto LABEL_238;
  v227 = (_BYTE *)v295[0];
  *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v225 + 16] + v226);
  v228 = ipa_write_8(2, v227);
  v229 = *((_WORD *)a2 + 11);
  v295[0] = v228;
  v230 = ipa_write_16(v229, v294);
  v231 = *((_WORD *)a2 + 11);
  v294 = v230;
  v232 = ipa_write_16(v231, v230);
  v148 = *a2;
  ++v217;
  v294 = v232;
  if ( (v148 & 0x10) != 0 )
    goto LABEL_150;
LABEL_140:
  if ( (v148 & 0x20) == 0 )
  {
LABEL_141:
    if ( (v148 & 0x1000000) == 0 )
    {
LABEL_142:
      if ( (v148 & 0x1000) == 0 )
        goto LABEL_143;
LABEL_167:
      if ( *(_DWORD *)ipahal_ctx <= 0x19u )
      {
        v256 = v294;
        *a1 |= 1LL << BYTE6(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 17]);
        v257 = ipa_write_32(a2[16] & 0xFFFFF, v256);
        v258 = *a2;
        v294 = v257;
        if ( (v258 & 0x8000) == 0 )
          goto LABEL_144;
        goto LABEL_169;
      }
LABEL_237:
      __break(0x5512u);
LABEL_238:
      __break(1u);
    }
    goto LABEL_160;
  }
LABEL_155:
  if ( v217 >= 2 )
  {
    printk(&unk_3DD3FE, "ipa_fltrt_generate_hw_rule_bdy_ip6");
    if ( ipa3_get_ipc_logbuf() )
    {
      v283 = ipa3_get_ipc_logbuf();
      ipc_log_string(v283, "ipahal %s:%d ran out of ihl_rng16 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2337);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v284 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v284, "ipahal %s:%d ran out of ihl_rng16 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2337);
    }
    goto LABEL_235;
  }
  if ( *((unsigned __int16 *)a2 + 5) < (unsigned int)*((unsigned __int16 *)a2 + 4) )
  {
    printk(&unk_3FA1EB, "ipa_fltrt_generate_hw_rule_bdy_ip6");
    if ( ipa3_get_ipc_logbuf() )
    {
      v289 = ipa3_get_ipc_logbuf();
      ipc_log_string(v289, "ipahal %s:%d bad dst port range param\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2341);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v290 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v290, "ipahal %s:%d bad dst port range param\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2341);
    }
    goto LABEL_235;
  }
  v241 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx > 0x19u )
    goto LABEL_237;
  v242 = *((int *)&ipa3_0_ihl_ofst_rng16 + v217);
  if ( v242 + 152 * (unsigned __int64)v241 + 128 > 0xF6F )
    goto LABEL_238;
  v243 = (_BYTE *)v295[0];
  *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v241 + 16] + v242);
  v244 = ipa_write_8(2, v243);
  v245 = *((_WORD *)a2 + 5);
  v295[0] = v244;
  v246 = ipa_write_16(v245, v294);
  v247 = *((_WORD *)a2 + 4);
  v294 = v246;
  v248 = ipa_write_16(v247, v246);
  v148 = *a2;
  ++v217;
  v294 = v248;
  if ( (v148 & 0x1000000) == 0 )
    goto LABEL_142;
LABEL_160:
  if ( v217 >= 2 )
  {
    printk(&unk_3DD3FE, "ipa_fltrt_generate_hw_rule_bdy_ip6");
    if ( ipa3_get_ipc_logbuf() )
    {
      v287 = ipa3_get_ipc_logbuf();
      ipc_log_string(v287, "ipahal %s:%d ran out of ihl_rng16 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2356);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v288 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v288, "ipahal %s:%d ran out of ihl_rng16 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip6", 2356);
    }
    goto LABEL_235;
  }
  v249 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx > 0x19u )
    goto LABEL_237;
  v250 = *((int *)&ipa3_0_ihl_ofst_rng16 + v217);
  if ( v250 + 152 * (unsigned __int64)v249 + 128 > 0xF6F )
    goto LABEL_238;
  v251 = (_BYTE *)v295[0];
  *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v249 + 16] + v250);
  if ( *((_WORD *)a2 + 28) == 2048 )
  {
    v252 = ipa_write_8(21, v251);
    v253 = ipa_write_16(69, v294);
    v294 = v253;
    v254 = 69;
  }
  else
  {
    v252 = ipa_write_8(20, v251);
    v253 = ipa_write_16(*((_WORD *)a2 + 28), v294);
    v254 = *((_WORD *)a2 + 28);
    v294 = v253;
  }
  v255 = ipa_write_16(v254, v253);
  v148 = *a2;
  v294 = v255;
  v295[0] = v252;
  if ( (v148 & 0x1000) != 0 )
    goto LABEL_167;
LABEL_143:
  if ( (v148 & 0x8000) != 0 )
  {
LABEL_169:
    if ( *(_DWORD *)ipahal_ctx <= 0x19u )
    {
      result = 0;
      *a1 |= 1LL << HIBYTE(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 17]);
      goto LABEL_236;
    }
    goto LABEL_237;
  }
LABEL_144:
  result = 0;
LABEL_236:
  v291 = v294;
  *a3 = (_BYTE *)v295[0];
  *a4 = v291;
  _ReadStatusReg(SP_EL0);
  return result;
}
