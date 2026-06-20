__int64 __fastcall mlo_t2lm_ctx_init(__int64 a1, __int64 a2)
{
  __int64 v2; // x21

  v2 = a1 + 2240;
  qdf_mem_set((void *)(a1 + 2240), 0x350u, 0);
  *(_DWORD *)(a1 + 2244) = 2;
  *(_BYTE *)(a1 + 2248) = 1;
  *(_BYTE *)(a1 + 2293) = 0;
  *(_QWORD *)(a1 + 3080) = a1;
  *(_QWORD *)(a1 + 2520) = v2;
  return wlan_mlo_t2lm_timer_init(a2);
}
