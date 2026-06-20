__int64 __fastcall extract_green_ap_egap_status_info_tlv(
        _QWORD *a1,
        _DWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _DWORD *v10; // x8
  const char *v12; // x2

  if ( a1 )
  {
    if ( *a1 )
    {
      v10 = (_DWORD *)a1[2];
      if ( v10 )
      {
        *a2 = *(_DWORD *)(*a1 + 4LL);
        a2[1] = v10[1];
        a2[2] = v10[2];
        a2[3] = v10[3];
        return 0;
      }
    }
    v12 = "%s: Invalid EGAP Info event or chainmask event";
  }
  else
  {
    v12 = "%s: Invalid EGAP Info status event buffer";
  }
  qdf_trace_msg(0x31u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "extract_green_ap_egap_status_info_tlv");
  return 4;
}
