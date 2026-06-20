__int64 sub_714F34()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x71BF08);
  return ucfg_fwol_get_tsf_ptp_options();
}
