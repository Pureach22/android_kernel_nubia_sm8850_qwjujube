__int64 __fastcall dp_mon_peer_get_peerstats_ctx(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 8);
  if ( v1 )
    return *(_QWORD *)(v1 + 8);
  else
    return 0;
}
