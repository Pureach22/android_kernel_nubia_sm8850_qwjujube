__int64 __fastcall extract_p2p_lo_stop_ev_param_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        _DWORD *a11)
{
  __int64 v11; // x8
  const char *v13; // x2

  if ( a10 )
  {
    if ( a11 )
    {
      v11 = *a10;
      *a11 = *(_DWORD *)(*a10 + 4);
      a11[1] = *(_DWORD *)(v11 + 8);
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: vdev_id:%d, reason:%d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_p2p_lo_stop_ev_param_tlv");
      return 0;
    }
    v13 = "%s: lo stop event param is null";
  }
  else
  {
    v13 = "%s: Invalid P2P lo stop event buffer";
  }
  qdf_trace_msg(0x31u, 2u, v13, a1, a2, a3, a4, a5, a6, a7, a8, "extract_p2p_lo_stop_ev_param_tlv");
  return 4;
}
