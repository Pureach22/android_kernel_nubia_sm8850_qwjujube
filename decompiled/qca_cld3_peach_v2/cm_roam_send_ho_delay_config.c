__int64 __fastcall cm_roam_send_ho_delay_config(__int64 a1, unsigned int a2, unsigned int a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w19

  wlan_cm_roam_set_ho_delay_config(a1, a3);
  result = wlan_cm_tgt_send_roam_ho_delay_config(a1, a2, a3);
  if ( (_DWORD)result )
  {
    v15 = result;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: fail to send roam HO delay config",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "cm_roam_send_ho_delay_config");
    return v15;
  }
  return result;
}
