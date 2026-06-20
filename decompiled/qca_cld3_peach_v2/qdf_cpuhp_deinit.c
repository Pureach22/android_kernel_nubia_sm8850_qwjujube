__int64 qdf_cpuhp_deinit()
{
  double v0; // d0
  double v1; // d1
  double v2; // d2
  double v3; // d3
  double v4; // d4
  double v5; // d5
  double v6; // d6
  double v7; // d7

  _qdf_cpuhp_os_deinit();
  if ( (_DWORD)qword_92E438 )
    qdf_trace_msg(0x33u, 2u, "%s: list length not equal to zero", v0, v1, v2, v3, v4, v5, v6, v7, "qdf_list_destroy");
  return qdf_mutex_destroy((__int64)&qdf_cpuhp_lock);
}
