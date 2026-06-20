__int64 __fastcall ipa_get_drop_stats(void *a1)
{
  __int64 v1; // x8
  __int64 v3; // x8
  unsigned int v4; // w0
  __int64 v5; // x0
  int ep_mapping; // w0
  __int64 v7; // x8
  unsigned int v8; // w19
  __int64 v9; // x0
  unsigned int v10; // w19
  unsigned int v11; // w0
  __int64 v12; // x20
  unsigned int v13; // w0
  __int64 v14; // x21
  __int64 v15; // x25
  unsigned int v16; // w0
  signed int v17; // w22
  _DWORD *v18; // x9
  unsigned int v19; // w21
  unsigned int v20; // w19
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 result; // x0
  __int64 v25; // x8
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
  unsigned __int64 StatusReg; // x21
  __int64 v40; // x22
  __int64 (*v41)(_QWORD, _QWORD, const char *, ...); // x0
  __int64 v42; // [xsp+0h] [xbp-130h]
  __int64 v43; // [xsp+8h] [xbp-128h] BYREF
  __int64 v44; // [xsp+10h] [xbp-120h]
  __int64 v45; // [xsp+18h] [xbp-118h] BYREF
  __int64 v46; // [xsp+20h] [xbp-110h]
  __int64 v47; // [xsp+28h] [xbp-108h]
  __int64 v48; // [xsp+30h] [xbp-100h] BYREF
  _QWORD v49[26]; // [xsp+38h] [xbp-F8h] BYREF
  __int64 v50; // [xsp+108h] [xbp-28h] BYREF
  __int64 v51; // [xsp+110h] [xbp-20h]
  _QWORD v52[3]; // [xsp+118h] [xbp-18h] BYREF

  v52[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v1 = *(_QWORD *)(ipa3_ctx + 43800);
  if ( !v1 )
    goto LABEL_41;
  v43 = 0;
  v44 = 0;
  if ( *(_BYTE *)v1 != 1 )
    goto LABEL_41;
  v3 = *(_QWORD *)(v1 + 63896);
  memset(v49, 0, sizeof(v49));
  v50 = 0;
  v51 = 0;
  v52[0] = v3;
  v4 = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64 *))ipahal_stats_get_offset)(3, v52, &v48);
  if ( v4 )
  {
    v20 = v4;
    printk(&unk_3F543B, "ipa_get_drop_stats");
    v21 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_35;
    v22 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v22 )
    {
      ipc_log_string(v22, "ipa %s:%d failed to get offset from hal %d\n", "ipa_get_drop_stats", 2167, v20);
      v21 = ipa3_ctx;
    }
    v23 = *(_QWORD *)(v21 + 34160);
    if ( v23 )
    {
      ipc_log_string(v23, "ipa %s:%d failed to get offset from hal %d\n", "ipa_get_drop_stats", 2167, v20);
      result = v20;
    }
    else
    {
LABEL_35:
      result = v20;
    }
    goto LABEL_42;
  }
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v5 )
      ipc_log_string(v5, "ipa %s:%d offset = %d size = %d\n", "ipa_get_drop_stats", 2171, v48, WORD2(v48));
  }
  if ( !WORD2(v48) )
  {
LABEL_41:
    result = 0;
    goto LABEL_42;
  }
  LODWORD(v44) = WORD2(v48);
  v42 = dma_alloc_attrs(*(_QWORD *)(ipa3_ctx + 34216), WORD2(v48), &v43, 3264, 0);
  if ( !v42 )
  {
    printk(&unk_3DB7B7, "ipa_get_drop_stats");
    v25 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v26 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v26 )
      {
        ipc_log_string(v26, "ipa %s:%d fail to alloc DMA memory\n", "ipa_get_drop_stats", 2182);
        v25 = ipa3_ctx;
      }
      result = *(_QWORD *)(v25 + 34160);
      if ( result )
      {
        ipc_log_string(result, "ipa %s:%d fail to alloc DMA memory\n", "ipa_get_drop_stats", 2182);
        result = 0;
      }
      goto LABEL_42;
    }
    goto LABEL_41;
  }
  ep_mapping = ipa_get_ep_mapping(95);
  v7 = ipa3_ctx;
  if ( ep_mapping == -1 || (*(_BYTE *)(ipa3_ctx + 51242) & 1) != 0 )
  {
    v8 = 0;
  }
  else
  {
    ipa_close_coal_frame(&v50);
    if ( !v50 )
    {
      printk(&unk_3AEDE8, "ipa_get_drop_stats");
      v36 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v37 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v37 )
        {
          ipc_log_string(v37, "ipa %s:%d failed to construct coal close IC\n", "ipa_get_drop_stats", 2191);
          v36 = ipa3_ctx;
        }
        v38 = *(_QWORD *)(v36 + 34160);
        if ( v38 )
          ipc_log_string(v38, "ipa %s:%d failed to construct coal close IC\n", "ipa_get_drop_stats", 2191);
      }
      v19 = -12;
      goto LABEL_71;
    }
    ipa3_init_imm_cmd_desc(v49, v50);
    v7 = ipa3_ctx;
    v8 = 1;
  }
  BYTE2(v47) = 0;
  LOWORD(v47) = 257;
  HIDWORD(v47) = 0;
  LODWORD(v46) = v44;
  v45 = v43;
  HIDWORD(v46) = *(_DWORD *)(**(_QWORD **)(v7 + 34176) + 368LL) + *(unsigned __int16 *)(v7 + 29522) + (_DWORD)v48;
  v9 = ((__int64 (__fastcall *)(__int64, __int64 *, _QWORD))ipahal_construct_imm_cmd)(11, &v45, 0);
  *(&v50 + v8) = v9;
  if ( !v9 )
  {
    printk(&unk_3A8EB0, "ipa_get_drop_stats");
    v27 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v28 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v28 )
      {
        ipc_log_string(v28, "ipa %s:%d failed to construct dma_shared_mem imm cmd\n", "ipa_get_drop_stats", 2210);
        v27 = ipa3_ctx;
      }
      v29 = *(_QWORD *)(v27 + 34160);
      if ( v29 )
        ipc_log_string(v29, "ipa %s:%d failed to construct dma_shared_mem imm cmd\n", "ipa_get_drop_stats", 2210);
    }
    v19 = -12;
    if ( v8 )
    {
      v10 = 1;
      goto LABEL_69;
    }
    goto LABEL_71;
  }
  ipa3_init_imm_cmd_desc(&v49[13 * v8], v9);
  v10 = v8 + 1;
  v11 = ((__int64 (__fastcall *)(_QWORD, _QWORD *))ipa3_send_cmd)(v10, v49);
  if ( v11 )
  {
    v19 = v11;
    printk(&unk_3B18DA, "ipa_get_drop_stats");
    v30 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v31 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v31 )
      {
        ipc_log_string(v31, "ipa %s:%d failed to send immediate command (error %d)\n", "ipa_get_drop_stats", 2219, v19);
        v30 = ipa3_ctx;
      }
      v32 = *(_QWORD *)(v30 + 34160);
      if ( v32 )
        ipc_log_string(v32, "ipa %s:%d failed to send immediate command (error %d)\n", "ipa_get_drop_stats", 2219, v19);
    }
    goto LABEL_69;
  }
  v12 = _kmalloc_cache_noprof(scnprintf, 3520, 288);
  if ( !v12 )
    goto LABEL_68;
  while ( 2 )
  {
    v13 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64))ipahal_parse_stats)(
            3,
            *(_QWORD *)(ipa3_ctx + 43800) + 63896LL,
            v42,
            v12);
    if ( v13 )
    {
      v19 = v13;
      printk(&unk_3E0FF4, "ipa_get_drop_stats");
      v33 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v34 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v34 )
        {
          ipc_log_string(v34, "ipa %s:%d failed to parse stats (error %d)\n", "ipa_get_drop_stats", 2232, v19);
          v33 = ipa3_ctx;
        }
        v35 = *(_QWORD *)(v33 + 34160);
        if ( v35 )
          ipc_log_string(v35, "ipa %s:%d failed to parse stats (error %d)\n", "ipa_get_drop_stats", 2232, v19);
      }
