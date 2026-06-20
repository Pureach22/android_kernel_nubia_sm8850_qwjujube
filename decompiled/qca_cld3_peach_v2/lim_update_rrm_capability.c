void *__fastcall lim_update_rrm_capability(_BYTE *a1)
{
  a1[20208] = a1[17480];
  return qdf_mem_copy(a1 + 20220, a1 + 17483, 5u);
}
