__int64 __fastcall ipa_fltrt_generate_hw_rule_bdy_ip4(_WORD *a1, int *a2, _BYTE **a3, _WORD **a4)
{
  _BYTE *v8; // x1
  _WORD *v9; // x9
  int v10; // w8
  __int64 v11; // x8
  _BYTE *v12; // x0
  char v13; // w25
  int v14; // w8
  __int64 v15; // x8
  _BYTE *v16; // x23
  __int64 v17; // x0
  __int64 v18; // x0
  _BYTE *v19; // x0
  _BYTE *v20; // x1
  _BYTE *v21; // x0
  int v22; // w8
  _DWORD *v23; // x0
  _WORD *v24; // x0
  unsigned __int8 v25; // w23
  unsigned int v26; // w8
  __int64 v27; // x9
  _BYTE *v28; // x1
  _BYTE *v29; // x0
  int v30; // w8
  _DWORD *v31; // x0
  _WORD *v32; // x0
  unsigned __int8 v33; // w23
  unsigned int v34; // w8
  __int64 v35; // x9
  _BYTE *v36; // x1
  _BYTE *v37; // x0
  int v38; // w8
  _DWORD *v39; // x0
  _WORD *v40; // x0
  unsigned __int8 v41; // w23
  unsigned int v42; // w8
  __int64 v43; // x9
  _BYTE *v44; // x1
  _WORD *v45; // x0
  _WORD *v46; // x0
  _WORD *v47; // x0
  _WORD *v48; // x0
  char v49; // w8
  unsigned __int8 v50; // w23
  __int64 v51; // x0
  __int64 v52; // x0
  unsigned int v53; // w8
  __int64 v54; // x9
  _BYTE *v55; // x1
  _DWORD *v56; // x0
  int v57; // w8
  unsigned int v58; // w23
  int v59; // w8
  _BYTE *v60; // x1
  _DWORD *v61; // x0
  _WORD *v62; // x0
  unsigned int v63; // w8
  __int64 v64; // x9
  _BYTE *v65; // x1
  _DWORD *v66; // x0
  _WORD *v67; // x0
  unsigned int v68; // w8
  __int64 v69; // x9
  _BYTE *v70; // x1
  _DWORD *v71; // x0
  _WORD *v72; // x0
  unsigned int v73; // w9
  __int16 v74; // w9
  _BYTE *v75; // x1
  _BYTE *v76; // x23
  _BYTE *v77; // x0
  _BYTE *v78; // x0
  _BYTE *v79; // x0
  _BYTE *v80; // x0
  _BYTE *v81; // x0
  _BYTE *v82; // x0
  _BYTE *v83; // x0
  _WORD *v84; // x24
  _WORD *v85; // x0
  _BYTE *v86; // x0
  _WORD *v87; // x0
  _WORD *v88; // x0
  _BYTE *v89; // x0
  _WORD *v90; // x0
  int v91; // w8
  unsigned __int8 v92; // w24
  unsigned int v93; // w8
  __int64 v94; // x9
  _BYTE *v95; // x1
  _WORD *v96; // x0
  _WORD *v97; // x0
  _WORD *v98; // x0
  unsigned int v99; // w8
  __int64 v100; // x9
  _BYTE *v101; // x1
  _DWORD *v102; // x0
  _WORD *v103; // x0
  char v104; // w8
  __int64 v105; // x0
  __int64 v106; // x0
  unsigned int v107; // w23
  int v108; // w8
  unsigned int v109; // w8
  __int64 v110; // x9
  _BYTE *v111; // x1
  _DWORD *v112; // x0
  _DWORD *v113; // x1
  _DWORD *v114; // x0
  _BYTE *v115; // x1
  _BYTE *v116; // x0
  __int16 v117; // w8
  _WORD *v118; // x0
  unsigned int v119; // w8
  __int64 v120; // x9
  _BYTE *v121; // x1
  _BYTE *v122; // x0
  __int16 v123; // w8
  _WORD *v124; // x0
  _WORD *v125; // x0
  unsigned int v126; // w8
  __int64 v127; // x9
  _BYTE *v128; // x1
  _BYTE *v129; // x0
  __int16 v130; // w8
  _WORD *v131; // x0
  _WORD *v132; // x0
  unsigned int v133; // w8
  __int64 v134; // x9
  _BYTE *v135; // x1
  _BYTE *v136; // x0
  __int16 v137; // w8
  _WORD *v138; // x0
  _WORD *v139; // x0
  unsigned int v140; // w8
  __int64 v141; // x9
  _BYTE *v142; // x1
  _BYTE *v143; // x0
  __int16 v144; // w8
  _WORD *v145; // x0
  _WORD *v146; // x0
  char v147; // w8
  __int64 result; // x0
  unsigned int v149; // w9
  __int16 v150; // w9
  _BYTE *v151; // x1
  _BYTE *v152; // x23
  _BYTE *v153; // x0
  _BYTE *v154; // x0
  _BYTE *v155; // x0
  _BYTE *v156; // x0
  _BYTE *v157; // x0
  _BYTE *v158; // x0
  _BYTE *v159; // x0
  _WORD *v160; // x24
  _WORD *v161; // x0
  _BYTE *v162; // x0
  _WORD *v163; // x0
  _WORD *v164; // x0
  _BYTE *v165; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v168; // x0
  __int64 v169; // x0
  __int64 v170; // x0
  __int64 v171; // x0
  __int64 v172; // x0
  __int64 v173; // x0
  __int64 v174; // x0
  __int64 v175; // x0
  __int64 v176; // x0
  __int64 v177; // x0
  __int64 v178; // x0
  __int64 v179; // x0
  __int64 v180; // x0
  __int64 v181; // x0
  __int64 v182; // x0
  __int64 v183; // x0
  __int64 v184; // x0
  __int64 v185; // x0
  __int64 v186; // x0
  __int64 v187; // x0
  __int64 v188; // x0
  __int64 v189; // x0
  __int64 v190; // x0
  __int64 v191; // x0
  __int64 v192; // x0
  __int64 v193; // x0
  __int64 v194; // x0
  __int64 v195; // x0
  _WORD *v196; // x9
  _BYTE v197[4]; // [xsp+0h] [xbp-20h] BYREF
  unsigned __int8 v198[4]; // [xsp+4h] [xbp-1Ch] BYREF
  _WORD *v199; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v200[2]; // [xsp+10h] [xbp-10h] BYREF

  v200[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *a3;
  v9 = *a4;
  v10 = *a2;
  v198[0] = 0;
  v199 = v9;
  v200[0] = v8;
  v197[0] = 0;
  if ( (v10 & 0x8000000) != 0 )
  {
    if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
      goto LABEL_202;
    v11 = LOBYTE(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 18]);
    if ( v11 == 255 )
    {
      printk(&unk_3D1887, "ipa_fltrt_generate_hw_rule_bdy_ip4");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipahal %s:%d is_pure_ack eq not supported\n",
          "ipa_fltrt_generate_hw_rule_bdy_ip4",
          1498);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipahal %s:%d is_pure_ack eq not supported\n",
          "ipa_fltrt_generate_hw_rule_bdy_ip4",
          1498);
      }
      goto LABEL_200;
    }
    *a1 |= 1LL << v11;
    v12 = ipa_write_8(0, v8);
    v10 = *a2;
    v8 = v12;
    v200[0] = v12;
  }
  if ( (v10 & 1) != 0 )
  {
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_202;
    v15 = LOBYTE(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 16]);
    if ( v15 == 255 )
    {
      v16 = v8;
      if ( ipa3_get_ipc_logbuf() )
      {
        v17 = ipa3_get_ipc_logbuf();
        ipc_log_string(v17, "ipahal %s:%d tos eq not supported\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1507);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v18 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v18, "ipahal %s:%d tos eq not supported\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1507);
      }
      v13 = 0;
      v8 = v16;
      v14 = *a2;
      if ( (*a2 & 2) == 0 )
        goto LABEL_19;
    }
    else
    {
      v13 = 1;
      *a1 |= 1LL << v15;
      v8 = ipa_write_8(*((_BYTE *)a2 + 60), v8);
      v200[0] = v8;
      v14 = *a2;
      if ( (*a2 & 2) == 0 )
        goto LABEL_19;
    }
  }
  else
  {
    v13 = 0;
    v14 = *a2;
    if ( (*a2 & 2) == 0 )
      goto LABEL_19;
  }
  if ( *(_DWORD *)ipahal_ctx > 0x19u )
    goto LABEL_202;
  *a1 |= 1LL << BYTE1(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 16]);
  v19 = ipa_write_8(*((_BYTE *)a2 + 61), v8);
  v14 = *a2;
  v200[0] = v19;
