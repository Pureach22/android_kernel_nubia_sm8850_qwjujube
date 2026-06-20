__int64 __fastcall sys_init_globals(__int64 a1)
{
  qdf_mem_set((void *)(a1 + 12536), 0x128u, 0);
  *(_DWORD *)(a1 + 12808) = 0;
  return 0;
}
