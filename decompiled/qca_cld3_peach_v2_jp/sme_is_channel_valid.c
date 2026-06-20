__int64 __fastcall sme_is_channel_valid(__int64 a1, unsigned int a2)
{
  char v4; // w20

  if ( (unsigned int)qdf_mutex_acquire(a1 + 12776) )
  {
    v4 = 0;
  }
  else
  {
    v4 = ((__int64 (__fastcall *)(__int64, _QWORD))wlan_roam_is_channel_valid)(*(_QWORD *)(a1 + 8) + 5756LL, a2);
    qdf_mutex_release(a1 + 12776);
  }
  return v4 & 1;
}
