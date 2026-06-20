bool __fastcall wlan_is_rso_enabled(__int64 a1, __int64 a2)
{
  int roam_state; // w0

  roam_state = mlme_get_roam_state(*(_QWORD *)(a1 + 80), a2);
  return (roam_state & 0xFFFFFFFB) == 2 || (roam_state & 0xFFFFFFFE) == 4;
}
