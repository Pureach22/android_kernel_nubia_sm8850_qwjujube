__int64 __fastcall ipa_get_quota_stats(void *a1)
{
  __int64 v1; // x8
  __int64 v3; // x8
  unsigned int v4; // w0
  __int64 v5; // x0
  int ep_mapping; // w0
  __int64 v7; // x8
  unsigned int v8; // w19
  char v9; // w23
  __int64 v10; // x0
  unsigned int v11; // w0
  __int64 v12; // x19
  unsigned int v13; // w0
  unsigned int v14; // w20
  __int64 v15; // x8
  unsigned int v16; // w0
  signed int v17; // w21
  __int64 v18; // x10
  __int64 v19; // x11
  __int64 v20; // x9
  __int64 v21; // x11
  __int64 v22; // x11
  unsigned int v23; // w20
  unsigned int v24; // w19
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 result; // x0
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 v42; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v44; // x21
  __int64 v45; // [xsp+8h] [xbp-128h]
  __int64 v46; // [xsp+10h] [xbp-120h] BYREF
  __int64 v47; // [xsp+18h] [xbp-118h]
  __int64 v48; // [xsp+20h] [xbp-110h] BYREF
  __int64 v49; // [xsp+28h] [xbp-108h]
  __int64 v50; // [xsp+30h] [xbp-100h]
  __int64 v51; // [xsp+38h] [xbp-F8h] BYREF
  _QWORD v52[26]; // [xsp+40h] [xbp-F0h] BYREF
  __int64 v53; // [xsp+110h] [xbp-20h] BYREF
  __int64 v54; // [xsp+118h] [xbp-18h]
  _QWORD v55[2]; // [xsp+120h] [xbp-10h] BYREF

  v55[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v1 = *(_QWORD *)(ipa3_ctx + 43800);
  if ( !v1 )
    goto LABEL_44;
  v46 = 0;
  v47 = 0;
  if ( *(_BYTE *)v1 != 1 )
    goto LABEL_44;
  memset(v52, 0, sizeof(v52));
  v3 = *(_QWORD *)(v1 + 8);
  v53 = 0;
  v54 = 0;
  v55[0] = v3;
  v4 = ((__int64 (__fastcall *)(_QWORD, _QWORD *, __int64 *))ipahal_stats_get_offset)(0, v55, &v51);
  if ( v4 )
  {
    v24 = v4;
    printk(&unk_3F543B, "ipa_get_quota_stats");
    v25 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_38;
    v26 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v26 )
    {
      ipc_log_string(v26, "ipa %s:%d failed to get offset from hal %d\n", "ipa_get_quota_stats", 703, v24);
      v25 = ipa3_ctx;
    }
    v27 = *(_QWORD *)(v25 + 34160);
    if ( v27 )
    {
      ipc_log_string(v27, "ipa %s:%d failed to get offset from hal %d\n", "ipa_get_quota_stats", 703, v24);
      result = v24;
    }
    else
    {
LABEL_38:
      result = v24;
    }
    goto LABEL_45;
  }
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v5 )
      ipc_log_string(v5, "ipa %s:%d offset = %d size = %d\n", "ipa_get_quota_stats", 707, v51, WORD2(v51));
  }
  if ( !WORD2(v51) )
  {
LABEL_44:
    result = 0;
    goto LABEL_45;
  }
  LODWORD(v47) = WORD2(v51);
  v45 = dma_alloc_attrs(*(_QWORD *)(ipa3_ctx + 34216), WORD2(v51), &v46, 3264, 0);
  if ( !v45 )
  {
    printk(&unk_3B245B, "ipa_get_quota_stats");
    v29 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v30 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v30 )
      {
        ipc_log_string(v30, "ipa %s:%d fail to alloc DMA memory", "ipa_get_quota_stats", 718);
        v29 = ipa3_ctx;
      }
      result = *(_QWORD *)(v29 + 34160);
      if ( result )
      {
        ipc_log_string(result, "ipa %s:%d fail to alloc DMA memory", "ipa_get_quota_stats", 718);
        result = 0;
      }
      goto LABEL_45;
    }
    goto LABEL_44;
  }
  ep_mapping = ipa_get_ep_mapping(95);
  v7 = ipa3_ctx;
  if ( ep_mapping == -1 || (*(_BYTE *)(ipa3_ctx + 51242) & 1) != 0 )
  {
    v8 = 0;
    v9 = 1;
  }
  else
  {
    ipa_close_coal_frame(&v53);
    if ( !v53 )
    {
      printk(&unk_3AEDE8, "ipa_get_quota_stats");
      v40 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v41 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v41 )
        {
          ipc_log_string(v41, "ipa %s:%d failed to construct coal close IC\n", "ipa_get_quota_stats", 727);
          v40 = ipa3_ctx;
        }
        v42 = *(_QWORD *)(v40 + 34160);
        if ( v42 )
          ipc_log_string(v42, "ipa %s:%d failed to construct coal close IC\n", "ipa_get_quota_stats", 727);
      }
      goto LABEL_66;
    }
    ipa3_init_imm_cmd_desc(v52, v53);
    v7 = ipa3_ctx;
    v9 = 0;
    v8 = 1;
  }
  BYTE2(v50) = 0;
  LOWORD(v50) = 257;
  HIDWORD(v50) = 0;
  LODWORD(v49) = v47;
  v48 = v46;
  HIDWORD(v49) = *(_DWORD *)(**(_QWORD **)(v7 + 34176) + 304LL) + *(unsigned __int16 *)(v7 + 29522) + (_DWORD)v51;
  v10 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v48, 0);
  *(&v53 + v8) = v10;
  if ( !v10 )
  {
    printk(&unk_3A8EB0, "ipa_get_quota_stats");
    v31 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v32 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v32 )
      {
        ipc_log_string(v32, "ipa %s:%d failed to construct dma_shared_mem imm cmd\n", "ipa_get_quota_stats", 746);
        v31 = ipa3_ctx;
      }
      v33 = *(_QWORD *)(v31 + 34160);
      if ( v33 )
        ipc_log_string(v33, "ipa %s:%d failed to construct dma_shared_mem imm cmd\n", "ipa_get_quota_stats", 746);
    }
