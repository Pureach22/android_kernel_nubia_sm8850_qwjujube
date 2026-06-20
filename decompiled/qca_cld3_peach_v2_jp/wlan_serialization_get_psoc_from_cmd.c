__int64 __fastcall wlan_serialization_get_psoc_from_cmd(
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
  __int64 v10; // x8
  const char *v12; // x2

  if ( !a1 )
  {
    v12 = "%s: invalid cmd";
LABEL_7:
    qdf_trace_msg(0x4Cu, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_serialization_get_psoc_from_cmd");
    return 0;
  }
  v9 = *(_QWORD *)(a1 + 32);
  if ( !v9 )
  {
    v12 = "%s: invalid cmd->vdev";
    goto LABEL_7;
  }
  v10 = *(_QWORD *)(v9 + 152);
  if ( v10 )
    return *(_QWORD *)(v10 + 80);
  return 0;
}
