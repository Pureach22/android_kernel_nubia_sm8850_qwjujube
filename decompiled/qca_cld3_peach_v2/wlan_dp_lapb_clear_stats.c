void *__fastcall wlan_dp_lapb_clear_stats(__int64 a1)
{
  return qdf_mem_set((void *)(a1 + 19960), 0, 12);
}
