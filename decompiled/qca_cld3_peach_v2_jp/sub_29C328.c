__int64 __fastcall sub_29C328(__int64 a1, __int64 a2)
{
  char v2; // w25

  if ( (v2 & 0x40) != 0 )
    JUMPOUT(0x2A32FC);
  return wlan_mlme_cfg_get_vht_rx_mcs_map(a1, a2);
}