LABEL_29:
      kfree(v12);
      goto LABEL_69;
    }
    v14 = 0;
    v15 = 63908;
    while ( 1 )
    {
      v16 = ipa_get_ep_mapping((unsigned int)v14);
      if ( v16 == -1 )
        goto LABEL_19;
      v17 = v16;
      if ( v16 >= (unsigned int)ipa3_get_max_num_pipes() )
        goto LABEL_19;
      if ( (unsigned int)v17 > 0x23 )
        break;
      if ( v14 == *(_DWORD *)(ipa3_ctx + 480LL * v17 + 172) )
      {
        if ( ((8LL * v17) | 4uLL) > 0x120 )
          goto LABEL_67;
        v18 = (_DWORD *)(v12 + 8LL * v17);
        *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43800) + v15) += v18[1];
        *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 43800) + v15 - 4) += *v18;
      }
LABEL_19:
      ++v14;
      v15 += 8;
      if ( v14 == 134 )
      {
        if ( a1 )
          memcpy(a1, (const void *)(*(_QWORD *)(ipa3_ctx + 43800) + 63904LL), 0x430u);
        v19 = 0;
        goto LABEL_29;
      }
    }
    __break(0x5512u);
LABEL_67:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v40 = *(_QWORD *)(StatusReg + 80);
    v41 = scnprintf;
    *(_QWORD *)(StatusReg + 80) = &ipa_get_drop_stats__alloc_tag;
    v12 = _kmalloc_cache_noprof(v41, 3520, 288);
    *(_QWORD *)(StatusReg + 80) = v40;
    if ( v12 )
      continue;
    break;
  }
LABEL_68:
  v19 = -12;
LABEL_69:
  kfree(v50);
  if ( v10 != 1 )
    kfree(v51);
LABEL_71:
  dma_free_attrs(*(_QWORD *)(ipa3_ctx + 34216), (unsigned int)v44, v42, v43, 0);
  result = v19;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
