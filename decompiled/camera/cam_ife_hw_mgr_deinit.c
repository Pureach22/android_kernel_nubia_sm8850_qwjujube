_QWORD *cam_ife_hw_mgr_deinit()
{
  __int64 v0; // x19
  __int64 v1; // x21
  _QWORD *v2; // x8
  int v3; // w8
  _QWORD *v4; // x0
  _QWORD *v5; // x0
  _QWORD *result; // x0

  cam_req_mgr_workq_destroy(&qword_3A84E8);
  qword_3A84F0 = 0;
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)qword_3A8538, 0);
  else
    kvfree(qword_3A8538);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)qword_3A8530, 0);
  else
    kvfree(qword_3A8530);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)qword_3A8538, 0);
  else
    kvfree(qword_3A8538);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)qword_3A8530, 0);
  else
    kvfree(qword_3A8530);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)qword_3A8550, 0);
  else
    kvfree(qword_3A8550);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)qword_3A8548, 0);
  else
    kvfree(qword_3A8548);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)qword_3A8560, 0);
  else
    kvfree(qword_3A8560);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)qword_3A8568, 0);
  else
    kvfree(qword_3A8568);
  v0 = 0;
  v1 = 0;
  do
  {
    cam_tasklet_deinit(&g_ife_hw_mgr[v1]);
    v3 = (unsigned __int8)mem_trace_en;
    v4 = (_QWORD *)g_ife_hw_mgr[v0 + 1112];
    g_ife_hw_mgr[v0 + 1142] = 0;
    if ( v3 == 1 )
      cam_mem_trace_free(v4, 0);
    else
      kvfree(v4);
    v5 = (_QWORD *)g_ife_hw_mgr[v0 + 1113];
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v5, 0);
    else
      kvfree(v5);
    ++v1;
    v2 = &g_ife_hw_mgr[v0];
    v0 += 1251;
    v2[52] = 0;
    v2[1112] = 0;
    v2[1113] = 0;
  }
  while ( v1 != 8 );
  cam_smmu_destroy_handle(dword_39493C);
  dword_39493C = -1;
  cam_smmu_destroy_handle(dword_394938);
  dword_394938 = -1;
  result = (_QWORD *)irq_inject_display_buf;
  dword_3A860C = 0;
  if ( irq_inject_display_buf )
  {
    if ( mem_trace_en == 1 )
      return cam_mem_trace_free((_QWORD *)irq_inject_display_buf, 0);
    else
      return (_QWORD *)kvfree(irq_inject_display_buf);
  }
  return result;
}
