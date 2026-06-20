__int64 __fastcall wlan_sr_register_callback(__int64 result, void *a2)
{
  if ( result )
    sr_cb = a2;
  return result;
}
