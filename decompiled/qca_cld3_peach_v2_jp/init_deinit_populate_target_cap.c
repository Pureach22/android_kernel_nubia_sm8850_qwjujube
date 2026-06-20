__int64 init_deinit_populate_target_cap()
{
  __int64 result; // x0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  unsigned int v9; // w19

  result = wmi_get_target_cap_from_service_ready();
  if ( (_DWORD)result )
  {
    v9 = result;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: failed to parse target cap",
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      "init_deinit_populate_target_cap");
    return qdf_status_to_os_return(v9);
  }
  return result;
}
