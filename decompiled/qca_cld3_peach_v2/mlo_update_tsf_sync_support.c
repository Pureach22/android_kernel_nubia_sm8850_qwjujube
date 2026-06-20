__int64 __fastcall mlo_update_tsf_sync_support(__int64 a1, char a2)
{
  __int64 result; // x0

  result = wlan_objmgr_get_mlo_ctx();
  *(_BYTE *)(result + 348) = a2;
  return result;
}
