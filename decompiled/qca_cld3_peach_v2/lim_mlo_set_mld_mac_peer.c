void *__fastcall lim_mlo_set_mld_mac_peer(__int64 a1, const void *a2)
{
  return qdf_mem_copy((void *)(a1 + 1080), a2, 6u);
}
