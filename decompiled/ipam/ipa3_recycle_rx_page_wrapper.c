__int64 __fastcall ipa3_recycle_rx_page_wrapper(__int64 result)
{
  if ( (*(_BYTE *)(result + 32) & 1) != 0 )
    return kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29448), result);
  return result;
}
