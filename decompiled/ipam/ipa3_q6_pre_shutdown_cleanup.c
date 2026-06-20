__int64 ipa3_q6_pre_shutdown_cleanup()
{
  unsigned __int64 v0; // x19
  __int64 *v1; // x20
  __int64 v2; // x0
  __int64 ep_mapping; // x0
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  int v12; // w0
  __int64 v13; // x8
  unsigned int v14; // w21
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  unsigned int v18; // w21
  unsigned int v19; // w8
  int ep_reg_offset; // w0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  int v44; // w0
  __int64 v45; // x0
  __int64 v46; // x8
  unsigned int v47; // w21
  __int64 v48; // x0
  __int64 v49; // x0
  int v50; // w0
  int v51; // w22
  __int64 v52; // x8
  __int64 v53; // x0
  __int64 v54; // x0
  int v55; // w22
  __int64 v56; // x8
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x8
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x8
  __int64 v63; // x0
  __int64 v64; // x0
  int v65; // w21
  __int64 v66; // x1
  __int64 v67; // x8
  __int64 v68; // x0
  __int64 v69; // x0
  unsigned int v70; // w21
  unsigned int v71; // w8
  int v72; // w0
  __int64 v73; // x0
  __int64 v74; // x21
  unsigned int i; // w22
  unsigned int v76; // w0
  unsigned int v77; // w23
  __int64 v78; // x1
  __int64 v79; // x8
  __int64 v80; // x10
  unsigned int v81; // w9
  __int64 v82; // x10
  int v83; // t1
  __int64 v84; // x0
  __int64 *v85; // x24
  __int64 v86; // x23
  __int64 v87; // x25
  int v88; // w0
  __int64 v89; // x1
  __int64 v90; // x0
  __int64 result; // x0
  unsigned int v92; // w19
  unsigned int v93; // w0
  int v94; // w22
  __int64 v95; // x8
  __int64 v96; // x0
  __int64 v97; // x0
  unsigned __int64 v98; // x22
  __int64 v99; // x21
  __int64 v100; // x0
  __int64 v101; // x1
  void (__fastcall *v102)(__int64, __int64); // x8
  __int64 v103; // x1
  __int64 v104; // x8
  __int64 v105; // x0
  __int64 v106; // x0
  __int64 v107; // x1
  __int64 v108; // x8
  __int64 v109; // x0
  __int64 v110; // x0
  __int64 v111; // x1
  __int64 v112; // x8
  __int64 v113; // x0
  __int64 v114; // x0
  __int64 v115; // x9
  unsigned __int64 StatusReg; // x21
  __int64 v117; // x22
  int v118; // [xsp+Ch] [xbp-44h] BYREF
  __int128 v119; // [xsp+10h] [xbp-40h] BYREF
  int v120; // [xsp+20h] [xbp-30h]
  __int64 v121; // [xsp+28h] [xbp-28h] BYREF
  __int128 v122; // [xsp+30h] [xbp-20h] BYREF
  int v123; // [xsp+40h] [xbp-10h]
  __int64 v124; // [xsp+48h] [xbp-8h]

  v124 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( ipa3_ctx )
  {
    v2 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v2 )
      ipc_log_string(v2, "ipa %s:%d ENTER\n", "ipa3_q6_pre_shutdown_cleanup", 5450);
  }
  ep_mapping = ipa3_inc_client_enable_clks_no_log();
  v4 = ipa3_ctx;
  *(_DWORD *)(ipa3_ctx + 45216) = 1;
  if ( *(_BYTE *)(v4 + 50153) == 1 )
  {
    ep_mapping = ipa3_q6_pipe_flow_control(1);
  }
  else if ( (*(_BYTE *)(v4 + 32268) & 1) == 0 )
  {
    LODWORD(v0) = 0;
    v1 = (_QWORD *)&unk_FB;
    LOWORD(v122) = 256;
    do
    {
      if ( (_DWORD)v0 == 84
        || (_DWORD)v0 == 114
        || (_DWORD)v0 == 74
        || (_DWORD)v0 == 122
        || (v0 & 0xFD) == 0x38
        || (_DWORD)v0 == 52
        || (v0 & 0xFB) == 0x32 )
      {
        ep_mapping = ipa_get_ep_mapping((unsigned int)v0);
        if ( (_DWORD)ep_mapping != -1 )
          ep_mapping = ((__int64 (__fastcall *)(__int64, _QWORD, __int128 *))ipahal_write_reg_n_fields)(
                         49,
                         (unsigned int)ep_mapping,
                         &v122);
      }
      v0 = (unsigned int)(v0 + 1);
    }
    while ( (_DWORD)v0 != 134 );
  }
  ipa3_q6_avoid_holb(ep_mapping);
  v5 = ipa3_ctx;
  if ( *(_BYTE *)(ipa3_ctx + 32260) == 1 )
  {
    ipa3_set_reset_client_cons_pipe_sus_holb(1, 43);
    v5 = ipa3_ctx;
    if ( *(_BYTE *)(ipa3_ctx + 32264) == 1 )
    {
      ipa3_set_reset_client_cons_pipe_sus_holb(1, 113);
      v5 = ipa3_ctx;
    }
  }
  if ( *(_BYTE *)(v5 + 32267) == 1 )
  {
    LODWORD(v122) = 0;
    LOWORD(v119) = 0;
    v6 = ipa_wdi_opt_dpath_remove_all_filter_req(&v119, &v122);
    ipa_wdi_opt_dpath_remove_all_ctrl_filter_req(v6);
    v5 = ipa3_ctx;
  }
  v123 = 0;
  v122 = 0u;
  v121 = 0;
  v120 = 0;
  v119 = 0u;
  if ( v5 )
  {
    v7 = *(_QWORD *)(v5 + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d Entry\n", "ipa3_q6_clean_q6_tables", 5182);
      v5 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v5 + 34160);
    if ( v8 )
      ipc_log_string(v8, "ipa %s:%d Entry\n", "ipa3_q6_clean_q6_tables", 5182);
  }
  if ( (unsigned int)ipa3_q6_clean_q6_flt_tbls(0, 0) )
  {
    printk(&unk_3DDB26, "ipa3_q6_clean_q6_tables");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d failed to clean q6 flt tbls (v4/hashable)\n", "ipa3_q6_clean_q6_tables", 5186);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
        ipc_log_string(v17, "ipa %s:%d failed to clean q6 flt tbls (v4/hashable)\n", "ipa3_q6_clean_q6_tables", 5186);
    }
  }
  else
  {
    v9 = ipa3_q6_clean_q6_flt_tbls(1, 0);
    if ( (_DWORD)v9 )
    {
      printk(&unk_3AEEDB, "ipa3_q6_clean_q6_tables");
      v21 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v22 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v22 )
        {
          ipc_log_string(v22, "ipa %s:%d failed to clean q6 flt tbls (v6/hashable)\n", "ipa3_q6_clean_q6_tables", 5190);
          v21 = ipa3_ctx;
        }
        v23 = *(_QWORD *)(v21 + 34160);
        if ( v23 )
          ipc_log_string(v23, "ipa %s:%d failed to clean q6 flt tbls (v6/hashable)\n", "ipa3_q6_clean_q6_tables", 5190);
      }
    }
    else if ( (unsigned int)ipa3_q6_clean_q6_flt_tbls(v9, 1) )
    {
      printk(&unk_3BD467, "ipa3_q6_clean_q6_tables");
      v24 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v25 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v25 )
        {
          ipc_log_string(
            v25,
            "ipa %s:%d failed to clean q6 flt tbls (v4/non-hashable)\n",
            "ipa3_q6_clean_q6_tables",
            5194);
          v24 = ipa3_ctx;
        }
        v26 = *(_QWORD *)(v24 + 34160);
        if ( v26 )
          ipc_log_string(
            v26,
            "ipa %s:%d failed to clean q6 flt tbls (v4/non-hashable)\n",
            "ipa3_q6_clean_q6_tables",
            5194);
      }
    }
    else
    {
      v10 = ipa3_q6_clean_q6_flt_tbls(1, 1);
      if ( (_DWORD)v10 )
      {
        printk(&unk_3ABF6D, "ipa3_q6_clean_q6_tables");
        v27 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v28 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v28 )
          {
            ipc_log_string(
              v28,
              "ipa %s:%d failed to clean q6 flt tbls (v6/non-hashable)\n",
              "ipa3_q6_clean_q6_tables",
              5198);
            v27 = ipa3_ctx;
          }
          v29 = *(_QWORD *)(v27 + 34160);
          if ( v29 )
            ipc_log_string(
              v29,
              "ipa %s:%d failed to clean q6 flt tbls (v6/non-hashable)\n",
              "ipa3_q6_clean_q6_tables",
              5198);
        }
      }
      else if ( (unsigned int)ipa3_q6_clean_q6_rt_tbls(v10, 0) )
      {
        printk(&unk_3E03ED, "ipa3_q6_clean_q6_tables");
        v30 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v31 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v31 )
          {
            ipc_log_string(v31, "ipa %s:%d failed to clean q6 rt tbls (v4/hashable)\n", "ipa3_q6_clean_q6_tables", 5203);
            v30 = ipa3_ctx;
          }
          v32 = *(_QWORD *)(v30 + 34160);
          if ( v32 )
            ipc_log_string(v32, "ipa %s:%d failed to clean q6 rt tbls (v4/hashable)\n", "ipa3_q6_clean_q6_tables", 5203);
        }
      }
      else
      {
        v11 = ipa3_q6_clean_q6_rt_tbls(1, 0);
        if ( (_DWORD)v11 )
        {
          printk(&unk_3D7B8F, "ipa3_q6_clean_q6_tables");
          v33 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v34 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v34 )
            {
              ipc_log_string(
                v34,
                "ipa %s:%d failed to clean q6 rt tbls (v6/hashable)\n",
                "ipa3_q6_clean_q6_tables",
                5207);
              v33 = ipa3_ctx;
            }
            v35 = *(_QWORD *)(v33 + 34160);
            if ( v35 )
              ipc_log_string(
                v35,
                "ipa %s:%d failed to clean q6 rt tbls (v6/hashable)\n",
                "ipa3_q6_clean_q6_tables",
                5207);
          }
        }
        else if ( (unsigned int)ipa3_q6_clean_q6_rt_tbls(v11, 1) )
        {
          printk(&unk_3F16B3, "ipa3_q6_clean_q6_tables");
          v36 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v37 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v37 )
            {
              ipc_log_string(
                v37,
                "ipa %s:%d failed to clean q6 rt tbls (v4/non-hashable)\n",
                "ipa3_q6_clean_q6_tables",
                5211);
              v36 = ipa3_ctx;
            }
            v38 = *(_QWORD *)(v36 + 34160);
            if ( v38 )
              ipc_log_string(
                v38,
                "ipa %s:%d failed to clean q6 rt tbls (v4/non-hashable)\n",
                "ipa3_q6_clean_q6_tables",
                5211);
          }
        }
        else
        {
          if ( !(unsigned int)ipa3_q6_clean_q6_rt_tbls(1, 1) )
          {
            if ( *(_BYTE *)(ipa3_ctx + 32270) == 1 )
              goto LABEL_127;
            v0 = _kmalloc_cache_noprof(raw_spin_lock_irqsave, 2336, 208);
            if ( !v0 )
              goto LABEL_131;
            v1 = (__int64 *)_kmalloc_cache_noprof(kfree, 2336, 16);
            if ( !v1 )
            {
              v51 = -12;
LABEL_121:
              kfree(v0);
              v62 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v63 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v63 )
                {
                  ipc_log_string(v63, "ipa %s:%d Done - retval = %d\n", "ipa3_q6_clean_q6_tables", 5314, v51);
                  v62 = ipa3_ctx;
                }
                v64 = *(_QWORD *)(v62 + 34160);
                if ( v64 )
                  ipc_log_string(v64, "ipa %s:%d Done - retval = %d\n", "ipa3_q6_clean_q6_tables", 5314, v51);
              }
              if ( !v51 )
              {
LABEL_127:
                v123 = 0;
                v122 = 0u;
                v121 = 0;
                v120 = 0;
                v119 = 0u;
                v0 = 104LL * (unsigned int)(*(_DWORD *)(ipa3_ctx + 34308) + 1);
                v1 = (__int64 *)_kmalloc_noprof(v0, 2336);
                if ( !v1 )
                  goto LABEL_218;
                goto LABEL_128;
              }
              goto LABEL_131;
            }
            v12 = ipa_get_ep_mapping(95);
            v13 = ipa3_ctx;
            if ( v12 == -1 || (*(_BYTE *)(ipa3_ctx + 51242) & 1) != 0 )
            {
              v14 = 0;
            }
            else
            {
              v18 = ipa_get_ep_mapping(95);
              BYTE12(v119) = 0;
              v19 = *(_DWORD *)(ipa3_ctx + 32240);
              v120 = 0;
              if ( v19 > 0x14 )
                ep_reg_offset = ipahal_get_ep_reg_offset(133, v18);
              else
                ep_reg_offset = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(44, 0, 0);
              LODWORD(v119) = ep_reg_offset;
              ipahal_get_aggr_force_close_valmask(v18, &v121);
              *(_QWORD *)((char *)&v119 + 4) = v121;
              v42 = ((__int64 (__fastcall *)(__int64, __int128 *, _QWORD))ipahal_construct_imm_cmd)(7, &v119, 0);
              *v1 = v42;
              if ( !v42 )
              {
                printk(&unk_3AEDE8, "ipa3_q6_clean_q6_tables");
                v59 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v60 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v60 )
                  {
                    ipc_log_string(
                      v60,
                      "ipa %s:%d failed to construct coal close IC\n",
                      "ipa3_q6_clean_q6_tables",
                      5258);
                    v59 = ipa3_ctx;
                  }
                  v61 = *(_QWORD *)(v59 + 34160);
                  if ( v61 )
                    ipc_log_string(
                      v61,
                      "ipa %s:%d failed to construct coal close IC\n",
                      "ipa3_q6_clean_q6_tables",
                      5258);
                }
                v51 = -12;
                goto LABEL_100;
              }
              ipa3_init_imm_cmd_desc(v0, v42);
              v13 = ipa3_ctx;
              v14 = 1;
            }
            if ( *(_DWORD *)(v13 + 32240) < 0x15u )
            {
              v118 = 16843009;
              ipahal_get_fltrt_hash_flush_valmask(&v118, &v121);
              v43 = 67;
            }
            else
            {
              LOWORD(v118) = 257;
              ipahal_get_fltrt_cache_flush_valmask(&v118, &v121);
              v43 = 140;
            }
            v44 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(v43, 0, 0);
            BYTE12(v122) = 0;
            v123 = 0;
            LODWORD(v122) = v44;
            *(_QWORD *)((char *)&v122 + 4) = v121;
            v45 = ((__int64 (__fastcall *)(__int64, __int128 *, _QWORD))ipahal_construct_imm_cmd)(7, &v122, 0);
            v1[v14] = v45;
            if ( v45 )
            {
              ipa3_init_imm_cmd_desc(v0 + 104LL * v14, v45);
              v46 = ipa3_ctx;
              v47 = v14 + 1;
              if ( ipa3_ctx )
              {
                v48 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v48 )
                {
                  ipc_log_string(
                    v48,
                    "ipa %s:%d Sending 1 descriptor for tbls flush\n",
                    "ipa3_q6_clean_q6_tables",
                    5301);
                  v46 = ipa3_ctx;
                }
                v49 = *(_QWORD *)(v46 + 34160);
                if ( v49 )
                  ipc_log_string(
                    v49,
                    "ipa %s:%d Sending 1 descriptor for tbls flush\n",
                    "ipa3_q6_clean_q6_tables",
                    5301);
              }
              v50 = ((__int64 (__fastcall *)(_QWORD, unsigned __int64))ipa3_send_cmd)(v47, v0);
              if ( v50 )
              {
                v55 = v50;
                printk(&unk_3B759A, "ipa3_q6_clean_q6_tables");
                v56 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v57 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v57 )
                  {
                    ipc_log_string(
                      v57,
                      "ipa %s:%d failed to send immediate command (err %d)\n",
                      "ipa3_q6_clean_q6_tables",
                      5304,
                      v55);
                    v56 = ipa3_ctx;
                  }
                  v58 = *(_QWORD *)(v56 + 34160);
                  if ( v58 )
                    ipc_log_string(
                      v58,
                      "ipa %s:%d failed to send immediate command (err %d)\n",
                      "ipa3_q6_clean_q6_tables",
                      5304,
                      v55);
                }
                v51 = -14;
              }
              else
              {
                v51 = 0;
              }
            }
            else
            {
              printk(&unk_3B4561, "ipa3_q6_clean_q6_tables");
              v52 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v53 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v53 )
                {
                  ipc_log_string(
                    v53,
                    "ipa %s:%d fail construct register_write imm cmd\n",
                    "ipa3_q6_clean_q6_tables",
                    5294);
                  v52 = ipa3_ctx;
                }
                v54 = *(_QWORD *)(v52 + 34160);
                if ( v54 )
                  ipc_log_string(
                    v54,
                    "ipa %s:%d fail construct register_write imm cmd\n",
                    "ipa3_q6_clean_q6_tables",
                    5294);
              }
              v51 = -14;
              if ( !v14 )
                goto LABEL_100;
              v47 = 1;
            }
            kfree(*v1);
            if ( v47 != 1 )
              kfree(v1[1]);
