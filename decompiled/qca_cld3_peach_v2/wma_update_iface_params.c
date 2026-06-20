__int64 __fastcall wma_update_iface_params(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v11; // w1
  __int64 v13; // x21
  __int64 v14; // x0
  void *v15; // x0
  int v16; // w8

  v11 = *(unsigned __int8 *)(a2 + 167);
  v13 = *(_QWORD *)(a1 + 520) + 488LL * (unsigned __int8)v11;
  wma_set_bss_rate_flags(a1, v11, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  v14 = *(_QWORD *)(v13 + 200);
  if ( v14 )
    _qdf_mem_free(v14);
  v15 = (void *)_qdf_mem_malloc(0x338u, "wma_update_iface_params", 4750);
  *(_QWORD *)(v13 + 200) = v15;
  if ( !v15 )
    return 1;
  memcpy(v15, (const void *)(a2 + 24), 0x338u);
  v16 = *(unsigned __int8 *)(a2 + 18);
  *(_BYTE *)(v13 + 210) = v16;
  if ( v16 )
    wma_set_peer_pmf_status(a1, a2);
  *(_WORD *)(v13 + 174) = *(_WORD *)(a2 + 14);
  *(_BYTE *)(v13 + 176) = *(_BYTE *)(a2 + 13);
  *(_BYTE *)(v13 + 177) = *(_BYTE *)(a2 + 12);
  *(_DWORD *)(v13 + 240) = *(_DWORD *)(a2 + 8);
  *(_WORD *)(v13 + 480) = *(_WORD *)(a2 + 866);
  return 0;
}
