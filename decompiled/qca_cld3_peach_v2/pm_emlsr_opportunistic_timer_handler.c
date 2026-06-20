__int64 __fastcall pm_emlsr_opportunistic_timer_handler(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  __int64 v19; // [xsp+0h] [xbp-10h] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v19) = 0;
  LODWORD(v19) = 0;
  if ( a1 )
  {
    if ( (unsigned int)policy_mgr_get_mode_specific_conn_info(a1, 0, (unsigned __int64)&v19, 0) )
      result = ml_nlink_conn_change_notify(a1, (unsigned __int8)v19, 20, 0);
    else
      result = qdf_trace_msg(
                 0x4Fu,
                 8u,
                 "emlsr timeout, no sta active",
                 v10,
                 v11,
                 v12,
                 v13,
                 v14,
                 v15,
                 v16,
                 v17,
                 v19,
                 v20);
  }
  else
  {
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: Invalid Context",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "pm_emlsr_opportunistic_timer_handler",
               v19,
               v20);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
