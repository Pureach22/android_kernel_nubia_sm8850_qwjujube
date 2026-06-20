void *__fastcall sir_copy_assoc_rsp_partner_info_to_session(__int64 a1, _BYTE *a2)
{
  void *result; // x0

  result = qdf_mem_set((void *)(a1 + 10696), 0xB0u, 0);
  if ( *a2 )
    return qdf_mem_copy((void *)(a1 + 10696), a2, 0xB0u);
  return result;
}
