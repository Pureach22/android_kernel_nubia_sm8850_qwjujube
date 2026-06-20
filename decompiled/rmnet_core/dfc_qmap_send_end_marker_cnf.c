__int64 __fastcall dfc_qmap_send_end_marker_cnf(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  __int64 result; // x0
  __int64 v9; // x23
  __int64 v10; // x0
  char v11; // w8

  result = _alloc_skb(28, 2080, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v9 = result;
    v10 = skb_put(result, 28);
    *(_QWORD *)v10 = 0;
    *(_QWORD *)(v10 + 8) = 0;
    *(_QWORD *)(v10 + 16) = 0;
    *(_DWORD *)(v10 + 24) = 0;
    *(_BYTE *)v10 = -64;
    *(_BYTE *)(v10 + 1) = *(_BYTE *)(a1 + 16);
    *(_DWORD *)(v10 + 2) = 267264;
    *(_WORD *)(v10 + 8) = 269;
    *(_DWORD *)(v10 + 12) = bswap32(a4);
    *(_BYTE *)(v10 + 16) = 1;
    v11 = *(_BYTE *)(a2 + 16);
    *(_WORD *)(v10 + 22) = bswap32(a3) >> 16;
    *(_BYTE *)(v10 + 18) = v11;
    return rmnet_qmap_send(v9, *(unsigned __int8 *)(a2 + 128), 1);
  }
  return result;
}
