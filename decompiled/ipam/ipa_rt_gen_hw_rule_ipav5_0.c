__int64 __fastcall ipa_rt_gen_hw_rule_ipav5_0(int *a1, unsigned int *a2, __int64 *a3)
{
  unsigned int v5; // w8
  unsigned __int64 v6; // x8
  int v7; // w3
  unsigned __int64 v8; // x8
  unsigned int v9; // w9
  int v10; // w9
  unsigned __int64 v11; // x8
  unsigned int v12; // w9
  unsigned int v13; // w9
  unsigned __int64 v14; // x8
  unsigned int v15; // w8
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x9
  unsigned int v18; // w8
  __int64 v19; // x9
  int v20; // w21
  __int64 v21; // x0
  __int64 v22; // x3
  __int64 v23; // x20
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  int *v29; // x19
  __int64 v30; // x0
  __int64 v31; // x0
  int *v32; // x21
  int *v33; // x21
  int *v34; // x21
  int *v35; // x21
  int *v36; // x21
  int *v37; // x21
  unsigned __int16 v38; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v39[2]; // [xsp+10h] [xbp-10h] BYREF

  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a1[1];
  v39[0] = a3;
  v38 = 0;
  if ( v5 >= 0x100 )
  {
    v32 = a1;
    ((void (*)(void))ipa_assert)();
    v5 = v32[1];
    a1 = v32;
  }
  v6 = *a3 & 0xFFFFFFFFFF00FFFFLL | ((unsigned __int8)v5 << 16);
  *a3 = v6;
  v7 = a1[2];
  switch ( v7 )
  {
    case 0:
      v11 = v6 & 0x400FFFFFFFFFFFFFLL | ((unsigned __int64)~*((unsigned __int8 *)a1 + 12) << 63);
      goto LABEL_14;
    case 1:
      v8 = v6 & 0x5FFFFFFFFFFFFFFFLL | ((unsigned __int64)~*((unsigned __int8 *)a1 + 12) << 63);
      *a3 = v8;
      v12 = a1[4];
      if ( (v12 & 3) != 0 )
      {
        v37 = a1;
        ((void (*)(void))ipa_assert)();
        v12 = v37[4];
        v8 = *a3;
        a1 = v37;
      }
      v10 = (v12 >> 2) & 0x1FF;
      goto LABEL_13;
    case 2:
      v8 = v6 & 0x7FFFFFFFFFFFFFFFLL | ((unsigned __int64)~*((unsigned __int8 *)a1 + 12) << 63) | 0x2000000000000000LL;
      *a3 = v8;
      v9 = a1[4];
      if ( (v9 & 0x1F) != 0 )
      {
        v36 = a1;
        ((void (*)(void))ipa_assert)();
        v9 = v36[4];
        v8 = *a3;
        a1 = v36;
      }
      v10 = (v9 >> 5) & 0x1FF;
LABEL_13:
      v11 = v8 & 0xE00FFFFFFFFFFFFFLL | ((unsigned __int64)(v10 & 0x1FF) << 52);
LABEL_14:
      *a3 = v11;
      v13 = a1[5];
      if ( v13 >= 0x100 )
      {
        v33 = a1;
        ((void (*)(void))ipa_assert)();
        LOBYTE(v13) = *((_BYTE *)v33 + 20);
        v11 = *a3;
        a1 = v33;
      }
      v14 = v11 & 0xFFFFFF00FFFFFFFFLL | ((unsigned __int64)(unsigned __int8)v13 << 32);
      *a3 = v14;
      *a3 = v14 & 0xBFFFFFFFFFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(*((_QWORD *)a1 + 4) + 166LL) != 0) << 62);
      v15 = a1[6];
      if ( v15 >= 0x400 )
      {
        v34 = a1;
        ((void (*)(void))ipa_assert)();
        v15 = v34[6];
        a1 = v34;
        if ( v15 != 1023 )
          goto LABEL_18;
      }
      else if ( v15 != 1023 )
      {
        goto LABEL_18;
      }
      v35 = a1;
      ((void (*)(void))ipa_assert)();
      v15 = v35[6];
      a1 = v35;
LABEL_18:
      v16 = *a3 & 0xFFF003FFFFFFFFFFLL | ((unsigned __int64)(v15 & 0x3FF) << 42);
      *a3 = v16;
      v17 = v16 & 0xFFFFFFFF00FFFFFFLL | ((unsigned __int64)*((unsigned __int8 *)a1 + 28) << 24);
      *a3 = v17;
      *a3 = v17 & 0xFFFFFDFFFFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(*((_QWORD *)a1 + 4) + 170LL) != 0) << 41);
      v18 = *a1;
      v19 = *((_QWORD *)a1 + 4);
      v39[0] = a3 + 1;
      if ( (unsigned int)ipa_fltrt_generate_hw_rule_bdy(v18, v19 + 12, v39, &v38) )
      {
        printk(&unk_3C2B3C, "ipa_rt_gen_hw_rule_ipav5_0");
        if ( ipa3_get_ipc_logbuf() )
        {
          ipc_logbuf = ipa3_get_ipc_logbuf();
          ipc_log_string(ipc_logbuf, "ipahal %s:%d fail to generate hw rule\n", "ipa_rt_gen_hw_rule_ipav5_0", 361);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(ipc_logbuf_low, "ipahal %s:%d fail to generate hw rule\n", "ipa_rt_gen_hw_rule_ipav5_0", 361);
        }
      }
      else
      {
        v20 = v38;
        *(_WORD *)a3 = v38;
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v21 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v21, "ipahal %s:%d en_rule 0x%x\n", "ipa_rt_gen_hw_rule_ipav5_0", 366, v20);
        }
        ipa_write_64(*a3, a3);
        v22 = *a2;
        if ( !(_DWORD)v22 )
        {
          result = 0;
          *a2 = LODWORD(v39[0]) - (_DWORD)a3;
          goto LABEL_34;
        }
        v23 = v39[0] - (_QWORD)a3;
        if ( v23 == v22 )
        {
          result = 0;
          goto LABEL_34;
        }
        printk(&unk_3B3D90, "ipa_rt_gen_hw_rule_ipav5_0");
        if ( ipa3_get_ipc_logbuf() )
        {
          v27 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v27,
            "ipahal %s:%d hw_len differs b/w passed=0x%x calc=%td\n",
            "ipa_rt_gen_hw_rule_ipav5_0",
            373,
            *a2,
            v23);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v28 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v28,
            "ipahal %s:%d hw_len differs b/w passed=0x%x calc=%td\n",
            "ipa_rt_gen_hw_rule_ipav5_0",
            373,
            *a2,
            v23);
        }
      }
      result = 0xFFFFFFFFLL;
      goto LABEL_34;
  }
  v29 = a1;
  printk(&unk_3D75DB, "ipa_rt_gen_hw_rule_ipav5_0");
  if ( ipa3_get_ipc_logbuf() )
  {
    v30 = ipa3_get_ipc_logbuf();
    ipc_log_string(v30, "ipahal %s:%d Invalid HDR type %d\n", "ipa_rt_gen_hw_rule_ipav5_0", 342, v29[2]);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v31 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v31, "ipahal %s:%d Invalid HDR type %d\n", "ipa_rt_gen_hw_rule_ipav5_0", 342, v29[2]);
  }
  result = 4294967274LL;
LABEL_34:
  _ReadStatusReg(SP_EL0);
  return result;
}
