__int64 __fastcall wlan_action_oui_extension_dump(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0

  qdf_trace_msg(0x63u, 9u, "%s: oui len %u", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_action_oui_extension_dump", a1[1]);
  if ( a1[1] )
    ((void (__fastcall *)(__int64, __int64, unsigned int *))qdf_trace_hex_dump)(99, 9, a1 + 7);
  qdf_trace_msg(
    0x63u,
    9u,
    "%s: oui data len %u",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "wlan_action_oui_extension_dump",
    a1[2]);
  if ( a1[2] )
    ((void (__fastcall *)(__int64, __int64, char *))qdf_trace_hex_dump)(99, 9, (char *)a1 + 33);
  result = qdf_trace_msg(
             0x63u,
             9u,
             "%s: oui data mask len %u",
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             "wlan_action_oui_extension_dump",
             a1[3]);
  if ( a1[3] )
    return ((__int64 (__fastcall *)(__int64, __int64, char *))qdf_trace_hex_dump)(99, 9, (char *)a1 + 53);
  return result;
}