LABEL_19:
  if ( (v14 & 0x601E0000) != 0 )
  {
    if ( (unsigned int)ipa_fltrt_generate_mac_hw_rule_bdy(a1, a2, v197, v200, &v199) )
      goto LABEL_200;
    v14 = *a2;
  }
  if ( (v14 & 0x10000) != 0 )
  {
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_202;
    v20 = (_BYTE *)v200[0];
    *a1 |= 1LL << BYTE5(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 16]);
    v21 = ipa_write_8(0, v20);
    v22 = *((unsigned __int8 *)a2 + 15);
    v200[0] = v21;
    v23 = ipa_write_32(v22 << 16, v199);
    v24 = ipa_write_32(*((unsigned __int8 *)a2 + 14) << 16, v23);
    v14 = *a2;
    v199 = v24;
    v198[0] = 1;
  }
  if ( (v14 & 4) != 0 )
  {
    v25 = v198[0];
    if ( v198[0] >= 2u )
    {
      printk(&unk_3FA176, "ipa_fltrt_generate_hw_rule_bdy_ip4");
      if ( ipa3_get_ipc_logbuf() )
      {
        v168 = ipa3_get_ipc_logbuf();
        ipc_log_string(v168, "ipahal %s:%d ran out of meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1542);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v169 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v169, "ipahal %s:%d ran out of meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1542);
      }
      goto LABEL_200;
    }
    v26 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_202;
    v27 = *((int *)&ipa3_0_ofst_meq32 + v198[0]);
    if ( v27 + 152 * (unsigned __int64)v26 + 128 > 0xF6F )
      goto LABEL_203;
    v28 = (_BYTE *)v200[0];
    *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v26 + 16] + v27);
    v29 = ipa_write_8(12, v28);
    v30 = a2[17];
    v200[0] = v29;
    v31 = ipa_write_32(v30, v199);
    v32 = ipa_write_32(a2[16], v31);
    v14 = *a2;
    v199 = v32;
    v198[0] = v25 + 1;
  }
  if ( (v14 & 8) != 0 )
  {
    v33 = v198[0];
    if ( v198[0] >= 2u )
    {
      printk(&unk_3FA176, "ipa_fltrt_generate_hw_rule_bdy_ip4");
      if ( ipa3_get_ipc_logbuf() )
      {
        v170 = ipa3_get_ipc_logbuf();
        ipc_log_string(v170, "ipahal %s:%d ran out of meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1556);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v171 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v171, "ipahal %s:%d ran out of meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1556);
      }
      goto LABEL_200;
    }
    v34 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_202;
    v35 = *((int *)&ipa3_0_ofst_meq32 + v198[0]);
    if ( v35 + 152 * (unsigned __int64)v34 + 128 > 0xF6F )
      goto LABEL_203;
    v36 = (_BYTE *)v200[0];
    *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v34 + 16] + v35);
    v37 = ipa_write_8(16, v36);
    v38 = a2[19];
    v200[0] = v37;
    v39 = ipa_write_32(v38, v199);
    v40 = ipa_write_32(a2[18], v39);
    v14 = *a2;
    v199 = v40;
    v198[0] = v33 + 1;
  }
  if ( (v14 & 0x200000) != 0 )
  {
    v41 = v198[0];
    if ( v198[0] >= 2u )
    {
      printk(&unk_3FA176, "ipa_fltrt_generate_hw_rule_bdy_ip4");
      if ( ipa3_get_ipc_logbuf() )
      {
        v172 = ipa3_get_ipc_logbuf();
        ipc_log_string(v172, "ipahal %s:%d ran out of meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1570);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v173 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v173, "ipahal %s:%d ran out of meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1570);
      }
      goto LABEL_200;
    }
    v42 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_202;
    v43 = *((int *)&ipa3_0_ofst_meq32 + v198[0]);
    if ( v43 + 152 * (unsigned __int64)v42 + 128 > 0xF6F )
      goto LABEL_203;
    v44 = (_BYTE *)v200[0];
    *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v42 + 16] + v43);
    v200[0] = ipa_write_8(254, v44);
    v45 = ipa_write_16(0, v199);
    v46 = ipa_write_16(bswap32(*((unsigned __int16 *)a2 + 28)) >> 16, v45);
    v47 = ipa_write_16(0, v46);
    v48 = ipa_write_16(bswap32(*((unsigned __int16 *)a2 + 28)) >> 16, v47);
    v14 = *a2;
    v199 = v48;
    v198[0] = v41 + 1;
  }
  if ( (v14 & 1) != 0 )
    v49 = v13;
  else
    v49 = 1;
  if ( (v49 & 1) == 0 )
  {
    v50 = v198[0];
    if ( v198[0] < 2u )
    {
      v53 = *(_DWORD *)ipahal_ctx;
      if ( *(_DWORD *)ipahal_ctx > 0x19u )
        goto LABEL_202;
      v54 = *((int *)&ipa3_0_ofst_meq32 + v198[0]);
      if ( v54 + 152 * (unsigned __int64)v53 + 128 > 0xF6F )
        goto LABEL_203;
      v13 = 1;
      v55 = (_BYTE *)v200[0];
      *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v53 + 16] + v54);
      v200[0] = ipa_write_8(0, v55);
      v56 = ipa_write_32(16711680, v199);
      v199 = ipa_write_32(*((unsigned __int8 *)a2 + 60) << 16, v56);
      v198[0] = v50 + 1;
    }
    else
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v51 = ipa3_get_ipc_logbuf();
        ipc_log_string(v51, "ipahal %s:%d ran out of meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1586);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v52 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v52, "ipahal %s:%d ran out of meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1586);
      }
      v13 = 0;
    }
  }
  if ( (unsigned int)ipa_fltrt_generate_vlan_hw_rule_bdy(a1, a2, v198, v200, &v199) )
  {
LABEL_200:
    result = 0xFFFFFFFFLL;
    goto LABEL_201;
  }
  v57 = *a2;
  if ( (*a2 & 0x40) != 0 )
  {
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_202;
    v58 = 1;
    v60 = (_BYTE *)v200[0];
    *a1 |= 1LL << HIBYTE(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 16]);
    v200[0] = ipa_write_8(0, v60);
    v61 = ipa_write_32(255, v199);
    v62 = ipa_write_32(*((unsigned __int8 *)a2 + 12), v61);
    v57 = *a2;
    v199 = v62;
    if ( (v57 & 0x80) == 0 )
    {
LABEL_56:
      if ( (v57 & 0x100) == 0 )
        goto LABEL_57;
      goto LABEL_67;
    }
  }
  else
  {
    v58 = 0;
    if ( (v57 & 0x80) == 0 )
      goto LABEL_56;
  }
  v63 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx > 0x19u )
    goto LABEL_202;
  v64 = *((int *)&ipa3_0_ihl_ofst_meq32 + v58);
  if ( v64 + 152 * (unsigned __int64)v63 + 128 > 0xF6F )
    goto LABEL_203;
  v65 = (_BYTE *)v200[0];
  *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v63 + 16] + v64);
  v200[0] = ipa_write_8(1, v65);
  v66 = ipa_write_32(255, v199);
  v67 = ipa_write_32(*((unsigned __int8 *)a2 + 13), v66);
  v57 = *a2;
  ++v58;
  v199 = v67;
  if ( (v57 & 0x100) == 0 )
  {
LABEL_57:
    if ( (v57 & 0x400000) == 0 )
      goto LABEL_58;
LABEL_71:
    if ( v58 )
    {
      printk(&unk_3FA19A, "ipa_fltrt_generate_hw_rule_bdy_ip4");
      if ( ipa3_get_ipc_logbuf() )
      {
        v180 = ipa3_get_ipc_logbuf();
        ipc_log_string(v180, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1655);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v181 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v181, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1655);
      }
      goto LABEL_200;
    }
    v73 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_202;
    if ( 152 * (unsigned __int64)v73 + 135 > 0xF6F )
      goto LABEL_203;
    v74 = *a1 | (1LL << HIBYTE(ipahal_fltrt_objs[19 * v73 + 16]));
    *a1 = v74;
    if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
      goto LABEL_202;
    v75 = (_BYTE *)v200[0];
    *a1 = v74 | (1LL << LOBYTE(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 17]));
    v76 = ipa_write_8(8, v75);
    v77 = ipa_write_8(*((_BYTE *)a2 + 53), v199);
    v78 = ipa_write_8(*((_BYTE *)a2 + 52), v77);
    v79 = ipa_write_8(*((_BYTE *)a2 + 51), v78);
    v80 = ipa_write_8(*((_BYTE *)a2 + 50), v79);
    v81 = ipa_write_8(*((_BYTE *)a2 + 47), v80);
    v82 = ipa_write_8(*((_BYTE *)a2 + 46), v81);
    v83 = ipa_write_8(*((_BYTE *)a2 + 45), v82);
    v84 = ipa_write_8(*((_BYTE *)a2 + 44), v83);
    v200[0] = ipa_write_8(12, v76);
    v85 = ipa_write_16(0, v84);
    v86 = ipa_write_8(*((_BYTE *)a2 + 55), v85);
    v87 = ipa_write_8(*((_BYTE *)a2 + 54), v86);
    v88 = ipa_write_16(0, v87);
    v89 = ipa_write_8(*((_BYTE *)a2 + 49), v88);
    v90 = ipa_write_8(*((_BYTE *)a2 + 48), v89);
    v91 = *a2;
    v199 = v90;
    if ( (v91 & 0x80000000) == 0 )
    {
      v58 = 2;
      if ( (a2[35] & 2) != 0 )
        goto LABEL_77;
      goto LABEL_60;
    }
