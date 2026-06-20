__int64 __fastcall extract_get_rxpn_data_tlv(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 v3; // x20
  int v5; // w8
  const void *v6; // x1

  v3 = *a2;
  v5 = *(_DWORD *)(*a2 + 4);
  v6 = (const void *)(*a2 + 24);
  *(_DWORD *)a3 = v5;
  *(_WORD *)(a3 + 10) = *(_DWORD *)(v3 + 20);
  qdf_mem_copy((void *)(a3 + 12), v6, 8u);
  *(_WORD *)(a3 + 4) = *(_DWORD *)(v3 + 8);
  *(_BYTE *)(a3 + 6) = *(_WORD *)(v3 + 10);
  *(_BYTE *)(a3 + 7) = *(_BYTE *)(v3 + 11);
  *(_WORD *)(a3 + 8) = *(_DWORD *)(v3 + 12);
  return 0;
}
