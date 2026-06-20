void *__fastcall _qdf_nbuf_dma_map_info(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x8
  size_t v5; // x2
  void *result; // x0
  __int64 v7; // x21

  v2 = *(unsigned int *)(a1 + 4);
  v5 = 16 * v2;
  if ( (unsigned int)v2 >= 2 && (_qdf_nbuf_dma_map_info___already_done & 1) == 0 )
  {
    _qdf_nbuf_dma_map_info___already_done = 1;
    v7 = 16 * v2;
    _warn_printk(
      "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
      v5,
      "field \"sg->dma_segs\" at ../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/qdf/linux/src/qdf_nbuf.c:5692",
      0x10u);
    v5 = v7;
    __break(0x800u);
  }
  result = memcpy(a2 + 2, (const void *)(a1 + 16), v5);
  *a2 = *(_DWORD *)(a1 + 4);
  return result;
}
