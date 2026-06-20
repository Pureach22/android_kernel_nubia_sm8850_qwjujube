__int64 __fastcall ipahal_flt_parse_hw_rule(const void *a1, const void *a2)
{
  __int64 v2; // x22
  long double v5; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 (__fastcall *v7)(const void *, const void *, long double); // x8
  __int64 ipc_logbuf; // x0
  __int64 v10; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v5 = ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Entry\n", "ipahal_flt_parse_hw_rule", 5557);
  }
  if ( a1 && a2 )
  {
    if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
    {
      __break(0x5512u);
      if ( (v2 & 0x80000000000LL) != 0 )
        JUMPOUT(0x1878A0);
      return ipa_fltrt_create_flt_bitmap(v5);
    }
    else
    {
      v7 = (__int64 (__fastcall *)(const void *, const void *, long double))ipahal_fltrt_objs[19
                                                                                            * *(unsigned int *)ipahal_ctx
                                                                                            + 15];
      if ( *((_DWORD *)v7 - 1) != -1785864310 )
        __break(0x8228u);
      return v7(a1, a2, v5);
    }
  }
  else
  {
    printk(&unk_3B1372, "ipahal_flt_parse_hw_rule");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipahal %s:%d Input err: rule_addr=%pK rule=%pK\n",
        "ipahal_flt_parse_hw_rule",
        5561,
        a1,
        a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v10 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v10, "ipahal %s:%d Input err: rule_addr=%pK rule=%pK\n", "ipahal_flt_parse_hw_rule", 5561, a1, a2);
    }
    return 4294967274LL;
  }
}
