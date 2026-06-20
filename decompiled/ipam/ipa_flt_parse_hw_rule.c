__int64 __fastcall ipa_flt_parse_hw_rule(__int64 a1, __int64 a2)
{
  long double v4; // q0
  __int64 ipc_logbuf_low; // x0
  unsigned int v6; // w3
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 v9; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v4 = ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Entry\n", "ipa_flt_parse_hw_rule", 4311);
  }
  if ( *(_QWORD *)a1 )
  {
    v6 = WORD1(*(_QWORD *)a1) & 0x1F;
    if ( v6 >= 4 )
    {
      printk(&unk_3EB3EF, "ipa_flt_parse_hw_rule");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipahal %s:%d Invalid Rule Action %d\n",
          "ipa_flt_parse_hw_rule",
          4336,
          *(_WORD *)(a1 + 2) & 0x1F);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v9 = ipa3_get_ipc_logbuf_low();
        v4 = ipc_log_string(
               v9,
               "ipahal %s:%d Invalid Rule Action %d\n",
               "ipa_flt_parse_hw_rule",
               4336,
               *(_WORD *)(a1 + 2) & 0x1F);
      }
      v6 = *(_WORD *)(a1 + 2) & 0x1F;
    }
    *(_DWORD *)(a2 + 4) = v6;
    *(_DWORD *)(a2 + 348) = (*(_DWORD *)a1 >> 21) & 0x1F;
    *(_BYTE *)a2 = (*(_DWORD *)a1 & 0x4000000) != 0;
    *(_DWORD *)(a2 + 368) = *(_DWORD *)(a1 + 4) & 0x3FF;
    *(_DWORD *)(a2 + 372) = *(_WORD *)(a1 + 6) & 0x3FF;
    *(_WORD *)(a2 + 164) = *(_QWORD *)a1;
    *(_BYTE *)(a2 + 352) = 1;
    return ipa_fltrt_parse_hw_rule_eq(a1, 8, a2 + 164, a2 + 380, v4);
  }
  else
  {
    result = 0;
    *(_DWORD *)(a2 + 380) = 0;
  }
  return result;
}