LABEL_100:
            kfree(v1);
            goto LABEL_121;
          }
          printk(&unk_3D1F8A, "ipa3_q6_clean_q6_tables");
          v39 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v40 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v40 )
            {
              ipc_log_string(
                v40,
                "ipa %s:%d failed to clean q6 rt tbls (v6/non-hashable)\n",
                "ipa3_q6_clean_q6_tables",
                5215);
              v39 = ipa3_ctx;
            }
            v41 = *(_QWORD *)(v39 + 34160);
            if ( v41 )
              ipc_log_string(
                v41,
                "ipa %s:%d failed to clean q6 rt tbls (v6/non-hashable)\n",
                "ipa3_q6_clean_q6_tables",
                5215);
          }
        }
      }
    }
  }
LABEL_131:
  printk(&unk_3FD4BB, "ipa3_q6_pre_shutdown_cleanup");
  v67 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v68 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v68 )
    {
      ipc_log_string(v68, "ipa %s:%d Failed to clean Q6 tables\n", "ipa3_q6_pre_shutdown_cleanup", 5481);
      v67 = ipa3_ctx;
    }
    v69 = *(_QWORD *)(v67 + 34160);
    if ( v69 )
      ipc_log_string(v69, "ipa %s:%d Failed to clean Q6 tables\n", "ipa3_q6_pre_shutdown_cleanup", 5481);
  }
  printk(&unk_3AED39, v66);
  __break(0x800u);
