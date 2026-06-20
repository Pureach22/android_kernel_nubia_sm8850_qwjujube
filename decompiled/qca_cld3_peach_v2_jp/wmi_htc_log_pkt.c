__int64 __fastcall wmi_htc_log_pkt(__int64 a1, __int64 a2)
{
  int v2; // w19
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  v2 = **(_DWORD **)(*(_QWORD *)(a2 + 96) + 224LL);
  v3 = wmi_id_to_name(v2 & 0xFFFFFF);
  return qdf_trace_msg(
           0x31u,
           8u,
           "%s: WMI command from HTC packet: %s, ID: %d",
           v4,
           v5,
           v6,
           v7,
           v8,
           v9,
           v10,
           v11,
           "wmi_htc_log_pkt",
           v3,
           v2 & 0xFFFFFF);
}
