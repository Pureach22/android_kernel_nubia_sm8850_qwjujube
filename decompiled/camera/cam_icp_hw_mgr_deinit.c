_QWORD *__fastcall cam_icp_hw_mgr_deinit(__int64 a1)
{
  int v1; // w19
  __int64 v2; // x20
  __int64 v3; // x21
  int v4; // w0
  _QWORD *result; // x0
  void (__fastcall *v6)(__int64, __int64, __int64, __int64); // x8
  __int64 v7; // x0
  unsigned int v8; // w21
  _QWORD *v9; // x0
  _QWORD *v10; // x0
  __int64 v11; // x24
  __int64 v12; // x8
  __int64 v13; // x21
  __int64 v14; // x0
  _QWORD *v15; // x0
  _QWORD *v16; // x0
  _QWORD *v17; // x0
  _QWORD *v18; // x0

  if ( (unsigned int)a1 >= 2 )
  {
    __break(0x5512u);
    return (_QWORD *)cam_icp_cpas_deactivate_llcc(a1);
  }
  else
  {
    v1 = a1;
    v2 = g_icp_hw_mgr[(unsigned int)a1];
    if ( v2 )
    {
      if ( (debug_mdl & 0x100) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x100,
          4,
          "cam_icp_hw_mgr_deinit",
          10236,
          "hw mgr deinit: %u icp name: %s",
          a1,
          (const char *)(v2 + 112));
      v3 = *(_QWORD *)(v2 + 80);
      *(_QWORD *)(v2 + 44088) = 0;
      v4 = ((__int64 (__fastcall *)(__int64))cam_hfi_unregister)(v2 + 156);
      if ( v4 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_unregister_hfi_client",
          9992,
          "[%s] Failed to unregister hfi client hdl: %d rc: %d",
          (const char *)(v2 + 112),
          *(_DWORD *)(v2 + 156),
          v4);
      }
      else if ( v3 )
      {
        v6 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v3 + 88);
        v7 = *(_QWORD *)(v3 + 112);
        if ( *((_DWORD *)v6 - 1) != -1055839300 )
          __break(0x8228u);
        v6(v7, 16, v2 + 156, 4);
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_unregister_hfi_client",
          9997,
          "[%s] ICP dev intf is NULL",
          (const char *)(v2 + 112));
      }
      cam_req_mgr_workq_destroy((_QWORD *)(v2 + 1008));
      cam_req_mgr_workq_destroy((_QWORD *)(v2 + 1000));
      cam_req_mgr_workq_destroy((_QWORD *)(v2 + 992));
      cam_smmu_destroy_handle(*(_DWORD *)(v2 + 148));
      if ( *(_DWORD *)(v2 + 64) )
      {
        v8 = 0;
        do
        {
          v9 = *(_QWORD **)(*(_QWORD *)(v2 + 56) + 584LL * (int)v8 + 16);
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v9, 0);
          else
            kvfree(v9);
          ++v8;
        }
        while ( v8 < *(_DWORD *)(v2 + 64) );
      }
      v10 = *(_QWORD **)(v2 + 56);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v10, 0);
      else
        kvfree(v10);
      v11 = 0;
      *(_QWORD *)(v2 + 56) = 0;
      *(_QWORD *)(v2 + 80) = 0;
      do
      {
        v12 = *(_QWORD *)(v2 + 96);
        v13 = *(_QWORD *)(v12 + v11);
        if ( v13 )
        {
          v14 = cam_icp_cpas_deactivate_llcc(*(_QWORD *)(v12 + v11));
          if ( (cam_presil_mode_enabled(v14) & 1) != 0 )
          {
            v15 = *(_QWORD **)(v13 + 29184);
            if ( mem_trace_en == 1 )
              cam_mem_trace_free(v15, 0);
            else
              kvfree(v15);
          }
          v16 = *(_QWORD **)(*(_QWORD *)(v2 + 96) + v11);
          if ( mem_trace_en == 1 )
            cam_mem_trace_free(v16, 0);
          else
            kvfree(v16);
        }
        v11 += 8;
      }
      while ( v11 != 432 );
      v17 = *(_QWORD **)(v2 + 88);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v17, 0);
      else
        kvfree(v17);
      v18 = *(_QWORD **)(v2 + 96);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v18, 0);
      else
        kvfree(v18);
      if ( mem_trace_en == 1 )
        result = cam_mem_trace_free((_QWORD *)v2, 0);
      else
        result = (_QWORD *)kvfree(v2);
      g_icp_hw_mgr[v1] = 0;
    }
    else
    {
      return (_QWORD *)((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                         3,
                         256,
                         1,
                         "cam_icp_hw_mgr_deinit",
                         10232,
                         "Uninitialized hw mgr for subdev: %u",
                         a1);
    }
  }
  return result;
}