LABEL_137:
  v70 = ipa_get_ep_mapping(95);
  BYTE12(v119) = 0;
  v71 = *(_DWORD *)(ipa3_ctx + 32240);
  v120 = 0;
  if ( v71 > 0x14 )
    v72 = ipahal_get_ep_reg_offset(133, v70);
  else
    v72 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(44, 0, 0);
  LODWORD(v119) = v72;
  ipahal_get_aggr_force_close_valmask(v70, &v121);
  *(_QWORD *)((char *)&v119 + 4) = v121;
  v73 = ((__int64 (__fastcall *)(__int64, __int128 *, _QWORD))ipahal_construct_imm_cmd)(7, &v119, 0);
  if ( !v73 )
  {
LABEL_224:
    printk(&unk_3AEDE8, "ipa3_q6_set_ex_path_to_apps");
    v108 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v109 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v109 )
      {
        ipc_log_string(v109, "ipa %s:%d failed to construct coal close IC\n", "ipa3_q6_set_ex_path_to_apps", 5359);
        v108 = ipa3_ctx;
      }
      v110 = *(_QWORD *)(v108 + 34160);
      if ( v110 )
        ipc_log_string(v110, "ipa %s:%d failed to construct coal close IC\n", "ipa3_q6_set_ex_path_to_apps", 5359);
    }
    printk(&unk_3AED39, v107);
    __break(0x800u);
