__int64 __fastcall ipa_fltrt_generate_hw_rule_bdy_5_5(int a1, int *a2, const char **a3, _WORD *a4, char a5)
{
  __int64 v10; // x19
  __int64 v11; // x20
  char *v12; // x27
  char *v13; // x26
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int v16; // w21
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  _BYTE *v24; // x1
  _DWORD *v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  int v28; // w22
  __int64 v29; // x0
  char *i; // x8
  char v31; // t1
  __int64 v32; // x0
  char *j; // x0
  unsigned int v34; // w22
  __int64 v35; // x0
  char v36; // t1
  __int64 v37; // x0
  unsigned int v38; // w22
  __int64 v39; // x0
  char *k; // x8
  char v41; // t1
  __int64 v42; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v44; // x26
  __int64 (__fastcall *v45)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD); // x0
  char *v47; // [xsp+8h] [xbp-18h] BYREF
  _BYTE *v48[2]; // [xsp+10h] [xbp-10h] BYREF

  v48[1] = *(_BYTE **)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 23);
  if ( v10 )
  {
    while ( 1 )
    {
      v11 = _kmalloc_cache_noprof(scnprintf, 3520, 263);
      if ( !v11 )
        break;
      v12 = (char *)((v10 + 7) & 0xFFFFFFFFFFFFFFF8LL);
      v13 = (char *)((v11 + 7) & 0xFFFFFFFFFFFFFFF8LL);
      v47 = v13;
      v48[0] = v12;
      if ( (unsigned int)ipa_fltrt_rule_generation_err_check(a1, a2) )
      {
        if ( (unsigned int)__ratelimit(&ipa_fltrt_generate_hw_rule_bdy_5_5__rs, "ipa_fltrt_generate_hw_rule_bdy_5_5") )
        {
          printk(&unk_3DD3A9, "ipa_fltrt_generate_hw_rule_bdy_5_5");
          if ( ipa3_get_ipc_logbuf() )
          {
LABEL_6:
            ipc_logbuf = ipa3_get_ipc_logbuf();
            ipc_log_string(
              ipc_logbuf,
              "ipahal %s:%d rule generation err check failed\n",
              "ipa_fltrt_generate_hw_rule_bdy_5_5",
              2559);
          }
        }
        else if ( ipa3_get_ipc_logbuf() )
        {
          goto LABEL_6;
        }
        if ( !ipa3_get_ipc_logbuf_low() )
          goto LABEL_24;
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipahal %s:%d rule generation err check failed\n",
          "ipa_fltrt_generate_hw_rule_bdy_5_5",
          2559);
        goto LABEL_9;
      }
      if ( a1 == 1 )
      {
        if ( (unsigned int)ipa_fltrt_generate_hw_rule_bdy_ip6(a4, a2, v48, (_WORD **)&v47) )
        {
          if ( (unsigned int)__ratelimit(
                               &ipa_fltrt_generate_hw_rule_bdy_5_5__rs_225,
                               "ipa_fltrt_generate_hw_rule_bdy_5_5") )
          {
            printk(&unk_3A8B7B, "ipa_fltrt_generate_hw_rule_bdy_5_5");
            if ( ipa3_get_ipc_logbuf() )
            {
LABEL_21:
              v19 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v19,
                "ipahal %s:%d failed to build ipv6 hw rule\n",
                "ipa_fltrt_generate_hw_rule_bdy_5_5",
                2574);
            }
          }
          else if ( ipa3_get_ipc_logbuf() )
          {
            goto LABEL_21;
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v20 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v20,
              "ipahal %s:%d failed to build ipv6 hw rule\n",
              "ipa_fltrt_generate_hw_rule_bdy_5_5",
              2574);
            goto LABEL_9;
          }
LABEL_24:
          v16 = -1;
          goto LABEL_60;
        }
      }
      else
      {
        if ( a1 )
        {
          if ( (unsigned int)__ratelimit(
                               &ipa_fltrt_generate_hw_rule_bdy_5_5__rs_226,
                               "ipa_fltrt_generate_hw_rule_bdy_5_5") )
          {
            printk(&unk_3DA453, "ipa_fltrt_generate_hw_rule_bdy_5_5");
            if ( ipa3_get_ipc_logbuf() )
            {
LABEL_27:
              v21 = ipa3_get_ipc_logbuf();
              ipc_log_string(v21, "ipahal %s:%d unsupported ip %d\n", "ipa_fltrt_generate_hw_rule_bdy_5_5", 2579, a1);
            }
          }
          else if ( ipa3_get_ipc_logbuf() )
          {
            goto LABEL_27;
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v22 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v22, "ipahal %s:%d unsupported ip %d\n", "ipa_fltrt_generate_hw_rule_bdy_5_5", 2579, a1);
          }
          goto LABEL_59;
        }
        if ( (unsigned int)ipa_fltrt_generate_hw_rule_bdy_ip4(a4, a2, v48, (_WORD **)&v47) )
        {
          if ( (unsigned int)__ratelimit(
                               &ipa_fltrt_generate_hw_rule_bdy_5_5__rs_224,
                               "ipa_fltrt_generate_hw_rule_bdy_5_5") )
          {
            printk(&unk_3D4805, "ipa_fltrt_generate_hw_rule_bdy_5_5");
            if ( ipa3_get_ipc_logbuf() )
            {
LABEL_15:
              v17 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v17,
                "ipahal %s:%d failed to build ipv4 hw rule\n",
                "ipa_fltrt_generate_hw_rule_bdy_5_5",
                2566);
            }
          }
          else if ( ipa3_get_ipc_logbuf() )
          {
            goto LABEL_15;
          }
          if ( !ipa3_get_ipc_logbuf_low() )
            goto LABEL_24;
          v18 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v18, "ipahal %s:%d failed to build ipv4 hw rule\n", "ipa_fltrt_generate_hw_rule_bdy_5_5", 2566);
