__int64 __fastcall _qdf_wake_lock_create(_QWORD *a1, __int64 a2)
{
  const void *v4; // x1

  qdf_mem_set((int)a1, 0xC8u, 0);
  qdf_trace_msg(56, 8, "%s enter", "__qdf_wake_lock_create");
  a1[24] = wakeup_source_register(a1[22], a2);
  qdf_trace_msg(56, 8, "%s exit", "__qdf_wake_lock_create");
  v4 = (const void *)a1[24];
  if ( !v4 )
    return 16;
  memcpy(a1, v4, 0xC0u);
  return 0;
}
