__int64 sub_274D9C()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x27BD70);
  return ucfg_policy_mgr_get_chnl_select_plcy();
}
