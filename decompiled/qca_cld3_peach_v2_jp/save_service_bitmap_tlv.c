__int64 __fastcall save_service_bitmap_tlv(__int64 a1, __int64 a2, void *a3)
{
  __int64 v3; // x21
  void *v6; // x0

  v3 = *(_QWORD *)(a1 + 760);
  v6 = *(void **)(v3 + 6336);
  if ( !v6 )
  {
    v6 = (void *)_qdf_mem_malloc(0x80u, "save_service_bitmap_tlv", 13551);
    *(_QWORD *)(v3 + 6336) = v6;
    if ( !v6 )
      return 2;
  }
  qdf_mem_copy(v6, *(const void **)(a2 + 32), 0x80u);
  if ( a3 )
    qdf_mem_copy(a3, *(const void **)(a2 + 32), 0x80u);
  return 0;
}
