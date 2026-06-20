__int64 __fastcall dp_peer_delete(__int64 result, __int64 a2)
{
  if ( (*(_BYTE *)(a2 + 120) & 4) != 0 )
    return dp_peer_delete_wifi3(result, *(unsigned __int8 *)(*(_QWORD *)(a2 + 24) + 59LL), (int)a2 + 44);
  return result;
}
