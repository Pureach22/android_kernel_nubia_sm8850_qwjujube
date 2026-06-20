__int64 __fastcall policy_mgr_reset_sap_mandatory_channels(__int64 a1)
{
  __int64 context; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    *(_DWORD *)(context + 960) = 0;
    qdf_mem_set((void *)(context + 552), 0x198u, 0);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "policy_mgr_reset_sap_mandatory_channels");
    return 16;
  }
}
