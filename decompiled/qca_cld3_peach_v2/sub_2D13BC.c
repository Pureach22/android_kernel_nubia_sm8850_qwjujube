__int64 sub_2D13BC()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D8390);
  return wlan_mlme_get_tx_retry_multiplier();
}
