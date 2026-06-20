__int64 __fastcall populate_dot11f_bcn_prot_extcaps(__int64 a1, __int64 a2, _BYTE *a3)
{
  if ( *(_DWORD *)(a2 + 7036) == 1
    && (wlan_mlme_is_bcn_prot_disabled_for_sap(*(_QWORD *)(a1 + 21624)) & 1) != 0
    && !wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 284))
    && *(unsigned __int8 *)(a2 + 154) <= 0xBu
    && *a3
    && (a3[12] & 0x10) != 0 )
  {
    a3[12] &= ~0x10u;
    a3[1] = lim_compute_ext_cap_ie_length(a3);
  }
  return 0;
}
