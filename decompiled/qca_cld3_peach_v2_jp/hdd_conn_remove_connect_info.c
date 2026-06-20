void *__fastcall hdd_conn_remove_connect_info(__int64 a1)
{
  void *result; // x0

  qdf_mem_set((void *)(a1 + 220), 6u, 0);
  qdf_mem_set((void *)(a1 + 268), 6u, 0);
  *(_QWORD *)(a1 + 588) = 1;
  *(_BYTE *)(a1 + 604) = 0;
  result = qdf_mem_set((void *)(a1 + 228), 0x28u, 0);
  *(_WORD *)(a1 + 605) = 0;
  return result;
}
