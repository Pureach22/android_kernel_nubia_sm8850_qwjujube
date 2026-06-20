__int64 __fastcall sme_set_cal_failure_event_cb(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7

  if ( result )
  {
    v2 = result;
    if ( (unsigned int)qdf_mutex_acquire(result + 12776) )
    {
      return qdf_trace_msg(
               0x34u,
               2u,
               "%s: sme_acquire_global_lock failed",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "sme_set_cal_failure_event_cb");
    }
    else
    {
      *(_QWORD *)(v2 + 21992) = a2;
      return qdf_mutex_release(v2 + 12776);
    }
  }
  return result;
}
