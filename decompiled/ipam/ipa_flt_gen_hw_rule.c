__int64 __fastcall ipa_flt_gen_hw_rule(__int64 a1, unsigned int *a2, __int64 *a3)
{
  unsigned int *v5; // x21
  __int64 v6; // x8
  int v7; // w8
  unsigned __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 result; // x0
  unsigned int v12; // w9
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x8
  unsigned int v15; // w9
  unsigned int v16; // w8
  __int64 v17; // x8
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v20; // x0
  unsigned __int16 *v21; // x21
  __int64 v22; // x0
  __int64 v23; // x0
  int v24; // w21
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x20
  __int64 v29; // x0
  __int64 v30; // x0
  _WORD v31[2]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v32[2]; // [xsp+10h] [xbp-10h] BYREF

  v5 = (unsigned int *)a1;
  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 24);
  v32[0] = a3;
  v31[0] = 0;
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
        goto LABEL_8;
      v8 = *a3 & 0xFFFFFFFFFFE0FFFFLL | 0x30000;
    }
LABEL_16:
    *a3 = v8;
    v12 = *(_DWORD *)(a1 + 4);
    if ( v12 >= 0x20 )
    {
      a1 = ((__int64 (*)(void))ipa_assert)();
      v12 = v5[1];
      v8 = *a3;
    }
    v13 = v8 & 0xFFFFFFFFFC1FFFFFLL | ((unsigned __int8)(v12 & 0x1F) << 21);
    *a3 = v13;
    v14 = v13 & 0x3FF03FF03FFFFFFLL | ((unsigned __int64)(**((_BYTE **)v5 + 3) != 0) << 26);
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
        goto LABEL_22;
    }
    else if ( v16 != 1023 )
    {
      goto LABEL_22;
    }
    ((void (__fastcall *)(__int64))ipa_assert)(a1);
    v16 = v5[3];
LABEL_22:
    *a3 = *a3 & 0xFC00FFFFFFFFFFFFLL | ((unsigned __int64)(v16 & 0x3FF) << 48);
    v17 = *((_QWORD *)v5 + 3);
    v32[0] = a3 + 1;
    if ( *(_BYTE *)(v17 + 352) )
    {
      if ( (unsigned int)ipa_fltrt_generate_hw_rule_bdy_from_eq(v17 + 164, v32) )
      {
        if ( (unsigned int)__ratelimit(&ipa_flt_gen_hw_rule__rs_167, "ipa_flt_gen_hw_rule") )
        {
          printk(&unk_3CEB33, "ipa_flt_gen_hw_rule");
          if ( !ipa3_get_ipc_logbuf() )
          {
LABEL_27:
            if ( ipa3_get_ipc_logbuf_low() )
            {
              ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                ipc_logbuf_low,
                "ipahal %s:%d fail to generate hw rule from eq\n",
                "ipa_flt_gen_hw_rule",
                508);
            }
LABEL_49:
            result = 0xFFFFFFFFLL;
            goto LABEL_50;
          }
        }
        else if ( !ipa3_get_ipc_logbuf() )
        {
          goto LABEL_27;
        }
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(ipc_logbuf, "ipahal %s:%d fail to generate hw rule from eq\n", "ipa_flt_gen_hw_rule", 508);
        goto LABEL_27;
      }
      v21 = (unsigned __int16 *)(*((_QWORD *)v5 + 3) + 164LL);
LABEL_36:
      v24 = *v21;
      *(_WORD *)a3 = v24;
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v25 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v25,
          "ipahal %s:%d en_rule=0x%x, action=%d, rt_idx=%d, retain_hdr=%d\n",
          "ipa_flt_gen_hw_rule",
          525,
          v24,
          HIWORD(*(_DWORD *)a3) & 0x1F,
          (*(_DWORD *)a3 >> 21) & 0x1F,
          (*(_DWORD *)a3 >> 26) & 1);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v26 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v26,
          "ipahal %s:%d priority=%d, rule_id=%d\n",
          "ipa_flt_gen_hw_rule",
          528,
          HIDWORD(*a3) & 0x3FF,
          HIWORD(*a3) & 0x3FF);
      }
      ipa_write_64(*a3, a3);
      v27 = *a2;
      if ( !(_DWORD)v27 )
      {
        result = 0;
        *a2 = LODWORD(v32[0]) - (_DWORD)a3;
        goto LABEL_50;
      }
      v28 = v32[0] - (_QWORD)a3;
      if ( v28 == v27 )
      {
        result = 0;
        goto LABEL_50;
      }
      if ( (unsigned int)__ratelimit(&ipa_flt_gen_hw_rule__rs_173, "ipa_flt_gen_hw_rule") )
      {
        printk(&unk_3B3D90, "ipa_flt_gen_hw_rule");
        if ( !ipa3_get_ipc_logbuf() )
        {
LABEL_47:
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v30 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v30,
              "ipahal %s:%d hw_len differs b/w passed=0x%x calc=%td\n",
              "ipa_flt_gen_hw_rule",
              536,
              *a2,
              v28);
          }
          goto LABEL_49;
        }
      }
      else if ( !ipa3_get_ipc_logbuf() )
      {
        goto LABEL_47;
      }
      v29 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v29,
        "ipahal %s:%d hw_len differs b/w passed=0x%x calc=%td\n",
        "ipa_flt_gen_hw_rule",
        536,
        *a2,
        v28);
      goto LABEL_47;
    }
    v20 = *v5;
    v21 = v31;
    if ( !(unsigned int)ipa_fltrt_generate_hw_rule_bdy(v20, v17 + 12, v32, v31) )
      goto LABEL_36;
    if ( (unsigned int)__ratelimit(&ipa_flt_gen_hw_rule__rs_170, "ipa_flt_gen_hw_rule") )
    {
      printk(&unk_3C2B3C, "ipa_flt_gen_hw_rule");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_33:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v23 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v23, "ipahal %s:%d fail to generate hw rule\n", "ipa_flt_gen_hw_rule", 515);
        }
        goto LABEL_49;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_33;
    }
    v22 = ipa3_get_ipc_logbuf();
    ipc_log_string(v22, "ipahal %s:%d fail to generate hw rule\n", "ipa_flt_gen_hw_rule", 515);
    goto LABEL_33;
  }
  if ( !v7 )
  {
    v8 = *a3 & 0xFFFFFFFFFFE0FFFFLL;
    goto LABEL_16;
  }
  if ( v7 == 1 )
  {
    v8 = *a3 & 0xFFFFFFFFFFE0FFFFLL | 0x10000;
    goto LABEL_16;
  }
LABEL_8:
  if ( (unsigned int)__ratelimit(&ipa_flt_gen_hw_rule__rs, "ipa_flt_gen_hw_rule") )
  {
    printk(&unk_3EB3EF, "ipa_flt_gen_hw_rule");
    if ( !ipa3_get_ipc_logbuf() )
      goto LABEL_11;
    goto LABEL_10;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
LABEL_10:
    v9 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v9,
      "ipahal %s:%d Invalid Rule Action %d\n",
      "ipa_flt_gen_hw_rule",
      486,
      *(_DWORD *)(*((_QWORD *)v5 + 3) + 4LL));
  }
LABEL_11:
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v10 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v10,
      "ipahal %s:%d Invalid Rule Action %d\n",
      "ipa_flt_gen_hw_rule",
      486,
      *(_DWORD *)(*((_QWORD *)v5 + 3) + 4LL));
  }
  result = 4294967274LL;
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
