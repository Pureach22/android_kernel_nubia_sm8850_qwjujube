__int64 __fastcall _ipa_validate_flt_rule(__int64 a1, __int64 *a2, int a3)
{
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  int v13; // w20
  int v14; // w8
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  unsigned int v24; // w20
  unsigned int v25; // w20
  __int64 result; // x0
  __int64 is_rule_cnt_id_valid; // x0
  __int64 v28; // x1
  __int64 v29; // x2
  __int64 v30; // x3
  __int64 v31; // x4
  unsigned __int64 v32; // x8
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x8
  __int64 v37; // x20
  int v38; // w21
  int v39; // w0
  __int64 v40; // x20
  int v41; // w19
  int v42; // w0
  __int64 v43; // x8
  __int64 v44; // x0
  unsigned int *v45; // x8
  __int64 v46; // x0
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x8
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x0

  v3 = a1;
  if ( *(_DWORD *)(a1 + 4) == 3 )
  {
    if ( *(_DWORD *)(a1 + 348) )
    {
      if ( (unsigned int)__ratelimit(&_ipa_validate_flt_rule__rs_186, "__ipa_validate_flt_rule") )
        printk(&unk_3D2B59, "__ipa_validate_flt_rule");
      v4 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v5 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v5 )
        {
          ipc_log_string(v5, "ipa %s:%d invalid RT tbl\n", "__ipa_validate_flt_rule", 905);
          v4 = ipa3_ctx;
        }
        v6 = *(_QWORD *)(v4 + 34160);
        if ( v6 )
          ipc_log_string(v6, "ipa %s:%d invalid RT tbl\n", "__ipa_validate_flt_rule", 905);
      }
      return 0xFFFFFFFFLL;
    }
  }
  else if ( *(_BYTE *)(a1 + 352) )
  {
    v7 = 104;
    if ( !a3 )
      v7 = 60;
    if ( *(_DWORD *)(a1 + 348) > *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + v7) )
    {
      if ( (unsigned int)__ratelimit(&_ipa_validate_flt_rule__rs_185, "__ipa_validate_flt_rule") )
      {
        printk(&unk_3D2B59, "__ipa_validate_flt_rule");
        v8 = ipa3_ctx;
        if ( !ipa3_ctx )
          return 0xFFFFFFFFLL;
      }
      else
      {
        v8 = ipa3_ctx;
        if ( !ipa3_ctx )
          return 0xFFFFFFFFLL;
      }
      v9 = *(_QWORD *)(v8 + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d invalid RT tbl\n", "__ipa_validate_flt_rule", 899);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
        ipc_log_string(v10, "ipa %s:%d invalid RT tbl\n", "__ipa_validate_flt_rule", 899);
      return 0xFFFFFFFFLL;
    }
  }
  else
  {
    v11 = *(unsigned int *)(a1 + 8);
    if ( !(_DWORD)v11 )
    {
      if ( (unsigned int)__ratelimit(&_ipa_validate_flt_rule__rs, "__ipa_validate_flt_rule") )
        printk(&unk_3D2B59, "__ipa_validate_flt_rule");
      v18 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v19 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v19 )
        {
          ipc_log_string(v19, "ipa %s:%d invalid RT tbl\n", "__ipa_validate_flt_rule", 881);
          v18 = ipa3_ctx;
        }
        v20 = *(_QWORD *)(v18 + 34160);
        if ( v20 )
          ipc_log_string(v20, "ipa %s:%d invalid RT tbl\n", "__ipa_validate_flt_rule", 881);
      }
      return 0xFFFFFFFFLL;
    }
    a1 = ipa3_id_find(v11);
    *a2 = a1;
    if ( !a1 )
    {
      if ( (unsigned int)__ratelimit(&_ipa_validate_flt_rule__rs_179, "__ipa_validate_flt_rule") )
        printk(&unk_3D8791, "__ipa_validate_flt_rule");
      v21 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v22 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v22 )
        {
          ipc_log_string(v22, "ipa %s:%d RT tbl not found\n", "__ipa_validate_flt_rule", 887);
          v21 = ipa3_ctx;
        }
        v23 = *(_QWORD *)(v21 + 34160);
        if ( v23 )
          ipc_log_string(v23, "ipa %s:%d RT tbl not found\n", "__ipa_validate_flt_rule", 887);
      }
      return 0xFFFFFFFFLL;
    }
    if ( *(_DWORD *)(a1 + 16) != 1468208645 )
    {
      if ( (unsigned int)__ratelimit(&_ipa_validate_flt_rule__rs_182, "__ipa_validate_flt_rule") )
        printk(&unk_3E6641, "__ipa_validate_flt_rule");
      v47 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v48 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v48 )
        {
          ipc_log_string(v48, "ipa %s:%d RT table cookie is invalid\n", "__ipa_validate_flt_rule", 892);
          v47 = ipa3_ctx;
        }
        v49 = *(_QWORD *)(v47 + 34160);
        if ( v49 )
          ipc_log_string(v49, "ipa %s:%d RT table cookie is invalid\n", "__ipa_validate_flt_rule", 892);
      }
      return 0xFFFFFFFFLL;
    }
  }
  if ( *(_DWORD *)(ipa3_ctx + 32240) < 0xEu || !*(_BYTE *)(v3 + 359) )
  {
LABEL_48:
    if ( *(_WORD *)(v3 + 356) )
    {
      v24 = *(unsigned __int16 *)(v3 + 356);
      if ( (unsigned int)((__int64 (*)(void))ipahal_get_rule_id_hi_bit)() > v24
        || (v25 = *(unsigned __int16 *)(v3 + 356),
            2 * (unsigned int)((__int64 (*)(void))ipahal_get_rule_id_hi_bit)() - 1 <= v25) )
      {
        if ( (unsigned int)__ratelimit(&_ipa_validate_flt_rule__rs_193, "__ipa_validate_flt_rule") )
        {
          ((void (*)(void))ipahal_get_rule_id_hi_bit)();
          printk(&unk_3A6D1B, "__ipa_validate_flt_rule");
          v36 = ipa3_ctx;
          if ( !ipa3_ctx )
            return 0xFFFFFFFFLL;
        }
        else
        {
          v36 = ipa3_ctx;
          if ( !ipa3_ctx )
            return 0xFFFFFFFFLL;
        }
        v37 = *(_QWORD *)(v36 + 34152);
        if ( v37 )
        {
          v38 = *(unsigned __int16 *)(v3 + 356);
          v39 = ((__int64 (*)(void))ipahal_get_rule_id_hi_bit)();
          ipc_log_string(
            v37,
            "ipa %s:%d invalid rule_id provided 0x%x\nrule_id with bit 0x%x are auto generated\n",
            "__ipa_validate_flt_rule",
            932,
            v38,
            v39);
          v36 = ipa3_ctx;
        }
        v40 = *(_QWORD *)(v36 + 34160);
        if ( v40 )
        {
          v41 = *(unsigned __int16 *)(v3 + 356);
          v42 = ((__int64 (*)(void))ipahal_get_rule_id_hi_bit)();
          ipc_log_string(
            v40,
            "ipa %s:%d invalid rule_id provided 0x%x\nrule_id with bit 0x%x are auto generated\n",
            "__ipa_validate_flt_rule",
            932,
            v41,
            v42);
        }
        return 0xFFFFFFFFLL;
      }
    }
    if ( *(_DWORD *)(ipa3_ctx + 32240) < 0x11u )
    {
      if ( *(_BYTE *)(v3 + 360) )
      {
        if ( (unsigned int)__ratelimit(&_ipa_validate_flt_rule__rs_202, "__ipa_validate_flt_rule") )
        {
          printk(&unk_3AF9AA, "__ipa_validate_flt_rule");
          v43 = ipa3_ctx;
          if ( !ipa3_ctx )
            return 0xFFFFFFFFLL;
        }
        else
        {
          v43 = ipa3_ctx;
          if ( !ipa3_ctx )
            return 0xFFFFFFFFLL;
        }
        v44 = *(_QWORD *)(v43 + 34152);
        if ( v44 )
        {
          ipc_log_string(
            v44,
            "ipa %s:%d enable_stats won't support on ipa_hw_type %d\n",
            "__ipa_validate_flt_rule",
            957,
            *(_DWORD *)(v43 + 32240));
          v43 = ipa3_ctx;
        }
        v45 = (unsigned int *)(v43 + 32240);
        v46 = *((_QWORD *)v45 + 240);
        if ( v46 )
          ipc_log_string(
            v46,
            "ipa %s:%d enable_stats won't support on ipa_hw_type %d\n",
            "__ipa_validate_flt_rule",
            957,
            *v45);
        return 0xFFFFFFFFLL;
      }
    }
    else if ( *(_BYTE *)(v3 + 360) )
    {
      result = *(unsigned __int8 *)(v3 + 361);
      if ( !*(_BYTE *)(v3 + 361) )
        return result;
      is_rule_cnt_id_valid = ipahal_is_rule_cnt_id_valid();
      if ( (is_rule_cnt_id_valid & 1) == 0 )
      {
        if ( (unsigned int)__ratelimit(&_ipa_validate_flt_rule__rs_196, "__ipa_validate_flt_rule") )
        {
          printk(&unk_3FB430, "__ipa_validate_flt_rule");
          v53 = ipa3_ctx;
          if ( !ipa3_ctx )
            return 0xFFFFFFFFLL;
        }
        else
        {
          v53 = ipa3_ctx;
          if ( !ipa3_ctx )
            return 0xFFFFFFFFLL;
        }
        v54 = *(_QWORD *)(v53 + 34152);
        if ( v54 )
        {
          ipc_log_string(
            v54,
            "ipa %s:%d invalid cnt_idx %hhu out of range\n",
            "__ipa_validate_flt_rule",
            942,
            *(unsigned __int8 *)(v3 + 361));
          v53 = ipa3_ctx;
        }
        v55 = *(_QWORD *)(v53 + 34160);
        if ( v55 )
          ipc_log_string(
            v55,
            "ipa %s:%d invalid cnt_idx %hhu out of range\n",
            "__ipa_validate_flt_rule",
            942,
            *(unsigned __int8 *)(v3 + 361));
        return 0xFFFFFFFFLL;
      }
      v32 = *(unsigned __int8 *)(v3 + 361) - 1LL;
      if ( v32 >= 0x18 )
      {
        __break(0x5512u);
        return _ipa_create_flt_entry(is_rule_cnt_id_valid, v28, v29, v30, v31);
      }
      if ( (*(_BYTE *)(ipa3_ctx + v32 + 43832) & 1) == 0 )
      {
        if ( (unsigned int)__ratelimit(&_ipa_validate_flt_rule__rs_199, "__ipa_validate_flt_rule") )
        {
          printk(&unk_3ACBEE, "__ipa_validate_flt_rule");
          v33 = ipa3_ctx;
          if ( !ipa3_ctx )
            return 0xFFFFFFFFLL;
        }
        else
        {
          v33 = ipa3_ctx;
          if ( !ipa3_ctx )
            return 0xFFFFFFFFLL;
        }
        v34 = *(_QWORD *)(v33 + 34152);
        if ( v34 )
        {
          ipc_log_string(
            v34,
            "ipa %s:%d invalid cnt_idx %hhu not alloc by driver\n",
            "__ipa_validate_flt_rule",
            949,
            *(unsigned __int8 *)(v3 + 361));
          v33 = ipa3_ctx;
        }
        v35 = *(_QWORD *)(v33 + 34160);
        if ( v35 )
          ipc_log_string(
            v35,
            "ipa %s:%d invalid cnt_idx %hhu not alloc by driver\n",
            "__ipa_validate_flt_rule",
            949,
            *(unsigned __int8 *)(v3 + 361));
        return 0xFFFFFFFFLL;
      }
    }
    return 0;
  }
  v14 = *(_DWORD *)(v3 + 4);
  if ( v14 != 3 && v14 )
  {
    v13 = *(unsigned __int8 *)(v3 + 359);
    if ( (int)ipa3_get_max_pdn(a1) <= v13 )
    {
      if ( (unsigned int)__ratelimit(&_ipa_validate_flt_rule__rs_190, "__ipa_validate_flt_rule") )
      {
        printk(&unk_3C3F9E, "__ipa_validate_flt_rule");
        v50 = ipa3_ctx;
        if ( !ipa3_ctx )
          return 0xFFFFFFFFLL;
      }
      else
      {
        v50 = ipa3_ctx;
        if ( !ipa3_ctx )
          return 0xFFFFFFFFLL;
      }
      v51 = *(_QWORD *)(v50 + 34152);
      if ( v51 )
      {
        ipc_log_string(
          v51,
          "ipa %s:%d PDN index %d is too large\n",
          "__ipa_validate_flt_rule",
          920,
          *(unsigned __int8 *)(v3 + 359));
        v50 = ipa3_ctx;
      }
      v52 = *(_QWORD *)(v50 + 34160);
      if ( v52 )
        ipc_log_string(
          v52,
          "ipa %s:%d PDN index %d is too large\n",
          "__ipa_validate_flt_rule",
          920,
          *(unsigned __int8 *)(v3 + 359));
      return 0xFFFFFFFFLL;
    }
    goto LABEL_48;
  }
  if ( (unsigned int)__ratelimit(&_ipa_validate_flt_rule__rs_187, "__ipa_validate_flt_rule") )
  {
    printk(&unk_3C9B9E, "__ipa_validate_flt_rule");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
      goto LABEL_29;
  }
  else
  {
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
LABEL_29:
      v16 = *(_QWORD *)(v15 + 34152);
      if ( v16 )
      {
        ipc_log_string(
          v16,
          "ipa %s:%d PDN index should be 0 when action is not pass to NAT\n",
          "__ipa_validate_flt_rule",
          915);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
        ipc_log_string(
          v17,
          "ipa %s:%d PDN index should be 0 when action is not pass to NAT\n",
          "__ipa_validate_flt_rule",
          915);
    }
  }
  return 0xFFFFFFFFLL;
}
