__int64 __fastcall sme_update_new_channel_event(__int64 a1, unsigned __int8 a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21

  v4 = _qdf_mem_malloc(0x180u, "sme_update_new_channel_event", 1398);
  if ( !v4 )
    return 16;
  v13 = v4;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: sapdfs: Updated new channel event",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "sme_update_new_channel_event");
  csr_roam_call_callback(a1, a2, v13, 47, 14);
  _qdf_mem_free(v13);
  return 0;
}
