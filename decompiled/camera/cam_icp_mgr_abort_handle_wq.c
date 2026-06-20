__int64 __fastcall cam_icp_mgr_abort_handle_wq(const void *a1, _QWORD *a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x22
  __int64 v5; // x6
  __int64 result; // x0
  unsigned int v7; // w0
  unsigned int v8; // w20
  __int64 v9; // x0
  _QWORD *v10; // x20
  unsigned int v11; // w21
  __int64 v12[2]; // [xsp+10h] [xbp-10h] BYREF

  v12[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v2 = a2[1];
    if ( v2 )
    {
      v3 = *(_QWORD *)(v2 + 8);
      v4 = *(_QWORD *)(v2 + 16);
      v5 = *(unsigned int *)(v2 + 4);
      if ( v4 == *(_QWORD *)(*(_QWORD *)(v3 + 96) + 8 * v5) )
      {
        if ( v4 )
        {
          v12[0] = 0;
          v7 = cam_icp_mgr_populate_abort_cmd(v2, v12);
          if ( v7 )
          {
            v8 = v7;
            if ( mem_trace_en == 1 )
              cam_mem_trace_free((_QWORD *)v2, 0);
            else
              kvfree(v2);
            result = v8;
          }
          else
          {
            v9 = *(unsigned int *)(v3 + 156);
            v10 = (_QWORD *)v12[0];
            v11 = hfi_write_cmd(v9, v12[0]);
            if ( v11 )
            {
              if ( mem_trace_en == 1 )
                cam_mem_trace_free((_QWORD *)v2, 0);
              else
                kvfree(v2);
            }
            else if ( (debug_mdl & 0x100) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x100,
                4,
                "cam_icp_mgr_abort_handle_wq",
                4917,
                "%s: fw_handle = 0x%x ctx_data = %pK",
                (const char *)(v4 + 29824),
                *(_DWORD *)(v4 + 72),
                (const void *)v4);
            }
            if ( mem_trace_en == 1 )
              cam_mem_trace_free(v10, 0);
            else
              kvfree(v10);
            result = v11;
          }
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_mgr_abort_handle_wq",
            4898,
            "Invalid ctx_data, ctx_id: %d",
            v5);
          if ( mem_trace_en == 1 )
            cam_mem_trace_free((_QWORD *)v2, 0);
          else
            kvfree(v2);
          result = 4294967274LL;
        }
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          2,
          "cam_icp_mgr_abort_handle_wq",
          4891,
          "ctx data is released before accessing it, ctx_id: %u",
          v5);
        if ( mem_trace_en == 1 )
          cam_mem_trace_free((_QWORD *)v2, 0);
        else
          kvfree(v2);
        result = 0;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD *, const void *))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_abort_handle_wq",
        4884,
        "Invalid ctx_info",
        a2,
        a1);
      result = 4294967274LL;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_abort_handle_wq",
      4876,
      "Invalid params %pK %pK",
      a2,
      a1);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
