__int64 __fastcall ucfg_pmo_is_ap_mode_supports_arp_ns(__int64 a1, int a2)
{
  return pmo_core_is_ap_mode_supports_arp_ns(a1, a2) & 1;
}
