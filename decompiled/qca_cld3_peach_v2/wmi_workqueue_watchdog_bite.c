__int64 __fastcall wmi_workqueue_watchdog_bite(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  qdf_trace_msg(
    0x38u,
    2u,
    "%s: WLAN_BUG_RCA: Message type %x has exceeded its allotted time of %ds",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wmi_workqueue_watchdog_warn",
    *a1,
    30);
  return qdf_print_thread_trace(*((_QWORD *)a1 + 2));
}
