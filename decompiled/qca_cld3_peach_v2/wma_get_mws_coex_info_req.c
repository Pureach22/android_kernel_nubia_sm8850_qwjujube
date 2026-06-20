__int64 __fastcall wma_get_mws_coex_info_req(__int64 *a1)
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

  result = wmi_unified_send_mws_coex_req_cmd(*a1);
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x36u,
             2u,
             "%s: Failed to send mws coex info",
             v2,
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             "wma_get_mws_coex_info_req");
  return result;
}
