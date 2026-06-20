_QWORD *__fastcall cam_bps_component_unbind(__int64 a1)
{
  _QWORD **v1; // x8
  _QWORD *v2; // x19
  _QWORD *v3; // x20
  _QWORD *v4; // x0
  const char *v5; // x5
  __int64 v6; // x4

  if ( (debug_mdl & 0x100) == 0 || debug_priority )
  {
    v1 = *(_QWORD ***)(a1 + 152);
    if ( v1 )
      goto LABEL_4;
LABEL_16:
    v5 = "Error No data in pdev";
    v6 = 230;
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       256,
                       1,
                       "cam_bps_component_unbind",
                       v6,
                       v5);
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x100,
    4,
    "cam_bps_component_unbind",
    227,
    "Unbinding component: %s",
    *(const char **)(a1 - 16));
  v1 = *(_QWORD ***)(a1 + 152);
  if ( !v1 )
    goto LABEL_16;
LABEL_4:
  v2 = *v1;
  if ( !*v1 )
  {
    v5 = "Error No BPS dev interface";
    v6 = 236;
    return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                       3,
                       256,
                       1,
                       "cam_bps_component_unbind",
                       v6,
                       v5);
  }
  v3 = (_QWORD *)v2[14];
  cam_cpas_unregister_client(*(_DWORD *)(v3[460] + 8LL));
  cam_bps_deinit_soc_resources(v3 + 12);
  v4 = (_QWORD *)v3[460];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v4, 0);
  else
    kvfree(v4);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v3, 0);
  else
    kvfree(v3);
  if ( mem_trace_en == 1 )
    return cam_mem_trace_free(v2, 0);
  else
    return (_QWORD *)kvfree(v2);
}
