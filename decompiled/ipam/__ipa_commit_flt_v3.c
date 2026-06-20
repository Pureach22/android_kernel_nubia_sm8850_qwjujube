__int64 __fastcall _ipa_commit_flt_v3(unsigned int a1)
{
  int v2; // w0
  __int64 v3; // x16
  __int64 v4; // x9
  __int64 v5; // x11
  __int64 v6; // x12
  int v7; // w11
  __int64 v8; // x13
  __int64 v9; // x14
  __int64 v10; // x15
  int v11; // w11
  int v12; // w9
  unsigned __int64 v13; // x20
  __int64 v14; // x27
  __int64 v15; // x24
  int v16; // w0
  __int64 *v17; // x27
  __int16 v18; // w26
  __int16 v19; // w3
  int v20; // w0
  __int64 v21; // x0
  int v22; // w8
  __int64 v23; // x0
  int v24; // w0
  int v25; // w8
  int v26; // w5
  int v27; // w8
  int v28; // w6
  __int64 v29; // x8
  __int64 v30; // x0
  char v31; // w8
  __int64 v32; // x1
  __int64 v33; // x0
  unsigned int aligned_lcl_bdy_size; // w0
  __int64 v35; // x8
  __int64 v36; // x11
  unsigned int v37; // w21
  unsigned int v38; // w20
  __int64 v39; // x0
  __int64 v40; // x0
  _QWORD *v41; // x8
  __int64 v42; // x9
  _QWORD *v43; // x27
  __int64 v44; // x0
  __int64 v45; // x1
  __int64 v46; // x22
  __int64 v47; // x8
  int v48; // w10
  unsigned int v49; // w0
  unsigned int v50; // w26
  unsigned int v51; // w25
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x8
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x10
  __int64 *v61; // x8
  __int64 v62; // x9
  __int64 v63; // x13
  __int64 v64; // x8
  __int64 v65; // x11
  int v66; // w21
  int v67; // w22
  int v68; // w23
  int v69; // w24
  __int64 v70; // x8
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x8
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x8
  __int64 v77; // x0
  __int64 v78; // x0
  __int64 v79; // x8
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v82; // x8
  __int64 v83; // x0
  __int64 v84; // x0
  __int64 v85; // x8
  __int64 v86; // x0
  __int64 v87; // x0
  int v89; // w26
  __int64 v90; // x25
  unsigned __int64 v91; // x22
  __int64 *v92; // x21
  int ep_mapping; // w0
  __int64 v94; // x8
  int v95; // w23
  unsigned int v96; // w24
  unsigned int v97; // w8
  int ep_reg_offset; // w0
  __int64 v99; // x0
  __int64 v100; // x0
  __int64 v101; // x8
  int v102; // w0
  __int64 v103; // x0
  unsigned int v104; // w24
  int v105; // w25
  int v106; // w8
  __int64 v107; // x0
  __int64 v108; // x0
  __int64 v109; // x0
  __int64 v110; // x20
  __int64 v111; // x0
  __int64 v112; // x20
  __int64 v113; // x0
  __int64 v114; // x0
  unsigned __int16 v115; // w20
  __int64 v116; // x0
  __int64 v117; // x0
  int v118; // w27
  __int64 v119; // x23
  unsigned int v120; // w24
  bool v121; // vf
  __int64 v122; // x8
  __int64 v123; // x0
  __int64 v124; // x0
  __int64 v125; // x0
  __int64 v126; // x0
  unsigned int v127; // w8
  unsigned __int64 v128; // x23
  __int64 v129; // x20
  __int64 v130; // x8
  __int64 v131; // x0
  __int64 v132; // x0
  __int64 v133; // x8
  __int64 v134; // x0
  __int64 v135; // x0
  __int64 v136; // x8
  __int64 v137; // x0
  __int64 v138; // x0
  __int64 v139; // x8
  __int64 v140; // x0
  __int64 v141; // x0
  __int64 v142; // x8
  __int64 v143; // x0
  __int64 v144; // x0
  __int64 v145; // x8
  __int64 v146; // x0
  __int64 v147; // x0
  __int64 v148; // x8
  __int64 v149; // x0
  __int64 v150; // x0
  __int64 v151; // x8
  __int64 v152; // x0
  __int64 v153; // x0
  __int64 v154; // x8
  __int64 v155; // x0
  __int64 v156; // x0
  __int64 v157; // x8
  __int64 v158; // x0
  __int64 v159; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v161; // x21
  __int64 v162; // x8
  __int64 v163; // x0
  __int64 v164; // x0
  __int64 v165; // x8
  __int64 v166; // x0
  __int64 v167; // x0
  int v168; // [xsp+Ch] [xbp-114h]
  unsigned __int16 v169; // [xsp+10h] [xbp-110h]
  __int64 v170; // [xsp+18h] [xbp-108h]
  int v171; // [xsp+20h] [xbp-100h]
  int v172; // [xsp+24h] [xbp-FCh]
  int v173; // [xsp+28h] [xbp-F8h]
  int v174; // [xsp+2Ch] [xbp-F4h]
  int v175; // [xsp+30h] [xbp-F0h]
  int v176; // [xsp+34h] [xbp-ECh]
  int v177; // [xsp+38h] [xbp-E8h]
  int v178; // [xsp+3Ch] [xbp-E4h]
  __int128 v179; // [xsp+40h] [xbp-E0h] BYREF
  int v180; // [xsp+50h] [xbp-D0h]
  __int64 v181; // [xsp+58h] [xbp-C8h] BYREF
  __int64 v182; // [xsp+60h] [xbp-C0h] BYREF
  __int64 v183; // [xsp+68h] [xbp-B8h]
  __int64 v184; // [xsp+70h] [xbp-B0h]
  __int128 v185; // [xsp+78h] [xbp-A8h] BYREF
  int v186; // [xsp+88h] [xbp-98h]
  _DWORD v187[2]; // [xsp+90h] [xbp-90h] BYREF
  __int64 v188; // [xsp+98h] [xbp-88h]
  __int64 v189; // [xsp+A0h] [xbp-80h]
  __int64 v190; // [xsp+A8h] [xbp-78h] BYREF
  __int64 v191; // [xsp+B0h] [xbp-70h]
  __int64 v192; // [xsp+B8h] [xbp-68h]
  __int64 v193; // [xsp+C0h] [xbp-60h] BYREF
  __int64 v194; // [xsp+C8h] [xbp-58h]
  __int64 v195; // [xsp+D0h] [xbp-50h]
  __int64 v196; // [xsp+D8h] [xbp-48h] BYREF
  __int64 v197; // [xsp+E0h] [xbp-40h]
  __int64 v198; // [xsp+E8h] [xbp-38h]
  __int64 v199; // [xsp+F0h] [xbp-30h] BYREF
  __int64 v200; // [xsp+F8h] [xbp-28h]
  __int64 v201; // [xsp+100h] [xbp-20h]
  int v202; // [xsp+10Ch] [xbp-14h] BYREF
  __int64 v203; // [xsp+110h] [xbp-10h]

  v203 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v186 = 0;
  v185 = 0u;
  v183 = 0;
  v184 = 0;
  v181 = 0;
  v182 = 0;
  v180 = 0;
  v179 = 0u;
  v2 = ((__int64 (*)(void))ipahal_get_hw_tbl_hdr_width)();
  v188 = 0;
  v189 = 0;
  v190 = 0;
  v191 = 0;
  v192 = 0;
  v193 = 0;
  v194 = 0;
  v195 = 0;
  v196 = 0;
  v197 = 0;
  v198 = 0;
  v199 = 0;
  v3 = 30470;
  v200 = 0;
  v201 = 0;
  if ( a1 )
    v3 = 30471;
  v187[0] = a1;
  v178 = v2;
  v187[1] = *(_DWORD *)(ipa3_ctx + 17496);
  v177 = *(unsigned __int16 *)(ipa3_ctx + 29522);
  v4 = **(_QWORD **)(ipa3_ctx + 34176);
  v5 = 28;
  if ( !a1 )
    v5 = 4;
  v6 = 40;
  v7 = *(_DWORD *)(v4 + v5);
  if ( !a1 )
    v6 = 16;
  v8 = 220;
  if ( !a1 )
    v8 = 204;
  v9 = 228;
  v174 = v7;
  if ( !a1 )
    v9 = 212;
  v10 = 30468;
  v173 = *(_DWORD *)(v4 + v6);
  v11 = *(_DWORD *)(v4 + v8);
  v12 = *(_DWORD *)(v4 + v9);
  if ( a1 )
    v10 = 30469;
  v171 = v11;
  v172 = v12;
  v175 = *(unsigned __int8 *)(ipa3_ctx + v10);
  v176 = *(unsigned __int8 *)(ipa3_ctx + v3);
  if ( !*(_DWORD *)(ipa3_ctx + 34308) )
  {
    v32 = 0;
    v33 = 0;
    goto LABEL_51;
  }
  v13 = 0;
  do
  {
    if ( (ipa_is_ep_support_flt((unsigned int)v13) & 1) == 0 )
      goto LABEL_15;
    if ( a1 > 2 || v13 > 0x23 )
      goto LABEL_315;
    v14 = ipa3_ctx + 304 * v13 + 152LL * a1;
    v15 = v14 + 17640;
    *(_QWORD *)(v14 + 17664) = 0;
    v16 = ((__int64 (*)(void))ipahal_get_rule_max_priority)();
    v17 = *(__int64 **)(v14 + 17640);
    v202 = v16;
    if ( v17 != (__int64 *)v15 )
    {
      v18 = v16;
      while ( 1 )
      {
        v19 = v18;
        if ( !*((_BYTE *)v17 + 373) )
        {
          v20 = ((__int64 (__fastcall *)(int *))ipahal_rule_decrease_priority)(&v202);
          v19 = v202;
          if ( v20 )
            break;
        }
        *((_WORD *)v17 + 208) = v19;
        if ( (unsigned int)ipa3_generate_flt_hw_rule(a1, v17, 0) )
        {
          printk(&unk_3CFB81, "ipa_prep_flt_tbl_for_cmt");
          v73 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v74 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v74 )
            {
              ipc_log_string(v74, "ipa %s:%d failed to calculate HW FLT rule size\n", "ipa_prep_flt_tbl_for_cmt", 154);
              v73 = ipa3_ctx;
            }
            v75 = *(_QWORD *)(v73 + 34160);
            if ( v75 )
            {
              ipc_log_string(v75, "ipa %s:%d failed to calculate HW FLT rule size\n", "ipa_prep_flt_tbl_for_cmt", 154);
              a1 = -1;
              goto LABEL_143;
            }
          }
LABEL_122:
          a1 = -1;
          goto LABEL_143;
        }
        if ( ipa3_ctx )
        {
          v21 = *(_QWORD *)(ipa3_ctx + 34160);
          if ( v21 )
            ipc_log_string(
              v21,
              "ipa %s:%d pipe %d rule_id(handle) %u hw_len %d priority %u\n",
              "ipa_prep_flt_tbl_for_cmt",
              158,
              v13,
              *((unsigned __int16 *)v17 + 209),
              *((_DWORD *)v17 + 102),
              *((unsigned __int16 *)v17 + 208));
        }
        v22 = *((_DWORD *)v17 + 102);
        if ( *((_BYTE *)v17 + 374) )
          *(_DWORD *)(v15 + 24) += v22;
        else
          *(_DWORD *)(v15 + 28) += v22;
        v17 = (__int64 *)*v17;
        if ( v17 == (__int64 *)v15 )
          goto LABEL_31;
      }
      printk(&unk_3A37E1, "ipa_prep_flt_tbl_for_cmt");
      v79 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v80 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v80 )
        {
          ipc_log_string(v80, "ipa %s:%d cannot decrease rule priority - %d\n", "ipa_prep_flt_tbl_for_cmt", 147, v202);
          v79 = ipa3_ctx;
        }
        v81 = *(_QWORD *)(v79 + 34160);
        if ( v81 )
          ipc_log_string(v81, "ipa %s:%d cannot decrease rule priority - %d\n", "ipa_prep_flt_tbl_for_cmt", 147, v202);
      }
      goto LABEL_122;
    }
