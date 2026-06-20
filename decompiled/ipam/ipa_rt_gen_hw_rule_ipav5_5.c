__int64 __fastcall ipa_rt_gen_hw_rule_ipav5_5(unsigned int *a1, unsigned int *a2, __int64 a3)
{
  unsigned int v5; // w8
  unsigned __int64 v6; // x8
  unsigned int v7; // w3
  unsigned __int64 v8; // x8
  unsigned int v9; // w9
  int v10; // w9
  unsigned __int64 v11; // x8
  unsigned int v12; // w9
  unsigned int v13; // w9
  unsigned __int64 v14; // x8
  unsigned int v15; // w9
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  _BYTE *v19; // x9
  __int16 v20; // w9
  __int64 v21; // x4
  __int16 v22; // w9
  __int16 v23; // w8
  __int16 v24; // w8
  __int16 v25; // w9
  int v26; // w21
  __int64 v27; // x0
  __int64 v28; // x3
  __int64 v29; // x20
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  unsigned int *v35; // x19
  __int64 v36; // x0
  __int64 v37; // x0
  unsigned int *v38; // x21
  unsigned int *v39; // x21
  unsigned int *v40; // x21
  unsigned int *v41; // x21
  unsigned int *v42; // x21
  unsigned int *v43; // x21
  unsigned __int16 v44; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v45[2]; // [xsp+10h] [xbp-10h] BYREF

  v45[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a1[1];
  v45[0] = a3;
  v44 = 0;
  if ( v5 >= 0x100 )
  {
    v38 = a1;
    ((void (*)(void))ipa_assert)();
    v5 = v38[1];
    a1 = v38;
  }
  v6 = *(_QWORD *)a3 & 0xFFFFFFFFFF00FFFFLL | ((unsigned __int8)v5 << 16);
  *(_QWORD *)a3 = v6;
  v7 = a1[2];
  switch ( v7 )
  {
    case 0u:
      v11 = v6 & 0x400FFFFFFFFFFFFFLL | ((unsigned __int64)~*((unsigned __int8 *)a1 + 12) << 63);
      goto LABEL_14;
    case 1u:
      v8 = v6 & 0x5FFFFFFFFFFFFFFFLL | ((unsigned __int64)~*((unsigned __int8 *)a1 + 12) << 63);
      *(_QWORD *)a3 = v8;
      v12 = a1[4];
      if ( (v12 & 3) != 0 )
      {
        v43 = a1;
        ((void (*)(void))ipa_assert)();
        v12 = v43[4];
        v8 = *(_QWORD *)a3;
        a1 = v43;
      }
      v10 = (v12 >> 2) & 0x1FF;
      goto LABEL_13;
    case 2u:
      v8 = v6 & 0x7FFFFFFFFFFFFFFFLL | ((unsigned __int64)~*((unsigned __int8 *)a1 + 12) << 63) | 0x2000000000000000LL;
      *(_QWORD *)a3 = v8;
      v9 = a1[4];
      if ( (v9 & 0x1F) != 0 )
      {
        v42 = a1;
        ((void (*)(void))ipa_assert)();
        v9 = v42[4];
        v8 = *(_QWORD *)a3;
        a1 = v42;
      }
      v10 = (v9 >> 5) & 0x1FF;
LABEL_13:
      v11 = v8 & 0xE00FFFFFFFFFFFFFLL | ((unsigned __int64)(v10 & 0x1FF) << 52);
LABEL_14:
      *(_QWORD *)a3 = v11;
      v13 = a1[5];
      if ( v13 >= 0x100 )
      {
        v39 = a1;
        ((void (*)(void))ipa_assert)();
        LOBYTE(v13) = *((_BYTE *)v39 + 20);
        v11 = *(_QWORD *)a3;
        a1 = v39;
      }
      v14 = v11 & 0xFFFFFF00FFFFFFFFLL | ((unsigned __int64)(unsigned __int8)v13 << 32);
      *(_QWORD *)a3 = v14;
      *(_QWORD *)a3 = v14 & 0xBFFFFFFFFFFFFFFFLL
                    | ((unsigned __int64)(*(_BYTE *)(*((_QWORD *)a1 + 4) + 166LL) != 0) << 62);
      v15 = a1[6];
      if ( v15 >= 0x400 )
      {
        v40 = a1;
        ((void (*)(void))ipa_assert)();
        v15 = v40[6];
        a1 = v40;
        if ( v15 != 1023 )
          goto LABEL_18;
      }
      else if ( v15 != 1023 )
      {
LABEL_18:
        v16 = *(_QWORD *)a3 & 0xFFF003FFFFFFFFFFLL | ((unsigned __int64)(v15 & 0x3FF) << 42);
        *(_QWORD *)a3 = v16;
        v17 = v16 & 0xFFFFFFFF00FFFFFFLL | ((unsigned __int64)*((unsigned __int8 *)a1 + 28) << 24);
        *(_QWORD *)a3 = v17;
        v18 = v17 & 0xFFFFFDFFFFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(*((_QWORD *)a1 + 4) + 170LL) != 0) << 41);
        *(_QWORD *)a3 = v18;
        v19 = *((_BYTE **)a1 + 4);
        v45[0] = a3 + 8;
        if ( v19[171] || v19[172] || v19[173] )
        {
          v20 = *(_WORD *)(a3 + 8);
          v21 = 1;
          *(_QWORD *)a3 = v18 | 0x10000000000LL;
          v22 = v20 & 0xFFFE;
          if ( *(_BYTE *)(*((_QWORD *)a1 + 4) + 171LL) )
            v23 = v22 + 1;
          else
            v23 = v22;
          *(_WORD *)(a3 + 8) = v23;
          v24 = v23 & 0xFF81 | (2 * (*(_BYTE *)(*((_QWORD *)a1 + 4) + 172LL) & 0x3F));
          *(_WORD *)(a3 + 8) = v24;
          v25 = *(_BYTE *)(*((_QWORD *)a1 + 4) + 173LL) != 0;
          v45[0] = a3 + 10;
          *(_WORD *)(a3 + 8) = v24 & 0xFF7F | (v25 << 7);
        }
        else
        {
          v21 = 0;
          *(_QWORD *)a3 = v18 & 0xFFFFFEFFFFFFFFFFLL;
        }
        if ( (unsigned int)ipa_fltrt_generate_hw_rule_bdy_5_5(*a1, *((_QWORD *)a1 + 4) + 12LL, v45, &v44, v21) )
        {
          printk(&unk_3C2B3C, "ipa_rt_gen_hw_rule_ipav5_5");
          if ( ipa3_get_ipc_logbuf() )
          {
            ipc_logbuf = ipa3_get_ipc_logbuf();
            ipc_log_string(ipc_logbuf, "ipahal %s:%d fail to generate hw rule\n", "ipa_rt_gen_hw_rule_ipav5_5", 443);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
            ipc_log_string(ipc_logbuf_low, "ipahal %s:%d fail to generate hw rule\n", "ipa_rt_gen_hw_rule_ipav5_5", 443);
          }
        }
        else
        {
          v26 = v44;
          *(_WORD *)a3 = v44;
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v27 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v27, "ipahal %s:%d en_rule 0x%x\n", "ipa_rt_gen_hw_rule_ipav5_5", 448, v26);
          }
          ipa_write_64(*(_QWORD *)a3, (_QWORD *)a3);
          v28 = *a2;
          if ( !(_DWORD)v28 )
          {
            result = 0;
            *a2 = LODWORD(v45[0]) - a3;
            goto LABEL_42;
          }
          v29 = v45[0] - a3;
          if ( v29 == v28 )
          {
            result = 0;
            goto LABEL_42;
          }
          printk(&unk_3B3D90, "ipa_rt_gen_hw_rule_ipav5_5");
          if ( ipa3_get_ipc_logbuf() )
          {
            v33 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v33,
              "ipahal %s:%d hw_len differs b/w passed=0x%x calc=%td\n",
              "ipa_rt_gen_hw_rule_ipav5_5",
              455,
              *a2,
              v29);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v34 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v34,
              "ipahal %s:%d hw_len differs b/w passed=0x%x calc=%td\n",
              "ipa_rt_gen_hw_rule_ipav5_5",
              455,
              *a2,
              v29);
          }
        }
        result = 0xFFFFFFFFLL;
        goto LABEL_42;
      }
      v41 = a1;
      ((void (*)(void))ipa_assert)();
      v15 = v41[6];
      a1 = v41;
      goto LABEL_18;
  }
  v35 = a1;
  printk(&unk_3D75DB, "ipa_rt_gen_hw_rule_ipav5_5");
  if ( ipa3_get_ipc_logbuf() )
  {
    v36 = ipa3_get_ipc_logbuf();
    ipc_log_string(v36, "ipahal %s:%d Invalid HDR type %d\n", "ipa_rt_gen_hw_rule_ipav5_5", 412, v35[2]);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v37 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v37, "ipahal %s:%d Invalid HDR type %d\n", "ipa_rt_gen_hw_rule_ipav5_5", 412, v35[2]);
  }
  result = 4294967274LL;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
