void *__fastcall hal_rx_priv_info_set_in_tlv_peach(__int64 a1, const void *a2, size_t a3)
{
  void *v3; // x0

  v3 = (void *)(a1 + 8);
  if ( (unsigned int)a3 >= 4 )
    a3 = 4;
  else
    a3 = (unsigned int)a3;
  return qdf_mem_copy(v3, a2, a3);
}