LABEL_31:
    if ( !(*(_DWORD *)(v15 + 24) + *(_DWORD *)(v15 + 28)) )
    {
      if ( ipa3_ctx )
      {
        v23 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( v23 )
          ipc_log_string(
            v23,
            "ipa %s:%d flt tbl pipe %d is with zero total size\n",
            "ipa_prep_flt_tbl_for_cmt",
            169,
            v13);
      }
      goto LABEL_43;
    }
    v24 = ((__int64 (*)(void))ipahal_get_hw_tbl_hdr_width)();
    v25 = *(_DWORD *)(v15 + 24);
    if ( v25 )
    {
      v26 = v25 + v24;
      *(_DWORD *)(v15 + 24) = v25 + v24;
      v27 = *(_DWORD *)(v15 + 28);
      if ( v27 )
        goto LABEL_37;
    }
    else
    {
      v26 = 0;
      v27 = *(_DWORD *)(v15 + 28);
      if ( v27 )
      {
LABEL_37:
        v28 = v27 + v24;
        *(_DWORD *)(v15 + 28) = v27 + v24;
        v29 = ipa3_ctx;
        if ( ipa3_ctx )
          goto LABEL_41;
        goto LABEL_43;
      }
    }
    v28 = 0;
    v29 = ipa3_ctx;
    if ( ipa3_ctx )
    {
LABEL_41:
      v30 = *(_QWORD *)(v29 + 34160);
      if ( v30 )
        ipc_log_string(
          v30,
          "ipa %s:%d FLT tbl pipe idx %d hash sz %u non-hash sz %u\n",
          "ipa_prep_flt_tbl_for_cmt",
          182,
          v13,
          v26,
          v28);
    }
