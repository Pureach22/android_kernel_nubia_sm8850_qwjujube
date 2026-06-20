__int64 sub_6B9F58()
{
  __asm { FMLSL           V8.2S, V30.2H, V12.H[4] }
  return wlan_mlo_peer_get_links_info();
}
