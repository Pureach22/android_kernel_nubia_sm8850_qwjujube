__int64 __fastcall _ipa_commit_rt_v3(unsigned int a1)
{
  int v2; // w20
  __int64 v3; // x2
  __int64 v4; // x8
  _QWORD *v5; // x11
  int v6; // w26
  _DWORD *v7; // x10
  int v8; // w13
  int v9; // w14
  int v10; // w12
  int v11; // w11
  int v12; // w16
  __int64 v13; // x0
  __int64 v14; // x1
  char v15; // w17
  __int64 v16; // x27
  int v17; // w9
  unsigned int v18; // w12
  unsigned int v19; // w28
  int v20; // w11
  __int64 v21; // x9
  __int64 *v22; // x25
  int *v23; // x21
  __int64 rt_hw_rule; // x0
  __int64 *v25; // x28
  int *v26; // x20
  __int16 v27; // w27
  _DWORD *v28; // x8
  __int16 v29; // w3
  int v30; // w0
  __int64 v31; // x8
  __int64 v32; // x0
  int v33; // w0
  int v34; // w8
  int v35; // w5
  int v36; // w8
  int v37; // w6
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  int v41; // w8
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 result; // x0
  __int64 v46; // x8
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x10
  __int64 *v50; // x8
  __int64 v51; // x9
  __int64 v52; // x11
  __int64 v53; // x12
  __int64 v54; // x8
  __int64 v55; // x13
  int v56; // w21
  int v57; // w22
  int v58; // w23
  int v59; // w24
  unsigned int v60; // w20
  int ep_mapping; // w0
  __int64 v62; // x8
  unsigned int v63; // w22
  unsigned int v64; // w19
  unsigned int v65; // w20
  int ep_reg_offset; // w0
  __int64 v67; // x8
  __int64 v68; // x0
  __int64 v69; // x0
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
  __int64 v82; // x0
  __int64 v83; // x8
  __int64 v84; // x0
  int v85; // w0
  __int64 v86; // x0
  __int64 v87; // x0
  unsigned int v88; // w20
  __int64 v89; // x0
  __int64 v90; // x0
  __int64 v91; // x0
  __int64 v92; // x8
  __int64 v93; // x0
  __int64 v94; // x0
  __int64 v95; // x8
  __int64 v96; // x0
  __int64 v97; // x0
  __int64 v98; // x0
  __int64 v99; // x0
  __int64 v100; // x8
  __int64 v101; // x9
  __int64 *v102; // x23
  __int64 v103; // x24
  __int64 v104; // x0
  __int64 v105; // x0
  __int64 v106; // x8
  __int64 *v107; // x21
  __int64 v108; // x24
  __int64 *v109; // x26
  __int64 v110; // x0
  __int64 v111; // x0
  __int64 **v112; // x8
  __int64 *v113; // x9
  __int64 v114; // x8
  __int64 v115; // x0
  __int64 v116; // x0
  __int64 v117; // x8
  __int64 v118; // x0
  __int64 v119; // x0
  __int64 v120; // x8
  __int64 v121; // x0
  __int64 v122; // x0
  __int64 v123; // x8
  __int64 v124; // x0
  __int64 v125; // x0
  __int64 v126; // x8
  __int64 v127; // x0
  __int64 v128; // x0
  __int64 v129; // x8
  __int64 v130; // x0
  __int64 v131; // x0
  unsigned int v132; // [xsp+8h] [xbp-3A8h]
  int v133; // [xsp+10h] [xbp-3A0h]
  int v134; // [xsp+18h] [xbp-398h]
  int v135; // [xsp+1Ch] [xbp-394h]
  unsigned int v136; // [xsp+20h] [xbp-390h]
  char v137; // [xsp+24h] [xbp-38Ch]
  char v138; // [xsp+28h] [xbp-388h]
  int v139; // [xsp+2Ch] [xbp-384h]
  __int64 v140; // [xsp+30h] [xbp-380h]
  __int128 v141; // [xsp+38h] [xbp-378h] BYREF
  int v142; // [xsp+48h] [xbp-368h]
  __int64 v143; // [xsp+50h] [xbp-360h] BYREF
  __int64 v144; // [xsp+58h] [xbp-358h] BYREF
  __int64 v145; // [xsp+60h] [xbp-350h]
  __int64 v146; // [xsp+68h] [xbp-348h]
  __int64 v147; // [xsp+70h] [xbp-340h] BYREF
  __int64 v148; // [xsp+78h] [xbp-338h]
  __int64 v149; // [xsp+80h] [xbp-330h]
  __int64 v150; // [xsp+88h] [xbp-328h] BYREF
  __int64 v151; // [xsp+90h] [xbp-320h]
  __int64 v152; // [xsp+98h] [xbp-318h]
  __int64 v153; // [xsp+A0h] [xbp-310h] BYREF
  __int64 v154; // [xsp+A8h] [xbp-308h]
  __int64 v155; // [xsp+B0h] [xbp-300h]
  __int64 v156; // [xsp+B8h] [xbp-2F8h] BYREF
  __int64 v157; // [xsp+C0h] [xbp-2F0h]
  __int64 v158; // [xsp+C8h] [xbp-2E8h]
  __int64 v159; // [xsp+D0h] [xbp-2E0h] BYREF
  unsigned __int64 v160; // [xsp+D8h] [xbp-2D8h]
  __int64 v161; // [xsp+E0h] [xbp-2D0h]
  __int128 v162; // [xsp+E8h] [xbp-2C8h] BYREF
  int v163; // [xsp+F8h] [xbp-2B8h]
  int v164; // [xsp+FCh] [xbp-2B4h] BYREF
  __int64 v165; // [xsp+100h] [xbp-2B0h]
  __int64 v166; // [xsp+108h] [xbp-2A8h]
  __int64 v167; // [xsp+110h] [xbp-2A0h]
  __int64 v168; // [xsp+118h] [xbp-298h]
  __int64 v169; // [xsp+120h] [xbp-290h]
  __int64 v170; // [xsp+128h] [xbp-288h]
  _QWORD s[80]; // [xsp+130h] [xbp-280h] BYREF

  s[78] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v163 = 0;
  v162 = 0u;
  v160 = 0;
  v161 = 0;
  v159 = 0;
  v143 = 0;
  v142 = 0;
  v141 = 0u;
  v2 = ((__int64 (*)(void))ipahal_get_hw_tbl_hdr_width)();
  memset(s, 0, 0x270u);
  v145 = 0;
  v4 = ipa3_ctx;
  v146 = 0;
  v147 = 0;
  v148 = 0;
  v149 = 0;
  v150 = 0;
  v151 = 0;
  v152 = 0;
  v153 = 0;
  v154 = 0;
  v155 = 0;
  v156 = 0;
  v157 = 0;
  v158 = 0;
  v144 = a1;
  v5 = *(_QWORD **)(ipa3_ctx + 34176);
  v165 = 0;
  v166 = 0;
  v6 = *(unsigned __int16 *)(ipa3_ctx + 29522);
  v167 = 0;
  v168 = 0;
  v7 = (_DWORD *)*v5;
  v169 = 0;
  v170 = 0;
  if ( a1 )
  {
    v9 = v7[25];
    v8 = v7[26];
    v10 = v7[29];
    v11 = v7[32];
    v12 = v7[66];
    v13 = (unsigned int)v7[68];
    v14 = *(unsigned __int8 *)(ipa3_ctx + 30467);
    v15 = *(_BYTE *)(ipa3_ctx + 30465);
    HIDWORD(v144) = v7[28] - v7[27] + 1;
    if ( a1 != 1 )
    {
      __break(0x5512u);
      return ipa_rt_valid_lcl_tbl_size(v13, v14, v3);
    }
    v16 = 1;
    v17 = v2 + v2 * (v8 - v9) + v6;
    v18 = v17 + v10;
    v19 = v17 + v11;
  }
  else
  {
    v16 = 0;
    v12 = v7[62];
    LODWORD(v13) = v7[64];
    LOBYTE(v14) = *(_BYTE *)(ipa3_ctx + 30466);
    v15 = *(_BYTE *)(ipa3_ctx + 30464);
    v20 = v2 + v2 * (v7[15] - v7[14]) + v6;
    v18 = v20 + v7[18];
    v19 = v20 + v7[21];
    HIDWORD(v144) = v7[17] - v7[16] + 1;
  }
  if ( !*(_QWORD *)(ipa3_ctx + 8 * v16 + 29456) )
  {
    printk(&unk_3FBB25, "__ipa_commit_rt_v3");
    v46 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v47 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v47 )
      {
        ipc_log_string(v47, "ipa %s:%d no rt tbls present\n", "__ipa_commit_rt_v3", 530);
        v46 = ipa3_ctx;
      }
      v48 = *(_QWORD *)(v46 + 34160);
      if ( v48 )
      {
        ipc_log_string(v48, "ipa %s:%d no rt tbls present\n", "__ipa_commit_rt_v3", 530);
LABEL_52:
        result = 0xFFFFFFFFLL;
        goto LABEL_120;
      }
    }