LABEL_160:
    printk(&unk_3FA19A, "ipa_fltrt_generate_hw_rule_bdy_ip4");
    if ( ipa3_get_ipc_logbuf() )
    {
      v176 = ipa3_get_ipc_logbuf();
      ipc_log_string(v176, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1687);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v177 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v177, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1687);
    }
    goto LABEL_200;
  }
LABEL_67:
  if ( v58 >= 2 )
  {
    printk(&unk_3FA19A, "ipa_fltrt_generate_hw_rule_bdy_ip4");
    if ( ipa3_get_ipc_logbuf() )
    {
      v178 = ipa3_get_ipc_logbuf();
      ipc_log_string(v178, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1639);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v179 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v179, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1639);
    }
    goto LABEL_200;
  }
  v68 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx > 0x19u )
    goto LABEL_202;
  v69 = *((int *)&ipa3_0_ihl_ofst_meq32 + v58);
  if ( v69 + 152 * (unsigned __int64)v68 + 128 > 0xF6F )
    goto LABEL_203;
  v70 = (_BYTE *)v200[0];
  *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v68 + 16] + v69);
  v200[0] = ipa_write_8(0, v70);
  v71 = ipa_write_32(-1, v199);
  v72 = ipa_write_32(a2[4], v71);
  v57 = *a2;
  ++v58;
  v199 = v72;
  if ( (v57 & 0x400000) != 0 )
    goto LABEL_71;
