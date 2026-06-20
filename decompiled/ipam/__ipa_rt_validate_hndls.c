__int64 __fastcall _ipa_rt_validate_hndls(__int64 a1, __int64 *a2, __int64 *a3)
{
  __int64 v4; // x0
  unsigned int v5; // w8
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 result; // x0
  __int64 is_rule_cnt_id_valid; // x0
  __int64 v24; // x1
  __int64 v25; // x2
  __int64 v26; // x3
  __int64 v27; // x4
  __int64 v28; // x5
  __int64 v29; // x6
  unsigned __int64 v30; // x8
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x8
  __int64 v35; // x0
  unsigned int *v36; // x8
  __int64 v37; // x0
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x0

  v4 = *(unsigned int *)(a1 + 4);
  v5 = *(_DWORD *)(a1 + 8);
  if ( (_DWORD)v4 )
  {
    if ( v5 )
    {
      if ( (unsigned int)__ratelimit(&_ipa_rt_validate_hndls__rs, "__ipa_rt_validate_hndls") )
        printk(&unk_3B2C25, "__ipa_rt_validate_hndls");
      v6 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v7 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v7 )
        {
          ipc_log_string(
            v7,
            "ipa %s:%d rule contains both hdr_hdl and hdr_proc_ctx_hdl\n",
            "__ipa_rt_validate_hndls",
            995);
          v6 = ipa3_ctx;
        }
        v8 = *(_QWORD *)(v6 + 34160);
        if ( v8 )
          ipc_log_string(
            v8,
            "ipa %s:%d rule contains both hdr_hdl and hdr_proc_ctx_hdl\n",
            "__ipa_rt_validate_hndls",
            995);
      }
      return 0xFFFFFFFFLL;
    }
    v15 = ipa3_id_find(v4);
    *a2 = v15;
    if ( !v15 || *(_DWORD *)(v15 + 16) != 1468208647 )
    {
      if ( (unsigned int)__ratelimit(&_ipa_rt_validate_hndls__rs_201, "__ipa_rt_validate_hndls") )
        printk(&unk_3C47EC, "__ipa_rt_validate_hndls");
      v19 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v20 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v20 )
        {
          ipc_log_string(v20, "ipa %s:%d rt rule does not point to valid hdr\n", "__ipa_rt_validate_hndls", 1002);
          v19 = ipa3_ctx;
        }
        v21 = *(_QWORD *)(v19 + 34160);
        if ( v21 )
          ipc_log_string(v21, "ipa %s:%d rt rule does not point to valid hdr\n", "__ipa_rt_validate_hndls", 1002);
      }
      return 0xFFFFFFFFLL;
    }
  }
  else if ( v5 )
  {
    v10 = ipa3_id_find(v5);
    *a3 = v10;
    if ( !v10 || *(_DWORD *)(v10 + 16) != 1468208648 )
    {
      if ( (unsigned int)__ratelimit(&_ipa_rt_validate_hndls__rs_204, "__ipa_rt_validate_hndls") )
        printk(&unk_3E4202, "__ipa_rt_validate_hndls");
      v11 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v12 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v12 )
        {
          ipc_log_string(v12, "ipa %s:%d rt rule does not point to valid proc ctx\n", "__ipa_rt_validate_hndls", 1010);
          v11 = ipa3_ctx;
        }
        v13 = *(_QWORD *)(v11 + 34160);
        if ( v13 )
          ipc_log_string(v13, "ipa %s:%d rt rule does not point to valid proc ctx\n", "__ipa_rt_validate_hndls", 1010);
      }
      return 0xFFFFFFFFLL;
    }
  }
  if ( *(_DWORD *)(ipa3_ctx + 32240) > 0x10u )
  {
    if ( *(_BYTE *)(a1 + 168) )
    {
      result = *(unsigned __int8 *)(a1 + 169);
      if ( !*(_BYTE *)(a1 + 169) )
        return result;
      is_rule_cnt_id_valid = ipahal_is_rule_cnt_id_valid();
      if ( (is_rule_cnt_id_valid & 1) == 0 )
      {
        if ( (unsigned int)__ratelimit(&_ipa_rt_validate_hndls__rs_210, "__ipa_rt_validate_hndls") )
        {
          printk(&unk_3FB430, "__ipa_rt_validate_hndls");
          v38 = ipa3_ctx;
          if ( !ipa3_ctx )
            return 0xFFFFFFFFLL;
        }
        else
        {
          v38 = ipa3_ctx;
          if ( !ipa3_ctx )
            return 0xFFFFFFFFLL;
        }
        v39 = *(_QWORD *)(v38 + 34152);
        if ( v39 )
        {
          ipc_log_string(
            v39,
            "ipa %s:%d invalid cnt_idx %hhu out of range\n",
            "__ipa_rt_validate_hndls",
            1025,
            *(unsigned __int8 *)(a1 + 169));
          v38 = ipa3_ctx;
        }
        v40 = *(_QWORD *)(v38 + 34160);
        if ( v40 )
          ipc_log_string(
            v40,
            "ipa %s:%d invalid cnt_idx %hhu out of range\n",
            "__ipa_rt_validate_hndls",
            1025,
            *(unsigned __int8 *)(a1 + 169));
        return 0xFFFFFFFFLL;
      }
      v30 = *(unsigned __int8 *)(a1 + 169) - 1LL;
      if ( v30 >= 0x18 )
      {
        __break(0x5512u);
        return _ipa_create_rt_entry(is_rule_cnt_id_valid, v24, v25, v26, v27, v28, v29);
      }
      if ( (*(_BYTE *)(ipa3_ctx + v30 + 43832) & 1) == 0 )
      {
        if ( (unsigned int)__ratelimit(&_ipa_rt_validate_hndls__rs_213, "__ipa_rt_validate_hndls") )
        {
          printk(&unk_3ACBEE, "__ipa_rt_validate_hndls");
          v31 = ipa3_ctx;
          if ( !ipa3_ctx )
            return 0xFFFFFFFFLL;
        }
        else
        {
          v31 = ipa3_ctx;
          if ( !ipa3_ctx )
            return 0xFFFFFFFFLL;
        }
        v32 = *(_QWORD *)(v31 + 34152);
        if ( v32 )
        {
          ipc_log_string(
            v32,
            "ipa %s:%d invalid cnt_idx %hhu not alloc by driver\n",
            "__ipa_rt_validate_hndls",
            1032,
            *(unsigned __int8 *)(a1 + 169));
          v31 = ipa3_ctx;
        }
        v33 = *(_QWORD *)(v31 + 34160);
        if ( v33 )
          ipc_log_string(
            v33,
            "ipa %s:%d invalid cnt_idx %hhu not alloc by driver\n",
            "__ipa_rt_validate_hndls",
            1032,
            *(unsigned __int8 *)(a1 + 169));
        return 0xFFFFFFFFLL;
      }
    }
    return 0;
  }
  if ( !*(_BYTE *)(a1 + 167) )
  {
    if ( *(_BYTE *)(a1 + 168) )
    {
      if ( (unsigned int)__ratelimit(&_ipa_rt_validate_hndls__rs_216, "__ipa_rt_validate_hndls") )
      {
        printk(&unk_3AF9AA, "__ipa_rt_validate_hndls");
        v34 = ipa3_ctx;
        if ( !ipa3_ctx )
          return 0xFFFFFFFFLL;
      }
      else
      {
        v34 = ipa3_ctx;
        if ( !ipa3_ctx )
          return 0xFFFFFFFFLL;
      }
      v35 = *(_QWORD *)(v34 + 34152);
      if ( v35 )
      {
        ipc_log_string(
          v35,
          "ipa %s:%d enable_stats won't support on ipa_hw_type %d\n",
          "__ipa_rt_validate_hndls",
          1040,
          *(_DWORD *)(v34 + 32240));
        v34 = ipa3_ctx;
      }
      v36 = (unsigned int *)(v34 + 32240);
      v37 = *((_QWORD *)v36 + 240);
      if ( v37 )
        ipc_log_string(
          v37,
          "ipa %s:%d enable_stats won't support on ipa_hw_type %d\n",
          "__ipa_rt_validate_hndls",
          1040,
          *v36);
      return 0xFFFFFFFFLL;
    }
    return 0;
  }
  if ( (unsigned int)__ratelimit(&_ipa_rt_validate_hndls__rs_207, "__ipa_rt_validate_hndls") )
  {
    printk(&unk_3BB94A, "__ipa_rt_validate_hndls");
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
      goto LABEL_26;
  }
  else
  {
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
LABEL_26:
      v17 = *(_QWORD *)(v16 + 34152);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d rt rule should not allow coalescing\n", "__ipa_rt_validate_hndls", 1016);
        v16 = ipa3_ctx;
      }
      v18 = *(_QWORD *)(v16 + 34160);
      if ( v18 )
        ipc_log_string(v18, "ipa %s:%d rt rule should not allow coalescing\n", "__ipa_rt_validate_hndls", 1016);
    }
  }
  return 0xFFFFFFFFLL;
}
