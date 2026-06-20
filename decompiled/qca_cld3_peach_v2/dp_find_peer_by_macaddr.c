__int64 __fastcall dp_find_peer_by_macaddr(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  __int64 result; // x0
  _DWORD *v9; // x8

  result = dp_peer_find_hash_find(a1, a2);
  if ( !result )
  {
    v9 = *(_DWORD **)(a1 + 1536);
    if ( v9 )
    {
      if ( *(v9 - 1) != 69695039 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD))v9)(a1, a2, 0, a4, a3);
    }
    else
    {
      return 0;
    }
  }
  return result;
}
