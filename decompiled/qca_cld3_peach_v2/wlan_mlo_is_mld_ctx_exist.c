bool __fastcall wlan_mlo_is_mld_ctx_exist(const void *a1)
{
  return wlan_mlo_get_mld_ctx_by_mldaddr(a1) != nullptr;
}
