__int64 qdf_ssr_driver_dump_deinit()
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

  result = qdf_mutex_destroy((__int64)&region_list_mutex);
  if ( !(_DWORD)result )
  {
    if ( num_of_regions_registered )
    {
      qdf_trace_msg(
        0x38u,
        3u,
        "%s: deiniting with regions still registered",
        v1,
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        "qdf_ssr_driver_dump_deinit");
      result = 0;
    }
    num_of_regions_registered = 0;
  }
  return result;
}
