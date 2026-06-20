__int64 __fastcall ipa_rt_gen_hw_rule(int *a1, unsigned int *a2, __int64 *a3)
{
  unsigned int v5; // w8
  unsigned __int64 v6; // x8
  int v7; // w3
  unsigned __int64 v8; // x8
  int v9; // w9
  int v10; // w9
  unsigned __int64 v11; // x8
  int v12; // w9
  unsigned int v13; // w9
  unsigned __int64 v14; // x8
  unsigned int v15; // w8
  unsigned int v16; // w8
  __int64 v17; // x9
  int v18; // w21
  __int64 v19; // x0
  __int64 v20; // x3
  __int64 v21; // x20
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  int *v27; // x19
  __int64 v28; // x0
  __int64 v29; // x0
  int *v30; // x21
  int *v31; // x21
  int *v32; // x21
  int *v33; // x21
  int *v34; // x21
  int *v35; // x21
  unsigned __int16 v36; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v37[2]; // [xsp+10h] [xbp-10h] BYREF

  v37[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a1[1];
  v37[0] = a3;
  v36 = 0;
  if ( v5 >= 0x20 )
  {
    v30 = a1;
    ((void (*)(void))ipa_assert)();
    v5 = v30[1];
    a1 = v30;
  }
  v6 = *a3 & 0xFFFFFFFFFFE0FFFFLL | ((unsigned __int8)(v5 & 0x1F) << 16);
  *a3 = v6;
  v7 = a1[2];
  switch ( v7 )
  {
    case 0:
      v11 = v6 & 0xFFFFFFFF001FFFFFLL | ((~*((unsigned __int8 *)a1 + 12) & 1LL) << 21);
      goto LABEL_14;
    case 1:
      v8 = v6 & 0xFFFFFFFF7FDFFFFFLL | ((*((unsigned __int8 *)a1 + 12) ^ 1LL) << 21);
      *a3 = v8;
      v12 = a1[4];
      if ( (v12 & 3) != 0 )
      {
        v35 = a1;
        ((void (*)(void))ipa_assert)();
        v12 = v35[4];
        v8 = *a3;
        a1 = v35;
      }
      v10 = v12 << 20;
      goto LABEL_13;
    case 2:
      v8 = v6 & 0xFFFFFFFFFFDFFFFFLL | ((*((unsigned __int8 *)a1 + 12) ^ 1LL) << 21) | 0x80000000;
      *a3 = v8;
      v9 = a1[4];
      if ( (v9 & 0x1F) != 0 )
      {
        v34 = a1;
        ((void (*)(void))ipa_assert)();
        v9 = v34[4];
        v8 = *a3;
        a1 = v34;
      }
      v10 = v9 << 17;
LABEL_13:
      v11 = v8 & 0xFFFFFFFF803FFFFFLL | v10 & 0x7FC00000;
LABEL_14:
      *a3 = v11;
      v13 = a1[5];
      if ( v13 >= 0x400 )
      {
        v31 = a1;
        ((void (*)(void))ipa_assert)();
        v13 = v31[5];
        v11 = *a3;
        a1 = v31;
      }
      v14 = v11 & 0xFFFFFC00FFFFFFFFLL | ((unsigned __int64)(v13 & 0x3FF) << 32);
      *a3 = v14;
      *a3 = v14 & 0xFFFF7FFFFFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(*((_QWORD *)a1 + 4) + 166LL) != 0) << 47);
      v15 = a1[6];
      if ( v15 >= 0x400 )
      {
        v32 = a1;
        ((void (*)(void))ipa_assert)();
        v15 = v32[6];
        a1 = v32;
        if ( v15 != 1023 )
          goto LABEL_18;
      }
      else if ( v15 != 1023 )
      {
        goto LABEL_18;
      }
      v33 = a1;
      ((void (*)(void))ipa_assert)();
      v15 = v33[6];
      a1 = v33;
LABEL_18:
      *a3 = *a3 & 0xFC00FFFFFFFFFFFFLL | ((unsigned __int64)(v15 & 0x3FF) << 48);
      v16 = *a1;
      v17 = *((_QWORD *)a1 + 4);
      v37[0] = a3 + 1;
      if ( (unsigned int)ipa_fltrt_generate_hw_rule_bdy(v16, v17 + 12, v37, &v36) )
      {
        printk(&unk_3C2B3C, "ipa_rt_gen_hw_rule");
        if ( ipa3_get_ipc_logbuf() )
        {
          ipc_logbuf = ipa3_get_ipc_logbuf();
          ipc_log_string(ipc_logbuf, "ipahal %s:%d fail to generate hw rule\n", "ipa_rt_gen_hw_rule", 224);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(ipc_logbuf_low, "ipahal %s:%d fail to generate hw rule\n", "ipa_rt_gen_hw_rule", 224);
        }
      }
      else
      {
        v18 = v36;
        *(_WORD *)a3 = v36;
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v19 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v19, "ipahal %s:%d en_rule 0x%x\n", "ipa_rt_gen_hw_rule", 229, v18);
        }
        ipa_write_64(*a3, a3);
        v20 = *a2;
        if ( !(_DWORD)v20 )
        {
          result = 0;
          *a2 = LODWORD(v37[0]) - (_DWORD)a3;
          goto LABEL_34;
        }
        v21 = v37[0] - (_QWORD)a3;
        if ( v21 == v20 )
        {
          result = 0;
          goto LABEL_34;
        }
        printk(&unk_3B3D90, "ipa_rt_gen_hw_rule");
        if ( ipa3_get_ipc_logbuf() )
        {
          v25 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v25,
            "ipahal %s:%d hw_len differs b/w passed=0x%x calc=%td\n",
            "ipa_rt_gen_hw_rule",
            236,
            *a2,
            v21);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v26 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v26,
            "ipahal %s:%d hw_len differs b/w passed=0x%x calc=%td\n",
            "ipa_rt_gen_hw_rule",
            236,
            *a2,
            v21);
        }
      }
      result = 0xFFFFFFFFLL;
      goto LABEL_34;
  }
  v27 = a1;
  printk(&unk_3D75DB, "ipa_rt_gen_hw_rule");
  if ( ipa3_get_ipc_logbuf() )
  {
    v28 = ipa3_get_ipc_logbuf();
    ipc_log_string(v28, "ipahal %s:%d Invalid HDR type %d\n", "ipa_rt_gen_hw_rule", 208, v27[2]);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v29 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v29, "ipahal %s:%d Invalid HDR type %d\n", "ipa_rt_gen_hw_rule", 208, v27[2]);
  }
  result = 4294967274LL;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