LABEL_66:
    v23 = -12;
    goto LABEL_71;
  }
  ipa3_init_imm_cmd_desc(&v52[13 * v8], v10);
  v11 = ((__int64 (__fastcall *)(_QWORD, _QWORD *))ipa3_send_cmd)(v8 + 1, v52);
  if ( v11 )
  {
    v23 = v11;
    printk(&unk_3B18DA, "ipa_get_quota_stats");
    v34 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v35 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v35 )
      {
        ipc_log_string(v35, "ipa %s:%d failed to send immediate command (error %d)\n", "ipa_get_quota_stats", 755, v23);
        v34 = ipa3_ctx;
      }
      v36 = *(_QWORD *)(v34 + 34160);
      if ( v36 )
        ipc_log_string(v36, "ipa %s:%d failed to send immediate command (error %d)\n", "ipa_get_quota_stats", 755, v23);
    }
    goto LABEL_69;
  }
  v12 = _kmalloc_cache_noprof(__ratelimit, 3520, 1152);
  if ( !v12 )
    goto LABEL_68;
  while ( 2 )
  {
    v13 = ((__int64 (__fastcall *)(_QWORD, __int64, __int64, __int64))ipahal_parse_stats)(
            0,
            *(_QWORD *)(ipa3_ctx + 43800) + 8LL,
            v45,
            v12);
    if ( v13 )
    {
      v23 = v13;
      printk(&unk_3E0FF4, "ipa_get_quota_stats");
      v37 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v38 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v38 )
        {
          ipc_log_string(v38, "ipa %s:%d failed to parse stats (error %d)\n", "ipa_get_quota_stats", 768, v23);
          v37 = ipa3_ctx;
        }
        v39 = *(_QWORD *)(v37 + 34160);
        if ( v39 )
          ipc_log_string(v39, "ipa %s:%d failed to parse stats (error %d)\n", "ipa_get_quota_stats", 768, v23);
      }
LABEL_32:
      kfree(v12);
      goto LABEL_69;
    }
    v14 = 0;
    while ( 1 )
    {
      v16 = ipa_get_ep_mapping(v14);
      if ( v16 == -1 )
        goto LABEL_20;
      v17 = v16;
      if ( v16 >= (unsigned int)ipa3_get_max_num_pipes() )
        goto LABEL_20;
      if ( (unsigned int)v17 > 0x23 )
        break;
      if ( v14 == *(_DWORD *)(ipa3_ctx + 480LL * v17 + 172) )
      {
        v18 = 32LL * v17;
        v19 = *(_QWORD *)(ipa3_ctx + 43800) + 24LL * v17;
        v20 = v12 + v18;
        *(_QWORD *)(v19 + 16) += *(_QWORD *)(v12 + v18);
        if ( (v18 | 0x10uLL) > 0x480
          || (v21 = *(_QWORD *)(ipa3_ctx + 43800) + 24LL * v17,
              *(_DWORD *)(v21 + 32) += *(_DWORD *)(v20 + 16),
              (v18 | 8uLL) > 0x480)
          || (v22 = *(_QWORD *)(ipa3_ctx + 43800) + 24LL * v17,
              *(_QWORD *)(v22 + 24) += *(_QWORD *)(v20 + 8),
              (v18 | 0x18uLL) > 0x480) )
        {
          __break(1u);
LABEL_29:
          if ( a1 )
            memcpy(a1, (const void *)(*(_QWORD *)(ipa3_ctx + 43800) + 16LL), 0x360u);
          v23 = 0;
          goto LABEL_32;
        }
        v15 = *(_QWORD *)(ipa3_ctx + 43800) + 24LL * v17;
        *(_DWORD *)(v15 + 36) += *(_DWORD *)(v20 + 24);
      }
LABEL_20:
      if ( ++v14 == 134 )
        goto LABEL_29;
    }
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v44 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &ipa_get_quota_stats__alloc_tag;
    v12 = _kmalloc_cache_noprof(__ratelimit, 3520, 1152);
    *(_QWORD *)(StatusReg + 80) = v44;
    if ( v12 )
      continue;
    break;
  }
LABEL_68:
  v23 = -12;
LABEL_69:
  kfree(v53);
  if ( (v9 & 1) == 0 )
    kfree(v54);
LABEL_71:
  dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v47, v45, v46, 0);
  result = v23;
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
