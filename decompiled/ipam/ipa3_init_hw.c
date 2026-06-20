__int64 ipa3_init_hw()
{
  int reg_n; // w19
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x8
  int v6; // w4
  __int64 result; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x8
  unsigned __int64 v12; // x19
  __int64 v13; // x0
  unsigned __int16 *v15; // x8
  int v16; // w9
  int v17; // w10
  unsigned int v18; // w11
  unsigned int v19; // w8
  __int64 v20; // x8
  unsigned int v21; // w9
  int v22; // w0
  __int64 v23; // x8
  int v24; // w19
  __int64 v25; // x0
  __int64 v26; // x0
  int v27; // w0
  __int64 v28; // x8
  int v29; // w19
  __int64 v30; // x0
  __int64 v31; // x0
  unsigned int v32; // w8
  int v33; // w8
  int v34; // w0
  __int64 v35; // x8
  int v36; // w19
  __int64 v37; // x0
  __int64 v38; // x0
  int v39; // w0
  __int64 v40; // x8
  int v41; // w19
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  const char *v51; // x4
  __int64 v52; // x0
  const char *v53; // x4
  __int64 v54; // x8
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x8
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x0
  __int64 v78; // x0
  __int64 v79; // x0
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v82; // x0
  __int64 v83; // x0
  __int64 v84; // x8
  __int64 v85; // x0
  __int64 v86; // x0
  __int64 v87; // x0
  __int64 v88; // x0
  __int64 v89; // x0
  __int64 v90; // x0
  __int64 v91; // x0
  __int64 v92; // x0
  __int64 v93; // x0
  __int64 v94; // x0
  __int64 v95; // x8
  __int64 v96; // x0
  __int64 v97; // x0
  __int64 v103; // [xsp+8h] [xbp-58h] BYREF
  __int128 v104; // [xsp+10h] [xbp-50h]
  __int64 v105; // [xsp+20h] [xbp-40h]
  unsigned __int64 v106; // [xsp+28h] [xbp-38h] BYREF
  __int64 v107; // [xsp+30h] [xbp-30h]
  _QWORD v108[2]; // [xsp+38h] [xbp-28h]
  __int16 v109; // [xsp+48h] [xbp-18h] BYREF
  char v110; // [xsp+4Ah] [xbp-16h]
  int v111; // [xsp+4Ch] [xbp-14h] BYREF
  _QWORD v112[2]; // [xsp+50h] [xbp-10h] BYREF

  v112[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v111 = 0;
  v110 = 0;
  v109 = 0;
  reg_n = ipahal_read_reg_n(12, 0);
  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d IPA_VERSION=%u\n", "ipa3_init_hw", 8221, reg_n);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(v4, "ipa %s:%d IPA_VERSION=%u\n", "ipa3_init_hw", 8221, reg_n);
  }
  if ( !reg_n )
  {
    result = 4294967282LL;
    goto LABEL_185;
  }
  v5 = ipa3_ctx;
  v6 = *(_DWORD *)(ipa3_ctx + 32240);
  if ( v6 > 13 )
  {
    if ( (unsigned int)(v6 - 14) < 2 )
    {
      ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))ipahal_write_reg_mn)(10, 0, 0, 57);
      goto LABEL_22;
    }
    if ( v6 == 16 )
    {
      ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))ipahal_write_reg_mn)(10, 0, 0, 0);
      goto LABEL_22;
    }
  }
  else
  {
    if ( (unsigned int)(v6 - 10) < 2 )
    {
      ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))ipahal_write_reg_mn)(10, 0, 0, 1);
      goto LABEL_22;
    }
    if ( (unsigned int)(v6 - 12) < 2 )
    {
      ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64))ipahal_write_reg_mn)(10, 0, 0, 59);
      goto LABEL_22;
    }
  }
  if ( ipa3_ctx )
  {
    v8 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d Do not update BCR - hw_type=%d\n", "ipa3_init_hw", 8243, v6);
      v5 = ipa3_ctx;
    }
    v9 = v5 + 32240;
    v10 = *(_QWORD *)(v9 + 1920);
    if ( v10 )
      ipc_log_string(v10, "ipa %s:%d Do not update BCR - hw_type=%d\n", "ipa3_init_hw", 8243, *(_DWORD *)v9);
  }
