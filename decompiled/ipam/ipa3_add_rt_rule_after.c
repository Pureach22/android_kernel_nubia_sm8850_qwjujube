__int64 __fastcall ipa3_add_rt_rule_after(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x20
  __int64 v9; // x0
  __int64 v10; // x21
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned int v17; // w19
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  unsigned __int64 v27; // x21
  _DWORD *v28; // x28
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  unsigned int (__fastcall *v33)(_QWORD); // x8
  __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x8
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // [xsp+8h] [xbp-C8h] BYREF
  _BYTE dest[168]; // [xsp+10h] [xbp-C0h] BYREF
  __int64 v42; // [xsp+B8h] [xbp-18h]
  __int64 v43; // [xsp+C0h] [xbp-10h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && *(_BYTE *)(a1 + 40) && *(_DWORD *)(a1 + 4) < 2u )
  {
    mutex_lock(ipa3_ctx + 29472);
    v6 = *(unsigned int *)(a1 + 4);
    *(_BYTE *)(a1 + 39) = 0;
    v7 = ((__int64 (__fastcall *)(__int64, __int64))_ipa3_find_rt_tbl)(v6, a1 + 8);
    if ( !v7 || (v8 = v7, *(_DWORD *)(v7 + 16) != 1468208645) )
    {
      if ( (unsigned int)__ratelimit(&ipa3_add_rt_rule_after__rs_30, "ipa3_add_rt_rule_after") )
      {
        printk(&unk_3E6C77, "ipa3_add_rt_rule_after");
        v14 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_28;
      }
      else
      {
        v14 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_28;
      }
      v15 = *(_QWORD *)(v14 + 34152);
      if ( v15 )
      {
        ipc_log_string(
          v15,
          "ipa %s:%d failed finding rt tbl name = %s\n",
          "ipa3_add_rt_rule_after",
          1578,
          (const char *)(a1 + 8));
        v14 = ipa3_ctx;
      }
      v16 = *(_QWORD *)(v14 + 34160);
      if ( v16 )
        ipc_log_string(
          v16,
          "ipa %s:%d failed finding rt tbl name = %s\n",
          "ipa3_add_rt_rule_after",
          1578,
          (const char *)(a1 + 8));
      goto LABEL_28;
    }
    if ( !*(_DWORD *)(v7 + 76) )
    {
      if ( (unsigned int)__ratelimit(&ipa3_add_rt_rule_after__rs_33, "ipa3_add_rt_rule_after") )
      {
        printk(&unk_3F5A1B, "ipa3_add_rt_rule_after");
        v18 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_28;
      }
      else
      {
        v18 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_28;
      }
      v19 = *(_QWORD *)(v18 + 34152);
      if ( v19 )
      {
        ipc_log_string(v19, "ipa %s:%d tbl->rule_cnt == 0", "ipa3_add_rt_rule_after", 1584);
        v18 = ipa3_ctx;
      }
      v20 = *(_QWORD *)(v18 + 34160);
      if ( v20 )
        ipc_log_string(v20, "ipa %s:%d tbl->rule_cnt == 0", "ipa3_add_rt_rule_after", 1584);
      goto LABEL_28;
    }
    v9 = ipa3_id_find(*(unsigned int *)(a1 + 44));
    v40 = v9;
    if ( !v9 )
    {
      if ( (unsigned int)__ratelimit(&ipa3_add_rt_rule_after__rs_36, "ipa3_add_rt_rule_after") )
      {
        printk(&unk_3B2B52, "ipa3_add_rt_rule_after");
        v21 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_28;
      }
      else
      {
        v21 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_28;
      }
      v22 = *(_QWORD *)(v21 + 34152);
      if ( v22 )
      {
        ipc_log_string(
          v22,
          "ipa %s:%d failed finding rule %d in rt tbls\n",
          "ipa3_add_rt_rule_after",
          1592,
          *(_DWORD *)(a1 + 44));
        v21 = ipa3_ctx;
      }
      v23 = *(_QWORD *)(v21 + 34160);
      if ( v23 )
        ipc_log_string(
          v23,
          "ipa %s:%d failed finding rule %d in rt tbls\n",
          "ipa3_add_rt_rule_after",
          1592,
          *(_DWORD *)(a1 + 44));
      goto LABEL_28;
    }
    v10 = v9;
    if ( *(_DWORD *)(v9 + 16) != 1468208644 )
    {
      if ( (unsigned int)__ratelimit(&ipa3_add_rt_rule_after__rs_39, "ipa3_add_rt_rule_after") )
      {
        printk(&unk_3F887A, "ipa3_add_rt_rule_after");
        v24 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_28;
      }
      else
      {
        v24 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_28;
      }
      v25 = *(_QWORD *)(v24 + 34152);
      if ( v25 )
      {
        ipc_log_string(
          v25,
          "ipa %s:%d Invalid cookie value =  %u rule %d in rt tbls\n",
          "ipa3_add_rt_rule_after",
          1599,
          *(_DWORD *)(v10 + 16),
          *(_DWORD *)(a1 + 44));
        v24 = ipa3_ctx;
      }
      v26 = *(_QWORD *)(v24 + 34160);
      if ( v26 )
        ipc_log_string(
          v26,
          "ipa %s:%d Invalid cookie value =  %u rule %d in rt tbls\n",
          "ipa3_add_rt_rule_after",
          1599,
          *(_DWORD *)(v10 + 16),
          *(_DWORD *)(a1 + 44));
      goto LABEL_28;
    }
    if ( *(_QWORD *)(v9 + 200) != v8 )
    {
      if ( (unsigned int)__ratelimit(&ipa3_add_rt_rule_after__rs_42, "ipa3_add_rt_rule_after") )
      {
        printk(&unk_3D02CD, "ipa3_add_rt_rule_after");
        v11 = ipa3_ctx;
        if ( ipa3_ctx )
          goto LABEL_18;
      }
      else
      {
        v11 = ipa3_ctx;
        if ( ipa3_ctx )
        {
LABEL_18:
          v12 = *(_QWORD *)(v11 + 34152);
          if ( v12 )
          {
            ipc_log_string(v12, "ipa %s:%d given rt rule does not match the table\n", "ipa3_add_rt_rule_after", 1605);
            v11 = ipa3_ctx;
          }
          v13 = *(_QWORD *)(v11 + 34160);
          if ( v13 )
            ipc_log_string(v13, "ipa %s:%d given rt rule does not match the table\n", "ipa3_add_rt_rule_after", 1605);
        }
      }
LABEL_28:
      v17 = -22;
LABEL_29:
      mutex_unlock(ipa3_ctx + 29472);
      result = v17;
      goto LABEL_32;
    }
    if ( !strcmp((const char *)(v8 + 40), "ipa_dflt_rt") && *(_DWORD *)(v8 + 76) )
    {
      if ( (unsigned int)__ratelimit(&ipa3_add_rt_rule_after__rs_46, "ipa3_add_rt_rule_after") )
      {
        printk(&unk_3C143C, "ipa3_add_rt_rule_after");
        v37 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_28;
      }
      else
      {
        v37 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_28;
      }
      v38 = *(_QWORD *)(v37 + 34152);
      if ( v38 )
      {
        ipc_log_string(v38, "ipa %s:%d cannot add rules to default rt table\n", "ipa3_add_rt_rule_after", 1616);
        v37 = ipa3_ctx;
      }
      v39 = *(_QWORD *)(v37 + 34160);
      if ( v39 )
        ipc_log_string(v39, "ipa %s:%d cannot add rules to default rt table\n", "ipa3_add_rt_rule_after", 1616);
      goto LABEL_28;
    }
    if ( *(_BYTE *)(a1 + 40) )
    {
      v27 = 0;
      v28 = (_DWORD *)(a1 + 224);
      do
      {
        if ( *(_BYTE *)(ipa3_ctx + 32270) == 1 )
          *((_BYTE *)v28 - 11) = 0;
        memcpy(dest, v28 - 44, sizeof(dest));
        v42 = 0;
        if ( !(unsigned int)_ipa_add_rt_rule_after(v8, dest, v28 - 1, &v40) )
        {
          *v28 = 0;
          memcpy(v28 - 44, dest, 0xA8u);
          goto LABEL_57;
        }
        if ( (unsigned int)__ratelimit(&ipa3_add_rt_rule_after__rs_49, "ipa3_add_rt_rule_after") )
        {
          printk(&unk_3B00AA, "ipa3_add_rt_rule_after");
          v29 = ipa3_ctx;
          if ( ipa3_ctx )
          {
LABEL_63:
            v30 = *(_QWORD *)(v29 + 34152);
            if ( v30 )
            {
              ipc_log_string(v30, "ipa %s:%d failed to add rt rule %d\n", "ipa3_add_rt_rule_after", 1637, v27);
              v29 = ipa3_ctx;
            }
            v31 = *(_QWORD *)(v29 + 34160);
            if ( v31 )
              ipc_log_string(v31, "ipa %s:%d failed to add rt rule %d\n", "ipa3_add_rt_rule_after", 1637, v27);
          }
        }
        else
        {
          v29 = ipa3_ctx;
          if ( ipa3_ctx )
            goto LABEL_63;
        }
        *v28 = -1;
LABEL_57:
        ++v27;
        v28 += 45;
      }
      while ( v27 < *(unsigned __int8 *)(a1 + 40) );
    }
    if ( !*(_BYTE *)a1 )
      goto LABEL_81;
    v32 = *(unsigned int *)(a1 + 4);
    v33 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 120LL);
    if ( *((_DWORD *)v33 - 1) != 1856640366 )
      __break(0x8228u);
    if ( !v33(v32) )
    {
LABEL_81:
      v17 = 0;
      goto LABEL_29;
    }
    if ( (unsigned int)__ratelimit(&ipa3_add_rt_rule_after__rs_50, "ipa3_add_rt_rule_after") )
    {
      printk(&unk_3A40EC, "ipa3_add_rt_rule_after");
      v34 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_76;
    }
    else
    {
      v34 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_76:
        v35 = *(_QWORD *)(v34 + 34152);
        if ( v35 )
        {
          ipc_log_string(v35, "ipa %s:%d failed to commit\n", "ipa3_add_rt_rule_after", 1647);
          v34 = ipa3_ctx;
        }
        v36 = *(_QWORD *)(v34 + 34160);
        if ( v36 )
          ipc_log_string(v36, "ipa %s:%d failed to commit\n", "ipa3_add_rt_rule_after", 1647);
      }
    }
    v17 = -1;
    goto LABEL_29;
  }
  if ( !(unsigned int)__ratelimit(&ipa3_add_rt_rule_after__rs, "ipa3_add_rt_rule_after") )
  {
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
      goto LABEL_6;
LABEL_31:
    result = 4294967274LL;
    goto LABEL_32;
  }
  printk(&unk_3C3EF1, "ipa3_add_rt_rule_after");
  v2 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_31;
LABEL_6:
  v3 = *(_QWORD *)(v2 + 34152);
  if ( v3 )
  {
    ipc_log_string(v3, "ipa %s:%d bad param\n", "ipa3_add_rt_rule_after", 1569);
    v2 = ipa3_ctx;
  }
  v4 = *(_QWORD *)(v2 + 34160);
  if ( !v4 )
    goto LABEL_31;
  ipc_log_string(v4, "ipa %s:%d bad param\n", "ipa3_add_rt_rule_after", 1569);
  result = 4294967274LL;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
