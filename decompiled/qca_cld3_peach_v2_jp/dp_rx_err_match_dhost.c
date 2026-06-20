bool __fastcall dp_rx_err_match_dhost(const void *a1, __int64 a2)
{
  return (unsigned int)qdf_mem_cmp(a1, (const void *)(a2 + 96), 6u) == 0;
}
