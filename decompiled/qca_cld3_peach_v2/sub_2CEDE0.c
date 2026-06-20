__int64 sub_2CEDE0()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D5DB4);
  return wlan_mlme_get_self_gen_frm_pwr();
}
