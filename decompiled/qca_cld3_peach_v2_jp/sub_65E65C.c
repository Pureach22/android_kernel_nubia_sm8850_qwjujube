__int64 sub_65E65C()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x665630);
  return ucfg_fwol_get_tsf_ptp_options();
}
