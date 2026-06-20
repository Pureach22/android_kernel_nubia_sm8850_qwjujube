__int64 __fastcall dp_send_htt_mgmt_rx_buf_refil_srng_setup(__int64 a1, __int64 a2)
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

  result = htt_srng_setup(*(_QWORD *)(a1 + 48), 0, a2, 14);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Failed to send HTT msg for mgmt rx srng",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "dp_send_htt_mgmt_rx_buf_refil_srng_setup");
    return 16;
  }
  return result;
}
