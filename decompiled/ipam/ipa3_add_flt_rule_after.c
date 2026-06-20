__int64 __fastcall ipa3_add_flt_rule_after(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int v9; // w19
  unsigned int v10; // w20
  __int64 max_num_pipes; // x0
  __int64 v12; // x1
  unsigned int v13; // w22
  __int64 v14; // x23
  __int64 v15; // x0
  __int64 v16; // x21
  __int64 v17; // x8
  __int64 v18; // x20
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  unsigned __int64 v34; // x21
  __int64 v35; // x25
  int v36; // w8
  __int64 v37; // x3
  int v38; // w26
  __int64 v39; // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  unsigned int (__fastcall *v43)(_QWORD); // x8
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // [xsp+0h] [xbp-190h] BYREF
  unsigned int v51; // [xsp+Ch] [xbp-184h] BYREF
  _QWORD s[48]; // [xsp+10h] [xbp-180h] BYREF

  s[46] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x170u);
  if ( !a1 || !*(_BYTE *)(a1 + 12) || *(_DWORD *)(a1 + 4) >= 2u )
  {
    if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_after__rs, "ipa3_add_flt_rule_after") )
    {
      printk(&unk_3FB3F2, "ipa3_add_flt_rule_after");
      v2 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_6;
    }
    else
    {
      v2 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_6:
        v3 = *(_QWORD *)(v2 + 34152);
        if ( v3 )
        {
          ipc_log_string(v3, "ipa %s:%d bad parm\n", "ipa3_add_flt_rule_after", 1493);
          v2 = ipa3_ctx;
        }
        v4 = *(_QWORD *)(v2 + 34160);
        if ( v4 )
          ipc_log_string(v4, "ipa %s:%d bad parm\n", "ipa3_add_flt_rule_after", 1493);
      }
    }
LABEL_10:
    result = 4294967274LL;
