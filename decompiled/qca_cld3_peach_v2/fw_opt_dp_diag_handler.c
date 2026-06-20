__int64 __fastcall fw_opt_dp_diag_handler(__int64 a1, __int64 a2)
{
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  ipa_fw_log_received_stats();
  if ( a2 )
    return ipa_fw_nl_broadcast(*(_QWORD *)a2, *(unsigned int *)(a2 + 8));
  if ( (dword_183E4 & 1) != 0 )
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: Got NULL point message from FW\n",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "fw_opt_dp_diag_handler");
  return 0xFFFFFFFFLL;
}