LABEL_58:
  if ( v57 < 0 )
  {
    if ( !v58 )
    {
      v149 = *(_DWORD *)ipahal_ctx;
      if ( *(_DWORD *)ipahal_ctx > 0x19u )
        goto LABEL_202;
      if ( 152 * (unsigned __int64)v149 + 135 > 0xF6F )
        goto LABEL_203;
      v150 = *a1 | (1LL << HIBYTE(ipahal_fltrt_objs[19 * v149 + 16]));
      *a1 = v150;
      if ( *(_DWORD *)ipahal_ctx > 0x19u )
        goto LABEL_202;
      v151 = (_BYTE *)v200[0];
      *a1 = v150 | (1LL << LOBYTE(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 17]));
      v152 = ipa_write_8(24, v151);
      v153 = ipa_write_8(*((_BYTE *)a2 + 53), v199);
      v154 = ipa_write_8(*((_BYTE *)a2 + 52), v153);
      v155 = ipa_write_8(*((_BYTE *)a2 + 51), v154);
      v156 = ipa_write_8(*((_BYTE *)a2 + 50), v155);
      v157 = ipa_write_8(*((_BYTE *)a2 + 47), v156);
      v158 = ipa_write_8(*((_BYTE *)a2 + 46), v157);
      v159 = ipa_write_8(*((_BYTE *)a2 + 45), v158);
      v160 = ipa_write_8(*((_BYTE *)a2 + 44), v159);
      v200[0] = ipa_write_8(28, v152);
      v161 = ipa_write_16(0, v160);
      v162 = ipa_write_8(*((_BYTE *)a2 + 55), v161);
      v163 = ipa_write_8(*((_BYTE *)a2 + 54), v162);
      v164 = ipa_write_16(0, v163);
      v165 = ipa_write_8(*((_BYTE *)a2 + 49), v164);
      v58 = 2;
      v199 = ipa_write_8(*((_BYTE *)a2 + 48), v165);
      if ( (a2[35] & 2) != 0 )
        goto LABEL_77;
LABEL_60:
      v59 = *a2;
      if ( (*a2 & 0x800000) == 0 )
        goto LABEL_85;
      goto LABEL_81;
    }
    goto LABEL_160;
  }
  if ( (a2[35] & 2) == 0 )
    goto LABEL_60;
