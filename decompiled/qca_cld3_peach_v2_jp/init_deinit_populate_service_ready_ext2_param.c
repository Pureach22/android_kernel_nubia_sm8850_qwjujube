__int64 __fastcall init_deinit_populate_service_ready_ext2_param(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w19

  result = wmi_extract_service_ready_ext2(a1, a2, a3 + 920);
  if ( (_DWORD)result )
  {
    v12 = result;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: failed to parse wmi service ready ext param",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "init_deinit_populate_service_ready_ext2_param");
    return qdf_status_to_os_return(v12);
  }
  return result;
}
