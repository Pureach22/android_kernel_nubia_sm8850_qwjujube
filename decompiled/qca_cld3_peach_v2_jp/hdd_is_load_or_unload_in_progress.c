bool __fastcall hdd_is_load_or_unload_in_progress(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  return (cds_get_driver_state(a1, a2, a3, a4, a5, a6, a7, a8) & 6) != 0;
}