LABEL_77:
  v92 = v198[0];
  if ( v198[0] >= 2u )
  {
    printk(&unk_3FA176, "ipa_fltrt_generate_hw_rule_bdy_ip4");
    if ( ipa3_get_ipc_logbuf() )
    {
      v182 = ipa3_get_ipc_logbuf();
      ipc_log_string(v182, "ipahal %s:%d ran out of meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1717);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v183 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v183, "ipahal %s:%d ran out of meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1717);
    }
    goto LABEL_200;
  }
  v93 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx > 0x19u )
    goto LABEL_202;
  v94 = *((int *)&ipa3_0_ofst_meq32 + v198[0]);
  if ( v94 + 152 * (unsigned __int64)v93 + 128 > 0xF6F )
    goto LABEL_203;
  v95 = (_BYTE *)v200[0];
  *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v93 + 16] + v94);
  v200[0] = ipa_write_8(76, v95);
  v96 = ipa_write_16(0, v199);
  v97 = ipa_write_16(*((_WORD *)a2 + 28), v96);
  v98 = ipa_write_16(0, v97);
  v199 = ipa_write_16(*((_WORD *)a2 + 28), v98);
  v198[0] = v92 + 1;
  v59 = *a2;
  if ( (*a2 & 0x800000) != 0 )
  {
LABEL_81:
    if ( v58 >= 2 )
    {
      printk(&unk_3FA19A, "ipa_fltrt_generate_hw_rule_bdy_ip4");
      if ( ipa3_get_ipc_logbuf() )
      {
        v184 = ipa3_get_ipc_logbuf();
        ipc_log_string(v184, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1734);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v185 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v185, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1734);
      }
      goto LABEL_200;
    }
    v99 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_202;
    v100 = *((int *)&ipa3_0_ihl_ofst_meq32 + v58);
    if ( v100 + 152 * (unsigned __int64)v99 + 128 > 0xF6F )
      goto LABEL_203;
    v101 = (_BYTE *)v200[0];
    *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v99 + 16] + v100);
    v200[0] = ipa_write_8(12, v101);
    v102 = ipa_write_32(0x20000, v199);
    v103 = ipa_write_32(0x20000, v102);
    v59 = *a2;
    ++v58;
    v199 = v103;
  }
