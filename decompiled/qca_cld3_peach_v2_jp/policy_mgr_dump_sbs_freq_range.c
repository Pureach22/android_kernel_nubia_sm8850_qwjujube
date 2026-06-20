_DWORD *__fastcall policy_mgr_dump_sbs_freq_range(
        _DWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _DWORD *result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  result = policy_mgr_dump_freq_range_per_mac(a1 + 317, 2u, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( a1[300] )
  {
    result = policy_mgr_dump_freq_range_per_mac(a1 + 325, 3u, v11, v12, v13, v14, v15, v16, v17, v18);
    if ( a1[300] )
      return policy_mgr_dump_freq_range_per_mac(a1 + 333, 4u, v19, v20, v21, v22, v23, v24, v25, v26);
  }
  return result;
}