LABEL_43:
    v31 = *(_BYTE *)(v15 + 20);
    *(_BYTE *)(v15 + 145) = 0;
    if ( (v31 & 1) == 0 && *(_DWORD *)(v15 + 24) )
    {
      LODWORD(v188) = v188 + 1;
      LODWORD(v189) = *(_DWORD *)(v15 + 24) - v178 + v189;
    }
    if ( (*(_BYTE *)(v15 + 21) & 1) == 0 && *(_DWORD *)(v15 + 28) )
    {
      ++HIDWORD(v188);
      HIDWORD(v189) += *(_DWORD *)(v15 + 28) - v178;
    }
LABEL_15:
    ++v13;
  }
  while ( v13 < *(unsigned int *)(ipa3_ctx + 34308) );
  v33 = (unsigned int)v188;
  v32 = (unsigned int)v189;
LABEL_51:
  aligned_lcl_bdy_size = ipa_fltrt_get_aligned_lcl_bdy_size(v33, v32);
  v35 = ipa3_ctx;
  v36 = 224;
  v37 = aligned_lcl_bdy_size;
  if ( !a1 )
    v36 = 208;
  v38 = *(unsigned __int16 *)(**(_QWORD **)(ipa3_ctx + 34176) + v36);
  if ( ipa3_ctx && v38 < aligned_lcl_bdy_size )
  {
    v39 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v39 )
    {
      ipc_log_string(
        v39,
        "ipa %s:%d tbl too big, needed %d avail %d ipt %d rlt %d\n",
        "ipa_flt_valid_lcl_tbl_size",
        397,
        v37,
        v38,
        a1,
        0);
      v35 = ipa3_ctx;
    }
    v40 = *(_QWORD *)(v35 + 34160);
    if ( v40 )
      ipc_log_string(
        v40,
        "ipa %s:%d tbl too big, needed %d avail %d ipt %d rlt %d\n",
        "ipa_flt_valid_lcl_tbl_size",
        397,
        v37,
        v38,
        a1,
        0);
  }
  if ( v38 < v37 )
  {
    if ( (unsigned int)__ratelimit(&_ipa_commit_flt_v3__rs, "__ipa_commit_flt_v3") )
    {
      printk(&unk_3D860A, "__ipa_commit_flt_v3");
      v57 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_83;
    }
    else
    {
      v57 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_83:
        v58 = *(_QWORD *)(v57 + 34152);
        if ( v58 )
        {
          ipc_log_string(
            v58,
            "ipa %s:%d Hash filter table for IP:%d too big to fit in lcl memory\n",
            "__ipa_commit_flt_v3",
            571,
            a1);
          v57 = ipa3_ctx;
        }
        v59 = *(_QWORD *)(v57 + 34160);
        if ( v59 )
          ipc_log_string(
            v59,
            "ipa %s:%d Hash filter table for IP:%d too big to fit in lcl memory\n",
            "__ipa_commit_flt_v3",
            571,
            a1);
      }
    }
    a1 = -14;
    goto LABEL_88;
  }
  if ( a1 > 2 )
