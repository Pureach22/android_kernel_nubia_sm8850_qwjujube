__int64 __fastcall ipa_fltrt_generate_hw_rule_bdy(unsigned int a1, _DWORD *a2, _BYTE **a3, _WORD *a4)
{
  __int64 v8; // x19
  __int64 v9; // x20
  char *v10; // x26
  char *v11; // x25
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  unsigned int v14; // w22
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  char *v22; // x1
  _DWORD *v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned int v26; // w22
  __int64 v27; // x0
  _BYTE *i; // x8
  char v29; // t1
  char *v30; // x0
  unsigned int v31; // w22
  __int64 v32; // x0
  _BYTE *j; // x8
  char v34; // t1
  unsigned __int64 StatusReg; // x20
  __int64 v36; // x25
  __int64 (__fastcall *v37)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD); // x0
  char *v39; // [xsp+8h] [xbp-18h] BYREF
  char *v40[2]; // [xsp+10h] [xbp-10h] BYREF

  v40[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 23);
  if ( v8 )
  {
    while ( 1 )
    {
      v9 = _kmalloc_cache_noprof(scnprintf, 3520, 263);
      if ( !v9 )
        break;
      v10 = (char *)((v8 + 7) & 0xFFFFFFFFFFFFFFF8LL);
      v11 = (char *)((v9 + 7) & 0xFFFFFFFFFFFFFFF8LL);
      v39 = v11;
      v40[0] = v10;
      if ( (unsigned int)ipa_fltrt_rule_generation_err_check(a1, a2) )
      {
        if ( (unsigned int)__ratelimit(&ipa_fltrt_generate_hw_rule_bdy__rs, "ipa_fltrt_generate_hw_rule_bdy") )
        {
          printk(&unk_3DD3A9, "ipa_fltrt_generate_hw_rule_bdy");
          if ( ipa3_get_ipc_logbuf() )
          {
LABEL_6:
            ipc_logbuf = ipa3_get_ipc_logbuf();
            ipc_log_string(
              ipc_logbuf,
              "ipahal %s:%d rule generation err check failed\n",
              "ipa_fltrt_generate_hw_rule_bdy",
              2451);
          }
        }
        else if ( ipa3_get_ipc_logbuf() )
        {
          goto LABEL_6;
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            ipc_logbuf_low,
            "ipahal %s:%d rule generation err check failed\n",
            "ipa_fltrt_generate_hw_rule_bdy",
            2451);
        }
        goto LABEL_9;
      }
      if ( a1 == 1 )
      {
        if ( (unsigned int)ipa_fltrt_generate_hw_rule_bdy_ip6(a4, a2, v40, &v39) )
        {
          if ( (unsigned int)__ratelimit(&ipa_fltrt_generate_hw_rule_bdy__rs_131, "ipa_fltrt_generate_hw_rule_bdy") )
          {
            printk(&unk_3A8B7B, "ipa_fltrt_generate_hw_rule_bdy");
            if ( ipa3_get_ipc_logbuf() )
            {
LABEL_22:
              v17 = ipa3_get_ipc_logbuf();
              ipc_log_string(v17, "ipahal %s:%d failed to build ipv6 hw rule\n", "ipa_fltrt_generate_hw_rule_bdy", 2466);
            }
          }
          else if ( ipa3_get_ipc_logbuf() )
          {
            goto LABEL_22;
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v18 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v18, "ipahal %s:%d failed to build ipv6 hw rule\n", "ipa_fltrt_generate_hw_rule_bdy", 2466);
          }
LABEL_9:
          v14 = -1;
          goto LABEL_10;
        }
      }
      else
      {
        if ( a1 )
        {
          if ( (unsigned int)__ratelimit(&ipa_fltrt_generate_hw_rule_bdy__rs_134, "ipa_fltrt_generate_hw_rule_bdy") )
          {
            printk(&unk_3DA453, "ipa_fltrt_generate_hw_rule_bdy");
            if ( ipa3_get_ipc_logbuf() )
            {
LABEL_27:
              v19 = ipa3_get_ipc_logbuf();
              ipc_log_string(v19, "ipahal %s:%d unsupported ip %d\n", "ipa_fltrt_generate_hw_rule_bdy", 2471, a1);
            }
          }
          else if ( ipa3_get_ipc_logbuf() )
          {
            goto LABEL_27;
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v20 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v20, "ipahal %s:%d unsupported ip %d\n", "ipa_fltrt_generate_hw_rule_bdy", 2471, a1);
          }
          v14 = 0;
          goto LABEL_10;
        }
        if ( (unsigned int)ipa_fltrt_generate_hw_rule_bdy_ip4(a4, a2, v40, &v39) )
        {
          if ( (unsigned int)__ratelimit(&ipa_fltrt_generate_hw_rule_bdy__rs_128, "ipa_fltrt_generate_hw_rule_bdy") )
          {
            printk(&unk_3D4805, "ipa_fltrt_generate_hw_rule_bdy");
            if ( ipa3_get_ipc_logbuf() )
            {
LABEL_16:
              v15 = ipa3_get_ipc_logbuf();
              ipc_log_string(v15, "ipahal %s:%d failed to build ipv4 hw rule\n", "ipa_fltrt_generate_hw_rule_bdy", 2458);
            }
          }
          else if ( ipa3_get_ipc_logbuf() )
          {
            goto LABEL_16;
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v16 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v16, "ipahal %s:%d failed to build ipv4 hw rule\n", "ipa_fltrt_generate_hw_rule_bdy", 2458);
          }
          goto LABEL_9;
        }
      }
      if ( *a2 )
        goto LABEL_36;
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v21 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v21, "ipahal %s:%d building default rule\n", "ipa_fltrt_generate_hw_rule_bdy", 2480);
      }
      if ( *(_DWORD *)ipahal_ctx < 0x1Au )
      {
        v22 = v40[0];
        *a4 |= 1LL << BYTE5(ipahal_fltrt_objs[19 * *(unsigned int *)ipahal_ctx + 16]);
        v40[0] = ipa_write_8(0, v22);
        v23 = ipa_write_32(0, v39);
        v39 = (char *)ipa_write_32(0, v23);
LABEL_36:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v24 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v24,
            "ipahal %s:%d extra_word_1 0x%llx\n",
            "ipa_fltrt_generate_hw_rule_bdy",
            2487,
            *(_QWORD *)v10);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v25 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v25,
            "ipahal %s:%d extra_word_2 0x%llx\n",
            "ipa_fltrt_generate_hw_rule_bdy",
            2489,
            *((_QWORD *)v10 + 1));
        }
        v26 = (unsigned int)ipa_pad_to_64(v40[0]) - (_DWORD)v10;
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v27 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v27, "ipahal %s:%d extra words params sz %d\n", "ipa_fltrt_generate_hw_rule_bdy", 2493, v26);
        }
        for ( i = *a3; v26; ++i )
        {
          v29 = *v10++;
          --v26;
          *i = v29;
        }
        v30 = v39;
        *a3 = i;
        v31 = (unsigned int)ipa_pad_to_64(v30) - (_DWORD)v11;
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v32 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v32,
            "ipahal %s:%d non extra words params sz %d\n",
            "ipa_fltrt_generate_hw_rule_bdy",
            2498,
            v31);
        }
        for ( j = *a3; v31; ++j )
        {
          v34 = *v11++;
          --v31;
          *j = v34;
        }
        v14 = 0;
        *a3 = j;
LABEL_10:
        kfree(v9);
        goto LABEL_61;
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v36 = *(_QWORD *)(StatusReg + 80);
      v37 = of_property_read_variable_u32_array;
      *(_QWORD *)(StatusReg + 80) = &ipa_fltrt_generate_hw_rule_bdy__alloc_tag;
      v8 = _kmalloc_cache_noprof(v37, 3520, 23);
      *(_QWORD *)(StatusReg + 80) = v36;
      if ( !v8 )
        goto LABEL_59;
    }
    v14 = -12;
LABEL_61:
    kfree(v8);
  }
  else
  {
LABEL_59:
    v14 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v14;
}
