bool __fastcall dp_rx_err_match_dhost(const void *a1, __int64 a2, char a3)
{
  const void *v4; // x20
  int v5; // w8

  if ( (a3 & 1) != 0 && (v4 = a1, v5 = qdf_mem_cmp(a1, (const void *)(a2 + 104), 6u), a1 = v4, !v5) )
    return 1;
  else
    return (unsigned int)qdf_mem_cmp(a1, (const void *)(a2 + 96), 6u) == 0;
}
