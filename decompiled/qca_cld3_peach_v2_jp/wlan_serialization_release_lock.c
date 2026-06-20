__int64 __fastcall wlan_serialization_release_lock(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 8);
  if ( (v1 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 8) = v1 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1);
  }
  else
  {
    raw_spin_unlock(a1);
  }
  return 0;
}
