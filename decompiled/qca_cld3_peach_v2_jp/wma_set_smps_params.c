__int64 __fastcall wma_set_smps_params(
        __int64 *a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w19
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  if ( (wma_is_vdev_valid(a2, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
  {
    v20 = wmi_unified_set_smps_params(*a1);
    if ( v20 )
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to send set Mimo PS ret = %d",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "wma_set_smps_params",
        v20);
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid VDEV ID: %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_set_smps_params",
      a2);
    return 4;
  }
  return v20;
}
