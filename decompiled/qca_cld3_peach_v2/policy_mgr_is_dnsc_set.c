__int64 __fastcall policy_mgr_is_dnsc_set(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 49) & 2) != 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Restrict offchannel is set",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "policy_mgr_is_dnsc_set");
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid parameter", a2, a3, a4, a5, a6, a7, a8, a9, "policy_mgr_is_dnsc_set");
    return 0;
  }
}
