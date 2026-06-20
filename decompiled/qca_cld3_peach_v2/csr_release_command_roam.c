void *__fastcall csr_release_command_roam(__int64 a1, __int64 a2)
{
  return qdf_mem_set((void *)(a2 + 32), 0x14u, 0);
}
