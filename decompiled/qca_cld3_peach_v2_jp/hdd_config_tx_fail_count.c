__int64 __fastcall hdd_config_tx_fail_count(unsigned __int8 *a1, __int64 a2)
{
  unsigned int updated; // w19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  if ( !*(_DWORD *)(a2 + 4) )
    return 0;
  updated = sme_update_tx_fail_cnt_threshold(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 24LL) + 16LL), a1[8]);
  if ( updated )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: sme_update_tx_fail_cnt_threshold (err=%d)",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "hdd_config_tx_fail_count",
      updated);
  return qdf_status_to_os_return(updated);
}
