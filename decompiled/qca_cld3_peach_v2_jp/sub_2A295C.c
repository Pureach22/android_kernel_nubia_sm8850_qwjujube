__int64 sub_2A295C()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A9930);
  return ucfg_mlme_get_pmkid_modes();
}
