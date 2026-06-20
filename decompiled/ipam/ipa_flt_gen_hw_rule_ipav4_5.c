__int64 __fastcall ipa_flt_gen_hw_rule_ipav4_5(__int64 a1, unsigned int *a2, __int64 *a3)
{
  unsigned int *v5; // x21
  __int64 v6; // x8
  int v7; // w3
  unsigned __int64 v8; // x8
  unsigned int v9; // w9
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x8
  unsigned int v12; // w9
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x8
  unsigned int v15; // w9
  unsigned int v16; // w8
  unsigned __int64 v17; // x9
  unsigned __int64 v18; // x9
  __int64 v19; // x8
  unsigned __int16 *v20; // x21
  __int64 v21; // x0
  int v22; // w21
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x3
  __int64 v26; // x20
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  _WORD v36[2]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v37[2]; // [xsp+10h] [xbp-10h] BYREF

  v5 = (unsigned int *)a1;
  v37[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 24);
  v37[0] = a3;
  v36[0] = 0;
  v7 = *(_DWORD *)(v6 + 4);
  if ( v7 > 1 )
  {
    if ( v7 == 2 )
    {
      v8 = *a3 & 0xFFFFFFFFFFE0FFFFLL | 0x20000;
    }
    else
    {
      if ( v7 != 3 )
        goto LABEL_44;
      v8 = *a3 & 0xFFFFFFFFFFE0FFFFLL | 0x30000;
    }
LABEL_10:
    *a3 = v8;
    v9 = *(_DWORD *)(a1 + 4);
    if ( v9 >= 0x20 )
    {
      a1 = ((__int64 (*)(void))ipa_assert)();
      v9 = v5[1];
      v8 = *a3;
    }
    v10 = v8 & 0xFFFFFFFFFC1FFFFFLL | ((unsigned __int8)(v9 & 0x1F) << 21);
    *a3 = v10;
    v11 = v10 & 0xFFFFFFFFFBFFFFFFLL | ((unsigned __int64)(**((_BYTE **)v5 + 3) != 0) << 26);
    *a3 = v11;
    v12 = *(unsigned __int8 *)(*((_QWORD *)v5 + 3) + 359LL);
    if ( v12 >= 0x10 )
    {
      a1 = ((__int64 (__fastcall *)(__int64))ipa_assert)(a1);
      LOBYTE(v12) = *(_BYTE *)(*((_QWORD *)v5 + 3) + 359LL);
      v11 = *a3;
    }
    v13 = v11 & 0xFFFFFFFF87FFFFFFLL | ((unsigned __int64)(v12 & 0xF) << 27);
    *a3 = v13;
    v14 = v13 & 0xFFFF0FFF7FFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(*((_QWORD *)v5 + 3) + 358LL) & 1) << 31);
    *a3 = v14;
    v15 = v5[2];
    if ( v15 >= 0x400 )
    {
      a1 = ((__int64 (__fastcall *)(__int64))ipa_assert)(a1);
      v15 = v5[2];
      v14 = *a3;
    }
    *a3 = v14 & 0xFFFFFC00FFFFFFFFLL | ((unsigned __int64)(v15 & 0x3FF) << 32);
    v16 = v5[3];
    if ( v16 >= 0x400 )
    {
      a1 = ((__int64 (__fastcall *)(__int64))ipa_assert)(a1);
      v16 = v5[3];
      if ( v16 != 1023 )
        goto LABEL_18;
    }
    else if ( v16 != 1023 )
    {
      goto LABEL_18;
    }
    ((void (__fastcall *)(__int64))ipa_assert)(a1);
    v16 = v5[3];
