__int64 __fastcall extract_vdev_disconnect_event_tlv(
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
        __int64 a11,
        __int64 a12)
{
  __int64 v12; // x8
  unsigned int v13; // w4

  v12 = *a10;
  if ( *a10 )
  {
    v13 = *(_DWORD *)(v12 + 4);
    if ( v13 < 6 )
    {
      *(_BYTE *)a12 = v13;
      *(_DWORD *)(a12 + 16) = *(_DWORD *)(v12 + 8);
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Received disconnect roam event on vdev_id : %d, reason:%d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_vdev_disconnect_event_tlv");
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Invalid vdev id %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_vdev_disconnect_event_tlv");
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: roam cap event is NULL",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_vdev_disconnect_event_tlv");
    return 4;
  }
}
