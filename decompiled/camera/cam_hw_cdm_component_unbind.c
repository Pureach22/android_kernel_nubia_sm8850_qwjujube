_QWORD *__fastcall cam_hw_cdm_component_unbind(__int64 a1)
{
  _QWORD *v1; // x20
  __int64 v2; // x19
  unsigned int *v3; // x21
  int v5; // w0
  _QWORD *v6; // x0
  int v7; // w8
  _QWORD *v8; // x0
  int v9; // w8

  v1 = *(_QWORD **)(a1 + 152);
  if ( !v1 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       1,
                       1,
                       "cam_hw_cdm_component_unbind",
                       2599,
                       "Failed to get dev private data");
  v2 = v1[14];
  if ( !v2 )
    return (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       1,
                       1,
                       "cam_hw_cdm_component_unbind",
                       2607,
                       "Failed to get hw private data for type=%d idx=%d",
                       *(_DWORD *)v1,
                       *((_DWORD *)v1 + 1));
  v3 = *(unsigned int **)(v2 + 3680);
  if ( !v3 )
    return (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       1,
                       1,
                       "cam_hw_cdm_component_unbind",
                       2615,
                       "Failed to get hw core data for type=%d idx=%d",
                       *(_DWORD *)v1,
                       *((_DWORD *)v1 + 1));
  if ( *(_DWORD *)(v2 + 88) )
    return (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                       3,
                       1,
                       1,
                       "cam_hw_cdm_component_unbind",
                       2622,
                       "Hw open count invalid type=%d idx=%d cnt=%d",
                       *(_DWORD *)v1,
                       *((_DWORD *)v1 + 1),
                       *(_DWORD *)(v2 + 88));
  if ( *(_DWORD *)(v2 + 92) == 1 && (unsigned int)cam_hw_cdm_deinit(v1[14]) )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       1,
                       1,
                       "cam_hw_cdm_component_unbind",
                       2629,
                       "Deinit failed for hw");
  v5 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64, _QWORD))cam_cdm_intf_deregister_hw_cdm)(
         v1,
         *(_QWORD *)(v2 + 3392),
         1,
         *v3);
  if ( v5 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_component_unbind",
      2638,
      "HW_CDM interface deregistration failed: rd: %d",
      v5);
  if ( (unsigned int)cam_cpas_unregister_client(v3[1217]) )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       1,
                       1,
                       "cam_hw_cdm_component_unbind",
                       2643,
                       "CPAS unregister failed");
  if ( (unsigned int)cam_soc_util_release_platform_resource(v2 + 96) )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_component_unbind",
      2648,
      "Release platform resource failed");
  _flush_workqueue(*((_QWORD *)v3 + 291));
  destroy_workqueue(*((_QWORD *)v3 + 291));
  _flush_workqueue(*((_QWORD *)v3 + 371));
  destroy_workqueue(*((_QWORD *)v3 + 371));
  _flush_workqueue(*((_QWORD *)v3 + 451));
  destroy_workqueue(*((_QWORD *)v3 + 451));
  _flush_workqueue(*((_QWORD *)v3 + 531));
  destroy_workqueue(*((_QWORD *)v3 + 531));
  cam_smmu_unset_client_page_fault_handler(v3[56], v2);
  if ( (unsigned int)cam_smmu_destroy_handle(v3[56]) )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_component_unbind",
      2658,
      "Release iommu secure hdl failed");
  v6 = *(_QWORD **)(v2 + 3392);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v6, 0);
  else
    kvfree(v6);
  v7 = (unsigned __int8)mem_trace_en;
  *(_QWORD *)(v2 + 3392) = 0;
  if ( v7 == 1 )
    cam_mem_trace_free(v1, 0);
  else
    kvfree(v1);
  v8 = *(_QWORD **)(v2 + 3680);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v8, 0);
  else
    kvfree(v8);
  v9 = (unsigned __int8)mem_trace_en;
  *(_QWORD *)(v2 + 3680) = 0;
  if ( v9 == 1 )
    return cam_mem_trace_free((_QWORD *)v2, 0);
  else
    return (_QWORD *)kvfree(v2);
}
