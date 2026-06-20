__int64 __fastcall extract_twt_notify_event_tlv(
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
  __int64 v12; // x4
  int v14; // w8
  int v15; // w5

  if ( a10 )
  {
    v11 = *a10;
    v12 = *(unsigned int *)(*a10 + 4);
    if ( *(_DWORD *)(*a10 + 8) < 4u )
    {
      *a11 = v12;
      v14 = *(_DWORD *)(v11 + 8);
      if ( v14 == 2 )
        v15 = 1;
      else
        v15 = 2 * (v14 == 3);
      a11[1] = v15;
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Extract notify event vdev_id: %d, status: %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_twt_notify_event_tlv");
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Incorrect TWT notify event vdev_id: %d, status: %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_twt_notify_event_tlv",
        v12);
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(0x31u, 2u, "%s: evt_buf is NULL", a1, a2, a3, a4, a5, a6, a7, a8, "extract_twt_notify_event_tlv");
    return 4;
  }
}
