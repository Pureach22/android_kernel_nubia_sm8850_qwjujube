__int64 sub_481878()
{
  __asm { LDTR            H20, [X28,#0x8E] }
  return wlansap_get_safe_channel_from_pcl_for_sap();
}
