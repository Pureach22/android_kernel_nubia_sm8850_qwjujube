__int64 __fastcall cam_cpas_hw_remove(_QWORD *a1)
{
  __int64 v1; // x19
  const char *v2; // x5
  __int64 v3; // x4
  __int64 v6; // x20
  __int64 v7; // x21
  __int64 v8; // x21
  __int64 v9; // x24
  __int64 v10; // x0
  __int64 v11; // x0

  if ( !a1 )
  {
    v2 = "cpas interface not initialized";
    v3 = 5441;
    goto LABEL_5;
  }
  v1 = a1[14];
  if ( *(_DWORD *)(v1 + 92) == 1 )
  {
    v2 = "cpas hw is in power up state";
    v3 = 5449;
LABEL_5:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_hw_remove",
      v3,
      v2);
    return 4294967274LL;
  }
  v6 = *(_QWORD *)(v1 + 3680);
  mutex_lock(a1[14]);
  v7 = *(_QWORD *)(v1 + 3392);
  sysfs_remove_file_ns(*(_QWORD *)(v7 + 1328), &cam_subparts_info_attribute, 0);
  kobject_put(*(_QWORD *)(v7 + 1328));
  mutex_unlock(v1);
  cam_cpas_util_axi_cleanup(v6);
  cam_cpas_node_tree_cleanup(v6, *(_QWORD **)(v1 + 3392));
  if ( (*(_BYTE *)(v6 + 2856) & 1) != 0 )
  {
    cam_soc_bus_client_unregister(v6 + 3088);
    *(_DWORD *)(v6 + 2912) = 0;
    *(_BYTE *)(v6 + 2856) = 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_unregister_bus_client",
      481,
      "bus client not valid");
  }
  v8 = 0;
  v9 = *(_QWORD *)(v1 + 3680) + 320LL;
  do
  {
    v10 = *(_QWORD *)(v9 + 8 * v8);
    if ( v10 && *(_BYTE *)(v10 + 168) == 1 )
    {
      cam_cpas_hw_unregister_client(v1, v8);
      v10 = *(_QWORD *)(v9 + 8 * v8);
    }
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v10, 0);
    else
      kvfree(v10);
    *(_QWORD *)(v9 + 8 * v8++) = 0;
  }
  while ( v8 != 43 );
  cam_cpas_soc_deinit_resources(v1 + 96);
  v11 = *(_QWORD *)(v6 + 8096);
  *(_QWORD *)(v6 + 8136) = 0;
  _flush_workqueue(v11);
  destroy_workqueue(*(_QWORD *)(v6 + 8096));
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v6, 0);
  else
    kvfree(v6);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v1, 0);
  else
    kvfree(v1);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(a1, 0);
  else
    kvfree(a1);
  return 0;
}
