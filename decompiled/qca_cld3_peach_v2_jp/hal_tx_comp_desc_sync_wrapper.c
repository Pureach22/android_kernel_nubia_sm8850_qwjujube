void *__fastcall hal_tx_comp_desc_sync_wrapper(const void *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, char a6)
{
  unsigned int v6; // w8

  if ( (a6 & 1) != 0 )
    v6 = 32;
  else
    v6 = 12;
  return qdf_mem_copy((void *)(a3 + 104), a1, v6);
}
