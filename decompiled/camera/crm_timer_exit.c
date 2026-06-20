const void **__fastcall crm_timer_exit(const void **result)
{
  const void **v1; // x19
  char *v2; // x8

  v1 = result;
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    result = (const void **)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                              3,
                              debug_mdl & 0x10,
                              4,
                              "crm_timer_exit",
                              85,
                              "destroy timer %pK @ %pK",
                              *result,
                              result);
    v2 = (char *)*v1;
    if ( !*v1 )
      return result;
  }
  else
  {
    v2 = (char *)*result;
    if ( !*result )
      return result;
  }
  timer_delete_sync(v2 + 8);
  result = (const void **)g_cam_req_mgr_timer_cachep;
  if ( g_cam_req_mgr_timer_cachep )
    result = (const void **)kmem_cache_free(g_cam_req_mgr_timer_cachep, *v1);
  *v1 = nullptr;
  return result;
}
