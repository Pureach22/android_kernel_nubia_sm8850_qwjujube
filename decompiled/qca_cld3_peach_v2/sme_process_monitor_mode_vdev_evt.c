__int64 __fastcall sme_process_monitor_mode_vdev_evt(
        unsigned int a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _DWORD *v21; // x8
  __int64 v23; // x20

  context = _cds_get_context(52, (__int64)"sme_process_monitor_mode_vdev_evt", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
    return 4;
  v21 = (_DWORD *)context[1836];
  if ( v21 )
  {
    if ( *(v21 - 1) != 2130452855 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD, _QWORD))v21)(a1, a2 & 1);
    return 0;
  }
  else
  {
    v23 = jiffies;
    if ( sme_process_monitor_mode_vdev_evt___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x34u,
        3u,
        "%s: monitor_mode_cb is not registered",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "sme_process_monitor_mode_vdev_evt");
      sme_process_monitor_mode_vdev_evt___last_ticks = v23;
    }
    return 16;
  }
}
