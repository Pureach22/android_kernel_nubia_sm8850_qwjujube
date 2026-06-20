void *__fastcall hdd_conn_remove_connect_info(__int64 a1)
{
  void *result; // x0

  qdf_mem_set((void *)(a1 + 228), 6u, 0);
  qdf_mem_set((void *)(a1 + 276), 6u, 0);
  hdd_cm_clear_conn_info_mld_addr(a1);
  *(_QWORD *)(a1 + 596) = 1;
  *(_BYTE *)(a1 + 612) = 0;
  result = qdf_mem_set((void *)(a1 + 236), 0x28u, 0);
  *(_WORD *)(a1 + 613) = 0;
  return result;
}
