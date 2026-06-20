_QWORD *__fastcall cam_sensor_shutdown(_QWORD *result)
{
  __int64 v1; // x20
  _QWORD *v2; // x19
  __int64 v3; // x0
  int v4; // w0
  int v5; // w9
  _QWORD *v6; // x0
  _QWORD *v7; // x0

  v1 = result[457];
  v2 = result;
  if ( *((_DWORD *)result + 1636) || *((_BYTE *)result + 6548) )
  {
    if ( *((_DWORD *)result + 1802) == 1 )
    {
      *((_DWORD *)result + 1802) = -1;
      if ( (delete_request(result + 899) & 0x80000000) != 0 )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          32,
          1,
          "cam_sensor_release_stream_rsc",
          131,
          "failed while deleting Streamoff settings");
    }
    if ( *((_DWORD *)v2 + 1790) == 1 )
    {
      *((_DWORD *)v2 + 1790) = -1;
      if ( (delete_request(v2 + 893) & 0x80000000) != 0 )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          32,
          1,
          "cam_sensor_release_stream_rsc",
          140,
          "failed while deleting Streamon settings");
    }
    cam_sensor_release_per_frame_resource(v2);
    if ( *((_DWORD *)v2 + 1636) )
      cam_sensor_power_down(v2);
    v3 = *((unsigned int *)v2 + 1864);
    if ( (_DWORD)v3 != -1 )
    {
      v4 = cam_destroy_device_hdl(v3);
      if ( v4 < 0 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          32,
          1,
          "cam_sensor_shutdown",
          1203,
          "dhdl already destroyed: rc = %d",
          v4);
    }
    v2[932] = -1;
    v5 = (unsigned __int8)mem_trace_en;
    *((_DWORD *)v2 + 1866) = -1;
    v6 = *(_QWORD **)(v1 + 120);
    if ( v5 == 1 )
      cam_mem_trace_free(v6, 0);
    else
      kvfree(v6);
    v7 = *(_QWORD **)(v1 + 136);
    if ( mem_trace_en == 1 )
      result = cam_mem_trace_free(v7, 0);
    else
      result = (_QWORD *)kvfree(v7);
    *(_QWORD *)(v1 + 120) = 0;
    *(_QWORD *)(v1 + 136) = 0;
    *(_WORD *)(v1 + 128) = 0;
    *(_WORD *)(v1 + 144) = 0;
    v2[942] = 0;
    *((_BYTE *)v2 + 6548) = 0;
    *((_DWORD *)v2 + 1888) = 0;
    *((_DWORD *)v2 + 1636) = 0;
  }
  return result;
}