LABEL_315:
    __break(0x5512u);
  v41 = (_QWORD *)ipa3_ctx;
  v42 = ipa3_ctx + 16LL * a1;
  v43 = *(_QWORD **)(v42 + 30472);
  if ( v43 != (_QWORD *)(v42 + 30472) )
  {
    v44 = HIDWORD(v188);
    v45 = HIDWORD(v189);
    if ( a1 )
      v46 = 232;
    else
      v46 = 216;
    do
    {
      v49 = ipa_fltrt_get_aligned_lcl_bdy_size(v44, v45);
      v41 = (_QWORD *)ipa3_ctx;
      v50 = v49;
      v51 = *(unsigned __int16 *)(**(_QWORD **)(ipa3_ctx + 34176) + v46);
      if ( ipa3_ctx && v51 < v49 )
      {
        v52 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v52 )
        {
          ipc_log_string(
            v52,
            "ipa %s:%d tbl too big, needed %d avail %d ipt %d rlt %d\n",
            "ipa_flt_valid_lcl_tbl_size",
            397,
            v50,
            v51,
            a1,
            1);
          v41 = (_QWORD *)ipa3_ctx;
        }
        v53 = v41[4270];
        if ( v53 )
        {
          ipc_log_string(
            v53,
            "ipa %s:%d tbl too big, needed %d avail %d ipt %d rlt %d\n",
            "ipa_flt_valid_lcl_tbl_size",
            397,
            v50,
            v51,
            a1,
            1);
          v41 = (_QWORD *)ipa3_ctx;
        }
      }
      if ( v51 >= v50 || HIDWORD(v188) == 0 )
        break;
      if ( v41 )
      {
        v55 = v41[4269];
        if ( v55 )
        {
          ipc_log_string(
            v55,
            "ipa %s:%d SRAM partition is too small, move one non-hash table in DDR. IP:%d alloc_params.total_sz_lcl_nhash_tbls = %u\n",
            "__ipa_commit_flt_v3",
            586,
            a1,
            HIDWORD(v189));
          v41 = (_QWORD *)ipa3_ctx;
        }
        v56 = v41[4270];
        if ( v56 )
          ipc_log_string(
            v56,
            "ipa %s:%d SRAM partition is too small, move one non-hash table in DDR. IP:%d alloc_params.total_sz_lcl_nhash_tbls = %u\n",
            "__ipa_commit_flt_v3",
            586,
            a1,
            HIDWORD(v189));
      }
      *(_BYTE *)(v43[2] + 145LL) = 1;
      v44 = (unsigned int)(HIDWORD(v188) - 1);
      v47 = v43[2];
      --HIDWORD(v188);
      v48 = v178 - *(_DWORD *)(v47 + 28);
      v41 = (_QWORD *)ipa3_ctx;
      v45 = (unsigned int)(v48 + HIDWORD(v189));
      HIDWORD(v189) += v48;
      v43 = (_QWORD *)*v43;
    }
    while ( v43 != (_QWORD *)(ipa3_ctx + 16LL * a1 + 30472) );
  }
  v60 = 228;
  v61 = (__int64 *)v41[4272];
  v62 = 40;
  v63 = 220;
  if ( !a1 )
    v60 = 212;
  v64 = *v61;
  v65 = 28;
  if ( !a1 )
  {
    v62 = 16;
    v63 = 204;
    v65 = 4;
  }
  v66 = *(_DWORD *)(v64 + v60);
  v67 = *(_DWORD *)(v64 + v62);
  v68 = *(_DWORD *)(v64 + v63);
  v69 = *(_DWORD *)(v64 + v65);
  if ( (unsigned int)ipahal_fltrt_allocate_hw_tbl_imgs(v187) )
  {
    if ( (unsigned int)__ratelimit(&ipa_generate_flt_hw_tbl_img__rs, "ipa_generate_flt_hw_tbl_img") )
    {
      printk(&unk_3B233F, "ipa_generate_flt_hw_tbl_img");
      v70 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_101:
        v71 = *(_QWORD *)(v70 + 34152);
        if ( v71 )
        {
          ipc_log_string(
            v71,
            "ipa %s:%d fail to allocate FLT HW TBL images. IP %d\n",
            "ipa_generate_flt_hw_tbl_img",
            336,
            a1);
          v70 = ipa3_ctx;
        }
        v72 = *(_QWORD *)(v70 + 34160);
        if ( v72 )
          ipc_log_string(
            v72,
            "ipa %s:%d fail to allocate FLT HW TBL images. IP %d\n",
            "ipa_generate_flt_hw_tbl_img",
            336,
            a1);
      }
    }
    else
    {
      v70 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_101;
    }
LABEL_136:
    if ( (unsigned int)__ratelimit(&_ipa_commit_flt_v3__rs_3, "__ipa_commit_flt_v3") )
    {
      printk(&unk_3D8650, "__ipa_commit_flt_v3");
      v85 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_138:
        v86 = *(_QWORD *)(v85 + 34152);
        if ( v86 )
        {
          ipc_log_string(v86, "ipa %s:%d fail to generate FLT HW TBL image. IP %d\n", "__ipa_commit_flt_v3", 597, a1);
          v85 = ipa3_ctx;
        }
        v87 = *(_QWORD *)(v85 + 34160);
        if ( v87 )
          ipc_log_string(v87, "ipa %s:%d fail to generate FLT HW TBL image. IP %d\n", "__ipa_commit_flt_v3", 597, a1);
      }
    }
    else
    {
      v85 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_138;
    }
    a1 = -14;
    goto LABEL_143;
  }
  if ( (unsigned int)ipa_translate_flt_tbl_to_hw_fmt(a1, 0, v196, v190, (unsigned int)(v68 - v69)) )
  {
    if ( (unsigned int)__ratelimit(&ipa_generate_flt_hw_tbl_img__rs_129, "ipa_generate_flt_hw_tbl_img") )
    {
      printk(&unk_3DB6AA, "ipa_generate_flt_hw_tbl_img");
      v76 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_113:
        v77 = *(_QWORD *)(v76 + 34152);
        if ( v77 )
        {
          ipc_log_string(
            v77,
            "ipa %s:%d fail to translate hashable flt tbls to hw format\n",
            "ipa_generate_flt_hw_tbl_img",
            344);
          v76 = ipa3_ctx;
        }
        v78 = *(_QWORD *)(v76 + 34160);
        if ( v78 )
          ipc_log_string(
            v78,
            "ipa %s:%d fail to translate hashable flt tbls to hw format\n",
            "ipa_generate_flt_hw_tbl_img",
            344);
      }
    }
    else
    {
      v76 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_113;
    }
