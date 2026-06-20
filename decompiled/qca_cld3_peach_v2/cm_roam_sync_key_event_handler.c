__int64 __fastcall cm_roam_sync_key_event_handler(__int64 a1, unsigned __int8 *a2, unsigned __int8 a3)
{
  return wlan_crypto_key_event_handler(a1, a2, a3);
}
