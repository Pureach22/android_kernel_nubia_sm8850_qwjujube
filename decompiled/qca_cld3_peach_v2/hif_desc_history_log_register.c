__int64 hif_desc_history_log_register()
{
  ((void (__fastcall *)(const char *, void *, __int64))qdf_ssr_driver_dump_register_region)(
    "hif_event_history",
    &hif_event_desc_history,
    295344);
  return ((__int64 (__fastcall *)(const char *, __int64 **, __int64))qdf_ssr_driver_dump_register_region)(
           "hif_event_hist_max",
           &hif_event_hist_max,
           4);
}
