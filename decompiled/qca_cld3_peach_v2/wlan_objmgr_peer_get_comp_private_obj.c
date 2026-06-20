__int64 __fastcall wlan_objmgr_peer_get_comp_private_obj(__int64 a1, unsigned int a2)
{
  __int64 result; // x0

  result = 0;
  if ( a1 )
  {
    if ( a2 <= 0x35 )
      return *(_QWORD *)(a1 + 8LL * a2 + 112);
  }
  return result;
}
