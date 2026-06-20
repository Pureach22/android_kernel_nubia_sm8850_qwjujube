__int64 __fastcall sub_6BB030(__int64 a1, __int64 a2)
{
  __int64 v2; // x10

  if ( v2 )
    JUMPOUT(0x5D717C);
  return wlan_mlo_get_mlpeer_by_peer_mladdr(a1, a2);
}
