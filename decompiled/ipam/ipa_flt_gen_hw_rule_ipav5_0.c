__int64 __fastcall ipa_flt_gen_hw_rule_ipav5_0(unsigned int *a1, unsigned int *a2, __int64 *a3)
{
  __int64 v4; // x8
  int v5; // w8
  unsigned __int64 v6; // x8
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v9; // x9
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x8
  __int64 v15; // x9
  unsigned __int64 v16; // x8
  __int64 v17; // x9
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 result; // x0
  __int64 v29; // x8
  unsigned __int64 v30; // x8
  __int64 v31; // x8
  unsigned __int16 *v32; // x19
  int v33; // w19
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x3
  __int64 v37; // x19
  __int64 v38; // x0
  __int64 v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  _WORD v44[2]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v45[2]; // [xsp+10h] [xbp-10h] BYREF

  v45[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *((_QWORD *)a1 + 3);
  v44[0] = 0;
  v5 = *(_DWORD *)(v4 + 4);
  if ( v5 > 1 )
  {
    if ( v5 == 2 )
    {
      v6 = *a3 & 0xFE0FFFFFFFFFFFFFLL | 0x20000000000000LL;
    }
    else
    {
      if ( v5 != 3 )
        goto LABEL_8;
      v6 = *a3 & 0xFE0FFFFFFFFFFFFFLL | 0x30000000000000LL;
    }
  }
  else
  {
    if ( v5 )
    {
      if ( v5 == 1 )
      {
        v6 = *a3 & 0xFE0FFFFFFFFFFFFFLL | 0x10000000000000LL;
        goto LABEL_15;
      }
LABEL_8:
      if ( (unsigned int)__ratelimit(&ipa_flt_gen_hw_rule_ipav5_0__rs, "ipa_flt_gen_hw_rule_ipav5_0") )
      {
        printk(&unk_3EB3EF, "ipa_flt_gen_hw_rule_ipav5_0");
        if ( !ipa3_get_ipc_logbuf() )
        {
LABEL_11:
          if ( ipa3_get_ipc_logbuf_low() )
          {
            ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              ipc_logbuf_low,
              "ipahal %s:%d Invalid Rule Action %d\n",
              "ipa_flt_gen_hw_rule_ipav5_0",
              744,
              *(unsigned int *)(*((_QWORD *)a1 + 3) + 4LL));
          }
          goto LABEL_39;
        }
      }
      else if ( !ipa3_get_ipc_logbuf() )
      {
        goto LABEL_11;
      }
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipahal %s:%d Invalid Rule Action %d\n",
        "ipa_flt_gen_hw_rule_ipav5_0",
        744,
        *(_DWORD *)(*((_QWORD *)a1 + 3) + 4LL));
      goto LABEL_11;
    }
    v6 = *a3 & 0xFE0FFFFFFFFFFFFFLL;
  }
