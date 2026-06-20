_QWORD *__fastcall cam_vfe_component_unbind(__int64 a1)
{
  _QWORD *v1; // x19
  __int64 v2; // x8
  _QWORD *v3; // x20
  _QWORD *v4; // x0
  int v5; // w0
  _QWORD *v6; // x0
  int v8; // w0
  char v9; // w8

  v1 = *(_QWORD **)(a1 + 152);
  if ( !v1 )
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       8,
                       1,
                       "cam_vfe_component_unbind",
                       202,
                       "Error! No data in pdev");
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_vfe_component_unbind",
      207,
      "VFE component unbind, type %d index %d",
      *(_DWORD *)v1,
      *((_DWORD *)v1 + 1));
  v2 = *((unsigned int *)v1 + 1);
  if ( (unsigned int)v2 <= 7 )
    cam_vfe_hw_list[4 * v2] = 0;
  v3 = (_QWORD *)v1[14];
  if ( !v3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_component_unbind",
      214,
      "Error! HW data is NULL");
    goto LABEL_25;
  }
  v4 = (_QWORD *)v3[460];
  if ( v4 )
  {
    v5 = cam_vfe_core_deinit(v4, *v4);
    if ( v5 < 0 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_component_unbind",
        226,
        "Failed to deinit core rc=%d",
        v5);
    v6 = (_QWORD *)v3[460];
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v6, 0);
    else
      kvfree(v6);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_component_unbind",
      220,
      "Error! core data NULL");
  }
  v8 = cam_vfe_deinit_soc_resources((__int64)(v3 + 12));
  if ( v8 < 0 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_component_unbind",
      233,
      "Failed to deinit soc rc=%d",
      v8);
  if ( mem_trace_en != 1 )
  {
    kvfree(v3);
    v9 = debug_mdl;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_25;
LABEL_23:
    if ( !debug_priority )
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v9 & 8,
        4,
        "cam_vfe_component_unbind",
        238,
        "VFE%d component unbound",
        *((_DWORD *)v1 + 1));
    goto LABEL_25;
  }
  cam_mem_trace_free(v3, 0);
  v9 = debug_mdl;
  if ( (debug_mdl & 8) != 0 )
    goto LABEL_23;
LABEL_25:
  if ( mem_trace_en == 1 )
    return cam_mem_trace_free(v1, 0);
  else
    return (_QWORD *)kvfree(v1);
}
