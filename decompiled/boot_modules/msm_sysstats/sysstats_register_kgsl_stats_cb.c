void *__fastcall sysstats_register_kgsl_stats_cb(void *result)
{
  sysstats_kgsl_get_stats = result;
  return result;
}
