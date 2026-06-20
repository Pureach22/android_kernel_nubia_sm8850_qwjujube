bool __fastcall hdd_check_internal_netdev_state(
        _BOOL8 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19

  if ( result )
  {
    v9 = result;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: netdev name %s, netdev flags 0x%x, event_flags %lu",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "hdd_check_internal_netdev_state",
      result + 296,
      *(unsigned int *)(result + 176),
      *(_QWORD *)(result + 4312));
    return (*(_QWORD *)(v9 + 4312) & 4) != 0 && (*(_BYTE *)(v9 + 176) & 1) != 0;
  }
  return result;
}
