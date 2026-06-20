__int64 __fastcall ipa3_add_flt_rule_after_v2(__int64 a1)
{
  __int64 v1; // x18
  __int128 v2; // q10
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 result; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  unsigned int v11; // w19
  unsigned int v12; // w19
  unsigned int max_num_pipes; // w0
  __int128 v14; // q1
  unsigned int v15; // w21
  __int64 v16; // x22
  __int64 v17; // x0
  __int64 v18; // x20
  __int64 v19; // x8
  __int64 v20; // x19
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
  __int64 v31; // x8
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x9
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0
  unsigned __int64 v38; // x20
  __int64 v39; // x27
  int v40; // w9
  __int64 v41; // x10
  __int64 v42; // x8
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  unsigned int (__fastcall *v46)(_QWORD); // x9
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x8
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 *v53; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v54; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v55; // [xsp+18h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !*(_BYTE *)(a1 + 12) || *(_DWORD *)(a1 + 4) >= 2u )
  {
    if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_after_v2__rs, "ipa3_add_flt_rule_after_v2") )
    {
      printk(&unk_3FB3F2, "ipa3_add_flt_rule_after_v2");
      v3 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_6;
    }
    else
    {
      v3 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_6:
        v4 = *(_QWORD *)(v3 + 34152);
        if ( v4 )
        {
          ipc_log_string(v4, "ipa %s:%d bad parm\n", "ipa3_add_flt_rule_after_v2", 1611);
          v3 = ipa3_ctx;
        }
        v5 = *(_QWORD *)(v3 + 34160);
        if ( v5 )
          ipc_log_string(v5, "ipa %s:%d bad parm\n", "ipa3_add_flt_rule_after_v2", 1611);
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
    if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_after_v2__rs_54, "ipa3_add_flt_rule_after_v2") )
    {
      printk(&unk_3F52A9, "ipa3_add_flt_rule_after_v2");
      v8 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_10;
    }
    else
    {
      v8 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_10;
    }
    v9 = *(_QWORD *)(v8 + 34152);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d bad parms ep=%d\n", "ipa3_add_flt_rule_after_v2", 1616, *(_DWORD *)(a1 + 8));
      v8 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v8 + 34160);
    if ( v10 )
      ipc_log_string(v10, "ipa %s:%d bad parms ep=%d\n", "ipa3_add_flt_rule_after_v2", 1616, *(_DWORD *)(a1 + 8));
    goto LABEL_10;
  }
  v54 = 0;
  mutex_lock(ipa3_ctx + 29472);
  if ( (unsigned int)_ipa_add_flt_get_ep_idx(*(unsigned int *)(a1 + 8), &v54) )
    goto LABEL_20;
  v12 = v54;
  max_num_pipes = ipa3_get_max_num_pipes();
  if ( (v12 & 0x80000000) != 0 || v12 >= max_num_pipes )
  {
    if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_after_v2__rs_55, "ipa3_add_flt_rule_after_v2") )
    {
      printk(&unk_3EF10D, "ipa3_add_flt_rule_after_v2");
      v24 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_20;
    }
    else
    {
      v24 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_20;
    }
    v25 = *(_QWORD *)(v24 + 34152);
    if ( v25 )
    {
      ipc_log_string(v25, "ipa %s:%d invalid ipa_ep_idx=%u\n", "ipa3_add_flt_rule_after_v2", 1629, v12);
      v24 = ipa3_ctx;
    }
    v26 = *(_QWORD *)(v24 + 34160);
    if ( v26 )
      ipc_log_string(v26, "ipa %s:%d invalid ipa_ep_idx=%u\n", "ipa3_add_flt_rule_after_v2", 1629, v12);
    goto LABEL_20;
  }
  if ( v12 < 0x24 )
  {
    v15 = *(_DWORD *)(a1 + 4);
    if ( v15 <= 2 )
    {
      v16 = ipa3_ctx;
      v17 = ipa3_id_find(*(unsigned int *)(a1 + 16));
      v53 = (__int64 *)v17;
      if ( !v17 )
      {
        if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_after_v2__rs_56, "ipa3_add_flt_rule_after_v2") )
        {
          printk(&unk_3DE445, "ipa3_add_flt_rule_after_v2");
          v27 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_20;
        }
        else
        {
          v27 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_20;
        }
        v28 = *(_QWORD *)(v27 + 34152);
        if ( v28 )
        {
          ipc_log_string(v28, "ipa %s:%d lookup failed\n", "ipa3_add_flt_rule_after_v2", 1638);
          v27 = ipa3_ctx;
        }
        v29 = *(_QWORD *)(v27 + 34160);
        if ( v29 )
          ipc_log_string(v29, "ipa %s:%d lookup failed\n", "ipa3_add_flt_rule_after_v2", 1638);
        goto LABEL_20;
      }
      v18 = v17;
      if ( *(_DWORD *)(v17 + 16) != 1468208646 )
      {
        if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_after_v2__rs_57, "ipa3_add_flt_rule_after_v2") )
        {
          printk(&unk_3DB627, "ipa3_add_flt_rule_after_v2");
          v30 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_20;
        }
        else
        {
          v30 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_20;
        }
        v31 = a1;
        v32 = *(_QWORD *)(v30 + 34152);
        if ( v32 )
        {
          ipc_log_string(
            v32,
            "ipa %s:%d Invalid cookie value =  %u flt hdl id = %d\n",
            "ipa3_add_flt_rule_after_v2",
            1645,
            *(_DWORD *)(v18 + 16),
            *(_DWORD *)(a1 + 16));
          v30 = ipa3_ctx;
          v31 = a1;
        }
        v33 = *(_QWORD *)(v30 + 34160);
        if ( v33 )
          ipc_log_string(
            v33,
            "ipa %s:%d Invalid cookie value =  %u flt hdl id = %d\n",
            "ipa3_add_flt_rule_after_v2",
            1645,
            *(_DWORD *)(v18 + 16),
            *(_DWORD *)(v31 + 16));
        goto LABEL_20;
      }
      v19 = v16 + 304LL * v12 + 152LL * v15;
      v20 = v19 + 17640;
      if ( *(_QWORD *)(v17 + 392) != v19 + 17640 )
      {
        if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_after_v2__rs_58, "ipa3_add_flt_rule_after_v2") )
        {
          printk(&unk_3B22CA, "ipa3_add_flt_rule_after_v2");
          v21 = ipa3_ctx;
          if ( ipa3_ctx )
            goto LABEL_33;
        }
        else
        {
          v21 = ipa3_ctx;
          if ( ipa3_ctx )
          {
LABEL_33:
            v22 = *(_QWORD *)(v21 + 34152);
            if ( v22 )
            {
              ipc_log_string(
                v22,
                "ipa %s:%d given entry does not match the table\n",
                "ipa3_add_flt_rule_after_v2",
                1651);
              v21 = ipa3_ctx;
            }
            v23 = *(_QWORD *)(v21 + 34160);
            if ( v23 )
              ipc_log_string(
                v23,
                "ipa %s:%d given entry does not match the table\n",
                "ipa3_add_flt_rule_after_v2",
                1651);
          }
        }
