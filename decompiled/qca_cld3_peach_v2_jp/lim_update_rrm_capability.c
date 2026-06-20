void *__fastcall lim_update_rrm_capability(_BYTE *a1)
{
  a1[20136] = a1[17408];
  return qdf_mem_copy(a1 + 20148, a1 + 17411, 5u);
}