LABEL_119:
    result = 0xFFFFFFFFLL;
    goto LABEL_120;
  }
  v135 = v13;
  v136 = v18;
  v21 = ipa3_ctx + 48LL * (unsigned int)v16;
  v137 = v15;
  v138 = v14;
  v134 = v12;
  v22 = *(__int64 **)(v21 + 29184);
  v140 = v21 + 29184;
  if ( v22 == (__int64 *)(v21 + 29184) )
    goto LABEL_59;
  v132 = v19;
  v139 = v2;
  v133 = v16;
  do
  {
    *(__int64 *)((char *)v22 + 100) = 0;
    v23 = (int *)v22 + 25;
    rt_hw_rule = ((__int64 (*)(void))ipahal_get_rule_max_priority)();
    v164 = rt_hw_rule;
    v25 = (__int64 *)v22[3];
    v26 = (int *)(v22 + 13);
    if ( v25 != v22 + 3 )
    {
      v27 = rt_hw_rule;
      while ( 1 )
      {
        v29 = v27;
        if ( !*((_BYTE *)v25 + 184) )
        {
          v30 = ((__int64 (__fastcall *)(int *))ipahal_rule_decrease_priority)(&v164);
          v29 = v164;
          if ( v30 )
          {
            printk(&unk_3F2C26, "ipa_prep_rt_tbl_for_cmt");
            v79 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v80 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v80 )
              {
                ipc_log_string(
                  v80,
                  "ipa %s:%d cannot rule decrease priority - %d\n",
                  "ipa_prep_rt_tbl_for_cmt",
                  321,
                  v164);
                v79 = ipa3_ctx;
              }
              v81 = *(_QWORD *)(v79 + 34160);
              if ( v81 )
                ipc_log_string(
                  v81,
                  "ipa %s:%d cannot rule decrease priority - %d\n",
                  "ipa_prep_rt_tbl_for_cmt",
                  321,
                  v164);
            }
            goto LABEL_119;
          }
        }
        *((_WORD *)v25 + 116) = v29;
        rt_hw_rule = ipa_generate_rt_hw_rule(a1, v25, 0);
        if ( (_DWORD)rt_hw_rule )
          break;
        if ( ipa3_ctx )
        {
          rt_hw_rule = *(_QWORD *)(ipa3_ctx + 34160);
          if ( rt_hw_rule )
            rt_hw_rule = ipc_log_string(
                           rt_hw_rule,
                           "ipa %s:%d RT rule id (handle) %d hw_len %u priority %u\n",
                           "ipa_prep_rt_tbl_for_cmt",
                           334,
                           *((_DWORD *)v25 + 57),
                           *((_DWORD *)v25 + 56),
                           *((unsigned __int16 *)v25 + 116));
        }
        if ( *((_BYTE *)v25 + 185) )
          v28 = (_DWORD *)v22 + 25;
        else
          v28 = v22 + 13;
        *v28 += *((_DWORD *)v25 + 56);
        v25 = (__int64 *)*v25;
        if ( v25 == v22 + 3 )
          goto LABEL_21;
      }
      if ( (unsigned int)__ratelimit(&ipa_prep_rt_tbl_for_cmt__rs, "ipa_prep_rt_tbl_for_cmt") )
        printk(&unk_3D62A0, "ipa_prep_rt_tbl_for_cmt");
      v42 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v43 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v43 )
        {
          ipc_log_string(v43, "ipa %s:%d failed to calculate HW RT rule size\n", "ipa_prep_rt_tbl_for_cmt", 329);
          v42 = ipa3_ctx;
        }
        v44 = *(_QWORD *)(v42 + 34160);
        if ( v44 )
        {
          ipc_log_string(v44, "ipa %s:%d failed to calculate HW RT rule size\n", "ipa_prep_rt_tbl_for_cmt", 329);
          goto LABEL_52;
        }
      }
      goto LABEL_119;
    }
