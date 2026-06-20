void *__fastcall dp_mon_reap_timer_init(__int64 a1)
{
  __int64 v1; // x19
  void *result; // x0

  v1 = *(_QWORD *)(a1 + 20112);
  *(_QWORD *)(v1 + 304) = dp_mon_reap_timer_handler;
  *(_QWORD *)(v1 + 312) = a1;
  *(_DWORD *)(v1 + 328) = 0;
  *(_QWORD *)(v1 + 336) = 0;
  init_timer_key(v1 + 264, _os_timer_shim_15, 0, 0, 0);
  result = qdf_mem_set((void *)(v1 + 344), 8u, 0);
  *(_BYTE *)(v1 + 320) = 1;
  return result;
}
