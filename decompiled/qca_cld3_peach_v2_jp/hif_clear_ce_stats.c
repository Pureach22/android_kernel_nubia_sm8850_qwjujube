__int64 __fastcall hif_clear_ce_stats(int a1)
{
  return qdf_mem_set(a1 + 29160, 0x600u, 0);
}