LABEL_130:
    if ( (_DWORD)v192 )
      ipahal_free_dma_mem(&v190);
    ipahal_free_dma_mem(&v193);
    if ( (_DWORD)v198 )
      ipahal_free_dma_mem(&v196);
    if ( (_DWORD)v201 )
      ipahal_free_dma_mem(&v199);
    goto LABEL_136;
  }
  if ( (unsigned int)ipa_translate_flt_tbl_to_hw_fmt(a1, 1, v199, v193, (unsigned int)(v66 - v67)) )
  {
    if ( (unsigned int)__ratelimit(&ipa_generate_flt_hw_tbl_img__rs_132, "ipa_generate_flt_hw_tbl_img") )
    {
      printk(&unk_3C0E4E, "ipa_generate_flt_hw_tbl_img");
      v82 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_130;
    }
    else
    {
      v82 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_130;
    }
    v83 = *(_QWORD *)(v82 + 34152);
    if ( v83 )
    {
      ipc_log_string(
        v83,
        "ipa %s:%d fail to translate non-hash flt tbls to hw format\n",
        "ipa_generate_flt_hw_tbl_img",
        351);
      v82 = ipa3_ctx;
    }
    v84 = *(_QWORD *)(v82 + 34160);
    if ( v84 )
      ipc_log_string(
        v84,
        "ipa %s:%d fail to translate non-hash flt tbls to hw format\n",
        "ipa_generate_flt_hw_tbl_img",
        351);
    goto LABEL_130;
  }
  LOWORD(v89) = 2 * *(_WORD *)(ipa3_ctx + 17496) + 4;
  v90 = _kmalloc_noprof(104LL * (unsigned __int16)v89, 2336);
  if ( !v90 )
    goto LABEL_317;
  while ( 2 )
  {
    v91 = 8LL * (unsigned __int16)v89;
    v92 = (__int64 *)_kmalloc_noprof(v91, 2336);
    if ( v92 )
    {
      ep_mapping = ipa_get_ep_mapping(95);
      v94 = ipa3_ctx;
      if ( ep_mapping == -1 || (*(_BYTE *)(ipa3_ctx + 51242) & 1) != 0 )
      {
        v95 = 0;
      }
      else
      {
        v96 = ipa_get_ep_mapping(95);
        BYTE12(v179) = 0;
        v97 = *(_DWORD *)(ipa3_ctx + 32240);
        v180 = 0;
        if ( v97 > 0x14 )
          ep_reg_offset = ipahal_get_ep_reg_offset(133, v96);
        else
          ep_reg_offset = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(44, 0, 0);
        LODWORD(v179) = ep_reg_offset;
        ipahal_get_aggr_force_close_valmask(v96, &v181);
        *(_QWORD *)((char *)&v179 + 4) = v181;
        v99 = ((__int64 (__fastcall *)(__int64, __int128 *, _QWORD))ipahal_construct_imm_cmd)(7, &v179, 0);
        if ( !v91 )
          goto LABEL_316;
        *v92 = v99;
        if ( !v99 )
        {
          printk(&unk_3AEDE8, "__ipa_commit_flt_v3");
          v148 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_295;
          v149 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v149 )
          {
            ipc_log_string(v149, "ipa %s:%d failed to construct coal close IC\n", "__ipa_commit_flt_v3", 634);
            v148 = ipa3_ctx;
          }
          v150 = *(_QWORD *)(v148 + 34160);
          if ( v150 )
          {
            ipc_log_string(v150, "ipa %s:%d failed to construct coal close IC\n", "__ipa_commit_flt_v3", 634);
            a1 = -12;
          }
          else
          {
LABEL_295:
            a1 = -12;
          }
LABEL_251:
          kfree(v90);
          kfree(v92);
          goto LABEL_88;
        }
        ipa3_init_imm_cmd_desc(v90, v99);
        v94 = ipa3_ctx;
        v95 = 1;
      }
      if ( (*(_BYTE *)(v94 + 32270) & 1) == 0 )
      {
        if ( *(_DWORD *)(v94 + 32240) < 0x15u )
        {
          v101 = 3;
          if ( a1 )
            v101 = 1;
          v202 = 0;
          *(_BYTE *)((unsigned __int64)&v202 | v101) = 1;
          ipahal_get_fltrt_hash_flush_valmask(&v202, &v181);
          v100 = 67;
        }
        else
        {
          LOWORD(v202) = 256;
          ipahal_get_fltrt_cache_flush_valmask(&v202, &v181);
          v100 = 140;
        }
        v102 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(v100, 0, 0);
        BYTE12(v185) = 0;
        v186 = 0;
        LODWORD(v185) = v102;
        *(_QWORD *)((char *)&v185 + 4) = v181;
        v103 = ((__int64 (__fastcall *)(__int64, __int128 *, _QWORD))ipahal_construct_imm_cmd)(7, &v185, 0);
        if ( v91 <= 8 * (unsigned __int64)(unsigned int)v95 )
          goto LABEL_316;
        v92[v95] = v103;
        if ( !v103 )
        {
          printk(&unk_3D2A74, "__ipa_commit_flt_v3");
          v133 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v134 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v134 )
            {
              ipc_log_string(
                v134,
                "ipa %s:%d fail construct register_write imm cmd: IP %d\n",
                "__ipa_commit_flt_v3",
                679,
                a1);
              v133 = ipa3_ctx;
            }
            v135 = *(_QWORD *)(v133 + 34160);
            if ( v135 )
            {
              ipc_log_string(
                v135,
                "ipa %s:%d fail construct register_write imm cmd: IP %d\n",
                "__ipa_commit_flt_v3",
                679,
                a1);
              a1 = -14;
              goto LABEL_247;
            }
          }
          goto LABEL_281;
        }
        ipa3_init_imm_cmd_desc(v90 + 104LL * (unsigned int)v95, v103);
        v94 = ipa3_ctx;
        ++v95;
      }
      v169 = v89;
      v170 = v90;
      if ( !*(_DWORD *)(v94 + 34308) )
      {
LABEL_213:
        if ( v176 )
        {
          v115 = v169;
          v90 = v170;
          if ( !HIDWORD(v188) )
            goto LABEL_220;
          if ( v95 < v169 )
          {
            v182 = v200;
            *(_WORD *)((char *)&v184 + 1) = 0;
            HIDWORD(v184) = 0;
            LODWORD(v183) = v201;
            HIDWORD(v183) = v172 + v177;
            v116 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v182, 0);
            if ( v91 <= 8LL * v95 )
              goto LABEL_316;
            v92[v95] = v116;
            if ( v116 )
            {
              ipa3_init_imm_cmd_desc(v170 + 104LL * v95++, v116);
              goto LABEL_220;
            }
            printk(&unk_3D2AAE, "__ipa_commit_flt_v3");
            v142 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v143 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v143 )
              {
                ipc_log_string(
                  v143,
                  "ipa %s:%d fail construct dma_shared_mem cmd: IP = %d\n",
                  "__ipa_commit_flt_v3",
                  776,
                  a1);
                v142 = ipa3_ctx;
              }
              v144 = *(_QWORD *)(v142 + 34160);
              if ( v144 )
              {
                ipc_log_string(
                  v144,
                  "ipa %s:%d fail construct dma_shared_mem cmd: IP = %d\n",
                  "__ipa_commit_flt_v3",
                  776,
                  a1);
LABEL_287:
                a1 = -12;
                goto LABEL_247;
              }
            }
            goto LABEL_288;
          }
          printk(&unk_3C0D8B, "__ipa_commit_flt_v3");
          v136 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v137 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v137 )
            {
              ipc_log_string(
                v137,
                "ipa %s:%d number of commands is out of range: IP = %d\n",
                "__ipa_commit_flt_v3",
                761,
                a1);
              v136 = ipa3_ctx;
            }
            v138 = *(_QWORD *)(v136 + 34160);
            if ( v138 )
            {
              ipc_log_string(
                v138,
                "ipa %s:%d number of commands is out of range: IP = %d\n",
                "__ipa_commit_flt_v3",
                761,
                a1);
LABEL_274:
              a1 = -105;
              goto LABEL_247;
            }
          }
          goto LABEL_275;
        }
        v115 = v169;
        v90 = v170;
