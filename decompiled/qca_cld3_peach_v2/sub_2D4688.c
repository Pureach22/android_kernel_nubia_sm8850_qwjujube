__int64 sub_2D4688()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2DB65C);
  return ucfg_mlme_get_pmkid_modes();
}
