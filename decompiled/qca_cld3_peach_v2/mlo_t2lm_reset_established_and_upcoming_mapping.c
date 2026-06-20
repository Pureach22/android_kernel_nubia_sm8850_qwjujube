void *__fastcall mlo_t2lm_reset_established_and_upcoming_mapping(__int64 a1)
{
  qdf_mem_set((void *)(a1 + 2240), 0x38u, 0);
  *(_DWORD *)(a1 + 2244) = 2;
  *(_BYTE *)(a1 + 2248) = 1;
  return qdf_mem_set((void *)(a1 + 2296), 0x38u, 0);
}
