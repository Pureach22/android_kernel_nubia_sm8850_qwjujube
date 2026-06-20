__int64 sub_2D3E18()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2DADEC);
  return ucfg_mlme_get_fine_time_meas_cap();
}