LABEL_22:
  v11 = ipa3_ctx;
  if ( (unsigned int)(*(_DWORD *)(ipa3_ctx + 32240) - 14) <= 2 )
  {
    v105 = 0;
    v103 = 0;
    v104 = 0u;
    v106 = 65792;
    v107 = 0;
    v108[0] = 0;
    *(_QWORD *)((char *)v108 + 7) = 0;
    ((void (__fastcall *)(__int64, _QWORD, unsigned __int64 *))ipahal_write_reg_n_fields)(99, 0, &v106);
    ipahal_read_reg_n_fields(93, 0, &v103);
    LODWORD(v105) = 0;
    ((void (__fastcall *)(__int64, _QWORD, __int64 *))ipahal_write_reg_n_fields)(93, 0, &v103);
    v11 = ipa3_ctx;
  }
  v12 = *(unsigned __int8 *)(v11 + 32244);
  v103 = 0;
  *(_QWORD *)&v104 = 0;
  v106 = 0;
  ipahal_read_reg_n_fields(91, 0, &v106);
  v13 = ipahal_read_reg_n_fields(92, 0, &v103);
  if ( v12 >= 0x18 )
  {
    __break(0x5512u);
  }
  else
  {
    v15 = (unsigned __int16 *)&ipa3_qmb_outstanding[6 * v12];
    LODWORD(v103) = *v15;
    if ( ((4 * ((3 * v12) & 0x3FF)) | 2) <= 0x120 )
    {
      v16 = v15[2];
      v17 = v15[3];
      v18 = v15[1];
      v19 = v15[4];
      HIDWORD(v103) = v17;
      LODWORD(v104) = v16;
      v106 = __PAIR64__(v19, v18);
      ((void (__fastcall *)(__int64, _QWORD, unsigned __int64 *))ipahal_write_reg_n_fields)(91, 0, &v106);
      ((void (__fastcall *)(__int64, _QWORD, __int64 *))ipahal_write_reg_n_fields)(92, 0, &v103);
      v20 = ipa3_ctx;
      v21 = *(_DWORD *)(ipa3_ctx + 32240);
      if ( v21 >= 0xC )
      {
        if ( v21 > 0x10 )
        {
          v112[0] = 0;
          v103 = 0x10000000ELL;
          *(_QWORD *)&v104 = 0x180000000ELL;
          v22 = ipahal_read_reg_n(100, 0);
          v23 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v24 = v22;
            v25 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v25 )
            {
              ipc_log_string(v25, "ipa %s:%d qtime timestamp before cfg: 0x%x\n", "ipa_cfg_qtime", 8152, v24);
              v23 = ipa3_ctx;
            }
            v26 = *(_QWORD *)(v23 + 34160);
            if ( v26 )
              ipc_log_string(v26, "ipa %s:%d qtime timestamp before cfg: 0x%x\n", "ipa_cfg_qtime", 8152, v24);
          }
          ((void (__fastcall *)(__int64, _QWORD, __int64 *))ipahal_write_reg_n_fields)(100, 0, &v103);
          v27 = ipahal_read_reg_n(100, 0);
          v28 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v29 = v27;
            v30 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v30 )
            {
              ipc_log_string(v30, "ipa %s:%d qtime timestamp after cfg: 0x%x\n", "ipa_cfg_qtime", 8155, v29);
              v28 = ipa3_ctx;
            }
            v31 = *(_QWORD *)(v28 + 34160);
            if ( v31 )
            {
              ipc_log_string(v31, "ipa %s:%d qtime timestamp after cfg: 0x%x\n", "ipa_cfg_qtime", 8155, v29);
              v28 = ipa3_ctx;
            }
          }
          v32 = *(_DWORD *)(v28 + 32240);
          v106 = 0x400000003LL;
          if ( v32 < 0x15 )
            v33 = 4;
          else
            v33 = 5;
          LODWORD(v107) = v33;
          HIDWORD(v107) = v33;
          v34 = ipahal_read_reg_n(101, 0);
          v35 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v36 = v34;
            v37 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v37 )
            {
              ipc_log_string(v37, "ipa %s:%d timer pulse granularity before cfg: 0x%x\n", "ipa_cfg_qtime", 8174, v36);
              v35 = ipa3_ctx;
            }
            v38 = *(_QWORD *)(v35 + 34160);
            if ( v38 )
              ipc_log_string(v38, "ipa %s:%d timer pulse granularity before cfg: 0x%x\n", "ipa_cfg_qtime", 8174, v36);
          }
          ((void (__fastcall *)(__int64, _QWORD, unsigned __int64 *))ipahal_write_reg_n_fields)(101, 0, &v106);
          v39 = ipahal_read_reg_n(101, 0);
          v40 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v41 = v39;
            v42 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v42 )
            {
              ipc_log_string(v42, "ipa %s:%d timer pulse granularity after cfg: 0x%x\n", "ipa_cfg_qtime", 8177, v41);
              v40 = ipa3_ctx;
            }
            v43 = *(_QWORD *)(v40 + 34160);
            if ( v43 )
              ipc_log_string(v43, "ipa %s:%d timer pulse granularity after cfg: 0x%x\n", "ipa_cfg_qtime", 8177, v41);
          }
          v112[0] = 0;
          ipahal_read_reg_n_fields(102, 0, v112);
          v44 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v45 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v45 )
            {
              ipc_log_string(
                v45,
                "ipa %s:%d timer XO clk divider before cfg: enabled=%d divider=%u\n",
                "ipa_cfg_qtime",
                8183,
                LOBYTE(v112[0]),
                HIDWORD(v112[0]));
              v44 = ipa3_ctx;
            }
            v46 = *(_QWORD *)(v44 + 34160);
            if ( v46 )
              ipc_log_string(
                v46,
                "ipa %s:%d timer XO clk divider before cfg: enabled=%d divider=%u\n",
                "ipa_cfg_qtime",
                8183,
                LOBYTE(v112[0]),
                HIDWORD(v112[0]));
          }
          if ( LOBYTE(v112[0]) == 1 )
          {
            LOBYTE(v112[0]) = 0;
            ((void (__fastcall *)(__int64, _QWORD, _QWORD *))ipahal_write_reg_n_fields)(102, 0, v112);
          }
          if ( (*(_DWORD *)(ipa3_ctx + 32248) | 2) == 3 )
            HIDWORD(v112[0]) = 0;
          LOBYTE(v112[0]) = 1;
          ((void (__fastcall *)(__int64, _QWORD, _QWORD *))ipahal_write_reg_n_fields)(102, 0, v112);
          ipahal_read_reg_n_fields(102, 0, v112);
          v47 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v48 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v48 )
            {
              ipc_log_string(
                v48,
                "ipa %s:%d timer XO clk divider after cfg: enabled=%d divider=%u\n",
                "ipa_cfg_qtime",
                8204,
                LOBYTE(v112[0]),
                HIDWORD(v112[0]));
              v47 = ipa3_ctx;
            }
            v49 = *(_QWORD *)(v47 + 34160);
            if ( v49 )
              ipc_log_string(
                v49,
                "ipa %s:%d timer XO clk divider after cfg: enabled=%d divider=%u\n",
                "ipa_cfg_qtime",
                8204,
                LOBYTE(v112[0]),
                HIDWORD(v112[0]));
          }
        }
        else
        {
          v111 = 15;
          ((void (__fastcall *)(__int64, _QWORD, int *))ipahal_write_reg_n_fields)(30, 0, &v111);
        }
        v20 = ipa3_ctx;
      }
      if ( v20 && *(_BYTE *)(v20 + 51097) == 1 )
      {
        ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))ipahal_write_reg_mn)(
          149,
          0,
          0,
          *(unsigned __int16 *)(v20 + 51098));
        ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))ipahal_write_reg_mn)(
          150,
          0,
          0,
          *(unsigned __int16 *)(ipa3_ctx + 51100));
        v20 = ipa3_ctx;
      }
      if ( *(_DWORD *)(v20 + 32240) >= 0x18u )
      {
        v110 = 0;
        v109 = 0;
        ipahal_read_reg_n_fields(163, 0, &v109);
        LOBYTE(v109) = *(_BYTE *)(ipa3_ctx + 51404);
        ((void (__fastcall *)(__int64, _QWORD, __int16 *))ipahal_write_reg_n_fields)(163, 0, &v109);
        v20 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v50 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v50 )
          {
            if ( (_BYTE)v109 )
              v51 = "True";
            else
              v51 = "False";
            ipc_log_string(v50, "ipa %s:%d : coal-ipv4-id-ignore = %s\n", "ipa3_init_hw", 8295, v51);
            v20 = ipa3_ctx;
          }
          v52 = *(_QWORD *)(v20 + 34160);
          if ( v52 )
          {
            if ( (_BYTE)v109 )
              v53 = "True";
            else
              v53 = "False";
            ipc_log_string(v52, "ipa %s:%d : coal-ipv4-id-ignore = %s\n", "ipa3_init_hw", 8295, v53);
            v20 = ipa3_ctx;
          }
        }
      }
      LOBYTE(v105) = 0;
      v104 = 0u;
      v103 = 0;
      if ( *(_DWORD *)(v20 + 32240) == 14 && (*(_BYTE *)(v20 + 32260) & 1) == 0 )
      {
        ipahal_read_reg_n_fields(16, 0, &v103);
        v54 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v55 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v55 )
          {
            ipc_log_string(v55, "ipa %s:%d Before comp config\n", "ipa_comp_cfg", 8033);
            v54 = ipa3_ctx;
          }
          v56 = *(_QWORD *)(v54 + 34160);
          if ( v56 )
          {
            ipc_log_string(v56, "ipa %s:%d Before comp config\n", "ipa_comp_cfg", 8033);
            v54 = ipa3_ctx;
          }
          if ( v54 )
          {
            v57 = *(_QWORD *)(v54 + 34152);
            if ( v57 )
            {
              ipc_log_string(
                v57,
                "ipa %s:%d ipa_qmb_select_by_address_global_en = %d\n",
                "ipa_comp_cfg",
                8035,
                HIBYTE(v103));
              v54 = ipa3_ctx;
            }
            v58 = *(_QWORD *)(v54 + 34160);
            if ( v58 )
            {
              ipc_log_string(
                v58,
                "ipa %s:%d ipa_qmb_select_by_address_global_en = %d\n",
                "ipa_comp_cfg",
                8035,
                HIBYTE(v103));
              v54 = ipa3_ctx;
            }
            if ( v54 )
            {
              v59 = *(_QWORD *)(v54 + 34152);
              if ( v59 )
              {
                ipc_log_string(
                  v59,
                  "ipa %s:%d ipa_qmb_select_by_address_prod_en = %d\n",
                  "ipa_comp_cfg",
                  8038,
                  BYTE9(v104));
                v54 = ipa3_ctx;
              }
              v60 = *(_QWORD *)(v54 + 34160);
              if ( v60 )
              {
                ipc_log_string(
                  v60,
                  "ipa %s:%d ipa_qmb_select_by_address_prod_en = %d\n",
                  "ipa_comp_cfg",
                  8038,
                  BYTE9(v104));
                v54 = ipa3_ctx;
              }
              if ( v54 )
              {
                v61 = *(_QWORD *)(v54 + 34152);
                if ( v61 )
                {
                  ipc_log_string(
                    v61,
                    "ipa %s:%d ipa_qmb_select_by_address_cons_en = %d\n",
                    "ipa_comp_cfg",
                    8041,
                    BYTE10(v104));
                  v54 = ipa3_ctx;
                }
                v62 = *(_QWORD *)(v54 + 34160);
                if ( v62 )
                  ipc_log_string(
                    v62,
                    "ipa %s:%d ipa_qmb_select_by_address_cons_en = %d\n",
                    "ipa_comp_cfg",
                    8041,
                    BYTE10(v104));
              }
            }
          }
        }
        HIBYTE(v103) = 0;
        *(_WORD *)((char *)&v104 + 9) = 0;
        ((void (__fastcall *)(__int64, _QWORD, __int64 *))ipahal_write_reg_n_fields)(16, 0, &v103);
        ipahal_read_reg_n_fields(16, 0, &v103);
        v20 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v63 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v63 )
          {
            ipc_log_string(v63, "ipa %s:%d After comp config\n", "ipa_comp_cfg", 8050);
            v20 = ipa3_ctx;
          }
          v64 = *(_QWORD *)(v20 + 34160);
          if ( v64 )
          {
            ipc_log_string(v64, "ipa %s:%d After comp config\n", "ipa_comp_cfg", 8050);
            v20 = ipa3_ctx;
          }
          if ( v20 )
          {
            v65 = *(_QWORD *)(v20 + 34152);
            if ( v65 )
            {
              ipc_log_string(
                v65,
                "ipa %s:%d ipa_qmb_select_by_address_global_en = %d\n",
                "ipa_comp_cfg",
                8052,
                HIBYTE(v103));
              v20 = ipa3_ctx;
            }
            v66 = *(_QWORD *)(v20 + 34160);
            if ( v66 )
            {
              ipc_log_string(
                v66,
                "ipa %s:%d ipa_qmb_select_by_address_global_en = %d\n",
                "ipa_comp_cfg",
                8052,
                HIBYTE(v103));
              v20 = ipa3_ctx;
            }
            if ( v20 )
            {
              v67 = *(_QWORD *)(v20 + 34152);
              if ( v67 )
              {
                ipc_log_string(
                  v67,
                  "ipa %s:%d ipa_qmb_select_by_address_prod_en = %d\n",
                  "ipa_comp_cfg",
                  8055,
                  BYTE9(v104));
                v20 = ipa3_ctx;
              }
              v68 = *(_QWORD *)(v20 + 34160);
              if ( v68 )
              {
                ipc_log_string(
                  v68,
                  "ipa %s:%d ipa_qmb_select_by_address_prod_en = %d\n",
                  "ipa_comp_cfg",
                  8055,
                  BYTE9(v104));
                v20 = ipa3_ctx;
              }
              if ( v20 )
              {
                v69 = *(_QWORD *)(v20 + 34152);
                if ( v69 )
                {
                  ipc_log_string(
                    v69,
                    "ipa %s:%d ipa_qmb_select_by_address_cons_en = %d\n",
                    "ipa_comp_cfg",
                    8058,
                    BYTE10(v104));
                  v20 = ipa3_ctx;
                }
                v70 = *(_QWORD *)(v20 + 34160);
                if ( v70 )
                {
                  ipc_log_string(
                    v70,
                    "ipa %s:%d ipa_qmb_select_by_address_cons_en = %d\n",
                    "ipa_comp_cfg",
                    8058,
                    BYTE10(v104));
                  v20 = ipa3_ctx;
                }
              }
            }
          }
        }
      }
      if ( *(_DWORD *)(v20 + 32240) >= 0xEu )
      {
        ipahal_read_reg_n_fields(16, 0, &v103);
        v71 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v72 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v72 )
          {
            ipc_log_string(v72, "ipa %s:%d Before comp config\n", "ipa_comp_cfg", 8063);
            v71 = ipa3_ctx;
          }
          v73 = *(_QWORD *)(v71 + 34160);
          if ( v73 )
          {
            ipc_log_string(v73, "ipa %s:%d Before comp config\n", "ipa_comp_cfg", 8063);
            v71 = ipa3_ctx;
          }
          if ( v71 )
          {
            v74 = *(_QWORD *)(v71 + 34152);
            if ( v74 )
            {
              ipc_log_string(v74, "ipa %s:%d gsi_multi_inorder_rd_dis = %d\n", "ipa_comp_cfg", 8065, BYTE8(v104));
              v71 = ipa3_ctx;
            }
            v75 = *(_QWORD *)(v71 + 34160);
            if ( v75 )
            {
              ipc_log_string(v75, "ipa %s:%d gsi_multi_inorder_rd_dis = %d\n", "ipa_comp_cfg", 8065, BYTE8(v104));
              v71 = ipa3_ctx;
            }
            if ( v71 )
            {
              v76 = *(_QWORD *)(v71 + 34152);
              if ( v76 )
              {
                ipc_log_string(v76, "ipa %s:%d gsi_multi_inorder_wr_dis = %d\n", "ipa_comp_cfg", 8068, BYTE7(v104));
                v71 = ipa3_ctx;
              }
              v77 = *(_QWORD *)(v71 + 34160);
              if ( v77 )
                ipc_log_string(v77, "ipa %s:%d gsi_multi_inorder_wr_dis = %d\n", "ipa_comp_cfg", 8068, BYTE7(v104));
            }
          }
        }
        *(_WORD *)((char *)&v104 + 7) = 257;
        ((void (__fastcall *)(__int64, _QWORD, __int64 *))ipahal_write_reg_n_fields)(16, 0, &v103);
        ipahal_read_reg_n_fields(16, 0, &v103);
        v20 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v78 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v78 )
          {
            ipc_log_string(v78, "ipa %s:%d After comp config\n", "ipa_comp_cfg", 8076);
            v20 = ipa3_ctx;
          }
          v79 = *(_QWORD *)(v20 + 34160);
          if ( v79 )
          {
            ipc_log_string(v79, "ipa %s:%d After comp config\n", "ipa_comp_cfg", 8076);
            v20 = ipa3_ctx;
          }
          if ( v20 )
          {
            v80 = *(_QWORD *)(v20 + 34152);
            if ( v80 )
            {
              ipc_log_string(v80, "ipa %s:%d gsi_multi_inorder_rd_dis = %d\n", "ipa_comp_cfg", 8078, BYTE8(v104));
              v20 = ipa3_ctx;
            }
            v81 = *(_QWORD *)(v20 + 34160);
            if ( v81 )
            {
              ipc_log_string(v81, "ipa %s:%d gsi_multi_inorder_rd_dis = %d\n", "ipa_comp_cfg", 8078, BYTE8(v104));
              v20 = ipa3_ctx;
            }
            if ( v20 )
            {
              v82 = *(_QWORD *)(v20 + 34152);
              if ( v82 )
              {
                ipc_log_string(v82, "ipa %s:%d gsi_multi_inorder_wr_dis = %d\n", "ipa_comp_cfg", 8081, BYTE7(v104));
                v20 = ipa3_ctx;
              }
              v83 = *(_QWORD *)(v20 + 34160);
              if ( v83 )
              {
                ipc_log_string(v83, "ipa %s:%d gsi_multi_inorder_wr_dis = %d\n", "ipa_comp_cfg", 8081, BYTE7(v104));
                v20 = ipa3_ctx;
              }
            }
          }
        }
      }
      if ( (unsigned int)(*(_DWORD *)(v20 + 32240) - 15) <= 1 )
      {
        ipahal_read_reg_n_fields(16, 0, &v103);
        v84 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v85 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v85 )
          {
            ipc_log_string(v85, "ipa %s:%d Before comp config\n", "ipa_comp_cfg", 8088);
            v84 = ipa3_ctx;
          }
          v86 = *(_QWORD *)(v84 + 34160);
          if ( v86 )
          {
            ipc_log_string(v86, "ipa %s:%d Before comp config\n", "ipa_comp_cfg", 8088);
            v84 = ipa3_ctx;
          }
          if ( v84 )
          {
            v87 = *(_QWORD *)(v84 + 34152);
            if ( v87 )
            {
              ipc_log_string(
                v87,
                "ipa %s:%d gsi_multi_axi_masters_dis = %d\n",
                "ipa_comp_cfg",
                8090,
                (unsigned __int8)v104);
              v84 = ipa3_ctx;
            }
            v88 = *(_QWORD *)(v84 + 34160);
            if ( v88 )
              ipc_log_string(
                v88,
                "ipa %s:%d gsi_multi_axi_masters_dis = %d\n",
                "ipa_comp_cfg",
                8090,
                (unsigned __int8)v104);
          }
        }
        LOBYTE(v104) = 1;
        ((void (__fastcall *)(__int64, _QWORD, __int64 *))ipahal_write_reg_n_fields)(16, 0, &v103);
        ipahal_read_reg_n_fields(16, 0, &v103);
        v20 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v89 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v89 )
          {
            ipc_log_string(v89, "ipa %s:%d After comp config\n", "ipa_comp_cfg", 8097);
            v20 = ipa3_ctx;
          }
          v90 = *(_QWORD *)(v20 + 34160);
          if ( v90 )
          {
            ipc_log_string(v90, "ipa %s:%d After comp config\n", "ipa_comp_cfg", 8097);
            v20 = ipa3_ctx;
          }
          if ( v20 )
          {
            v91 = *(_QWORD *)(v20 + 34152);
            if ( v91 )
            {
              ipc_log_string(
                v91,
                "ipa %s:%d gsi_multi_axi_masters_dis = %d\n",
                "ipa_comp_cfg",
                8099,
                (unsigned __int8)v104);
              v20 = ipa3_ctx;
            }
            v92 = *(_QWORD *)(v20 + 34160);
            if ( v92 )
            {
              ipc_log_string(
                v92,
                "ipa %s:%d gsi_multi_axi_masters_dis = %d\n",
                "ipa_comp_cfg",
                8099,
                (unsigned __int8)v104);
              v20 = ipa3_ctx;
            }
          }
        }
      }
      if ( *(_BYTE *)(v20 + 32270) == 1 )
      {
        if ( *(_DWORD *)(v20 + 32240) >= 0x15u )
        {
          printk(&unk_3C7EEA, "ipa_disable_hashing_rt_flt_v4_2");
          v95 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v96 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v96 )
            {
              ipc_log_string(v96, "ipa %s:%d reg deprecated\n", "ipa_disable_hashing_rt_flt_v4_2", 8008);
              v95 = ipa3_ctx;
            }
            v97 = *(_QWORD *)(v95 + 34160);
            if ( v97 )
              ipc_log_string(v97, "ipa %s:%d reg deprecated\n", "ipa_disable_hashing_rt_flt_v4_2", 8008);
          }
          result = 0;
          __break(0x800u);
          goto LABEL_185;
        }
        if ( v20 )
        {
          v93 = *(_QWORD *)(v20 + 34152);
          if ( v93 )
          {
            ipc_log_string(
              v93,
              "ipa %s:%d Disable hashing for filter and route table in IPA 4.2 HW\n",
              "ipa_disable_hashing_rt_flt_v4_2",
              8012);
            v20 = ipa3_ctx;
          }
          v94 = *(_QWORD *)(v20 + 34160);
          if ( v94 )
            ipc_log_string(
              v94,
              "ipa %s:%d Disable hashing for filter and route table in IPA 4.2 HW\n",
              "ipa_disable_hashing_rt_flt_v4_2",
              8012);
        }
        ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))ipahal_write_reg_mn)(68, 0, 0, 0);
      }
      result = 0;
LABEL_185:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  __break(1u);
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return ipa3_is_ulso_supported(v13);
}
