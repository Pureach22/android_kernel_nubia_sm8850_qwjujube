__int64 mlo_get_tsf_sync_support()
{
  return *(unsigned __int8 *)(wlan_objmgr_get_mlo_ctx() + 348);
}
