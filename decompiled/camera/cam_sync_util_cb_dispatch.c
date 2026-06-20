_QWORD *__fastcall cam_sync_util_cb_dispatch(__int64 a1)
{
  __int64 v1; // x19
  const void *v2; // x20
  __int64 v3; // x0
  __int64 v4; // x1
  __int64 v5; // x2

  v1 = a1 - 32;
  v2 = *(const void **)(a1 - 32);
  cam_common_util_thread_switch_delay_detect("cam_sync_workq", "schedule", v2, *(_QWORD *)(a1 - 8), 5u);
  v4 = *(unsigned int *)(v1 + 16);
  v3 = *(unsigned int *)(v1 + 20);
  v5 = *(_QWORD *)(v1 + 8);
  if ( *((_DWORD *)v2 - 1) != 1136383842 )
    __break(0x8234u);
  ((void (__fastcall *)(__int64, __int64, __int64))v2)(v3, v4, v5);
  if ( mem_trace_en == 1 )
    return cam_mem_trace_free((_QWORD *)v1, 0);
  else
    return (_QWORD *)kvfree(v1);
}