LABEL_11:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( *(_DWORD *)(a1 + 8) >= 0x86u )
  {
    if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_after__rs_32, "ipa3_add_flt_rule_after") )
    {
      printk(&unk_3F52A9, "ipa3_add_flt_rule_after");
      v6 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_10;
    }
    else
    {
      v6 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_10;
    }
    v7 = *(_QWORD *)(v6 + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d bad parms ep=%d\n", "ipa3_add_flt_rule_after", 1498, *(_DWORD *)(a1 + 8));
      v6 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v6 + 34160);
    if ( v8 )
      ipc_log_string(v8, "ipa %s:%d bad parms ep=%d\n", "ipa3_add_flt_rule_after", 1498, *(_DWORD *)(a1 + 8));
    goto LABEL_10;
  }
  v51 = 0;
  mutex_lock(ipa3_ctx + 29472);
  if ( (unsigned int)_ipa_add_flt_get_ep_idx(*(unsigned int *)(a1 + 8), &v51) )
    goto LABEL_20;
  v10 = v51;
  max_num_pipes = ipa3_get_max_num_pipes();
  if ( (v10 & 0x80000000) != 0 || v10 >= (unsigned int)max_num_pipes )
  {
    if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_after__rs_35, "ipa3_add_flt_rule_after") )
    {
      printk(&unk_3EF10D, "ipa3_add_flt_rule_after");
      v22 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_20;
    }
    else
    {
      v22 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_20;
    }
    v23 = *(_QWORD *)(v22 + 34152);
    if ( v23 )
    {
      ipc_log_string(v23, "ipa %s:%d invalid ipa_ep_idx=%u\n", "ipa3_add_flt_rule_after", 1510, v10);
      v22 = ipa3_ctx;
    }
    v24 = *(_QWORD *)(v22 + 34160);
    if ( v24 )
      ipc_log_string(v24, "ipa %s:%d invalid ipa_ep_idx=%u\n", "ipa3_add_flt_rule_after", 1510, v10);
    goto LABEL_20;
  }
  if ( v10 < 0x24 )
  {
    v13 = *(_DWORD *)(a1 + 4);
    if ( v13 <= 2 )
    {
      v14 = ipa3_ctx;
      v15 = ipa3_id_find(*(unsigned int *)(a1 + 16));
      v50 = v15;
      if ( !v15 )
      {
        if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_after__rs_38, "ipa3_add_flt_rule_after") )
        {
          printk(&unk_3DE445, "ipa3_add_flt_rule_after");
          v25 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_20;
        }
        else
        {
          v25 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_20;
        }
        v26 = *(_QWORD *)(v25 + 34152);
        if ( v26 )
        {
          ipc_log_string(v26, "ipa %s:%d lookup failed\n", "ipa3_add_flt_rule_after", 1519);
          v25 = ipa3_ctx;
        }
        v27 = *(_QWORD *)(v25 + 34160);
        if ( v27 )
          ipc_log_string(v27, "ipa %s:%d lookup failed\n", "ipa3_add_flt_rule_after", 1519);
        goto LABEL_20;
      }
      v16 = v15;
      if ( *(_DWORD *)(v15 + 16) != 1468208646 )
      {
        if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_after__rs_41, "ipa3_add_flt_rule_after") )
        {
          printk(&unk_3DB627, "ipa3_add_flt_rule_after");
          v28 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_20;
        }
        else
        {
          v28 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_20;
        }
        v29 = *(_QWORD *)(v28 + 34152);
        if ( v29 )
        {
          ipc_log_string(
            v29,
            "ipa %s:%d Invalid cookie value =  %u flt hdl id = %d\n",
            "ipa3_add_flt_rule_after",
            1526,
            *(_DWORD *)(v16 + 16),
            *(_DWORD *)(a1 + 16));
          v28 = ipa3_ctx;
        }
        v30 = *(_QWORD *)(v28 + 34160);
        if ( v30 )
          ipc_log_string(
            v30,
            "ipa %s:%d Invalid cookie value =  %u flt hdl id = %d\n",
            "ipa3_add_flt_rule_after",
            1526,
            *(_DWORD *)(v16 + 16),
            *(_DWORD *)(a1 + 16));
        goto LABEL_20;
      }
      v17 = v14 + 304LL * v10 + 152LL * v13;
      v18 = v17 + 17640;
      if ( *(_QWORD *)(v15 + 392) != v17 + 17640 )
      {
        if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_after__rs_44, "ipa3_add_flt_rule_after") )
        {
          printk(&unk_3B22CA, "ipa3_add_flt_rule_after");
          v19 = ipa3_ctx;
          if ( ipa3_ctx )
            goto LABEL_33;
        }
        else
        {
          v19 = ipa3_ctx;
          if ( ipa3_ctx )
          {
LABEL_33:
            v20 = *(_QWORD *)(v19 + 34152);
            if ( v20 )
            {
              ipc_log_string(v20, "ipa %s:%d given entry does not match the table\n", "ipa3_add_flt_rule_after", 1532);
              v19 = ipa3_ctx;
            }
            v21 = *(_QWORD *)(v19 + 34160);
            if ( v21 )
              ipc_log_string(v21, "ipa %s:%d given entry does not match the table\n", "ipa3_add_flt_rule_after", 1532);
          }
        }
LABEL_20:
        v9 = -22;
