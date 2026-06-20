__int64 sub_2D3D2C()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2DAD00);
  return ucfg_mlme_get_sta_keep_alive_period();
}
