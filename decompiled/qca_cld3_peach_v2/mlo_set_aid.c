__int64 __fastcall mlo_set_aid(__int64 a1, unsigned int a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v4; // x0

  v2 = *(_QWORD *)(a1 + 1360);
  if ( v2 && (v3 = *(_QWORD *)(v2 + 2232)) != 0 && (v4 = *(_QWORD *)(v3 + 8)) != 0 )
    return wlan_mlo_peer_set_aid(v4, 1, 255, a2);
  else
    return 16;
}
