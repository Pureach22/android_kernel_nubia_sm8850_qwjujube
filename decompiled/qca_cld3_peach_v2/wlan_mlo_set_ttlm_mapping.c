__int64 __fastcall wlan_mlo_set_ttlm_mapping(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  v2 = *(_QWORD *)(a1 + 184);
  if ( !v2 || !*(_QWORD *)(v2 + 784) )
    return 4;
  if ( (mlo_is_link_recfg_in_progress(a1) & 1) == 0 )
    return ttlm_sm_deliver_event(*(_QWORD *)(v2 + 784), 0, 0x34u, a2);
  qdf_trace_msg(
    0x99u,
    2u,
    "%s: failed due to link recfg in progress",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "wlan_mlo_set_ttlm_mapping");
  return 16;
}
