__int64 __fastcall tdls_decrement_peer_count(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x5
  void (__fastcall *v13)(_QWORD); // x8
  __int64 result; // x0

  if ( *(_WORD *)(a2 + 202) )
    v12 = (unsigned __int16)--*(_WORD *)(a2 + 202);
  else
    v12 = 0;
  qdf_trace_msg(
    0,
    8u,
    "%s: vdev %d connected peer count %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "tdls_decrement_peer_count",
    *(unsigned __int8 *)(a1 + 104),
    v12);
  if ( !*(_WORD *)(a2 + 202) )
  {
    v13 = *(void (__fastcall **)(_QWORD))(a2 + 608);
    if ( v13 )
    {
      if ( *((_DWORD *)v13 - 1) != 1458356883 )
        __break(0x8228u);
      v13(a1);
    }
  }
  result = tdls_update_6g_power(a1, a2, 0);
  if ( *(_WORD *)(a2 + 202) == 1 )
    return tdls_set_tdls_offchannelmode(a1, 1);
  return result;
}
