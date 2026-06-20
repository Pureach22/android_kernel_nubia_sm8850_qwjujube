__int64 sub_2A2148()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A911C);
  return ucfg_mlme_get_fine_time_meas_cap();
}