LABEL_85:
  if ( (v59 & 1) != 0 )
    v104 = v13;
  else
    v104 = 1;
  if ( (v104 & 1) != 0 )
    goto LABEL_105;
  if ( v58 < 2 )
  {
    v109 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_202;
    v110 = *((int *)&ipa3_0_ihl_ofst_meq32 + v58);
    if ( v110 + 152 * (unsigned __int64)v109 + 128 > 0xF6F )
      goto LABEL_203;
    v13 = 1;
    v111 = (_BYTE *)v200[0];
    *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v109 + 16] + v110);
    v200[0] = ipa_write_8(128, v111);
    v112 = ipa_write_32(16711680, v199);
    v199 = ipa_write_32(*((unsigned __int8 *)a2 + 60) << 16, v112);
LABEL_105:
    if ( (*((_BYTE *)a2 + 1) & 0x40) == 0 )
      goto LABEL_95;
    goto LABEL_106;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v105 = ipa3_get_ipc_logbuf();
    ipc_log_string(v105, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1749);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v106 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v106, "ipahal %s:%d ran out of ihl_meq32 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1749);
  }
  v13 = 0;
  if ( (*((_BYTE *)a2 + 1) & 0x40) == 0 )
  {
LABEL_95:
    if ( (a2[35] & 4) == 0 )
      goto LABEL_96;
    goto LABEL_108;
  }
