__int64 __fastcall sme_set_vdev_sw_retry(unsigned __int8 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x4
  unsigned int v12; // w19

  result = wma_set_vdev_sw_retry_th();
  if ( (_DWORD)result )
  {
    v11 = a1;
    v12 = result;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Failed to set retry count for vdev: %d",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "sme_set_vdev_sw_retry",
      v11);
    return v12;
  }
  return result;
}
