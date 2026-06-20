__int64 __fastcall extract_rf_path_resp_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        _DWORD *a11)
{
  const char *v12; // x2

  if ( a10 )
  {
    if ( *(_QWORD *)a10 )
    {
      *a11 = *(_DWORD *)(*(_QWORD *)a10 + 12LL);
      return 0;
    }
    v12 = "%s: Invalid fixed param";
  }
  else
  {
    v12 = "%s: Invalid RF path event buffer";
  }
  qdf_trace_msg(0x31u, 2u, v12, a1, a2, a3, a4, a5, a6, a7, a8, "extract_rf_path_resp_tlv");
  return 4;
}
