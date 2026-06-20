__int64 __fastcall wlan_ser_match_cmd_scan_id(
        __int64 a1,
        _QWORD *a2,
        unsigned __int16 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v12; // w19

  if ( *(_DWORD *)(a1 + 36) == a3 && *(_QWORD *)(a1 + 64) == a4 )
  {
    v12 = 1;
    *a2 = a1 + 32;
  }
  else
  {
    v12 = 0;
  }
  qdf_trace_msg(0x4Cu, 8u, "%s: match found: %d", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_ser_match_cmd_scan_id", v12);
  return v12;
}
