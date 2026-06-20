__int64 __fastcall extract_reg_11d_new_country_event_tlv(
        int a1,
        __int64 a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  if ( a2 )
  {
    qdf_mem_copy(a3, (const void *)(*(_QWORD *)a2 + 4LL), 2u);
    a3[2] = 0;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: processed 11d country event, new cc %s",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "extract_reg_11d_new_country_event_tlv",
      a3);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: invalid 11d country event buf",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "extract_reg_11d_new_country_event_tlv");
    return 16;
  }
}
