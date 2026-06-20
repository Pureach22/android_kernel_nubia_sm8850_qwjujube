__int64 sub_428B08()
{
  __asm { LDTR            H20, [X28,#0x8E] }
  return wlansap_get_safe_channel_from_pcl_for_sap();
}
