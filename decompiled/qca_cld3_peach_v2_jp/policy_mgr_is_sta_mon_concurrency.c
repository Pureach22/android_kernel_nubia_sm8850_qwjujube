__int64 __fastcall policy_mgr_is_sta_mon_concurrency(__int64 a1)
{
  __int64 context; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( (wlan_mlme_is_sta_mon_conc_supported() & 1) != 0 )
  {
    context = policy_mgr_get_context(a1);
    if ( context )
    {
      v11 = context;
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: concurrency_mode: 0x%x",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "policy_mgr_get_concurrency_mode",
        *(unsigned int *)(context + 968));
      if ( (~*(_DWORD *)(v11 + 968) & 0x41) == 0 )
      {
        qdf_trace_msg(
          0x4Fu,
          2u,
          "%s: STA + MON mode is UP",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "policy_mgr_is_sta_mon_concurrency");
        return 1;
      }
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid context",
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        "policy_mgr_get_concurrency_mode");
    }
  }
  return 0;
}
