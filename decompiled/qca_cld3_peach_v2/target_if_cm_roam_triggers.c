__int64 __fastcall target_if_cm_roam_triggers(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  _QWORD *v11; // x8
  const char *v13; // x2

  v10 = *(_QWORD *)(a1 + 216);
  if ( !v10 )
  {
    v13 = "%s: PDEV is NULL";
    goto LABEL_8;
  }
  v11 = *(_QWORD **)(v10 + 1240);
  if ( !v11 || !*v11 )
  {
    v13 = "%s: wmi_handle is null";
LABEL_8:
    qdf_trace_msg(0x49u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_cm_roam_get_wmi_handle_from_vdev");
    return 16;
  }
  if ( *a2 > 5u )
    return 4;
  else
    return wmi_unified_set_roam_triggers();
}
