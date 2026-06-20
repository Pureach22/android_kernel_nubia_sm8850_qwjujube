__int64 __fastcall dp_peer_delete(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  if ( (*(_BYTE *)(a2 + 120) & 4) != 0 )
    return dp_peer_delete_wifi3(
             result,
             *(unsigned __int8 *)(*(_QWORD *)(a2 + 24) + 59LL),
             a2 + 44,
             a4,
             *(unsigned int *)(a2 + 408));
  return result;
}
