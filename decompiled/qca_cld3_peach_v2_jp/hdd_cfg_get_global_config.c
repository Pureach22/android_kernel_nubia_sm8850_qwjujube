__int64 __fastcall hdd_cfg_get_global_config(__int64 *a1, char *a2, int a3)
{
  ucfg_cfg_store_print(*a1);
  return snprintf(a2, a3, "WLAN configuration written to debug log");
}
