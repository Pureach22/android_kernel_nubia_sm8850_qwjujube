__int64 __fastcall wma_roam_scan_bmiss_cnt(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned int a10,
        unsigned int a11)
{
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w19

  _ReadStatusReg(SP_EL0);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: first_bcnt: %d, final_bcnt: %d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "wma_roam_scan_bmiss_cnt",
    a10,
    a11);
  result = wma_send_multi_pdev_vdev_set_params(1, v11, v12, v13, v14, v15, v16, v17, v18);
  if ( (_DWORD)result )
  {
    v28 = result;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to set BMISS FIRST and FINAL vdev set params",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wma_roam_scan_bmiss_cnt");
    result = v28;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
