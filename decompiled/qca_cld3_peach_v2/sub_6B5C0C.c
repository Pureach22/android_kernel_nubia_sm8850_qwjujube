__int64 sub_6B5C0C()
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return wlan_mlo_get_sta_mld_ctx_count();
}
