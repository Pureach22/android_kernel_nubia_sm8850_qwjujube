__int64 __fastcall p2p_peer_obj_create_notification(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  if ( a1 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 88) + 16LL) == 3 )
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: p2p peer object create successful",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "p2p_peer_obj_create_notification");
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x4Eu,
      2u,
      "%s: peer context passed is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "p2p_peer_obj_create_notification");
    return 4;
  }
}
