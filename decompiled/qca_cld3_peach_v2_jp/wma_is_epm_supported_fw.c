__int64 __fastcall wma_is_epm_supported_fw(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  char v9; // w19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  v9 = wmi_service_enabled(*a1, 0x13Au, a2, a3, a4, a5, a6, a7, a8, a9);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: EPM enable feature fw value: %d",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "wma_is_epm_supported_fw",
    v9 & 1);
  return v9 & 1;
}
