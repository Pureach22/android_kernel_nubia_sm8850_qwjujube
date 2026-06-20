void *__fastcall dp_rx_desc_pool_free(
        void *result,
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
  if ( *(_QWORD *)(a2 + 24) )
    return dp_desc_multi_pages_mem_free(
             (__int64)result,
             *(_DWORD *)(a2 + 104),
             (_BYTE *)(a2 + 8),
             0,
             1,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10);
  return result;
}
