__int64 __fastcall wlan_serialization_get_pdev_from_cmd(
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
  __int64 v9; // x8
  const char *v11; // x2

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 32);
    if ( v9 )
      return *(_QWORD *)(v9 + 216);
    v11 = "%s: invalid cmd->vdev";
  }
  else
  {
    v11 = "%s: invalid cmd";
  }
  qdf_trace_msg(0x4Cu, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_serialization_get_pdev_from_cmd");
  return 0;
}
