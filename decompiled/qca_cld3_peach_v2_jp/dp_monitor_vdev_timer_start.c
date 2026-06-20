__int64 __fastcall dp_monitor_vdev_timer_start(
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
  __int64 (*v11)(void); // x8
  const char *v13; // x2

  v9 = *(_QWORD *)(a1 + 20056);
  if ( !v9 )
  {
    v13 = "%s: monitor soc is NULL";
    return qdf_trace_msg(0x92u, 8u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "dp_monitor_vdev_timer_start");
  }
  v10 = *(_QWORD *)(v9 + 416);
  if ( !v10 || (v11 = *(__int64 (**)(void))(v10 + 496)) == nullptr )
  {
    v13 = "%s: callback not registered";
    return qdf_trace_msg(0x92u, 8u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "dp_monitor_vdev_timer_start");
  }
  if ( *((_DWORD *)v11 - 1) != -1093861181 )
    __break(0x8228u);
  return v11();
}