LABEL_20:
        v11 = -22;
LABEL_21:
        mutex_unlock(ipa3_ctx + 29472);
        result = v11;
        goto LABEL_11;
      }
      if ( *(_BYTE *)(v19 + 17768) == 1 && v17 == *(_QWORD *)(v19 + 17648) )
      {
        if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_after_v2__rs_59, "ipa3_add_flt_rule_after_v2") )
        {
          printk(&unk_3D8686, "ipa3_add_flt_rule_after_v2");
          v47 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_20;
        }
        else
        {
          v47 = ipa3_ctx;
          if ( !ipa3_ctx )
            goto LABEL_20;
        }
        v48 = *(_QWORD *)(v47 + 34152);
        if ( v48 )
        {
          ipc_log_string(v48, "ipa %s:%d cannot add rule at end of a sticky table", "ipa3_add_flt_rule_after_v2", 1658);
          v47 = ipa3_ctx;
        }
        v49 = *(_QWORD *)(v47 + 34160);
        if ( v49 )
          ipc_log_string(v49, "ipa %s:%d cannot add rule at end of a sticky table", "ipa3_add_flt_rule_after_v2", 1658);
        goto LABEL_20;
      }
      v34 = ipa3_ctx;
      v35 = a1;
      if ( ipa3_ctx )
      {
        v36 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v36 )
        {
          ipc_log_string(
            v36,
            "ipa %s:%d add ep flt rule ip=%d ep=%d after hdl %d\n",
            "ipa3_add_flt_rule_after_v2",
            1664,
            *(_DWORD *)(a1 + 4),
            *(_DWORD *)(a1 + 8),
            *(_DWORD *)(a1 + 16));
          v34 = ipa3_ctx;
          v35 = a1;
        }
        v37 = *(_QWORD *)(v34 + 34160);
        if ( v37 )
        {
          ipc_log_string(
            v37,
            "ipa %s:%d add ep flt rule ip=%d ep=%d after hdl %d\n",
            "ipa3_add_flt_rule_after_v2",
            1664,
            *(_DWORD *)(v35 + 4),
            *(_DWORD *)(v35 + 8),
            *(_DWORD *)(v35 + 16));
          v35 = a1;
        }
      }
      if ( !*(_BYTE *)(v35 + 12) )
      {
LABEL_80:
        if ( !*(_BYTE *)v35 )
          goto LABEL_84;
        v45 = *(unsigned int *)(v35 + 4);
        v46 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 112LL);
        if ( *((_DWORD *)v46 - 1) != 1856640366 )
          __break(0x8229u);
        if ( v46(v45) )
        {
          printk(&unk_3C0DC4, "ipa3_add_flt_rule_after_v2");
          v50 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v51 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v51 )
            {
              ipc_log_string(v51, "ipa %s:%d failed to commit flt rules\n", "ipa3_add_flt_rule_after_v2", 1696);
              v50 = ipa3_ctx;
            }
            v52 = *(_QWORD *)(v50 + 34160);
            if ( v52 )
              ipc_log_string(v52, "ipa %s:%d failed to commit flt rules\n", "ipa3_add_flt_rule_after_v2", 1696);
          }
          v11 = -1;
        }
        else
        {
LABEL_84:
          v11 = 0;
        }
        goto LABEL_21;
      }
      v38 = 0;
      v39 = 366;
      while ( 1 )
      {
        if ( *(_BYTE *)(ipa3_ctx + 32270) == 1 )
          *(_BYTE *)(*(_QWORD *)(v35 + 32) + v39) = 0;
        if ( !(unsigned int)_ipa_add_flt_rule_after(
                              v20,
                              (const void *)(*(_QWORD *)(v35 + 32) + v39 - 354),
                              (const void *)(*(_QWORD *)(v35 + 32) + v39 - 362),
                              *(_DWORD *)(v35 + 4),
                              &v53) )
        {
          v40 = 0;
          goto LABEL_67;
        }
        if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_after_v2__rs_60, "ipa3_add_flt_rule_after_v2") )
        {
          printk(&unk_3A36F0, "ipa3_add_flt_rule_after_v2");
          v42 = ipa3_ctx;
          if ( ipa3_ctx )
          {
LABEL_73:
            v43 = *(_QWORD *)(v42 + 34152);
            if ( v43 )
            {
              ipc_log_string(v43, "ipa %s:%d failed to add flt rule %d\n", "ipa3_add_flt_rule_after_v2", 1685, v38);
              v42 = ipa3_ctx;
            }
            v44 = *(_QWORD *)(v42 + 34160);
            if ( v44 )
              ipc_log_string(v44, "ipa %s:%d failed to add flt rule %d\n", "ipa3_add_flt_rule_after_v2", 1685, v38);
          }
        }
        else
        {
          v42 = ipa3_ctx;
          if ( ipa3_ctx )
            goto LABEL_73;
        }
        v40 = -1;
LABEL_67:
        ++v38;
        v35 = a1;
        v41 = *(_QWORD *)(a1 + 32) + v39;
        v39 += 380;
        *(_DWORD *)(v41 - 358) = v40;
        if ( v38 >= *(unsigned __int8 *)(a1 + 12) )
          goto LABEL_80;
      }
    }
  }
  __break(0x5512u);
  *(_OWORD *)(v1 - 384) = v14;
  *(_OWORD *)(v1 - 368) = v2;
  return ipa3_del_flt_rule();
}
