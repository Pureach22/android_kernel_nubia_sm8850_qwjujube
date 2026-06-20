__int64 __fastcall sub_1F074(__int64 a1, __int64 a2)
{
  __int64 v2; // x26
  __int64 v3; // d24

  *(_QWORD *)(v2 + 9504) = v3;
  return wlfw_wlan_mode_send_sync_msg(a1, a2);
}
