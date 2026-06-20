__int64 __fastcall cam_virtual_cdm_remove(__int64 a1)
{
  unsigned int *v1; // x19
  _QWORD *v2; // x20
  unsigned int *v3; // x21
  unsigned int v4; // w0
  const char *v5; // x5
  unsigned int v6; // w19
  __int64 v7; // x4
  __int64 v9; // x6
  __int64 v10; // x7
  const char *v11; // x5
  __int64 v12; // x4
  unsigned int v13; // w0
  _QWORD *v14; // x0
  _QWORD *v15; // x0

  v1 = *(unsigned int **)(a1 + 168);
  if ( !v1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_virtual_cdm_remove",
      374,
      "Failed to get dev private data");
    return 4294967280LL;
  }
  v2 = *((_QWORD **)v1 + 14);
  if ( !v2 )
  {
    v9 = *v1;
    v10 = v1[1];
    v11 = "Failed to get virtual private data for type=%d idx=%d";
    v12 = 382;
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      1,
      1,
      "cam_virtual_cdm_remove",
      v12,
      v11,
      v9,
      v10);
    return 4294967280LL;
  }
  v3 = (unsigned int *)v2[460];
  if ( !v3 )
  {
    v9 = *v1;
    v10 = v1[1];
    v11 = "Failed to get virtual core data for type=%d idx=%d";
    v12 = 390;
    goto LABEL_9;
  }
  v4 = cam_cpas_unregister_client(v3[1217]);
  if ( v4 )
  {
    v5 = "CPAS unregister failed";
    v6 = v4;
    v7 = 396;
LABEL_12:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_virtual_cdm_remove",
      v7,
      v5);
    return v6;
  }
  v13 = ((__int64 (__fastcall *)(unsigned int *, _QWORD, _QWORD, _QWORD))cam_cdm_intf_deregister_hw_cdm)(
          v1,
          v2[424],
          0,
          *v3);
  if ( v13 )
  {
    v5 = "Virtual CDM Interface de-registration failed";
    v6 = v13;
    v7 = 405;
    goto LABEL_12;
  }
  _flush_workqueue(*((_QWORD *)v3 + 22));
  destroy_workqueue(*((_QWORD *)v3 + 22));
  v14 = (_QWORD *)v2[424];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v14, 0);
  else
    kvfree(v14);
  v15 = (_QWORD *)v2[460];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v15, 0);
  else
    kvfree(v15);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v2, 0);
  else
    kvfree(v2);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v1, 0);
  else
    kvfree(v1);
  return 0;
}
