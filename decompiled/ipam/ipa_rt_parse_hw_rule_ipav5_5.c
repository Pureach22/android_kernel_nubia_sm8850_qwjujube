__int64 __fastcall ipa_rt_parse_hw_rule_ipav5_5(__int64 a1, __int64 a2)
{
  __int64 ipc_logbuf_low; // x0
  long double v5; // q0
  __int64 v6; // x0
  bool v7; // zf
  int v8; // w8
  char v9; // w8
  int v10; // w9
  __int64 v11; // x1

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipahal %s:%d Entry\n", "ipa_rt_parse_hw_rule_ipav5_5", 4262);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v6 = ipa3_get_ipc_logbuf_low();
    v5 = ipc_log_string(v6, "ipahal %s:%d read hdr 0x%llx\n", "ipa_rt_parse_hw_rule_ipav5_5", 4267, *(_QWORD *)a1);
  }
  if ( *(_QWORD *)a1 )
  {
    *(_DWORD *)a2 = (unsigned __int8)BYTE2(*(_QWORD *)a1);
    v7 = (*(_QWORD *)a1 & 0x2000000000000000LL) == 0;
    if ( (*(_QWORD *)a1 & 0x2000000000000000LL) != 0 )
      v8 = 2;
    else
      v8 = 1;
    *(_DWORD *)(a2 + 12) = v8;
    v9 = 47;
    if ( v7 )
    {
      v9 = 50;
      v10 = 2044;
    }
    else
    {
      v10 = 16352;
    }
    *(_DWORD *)(a2 + 8) = v10 & (*(_QWORD *)a1 >> v9);
    *(_BYTE *)(a2 + 4) = *(_QWORD *)a1 >= 0LL;
    *(_DWORD *)(a2 + 16) = *(unsigned __int8 *)(a1 + 4);
    *(_BYTE *)(a2 + 20) = (*(_QWORD *)a1 & 0x4000000000000000LL) != 0;
    *(_BYTE *)(a2 + 28) = BYTE3(*(_QWORD *)a1);
    *(_DWORD *)(a2 + 24) = (*(_QWORD *)a1 >> 42) & 0x3FF;
    *(_BYTE *)(a2 + 29) = (*(_QWORD *)a1 & 0x20000000000LL) != 0;
    *(_WORD *)(a2 + 36) = *(_QWORD *)a1;
    if ( (*(_BYTE *)(a1 + 5) & 1) != 0 )
    {
      v11 = 10;
      *(_BYTE *)(a2 + 30) = *(_BYTE *)(a1 + 8) & 1;
      *(_BYTE *)(a2 + 31) = (*(_BYTE *)(a1 + 8) >> 1) & 0x3F;
      *(_BYTE *)(a2 + 32) = *(_BYTE *)(a1 + 8) >> 7;
    }
    else
    {
      v11 = 8;
    }
    return ipa_fltrt_parse_hw_rule_eq(a1, v11, a2 + 36, a2 + 220, v5);
  }
  else
  {
    *(_DWORD *)(a2 + 220) = 0;
    return 0;
  }
}