LABEL_230:
    printk(&unk_3C317D, "ipa3_q6_set_ex_path_to_apps");
    v112 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v113 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v113 )
      {
        ipc_log_string(v113, "ipa %s:%d fail construct register_write cmd\n", "ipa3_q6_set_ex_path_to_apps", 5397);
        v112 = ipa3_ctx;
      }
      v114 = *(_QWORD *)(v112 + 34160);
      if ( v114 )
        ipc_log_string(v114, "ipa %s:%d fail construct register_write cmd\n", "ipa3_q6_set_ex_path_to_apps", 5397);
    }
    printk(&unk_3AED39, v111);
    __break(0x800u);
LABEL_236:
    __break(0x5512u);
  }
  v74 = v73;
  ipa3_init_imm_cmd_desc(v1, v73);
  if ( v0 < 0x28 )
    goto LABEL_216;
  v1[5] = (__int64)ipa3_destroy_imm;
  if ( v0 < 0x30 )
    goto LABEL_216;
  v1[6] = v74;
  v65 = 1;
LABEL_144:
  for ( i = 0; i != 134; ++i )
  {
    v76 = ipa_get_ep_mapping(i);
    if ( v76 == -1 )
      continue;
    v77 = v76;
    if ( v76 >= (unsigned int)ipa3_get_max_num_pipes() || (i & 0xFE) == 0x3E || (i & 0xF8) == 0x40 )
      continue;
    if ( i == 84 || i == 114 || i == 74 || i == 122 || (i & 0xFD) == 0x38 || i == 52 || (i & 0xFB) == 0x32 )
    {
      v79 = ipa3_ctx;
    }
    else
    {
      if ( (i & 1) != 0 )
      {
        if ( v77 > 0x23 )
          goto LABEL_236;
        v79 = ipa3_ctx;
        v81 = v77;
LABEL_171:
        if ( *(_DWORD *)(v79 + 480LL * v81 + 172) != 34 || *(_BYTE *)(v79 + 32262) != 1 )
          continue;
        goto LABEL_163;
      }
      if ( v77 >= 0x24 )
        goto LABEL_236;
      v79 = ipa3_ctx;
      v80 = ipa3_ctx + 480LL * v77;
      v81 = v77;
      v83 = *(_DWORD *)(v80 + 168);
      v82 = v80 + 168;
      if ( !v83 || (*(_BYTE *)(v82 + 404) & 1) == 0 )
        goto LABEL_171;
    }
LABEL_163:
    if ( (unsigned int)v65 >= *(_DWORD *)(v79 + 34308) )
    {
      printk(&unk_3AED39, v78);
      __break(0x800u);
      v115 = ipa3_ctx;
      StatusReg = _ReadStatusReg(SP_EL0);
      v117 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &ipa3_q6_set_ex_path_to_apps__alloc_tag;
      v0 = 104LL * (unsigned int)(*(_DWORD *)(v115 + 34308) + 1);
      v1 = (__int64 *)_kmalloc_noprof(v0, 2336);
      *(_QWORD *)(StatusReg + 80) = v117;
      if ( !v1 )
      {
LABEL_218:
        printk(&unk_3A5E84, "ipa3_q6_pre_shutdown_cleanup");
        v104 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v105 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v105 )
          {
            ipc_log_string(
              v105,
              "ipa %s:%d Failed to redirect exceptions to APPS\n",
              "ipa3_q6_pre_shutdown_cleanup",
              5489);
            v104 = ipa3_ctx;
          }
          v106 = *(_QWORD *)(v104 + 34160);
          if ( v106 )
            ipc_log_string(
              v106,
              "ipa %s:%d Failed to redirect exceptions to APPS\n",
              "ipa3_q6_pre_shutdown_cleanup",
              5489);
        }
        printk(&unk_3AED39, v103);
        __break(0x800u);
        goto LABEL_224;
      }
