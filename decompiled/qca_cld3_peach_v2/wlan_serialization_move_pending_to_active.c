__int64 __fastcall wlan_serialization_move_pending_to_active(int a1, __int64 a2, __int64 a3, char a4)
{
  if ( a1 )
    return wlan_ser_move_non_scan_pending_to_active(a2, a3, a4 & 1);
  else
    return wlan_ser_move_scan_pending_to_active(a2);
}