LABEL_106:
  if ( *(_DWORD *)ipahal_ctx > 0x19u )
    goto LABEL_202;
  v113 = v199;
  *a1 |= 1LL << BYTE1(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 17]);
  v114 = ipa_write_32(a2[7], v113);
  v199 = ipa_write_32(a2[6], v114);
  if ( (a2[35] & 4) == 0 )
  {
LABEL_96:
    v107 = 0;
    v108 = *a2;
    if ( (*a2 & 0x10) == 0 )
      goto LABEL_97;
    goto LABEL_110;
  }
LABEL_108:
  if ( *(_DWORD *)ipahal_ctx > 0x19u )
    goto LABEL_202;
  v107 = 1;
  v115 = (_BYTE *)v200[0];
  *a1 |= 1LL << BYTE2(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 17]);
  v116 = ipa_write_8(130, v115);
  v117 = *((_WORD *)a2 + 69);
  v200[0] = v116;
  v118 = ipa_write_16(v117, v199);
  v199 = ipa_write_16(0, v118);
  v108 = *a2;
  if ( (*a2 & 0x10) == 0 )
  {
LABEL_97:
    if ( (v108 & 0x20) == 0 )
      goto LABEL_98;
LABEL_114:
    if ( v107 >= 2 )
    {
      printk(&unk_3DD3FE, "ipa_fltrt_generate_hw_rule_bdy_ip4");
      if ( ipa3_get_ipc_logbuf() )
      {
        v188 = ipa3_get_ipc_logbuf();
        ipc_log_string(v188, "ipahal %s:%d ran out of ihl_rng16 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1809);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v189 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v189, "ipahal %s:%d ran out of ihl_rng16 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1809);
      }
      goto LABEL_200;
    }
    if ( *((unsigned __int16 *)a2 + 5) < (unsigned int)*((unsigned __int16 *)a2 + 4) )
    {
      printk(&unk_3FA1EB, "ipa_fltrt_generate_hw_rule_bdy_ip4");
      if ( ipa3_get_ipc_logbuf() )
      {
        v192 = ipa3_get_ipc_logbuf();
        ipc_log_string(v192, "ipahal %s:%d bad dst port range param\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1813);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v193 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v193, "ipahal %s:%d bad dst port range param\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1813);
      }
      goto LABEL_200;
    }
    v126 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx > 0x19u )
      goto LABEL_202;
    v127 = *((int *)&ipa3_0_ihl_ofst_rng16 + v107);
    if ( v127 + 152 * (unsigned __int64)v126 + 128 > 0xF6F )
      goto LABEL_203;
    v128 = (_BYTE *)v200[0];
    *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v126 + 16] + v127);
    v129 = ipa_write_8(2, v128);
    v130 = *((_WORD *)a2 + 5);
    v200[0] = v129;
    v131 = ipa_write_16(v130, v199);
    v132 = ipa_write_16(*((_WORD *)a2 + 4), v131);
    v108 = *a2;
    ++v107;
    v199 = v132;
    if ( (v108 & 0x200) == 0 )
      goto LABEL_99;
    goto LABEL_119;
  }
LABEL_110:
  if ( *((unsigned __int16 *)a2 + 3) < (unsigned int)*((unsigned __int16 *)a2 + 2) )
  {
    printk(&unk_3FA1C2, "ipa_fltrt_generate_hw_rule_bdy_ip4");
    if ( ipa3_get_ipc_logbuf() )
    {
      v186 = ipa3_get_ipc_logbuf();
      ipc_log_string(v186, "ipahal %s:%d bad src port range param\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1794);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v187 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v187, "ipahal %s:%d bad src port range param\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1794);
    }
    goto LABEL_200;
  }
  v119 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx > 0x19u )
    goto LABEL_202;
  v120 = *((int *)&ipa3_0_ihl_ofst_rng16 + v107);
  if ( v120 + 152 * (unsigned __int64)v119 + 128 > 0xF6F )
    goto LABEL_203;
  v121 = (_BYTE *)v200[0];
  *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v119 + 16] + v120);
  v122 = ipa_write_8(0, v121);
  v123 = *((_WORD *)a2 + 3);
  v200[0] = v122;
  v124 = ipa_write_16(v123, v199);
  v125 = ipa_write_16(*((_WORD *)a2 + 2), v124);
  v108 = *a2;
  ++v107;
  v199 = v125;
  if ( (v108 & 0x20) != 0 )
    goto LABEL_114;
