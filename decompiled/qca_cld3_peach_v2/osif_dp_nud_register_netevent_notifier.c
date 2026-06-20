__int64 __fastcall osif_dp_nud_register_netevent_notifier(__int64 a1)
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

  if ( (unsigned __int8)ucfg_dp_nud_tracking_enabled(a1) )
  {
    result = register_netevent_notifier(&wlan_netevent_nb);
    if ( (_DWORD)result )
      return result;
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Registered netevent notifier",
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      "osif_dp_nud_register_netevent_notifier");
  }
  return 0;
}
