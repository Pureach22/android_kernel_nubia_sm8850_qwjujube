__int64 __fastcall free_rx_pkt(__int64 a1, __int64 a2)
{
  void (__fastcall *v4)(_QWORD); // x8
  __int64 v5; // x0

  dma_unmap_page_attrs(*(_QWORD *)(ipa3_ctx + 34216), *(_QWORD *)(a2 + 24), *(unsigned int *)(a1 + 160), 2, 0);
  v4 = *(void (__fastcall **)(_QWORD))(a1 + 144);
  v5 = *(_QWORD *)(a2 + 16);
  if ( *((_DWORD *)v4 - 1) != 303786302 )
    __break(0x8228u);
  v4(v5);
  return kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29448), a2);
}
