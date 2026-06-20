__int64 sub_2D4498()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    return p2p_send_tx_conf();
  else
    return ucfg_mlme_get_sap_tx_leakage_threshold();
}
