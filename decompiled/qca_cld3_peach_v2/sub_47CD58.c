__int64 sub_47CD58()
{
  __asm { LDTR            H20, [X28,#0x8E] }
  return wlan_sap_get_vht_ch_width();
}
