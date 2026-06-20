__int64 __fastcall cnss_diag_cmd_handler(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  const char *v13; // x2
  const char *v14; // x3
  __int64 v15; // x19
  __int64 v16; // x8
  _QWORD s[47]; // [xsp+8h] [xbp-178h] BYREF

  s[46] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x170u);
  result = _nla_parse(s, 6, a1, a2, 0, 31, 0);
  if ( (_DWORD)result )
  {
    if ( (dword_183E4 & 1) != 0 )
    {
      v13 = "%s: %s: nla parse fails\n";
LABEL_4:
      v14 = "cnss_diag_cmd_handler";
LABEL_5:
      result = qdf_trace_msg(0x38u, 2u, v13, v5, v6, v7, v8, v9, v10, v11, v12, v14, v14);
    }
  }
  else
  {
    v15 = s[2];
    if ( !s[2] )
    {
      if ( (dword_183E4 & 1) == 0 )
        goto LABEL_6;
      v13 = "%s: %s: attr VENDOR_DATA fails\n";
      goto LABEL_4;
    }
    if ( (unsigned __int16)(*(_WORD *)s[2] - 4) <= 0xFu )
    {
      if ( (dword_183E4 & 1) == 0 )
        goto LABEL_6;
      v13 = "%s: %s: attr length less than sizeof(struct dbglog_slot)\n";
      goto LABEL_4;
    }
    v16 = *(unsigned int *)(s[2] + 12LL);
    if ( v16 + 16 != (unsigned __int16)(*(_WORD *)s[2] - 4) )
    {
      if ( (dword_183E4 & 1) == 0 )
        goto LABEL_6;
      v13 = "%s: %s: attr length check fails\n";
      goto LABEL_4;
    }
    if ( *(_DWORD *)(s[2] + 4LL) == 6 )
    {
      if ( (_DWORD)v16 == 2 )
      {
        if ( (dword_183E4 & 4) != 0 )
          result = qdf_trace_msg(
                     0x38u,
                     2u,
                     "%s: %s : DIAG_TYPE_CRASH_INJECT: %d %d\n",
                     v5,
                     v6,
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     v12,
                     "cnss_diag_handle_crash_inject",
                     "cnss_diag_handle_crash_inject",
                     *(unsigned __int8 *)(s[2] + 20LL),
                     *(unsigned __int8 *)(s[2] + 21LL));
        if ( (tgt_assert_enable & 1) != 0 )
        {
          result = wma_cli_set2_command(0, 3, *(unsigned __int8 *)(v15 + 20), *(unsigned __int8 *)(v15 + 21), 3);
          goto LABEL_6;
        }
        if ( (dword_183E4 & 4) == 0 )
          goto LABEL_6;
        v13 = "%s: %s: tgt Assert Disabled\n";
        v14 = "cnss_diag_handle_crash_inject";
        goto LABEL_5;
      }
      if ( (dword_183E4 & 1) != 0 )
        result = qdf_trace_msg(
                   0x38u,
                   2u,
                   "%s: crash_inject cmd error\n",
                   v5,
                   v6,
                   v7,
                   v8,
                   v9,
                   v10,
                   v11,
                   v12,
                   "cnss_diag_handle_crash_inject");
    }
    else if ( (dword_183E4 & 1) != 0 )
    {
      result = qdf_trace_msg(
                 0x38u,
                 2u,
                 "%s: Unknown cmd[%d] error\n",
                 v5,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 v12,
                 "cnss_diag_handle_crash_inject");
    }
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
