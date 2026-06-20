__int64 __fastcall ipa_rt_parse_hw_rule_ipav4_5(__int64 a1, __int64 a2)
{
  __int64 ipc_logbuf_low; // x0
  long double v5; // q0
  __int64 v6; // x0
  bool v7; // zf
  int v8; // w8
  char v9; // w8
  int v10; // w9

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Entry\n", "ipa_rt_parse_hw_rule_ipav4_5", 4180);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v6 = ipa3_get_ipc_logbuf_low();
    v5 = ipc_log_string(v6, "ipahal %s:%d read hdr 0x%llx\n", "ipa_rt_parse_hw_rule_ipav4_5", 4185, *(_QWORD *)a1);
  }
  if ( *(_QWORD *)a1 )
  {
    *(_DWORD *)a2 = WORD1(*(_QWORD *)a1) & 0x1F;
    v7 = (*(_QWORD *)a1 & 0x80000000LL) == 0;
    if ( (*(_QWORD *)a1 & 0x80000000LL) != 0 )
      v8 = 2;
    else
      v8 = 1;
    *(_DWORD *)(a2 + 12) = v8;
    if ( v7 )
      v9 = 20;
    else
      v9 = 17;
    if ( v7 )
      v10 = 2044;
    else
      v10 = 16352;
    *(_DWORD *)(a2 + 8) = (*(_DWORD *)a1 >> v9) & v10;
    *(_BYTE *)(a2 + 4) = (*(_QWORD *)a1 & 0x200000LL) == 0;
    *(_DWORD *)(a2 + 16) = *(_DWORD *)(a1 + 4) & 0x3FF;
    *(_BYTE *)(a2 + 20) = (*(_QWORD *)a1 & 0x800000000000LL) != 0;
    *(_BYTE *)(a2 + 28) = (*(_QWORD *)a1 >> 36) & 0xC0 | (*(_QWORD *)a1 >> 58);
    *(_DWORD *)(a2 + 24) = *(_WORD *)(a1 + 6) & 0x3FF;
    *(_WORD *)(a2 + 36) = *(_QWORD *)a1;
    return ipa_fltrt_parse_hw_rule_eq(a1, 8, a2 + 36, a2 + 220, v5);
  }
  else
  {
    *(_DWORD *)(a2 + 220) = 0;
    return 0;
  }
}
