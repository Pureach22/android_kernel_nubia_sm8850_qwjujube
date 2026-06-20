__int64 __fastcall hdd_handle_country_change_work_error(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  __int64 v21; // x1

  if ( a2 == -11 )
  {
    qdf_sleep();
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: rescheduling country change work",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "hdd_handle_country_change_work_error");
    return queue_work_on(32, system_wq, a1 + 6784);
  }
  else
  {
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: can not handle country change %d",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "hdd_handle_country_change_work_error",
               a2);
    if ( a2 != -19 )
    {
      qdf_event_set_all(a1 + 6928, v21);
      qdf_mutex_acquire(a1 + 6968);
      *(_BYTE *)(a1 + 6924) = 0;
      return qdf_mutex_release(a1 + 6968);
    }
  }
  return result;
}
