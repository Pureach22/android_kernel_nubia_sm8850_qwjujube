__int64 __fastcall dp_tx_update_peer_basic_stats(__int64 result, unsigned int a2, char a3)
{
  __int64 v3; // x9

  if ( result )
  {
    v3 = *(_QWORD *)(result + 24) + a2;
    ++*(_QWORD *)(result + 16);
    *(_QWORD *)(result + 24) = v3;
    if ( a3 )
      ++*(_DWORD *)(result + 12);
  }
  return result;
}
