_QWORD *__fastcall cam_icp_v2_component_unbind(__int64 a1)
{
  _QWORD *v1; // x21
  _QWORD *v2; // x19
  _QWORD *v3; // x20
  _QWORD *v4; // x0
  _QWORD *v6; // x21
  _QWORD *v7; // x0
  int v8; // w8
  _QWORD *v9; // x0

  v1 = *(_QWORD **)(a1 + 152);
  if ( !v1 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       256,
                       1,
                       "cam_icp_v2_component_unbind",
                       213,
                       "Error No data in pdev");
  v2 = (_QWORD *)*v1;
  if ( !*v1 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       256,
                       1,
                       "cam_icp_v2_component_unbind",
                       219,
                       "Error No ICP dev interface");
  v3 = (_QWORD *)v2[14];
  cam_icp_v2_cpas_unregister(*v1);
  cam_icp_soc_resources_deinit(v3 + 12);
  v4 = (_QWORD *)v1[2];
  if ( v4 )
  {
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v4, 0);
    else
      kvfree(v4);
  }
  v6 = (_QWORD *)v3[424];
  v7 = (_QWORD *)v6[10];
  if ( v7 )
  {
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v7, 0);
    else
      kvfree(v7);
    v6[10] = 0;
    v6 = (_QWORD *)v3[424];
  }
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v6, 0);
  else
    kvfree(v6);
  v8 = (unsigned __int8)mem_trace_en;
  v9 = (_QWORD *)v3[460];
  v3[424] = 0;
  max_icp_v2_hw_idx = -1;
  if ( v8 == 1 )
    cam_mem_trace_free(v9, 0);
  else
    kvfree(v9);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v3, 0);
  else
    kvfree(v3);
  if ( mem_trace_en == 1 )
    return cam_mem_trace_free(v2, 0);
  else
    return (_QWORD *)kvfree(v2);
}