LABEL_18:
    v17 = *a3 & 0xFC00FFFFFFFFFFFFLL | ((unsigned __int64)(v16 & 0x3FF) << 48);
    *a3 = v17;
    v18 = v17 & 0x3FFFFFFFFFFFFFFLL | ((unsigned __int64)*((unsigned __int8 *)v5 + 16) << 58);
    *a3 = v18;
    *a3 = v18 & 0xFFFFF3FFFFFFFFFFLL | ((((unsigned __int64)*((unsigned __int8 *)v5 + 16) >> 6) & 3) << 42);
    v19 = *((_QWORD *)v5 + 3);
    v37[0] = a3 + 1;
    if ( *(_BYTE *)(v19 + 352) )
    {
      if ( (unsigned int)ipa_fltrt_generate_hw_rule_bdy_from_eq(v19 + 164, v37) )
      {
        printk(&unk_3CEB33, "ipa_flt_gen_hw_rule_ipav4_5");
        if ( ipa3_get_ipc_logbuf() )
        {
          ipc_logbuf = ipa3_get_ipc_logbuf();
          ipc_log_string(
            ipc_logbuf,
            "ipahal %s:%d fail to generate hw rule from eq\n",
            "ipa_flt_gen_hw_rule_ipav4_5",
            682);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            ipc_logbuf_low,
            "ipahal %s:%d fail to generate hw rule from eq\n",
            "ipa_flt_gen_hw_rule_ipav4_5",
            682);
        }
        goto LABEL_42;
      }
      v20 = (unsigned __int16 *)(*((_QWORD *)v5 + 3) + 164LL);
    }
    else
    {
      v21 = *v5;
      v20 = v36;
      if ( (unsigned int)ipa_fltrt_generate_hw_rule_bdy(v21, v19 + 12, v37, v36) )
      {
        printk(&unk_3C2B3C, "ipa_flt_gen_hw_rule_ipav4_5");
        if ( ipa3_get_ipc_logbuf() )
        {
          v32 = ipa3_get_ipc_logbuf();
          ipc_log_string(v32, "ipahal %s:%d fail to generate hw rule\n", "ipa_flt_gen_hw_rule_ipav4_5", 689);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v33 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v33, "ipahal %s:%d fail to generate hw rule\n", "ipa_flt_gen_hw_rule_ipav4_5", 689);
        }
        goto LABEL_42;
      }
    }
    v22 = *v20;
    *(_WORD *)a3 = v22;
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v23 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v23,
        "ipahal %s:%d en_rule=0x%x, action=%d, rt_idx=%d, retain_hdr=%d\n",
        "ipa_flt_gen_hw_rule_ipav4_5",
        699,
        v22,
        HIWORD(*(_DWORD *)a3) & 0x1F,
        (*(_DWORD *)a3 >> 21) & 0x1F,
        (*(_DWORD *)a3 >> 26) & 1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v24 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v24,
        "ipahal %s:%d priority=%d, rule_id=%d, pdn=%d, set_metadata=%d\n",
        "ipa_flt_gen_hw_rule_ipav4_5",
        704,
        HIDWORD(*a3) & 0x3FF,
        HIWORD(*a3) & 0x3FF,
        ((unsigned int)*a3 >> 27) & 0xF,
        ((unsigned __int64)*a3 >> 31) & 1);
    }
    ipa_write_64(*a3, a3);
    v25 = *a2;
    if ( !(_DWORD)v25 )
    {
      result = 0;
      *a2 = LODWORD(v37[0]) - (_DWORD)a3;
      goto LABEL_43;
    }
    v26 = v37[0] - (_QWORD)a3;
    if ( v26 == v25 )
    {
      result = 0;
      goto LABEL_43;
    }
    printk(&unk_3B3D90, "ipa_flt_gen_hw_rule_ipav4_5");
    if ( ipa3_get_ipc_logbuf() )
    {
      v30 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v30,
        "ipahal %s:%d hw_len differs b/w passed=0x%x calc=%td\n",
        "ipa_flt_gen_hw_rule_ipav4_5",
        712,
        *a2,
        v26);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v31 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v31,
        "ipahal %s:%d hw_len differs b/w passed=0x%x calc=%td\n",
        "ipa_flt_gen_hw_rule_ipav4_5",
        712,
        *a2,
        v26);
    }
LABEL_42:
    result = 0xFFFFFFFFLL;
    goto LABEL_43;
  }
  if ( !v7 )
  {
    v8 = *a3 & 0xFFFFFFFFFFE0FFFFLL;
    goto LABEL_10;
  }
  if ( v7 == 1 )
  {
    v8 = *a3 & 0xFFFFFFFFFFE0FFFFLL | 0x10000;
    goto LABEL_10;
  }
LABEL_44:
  printk(&unk_3EB3EF, "ipa_flt_gen_hw_rule_ipav4_5");
  if ( ipa3_get_ipc_logbuf() )
  {
    v34 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v34,
      "ipahal %s:%d Invalid Rule Action %d\n",
      "ipa_flt_gen_hw_rule_ipav4_5",
      655,
      *(_DWORD *)(*((_QWORD *)v5 + 3) + 4LL));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v35 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v35,
      "ipahal %s:%d Invalid Rule Action %d\n",
      "ipa_flt_gen_hw_rule_ipav4_5",
      655,
      *(_DWORD *)(*((_QWORD *)v5 + 3) + 4LL));
  }
  result = 4294967274LL;
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
