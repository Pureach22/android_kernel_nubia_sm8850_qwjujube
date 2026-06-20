__int64 sub_2A32F8()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2AA2CC);
  return ucfg_policy_mgr_get_chnl_select_plcy();
}
