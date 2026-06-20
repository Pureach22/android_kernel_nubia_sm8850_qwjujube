__int64 __fastcall extract_reg_c2c_detect_event_tlv(
        __int64 a1,
        bool *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  if ( a1 )
  {
    *a2 = *(_DWORD *)(*(_QWORD *)a1 + 4LL) != 0;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Is indoor AP detected = %u",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "extract_reg_c2c_detect_event_tlv");
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: invalid channel list event buf",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "extract_reg_c2c_detect_event_tlv");
    return 16;
  }
}