LABEL_21:
    if ( !(*v23 + *v26) )
    {
      rt_hw_rule = __ratelimit(&ipa_prep_rt_tbl_for_cmt__rs_153, "ipa_prep_rt_tbl_for_cmt");
      if ( (_DWORD)rt_hw_rule )
        rt_hw_rule = printk(&unk_3DEC89, "ipa_prep_rt_tbl_for_cmt");
      v31 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v32 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v32 )
        {
          ipc_log_string(
            v32,
            "ipa %s:%d rt tbl %s is with zero total size\n",
            "ipa_prep_rt_tbl_for_cmt",
            344,
            (const char *)v22 + 40);
          v31 = ipa3_ctx;
        }
        rt_hw_rule = *(_QWORD *)(v31 + 34160);
        if ( rt_hw_rule )
          rt_hw_rule = ipc_log_string(
                         rt_hw_rule,
                         "ipa %s:%d rt tbl %s is with zero total size\n",
                         "ipa_prep_rt_tbl_for_cmt",
                         344,
                         (const char *)v22 + 40);
      }
    }
    v33 = ((__int64 (__fastcall *)(__int64))ipahal_get_hw_tbl_hdr_width)(rt_hw_rule);
    v34 = *v23;
    if ( *v23 )
    {
      v35 = v34 + v33;
      *v23 = v34 + v33;
      v36 = *v26;
      if ( *v26 )
        goto LABEL_31;
    }
    else
    {
      v35 = 0;
      v36 = *v26;
      if ( *v26 )
      {
LABEL_31:
        v37 = v36 + v33;
        *v26 = v36 + v33;
        goto LABEL_34;
      }
    }
    v37 = 0;
