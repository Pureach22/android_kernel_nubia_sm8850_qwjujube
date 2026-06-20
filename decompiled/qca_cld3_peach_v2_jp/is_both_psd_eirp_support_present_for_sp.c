bool __fastcall is_both_psd_eirp_support_present_for_sp(__int64 a1, _BYTE *a2)
{
  return (is_service_enabled_tlv(a1, 393) & 1) != 0 && (a2[4] == 1 || a2[405] == 1) && a2[6] && a2[7] != 0;
}