LABEL_220:
        if ( v175 )
        {
          if ( v95 >= v115 )
          {
            printk(&unk_3C0D8B, "__ipa_commit_flt_v3");
            v139 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v140 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v140 )
              {
                ipc_log_string(
                  v140,
                  "ipa %s:%d number of commands is out of range: IP = %d\n",
                  "__ipa_commit_flt_v3",
                  786,
                  a1);
                v139 = ipa3_ctx;
              }
              v141 = *(_QWORD *)(v139 + 34160);
              if ( v141 )
              {
                ipc_log_string(
                  v141,
                  "ipa %s:%d number of commands is out of range: IP = %d\n",
                  "__ipa_commit_flt_v3",
                  786,
                  a1);
                goto LABEL_274;
              }
            }
LABEL_275:
            a1 = -105;
            goto LABEL_247;
          }
          v182 = v197;
          *(_WORD *)((char *)&v184 + 1) = 0;
          HIDWORD(v184) = 0;
          LODWORD(v183) = v198;
          HIDWORD(v183) = v171 + v177;
          v117 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v182, 0);
          if ( v91 <= 8LL * v95 )
            goto LABEL_316;
          v92[v95] = v117;
          if ( !v117 )
          {
            printk(&unk_3D2AAE, "__ipa_commit_flt_v3");
            v145 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v146 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v146 )
              {
                ipc_log_string(
                  v146,
                  "ipa %s:%d fail construct dma_shared_mem cmd: IP = %d\n",
                  "__ipa_commit_flt_v3",
                  801,
                  a1);
                v145 = ipa3_ctx;
              }
              v147 = *(_QWORD *)(v145 + 34160);
              if ( v147 )
              {
                ipc_log_string(
                  v147,
                  "ipa %s:%d fail construct dma_shared_mem cmd: IP = %d\n",
                  "__ipa_commit_flt_v3",
                  801,
                  a1);
                goto LABEL_287;
              }
            }
