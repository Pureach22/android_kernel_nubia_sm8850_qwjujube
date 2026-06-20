__int64 __fastcall wma_fips_request(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        void *a11,
        __int64 a12)
{
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x22
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w19

  if ( (unsigned int)_wma_validate_handle((__int64)a1, (__int64)"wma_fips_request", a2, a3, a4, a5, a6, a7, a8, a9) )
    return 4;
  v23 = *a1;
  if ( (unsigned int)_wmi_validate_handle(v23, (__int64)"wma_fips_request", v15, v16, v17, v18, v19, v20, v21, v22) )
    return 4;
  fips_callback = a11;
  fips_context = a12;
  result = wmi_unified_pdev_fips_cmd_send(v23);
  if ( (_DWORD)result )
  {
    v33 = result;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: wmi_unified_pdev_fips_cmd_send() error: %u",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "wma_fips_request",
      (unsigned int)result);
    fips_callback = nullptr;
    return v33;
  }
  return result;
}
