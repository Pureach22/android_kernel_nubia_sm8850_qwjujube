void *__fastcall hal_rx_priv_info_get_from_tlv_peach(__int64 a1, void *a2, size_t a3)
{
  if ( (unsigned int)a3 >= 4 )
    a3 = 4;
  else
    a3 = (unsigned int)a3;
  return qdf_mem_copy(a2, (const void *)(a1 + 8), a3);
}
