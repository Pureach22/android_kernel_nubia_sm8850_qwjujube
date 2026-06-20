__int64 __fastcall msm_geni_serial_driver_shutdown(__int64 a1)
{
  dev_info(a1 + 16, "%s called %d\n", "msm_geni_serial_driver_shutdown", 1);
  return msm_geni_serial_remove(a1);
}
