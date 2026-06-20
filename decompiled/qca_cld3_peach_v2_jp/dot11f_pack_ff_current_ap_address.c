void *__fastcall dot11f_pack_ff_current_ap_address(int a1, const void *a2, void *a3)
{
  return qdf_mem_copy(a3, a2, 6u);
}
