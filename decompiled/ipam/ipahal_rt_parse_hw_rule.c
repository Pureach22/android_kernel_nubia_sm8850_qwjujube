__int64 __fastcall ipahal_rt_parse_hw_rule(const void *a1, const void *a2)
{
  long double v4; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 (__fastcall *v6)(const void *, const void *, long double); // x8
  __int64 ipc_logbuf; // x0
  __int64 v9; // x0
  __int64 v10; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v4 = ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Entry\n", "ipahal_rt_parse_hw_rule", 5536);
  }
  if ( a1 && a2 )
  {
    if ( *(_DWORD *)ipahal_ctx >= 0x1Au )
    {
      __break(0x5512u);
      v10 = MEMORY[0x6503A08](v4);
      return ipahal_flt_parse_hw_rule(v10);
    }
    else
    {
      v6 = (__int64 (__fastcall *)(const void *, const void *, long double))ipahal_fltrt_objs[19
                                                                                            * *(unsigned int *)ipahal_ctx
                                                                                            + 14];
      if ( *((_DWORD *)v6 - 1) != 1564723355 )
        __break(0x8228u);
      return v6(a1, a2, v4);
    }
  }
  else
  {
    printk(&unk_3B1372, "ipahal_rt_parse_hw_rule");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipahal %s:%d Input err: rule_addr=%pK rule=%pK\n",
        "ipahal_rt_parse_hw_rule",
        5540,
        a1,
        a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v9 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v9, "ipahal %s:%d Input err: rule_addr=%pK rule=%pK\n", "ipahal_rt_parse_hw_rule", 5540, a1, a2);
    }
    return 4294967274LL;
  }
}
