__int64 wlan_ipa_uc_rt_debug_destructor()
{
  __int64 result; // x0
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7

  result = wlan_ipa_get_obj_context();
  if ( !result )
    return qdf_trace_msg(
             0x61u,
             2u,
             "%s: invalid ipa context",
             v1,
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             "wlan_ipa_uc_rt_debug_destructor");
  ++*(_QWORD *)(result + 4160);
  return result;
}