LABEL_15:
  *a3 = v6;
  v9 = a1[1];
  if ( (unsigned int)v9 >= 0x100 )
  {
    if ( (unsigned int)__ratelimit(&ipa_flt_gen_hw_rule_ipav5_0__rs_209, "ipa_flt_gen_hw_rule_ipav5_0") )
    {
      printk(&unk_3D768C, "ipa_flt_gen_hw_rule_ipav5_0");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_27:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v21 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v21, "ipahal %s:%d Invalid RT table idx 0x%X\n", "ipa_flt_gen_hw_rule_ipav5_0", 751, a1[1]);
        }
        goto LABEL_39;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_27;
    }
    v20 = ipa3_get_ipc_logbuf();
    ipc_log_string(v20, "ipahal %s:%d Invalid RT table idx 0x%X\n", "ipa_flt_gen_hw_rule_ipav5_0", 751, a1[1]);
    goto LABEL_27;
  }
  v10 = v6 & 0xFFFFFFFFFF00FFFFLL | (v9 << 16);
  *a3 = v10;
  v11 = v10 & 0xBFFFFFFFFFFFFFFFLL | ((unsigned __int64)(**((_BYTE **)a1 + 3) != 0) << 62);
  *a3 = v11;
  v12 = *(unsigned __int8 *)(*((_QWORD *)a1 + 3) + 359LL);
  if ( v12 >= 0x10 )
  {
    if ( (unsigned int)__ratelimit(&ipa_flt_gen_hw_rule_ipav5_0__rs_212, "ipa_flt_gen_hw_rule_ipav5_0") )
    {
      printk(&unk_3F11B2, "ipa_flt_gen_hw_rule_ipav5_0");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_32:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v23 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v23,
            "ipahal %s:%d Invalid PDN idx 0x%X\n",
            "ipa_flt_gen_hw_rule_ipav5_0",
            759,
            *(unsigned __int8 *)(*((_QWORD *)a1 + 3) + 359LL));
        }
        goto LABEL_39;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_32;
    }
    v22 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v22,
      "ipahal %s:%d Invalid PDN idx 0x%X\n",
      "ipa_flt_gen_hw_rule_ipav5_0",
      759,
      *(unsigned __int8 *)(*((_QWORD *)a1 + 3) + 359LL));
    goto LABEL_32;
  }
  v13 = v11 & 0xE1FFFFFFFFFFFFFFLL | (v12 << 57);
  *a3 = v13;
  v14 = v13 & 0x5FFFFEFFFFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(*((_QWORD *)a1 + 3) + 358LL) != 0) << 61);
  *a3 = v14;
  v15 = a1[2];
  if ( (unsigned int)v15 >= 0x100 )
  {
    if ( (unsigned int)__ratelimit(&ipa_flt_gen_hw_rule_ipav5_0__rs_215, "ipa_flt_gen_hw_rule_ipav5_0") )
    {
      printk(&unk_3FA248, "ipa_flt_gen_hw_rule_ipav5_0");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_37:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v25 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v25, "ipahal %s:%d Invalid priority 0x%X\n", "ipa_flt_gen_hw_rule_ipav5_0", 769, a1[2]);
        }
        goto LABEL_39;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_37;
    }
    v24 = ipa3_get_ipc_logbuf();
    ipc_log_string(v24, "ipahal %s:%d Invalid priority 0x%X\n", "ipa_flt_gen_hw_rule_ipav5_0", 769, a1[2]);
    goto LABEL_37;
  }
  v16 = v14 & 0xFFFFFE00FFFFFFFFLL | (v15 << 32);
  *a3 = v16;
  v17 = a1[3];
  if ( (unsigned int)v17 < 0x3FF )
  {
    v29 = v16 & 0x7FF002FFFFFFFFFFLL | (v17 << 42);
    *a3 = v29;
    v30 = v29 & 0xFFFFFFFF00FFFFFFLL | ((unsigned __int64)*((unsigned __int8 *)a1 + 16) << 24);
    *a3 = v30;
    *a3 = v30 & 0xFFFFFDFFFFFFFFFFLL | ((unsigned __int64)(*(_BYTE *)(*((_QWORD *)a1 + 3) + 362LL) != 0) << 41);
    v31 = *((_QWORD *)a1 + 3);
    v45[0] = a3 + 1;
    if ( *(_BYTE *)(v31 + 352) )
    {
      if ( (unsigned int)ipa_fltrt_generate_hw_rule_bdy_from_eq(v31 + 164, v45) )
      {
        printk(&unk_3CEB33, "ipa_flt_gen_hw_rule_ipav5_0");
        if ( ipa3_get_ipc_logbuf() )
        {
          v38 = ipa3_get_ipc_logbuf();
          ipc_log_string(v38, "ipahal %s:%d fail to generate hw rule from eq\n", "ipa_flt_gen_hw_rule_ipav5_0", 790);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v39 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v39, "ipahal %s:%d fail to generate hw rule from eq\n", "ipa_flt_gen_hw_rule_ipav5_0", 790);
        }
        goto LABEL_75;
      }
      v32 = (unsigned __int16 *)(*((_QWORD *)a1 + 3) + 164LL);
    }
    else
    {
      v32 = v44;
      if ( (unsigned int)ipa_fltrt_generate_hw_rule_bdy(*a1, v31 + 12, v45, v44) )
      {
        printk(&unk_3C2B3C, "ipa_flt_gen_hw_rule_ipav5_0");
        if ( ipa3_get_ipc_logbuf() )
        {
          v42 = ipa3_get_ipc_logbuf();
          ipc_log_string(v42, "ipahal %s:%d fail to generate hw rule\n", "ipa_flt_gen_hw_rule_ipav5_0", 797);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v43 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v43, "ipahal %s:%d fail to generate hw rule\n", "ipa_flt_gen_hw_rule_ipav5_0", 797);
        }
        goto LABEL_75;
      }
    }
    v33 = *v32;
    *(_WORD *)a3 = v33;
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v34 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v34,
        "ipahal %s:%d en_rule=0x%x, action=%d, rt_idx=%d, retain_hdr=%d\n",
        "ipa_flt_gen_hw_rule_ipav5_0",
        807,
        v33,
        ((unsigned __int64)*a3 >> 52) & 0x1F,
        (unsigned __int8)BYTE2(*a3),
        (*a3 & 0x4000000000000000LL) != 0);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v35 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v35,
        "ipahal %s:%d priority=%d, rule_id=%d, pdn=%d, set_metadata=%d\n",
        "ipa_flt_gen_hw_rule_ipav5_0",
        812,
        (unsigned __int8)BYTE4(*a3),
        ((unsigned __int64)*a3 >> 42) & 0x3FF,
        ((unsigned __int64)*a3 >> 57) & 0xF,
        (*a3 & 0x2000000000000000LL) != 0);
    }
    ipa_write_64(*a3, a3);
    v36 = *a2;
    if ( !(_DWORD)v36 )
    {
      result = 0;
      *a2 = LODWORD(v45[0]) - (_DWORD)a3;
      goto LABEL_40;
    }
    v37 = v45[0] - (_QWORD)a3;
    if ( v45[0] - (_QWORD)a3 == v36 )
    {
      result = 0;
      goto LABEL_40;
    }
    printk(&unk_3B3D90, "ipa_flt_gen_hw_rule_ipav5_0");
    if ( ipa3_get_ipc_logbuf() )
    {
      v40 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v40,
        "ipahal %s:%d hw_len differs b/w passed=0x%x calc=%td\n",
        "ipa_flt_gen_hw_rule_ipav5_0",
        820,
        *a2,
        v37);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v41 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v41,
        "ipahal %s:%d hw_len differs b/w passed=0x%x calc=%td\n",
        "ipa_flt_gen_hw_rule_ipav5_0",
        820,
        *a2,
        v37);
    }
LABEL_75:
    result = 0xFFFFFFFFLL;
    goto LABEL_40;
  }
  if ( !(unsigned int)__ratelimit(&ipa_flt_gen_hw_rule_ipav5_0__rs_218, "ipa_flt_gen_hw_rule_ipav5_0") )
  {
    if ( !ipa3_get_ipc_logbuf() )
      goto LABEL_22;
    goto LABEL_21;
  }
  printk(&unk_3D48CC, "ipa_flt_gen_hw_rule_ipav5_0");
  if ( ipa3_get_ipc_logbuf() )
  {
LABEL_21:
    v18 = ipa3_get_ipc_logbuf();
    ipc_log_string(v18, "ipahal %s:%d Invalid id 0x%X\n", "ipa_flt_gen_hw_rule_ipav5_0", 776, a1[3]);
  }
LABEL_22:
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v19 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v19, "ipahal %s:%d Invalid id 0x%X\n", "ipa_flt_gen_hw_rule_ipav5_0", 776, a1[3]);
  }
LABEL_39:
  result = 4294967274LL;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
