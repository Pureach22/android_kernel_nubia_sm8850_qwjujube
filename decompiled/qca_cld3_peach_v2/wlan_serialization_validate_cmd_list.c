__int64 __fastcall wlan_serialization_validate_cmd_list(
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
  if ( *(_QWORD *)(a1 + 40) )
  {
    if ( *(_QWORD *)(a1 + 64) )
      return 0;
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: invalid cmd.vdev",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_serialization_validate_cmd_list");
  }
  else
  {
    qdf_trace_msg(
      0x4Cu,
      2u,
      "%s: no cmd_cb for cmd type:%d, id: %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_serialization_validate_cmd_list",
      *(unsigned int *)(a1 + 32),
      *(unsigned int *)(a1 + 36));
  }
  return 4;
}
