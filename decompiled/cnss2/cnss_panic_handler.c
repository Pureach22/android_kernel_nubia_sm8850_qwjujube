__int64 __fastcall cnss_panic_handler(__int64 a1)
{
  cnss_bus_dev_crash_shutdown(a1 - 424);
  return 0;
}