LABEL_288:
            a1 = -12;
            goto LABEL_247;
          }
          ipa3_init_imm_cmd_desc(v90 + 104LL * v95++, v117);
        }
        v118 = v95;
        if ( v95 < 1 )
        {
LABEL_233:
          v122 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v123 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( !v123
              || (ipc_log_string(v123, "ipa %s:%d Hashable HEAD\n", "__ipa_commit_flt_v3", 830), (v122 = ipa3_ctx) != 0) )
            {
              v124 = *(_QWORD *)(v122 + 34160);
              if ( v124 )
                ipc_log_string(v124, "ipa %s:%d Non-Hashable HEAD\n", "__ipa_commit_flt_v3", 834);
            }
          }
          v90 = v170;
          v95 = v118;
          if ( (_DWORD)v198 )
          {
            if ( ipa3_ctx )
            {
              v125 = *(_QWORD *)(ipa3_ctx + 34160);
              if ( v125 )
                ipc_log_string(v125, "ipa %s:%d Hashable BODY\n", "__ipa_commit_flt_v3", 839);
            }
          }
          if ( (_DWORD)v201 )
          {
            if ( ipa3_ctx )
            {
              v126 = *(_QWORD *)(ipa3_ctx + 34160);
              if ( v126 )
                ipc_log_string(v126, "ipa %s:%d Non-Hashable BODY\n", "__ipa_commit_flt_v3", 846);
            }
          }
          ((void (__fastcall *)(_QWORD, _QWORD))_ipa_reap_sys_flt_tbls)(a1, 0);
          ((void (__fastcall *)(_QWORD, __int64))_ipa_reap_sys_flt_tbls)(a1, 1);
          a1 = 0;
          goto LABEL_247;
        }
        v119 = v170;
        v89 = v118;
        while ( 1 )
        {
          v120 = (unsigned int)v89 >= 0xA ? 10 : v89;
          if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, __int64))ipa3_send_cmd)(v120, v119) )
            break;
          v119 += 104LL * v120;
          v121 = __OFSUB__(v89, v120);
          v89 -= v120;
          if ( (v89 < 0) ^ v121 | (v89 == 0) )
            goto LABEL_233;
        }
        printk(&unk_3ACB28, "__ipa_commit_flt_v3");
        v130 = ipa3_ctx;
        if ( !ipa3_ctx )
        {
          v90 = v170;
          a1 = -14;
          v95 = v118;
          goto LABEL_247;
        }
        v90 = v170;
        v95 = v118;
        v131 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v131 )
        {
          ipc_log_string(v131, "ipa %s:%d fail to send immediate command batch\n", "__ipa_commit_flt_v3", 823);
          v130 = ipa3_ctx;
        }
        v132 = *(_QWORD *)(v130 + 34160);
        if ( v132 )
        {
          ipc_log_string(v132, "ipa %s:%d fail to send immediate command batch\n", "__ipa_commit_flt_v3", 823);
          a1 = -14;
          goto LABEL_247;
        }
LABEL_281:
        a1 = -14;
        goto LABEL_247;
      }
      v104 = 0;
      v105 = 0;
      v168 = v174 + v177 + v178;
      v173 += v177 + v178;
      v106 = (unsigned __int16)v89;
      LOWORD(v89) = -31376;
      v174 = v106;
LABEL_177:
      if ( (ipa_is_ep_support_flt(v104) & 1) != 0 )
      {
        if ( (ipa_is_modem_pipe(v104) & 1) != 0 )
        {
          if ( ipa3_ctx )
          {
            v107 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v107 )
              ipc_log_string(v107, "ipa %s:%d skip %d - modem owned pipe\n", "ipa_flt_skip_pipe_config", 447, v104);
          }
          goto LABEL_175;
        }
        if ( v104 >= 0x24 )
          goto LABEL_315;
        if ( *(_BYTE *)(ipa3_ctx + (int)v104 + 17448) == 1 )
        {
          if ( ipa3_ctx )
          {
            v109 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v109 )
              ipc_log_string(v109, "ipa %s:%d skip %d\n", "ipa_flt_skip_pipe_config", 452, v104);
          }
          goto LABEL_175;
        }
        v110 = ipa3_ctx + 480LL * (int)v104;
        if ( v104 == (unsigned int)ipa_get_ep_mapping(34)
          && *(_BYTE *)(ipa3_ctx + 32262) == 1
          && *(_DWORD *)(v110 + 172) == 34 )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
            ipc_log_string(*(_QWORD *)(ipa3_ctx + 34160), "ipa %s:%d skip %d\n", "ipa_flt_skip_pipe_config", 461, v104);
          goto LABEL_175;
        }
        if ( v104 == (unsigned int)ipa_get_ep_mapping(120)
          && *(_BYTE *)(ipa3_ctx + 32262) == 1
          && *(_DWORD *)(v110 + 172) == 120 )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
            ipc_log_string(*(_QWORD *)(ipa3_ctx + 34160), "ipa %s:%d skip %d\n", "ipa_flt_skip_pipe_config", 468, v104);
LABEL_175:
          ++v105;
        }
        else
        {
          v89 = v95++;
          if ( v95 >= v174 )
          {
            printk(&unk_3C0D8B, "__ipa_commit_flt_v3");
            v151 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v152 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v152 )
              {
                ipc_log_string(
                  v152,
                  "ipa %s:%d number of commands is out of range: IP = %d\n",
                  "__ipa_commit_flt_v3",
                  701,
                  a1);
                v151 = ipa3_ctx;
              }
              v153 = *(_QWORD *)(v151 + 34160);
              if ( v153 )
                ipc_log_string(
                  v153,
                  "ipa %s:%d number of commands is out of range: IP = %d\n",
                  "__ipa_commit_flt_v3",
                  701,
                  a1);
            }
            a1 = -105;
            goto LABEL_308;
          }
          if ( ipa3_ctx )
          {
            v111 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v111 )
              ipc_log_string(
                v111,
                "ipa %s:%d Prepare imm cmd for hdr at index %d for pipe %d\n",
                "__ipa_commit_flt_v3",
                707,
                v105,
                v104);
          }
          *(_WORD *)((char *)&v184 + 1) = 0;
          v112 = (unsigned int)(v105 * v178);
          HIDWORD(v184) = 0;
          v182 = v194 + v112;
          LODWORD(v183) = v178;
          HIDWORD(v183) = v173 + v112;
          v113 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v182, 0);
          if ( v91 <= 8LL * v89 )
            goto LABEL_316;
          v92[v89] = v113;
          if ( !v113 )
          {
            printk(&unk_3D2AAE, "__ipa_commit_flt_v3");
            v154 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v155 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v155 )
              {
                ipc_log_string(
                  v155,
                  "ipa %s:%d fail construct dma_shared_mem cmd: IP = %d\n",
                  "__ipa_commit_flt_v3",
                  721,
                  a1);
                v154 = ipa3_ctx;
              }
              v156 = *(_QWORD *)(v154 + 34160);
              if ( v156 )
                ipc_log_string(
                  v156,
                  "ipa %s:%d fail construct dma_shared_mem cmd: IP = %d\n",
                  "__ipa_commit_flt_v3",
                  721,
                  a1);
            }
            a1 = -12;
