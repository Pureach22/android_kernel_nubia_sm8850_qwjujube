__int64 __fastcall hif_clear_ce_desc_debug_data(int a1)
{
  return qdf_mem_set(a1, 0x38u, 0);
}
