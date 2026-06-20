int *__fastcall cam_virtual_cdm_work(int *result)
{
  int *v1; // x19
  __int64 v2; // x21
  int *v3; // x20
  __int64 v4; // x23
  int v5; // w8
  _DWORD *request_by_bl_tag; // x0
  int v7; // w8
  _QWORD *v8; // x22
  _QWORD *v9; // x8
  _QWORD *v10; // x9
  __int64 v11; // x10

  v1 = result - 8;
  if ( result != &dword_20 )
  {
    v2 = *((_QWORD *)result - 4);
    v3 = result;
    v4 = *(_QWORD *)(v2 + 3680);
    cam_common_util_thread_switch_delay_detect(
      "virtual_cdm_workq",
      "schedule",
      cam_virtual_cdm_work,
      *((_QWORD *)result - 1),
      5u);
    v5 = *(v3 - 6);
    if ( (v5 & 2) != 0 )
    {
      if ( (debug_mdl & 1) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          4,
          "cam_virtual_cdm_work",
          49,
          "CDM HW Gen/inline IRQ with data=%x",
          *(v3 - 5));
      mutex_lock(v2);
      request_by_bl_tag = cam_cdm_find_request_by_bl_tag(*(v3 - 5), (_QWORD *)(v4 + 184));
      if ( request_by_bl_tag )
      {
        v7 = request_by_bl_tag[1];
        v8 = request_by_bl_tag;
        if ( v7 == 2 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            1,
            1,
            "cam_virtual_cdm_work",
            63,
            "Invalid node=%pK %d",
            request_by_bl_tag,
            2);
        }
        else if ( v7 == 1 )
        {
          cam_cdm_notify_clients(v2, 0, (__int64)request_by_bl_tag);
        }
        v9 = (_QWORD *)v8[5];
        v10 = v8 + 4;
        if ( (_QWORD *)*v9 == v8 + 4 && (v11 = *v10, *(_QWORD **)(*v10 + 8LL) == v10) )
        {
          *(_QWORD *)(v11 + 8) = v9;
          *v9 = v11;
        }
        else
        {
          _list_del_entry_valid_or_report(v8 + 4);
        }
        v8[4] = v8 + 4;
        v8[5] = v10;
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v8, 0);
        else
          kvfree(v8);
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          1,
          1,
          "cam_virtual_cdm_work",
          68,
          "Invalid node for inline irq");
      }
      mutex_unlock(v2);
      v5 = *(v3 - 6);
    }
    if ( (v5 & 1) != 0 )
    {
      if ( (debug_mdl & 1) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          1,
          4,
          "cam_virtual_cdm_work",
          73,
          "CDM HW reset done IRQ");
      complete(v4 + 144);
    }
    if ( mem_trace_en == 1 )
      return (int *)cam_mem_trace_free(v1, 0);
    else
      return (int *)kvfree(v1);
  }
  return result;
}
