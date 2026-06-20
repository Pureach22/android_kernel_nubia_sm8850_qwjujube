bool __fastcall wlan_serialization_match_cmd_vdev(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v13; // x20

  v11 = -16;
  if ( !a3 )
    v11 = 0;
  v13 = *(_QWORD *)(a1 + v11 + 64);
  if ( v13 != a2 )
    qdf_trace_msg(
      0x4Cu,
      8u,
      "%s: matching cmd not found for (vdev:%pK)",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_serialization_match_cmd_vdev",
      a2);
  return v13 == a2;
}
