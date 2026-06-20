__int64 sub_29FA74()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A6A48);
  return wlan_mlme_get_tx_retry_multiplier();
}
