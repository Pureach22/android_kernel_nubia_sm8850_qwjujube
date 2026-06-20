_QWORD *__fastcall hdd_sme_monitor_mode_callback(
        unsigned __int8 a1,
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
  _QWORD *result; // x0
  __int64 v13; // x1
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _DWORD *v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x20
  __int64 v32; // x20
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7

  result = _cds_get_context(51, (__int64)"hdd_sme_monitor_mode_callback", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    result = (_QWORD *)hdd_get_link_info_by_vdev((__int64)result, a1);
    if ( result )
    {
      v22 = (_DWORD *)*result;
      if ( *(_DWORD *)*result == 1885692259 )
      {
        if ( (a2 & 1) != 0 )
        {
          qdf_event_set((__int64)(v22 + 416), v13);
          result = (_QWORD *)qdf_trace_msg(
                               0x33u,
                               8u,
                               "%s: monitor mode vdev up completed for vdev %d",
                               v23,
                               v24,
                               v25,
                               v26,
                               v27,
                               v28,
                               v29,
                               v30,
                               "hdd_sme_monitor_mode_callback",
                               a1);
          *((_BYTE *)v22 + 52194) = 0;
        }
        else
        {
          qdf_event_set((__int64)(v22 + 426), v13);
          return (_QWORD *)qdf_trace_msg(
                             0x33u,
                             8u,
                             "%s: monitor mode vdev stop completed for vdev %d",
                             v33,
                             v34,
                             v35,
                             v36,
                             v37,
                             v38,
                             v39,
                             v40,
                             "hdd_sme_monitor_mode_callback",
                             a1);
        }
      }
      else
      {
        v32 = jiffies;
        if ( hdd_sme_monitor_mode_callback___last_ticks_409 - jiffies + 125 < 0 )
        {
          result = (_QWORD *)qdf_trace_msg(
                               0x33u,
                               2u,
                               "%s: Invalid magic",
                               v14,
                               v15,
                               v16,
                               v17,
                               v18,
                               v19,
                               v20,
                               v21,
                               "hdd_sme_monitor_mode_callback");
          hdd_sme_monitor_mode_callback___last_ticks_409 = v32;
        }
      }
    }
    else
    {
      v31 = jiffies;
      if ( hdd_sme_monitor_mode_callback___last_ticks - jiffies + 125 < 0 )
      {
        result = (_QWORD *)qdf_trace_msg(
                             0x33u,
                             2u,
                             "%s: NULL adapter",
                             v14,
                             v15,
                             v16,
                             v17,
                             v18,
                             v19,
                             v20,
                             v21,
                             "hdd_sme_monitor_mode_callback");
        hdd_sme_monitor_mode_callback___last_ticks = v31;
      }
    }
  }
  return result;
}
