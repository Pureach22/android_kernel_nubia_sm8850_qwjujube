__int64 __fastcall wmi_unified_register_raw_event_handler(
        _QWORD *a1,
        unsigned int a2,
        __int64 a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  return wmi_register_event_handler_with_ctx(a1, a2, a3, a4, 1, a5, a6, a7, a8, a9, a10, a11, a12);
}
