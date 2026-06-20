__int64 __fastcall dp_get_peer_stats(__int64 a1, __int64 a2)
{
  _DWORD *v4; // x8
  __int64 result; // x0
  __int64 v6; // x8
  __int64 v7; // x9
  unsigned int v8; // w8
  __int64 *v9; // x8
  __int64 v10; // x8
  __int64 v11; // x11
  int v12; // w10
  int v13; // w9
  __int64 v14; // x10

  if ( *(_DWORD *)(a1 + 408) == 1 && (v4 = *(_DWORD **)(a1 + 416)) != nullptr || (v4 = (_DWORD *)a1) != nullptr )
  {
    *(_DWORD *)(a2 + 160) = v4[42];
    *(_DWORD *)(a2 + 192) = v4[43];
    *(_DWORD *)(a2 + 196) = v4[44];
    *(_DWORD *)(a2 + 200) = v4[45];
    *(_DWORD *)(a2 + 204) = v4[46];
    *(_DWORD *)(a2 + 208) = v4[47];
    *(_DWORD *)(a2 + 212) = v4[48];
    *(_DWORD *)(a2 + 916) = v4[49];
    *(_DWORD *)(a2 + 4064) = v4[50];
    *(_DWORD *)(a2 + 4068) = v4[51];
    *(_DWORD *)(a2 + 4072) = v4[52];
    *(_DWORD *)(a2 + 4076) = v4[53];
  }
  dp_get_peer_per_pkt_stats(a1);
  result = dp_get_peer_extd_stats(a1);
  v6 = *(unsigned int *)(a2 + 124);
  v7 = *(_QWORD *)(a2 + 88) + v6;
  if ( v7 )
    v8 = 100 * (int)v6 / (unsigned int)v7;
  else
    v8 = 0;
  *(_DWORD *)(a2 + 2076) = v8;
  if ( *(_DWORD *)(a1 + 408) != 1 || (v9 = *(__int64 **)(a1 + 416)) == nullptr )
    v9 = (__int64 *)a1;
  v10 = *v9;
  if ( v10 )
  {
    v11 = *(_QWORD *)(a2 + 16);
    v12 = *(_DWORD *)(a2 + 108);
    *(_QWORD *)(a2 + 8) += *(_QWORD *)(v10 + 16);
    *(_QWORD *)(a2 + 16) = v11 + *(_QWORD *)(v10 + 24);
    v13 = v12 + *(_DWORD *)(v10 + 12);
    v14 = *(_QWORD *)(a2 + 2752);
    *(_DWORD *)(a2 + 108) = v13;
    *(_QWORD *)(a2 + 2752) = v14 + *(_QWORD *)(v10 + 32);
    *(_QWORD *)(a2 + 2760) += *(_QWORD *)(v10 + 40);
  }
  return result;
}
