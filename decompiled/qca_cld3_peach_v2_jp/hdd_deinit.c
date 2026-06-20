void __fastcall hdd_deinit(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x1
  __int64 v4; // x2
  __int64 v5; // x3
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  v2 = wlan_logging_sock_deinit_svc(a1, a2);
  if ( !cds_get_global_context(v2, v3, v4, v5) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: cds context is NULL",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wlan_destroy_bug_report_lock");
  qdf_op_callbacks_register(nullptr, nullptr);
  cds_deinit();
}
