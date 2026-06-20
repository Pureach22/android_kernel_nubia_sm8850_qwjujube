__int64 __fastcall dp_get_info_by_peer_mac(__int64 a1, unsigned __int16 *a2, unsigned int a3, __int64 a4)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x8
  _DWORD *v18; // x8

  *(_BYTE *)a4 = a3;
  *(_WORD *)(a4 + 2) = -1;
  result = dp_peer_find_hash_find(a1, a2, 0, a3, 7u);
  if ( result )
    goto LABEL_13;
  v18 = *(_DWORD **)(a1 + 1536);
  if ( v18 )
  {
    if ( *(v18 - 1) != 69695039 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, unsigned __int16 *, _QWORD, __int64, _QWORD))v18)(a1, a2, 0, 7, a3);
    if ( result )
    {
LABEL_13:
      if ( *(_DWORD *)(result + 408) != 1 || (v17 = *(_QWORD *)(result + 416)) == 0 )
        v17 = result;
      *(_DWORD *)(a4 + 4) = *(_DWORD *)(v17 + 124);
      *(_WORD *)(a4 + 2) = *(_WORD *)(v17 + 16);
      return dp_peer_unref_delete(result, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
    }
  }
  return result;
}
