unsigned __int64 __fastcall policy_mgr_restrict_sap_on_unsafe_chan(__int64 a1)
{
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7

  if ( policy_mgr_get_context(a1) )
    return ((unsigned __int64)(unsigned int)policy_mgr_get_freq_restriction_mask() >> 1) & 1;
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: Invalid context",
    v1,
    v2,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    "policy_mgr_restrict_sap_on_unsafe_chan");
  return 0;
}
