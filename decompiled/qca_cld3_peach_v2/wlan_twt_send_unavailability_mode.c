__int64 __fastcall wlan_twt_send_unavailability_mode(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x4
  unsigned int v13; // w19

  result = tgt_twt_send_unavailability_mode();
  if ( (_DWORD)result )
  {
    v12 = *(unsigned __int8 *)(a2 + 168);
    v13 = result;
    qdf_trace_msg(
      0x96u,
      2u,
      "%s: vdev:%d failed to send unavailability mode",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wlan_twt_send_unavailability_mode",
      v12);
    return v13;
  }
  return result;
}
