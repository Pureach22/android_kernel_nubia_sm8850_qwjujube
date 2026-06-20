void *__fastcall hdd_apf_context_destroy(__int64 a1, __int64 a2)
{
  qdf_event_destroy(a1 + 52224, a2);
  return qdf_mem_set((void *)(a1 + 52216), 0x58u, 0);
}
