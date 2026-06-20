bool __fastcall wlan_is_roaming_enabled(__int64 a1, __int64 a2)
{
  return (unsigned int)mlme_get_roam_state(*(_QWORD *)(a1 + 80), a2) != 0;
}
