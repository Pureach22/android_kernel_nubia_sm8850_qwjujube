void *__fastcall wlan_hdd_reset_bcn_rssi_history_stats(__int64 a1)
{
  return qdf_mem_set((void *)(a1 + 4288), 0x50u, 0);
}