LABEL_128:
      if ( (unsigned int)ipa_get_ep_mapping(95) == -1 || (*(_BYTE *)(ipa3_ctx + 51242) & 1) != 0 )
      {
        v65 = 0;
        goto LABEL_144;
      }
      goto LABEL_137;
    }
    if ( v77 > 0x23 )
      goto LABEL_236;
    *(_BYTE *)(v79 + 480LL * v77 + 520) = 0;
    BYTE12(v122) = 0;
    v123 = 0;
    LODWORD(v122) = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(73, 0, v77);
    *(_QWORD *)((char *)&v122 + 4) = 0xFFFFFFFF00000000LL;
    v84 = ((__int64 (__fastcall *)(__int64, __int128 *, _QWORD))ipahal_construct_imm_cmd)(7, &v122, 0);
    if ( !v84 )
      goto LABEL_230;
    v85 = &v1[13 * v65];
    v86 = v84;
    v87 = 104LL * v65;
    ipa3_init_imm_cmd_desc(v85, v84);
    if ( v0 <= v87 + 40 )
      goto LABEL_216;
    v85[5] = (__int64)ipa3_destroy_imm;
    if ( v0 <= v87 + 48 )
      goto LABEL_216;
    ++v65;
    v85[6] = v86;
  }
  v88 = ipa3_tag_process(v1, (unsigned int)v65, 1000);
  if ( v88 )
  {
    v94 = v88;
    printk(&unk_3ABFE0, "ipa3_q6_set_ex_path_to_apps");
    v95 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v96 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v96 )
      {
        ipc_log_string(v96, "ipa %s:%d TAG process failed! (error %d)\n", "ipa3_q6_set_ex_path_to_apps", 5412, v94);
        v95 = ipa3_ctx;
      }
      v97 = *(_QWORD *)(v95 + 34160);
      if ( v97 )
        ipc_log_string(v97, "ipa %s:%d TAG process failed! (error %d)\n", "ipa3_q6_set_ex_path_to_apps", 5412, v94);
    }
    if ( v94 != -62 && v65 >= 1 )
    {
      v98 = 0;
      v99 = 104LL * (unsigned int)v65;
      while ( v0 > v98 + 40 )
      {
        v102 = (void (__fastcall *)(__int64, __int64))v1[v98 / 8 + 5];
        if ( v102 )
        {
          if ( v0 <= v98 + 48 || v0 <= v98 + 56 || v0 <= v98 + 48 || v0 <= v98 + 56 )
            break;
          v100 = v1[v98 / 8 + 6];
          v101 = LODWORD(v1[v98 / 8 + 7]);
          if ( *((_DWORD *)v102 - 1) != 1607364836 )
            __break(0x8228u);
          v102(v100, v101);
        }
        v98 += 104LL;
        if ( v99 == v98 )
          goto LABEL_217;
      }
LABEL_216:
      __break(1u);
    }
