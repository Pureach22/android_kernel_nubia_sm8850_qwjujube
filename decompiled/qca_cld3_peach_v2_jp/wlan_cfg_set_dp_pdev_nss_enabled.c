__int64 __fastcall wlan_cfg_set_dp_pdev_nss_enabled(__int64 result, int a2)
{
  *(_DWORD *)(result + 28) = a2;
  return result;
}