LABEL_98:
  if ( (v108 & 0x200) == 0 )
  {
LABEL_99:
    if ( (v108 & 0x400) == 0 )
      goto LABEL_100;
LABEL_123:
    if ( v107 >= 2 )
    {
      printk(&unk_3DD3FE, "ipa_fltrt_generate_hw_rule_bdy_ip4");
      if ( ipa3_get_ipc_logbuf() )
      {
        v194 = ipa3_get_ipc_logbuf();
        ipc_log_string(v194, "ipahal %s:%d ran out of ihl_rng16 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1843);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v195 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v195, "ipahal %s:%d ran out of ihl_rng16 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1843);
      }
      goto LABEL_200;
    }
    v140 = *(_DWORD *)ipahal_ctx;
    if ( *(_DWORD *)ipahal_ctx <= 0x19u )
    {
      v141 = *((int *)&ipa3_0_ihl_ofst_rng16 + v107);
      if ( v141 + 152 * (unsigned __int64)v140 + 128 > 0xF6F )
        goto LABEL_203;
      v142 = (_BYTE *)v200[0];
      *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v140 + 16] + v141);
      v143 = ipa_write_8(2, v142);
      v144 = *((_WORD *)a2 + 11);
      v200[0] = v143;
      v145 = ipa_write_16(v144, v199);
      v146 = ipa_write_16(*((_WORD *)a2 + 11), v145);
      v108 = *a2;
      v199 = v146;
      if ( (v108 & 0x8000) == 0 )
        goto LABEL_129;
      goto LABEL_127;
    }
LABEL_202:
    __break(0x5512u);
LABEL_203:
    __break(1u);
  }
LABEL_119:
  if ( v107 >= 2 )
  {
    printk(&unk_3DD3FE, "ipa_fltrt_generate_hw_rule_bdy_ip4");
    if ( ipa3_get_ipc_logbuf() )
    {
      v190 = ipa3_get_ipc_logbuf();
      ipc_log_string(v190, "ipahal %s:%d ran out of ihl_rng16 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1828);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v191 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v191, "ipahal %s:%d ran out of ihl_rng16 eq\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1828);
    }
    goto LABEL_200;
  }
  v133 = *(_DWORD *)ipahal_ctx;
  if ( *(_DWORD *)ipahal_ctx > 0x19u )
    goto LABEL_202;
  v134 = *((int *)&ipa3_0_ihl_ofst_rng16 + v107);
  if ( v134 + 152 * (unsigned __int64)v133 + 128 > 0xF6F )
    goto LABEL_203;
  v135 = (_BYTE *)v200[0];
  *a1 |= 1LL << *((_BYTE *)&ipahal_fltrt_objs[19 * v133 + 16] + v134);
  v136 = ipa_write_8(0, v135);
  v137 = *((_WORD *)a2 + 10);
  v200[0] = v136;
  v138 = ipa_write_16(v137, v199);
  v139 = ipa_write_16(*((_WORD *)a2 + 10), v138);
  v108 = *a2;
  ++v107;
  v199 = v139;
  if ( (v108 & 0x400) != 0 )
    goto LABEL_123;
LABEL_100:
  if ( (v108 & 0x8000) != 0 )
  {
LABEL_127:
    if ( *(_DWORD *)ipahal_ctx <= 0x19u )
    {
      *a1 |= 1LL << HIBYTE(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 17]);
      v108 = *a2;
      goto LABEL_129;
    }
    goto LABEL_202;
  }
LABEL_129:
  if ( (v108 & 1) != 0 )
    v147 = v13;
  else
    v147 = 1;
  if ( (v147 & 1) == 0 )
  {
    printk(&unk_3D4832, "ipa_fltrt_generate_hw_rule_bdy_ip4");
    if ( ipa3_get_ipc_logbuf() )
    {
      v174 = ipa3_get_ipc_logbuf();
      ipc_log_string(v174, "ipahal %s:%d could not find equation for tos\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1859);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v175 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v175, "ipahal %s:%d could not find equation for tos\n", "ipa_fltrt_generate_hw_rule_bdy_ip4", 1859);
    }
    goto LABEL_200;
  }
  result = 0;
LABEL_201:
  v196 = v199;
  *a3 = (_BYTE *)v200[0];
  *a4 = v196;
  _ReadStatusReg(SP_EL0);
  return result;
}
