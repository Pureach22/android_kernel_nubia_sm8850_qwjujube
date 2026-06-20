void *__fastcall hdd_cm_clear_conn_info_mld_addr(__int64 a1)
{
  return qdf_mem_set((void *)(a1 + 900), 6u, 0);
}
