__int64 __fastcall ipa_flt_parse_hw_rule_ipav5_0(__int64 a1, __int64 a2)
{
  long double v4; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 v6; // x3
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 v9; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v4 = ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Entry\n", "ipa_flt_parse_hw_rule_ipav5_0", 4458);
  }
  if ( *(_QWORD *)a1 )
  {
    v6 = (*(_QWORD *)a1 >> 52) & 0x1FLL;
    if ( (unsigned int)v6 >= 4 )
    {
      printk(&unk_3EB3EF, "ipa_flt_parse_hw_rule_ipav5_0");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipahal %s:%d Invalid Rule Action %d\n",
          "ipa_flt_parse_hw_rule_ipav5_0",
          4483,
          (*(_QWORD *)a1 >> 52) & 0x1F);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v9 = ipa3_get_ipc_logbuf_low();
        v4 = ipc_log_string(
               v9,
               "ipahal %s:%d Invalid Rule Action %d\n",
               "ipa_flt_parse_hw_rule_ipav5_0",
               4483,
               (*(_QWORD *)a1 >> 52) & 0x1F);
      }
      v6 = (*(_QWORD *)a1 >> 52) & 0x1FLL;
    }
    *(_DWORD *)(a2 + 4) = v6;
    *(_DWORD *)(a2 + 348) = *(unsigned __int8 *)(a1 + 2);
    *(_BYTE *)a2 = (*(_QWORD *)a1 & 0x4000000000000000LL) != 0;
    *(_DWORD *)(a2 + 368) = *(unsigned __int8 *)(a1 + 4);
    *(_DWORD *)(a2 + 372) = (*(_QWORD *)a1 >> 42) & 0x3FF;
    *(_BYTE *)(a2 + 359) = (*(_QWORD *)a1 >> 57) & 0xF;
    *(_BYTE *)(a2 + 358) = (*(_QWORD *)a1 & 0x2000000000000000LL) != 0;
    *(_BYTE *)(a2 + 376) = BYTE3(*(_QWORD *)a1);
    *(_BYTE *)(a2 + 362) = (*(_QWORD *)a1 & 0x20000000000LL) != 0;
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
