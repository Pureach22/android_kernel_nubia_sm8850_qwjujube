void *__fastcall enh_prepare_cfr_header_txstatus(_DWORD *a1, __int64 a2, int a3)
{
  target_if_cfr_fill_header(a2, 0, a3, 0);
  *(_BYTE *)(a2 + 24) = 0;
  *(_DWORD *)(a2 + 46) = 0;
  *(_DWORD *)(a2 + 124) = a1[27];
  *(_DWORD *)(a2 + 136) = a1[30];
  return qdf_mem_copy((void *)(a2 + 52), a1 + 2, 6u);
}