LABEL_9:
          v16 = -1;
          goto LABEL_60;
        }
      }
      if ( *a2 )
        goto LABEL_35;
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v23 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v23, "ipahal %s:%d building default rule\n", "ipa_fltrt_generate_hw_rule_bdy_5_5", 2588);
      }
      if ( *(_DWORD *)ipahal_ctx < 0x1Au )
      {
        v24 = v48[0];
        *a4 |= 1LL << BYTE5(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 16]);
        v48[0] = ipa_write_8(0, v24);
        v25 = ipa_write_32(0, v47);
        v47 = (char *)ipa_write_32(0, v25);
LABEL_35:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v26 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v26,
            "ipahal %s:%d extra_word_1 0x%llx\n",
            "ipa_fltrt_generate_hw_rule_bdy_5_5",
            2595,
            *(_QWORD *)v12);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v27 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v27,
            "ipahal %s:%d extra_word_2 0x%llx\n",
            "ipa_fltrt_generate_hw_rule_bdy_5_5",
            2597,
            *((_QWORD *)v12 + 1));
        }
        if ( (a5 & 1) != 0 )
        {
          v28 = LODWORD(v48[0]) - (_DWORD)v12;
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v29 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v29,
              "ipahal %s:%d extra words params sz %d, buf: 0x%s, \n",
              "ipa_fltrt_generate_hw_rule_bdy_5_5",
              2601,
              v28,
              *a3);
          }
          for ( i = (char *)*a3; v28; ++i )
          {
            v31 = *v12++;
            --v28;
            *i = v31;
          }
          *a3 = i;
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v32 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v32,
              "ipahal %s:%d After extra copy *buf 0x%s\n",
              "ipa_fltrt_generate_hw_rule_bdy_5_5",
              2603,
              *a3);
          }
          j = ipa_pad_to_64((char *)*a3);
        }
        else
        {
          v34 = (unsigned int)ipa_pad_to_64(v48[0]) - (_DWORD)v12;
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v35 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v35,
              "ipahal %s:%d extra words params sz %d, buf: 0x%s, \n",
              "ipa_fltrt_generate_hw_rule_bdy_5_5",
              2608,
              v34,
              *a3);
          }
          for ( j = (char *)*a3; v34; ++j )
          {
            v36 = *v12++;
            --v34;
            *j = v36;
          }
        }
        *a3 = j;
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v37 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v37, "ipahal %s:%d Updated *buf 0x%s\n", "ipa_fltrt_generate_hw_rule_bdy_5_5", 2611, *a3);
        }
        v38 = (unsigned int)ipa_pad_to_64(v47) - (_DWORD)v13;
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v39 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v39,
            "ipahal %s:%d non extra words params sz %d\n",
            "ipa_fltrt_generate_hw_rule_bdy_5_5",
            2615,
            v38);
        }
        for ( k = (char *)*a3; v38; ++k )
        {
          v41 = *v13++;
          --v38;
          *k = v41;
        }
        *a3 = k;
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v42 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v42,
            "ipahal %s:%d After rest copy *buf 0x%s\n",
            "ipa_fltrt_generate_hw_rule_bdy_5_5",
            2617,
            *a3);
        }
LABEL_59:
        v16 = 0;
LABEL_60:
        kfree(v11);
        goto LABEL_72;
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v44 = *(_QWORD *)(StatusReg + 80);
      v45 = of_property_read_variable_u32_array;
      *(_QWORD *)(StatusReg + 80) = &ipa_fltrt_generate_hw_rule_bdy_5_5__alloc_tag;
      v10 = _kmalloc_cache_noprof(v45, 3520, 23);
      *(_QWORD *)(StatusReg + 80) = v44;
      if ( !v10 )
        goto LABEL_70;
    }
    v16 = -12;
LABEL_72:
    kfree(v10);
  }
  else
  {
LABEL_70:
    v16 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v16;
}
