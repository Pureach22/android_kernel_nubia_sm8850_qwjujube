__int64 __fastcall ucfg_tdls_notify_reset_adapter(
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
  __int64 result; // x0
  __int64 v11; // [xsp+8h] [xbp-38h] BYREF
  __int64 v12; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v13)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 (__fastcall *v14)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+20h] [xbp-20h]
  __int64 v15; // [xsp+28h] [xbp-18h]
  __int64 v16; // [xsp+30h] [xbp-10h]
  __int64 v17; // [xsp+38h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  v13 = nullptr;
  v14 = nullptr;
  v11 = 0;
  v12 = 0;
  if ( a1 )
  {
    qdf_trace_msg(0, 8u, "%s: Enter ", a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_tdls_notify_reset_adapter");
    v12 = a1;
    v13 = tdls_process_cmd;
    v14 = ucfg_tdls_post_msg_flush_cb;
    LOWORD(v11) = 18;
    result = scheduler_post_message_debug(
               0x33u,
               0,
               72,
               (unsigned __int16 *)&v11,
               0x40Cu,
               (__int64)"ucfg_tdls_notify_reset_adapter");
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: vdev is NULL ", a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_tdls_notify_reset_adapter");
    result = 29;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
