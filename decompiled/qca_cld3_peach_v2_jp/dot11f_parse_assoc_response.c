__int64 __fastcall dot11f_parse_assoc_response(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned int v8; // w19
  unsigned int v10; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  v8 = a3;
  v10 = dot11f_unpack_assoc_response(a1, a2, a3, a4, a5, a6, a7, a8);
  if ( (v10 & 0x10000000) == 0 )
    return 0;
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Failed to parse an Association Response (0x%08x, %d bytes):",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "dot11f_parse_assoc_response",
    v10,
    v8);
  ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(53, 2, a2, v8);
  return 16;
}
