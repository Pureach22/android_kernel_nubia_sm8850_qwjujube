__int64 __fastcall wlan_unregister_t2lm_link_update_notify_handler(__int64 result, unsigned __int8 a2)
{
  if ( a2 <= 0x31u )
  {
    *(_QWORD *)(result + 8LL * a2 + 2600) = 0;
    *(_BYTE *)(result + a2 + 3000) = 0;
  }
  return result;
}
