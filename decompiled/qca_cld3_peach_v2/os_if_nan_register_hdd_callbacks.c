__int64 __fastcall os_if_nan_register_hdd_callbacks(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  *a2 = os_if_nan_discovery_event_handler;
  a2[1] = os_if_nan_datapath_event_handler;
  return ucfg_nan_register_hdd_callbacks(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}
