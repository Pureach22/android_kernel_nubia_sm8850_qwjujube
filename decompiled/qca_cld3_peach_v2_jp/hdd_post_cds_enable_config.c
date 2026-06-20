__int64 __fastcall hdd_post_cds_enable_config(__int64 a1)
{
  __int64 result; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  result = sme_hdd_ready_ind(*(_QWORD *)(a1 + 16));
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: sme_hdd_ready_ind() failed with status code %08d [x%08x]",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "hdd_post_cds_enable_config",
      (unsigned int)result,
      (unsigned int)result);
    return 16;
  }
  return result;
}
