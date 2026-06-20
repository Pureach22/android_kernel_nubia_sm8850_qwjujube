__int64 __fastcall wma_service_ready_ext_evt_timeout(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  return qdf_trace_msg(
           0x36u,
           1u,
           "%s: Timeout waiting for WMI_SERVICE_READY_EXT_EVENT",
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           "wma_service_ready_ext_evt_timeout");
}
