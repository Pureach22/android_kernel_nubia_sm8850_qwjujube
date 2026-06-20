__int64 __fastcall ucfg_dlm_update_bssid_connect_params(__int64 a1, __int64 a2, unsigned int a3)
{
  return dlm_update_bssid_connect_params(a1, a2 & 0xFFFFFFFFFFFFLL, a3);
}
