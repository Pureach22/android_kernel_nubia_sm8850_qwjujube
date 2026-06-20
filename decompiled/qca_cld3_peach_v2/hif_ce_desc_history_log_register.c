__int64 __fastcall hif_ce_desc_history_log_register(__int64 a1)
{
  ((void (__fastcall *)(const char *, void *, __int64))qdf_ssr_driver_dump_register_region)(
    "hif_ce_desc_history_buff",
    &hif_ce_desc_history_buff,
    172032);
  ((void (__fastcall *)(const char *, __int64, __int64))qdf_ssr_driver_dump_register_region)(
    "hif_ce_desc_hist",
    a1 + 2752,
    1184);
  ((void (__fastcall *)(const char *, void *, __int64))qdf_ssr_driver_dump_register_region)(
    "hif_ce_count_max",
    &hif_ce_count_max,
    4);
  ((void (__fastcall *)(const char *, void *, __int64))qdf_ssr_driver_dump_register_region)(
    "hif_ce_history_max",
    &hif_ce_history_max,
    4);
  return ((__int64 (__fastcall *)(const char *, void *, __int64))qdf_ssr_driver_dump_register_region)(
           "hif_ce_only_for_crit",
           &hif_ce_only_for_crit,
           1);
}
