_QWORD *cam_cpas_dev_component_unbind()
{
  __int64 v0; // x0
  _QWORD *result; // x0

  if ( !g_cpas_intf || (*(_BYTE *)(g_cpas_intf + 852) & 1) == 0 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       4,
                       1,
                       "cam_cpas_dev_component_unbind",
                       2148,
                       "cpas intf not initialized");
  mutex_lock(g_cpas_intf + 800);
  v0 = g_cpas_intf + 8;
  *(_BYTE *)(g_cpas_intf + 852) = 0;
  cam_unregister_subdev(v0);
  cam_cpas_hw_remove(*(_QWORD *)(g_cpas_intf + 480));
  mutex_unlock(g_cpas_intf + 800);
  if ( mem_trace_en == 1 )
    result = cam_mem_trace_free((_QWORD *)g_cpas_intf, 0);
  else
    result = (_QWORD *)kvfree(g_cpas_intf);
  g_cpas_intf = 0;
  return result;
}
