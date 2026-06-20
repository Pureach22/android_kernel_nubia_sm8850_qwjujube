__int64 __fastcall wma_init_scan_fw_mode_config(
        __int64 a1,
        int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  unsigned int v23; // w1

  qdf_trace_msg(0x36u, 8u, "%s: Enter", a4, a5, a6, a7, a8, a9, a10, a11, "wma_init_scan_fw_mode_config");
  if ( a1 )
  {
    policy_mgr_init_dbs_config(a1, a2, a3);
    policy_mgr_init_sbs_fw_config(a1, a3);
    v22 = "%s: Exit";
    v23 = 8;
  }
  else
  {
    v22 = "%s: obj psoc is NULL";
    v23 = 2;
  }
  return qdf_trace_msg(0x36u, v23, v22, v14, v15, v16, v17, v18, v19, v20, v21, "wma_init_scan_fw_mode_config");
}