LABEL_34:
    v38 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v39 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v39 )
      {
        ipc_log_string(
          v39,
          "ipa %s:%d RT tbl index %u hash_sz %u non-hash sz %u\n",
          "ipa_prep_rt_tbl_for_cmt",
          355,
          *((_DWORD *)v22 + 18),
          v35,
          v37);
        v38 = ipa3_ctx;
      }
      v40 = *(_QWORD *)(v38 + 34160);
      if ( v40 )
        ipc_log_string(
          v40,
          "ipa %s:%d RT tbl index %u hash_sz %u non-hash sz %u\n",
          "ipa_prep_rt_tbl_for_cmt",
          355,
          *((_DWORD *)v22 + 18),
          *((_DWORD *)v22 + 25),
          *((_DWORD *)v22 + 26));
    }
    if ( (v22[12] & 1) == 0 )
    {
      v41 = *v23;
      if ( *v23 )
      {
        LODWORD(v145) = v145 + 1;
        LODWORD(v146) = v41 - v139 + v146;
      }
    }
    if ( (*((_BYTE *)v22 + 97) & 1) == 0 && *v26 )
    {
      ++HIDWORD(v145);
      HIDWORD(v146) += *v26 - v139;
    }
    v22 = (__int64 *)*v22;
  }
  while ( v22 != (__int64 *)v140 );
  LODWORD(v16) = v133;
  v19 = v132;
  v4 = ipa3_ctx;
