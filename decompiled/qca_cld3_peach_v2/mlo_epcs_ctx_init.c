__int64 __fastcall mlo_epcs_ctx_init(__int64 a1)
{
  qdf_mem_set((void *)(a1 + 3088), 0x120u, 0);
  return qdf_mutex_create(a1 + 3088);
}
