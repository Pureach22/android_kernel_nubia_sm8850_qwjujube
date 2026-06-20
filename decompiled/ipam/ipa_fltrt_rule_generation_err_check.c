__int64 __fastcall ipa_fltrt_rule_generation_err_check(int a1, _BYTE *a2)
{
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x0
  __int64 v8; // x0

  if ( a1 == 1 )
  {
    if ( (*a2 & 3) == 0 )
      return 0;
    if ( (unsigned int)__ratelimit(&ipa_fltrt_rule_generation_err_check__rs_144, "ipa_fltrt_rule_generation_err_check") )
    {
      printk(&unk_3EB3BD, "ipa_fltrt_rule_generation_err_check");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_13:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            ipc_logbuf_low,
            "ipahal %s:%d v4 attrib's specified for v6 rule\n",
            "ipa_fltrt_rule_generation_err_check",
            166);
        }
        return 0xFFFFFFFFLL;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_13;
    }
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipahal %s:%d v4 attrib's specified for v6 rule\n",
      "ipa_fltrt_rule_generation_err_check",
      166);
    goto LABEL_13;
  }
  if ( a1 )
  {
    if ( (unsigned int)__ratelimit(&ipa_fltrt_rule_generation_err_check__rs_147, "ipa_fltrt_rule_generation_err_check") )
    {
      printk(&unk_3DA453, "ipa_fltrt_rule_generation_err_check");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_18:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v8 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v8, "ipahal %s:%d unsupported ip %d\n", "ipa_fltrt_rule_generation_err_check", 170, a1);
        }
        return 0xFFFFFFFFLL;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_18;
    }
    v7 = ipa3_get_ipc_logbuf();
    ipc_log_string(v7, "ipahal %s:%d unsupported ip %d\n", "ipa_fltrt_rule_generation_err_check", 170, a1);
    goto LABEL_18;
  }
  if ( (a2[1] & 0x38) != 0 )
  {
    if ( (unsigned int)__ratelimit(&ipa_fltrt_rule_generation_err_check__rs, "ipa_fltrt_rule_generation_err_check") )
    {
      printk(&unk_3C2BA2, "ipa_fltrt_rule_generation_err_check");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_7:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v4 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v4,
            "ipahal %s:%d v6 attrib's specified for v4 rule\n",
            "ipa_fltrt_rule_generation_err_check",
            160);
        }
        return 0xFFFFFFFFLL;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_7;
    }
    v3 = ipa3_get_ipc_logbuf();
    ipc_log_string(v3, "ipahal %s:%d v6 attrib's specified for v4 rule\n", "ipa_fltrt_rule_generation_err_check", 160);
    goto LABEL_7;
  }
  return 0;
}