LABEL_59:
  v49 = 272;
  v50 = *(__int64 **)(v4 + 34176);
  v51 = 84;
  if ( a1 )
    v51 = 128;
  else
    v49 = 256;
  if ( a1 )
    v52 = 264;
  else
    v52 = 248;
  v53 = 116;
  v54 = *v50;
  if ( !a1 )
    v53 = 72;
  v55 = 108;
  if ( !a1 )
    v55 = 64;
  v56 = *(_DWORD *)(v54 + v49);
  v57 = *(_DWORD *)(v54 + v51);
  v58 = *(_DWORD *)(v54 + v52);
  v59 = *(_DWORD *)(v54 + v53);
  v60 = *(_DWORD *)(v54 + v55);
  if ( (unsigned int)ipahal_fltrt_allocate_hw_tbl_imgs(&v144) )
  {
    printk(&unk_3A74FF, "ipa_generate_rt_hw_tbl_img");
    v67 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v68 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v68 )
      {
        ipc_log_string(
          v68,
          "ipa %s:%d fail to allocate RT HW TBL images. IP %d\n",
          "ipa_generate_rt_hw_tbl_img",
          393,
          a1);
        v67 = ipa3_ctx;
      }
      v69 = *(_QWORD *)(v67 + 34160);
      if ( v69 )
        ipc_log_string(
          v69,
          "ipa %s:%d fail to allocate RT HW TBL images. IP %d\n",
          "ipa_generate_rt_hw_tbl_img",
          393,
          a1);
    }
    goto LABEL_108;
  }
  if ( (unsigned int)ipa_translate_rt_tbl_to_hw_fmt(a1, 0, v153, v147, (unsigned int)(v58 - v59), v60) )
  {
    printk(&unk_3B567C, "ipa_generate_rt_hw_tbl_img");
    v70 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v71 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v71 )
      {
        ipc_log_string(
          v71,
          "ipa %s:%d fail to translate hashable rt tbls to hw format\n",
          "ipa_generate_rt_hw_tbl_img",
          401);
        v70 = ipa3_ctx;
      }
      v72 = *(_QWORD *)(v70 + 34160);
      if ( v72 )
        ipc_log_string(
          v72,
          "ipa %s:%d fail to translate hashable rt tbls to hw format\n",
          "ipa_generate_rt_hw_tbl_img",
          401);
    }
    goto LABEL_102;
  }
  if ( (unsigned int)ipa_translate_rt_tbl_to_hw_fmt(a1, 1, v156, v150, (unsigned int)(v56 - v57), v60) )
  {
    printk(&unk_3C14EF, "ipa_generate_rt_hw_tbl_img");
    v73 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v74 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v74 )
      {
        ipc_log_string(
          v74,
          "ipa %s:%d fail to translate non-hashable rt tbls to hw format\n",
          "ipa_generate_rt_hw_tbl_img",
          408);
        v73 = ipa3_ctx;
      }
      v75 = *(_QWORD *)(v73 + 34160);
      if ( v75 )
        ipc_log_string(
          v75,
          "ipa %s:%d fail to translate non-hashable rt tbls to hw format\n",
          "ipa_generate_rt_hw_tbl_img",
          408);
    }
LABEL_102:
    if ( (_DWORD)v149 )
      ipahal_free_dma_mem(&v147);
    ipahal_free_dma_mem(&v150);
    if ( (_DWORD)v155 )
      ipahal_free_dma_mem(&v153);
    if ( (_DWORD)v158 )
      ipahal_free_dma_mem(&v156);
LABEL_108:
    printk(&unk_3DBC88, "__ipa_commit_rt_v3");
    v76 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v77 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v77 )
      {
        ipc_log_string(v77, "ipa %s:%d fail to generate RT HW TBL images. IP %d\n", "__ipa_commit_rt_v3", 558, a1);
        v76 = ipa3_ctx;
      }
      v78 = *(_QWORD *)(v76 + 34160);
      if ( v78 )
        ipc_log_string(v78, "ipa %s:%d fail to generate RT HW TBL images. IP %d\n", "__ipa_commit_rt_v3", 558, a1);
    }
    result = 4294967282LL;
    goto LABEL_120;
  }
  if ( (ipa_rt_valid_lcl_tbl_size(a1, 0, &v153) & 1) == 0 || (ipa_rt_valid_lcl_tbl_size(a1, 1, &v156) & 1) == 0 )
  {
    v64 = -14;
    goto LABEL_78;
  }
  ep_mapping = ipa_get_ep_mapping(95);
  v62 = ipa3_ctx;
  if ( ep_mapping == -1 || (*(_BYTE *)(ipa3_ctx + 51242) & 1) != 0 )
  {
    v63 = 0;
    goto LABEL_124;
  }
  v65 = ipa_get_ep_mapping(95);
  BYTE12(v141) = 0;
  v142 = 0;
  if ( *(_DWORD *)(ipa3_ctx + 32240) > 0x14u )
    ep_reg_offset = ipahal_get_ep_reg_offset(133, v65);
  else
    ep_reg_offset = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(44, 0, 0);
  LODWORD(v141) = ep_reg_offset;
  ipahal_get_aggr_force_close_valmask(v65, &v143);
  *(_QWORD *)((char *)&v141 + 4) = v143;
  v82 = ((__int64 (__fastcall *)(__int64, __int128 *, _QWORD))ipahal_construct_imm_cmd)(7, &v141, 0);
  v165 = v82;
  if ( !v82 )
  {
    printk(&unk_3AEDE8, "__ipa_commit_rt_v3");
    v129 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v130 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v130 )
      {
        ipc_log_string(v130, "ipa %s:%d failed to construct coal close IC\n", "__ipa_commit_rt_v3", 596);
        v129 = ipa3_ctx;
      }
      v131 = *(_QWORD *)(v129 + 34160);
      if ( v131 )
        ipc_log_string(v131, "ipa %s:%d failed to construct coal close IC\n", "__ipa_commit_rt_v3", 596);
    }
    v64 = 0;
    goto LABEL_78;
  }
  ipa3_init_imm_cmd_desc(s, v82);
  v63 = 1;
  v62 = ipa3_ctx;
