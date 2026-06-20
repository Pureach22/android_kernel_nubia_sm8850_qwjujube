__int64 sub_2D5C34()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2DCC08);
  return ucfg_mlme_get_scan_11d_interval();
}
