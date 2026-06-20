__int64 __fastcall ipa3_tag_aggr_force_close(int a1)
{
  unsigned int v1; // w26
  unsigned int v2; // w22
  int v3; // w27
  unsigned __int64 v4; // x21
  unsigned __int64 v5; // x19
  signed int v6; // w25
  __int64 v7; // x8
  unsigned int v8; // w10
  unsigned int v9; // w11
  __int64 v10; // x0
  __int64 v11; // x0
  char v12; // w9
  int ep_reg_offset; // w0
  _WORD *v14; // x0
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x1
  unsigned __int64 v17; // x9
  unsigned int v18; // w20
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x9
  unsigned __int64 v31; // x20
  unsigned __int64 v32; // x22
  unsigned __int64 v33; // x23
  unsigned __int64 v34; // x24
  void (__fastcall *v35)(__int64, __int64); // x8
  __int64 v36; // x0
  __int64 v37; // x1
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x8
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // [xsp+8h] [xbp-48h] BYREF
  __int128 v45; // [xsp+10h] [xbp-40h] BYREF
  int v46; // [xsp+20h] [xbp-30h]
  _QWORD v47[3]; // [xsp+28h] [xbp-28h] BYREF
  int v48; // [xsp+40h] [xbp-10h]
  __int64 v49; // [xsp+48h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 < -1 || *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    printk(&unk_3ED009, "ipa3_tag_aggr_force_close");
    v21 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v22 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v22 )
      {
        ipc_log_string(v22, "ipa %s:%d Invalid pipe number %d\n", "ipa3_tag_aggr_force_close", 11433, a1);
        v21 = ipa3_ctx;
      }
      v23 = *(_QWORD *)(v21 + 34160);
      if ( v23 )
        ipc_log_string(v23, "ipa %s:%d Invalid pipe number %d\n", "ipa3_tag_aggr_force_close", 11433, a1);
    }
    v18 = -22;
    goto LABEL_58;
  }
  if ( a1 == -1 )
    v1 = *(_DWORD *)(ipa3_ctx + 34308);
  else
    v1 = a1 + 1;
  if ( a1 == -1 )
    v2 = 0;
  else
    v2 = a1;
  if ( a1 == -1 )
    v3 = *(_DWORD *)(ipa3_ctx + 34308);
  else
    v3 = 1;
  v4 = 104LL * (unsigned int)v3;
  v5 = _kmalloc_noprof(v4, 3520);
  if ( !v5 )
  {
    printk(&unk_3CF6DE, "ipa3_tag_aggr_force_close");
    v41 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v42 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v42 )
      {
        ipc_log_string(v42, "ipa %s:%d no mem\n", "ipa3_tag_aggr_force_close", 11449);
        v41 = ipa3_ctx;
      }
      v43 = *(_QWORD *)(v41 + 34160);
      if ( v43 )
        ipc_log_string(v43, "ipa %s:%d no mem\n", "ipa3_tag_aggr_force_close", 11449);
    }
    v18 = -12;
    goto LABEL_58;
  }
  if ( v2 >= v1 )
  {
    v6 = 0;
LABEL_56:
    v18 = ipa3_tag_process(v5, v6, 2500);
    goto LABEL_57;
  }
  v6 = 0;
  v48 = 0;
  memset(v47, 0, sizeof(v47));
  v45 = 0u;
  v46 = 0;
  v44 = 0;
  do
  {
    ipahal_read_reg_n_fields(43, v2, v47);
    if ( !LODWORD(v47[0]) )
      goto LABEL_15;
    v7 = ipa3_ctx;
    if ( *(_BYTE *)(ipa3_ctx + 51242) == 1 )
    {
      if ( *(unsigned __int8 *)(ipa3_ctx + 32244) >= 0x18uLL )
        goto LABEL_96;
      if ( ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 4940] != 1
        || (v8 = *(_DWORD *)&ipa3_ep_mapping[6968 * *(unsigned __int8 *)(ipa3_ctx + 32244) + 4960],
            (v8 & 0x80000000) != 0) )
      {
        if ( v2 == -1 )
          goto LABEL_15;
      }
      else
      {
        if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x14u )
          v9 = 31;
        else
          v9 = 36;
        if ( v8 >= v9 )
          v8 = -1;
        if ( v2 == v8 )
          goto LABEL_15;
      }
    }
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d Force close ep: %d\n", "ipa3_tag_generate_force_close_desc", 11368, v2);
        v7 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v7 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d Force close ep: %d\n", "ipa3_tag_generate_force_close_desc", 11368, v2);
    }
    if ( v6 + 1 > v3 )
    {
      printk(&unk_3B8F96, "ipa3_tag_generate_force_close_desc");
      v24 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v25 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v25 )
        {
          ipc_log_string(
            v25,
            "ipa %s:%d Internal error - no descriptors\n",
            "ipa3_tag_generate_force_close_desc",
            11370);
          v24 = ipa3_ctx;
        }
        v26 = *(_QWORD *)(v24 + 34160);
        if ( v26 )
          ipc_log_string(
            v26,
            "ipa %s:%d Internal error - no descriptors\n",
            "ipa3_tag_generate_force_close_desc",
            11370);
      }
      v6 = -14;
      goto LABEL_88;
    }
    if ( (*(_BYTE *)(ipa3_ctx + 51242) & 1) != 0 )
    {
      v12 = 1;
    }
    else
    {
      v12 = 0;
      v46 = 2;
    }
    BYTE12(v45) = v12;
    if ( *(_DWORD *)(ipa3_ctx + 32240) > 0x14u )
      ep_reg_offset = ipahal_get_ep_reg_offset(133, v2);
    else
      ep_reg_offset = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))ipahal_get_reg_mn_ofst)(44, 0, 0);
    LODWORD(v45) = ep_reg_offset;
    ipahal_get_aggr_force_close_valmask(v2, &v44);
    *(_QWORD *)((char *)&v45 + 4) = v44;
    v14 = (_WORD *)((__int64 (__fastcall *)(__int64, __int128 *, _QWORD))ipahal_construct_imm_cmd)(7, &v45, 0);
    if ( !v14 )
    {
      printk(&unk_3E98FD, "ipa3_tag_generate_force_close_desc");
      v27 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v28 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v28 )
        {
          ipc_log_string(
            v28,
            "ipa %s:%d failed to construct register_write imm cmd\n",
            "ipa3_tag_generate_force_close_desc",
            11396);
          v27 = ipa3_ctx;
        }
        v29 = *(_QWORD *)(v27 + 34160);
        if ( v29 )
          ipc_log_string(
            v29,
            "ipa %s:%d failed to construct register_write imm cmd\n",
            "ipa3_tag_generate_force_close_desc",
            11396);
      }
      if ( v6 < 1 )
      {
        v6 = -12;
      }
      else
      {
        v30 = 104LL * (unsigned int)v6;
        v31 = v5 + v30;
        v32 = v30 + 40;
        v33 = v30 + 48;
        v34 = v30 + 56;
        do
        {
          if ( v4 <= v32 )
            goto LABEL_94;
          v35 = *(void (__fastcall **)(__int64, __int64))(v31 + 40);
          if ( v35 )
          {
            if ( v4 <= v33 || v4 <= v34 )
              goto LABEL_94;
            v36 = *(_QWORD *)(v31 + 48);
            v37 = *(unsigned int *)(v31 + 56);
            if ( *((_DWORD *)v35 - 1) != 1607364836 )
              __break(0x8228u);
            v35(v36, v37);
          }
          --v6;
        }
        while ( v6 );
        v6 = -12;
      }
      goto LABEL_88;
    }
    v15 = 104LL * v6;
    if ( v4 >= v15 )
      v16 = v4 - v15;
    else
      v16 = 0;
    if ( v16 <= 0x67 )
      goto LABEL_95;
    v17 = v5 + 104LL * v6;
    *(_QWORD *)(v17 + 88) = 0;
    *(_QWORD *)(v17 + 96) = 0;
    *(_QWORD *)(v17 + 72) = 0;
    *(_QWORD *)(v17 + 80) = 0;
    *(_QWORD *)(v17 + 56) = 0;
    *(_QWORD *)(v17 + 64) = 0;
    *(_QWORD *)(v17 + 40) = 0;
    *(_QWORD *)(v17 + 48) = 0;
    *(_QWORD *)(v17 + 24) = 0;
    *(_QWORD *)(v17 + 32) = 0;
    *(_QWORD *)(v17 + 8) = 0;
    *(_QWORD *)(v17 + 16) = 0;
    *(_QWORD *)v17 = 0;
    if ( v6 < 0
      || v4 < v15 + 36
      || (*(_WORD *)(v17 + 36) = v14[1], v4 <= v15 + 8)
      || (*(_QWORD *)(v17 + 8) = v14 + 2, v4 < v15 + 34)
      || (*(_WORD *)(v17 + 34) = *v14, v4 <= v15)
      || (*(_DWORD *)v17 = 3, v4 <= v15 + 40)
      || (*(_QWORD *)(v17 + 40) = ipa3_tag_destroy_imm, v4 <= v15 + 48) )
    {
LABEL_94:
      __break(1u);
LABEL_95:
      _fortify_panic(15, v16, 104);
LABEL_96:
      __break(0x5512u);
    }
    ++v6;
    *(_QWORD *)(v17 + 48) = v14;
LABEL_15:
    ++v2;
  }
  while ( v1 != v2 );
  if ( (v6 & 0x80000000) == 0 )
    goto LABEL_56;
LABEL_88:
  printk(&unk_3F3254, "ipa3_tag_aggr_force_close");
  v38 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v39 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v39 )
    {
      ipc_log_string(
        v39,
        "ipa %s:%d ipa3_tag_generate_force_close_desc failed %d\n",
        "ipa3_tag_aggr_force_close",
        11458,
        v6);
      v38 = ipa3_ctx;
    }
    v40 = *(_QWORD *)(v38 + 34160);
    if ( v40 )
      ipc_log_string(
        v40,
        "ipa %s:%d ipa3_tag_generate_force_close_desc failed %d\n",
        "ipa3_tag_aggr_force_close",
        11458,
        v6);
  }
  v18 = -1;
LABEL_57:
  kfree(v5);
LABEL_58:
  _ReadStatusReg(SP_EL0);
  return v18;
}