LABEL_124:
  v83 = v62 + 28672;
  if ( (*(_BYTE *)(v83 + 3598) & 1) != 0 )
  {
LABEL_133:
    HIDWORD(v161) = 0;
    *(_WORD *)((char *)&v161 + 1) = 0;
    v159 = v151;
    v160 = __PAIR64__(v19, v152);
    v87 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v159, 0);
    *(&v165 + v63) = v87;
    if ( !v87 )
    {
      printk(&unk_3DBCBE, "__ipa_commit_rt_v3");
      v114 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v115 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v115 )
        {
          ipc_log_string(
            v115,
            "ipa %s:%d fail construct dma_shared_mem imm cmd. IP %d\n",
            "__ipa_commit_rt_v3",
            656,
            a1);
          v114 = ipa3_ctx;
        }
        v116 = *(_QWORD *)(v114 + 34160);
        if ( v116 )
          ipc_log_string(
            v116,
            "ipa %s:%d fail construct dma_shared_mem imm cmd. IP %d\n",
            "__ipa_commit_rt_v3",
            656,
            a1);
      }
      goto LABEL_203;
    }
    ipa3_init_imm_cmd_desc(&s[13 * v63], v87);
    v88 = v63 + 1;
    if ( (*(_BYTE *)(ipa3_ctx + 32270) & 1) == 0 )
    {
      *(_WORD *)((char *)&v161 + 1) = 0;
      v159 = v148;
      HIDWORD(v161) = 0;
      v160 = __PAIR64__(v136, v149);
      v89 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v159, 0);
      *(&v165 + v88) = v89;
      if ( !v89 )
      {
        printk(&unk_3DBCBE, "__ipa_commit_rt_v3");
        v120 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_236;
        v121 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v121 )
        {
          ipc_log_string(
            v121,
            "ipa %s:%d fail construct dma_shared_mem imm cmd. IP %d\n",
            "__ipa_commit_rt_v3",
            677,
            a1);
          v120 = ipa3_ctx;
        }
        v122 = *(_QWORD *)(v120 + 34160);
        if ( !v122 )
          goto LABEL_236;
        ipc_log_string(v122, "ipa %s:%d fail construct dma_shared_mem imm cmd. IP %d\n", "__ipa_commit_rt_v3", 677, a1);
        goto LABEL_235;
      }
      ipa3_init_imm_cmd_desc(&s[13 * v88], v89);
      v88 = v63 + 2;
    }
    if ( (v138 & 1) == 0 )
      goto LABEL_140;
    *(_WORD *)((char *)&v161 + 1) = 0;
    v159 = v157;
    HIDWORD(v161) = 0;
    LODWORD(v160) = v158;
    HIDWORD(v160) = v135 + v6;
    v90 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v159, 0);
    *(&v165 + v88) = v90;
    if ( v90 )
    {
      ipa3_init_imm_cmd_desc(&s[13 * v88++], v90);
LABEL_140:
      if ( (v137 & 1) == 0 )
      {
LABEL_143:
        if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD *))ipa3_send_cmd)(v88, s) )
        {
          if ( (unsigned int)__ratelimit(&_ipa_commit_rt_v3__rs, "__ipa_commit_rt_v3") )
            printk(&unk_3CB958, "__ipa_commit_rt_v3");
          v92 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v93 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v93 )
            {
              ipc_log_string(v93, "ipa %s:%d fail to send immediate command\n", "__ipa_commit_rt_v3", 734);
              v92 = ipa3_ctx;
            }
            v94 = *(_QWORD *)(v92 + 34160);
            if ( v94 )
              ipc_log_string(v94, "ipa %s:%d fail to send immediate command\n", "__ipa_commit_rt_v3", 734);
          }
          v64 = -14;
          goto LABEL_204;
        }
        v95 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v96 = *(_QWORD *)(ipa3_ctx + 34160);
          if ( !v96
            || (ipc_log_string(v96, "ipa %s:%d Hashable HEAD\n", "__ipa_commit_rt_v3", 739), (v95 = ipa3_ctx) != 0) )
          {
            v97 = *(_QWORD *)(v95 + 34160);
            if ( v97 )
              ipc_log_string(v97, "ipa %s:%d Non-Hashable HEAD\n", "__ipa_commit_rt_v3", 743);
          }
        }
        if ( (_DWORD)v155 )
        {
          if ( ipa3_ctx )
          {
            v98 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v98 )
              ipc_log_string(v98, "ipa %s:%d Hashable BODY\n", "__ipa_commit_rt_v3", 748);
          }
        }
        if ( (_DWORD)v158 )
        {
          if ( ipa3_ctx )
          {
            v99 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v99 )
              ipc_log_string(v99, "ipa %s:%d Non-Hashable BODY\n", "__ipa_commit_rt_v3", 755);
          }
        }
        v100 = ipa3_ctx;
        v101 = ipa3_ctx + 48LL * (unsigned int)v16;
        v102 = *(__int64 **)(v101 + 29184);
        v103 = v101 + 29184;
        if ( v102 != (__int64 *)(v101 + 29184) )
        {
          do
          {
            if ( v102[21] )
            {
              if ( ipa3_ctx )
              {
                v104 = *(_QWORD *)(ipa3_ctx + 34160);
                if ( v104 )
                  ipc_log_string(
                    v104,
                    "ipa %s:%d reaping sys rt tbl name=%s ip=%d rlt=%d\n",
                    "__ipa_reap_sys_rt_tbls",
                    266,
                    (const char *)v102 + 40,
                    a1,
                    0);
              }
              ipahal_free_dma_mem(v102 + 20);
              v102[21] = 0;
              v102[22] = 0;
              v102[20] = 0;
            }
            if ( v102[24] )
            {
              if ( ipa3_ctx )
              {
                v105 = *(_QWORD *)(ipa3_ctx + 34160);
                if ( v105 )
                  ipc_log_string(
                    v105,
                    "ipa %s:%d reaping sys rt tbl name=%s ip=%d rlt=%d\n",
                    "__ipa_reap_sys_rt_tbls",
                    266,
                    (const char *)v102 + 40,
                    a1,
                    1);
              }
              ipahal_free_dma_mem(v102 + 23);
              v102[24] = 0;
              v102[25] = 0;
              v102[23] = 0;
            }
            v102 = (__int64 *)*v102;
          }
          while ( v102 != (__int64 *)v103 );
          v100 = ipa3_ctx;
        }
        v106 = v100 + 48LL * (unsigned int)v16;
        v107 = *(__int64 **)(v106 + 29280);
        v108 = v106 + 29280;
        if ( v107 == (__int64 *)(v106 + 29280) )
        {
LABEL_202:
          v63 = v88;
          goto LABEL_203;
        }
        while ( 1 )
        {
          v109 = (__int64 *)*v107;
          if ( v107[21] )
          {
            __break(0x800u);
            if ( !v107[15] )
              goto LABEL_186;
          }
          else if ( !v107[15] )
          {
            goto LABEL_186;
          }
          if ( ipa3_ctx )
          {
            v110 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v110 )
              ipc_log_string(
                v110,
                "ipa %s:%d reaping sys rt tbl name=%s ip=%d rlt=%d\n",
                "__ipa_reap_sys_rt_tbls",
                281,
                (const char *)v107 + 40,
                a1,
                0);
          }
          ipahal_free_dma_mem(v107 + 14);
