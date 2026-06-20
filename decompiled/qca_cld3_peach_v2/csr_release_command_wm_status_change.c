void *__fastcall csr_release_command_wm_status_change(__int64 a1, __int64 a2)
{
  return qdf_mem_set((void *)(a2 + 32), 0x2Cu, 0);
}
