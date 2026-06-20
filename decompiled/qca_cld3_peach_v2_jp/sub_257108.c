__int64 sub_257108()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x25E0DC);
  return policy_mgr_get_chnl_select_plcy();
}
