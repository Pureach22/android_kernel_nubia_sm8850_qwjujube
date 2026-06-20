__int64 __fastcall target_if_mlo_register_vdev_tid_to_link_map_event(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  return wmi_unified_register_event_handler(
           a1,
           0x10Du,
           (__int64)target_if_mlo_vdev_tid_to_link_map_event_handler,
           2u,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9);
}
