__int64 __fastcall dp_mon_soc_htt_srng_setup_2_0(__int64 a1)
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
  unsigned int v10; // w19

  result = dp_tx_mon_soc_htt_srng_setup_2_0(a1, 0);
  if ( (_DWORD)result )
  {
    v10 = result;
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to send htt srng setup message for Tx mon buf ring",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "dp_mon_soc_htt_srng_setup_2_0");
    return v10;
  }
  return result;
}
