__int64 __fastcall extract_sar2_result_event_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v10; // x8
  const char *v11; // x4
  const char *v12; // x2

  if ( !a10 )
  {
    v12 = "%s: Invalid sar2 result event buffer";
LABEL_7:
    qdf_trace_msg(0x31u, 2u, v12, a1, a2, a3, a4, a5, a6, a7, a8, "extract_sar2_result_event_tlv");
    return 4;
  }
  if ( !*(_QWORD *)a10 )
  {
    v12 = "%s: Invalid sar2 result event fixed param buffer";
    goto LABEL_7;
  }
  v10 = *(unsigned int *)(*(_QWORD *)a10 + 4LL);
  if ( (unsigned int)v10 > 8 )
    v11 = "Unknown response";
  else
    v11 = off_B34430[v10];
  qdf_trace_msg(0x31u, 8u, "%s: SAR2 result: %s", a1, a2, a3, a4, a5, a6, a7, a8, "extract_sar2_result_event_tlv", v11);
  return 0;
}
