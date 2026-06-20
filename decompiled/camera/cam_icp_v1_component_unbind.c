_QWORD *__fastcall cam_icp_v1_component_unbind(__int64 a1)
{
  _QWORD *v1; // x19
  _QWORD *v2; // x20
  _QWORD *v3; // x0
  _QWORD *v5; // x0

  v1 = *(_QWORD **)(a1 + 152);
  if ( !v1 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       256,
                       1,
                       "cam_icp_v1_component_unbind",
                       225,
                       "Error No data in pdev");
  v2 = (_QWORD *)v1[14];
  cam_cpas_unregister_client(*(_DWORD *)(v2[460] + 56LL));
  cam_icp_soc_resources_deinit(v2 + 12);
  v3 = (_QWORD *)v2[424];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v3, 0);
  else
    kvfree(v3);
  v5 = (_QWORD *)v2[460];
  max_icp_v1_hw_idx = -1;
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v5, 0);
  else
    kvfree(v5);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v2, 0);
  else
    kvfree(v2);
  if ( mem_trace_en == 1 )
    return cam_mem_trace_free(v1, 0);
  else
    return (_QWORD *)kvfree(v1);
}
