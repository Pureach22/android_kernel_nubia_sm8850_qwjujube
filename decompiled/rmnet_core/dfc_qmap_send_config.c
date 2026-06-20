__int64 __fastcall dfc_qmap_send_config(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x20
  __int64 v4; // x21
  unsigned int txid; // w0
  char v6; // w8

  result = _alloc_skb(28, 2080, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v3 = result;
    *(_WORD *)(result + 180) = -1792;
    v4 = skb_put(result, 28);
    *(_QWORD *)(v4 + 4) = 0;
    *(_QWORD *)(v4 + 12) = 0;
    *(_DWORD *)v4 = 402653312;
    *(_QWORD *)(v4 + 20) = 0;
    *(_BYTE *)(v4 + 4) = 10;
    txid = rmnet_qmap_next_txid();
    v6 = *(_BYTE *)(v4 + 15);
    *(_DWORD *)(v4 + 8) = bswap32(txid);
    *(_WORD *)(v4 + 12) = 2817;
    *(_BYTE *)(v4 + 15) = v6 | 1;
    *(_DWORD *)(v4 + 16) = bswap32(*(_DWORD *)(a1 + 368));
    *(_DWORD *)(v4 + 20) = bswap32(*(_DWORD *)(a1 + 372));
    return rmnet_qmap_send(v3, 255, 0);
  }
  return result;
}
