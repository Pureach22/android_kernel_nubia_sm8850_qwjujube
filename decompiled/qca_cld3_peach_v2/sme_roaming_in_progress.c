bool __fastcall sme_roaming_in_progress(
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
  if ( a2 <= 5u && *(_QWORD *)(a1 + 17296) + 96LL * a2 )
  {
    return wlan_cm_roaming_in_progress(*(_QWORD *)(a1 + 21632), a2);
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: ROAM: incorrect vdev ID %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "sme_roaming_in_progress");
    return 0;
  }
}