LABEL_186:
          if ( v107[24] )
          {
            __break(0x800u);
            if ( v107[18] )
            {
LABEL_188:
              if ( ipa3_ctx )
              {
                v111 = *(_QWORD *)(ipa3_ctx + 34160);
                if ( v111 )
                  ipc_log_string(
                    v111,
                    "ipa %s:%d reaping sys rt tbl name=%s ip=%d rlt=%d\n",
                    "__ipa_reap_sys_rt_tbls",
                    281,
                    (const char *)v107 + 40,
                    a1,
                    1);
              }
              ipahal_free_dma_mem(v107 + 17);
            }
          }
          else if ( v107[18] )
          {
            goto LABEL_188;
          }
          v112 = (__int64 **)v107[1];
          if ( *v112 == v107 && (v113 = (__int64 *)*v107, *(__int64 **)(*v107 + 8) == v107) )
          {
            v113[1] = (__int64)v112;
            *v112 = v113;
          }
          else
          {
            _list_del_entry_valid_or_report(v107);
          }
          *v107 = 0xDEAD000000000100LL;
          v107[1] = 0xDEAD000000000122LL;
          kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29432), v107);
          v107 = v109;
          if ( v109 == (__int64 *)v108 )
            goto LABEL_202;
        }
      }
      *(_WORD *)((char *)&v161 + 1) = 0;
      v159 = v154;
      HIDWORD(v161) = 0;
      LODWORD(v160) = v155;
      HIDWORD(v160) = v134 + v6;
      v91 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v159, 0);
      *(&v165 + v88) = v91;
      if ( v91 )
      {
        ipa3_init_imm_cmd_desc(&s[13 * v88++], v91);
        goto LABEL_143;
      }
      printk(&unk_3FBB45, "__ipa_commit_rt_v3");
      v126 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v127 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v127 )
        {
          ipc_log_string(v127, "ipa %s:%d fail construct dma_shared_mem cmd. IP %d\n", "__ipa_commit_rt_v3", 726, a1);
          v126 = ipa3_ctx;
        }
        v128 = *(_QWORD *)(v126 + 34160);
        if ( v128 )
        {
          ipc_log_string(v128, "ipa %s:%d fail construct dma_shared_mem cmd. IP %d\n", "__ipa_commit_rt_v3", 726, a1);
          goto LABEL_235;
        }
      }
