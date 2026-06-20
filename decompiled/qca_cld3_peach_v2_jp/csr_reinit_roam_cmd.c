void *__fastcall csr_reinit_roam_cmd(__int64 a1, __int64 a2)
{
  return qdf_mem_set((void *)(a2 + 32), 0x14u, 0);
}
