__int64 __fastcall htc_credit_history_deinit(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  qdf_ssr_driver_dump_unregister_region("htc_credit_history_length", a1, a2, a3, a4, a5, a6, a7, a8);
  qdf_ssr_driver_dump_unregister_region("htc_credit_history_idx", v8, v9, v10, v11, v12, v13, v14, v15);
  qdf_ssr_driver_dump_unregister_region("htc_credit", v16, v17, v18, v19, v20, v21, v22, v23);
  return _qdf_minidump_remove((__int64)&htc_credit_history_buffer, 24576, "htc_credit");
}
