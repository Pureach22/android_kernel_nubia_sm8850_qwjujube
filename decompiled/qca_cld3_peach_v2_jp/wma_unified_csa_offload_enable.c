__int64 __fastcall wma_unified_csa_offload_enable(__int64 *a1)
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

  result = wmi_unified_csa_offload_enable(*a1);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x36u,
      1u,
      "%s: Failed to send CSA offload enable command",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "wma_unified_csa_offload_enable");
    return 4294967291LL;
  }
  return result;
}
