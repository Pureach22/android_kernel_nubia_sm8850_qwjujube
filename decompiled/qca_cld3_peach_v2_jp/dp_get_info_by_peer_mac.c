__int64 __fastcall dp_get_info_by_peer_mac(__int64 a1, unsigned __int16 *a2, unsigned __int8 a3, __int64 a4)
{
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7

  *(_BYTE *)a4 = a3;
  *(_WORD *)(a4 + 2) = -1;
  result = dp_peer_find_hash_find(a1, a2, 0, a3, 7u);
  if ( result )
  {
    *(_DWORD *)(a4 + 4) = *(_DWORD *)(result + 124);
    *(_WORD *)(a4 + 2) = *(_WORD *)(result + 16);
    return dp_peer_unref_delete(result, 7u, v6, v7, v8, v9, v10, v11, v12, v13);
  }
  return result;
}
