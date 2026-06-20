__int64 hif_ce_desc_history_log_unregister()
{
  qdf_ssr_driver_dump_unregister_region("hif_ce_only_for_crit");
  qdf_ssr_driver_dump_unregister_region("hif_ce_history_max");
  qdf_ssr_driver_dump_unregister_region("hif_ce_count_max");
  qdf_ssr_driver_dump_unregister_region("hif_ce_desc_hist");
  return qdf_ssr_driver_dump_unregister_region("hif_ce_desc_history_buff");
}
