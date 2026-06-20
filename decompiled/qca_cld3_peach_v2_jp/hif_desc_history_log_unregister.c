__int64 hif_desc_history_log_unregister()
{
  qdf_ssr_driver_dump_unregister_region("hif_event_hist_max");
  return qdf_ssr_driver_dump_unregister_region("hif_event_history");
}
