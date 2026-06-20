__int64 __fastcall dp_mon_get_is_local_pkt_capture_running(
        __int64 a1,
        unsigned __int8 a2,
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
  __int64 v13; // x8

  if ( !a2 )
  {
    v12 = *(_QWORD *)(a1 + 72);
    if ( v12 )
    {
      v13 = *(_QWORD *)(v12 + 95560);
      if ( v13 )
        return *(_BYTE *)(v13 + 39317) & 1;
    }
  }
  qdf_trace_msg(
    0x73u,
    2u,
    "%s: Invalid pdev_id %u",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dp_mon_get_is_local_pkt_capture_running",
    a2,
    v10,
    v11);
  return 0;
}
