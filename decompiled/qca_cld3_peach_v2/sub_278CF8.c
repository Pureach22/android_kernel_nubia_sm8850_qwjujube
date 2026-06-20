__int64 sub_278CF8()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x27FCCC);
  return policy_mgr_get_chnl_select_plcy();
}
