__int64 __fastcall sub_4E284C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned __int64 a5)
{
  return dp_get_peer_vdev_roaming_in_progress(a1, a2, a3, (a5 >> 50) & 0x7F);
}
