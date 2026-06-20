void *__fastcall dot11f_unpack_ff_transaction_id(int a1, const void *a2, void *a3)
{
  return qdf_mem_copy(a3, a2, 2u);
}
