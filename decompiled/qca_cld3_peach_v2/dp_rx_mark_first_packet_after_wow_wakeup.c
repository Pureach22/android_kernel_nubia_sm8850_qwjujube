__int64 __fastcall dp_rx_mark_first_packet_after_wow_wakeup(__int64 result, __int64 a2, __int64 a3)
{
  __int64 (__fastcall *v4)(_QWORD); // x8
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  if ( *(_BYTE *)(result + 96497) )
  {
    v4 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(result + 8) + 1128LL) + 74392LL) + 1760LL);
    if ( *((_DWORD *)v4 - 1) != -1147376687 )
      __break(0x8228u);
    result = v4(a2);
    if ( (_BYTE)result )
    {
      *(_DWORD *)(a3 + 168) |= 0x80000000;
      return qdf_trace_msg(
               0x45u,
               5u,
               "%s: First packet after WOW Wakeup rcvd",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "dp_rx_mark_first_packet_after_wow_wakeup");
    }
  }
  return result;
}
