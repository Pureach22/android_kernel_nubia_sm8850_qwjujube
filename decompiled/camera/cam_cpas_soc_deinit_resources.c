__int64 __fastcall cam_cpas_soc_deinit_resources(__int64 a1)
{
  __int64 v1; // x21
  unsigned int v3; // w20
  __int64 v4; // x1
  int v5; // w0
  _QWORD *v6; // x0
  _QWORD *v7; // x0
  unsigned int v8; // w20
  _QWORD *v9; // x0
  _QWORD *v10; // x0
  _QWORD *v11; // x0
  _QWORD *v12; // x0

  v1 = *(_QWORD *)(a1 + 3296);
  if ( *(_DWORD *)(v1 + 1592) )
  {
    v3 = 0;
    do
      llcc_slice_putd(*(_QWORD *)(*(_QWORD *)(v1 + 1600) + ((__int64)(int)v3++ << 6) + 40));
    while ( v3 < *(_DWORD *)(v1 + 1592) );
  }
  v4 = *(unsigned int *)(v1 + 1624);
  if ( (_DWORD)v4 != -1 )
  {
    v5 = cam_soc_util_put_optional_clk(a1, v4);
    if ( v5 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_soc_deinit_resources",
        2002,
        "Error Put optional clk failed rc=%d",
        v5);
  }
  v6 = *(_QWORD **)(v1 + 1632);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v6, 0);
  else
    kvfree(v6);
  v7 = *(_QWORD **)(v1 + 1648);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v7, 0);
  else
    kvfree(v7);
  v8 = cam_soc_util_release_platform_resource(a1);
  if ( v8 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_soc_deinit_resources",
      2011,
      "release platform failed, rc=%d",
      v8);
  v9 = *(_QWORD **)(v1 + 1656);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v9, 0);
  else
    kvfree(v9);
  v10 = *(_QWORD **)(v1 + 1600);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v10, 0);
  else
    kvfree(v10);
  v11 = *(_QWORD **)(v1 + 1616);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v11, 0);
  else
    kvfree(v11);
  v12 = *(_QWORD **)(a1 + 3296);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v12, 0);
  else
    kvfree(v12);
  *(_QWORD *)(a1 + 3296) = 0;
  return v8;
}
