__int64 __fastcall cds_pkt_get_packet_length(
        __int64 a1,
        _WORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  __int64 v12; // x8
  __int16 v13; // w9

  if ( a1 && a2 && (v12 = *(_QWORD *)(a1 + 64)) != 0 )
  {
    if ( (*(_BYTE *)(v12 + 68) & 4) != 0 )
      v13 = *(_WORD *)(v12 + 66);
    else
      v13 = 0;
    *a2 = *(_WORD *)(v12 + 112) + v13;
    return 0;
  }
  else
  {
    qdf_trace_msg(0x38u, 1u, "%s: NULL pointer", a3, a4, a5, a6, a7, a8, a9, a10, "cds_pkt_get_packet_length", v10, v11);
    return 4;
  }
}
