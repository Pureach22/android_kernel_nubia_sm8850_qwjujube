_QWORD *__fastcall cam_ipe_component_unbind(__int64 a1)
{
  __int64 v1; // x21
  _QWORD *v2; // x19
  _QWORD *v3; // x20
  _QWORD *v4; // x0
  const char *v5; // x5
  __int64 v6; // x4
  _QWORD *v7; // x0

  if ( (debug_mdl & 0x100) == 0 || debug_priority )
  {
    v1 = *(_QWORD *)(a1 + 152);
    if ( v1 )
      goto LABEL_4;
LABEL_20:
    v5 = "Error No data in pdev";
    v6 = 214;
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       256,
                       1,
                       "cam_ipe_component_unbind",
                       v6,
                       v5);
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x100,
    4,
    "cam_ipe_component_unbind",
    211,
    "Unbinding component: %s",
    *(const char **)(a1 - 16));
  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
    goto LABEL_20;
LABEL_4:
  v2 = *(_QWORD **)v1;
  if ( !*(_QWORD *)v1 )
  {
    v5 = "Error No IPE dev interface";
    v6 = 220;
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       256,
                       1,
                       "cam_ipe_component_unbind",
                       v6,
                       v5);
  }
  v3 = (_QWORD *)v2[14];
  cam_cpas_unregister_client(*(_DWORD *)(v3[460] + 8LL));
  v4 = *(_QWORD **)(v1 + 16);
  if ( v4 )
  {
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v4, 0);
    else
      kvfree(v4);
  }
  cam_ipe_deinit_soc_resources(v3 + 12);
  v7 = (_QWORD *)v3[460];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v7, 0);
  else
    kvfree(v7);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v3, 0);
  else
    kvfree(v3);
  if ( mem_trace_en == 1 )
    return cam_mem_trace_free(v2, 0);
  else
    return (_QWORD *)kvfree(v2);
}