LABEL_21:
        mutex_unlock(ipa3_ctx + 29472);
        result = v9;
        goto LABEL_11;
      }
      if ( *(_BYTE *)(v17 + 17768) == 1 && v15 == *(_QWORD *)(v17 + 17648) )
      {
        if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_after__rs_47, "ipa3_add_flt_rule_after") )
        {
          printk(&unk_3D8686, "ipa3_add_flt_rule_after");
          v44 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_20;
        }
        else
        {
          v44 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_20;
        }
        v45 = *(_QWORD *)(v44 + 34152);
        if ( v45 )
        {
          ipc_log_string(v45, "ipa %s:%d cannot add rule at end of a sticky table", "ipa3_add_flt_rule_after", 1539);
          v44 = ipa3_ctx;
        }
        v46 = *(_QWORD *)(v44 + 34160);
        if ( v46 )
          ipc_log_string(v46, "ipa %s:%d cannot add rule at end of a sticky table", "ipa3_add_flt_rule_after", 1539);
        goto LABEL_20;
      }
      v31 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v32 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v32 )
        {
          ipc_log_string(
            v32,
            "ipa %s:%d add ep flt rule ip=%d ep=%d after hdl %d\n",
            "ipa3_add_flt_rule_after",
            1545,
            *(_DWORD *)(a1 + 4),
            *(_DWORD *)(a1 + 8),
            *(_DWORD *)(a1 + 16));
          v31 = ipa3_ctx;
        }
        v33 = *(_QWORD *)(v31 + 34160);
        if ( v33 )
          ipc_log_string(
            v33,
            "ipa %s:%d add ep flt rule ip=%d ep=%d after hdl %d\n",
            "ipa3_add_flt_rule_after",
            1545,
            *(_DWORD *)(a1 + 4),
            *(_DWORD *)(a1 + 8),
            *(_DWORD *)(a1 + 16));
      }
      if ( !*(_BYTE *)(a1 + 12) )
      {
LABEL_80:
        if ( !*(_BYTE *)a1 )
          goto LABEL_84;
        v42 = *(unsigned int *)(a1 + 4);
        v43 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 112LL);
        if ( *((_DWORD *)v43 - 1) != 1856640366 )
          __break(0x8228u);
        if ( v43(v42) )
        {
          printk(&unk_3C0DC4, "ipa3_add_flt_rule_after");
          v47 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v48 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v48 )
            {
              ipc_log_string(v48, "ipa %s:%d failed to commit flt rules\n", "ipa3_add_flt_rule_after", 1580);
              v47 = ipa3_ctx;
            }
            v49 = *(_QWORD *)(v47 + 34160);
            if ( v49 )
              ipc_log_string(v49, "ipa %s:%d failed to commit flt rules\n", "ipa3_add_flt_rule_after", 1580);
          }
          v9 = -1;
        }
        else
        {
LABEL_84:
          v9 = 0;
        }
        goto LABEL_21;
      }
      v34 = 0;
      v35 = a1;
      while ( 1 )
      {
        if ( *(_BYTE *)(ipa3_ctx + 32270) == 1 )
          *(_BYTE *)(v35 + 374) = 0;
        memcpy(s, (const void *)(v35 + 20), 0x168u);
        v37 = *(unsigned int *)(a1 + 4);
        s[45] = 0;
        v38 = _ipa_add_flt_rule_after(v18, s, v35 + 384, v37, &v50);
        memcpy((void *)(v35 + 20), s, 0x168u);
        if ( !v38 )
        {
          v36 = 0;
          goto LABEL_67;
        }
        if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_after__rs_51, "ipa3_add_flt_rule_after") )
        {
          printk(&unk_3A36F0, "ipa3_add_flt_rule_after");
          v39 = ipa3_ctx;
          if ( ipa3_ctx )
          {
LABEL_73:
            v40 = *(_QWORD *)(v39 + 34152);
            if ( v40 )
            {
              ipc_log_string(v40, "ipa %s:%d failed to add flt rule %d\n", "ipa3_add_flt_rule_after", 1571, v34);
              v39 = ipa3_ctx;
            }
            v41 = *(_QWORD *)(v39 + 34160);
            if ( v41 )
              ipc_log_string(v41, "ipa %s:%d failed to add flt rule %d\n", "ipa3_add_flt_rule_after", 1571, v34);
          }
        }
        else
        {
          v39 = ipa3_ctx;
          if ( ipa3_ctx )
            goto LABEL_73;
        }
        v36 = -1;
LABEL_67:
        *(_DWORD *)(v35 + 388) = v36;
        ++v34;
        v35 += 372;
        if ( v34 >= *(unsigned __int8 *)(a1 + 12) )
          goto LABEL_80;
      }
    }
  }
  __break(0x5512u);
  return _ipa_add_flt_get_ep_idx(max_num_pipes, v12);
}