LABEL_308:
            v90 = v170;
            v95 = v89;
            goto LABEL_247;
          }
          ipa3_init_imm_cmd_desc(v170 + 104LL * v89, v113);
          if ( (*(_BYTE *)(ipa3_ctx + 32270) & 1) == 0 )
          {
            *(_WORD *)((char *)&v184 + 1) = 0;
            HIDWORD(v184) = 0;
            v182 = v191 + v112;
            LODWORD(v183) = v178;
            HIDWORD(v183) = v168 + v112;
            v114 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v182, 0);
            if ( v91 <= 8LL * v95 )
              goto LABEL_316;
            v92[v95] = v114;
            if ( !v114 )
            {
              printk(&unk_3D2AAE, "__ipa_commit_flt_v3");
              v157 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v158 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v158 )
                {
                  ipc_log_string(
                    v158,
                    "ipa %s:%d fail construct dma_shared_mem cmd: IP = %d\n",
                    "__ipa_commit_flt_v3",
                    747,
                    a1);
                  v157 = ipa3_ctx;
                }
                v159 = *(_QWORD *)(v157 + 34160);
                if ( v159 )
                  ipc_log_string(
                    v159,
                    "ipa %s:%d fail construct dma_shared_mem cmd: IP = %d\n",
                    "__ipa_commit_flt_v3",
                    747,
                    a1);
              }
              v90 = v170;
              a1 = -12;
LABEL_247:
              if ( v95 < 1 )
                goto LABEL_251;
              v127 = v95;
              v128 = 0;
              v129 = 8LL * v127;
              while ( v91 > v128 )
              {
                kfree(v92[v128 / 8]);
                v128 += 8LL;
                if ( v129 == v128 )
                  goto LABEL_251;
              }
LABEL_316:
              __break(1u);
              StatusReg = _ReadStatusReg(SP_EL0);
              v161 = *(_QWORD *)(StatusReg + 80);
              *(_QWORD *)(StatusReg + 80) = &ipa_flt_alloc_cmd_buffers__alloc_tag;
              v90 = _kmalloc_noprof(104LL * (unsigned __int16)v89, 2336);
              *(_QWORD *)(StatusReg + 80) = v161;
              if ( !v90 )
              {
LABEL_317:
                printk(&unk_3C3F27, "ipa_flt_alloc_cmd_buffers");
                v162 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v163 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v163 )
                  {
                    ipc_log_string(
                      v163,
                      "ipa %s:%d fail to alloc desc blob ip %d\n",
                      "ipa_flt_alloc_cmd_buffers",
                      417,
                      a1);
                    v162 = ipa3_ctx;
                  }
                  v164 = *(_QWORD *)(v162 + 34160);
                  if ( v164 )
                    ipc_log_string(
                      v164,
                      "ipa %s:%d fail to alloc desc blob ip %d\n",
                      "ipa_flt_alloc_cmd_buffers",
                      417,
                      a1);
                }
                a1 = -12;
                goto LABEL_88;
              }
              continue;
            }
            ipa3_init_imm_cmd_desc(v170 + 104LL * v95, v114);
            v95 = v89 + 2;
          }
          ++v105;
          LOWORD(v89) = -31376;
        }
      }
      else if ( ipa3_ctx )
      {
        v108 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( v108 )
          ipc_log_string(v108, "ipa %s:%d skip %d - not filtering pipe\n", "__ipa_commit_flt_v3", 690, v104);
      }
      if ( ++v104 >= *(_DWORD *)(ipa3_ctx + 34308) )
        goto LABEL_213;
      goto LABEL_177;
    }
    break;
  }
  printk(&unk_3ACBBF, "ipa_flt_alloc_cmd_buffers");
  v165 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v166 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v166 )
    {
      ipc_log_string(v166, "ipa %s:%d fail to alloc cmd pyld blob ip %d\n", "ipa_flt_alloc_cmd_buffers", 423, a1);
      v165 = ipa3_ctx;
    }
    v167 = *(_QWORD *)(v165 + 34160);
    if ( v167 )
      ipc_log_string(v167, "ipa %s:%d fail to alloc cmd pyld blob ip %d\n", "ipa_flt_alloc_cmd_buffers", 423, a1);
  }
  kfree(v90);
  a1 = -12;
LABEL_88:
  if ( (_DWORD)v192 )
    ipahal_free_dma_mem(&v190);
  ipahal_free_dma_mem(&v193);
  if ( (_DWORD)v198 )
    ipahal_free_dma_mem(&v196);
  if ( (_DWORD)v201 )
    ipahal_free_dma_mem(&v199);
LABEL_143:
  _ReadStatusReg(SP_EL0);
  return a1;
}
