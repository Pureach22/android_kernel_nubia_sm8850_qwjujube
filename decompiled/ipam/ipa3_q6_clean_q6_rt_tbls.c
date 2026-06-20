__int64 __fastcall ipa3_q6_clean_q6_rt_tbls(int a1, int a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  unsigned int v10; // w22
  int *v11; // x8
  int *v12; // x9
  bool v13; // zf
  __int64 v14; // x11
  __int64 v15; // x12
  __int64 v16; // x13
  __int64 v17; // x14
  _DWORD *v18; // x10
  __int64 v19; // x12
  int v20; // w22
  int v21; // w24
  __int64 v22; // x19
  __int64 *v23; // x20
  int ep_mapping; // w0
  __int64 v25; // x8
  unsigned int v26; // w21
  unsigned int v27; // w21
  unsigned int v28; // w8
  int ep_reg_offset; // w0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  int v34; // w8
  __int64 v35; // x0
  __int64 v36; // x8
  unsigned int v37; // w21
  __int64 v38; // x0
  __int64 v39; // x0
  int v40; // w0
  __int64 v41; // x8
  __int64 v42; // x0
  __int64 v43; // x0
  int v44; // w22
  __int64 v45; // x8
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x8
  __int64 v49; // x0
  __int64 v50; // x0
  __int128 v52; // [xsp+8h] [xbp-58h] BYREF
  int v53; // [xsp+18h] [xbp-48h]
  __int64 v54; // [xsp+20h] [xbp-40h] BYREF
  __int64 v55; // [xsp+28h] [xbp-38h] BYREF
  __int64 v56; // [xsp+30h] [xbp-30h]
  __int64 v57; // [xsp+38h] [xbp-28h]
  __int64 v58; // [xsp+40h] [xbp-20h] BYREF
  __int64 v59; // [xsp+48h] [xbp-18h]
  __int64 v60; // [xsp+50h] [xbp-10h]
  __int64 v61; // [xsp+58h] [xbp-8h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = ipa3_ctx;
  v59 = 0;
  v60 = 0;
  v58 = 0;
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v53 = 0;
  v52 = 0u;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d Entry\n", "ipa3_q6_clean_q6_rt_tbls", 5047);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
      ipc_log_string(v6, "ipa %s:%d Entry\n", "ipa3_q6_clean_q6_rt_tbls", 5047);
  }
  if ( !a2 )
  {
    v7 = ipa3_ctx;
    if ( *(_BYTE *)(ipa3_ctx + 32270) == 1 )
    {
      if ( !ipa3_ctx )
        goto LABEL_25;
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d Clean hashable rules not supported\n", "ipa3_q6_clean_q6_rt_tbls", 5059);
        v7 = ipa3_ctx;
      }
      v9 = *(_QWORD *)(v7 + 34160);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d Clean hashable rules not supported\n", "ipa3_q6_clean_q6_rt_tbls", 5059);
        v10 = 0;
      }
      else
      {
LABEL_25:
        v10 = 0;
      }
      goto LABEL_71;
    }
  }
  v11 = **(int ***)(ipa3_ctx + 34176);
  if ( a1 )
  {
    v12 = v11 + 25;
    v13 = a2 == 0;
    v14 = 128;
    v15 = 116;
    v16 = 44;
    v17 = 32;
    v18 = v11 + 26;
  }
  else
  {
    v12 = v11 + 14;
    v13 = a2 == 0;
    v14 = 84;
    v15 = 72;
    v16 = 20;
    v17 = 8;
    v18 = v11 + 15;
  }
  if ( v13 )
  {
    v14 = v15;
    v19 = v17;
  }
  else
  {
    v19 = v16;
  }
  v20 = *v12;
  v21 = *(int *)((char *)v11 + v14);
  if ( !(unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, __int64 *, __int64))ipahal_rt_generate_empty_img)(
                        (unsigned int)(*v18 - *v12 + 1),
                        *(unsigned int *)((char *)v11 + v19),
                        *(unsigned int *)((char *)v11 + v19),
                        &v55,
                        1) )
  {
    v22 = _kmalloc_cache_noprof(raw_spin_lock_irqsave, 2336, 208);
    if ( !v22 )
    {
      v10 = -12;
LABEL_70:
      ipahal_free_dma_mem(&v55);
      goto LABEL_71;
    }
    v23 = (__int64 *)_kmalloc_cache_noprof(kfree, 2336, 16);
    if ( !v23 )
    {
      v10 = -12;
      goto LABEL_69;
    }
    ep_mapping = ipa_get_ep_mapping(95);
    v25 = ipa3_ctx;
    if ( ep_mapping == -1 || (*(_BYTE *)(ipa3_ctx + 51242) & 1) != 0 )
    {
      v26 = 0;
    }
    else
    {
      v27 = ipa_get_ep_mapping(95);
      BYTE12(v52) = 0;
      v28 = *(_DWORD *)(ipa3_ctx + 32240);
      v53 = 0;
      if ( v28 > 0x14 )
        ep_reg_offset = ipahal_get_ep_reg_offset(133, v27);
      else
        ep_reg_offset = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(44, 0, 0);
      LODWORD(v52) = ep_reg_offset;
      ipahal_get_aggr_force_close_valmask(v27, &v54);
      *(_QWORD *)((char *)&v52 + 4) = v54;
      v33 = ((__int64 (__fastcall *)(__int64, __int128 *, _QWORD))ipahal_construct_imm_cmd)(7, &v52, 0);
      *v23 = v33;
      if ( !v33 )
      {
        printk(&unk_3AEDE8, "ipa3_q6_clean_q6_rt_tbls");
        v48 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v49 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v49 )
          {
            ipc_log_string(v49, "ipa %s:%d failed to construct coal close IC\n", "ipa3_q6_clean_q6_rt_tbls", 5127);
            v48 = ipa3_ctx;
          }
          v50 = *(_QWORD *)(v48 + 34160);
          if ( v50 )
            ipc_log_string(v50, "ipa %s:%d failed to construct coal close IC\n", "ipa3_q6_clean_q6_rt_tbls", 5127);
        }
        v10 = -12;
        goto LABEL_46;
      }
      ipa3_init_imm_cmd_desc(v22, v33);
      v25 = ipa3_ctx;
      v26 = 1;
    }
    v34 = *(unsigned __int16 *)(v25 + 29522);
    *(_WORD *)((char *)&v60 + 1) = 0;
    HIDWORD(v60) = 0;
    LODWORD(v59) = v57;
    v58 = v56;
    HIDWORD(v59) = v21 + v34 + ((__int64 (*)(void))ipahal_get_hw_tbl_hdr_width)() * v20;
    v35 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v58, 0);
    v23[v26] = v35;
    if ( v35 )
    {
      ipa3_init_imm_cmd_desc(v22 + 104LL * v26, v35);
      v36 = ipa3_ctx;
      v37 = v26 + 1;
      if ( ipa3_ctx )
      {
        v38 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v38 )
        {
          ipc_log_string(v38, "ipa %s:%d Sending 1 descriptor for rt tbl clearing\n", "ipa3_q6_clean_q6_rt_tbls", 5153);
          v36 = ipa3_ctx;
        }
        v39 = *(_QWORD *)(v36 + 34160);
        if ( v39 )
          ipc_log_string(v39, "ipa %s:%d Sending 1 descriptor for rt tbl clearing\n", "ipa3_q6_clean_q6_rt_tbls", 5153);
      }
      v40 = ((__int64 (__fastcall *)(_QWORD, __int64))ipa3_send_cmd)(v37, v22);
      if ( v40 )
      {
        v44 = v40;
        printk(&unk_3B759A, "ipa3_q6_clean_q6_rt_tbls");
        v45 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v46 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v46 )
          {
            ipc_log_string(
              v46,
              "ipa %s:%d failed to send immediate command (err %d)\n",
              "ipa3_q6_clean_q6_rt_tbls",
              5156,
              v44);
            v45 = ipa3_ctx;
          }
          v47 = *(_QWORD *)(v45 + 34160);
          if ( v47 )
            ipc_log_string(
              v47,
              "ipa %s:%d failed to send immediate command (err %d)\n",
              "ipa3_q6_clean_q6_rt_tbls",
              5156,
              v44);
        }
        v10 = -14;
      }
      else
      {
        v10 = 0;
      }
    }
    else
    {
      printk(&unk_3A8EB0, "ipa3_q6_clean_q6_rt_tbls");
      v41 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v42 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v42 )
        {
          ipc_log_string(
            v42,
            "ipa %s:%d failed to construct dma_shared_mem imm cmd\n",
            "ipa3_q6_clean_q6_rt_tbls",
            5146);
          v41 = ipa3_ctx;
        }
        v43 = *(_QWORD *)(v41 + 34160);
        if ( v43 )
          ipc_log_string(
            v43,
            "ipa %s:%d failed to construct dma_shared_mem imm cmd\n",
            "ipa3_q6_clean_q6_rt_tbls",
            5146);
      }
      v10 = -12;
      if ( !v26 )
        goto LABEL_46;
      v37 = 1;
    }
    kfree(*v23);
    if ( v37 != 1 )
      kfree(v23[1]);
LABEL_46:
    kfree(v23);
LABEL_69:
    kfree(v22);
    goto LABEL_70;
  }
  printk(&unk_3F707D, "ipa3_q6_clean_q6_rt_tbls");
  v30 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_47;
  v31 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v31 )
  {
    ipc_log_string(v31, "ipa %s:%d fail generate empty rt img\n", "ipa3_q6_clean_q6_rt_tbls", 5089);
    v30 = ipa3_ctx;
  }
  v32 = *(_QWORD *)(v30 + 34160);
  if ( v32 )
  {
    ipc_log_string(v32, "ipa %s:%d fail generate empty rt img\n", "ipa3_q6_clean_q6_rt_tbls", 5089);
    v10 = -12;
  }
  else
  {
LABEL_47:
    v10 = -12;
  }
LABEL_71:
  _ReadStatusReg(SP_EL0);
  return v10;
}
