bool __fastcall util_scan_entry_single_pmk(__int64 a1, __int64 a2)
{
  return *(_QWORD *)(a2 + 1656) && (wlan_mlme_is_sae_single_pmk_enabled() & 1) != 0;
}
