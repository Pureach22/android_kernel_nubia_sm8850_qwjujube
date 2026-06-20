__int64 sub_2A3F08()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2AAEDC);
  return ucfg_mlme_get_scan_11d_interval();
}