LABEL_236:
      v64 = 0;
      goto LABEL_204;
    }
    printk(&unk_3FBB45, "__ipa_commit_rt_v3");
    v123 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_236;
    v124 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v124 )
    {
      ipc_log_string(v124, "ipa %s:%d fail construct dma_shared_mem cmd. IP %d\n", "__ipa_commit_rt_v3", 702, a1);
      v123 = ipa3_ctx;
    }
    v125 = *(_QWORD *)(v123 + 34160);
    if ( !v125 )
      goto LABEL_236;
    ipc_log_string(v125, "ipa %s:%d fail construct dma_shared_mem cmd. IP %d\n", "__ipa_commit_rt_v3", 702, a1);
LABEL_235:
    v64 = 0;
    goto LABEL_204;
  }
  if ( *(_DWORD *)(v83 + 3568) < 0x15u )
  {
    v164 = 0;
    if ( a1 )
      LOBYTE(v164) = 1;
    else
      BYTE2(v164) = 1;
    ipahal_get_fltrt_hash_flush_valmask(&v164, &v143);
    v84 = 67;
  }
  else
  {
    LOWORD(v164) = 1;
    ipahal_get_fltrt_cache_flush_valmask(&v164, &v143);
    v84 = 140;
  }
  v85 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(v84, 0, 0);
  BYTE12(v162) = 0;
  v163 = 0;
  LODWORD(v162) = v85;
  *(_QWORD *)((char *)&v162 + 4) = v143;
  v86 = ((__int64 (__fastcall *)(__int64, __int128 *, _QWORD))ipahal_construct_imm_cmd)(7, &v162, 0);
  *(&v165 + v63) = v86;
  if ( v86 )
  {
    ipa3_init_imm_cmd_desc(&s[13 * v63++], v86);
    goto LABEL_133;
  }
  printk(&unk_3C475F, "__ipa_commit_rt_v3");
  v117 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v118 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v118 )
    {
      ipc_log_string(v118, "ipa %s:%d fail construct register_write imm cmd. IP %d\n", "__ipa_commit_rt_v3", 640, a1);
      v117 = ipa3_ctx;
    }
    v119 = *(_QWORD *)(v117 + 34160);
    if ( v119 )
      ipc_log_string(v119, "ipa %s:%d fail construct register_write imm cmd. IP %d\n", "__ipa_commit_rt_v3", 640, a1);
  }
LABEL_203:
  v64 = 0;
  v88 = v63;
  if ( (int)v63 >= 1 )
  {
LABEL_204:
    kfree(v165);
    if ( v88 != 1 )
    {
      kfree(v166);
      if ( v88 != 2 )
      {
        kfree(v167);
        if ( v88 != 3 )
        {
          kfree(v168);
          if ( v88 != 4 )
          {
            kfree(v169);
            if ( v88 != 5 )
              kfree(v170);
          }
        }
      }
    }
  }
LABEL_78:
  if ( (_DWORD)v149 )
    ipahal_free_dma_mem(&v147);
  ipahal_free_dma_mem(&v150);
  if ( (_DWORD)v155 )
    ipahal_free_dma_mem(&v153);
  if ( (_DWORD)v158 )
    ipahal_free_dma_mem(&v156);
  result = v64;
LABEL_120:
  _ReadStatusReg(SP_EL0);
  return result;
}
