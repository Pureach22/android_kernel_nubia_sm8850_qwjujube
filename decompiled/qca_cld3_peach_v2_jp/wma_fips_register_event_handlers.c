__int64 __fastcall wma_fips_register_event_handlers(
        _QWORD **a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  return wmi_unified_register_event_handler(
           *a1,
           0x2Cu,
           (__int64)wma_fips_event_handler,
           0,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9);
}
