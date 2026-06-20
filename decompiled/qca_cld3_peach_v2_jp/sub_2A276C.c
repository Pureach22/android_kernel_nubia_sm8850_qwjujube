__int64 sub_2A276C()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A9740);
  return ucfg_mlme_get_sap_tx_leakage_threshold();
}