LABEL_217:
    kfree(v1);
    goto LABEL_218;
  }
  kfree(v1);
  if ( (*(_BYTE *)(ipa3_ctx + 50153) & 1) != 0 )
  {
    ipa3_q6_pipe_flow_control(0);
    v89 = 18;
    goto LABEL_177;
  }
  if ( (*(_BYTE *)(ipa3_ctx + 32268) & 1) != 0 )
  {
    v90 = ((__int64 (__fastcall *)(__int64, _QWORD))ipa3_start_stop_client_prod_gsi_chnl)(18, 0);
    if ( *(_BYTE *)(ipa3_ctx + 32264) == 1 )
      v90 = ((__int64 (__fastcall *)(__int64, _QWORD))ipa3_start_stop_client_prod_gsi_chnl)(20, 0);
  }
  else
  {
    v92 = 0;
    LOWORD(v122) = 0;
    do
    {
      if ( v92 == 84
        || v92 == 114
        || v92 == 74
        || v92 == 122
        || (v92 & 0xFD) == 0x38
        || v92 == 52
        || (v92 & 0xFB) == 0x32 )
      {
        v93 = ipa_get_ep_mapping(v92);
        if ( v93 != -1 )
          ((void (__fastcall *)(__int64, _QWORD, __int128 *))ipahal_write_reg_n_fields)(49, v93, &v122);
      }
      ++v92;
    }
    while ( v92 != 134 );
    v90 = ipa3_set_reset_client_prod_pipe_delay(1, 18);
    if ( *(_BYTE *)(ipa3_ctx + 32264) == 1 )
    {
      v89 = 20;
LABEL_177:
      v90 = ipa3_set_reset_client_prod_pipe_delay(1, v89);
    }
  }
  result = _ipa3_dec_client_disable_clks(v90);
  if ( ipa3_ctx )
  {
    result = *(_QWORD *)(ipa3_ctx + 34160);
    if ( result )
      result = ipc_log_string(result, "ipa %s:%d Exit with success\n", "ipa3_q6_pre_shutdown_cleanup", 5520);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
