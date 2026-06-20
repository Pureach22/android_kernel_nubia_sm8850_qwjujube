__int64 __fastcall sme_roam_control_restore_default_config(
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
  if ( a2 < 6u )
    return cm_roam_control_restore_default_config(*(_QWORD *)(a1 + 21632), a2);
  qdf_trace_msg(
    0x34u,
    2u,
    "%s: Invalid vdev_id: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "sme_roam_control_restore_default_config");
  return 4;
}
