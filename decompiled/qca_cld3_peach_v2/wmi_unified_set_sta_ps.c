__int64 __fastcall wmi_unified_set_sta_ps(__int64 a1)
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

  result = wmi_unified_set_sta_ps_mode(a1);
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: Failed to send set Mimo PS ret = %d",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "wmi_unified_set_sta_ps",
             (unsigned int)result);
  return result;
}
