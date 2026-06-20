__int64 __fastcall init_deinit_update_p2p_p2p_conc_support(__int64 a1, __int64 a2)
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

  result = wmi_service_enabled(a1, 255);
  if ( (result & 1) == 0 )
    return qdf_trace_msg(
             0x49u,
             8u,
             "%s: P2P + P2P conc disabled",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "init_deinit_update_p2p_p2p_conc_support");
  *(_DWORD *)(a2 + 20) |= 0x20000000u;
  return result;
}
